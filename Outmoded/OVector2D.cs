namespace Outmoded
{
	public class OVector2D
	{
		public int X { get; protected set; }
		public int Y { get; protected set; }

		public OVector2D() : this(0, 0) { }

		public OVector2D(int X, int Y)
		{
			this.X = X;
			this.Y = Y;
		}
	}
}
