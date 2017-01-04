// ----------------------------------------------------
// Point class for X, Y and Z   -----------
// ----------------------------------------------------

#ifndef _POINT3D
#define _POINT3D

template<class TYPE>
class Point3D
{
public:

	TYPE x, y, z;

	Point3D()
	{}
	Point3D(TYPE x, TYPE y, TYPE z) : x(x), y(y), z(z)
	{}

	// Operators ------------------------------------------------
	Point3D operator -(const Point3D &v) const
	{
		Point3D r;

		r.x = x - v.x;
		r.y = y - v.y;
		r.z = z - v.z;

		return(r);
	}

	Point3D operator + (const Point3D &v) const
	{
		Point3D r;

		r.x = x + v.x;
		r.y = y + v.y;
		r.z = z + v.z;

		return(r);
	}

	const Point3D& operator -=(const Point3D &v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return(*this);
	}

	const Point3D& operator +=(const Point3D &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return(*this);
	}

	bool operator ==(const Point3D& v) const
	{
		return (x == v.x && y == v.y && z == v.z);
	}

	bool operator !=(const Point3D& v) const
	{
		return (x != v.x || y != v.y || z != v.z);
	}

	// Utils ------------------------------------------------
	bool IsZero() const
	{
		return (x == 0 && y == 0 && z == 0);
	}

	Point3D& SetToZero()
	{
		x = y = z = 0;
		return(*this);
	}

	Point3D& Negate()
	{
		x = -x;
		y = -y;
		z = -z;

		return(*this);
	}

	// Distances ---------------------------------------------
	TYPE DistanceTo(const Point3D& v) const
	{
		TYPE fx = x - v.x;
		TYPE fy = y - v.y;
		TYPE fz = z - v.z;

		return sqrt((fx*fx) + (fy*fy) + (fz*fz));
	}
};

typedef Point3D<int> iPoint3D;
typedef Point3D<float> fPoint3D;

#endif
