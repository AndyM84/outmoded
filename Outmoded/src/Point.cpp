#include <Point.h>

namespace Outmoded
{
	Point::Point()
		: X(0), Y(0)
	{ }

	Point::Point(int nX, int nY)
		: X(nX), Y(nY)
	{ }

	Point::Point(const Point &Source)
		: X(Source.X), Y(Source.Y)
	{ }

	const int &Point::operator()(int Index) const
	{
		return (&X)[Index];
	}

	int &Point::operator()(int Index)
	{
		return (&X)[Index];
	}

	int &Point::operator[](int Index)
	{
		if (Index < 0 || Index > 1)
		{
			throw ArgumentRangeException("Index", "0", "1");
		}

		return (Index == 0) ? X : Y;
	}

	int Point::operator[](int Index) const
	{
		if (Index < 0 || Index > 1)
		{
			throw ArgumentRangeException("Index", "0", "1");
		}

		return (Index == 0) ? X : Y;
	}

	bool Point::operator==(const Point &Other) const
	{
		return X == Other.X && Y == Other.Y;
	}

	bool Point::operator!=(const Point &Other) const
	{
		return X != Other.X || Y != Other.Y;
	}

	Point &Point::operator*=(int Scale)
	{
		X *= Scale;
		Y *= Scale;

		return *this;
	}

	Point &Point::operator/=(int Divisor)
	{
		X /= Divisor;
		Y /= Divisor;

		return *this;
	}

	Point &Point::operator+=(const Point &Other)
	{
		X += Other.X;
		Y += Other.Y;

		return *this;
	}

	Point &Point::operator-=(const Point &Other)
	{
		X -= Other.X;
		Y -= Other.Y;

		return *this;
	}

	Point &Point::operator*=(const Point &Other)
	{
		X *= Other.X;
		Y *= Other.Y;

		return *this;
	}

	Point &Point::operator/=(const Point &Divisor)
	{
		X /= Divisor.X;
		Y /= Divisor.Y;

		return *this;
	}

	Point Point::operator+(const Point &Other) const
	{
		return Point(*this) += Other;
	}

	Point Point::operator-(const Point &Other) const
	{
		return Point(*this) -= Other;
	}

	Point Point::operator*(const Point &Other) const
	{
		return Point(*this) *= Other;
	}

	Point Point::operator/(const Point &Other) const
	{
		return Point(*this) /= Other;
	}

	Point Point::ComponentMin(const Point &Other) const
	{
		return Point((X < Other.X) ? X : Other.X, (Y < Other.Y) ? Y : Other.Y);
	}

	Point Point::ComponentMax(const Point &Other) const
	{
		return Point((X > Other.X) ? X : Other.X, (Y > Other.Y) ? Y : Other.Y);
	}

	int Point::GetMin() const
	{
		return (X < Y) ? X : Y;
	}

	int Point::GetMax() const
	{
		return (X > Y) ? X : Y;
	}

	int Point::SizeSquared() const
	{
		return X * X + Y * Y;
	}

	std::string Point::ToString() const
	{
		std::stringstream stream("{X=");
		stream << X << ", Y=" << Y << "}";

		return stream.str();
	}
}
