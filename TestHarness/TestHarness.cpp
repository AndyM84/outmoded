#include <iostream>

#ifdef _WIN32
	#include <Windows.h>
	#include <atlbase.h>
#else
	#include <term.h>
	#include <ncurses.h>
	#include <unistd.h>
#endif

void write(char c, short, short);
void clearApp();
void pauseApp(int);

struct CellInfo
{
	char Value;
	short X, Y;
};

CellInfo Box[] = {
	{ 'X', 1, 1 }, { 'X', 2, 1 }, { 'X', 3, 1 },
	{ 'X', 1, 2 }, { 'X', 2, 2 }, { 'X', 3, 2 },
	{ 'X', 1, 3 }, { 'X', 2, 3 }, { 'X', 3, 3 }
};

enum TranslatedKeys
{
	NONE = 0,
	RETURN = 1,
	LEFT = 2,
	RIGHT = 3,
	UP = 4,
	DOWN = 5,
	ESC = 6
};

struct KeyTranslation
{
	int OsKey;
	TranslatedKeys Translation;
};

#ifdef _WIN32
KeyTranslation Keys[] = {
	{ VK_RETURN, RETURN },
	{ VK_LEFT, LEFT },
	{ VK_RIGHT, RIGHT },
	{ VK_UP, UP },
	{ VK_DOWN, DOWN },
	{ VK_ESCAPE, ESC }
};
#else
KeyTranslation Keys[] = {
	{ KEY_ENTER, RETURN },
	{ KEY_IL, RETURN },
	{ 10, RETURN },
	{ KEY_LEFT, LEFT },
	{ KEY_RIGHT, RIGHT },
	{ KEY_UP, UP },
	{ KEY_DOWN, DOWN },
	{ 27, ESC }
};
#endif

TranslatedKeys keyDown();

int main()
{
#ifndef _WIN32
	initscr();
	timeout(1);
	noecho();
	keypad(stdscr, TRUE);
#endif

	int boxLen = sizeof(Box) / sizeof(CellInfo);
	CellInfo currentPos = { 'X', 0, 0 }; // placeholder for movement
	bool needsWritten = true, keepRunning = true;

	while (keepRunning)
	{
		if (needsWritten)
		{
			clearApp();

			for (int j = 0; j < boxLen; ++j)
			{
				write(Box[j].Value, Box[j].X + currentPos.X, Box[j].Y + currentPos.Y);
			}

			needsWritten = false;
		}

		auto downKey = keyDown();

		if (downKey != NONE)
		{
			switch (downKey)
			{
			case RETURN:
				needsWritten = true;
				currentPos.X = 0;
				currentPos.Y = 0;

				break;
			case LEFT:
				needsWritten = true;
				currentPos.X -= 1;

				break;
			case RIGHT:
				needsWritten = true;
				currentPos.X += 1;

				break;
			case UP:
				needsWritten = true;
				currentPos.Y -= 1;

				break;
			case DOWN:
				needsWritten = true;
				currentPos.Y += 1;

				break;
			case ESC:
				keepRunning = false;

				break;
			default:
				break;
			}
		}

		pauseApp(30);
	}

	clearApp();

#ifndef _WIN32
	endwin();
	timeout(-1);
#endif

	std::cout << "Thanks for playing!" << std::endl;
	std::cin.get();

	return 0;
}

void write(char c, short x, short y)
{
#ifdef WIN32
	char *pC = &c;
	COORD pos = { x, y };
	DWORD dwBytesWritten = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hConsole == INVALID_HANDLE_VALUE)
	{
		return;
	}

	WriteConsoleOutputCharacter(hConsole, CA2W(pC), 1, pos, &dwBytesWritten);
#else
	mvaddch(y, x, c);
	refresh();
#endif

	return;
}

// Credit where due: http://stackoverflow.com/a/6487534/563136
void clearApp()
{
#ifdef WIN32
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
#else
	clear();
#endif

	return;
}

void pauseApp(int span)
{
	if (span < 0)
	{
		return;
	}

#ifdef WIN32
	Sleep(span);
#else
	usleep(span * 1000);
#endif

	return;
}

TranslatedKeys keyDown()
{
	int keyLen = sizeof(Keys) / sizeof(KeyTranslation);

#ifdef _WIN32
	for (int i = 0; i < keyLen; ++i)
	{
		if (GetAsyncKeyState(Keys[i].OsKey))
		{
			return Keys[i].Translation;
		}
	}
#else
	int ch = getch();

	for (int i = 0; i < keyLen; ++i)
	{
		if (ch == Keys[i].OsKey)
		{
			return Keys[i].Translation;
		}
	}
#endif

	return NONE;
}

