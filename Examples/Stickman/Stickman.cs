﻿using System;
using System.Collections.Generic;
using System.Threading;
using System.Diagnostics;
using Outmoded;

namespace Stickman
{
	class Stickman
	{
		enum ManStates {
			Idle,
			Walk1,
			Walk2,
			Walk3,
			Jump1,
			Jump2,
			Jump3
		};

		/// <summary>
		/// Collection of the man's cell data through his various states.
		/// </summary>
		static Dictionary<ManStates, List<OVector2D>> ManData = new Dictionary<ManStates, List<OVector2D>>() {
			{
				ManStates.Idle, new List<OVector2D>() {new OVector2D(1, 0), new OVector2D(2, 0), new OVector2D(3, 0),new OVector2D(0, 1), new OVector2D(1, 1), new OVector2D(2, 1), new OVector2D(3, 1), new OVector2D(4, 1),new OVector2D(1, 2), new OVector2D(2, 2), new OVector2D(3, 2),
																									new OVector2D(2, 3),
							new OVector2D(0, 4), new OVector2D(1, 4), new OVector2D(2, 4), new OVector2D(3, 4), new OVector2D(4, 4),
																									new OVector2D(2, 5),
																									new OVector2D(2, 6),
																					new OVector2D(1, 7), new OVector2D(3, 7),
																					new OVector2D(1, 8), new OVector2D(3, 8),
																					new OVector2D(1, 9), new OVector2D(3, 9)
				}
			}
		};

		static void Main(string[] args)
		{
			// Use default settings on a cleared screen (fore=white, back=black, enc=utf8)
			var eng = new Outmoded.Outmoded(true);

			foreach (var cell in ManData[ManStates.Idle])
			{
				eng.SetCell(cell,ConsoleColor.Green, ConsoleColor.Black, '\u0038');
			}

			eng.RenderFrame();
			Console.SetCursorPosition(0, Console.WindowHeight - 2);


            Console.WriteLine("Press ESC to stop");
              do
              {
                if(eng.Getkeyinput('\u0061'))
                {

                    Console.Write("\n pressed the a button");


                }
            

            } while (Console.ReadKey(true).Key != ConsoleKey.Escape);




         
            Console.Write("\r Press return to exit..");
			Console.ReadLine();

			eng.ClearScreen();

			Console.WriteLine("Thank you!");
			
			Thread.Sleep(1500);
		}
	}
}
