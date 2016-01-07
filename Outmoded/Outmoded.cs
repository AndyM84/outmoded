using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace Outmoded
{
	public class Outmoded
	{
		public ConsoleColor DefaultForegroundColor { get; set; }
		public ConsoleColor DefaultBackgroundColor { get; set; }
		protected Queue<Frame> FrameBuffer { get; set; }
		protected Frame FrameTemp { get; set; }

		private object FrameLock = new object();

		public Outmoded() : this(false) { }
		public Outmoded(bool ClearScreen) : this(ClearScreen, ConsoleColor.White, ConsoleColor.Black, Encoding.UTF8) { }

		public Outmoded(bool ClearScreen, ConsoleColor DefaultForegroundColor, ConsoleColor DefaultBackgroundColor, Encoding NewEncoding)
		{
			Console.OutputEncoding = NewEncoding;

			this.FrameTemp = new Frame();
			this.FrameBuffer = new Queue<Frame>();
			this.DefaultForegroundColor = DefaultForegroundColor;
			this.DefaultBackgroundColor = DefaultBackgroundColor;

			if (ClearScreen)
			{
				this.ClearScreen();
			}
		}

		public void ClearScreen()
		{
			Console.Clear();

			return;
		}

		public void SetCursorTo(OVector2D Position)
		{
			Console.SetCursorPosition(Position.X, Position.Y);

			return;
		}

		public void SetCell(OVector2D Position, char Character)
		{
			this.SetCell(Position, this.DefaultForegroundColor, this.DefaultBackgroundColor, Character);

			return;
		}

		public void SetCell(OVector2D Position, ConsoleColor Foreground, ConsoleColor Background, char Character)
		{
			this.FrameTemp.Add(new CellInfo(Position, Foreground, Background, Character));

			return;
		}

		public void RenderFrame()
		{
			this.ClearScreen();
			this.OutputFrame(this.FrameTemp);
			this.FrameTemp = new Frame();

			return;
		}

		protected void OutputCell(CellInfo Cell)
		{
			Console.SetCursorPosition(Cell.Position.X, Cell.Position.Y);
			Console.ForegroundColor = Cell.Foreground;
			Console.BackgroundColor = Cell.Background;
			Console.Write(Cell.Character);

			return;
		}

		protected void OutputFrame(Frame Frame)
		{
			foreach (var cell in Frame)
			{
				this.OutputCell(cell);
			}

			return;
		}
	}
}
