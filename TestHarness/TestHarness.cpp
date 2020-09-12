#include <iostream>
#include <Outmoded.h>

int main()
{
	bool keepRunning = true, needsRendered = true;
	Outmoded::Point currentOffset(0, 0);
	auto eng = Outmoded::Engine(true);
	Outmoded::Point Box[] = {
		{ 1, 1 }, { 2, 1 }, { 3, 1 },
		{ 1, 2 }, { 2, 2 }, { 3, 2 },
		{ 1, 3 }, { 2, 3 }, { 3, 3 }
	};

	eng.RegisterKey(OKEY_ESCAPE);
	eng.RegisterKey(OKEY_ENTER);
	eng.RegisterKey(OKEY_LEFT);
	eng.RegisterKey(OKEY_RIGHT);
	eng.RegisterKey(OKEY_UP);
	eng.RegisterKey(OKEY_DOWN);

	while (keepRunning) {
		if (needsRendered) {
			eng.ClearScreen();

			for (auto cell : Box) {
				Outmoded::Point pos(cell.X + currentOffset.X, cell.Y + currentOffset.Y);
				eng.SetCell(pos, Outmoded::OutmodedColors::Black, Outmoded::OutmodedColors::Yellow, 'X');
			}

			eng.Render();
			needsRendered = false;
		}

		auto ch = eng.GetKeyInput();

		if (ch.size() > 0) {
			for (auto key : ch) {
				switch (key) {
				case OKEY_ENTER:
					currentOffset.X = 0;
					currentOffset.Y = 0;
					needsRendered = true;

					break;
				case OKEY_ESCAPE:
					keepRunning = false;

					break;
				case OKEY_LEFT:
					currentOffset.X -= 1;
					needsRendered = true;

					break;
				case OKEY_RIGHT:
					currentOffset.X += 1;
					needsRendered = true;

					break;
				case OKEY_UP:
					currentOffset.Y -= 1;
					needsRendered = true;

					break;
				case OKEY_DOWN:
					currentOffset.Y += 1;
					needsRendered = true;

					break;
				default:
					break;
				}
			}
		}

		eng.Pause(1);
	}

	eng.ClearScreen();

	std::cout << std::endl << "Thanks for playing!" << std::endl;
	std::cin.get();

	return 0;
}
