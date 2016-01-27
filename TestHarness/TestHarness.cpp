#include <iostream>

#ifdef WIN32
	#include <Windows.h>
	#include <atlbase.h>
#else
	#include <term.h>
	#include <ncurses.h>
	#include <unistd.h>
#endif

#ifdef WIN32
	void write(LPCWSTR, short, short);
#else
	void write(char c, short, short);
#endif
void clearApp();
void pauseApp(int);

struct CellInfo
{
#ifdef WIN32
	LPCWSTR Value;
#else
	char Value;
#endif
	short X, Y;
};

CellInfo Box[] = {
#ifdef WIN32
	{ L"X", 1, 1 }, { L"X", 2, 1 }, { L"X", 3, 1 },
	{ L"X", 1, 2 }, { L"X", 2, 2 }, { L"X", 3, 2 },
	{ L"X", 1, 3 }, { L"X", 2, 3 }, { L"X", 3, 3 }
#else
	{ 'X', 1, 1 }, { 'X', 2, 1 }, { 'X', 3, 1 },
	{ 'X', 1, 2 }, { 'X', 2, 2 }, { 'X', 3, 2 },
	{ 'X', 1, 3 }, { 'X', 2, 3 }, { 'X', 3, 3 }
#endif
};

int main()
{
#ifndef WIN32
	setupterm(NULL, fileno(stdout), NULL);
#endif

	int boxLen = sizeof(Box) / sizeof(CellInfo);

	for (int i = 0; i < 300; ++i)
	{
		clearApp();

		for (int j = 0; j < boxLen; ++j)
		{
			write(Box[j].Value, Box[j].X + i, Box[j].Y + i);
		}

		pauseApp(33);
	}

	std::cin.get();

	return 0;
}

#ifdef WIN32
void write(LPCWSTR c, short x, short y)
{
	COORD pos = { x, y };
	DWORD dwBytesWritten = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hConsole == INVALID_HANDLE_VALUE)
	{
		return;
	}

	WriteConsoleOutputCharacter(hConsole, c, 1, pos, &dwBytesWritten);

	return;
}
#else
void write(char c, short x, short y)
{
	mvaddch(y, x, c);

	return;
}
#endif

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
	refresh();
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
