#pragma once

namespace Outmoded
{
	struct Vector2D
	{
		int X, Y;
	};

	class OVector2D
	{
	public:
		OVector2D();
		OVector2D(const int X, const int Y);
		OVector2D(const OVector2D &Source);
		~OVector2D();

		Vector2D Translate(const int X, const int Y);
		Vector2D Translate(const Vector2D Offset);

	protected:
		int X, Y;
	};
}
