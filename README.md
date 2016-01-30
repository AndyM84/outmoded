## Outmoded
A graphics library that doesn't do graphics at all.

## The Basics
### Instantiating an Engine
Basically all work is done through interaction with the `Outmoded::Engine` class.  The basics to creating an instance look like this:

```c++
#include <Outmoded.h>

int main()
{
	auto eng = Outmoded::Engine();
}
```

### Drawing to the Console
Output through the engine is done with the concept of 'cells', which really just represent a cursor location inside the console.  The `Outmoded::Point` class is used for providing the coordinates of a given cell, and can be used to create a box like this:

```c++
#include <Outmoded.h>

int main()
{
	auto eng = Outmoded::Engine();

	Outmoded::Point Box[] = {
		{ 1, 1 }, { 2, 1 }, { 3, 1 },
		{ 1, 2 }, { 2, 2 }, { 3, 2 },
		{ 1, 3 }, { 2, 3 }, { 3, 3 }
	};

	for (auto cell : Box)
	{
		eng.SetCell(cell, 'X');
	}

	return 0;
}
```

The above will produce a filled 3x3 box made of the 'X' character.  However, the box will not show until you call the `Engine::Render()` method:

```c++
#include <Outmoded.h>

int main()
{
	auto eng = Outmoded::Engine();

	Outmoded::Point Box[] = {
		{ 1, 1 }, { 2, 1 }, { 3, 1 },
		{ 1, 2 }, { 2, 2 }, { 3, 2 },
		{ 1, 3 }, { 2, 3 }, { 3, 3 }
	};

	for (auto cell : Box)
	{
		eng.SetCell(cell, 'X');
	}

	eng.Render();

	return 0;
}
```

Now the box appears just before the application closes.  You can further make use of the `Engine::ClearScreen()` and `Engine::Pause(int)` methods to allow yourself the ability to redraw the entire screen (similar to how you might with OpenGL/DirectX), but be warned that this will need to be managed carefully as redrawing in the console is not as quick/smooth as redrawing in a proper graphics pipeline.

### Handling Input
Input in `Outmoded` is done using a simple approach that polls registered keys to see if they have been pressed:

```c++
#include <Outmoded.h>

int main()
{
	auto eng = Outmoded::Engine();

	Outmoded::Point posOffset = { 0, 0 };
	Outmoded::Point Box[] = {
		{ 1, 1 }, { 2, 1 }, { 3, 1 },
		{ 1, 2 }, { 2, 2 }, { 3, 2 },
		{ 1, 3 }, { 2, 3 }, { 3, 3 }
	};

	eng.RegisterKey(OKEY_ESCAPE);
	eng.RegisterKey(OKEY_LEFT);
	eng.RegisterKey(OKEY_RIGHT);

	bool keepRunning = true, doRender = true;

	while (keepRunning)
	{
		if (doRender)
		{
			eng.ClearScreen();

			for (auto cell : Box)
			{
				eng.SetCell(Outmoded::Point(cell.X + posOffset.X, cell.Y + posOffset.Y), 'X');
			}

			doRender = false;
			eng.Render();
		}

		auto ch = eng.GetKeyInput();

		for (auto key : ch)
		{
			switch (key)
			{
			case OKEY_ESCAPE:
				keepRunning = false;

				break;
			case OKEY_LEFT:
				posOffset.X -= 1;
				doRender = true;
				
				break;
			case OKEY_RIGHT:
				posOffset.X += 1;
				doRender = true;
				
				break;
			default:
				break;
			}
		}

		eng.Pause(33); // close enough to 30fps
	}

	return 0;
}
```

This should give you a console application that lets you move your box left and right, as well as close when you hit the 'escape' key.

*NOTE* This library should NOT be used for user input such as data entry, it just isn't worth the effort.

## Building
### Visual Studio
This is pretty easy.  Simply add the `Outmoded` project to your solution, reference it as a static library and add the `include` directory to your `VC++ Directories` setting for your project.

### Linux
This is not very easy, though surely Linux gurus/fanboys will disagree.  If you are using an IDE on a *nix system, maybe it has a similar process to the Visual Studio process above (if so please let us know so we can document it).  On the other hand, if you're trying to do this from a terminal, you'll need to resort to using makefiles or a similar mechanism.

We've been able to compile successfully using a makefile and the g++ compiler in Cygwin and OSX, though we're admitted novices when it comes to *nix build processes.

#### Example makefile
```makefile
CC=g++

Engine.o: TerminalInitException.o Point.o
	$(CC) -std=c++11 -Wall -static -c -I../Outmoded/include ../Outmoded/src/Engine.cpp -o Engine.o

TerminalInitException.o:
	$(CC) -std=c++11 -Wall -static -c -I../Outmoded/include ../Outmoded/src/Exceptions/TerminalInitException.cpp -o TerminalInitException.o

Point.o: ArgumentRangeException.o
	$(CC) -std=c++11 -Wall -static -c -I../Outmoded/include ../Outmoded/src/Point.cpp -o Point.o

ArgumentRangeException.o: dir
	$(CC) -std=c++11 -Wall -static -c -I../Outmoded/include ../Outmoded/src/Exceptions/ArgumentRangeException.cpp -o ArgumentRangeException.o

clean:
	rm *.o
```

## Limitations
### Building
On Linux, we've had some issues getting `clang` and `clang++` to work as expected.  `g++` works in both environments, but as of this moment we have failed to get other compilers working.

### Key Input
We make use of the `ncurses` library on *nix, so there were a lot of oddities with the way the library handles key input.  For one thing it doesn't register simultaneous key presses, and also neglects a good number of keys (which limited the keys we could 'enable' for the engine).

Beyond that, key input on *nix and Windows behaves very differently, tending to be much faster/smoother on Windows.  You could likely deal with the difference somewhat using a state machine, but that's not within the scope of this project.

### Frames/Windows
The ONE area that `ncurses` behaved nicer than `Win32` for me would probably be it's ability to do 'windows'.  We had a lot of trouble with this concept in Win32, so we abandoned the concept of having a frame built into the engine.  You can do it, but you'll need to figure out the best approach for your project.

## Requirements
* IDE or Compiler (g++)
* ncurses and c++11 for *nix
* Boredom