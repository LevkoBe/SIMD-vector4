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

	vector4& add(const vector4& other) {
		__m128 ths = _mm_set_ps(_w, _z, _y, _x);
		__m128 tht = _mm_set_ps(other._w, other._z, other._y, other._x);
		__m128 res = _mm_add_ps(ths, tht);
		store(res);
		return *this;
	}
	vector4& add(float x, float y, float z) {
		__m128 ths = _mm_set_ps(_w, _z, _y, _x);
		__m128 tht = _mm_set_ps(0.0f, z, y, x);
		__m128 res = _mm_add_ps(ths, tht);
		store(res);
		return *this;
	}

	vector4& sub(const vector4& other) {
		__m128 ths = _mm_set_ps(_w, _z, _y, _x);
		__m128 tht = _mm_set_ps(other._w, other._z, other._y, other._x);
		__m128 res = _mm_sub_ps(ths, tht);
		store(res);
		return *this;
	}
	vector4& sub(float x, float y, float z) {
		__m128 ths = _mm_set_ps(_w, _z, _y, _x);
		__m128 tht = _mm_set_ps(0.0f, z, y, x);
		__m128 res = _mm_sub_ps(ths, tht);
		store(res);
		return *this;
	}

	static friend std::ostream& operator<<(std::ostream& os, const vector4& v) {
		os << "vector4(" << v._x << ", " << v._y << ", " << v._z << ", " << v._w << ")";
		return os;
	}

	void store(const __m128& v) {
		alignas(16) float res[4];
		_mm_store_ps(res, v);
		_x = res[0];
		_y = res[1];
		_z = res[2];
		_w = res[3];
	}
};

int main()
{
	vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
	vector4 v2(5.0f, 6.0f, 7.0f, 8.0f);

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;

	v1.add(v2);
	std::cout << "v1 += v2: " << v1 << std::endl;
	v1.sub(v2);
	std::cout << "v1 -= v2: " << v1 << std::endl;
	v1.add(1.0f, 2.0f, 3.0f);
	std::cout << "v1 += (1.0, 2.0, 3.0): " << v1 << std::endl;
	v1.sub(1.0f, 2.0f, 3.0f);
	std::cout << "v1 -= (1.0, 2.0, 3.0): " << v1 << std::endl;
	v1.sub(v2);
	std::cout << "v1 -= v2: " << v1 << std::endl;

	return 0;
}