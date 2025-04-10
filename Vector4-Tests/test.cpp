#include "pch.h"
#include <gtest/gtest.h>  
#include "../SIMD-vector4/vector4.h"

TEST(Vector4Test, AddAndSub) {
	vector4 v1(1.0f, 2.0f, 3.0f, 0.0f);
	vector4 v2(5.0f, 6.0f, 7.0f, 0.0f);

	v1.add(v2);
	EXPECT_FLOAT_EQ(v1.x(), 6.0f);
	EXPECT_FLOAT_EQ(v1.y(), 8.0f);
	EXPECT_FLOAT_EQ(v1.z(), 10.0f);

	v1.sub(v2);
	EXPECT_FLOAT_EQ(v1.x(), 1.0f);
	EXPECT_FLOAT_EQ(v1.y(), 2.0f);
	EXPECT_FLOAT_EQ(v1.z(), 3.0f);
}

TEST(Vector4Test, MulAndDiv) {
	vector4 v1(1.0f, 2.0f, 3.0f, 0.0f);

	v1.mul(2.0f);
	EXPECT_FLOAT_EQ(v1.x(), 2.0f);
	EXPECT_FLOAT_EQ(v1.y(), 4.0f);
	EXPECT_FLOAT_EQ(v1.z(), 6.0f);

	v1.div(2.0f);
	EXPECT_FLOAT_EQ(v1.x(), 1.0f);
	EXPECT_FLOAT_EQ(v1.y(), 2.0f);
	EXPECT_FLOAT_EQ(v1.z(), 3.0f);
}

TEST(Vector4Test, DotProduct) {
	vector4 v1(1.0f, 2.0f, 3.0f, 0.0f);
	vector4 v2(4.0f, 5.0f, 6.0f, 0.0f);

	EXPECT_FLOAT_EQ(v1.dot(v2), 32.0f);
}

TEST(Vector4Test, Magnitude) {
	vector4 v1(3.0f, 4.0f, 0.0f, 0.0f);
	EXPECT_FLOAT_EQ(v1.magnitude(), 5.0f);
}

TEST(Vector4Test, Normalize) {
	vector4 v1(3.0f, 4.0f, 0.0f, 0.0f);
	v1.normalize();
	EXPECT_FLOAT_EQ(v1.magnitude(), 1.0f);
	EXPECT_FLOAT_EQ(v1.magnitude_squared(), 1.0f);
}
