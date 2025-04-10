#include <iostream>
#include <xmmintrin.h>
#include "vector4.h"
#include "check_vector4.cpp"

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
	test_vector4_normalize(v1);

	return 0;
}