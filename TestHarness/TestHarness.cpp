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

#ifdef _WIN32
	eng.RegisterKey(VK_ESCAPE);
	eng.RegisterKey(VK_RETURN);
	eng.RegisterKey(VK_LEFT);
	eng.RegisterKey(VK_RIGHT);
	eng.RegisterKey(VK_UP);
	eng.RegisterKey(VK_DOWN);
#else
	eng.RegisterKey(27);
	eng.RegisterKey(10);
	eng.RegisterKey(KEY_LEFT);
	eng.RegisterKey(KEY_RIGHT);
	eng.RegisterKey(KEY_UP);
	eng.RegisterKey(KEY_DOWN);
#endif

	while (keepRunning)
	{
		if (needsRendered)
		{
			int boxSize = sizeof(Box) / sizeof(Outmoded::Point);

			eng.ClearScreen();

			for (int i = 0; i < boxSize; ++i)
			{
				Outmoded::Point pos(Box[i].X + currentOffset.X, Box[i].Y + currentOffset.Y);
				eng.SetCell(pos, Outmoded::OutmodedColors::Black, Outmoded::OutmodedColors::Yellow, 'X');
			}

			eng.Render();
			needsRendered = false;
		}

		auto ch = eng.GetKeyInput();

		if (ch.size() > 0)
		{
			for (auto key : ch)
			{
				switch (key)
				{
#ifdef _WIN32
				case VK_RETURN:
					currentOffset.X = 0;
					currentOffset.Y = 0;
					needsRendered = true;

					break;
				case VK_ESCAPE:
					keepRunning = false;

					break;
				case VK_LEFT:
					currentOffset.X -= 1;
					needsRendered = true;

					break;
				case VK_RIGHT:
					currentOffset.X += 1;
					needsRendered = true;
					
					break;
				case VK_UP:
					currentOffset.Y -= 1;
					needsRendered = true;

					break;
				case VK_DOWN:
					currentOffset.Y += 1;
					needsRendered = true;

					break;
#else
				case 10:
					currentOffset.X = 0;
					currentOffset.Y = 0;
					needsRendered = true;

					break;
				case 27:
					keepRunning = false;

					break;
				case KEY_LEFT:
					currentOffset.X -= 1;
					needsRendered = true;

					break;
				case KEY_RIGHT:
					currentOffset.X += 1;
					needsRendered = true;

					break;
				case KEY_UP:
					currentOffset.Y -= 1;
					needsRendered = true;

					break;
				case KEY_DOWN:
					currentOffset.Y += 1;
					needsRendered = true;

					break;
#endif
				default:
					break;
				}
			}
		}

		eng.Pause(33);
	}

	eng.ClearScreen();

	std::cout << std::endl << "Thanks for playing!" << std::endl;
	std::cin.get();

	return 0;
}
