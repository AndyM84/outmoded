#include <Engine.h>

namespace Outmoded
{
	Engine::Engine()
		: Engine(false)
	{ }

	Engine::Engine(bool ClearScreen)
		: Engine(ClearScreen, Black, White)
	{ }

	Engine::Engine(bool ClearScreen, OutmodedColors Background, OutmodedColors Foreground)
	{
#ifdef _WIN32
		this->Console = GetStdHandle(STD_OUTPUT_HANDLE);

		if (this->Console == INVALID_HANDLE_VALUE)
		{
			throw TerminalInitException();
		}
#else
		initscr();
		timeout(1);
		noecho();
		keypad(stdscr, TRUE);
		curs_set(0);
#endif

		this->BackgroundColor = Background;
		this->ForegroundColor = Foreground;

		if (ClearScreen)
		{
			this->ClearScreen();
		}
	}

	Engine::~Engine()
	{
#ifndef _WIN32
		endwin();
		timeout(-1);
#endif
	}

	void Engine::RegisterKey(int KeyCode)
	{
		this->RegisteredKeys.push_back(KeyCode);

		return;
	}

	std::vector<int> Engine::GetKeyInput() const
	{
		std::vector<int> caught;

		if (this->RegisteredKeys.size() < 1)
		{
			return caught;
		}

#ifdef _WIN32
		for (int i : this->RegisteredKeys)
		{
			if (GetAsyncKeyState(i))
			{
				caught.push_back(i);
			}
		}
#else
		int ch = getch();

		for (int i : this->RegisteredKeys)
		{
			if (ch == i)
			{
				caught.push_back(i);
			}
		}
#endif

		return caught;
	}

	void Engine::ClearScreen()
	{
#ifdef _WIN32
		DWORD written;
		COORD topLeft = { 0, 0 };
		CONSOLE_SCREEN_BUFFER_INFO bInfo;

		GetConsoleScreenBufferInfo(this->Console, &bInfo);
		FillConsoleOutputCharacterA(this->Console, ' ', bInfo.dwSize.X * bInfo.dwSize.Y, topLeft, &written);
		FillConsoleOutputAttribute(this->Console, this->GetDefaultColorValue(), bInfo.dwSize.X * bInfo.dwSize.Y, topLeft, &written);
		SetConsoleCursorPosition(this->Console, topLeft);
#else
		clear();
#endif

		return;
	}

	void Engine::SetCursorLocation(const Point &Position)
	{
#ifdef _WIN32
		COORD nPos = { (short)Position.X, (short)Position.Y };
		SetConsoleCursorPosition(this->Console, nPos);
#else
		move(Position.Y, Position.X);
#endif

		return;
	}

	void Engine::SetCell(const Point &Position, char Character)
	{
		this->SetCell(Position, this->BackgroundColor, this->ForegroundColor, Character);

		return;
	}

	void Engine::SetCell(const Point &Position, OutmodedColors Background, OutmodedColors Foreground, char Character)
	{
		CellInfo cell = { Position, Background, Foreground, Character };
		this->Buffer.push_back(cell);

		return;
	}

	void Engine::Render()
	{
		if (this->Buffer.size() < 1)
		{
			return;
		}

		for (auto cell : this->Buffer)
		{
			this->OutputCell(cell);
		}

		this->Buffer.clear();

		return;
	}

	void Engine::Pause(int Span)
	{
		if (Span < 0 || Span > 1000000)
		{
			throw ArgumentRangeException("Span", "0", "1,000,000");
		}

#ifdef _WIN32
		Sleep(Span);
#else
		usleep(Span * 1000);
#endif

		return;
	}

	void Engine::OutputCell(const CellInfo &Cell)
	{
#ifdef _WIN32
		const char *pC = &Cell.Character;
		WORD color = this->GetOsColorValue(Cell.Background, Cell.Foreground);
		COORD pos = { (short)Cell.Position.X, (short)Cell.Position.Y };
		DWORD written;

		WriteConsoleOutputAttribute(this->Console, &color, 1, pos, &written);
		WriteConsoleOutputCharacter(this->Console, pC, 1, pos, &written);
#else
		if (has_colors() == FALSE)
		{
			mvaddch(Cell.Position.Y, Cell.Position.X, Cell.Character);
			refresh();
		}
		else
		{
			attron(COLOR_PAIR(this->GetOsColorValue(Cell.Background, Cell.Foreground)));
			mvaddch(Cell.Position.Y, Cell.Position.X, Cell.Character);
			attroff(COLOR_PAIR(this->GetOsColorValue(Cell.Background, Cell.Foreground)));
			refresh();
		}
#endif

		return;
	}

#ifdef _WIN32
	WORD Engine::GetOsColorValue(OutmodedColors Background, OutmodedColors Foreground)
	{
		WORD bg, fg;

		switch (Background)
		{
		case Blue:
			bg = BACKGROUND_BLUE;

			break;
		case Green:
			bg = BACKGROUND_GREEN;

			break;
		case Red:
			bg = BACKGROUND_RED;

			break;
		case White:
			bg = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;

			break;
		case Yellow:
			bg = BACKGROUND_GREEN | BACKGROUND_RED;

			break;
		case Magenta:
			bg = BACKGROUND_RED | BACKGROUND_BLUE;

			break;
		case Cyan:
			bg = BACKGROUND_BLUE | BACKGROUND_GREEN;

			break;
		case Black:
		default:
			bg = 0;

			break;
		}

		switch (Foreground)
		{
		case Blue:
			fg = FOREGROUND_BLUE;

			break;
		case Green:
			fg = FOREGROUND_GREEN;

			break;
		case Red:
			fg = FOREGROUND_RED;

			break;
		case Black:
			fg = 0;

			break;
		case Yellow:
			fg = FOREGROUND_GREEN | FOREGROUND_RED;

			break;
		case Magenta:
			fg = FOREGROUND_RED | FOREGROUND_BLUE;

			break;
		case Cyan:
			fg = FOREGROUND_BLUE | FOREGROUND_GREEN;

			break;
		case White:
		default:
			fg = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

			break;
		}

		return bg | fg;
	}

	WORD Engine::GetDefaultColorValue()
	{
		return this->GetOsColorValue(this->BackgroundColor, this->ForegroundColor);
	}
#else
	int Engine::GetOsColorValue(OutmodedColors Background, OutmodedColors Foreground)
	{
		int ID = 1;

		if (this->ColorPairs.size() > 0)
		{
			for (auto pair : this->ColorPairs)
			{
				if (pair.Background == Background && pair.Foreground == Foreground)
				{
					return pair.ID;
				}
				else if (pair.ID > ID)
				{
					ID = pair.ID + 1;
				}
			}
		}

		int bg, fg;

		switch (Background)
		{
		case Blue:
			bg = COLOR_BLUE;

			break;
		case Green:
			bg = COLOR_GREEN;

			break;
		case Red:
			bg = COLOR_RED;

			break;
		case White:
			bg = COLOR_WHITE;

			break;
		case Yellow:
			bg = COLOR_YELLOW;

			break;
		case Magenta:
			bg = COLOR_MAGENTA;

			break;
		case Cyan:
			bg = COLOR_CYAN;

			break;
		case Black:
		default:
			bg = COLOR_BLACK;

			break;
		}

		switch (Foreground)
		{
		case Blue:
			fg = COLOR_BLUE;

			break;
		case Green:
			fg = COLOR_GREEN;

			break;
		case Red:
			fg = COLOR_RED;

			break;
		case Black:
			fg = COLOR_BLACK;

			break;
		case Yellow:
			fg = COLOR_YELLOW;

			break;
		case Magenta:
			fg = COLOR_MAGENTA;

			break;
		case Cyan:
			fg = COLOR_CYAN;

			break;
		case White:
		default:
			fg = COLOR_WHITE;

			break;
		}

		init_pair(ID, fg, bg);

		return ID;
	}

	int Engine::GetDefaultColorValue()
	{
		return this->GetOsColorValue(this->BackgroundColor, this->ForegroundColor);
	}
#endif
}
