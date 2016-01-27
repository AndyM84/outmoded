#include <iostream>

#ifdef WIN32
	#include <Windows.h>
	#include <atlbase.h>
#else
	#include <term.h>
	#include <unistd.h>
#endif

void write(LPCWSTR, short, short);
void clear();
void pauseApp(int);

struct CellInfo
{
	LPCWSTR Value;
	short X, Y;
};

CellInfo Box[] = {
	{ L"X", 1, 1 }, { L"X", 2, 1 }, { L"X", 3, 1 },
	{ L"X", 1, 2 }, { L"X", 2, 2 }, { L"X", 3, 2 },
	{ L"X", 1, 3 }, { L"X", 2, 3 }, { L"X", 3, 3 }
};

int main()
{
#ifndef WIN32
	setupterm(NULL, fileno(stdout), NULL);
#endif

	int boxLen = sizeof(Box) / sizeof(CellInfo);

	for (int i = 0; i < 300; ++i)
	{
		clear();

		for (int j = 0; j < boxLen; ++j)
		{
			write(Box[j].Value, Box[j].X + i, Box[j].Y + i);
		}

		pauseApp(33);
	}

	std::cin.get();

	return 0;
}

void write(LPCWSTR c, short x, short y)
{
#ifdef WIN32
	COORD pos = { x, y };
	DWORD dwBytesWritten = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hConsole == INVALID_HANDLE_VALUE)
	{
		return;
	}

	WriteConsoleOutputCharacter(hConsole, c, 1, pos, &dwBytesWritten);
#else
#endif

	return;
}

// Credit where due: http://stackoverflow.com/a/6487534/563136
void clear()
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
	putp(tigetstr("clear"));
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
