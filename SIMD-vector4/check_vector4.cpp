#include "vector4.h"

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

static void test_vector4_normalize(vector4& v1) {
	v1.normalize();
	std::cout << "v1 normalized: " << v1 << std::endl;
	std::cout << "v1 magnitude: " << v1.magnitude() << std::endl;
	std::cout << "v1 magnitude squared: " << v1.magnitude_squared() << "\n\n";
}