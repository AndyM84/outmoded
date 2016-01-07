using System;
using System.Collections.Generic;
using System.Threading;

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
				ManStates.Idle, new List<OVector2D>() {
					new OVector2D(1, 0), new OVector2D(0, 1), new OVector2D(1, 1), new OVector2D(2, 1), new OVector2D(1, 2)
				}
			}
		};

		static void Main(string[] args)
		{
			// Use default settings on a cleared screen (fore=white, back=black, enc=utf8)
			var eng = new Outmoded.Outmoded(true);

			foreach (var cell in ManData[ManStates.Idle])
			{
				eng.SetCell(cell, '\u2588');
			}

			eng.RenderFrame();
			Console.SetCursorPosition(0, Console.WindowHeight - 1);

			Console.Write("Press return to exit..");
			Console.ReadLine();

			eng.ClearScreen();

			Console.WriteLine("Thank you!");
			
			Thread.Sleep(1500);
		}
	}
}
