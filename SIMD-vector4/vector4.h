#pragma once

#include <xmmintrin.h>
#include <iostream>
#include <cmath>

// two decisions I made:
// 1. in-place operations for better efficiency and chaining available (and because it's implied in the task)
// 2. internal data as __m128 for better efficiency (although the opposite is implied in the task)

class vector4 {
private:
    __m128 v;

    float get(size_t index) const {
        alignas(16) float arr[4];
        _mm_store_ps(arr, v);
        return arr[index];
    }

public:
    vector4(float x, float y, float z);
    vector4(float x, float y, float z, float w);

    float x() const;
    float y() const;
    float z() const;
    float w() const;

    vector4& add(const vector4& other);
    vector4& add(float x, float y, float z);
    vector4& sub(const vector4& other);
    vector4& sub(float x, float y, float z);

    vector4& mul(float scale);
    vector4& mul(float scale, float w_scale);
    vector4& div(float scale);
    vector4& div(float scale, float w_scale);

    float dot(const vector4& other) const;
    float dot(float x, float y, float z) const;

    float magnitude() const;
    float magnitude_squared() const;

    vector4& normalize();

    friend std::ostream& operator<<(std::ostream& os, const vector4& v);
};
