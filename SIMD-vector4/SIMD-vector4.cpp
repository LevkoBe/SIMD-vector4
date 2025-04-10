#include <iostream>
#include <xmmintrin.h>
#include <cmath>

struct vector4 {
private:
	float _x, _y, _z, _w;
public:
	vector4() : _x(0), _y(0), _z(0), _w(1.0f) {}
	vector4(float x, float y, float z, float w) : _x(x), _y(y), _z(z), _w(w) {}

	float x() const { return _x; }
	float y() const { return _y; }
	float z() const { return _z; }
	float w() const { return _w; }

	static friend std::ostream& operator<<(std::ostream& os, const vector4& v) {
		os << "vector4(" << v._x << ", " << v._y << ", " << v._z << ", " << v._w << ")";
		return os;
	}
};

int main()
{
	vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
	vector4 v2(5.0f, 6.0f, 7.0f, 8.0f);

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	return 0;
}