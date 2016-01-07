using System;

namespace Outmoded
{
	public class CellInfo
	{
		public OVector2D Position { get; protected set; }
		public ConsoleColor Foreground { get; protected set; }
		public ConsoleColor Background { get; protected set; }
		public char Character { get; protected set; }

		public CellInfo(OVector2D Position, ConsoleColor Foreground, ConsoleColor Background, char Character)
		{
			this.Position = Position;
			this.Foreground = Foreground;
			this.Background = Background;
			this.Character = Character;
		}
	}
}
