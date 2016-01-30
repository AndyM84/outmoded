#pragma once

#include <Exceptions/ArgumentRangeException.h>
#include <Exceptions/TerminalInitException.h>
#include <iostream>
#include <vector>
#include <Point.h>
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
		Blue,
		Green,
		Red,
		Black,
		White,
		Yellow,
		Magenta,
		Cyan
	};

	enum OutmodedColorIntensities
	{
		Normal,
		Intense
	};

	class Engine
	{
	public:
		OutmodedColors BackgroundColor;
		OutmodedColors ForegroundColor;

		Engine();
		Engine(bool ClearScreen);
		Engine(bool ClearScreen, OutmodedColors Background, OutmodedColors Foreground);
		~Engine();

		void RegisterKey(int KeyCode);
		std::vector<int> GetKeyInput() const;
		void ClearScreen();
		void SetCursorLocation(const Point &Position);
		void SetCell(const Point &Position, char Character);
		void SetCell(const Point &Position, OutmodedColors Background, OutmodedColors Foreground, char Character);
		void Render();
		void Pause(int Span);

	protected:
		struct CellInfo
		{
			Point Position;
			OutmodedColors Background;
			OutmodedColors Foreground;
			char Character;
		};

		std::vector<int> RegisteredKeys;
		std::vector<CellInfo> Buffer;
#ifdef _WIN32
		HANDLE Console;
#else
		struct ColorPair
		{
			int ID;
			OutmodedColors Background;
			OutmodedColors Foreground;
		};

		std::vector<ColorPair> ColorPairs;
#endif

		void OutputCell(const CellInfo &Cell);
#ifdef _WIN32
		WORD GetOsColorValue(OutmodedColors Background, OutmodedColors Foreground);
		WORD GetDefaultColorValue();
#else
		int GetOsColorValue(OutmodedColors Background, OutmodedColors Foreground);
		int GetDefaultColorValue();
#endif
	};
}
