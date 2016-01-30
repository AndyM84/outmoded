#pragma once

#include <string>
#include <sstream>
#include <Exceptions/ArgumentRangeException.h>

namespace Outmoded
{
	class Point
	{
	public:
		int X;
		int Y;

		Point();
		Point(int nX, int nY);
		Point(const Point &Source);

		/* Return component of point */
		const int &operator()(int Index) const;
		int &operator()(int Index);
		int &operator[](int Index);
		int operator[](int Index) const;

		/* Equality comparison operator */
		bool operator==(const Point &Other) const;
		/* Inequality comparison operator */
		bool operator!=(const Point &Other) const;

		/* Scale point */
		Point &operator*=(int Scale);
		/* Divide point */
		Point &operator/=(int Divisor);
		/* Add to point */
		Point &operator+=(const Point &Other);
		/* Subtract from point */
		Point &operator-=(const Point &Other);
		/* Scales the point */
		Point &operator*=(const Point &Other);
		/* Divides the point */
		Point &operator/=(const Point &Divisor);
		/* Creates a new Point by addition */
		Point operator+(const Point &Other) const;
		/* Creates a new Point by subtraction */
		Point operator-(const Point &Other) const;
		/* Creates a new Point by multiplying */
		Point operator*(const Point &Other) const;
		/* Creates a new Point by dividing */
		Point operator/(const Point &Other) const;

		/* Get component-wise min of two Points */
		Point ComponentMin(const Point &Other) const;
		/* Get component-wise max of two Points */
		Point ComponentMax(const Point &Other) const;

		/* Get minimum value in Point */
		int GetMin() const;
		/* Get maximum value in Point */
		int GetMax() const;
		/* Get squared distance of this Point from (0,0) */
		int SizeSquared() const;

		/* Get textual representation of Point */
		std::string ToString() const;
	};
}
