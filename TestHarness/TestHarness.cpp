#include <iostream>

#ifdef WIN32
	#include <Windows.h>
#else
	#include <term.h>
#endif

void clear();

int main()
{
#ifndef WIN32
	setupterm(NULL, fileno(stdout), NULL);
#endif

	std::cout << "Testing!" << std::endl;

	std::cin.get();

	clear();

	std::cout << "This is another test." << std::endl;

	std::cin.get();

	return 0;
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
