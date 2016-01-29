#pragma once

#include <iostream>
#include <string>

#ifdef _WIN32
	#include <Windows.h>
	#include <atlbase.h>
#else
	#include <term.h>
	#include <ncurses.h>
	#include <unistd.h>
#endif

namespace Outmoded
{
	enum OutmodedColors
	{
		Green,
		Red,
		Blue,
		Black,
		Yellow,
		White
	};

	enum OutmodedColorIntensities
	{
		Normal,
		Intense
	};

	class Engine
	{
	public:

	};
}
