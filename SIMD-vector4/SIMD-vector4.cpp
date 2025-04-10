#include <iostream>
#include <xmmintrin.h>

// two decisions I made:
// 1. in-place operations for better efficiency and chaining available (and because it's implied in the task)
// 2. internal data as __m128 for better efficiency (although the opposite is implied in the task)

struct vector4 {
private:
	__m128 v;

	float get(size_t index) const {
		alignas(16) float arr[4];
		_mm_store_ps(arr, v);
		return arr[index];
	}

public:
	vector4(float x, float y, float z) : v(_mm_set_ps(0.0f, z, y, x)) {}
	vector4(float x, float y, float z, float w) : v(_mm_set_ps(w, z, y, x)) {}

	float x() const { return _mm_cvtss_f32(v); }
	float y() const { return get(1); }
	float z() const { return get(2); }
	float w() const { return get(3); }

	vector4& add(const vector4& other) {
		v = _mm_add_ps(v, other.v);
		return *this;
	}
	vector4& add(float x, float y, float z) {
		__m128 tht = _mm_set_ps(0.0f, z, y, x);
		v = _mm_add_ps(v, tht);
		return *this;
	}

	vector4& sub(const vector4& other) {
		v = _mm_sub_ps(v, other.v);
		return *this;
	}
	vector4& sub(float x, float y, float z) {
		__m128 tht = _mm_set_ps(0.0f, z, y, x);
		v = _mm_sub_ps(v, tht);
		return *this;
	}

	vector4& mul(float scale) {
		__m128 tht = _mm_set_ps1(scale);
		v = _mm_mul_ps(v, tht);
		return *this;
	}
	vector4& mul(float scale, float w_scale) {
		__m128 tht = _mm_set_ps(w_scale, scale, scale, scale);
		v = _mm_mul_ps(v, tht);
		return *this;
	}

	vector4& div(float scale) {
		__m128 tht = _mm_set_ps1(scale);
		v = _mm_div_ps(v, tht);
		return *this;
	}
	vector4& div(float scale, float w_scale) {
		__m128 tht = _mm_set_ps(w_scale, scale, scale, scale);
		v = _mm_div_ps(v, tht);
		return *this;
	}


	float dot(const vector4& other) const {
		__m128 tht = _mm_mul_ps(v, other.v);
		alignas(16) float arr[4];
		_mm_store_ps(arr, tht);
		return arr[0] + arr[1] + arr[2] + arr[3];
	}
	float dot(float x, float y, float z) const {
		__m128 tht = _mm_set_ps(0.0f, z, y, x);
		__m128 res = _mm_mul_ps(v, tht);
		alignas(16) float arr[4];
		_mm_store_ps(arr, res);
		return arr[0] + arr[1] + arr[2] + arr[3];
	}

	float magnitude() const {
		return std::sqrt(dot(*this));
	}
	float magnitude_squared() const {
		return dot(*this);
	}

	static friend std::ostream& operator<<(std::ostream& os, const vector4& v) {
		os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ", " << v.w() << ")";
		return os;
	}
};

static void test_vector4_add_sub(vector4& v1, vector4& v2) {
	v1.add(v2);
	std::cout << "v1 += v2: " << v1 << std::endl;
	v1.sub(v2);
	std::cout << "v1 -= v2: " << v1 << std::endl;
	v1.add(1.0f, 2.0f, 3.0f);
	std::cout << "v1 += (1.0, 2.0, 3.0): " << v1 << std::endl;
	v1.sub(1.0f, 2.0f, 3.0f);
	std::cout << "v1 -= (1.0, 2.0, 3.0): " << v1 << std::endl;
	v1.sub(v2);
	std::cout << "v1 -= v2: " << v1 << "\n\n";
}

static void test_vector4_mul_div(vector4& v1, vector4& v2) {
	v1.mul(2.0f);
	std::cout << "v1 *= 2.0: " << v1 << std::endl;
	v1.div(2.0f);
	std::cout << "v1 /= 2.0: " << v1 << std::endl;
	v1.mul(2.0f, 3.0f);
	std::cout << "v1 *= (2.0, 3.0): " << v1 << std::endl;
	v1.div(2.0f, 3.0f);
	std::cout << "v1 /= (2.0, 3.0): " << v1 << "\n\n";
}

static void test_vector4_dot(vector4& v1, vector4& v2) {
	std::cout << "v1 . v2: " << v1.dot(v2) << std::endl;
	std::cout << "v1 . (1.0, 2.0, 3.0): " << v1.dot(1.0f, 2.0f, 3.0f) << std::endl;
	std::cout << "(1.0, 2.0, 3.0) . v2: " << v2.dot(1.0f, 2.0f, 3.0f) << "\n\n";
}

static void test_vector4_magnitude(vector4& v1) {
	std::cout << "v1 magnitude: " << v1.magnitude() << std::endl;
	std::cout << "v1 magnitude squared: " << v1.magnitude_squared() << "\n\n";
}

int main()
{

	vector4 v1(1.0f, 2.0f, 3.0f, 0.0f);
	vector4 v2(5.0f, 6.0f, 7.0f, 0.0f);

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << "\n\n";

	test_vector4_add_sub(v1, v2);
	test_vector4_mul_div(v1, v2);
	test_vector4_dot(v1, v2);
	test_vector4_magnitude(v1);

	return 0;
}