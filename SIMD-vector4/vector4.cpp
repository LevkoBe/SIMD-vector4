#include "vector4.h"

vector4::vector4(float x, float y, float z) : v(_mm_set_ps(0.0f, z, y, x)) {}
vector4::vector4(float x, float y, float z, float w) : v(_mm_set_ps(w, z, y, x)) {}

float vector4::x() const { return _mm_cvtss_f32(v); }
float vector4::y() const { return get(1); }
float vector4::z() const { return get(2); }
float vector4::w() const { return get(3); }

vector4& vector4::add(const vector4& other) {
    v = _mm_add_ps(v, other.v);
    return *this;
}
vector4& vector4::add(float x, float y, float z) {
    __m128 tht = _mm_set_ps(0.0f, z, y, x);
    v = _mm_add_ps(v, tht);
    return *this;
}

vector4& vector4::sub(const vector4& other) {
    v = _mm_sub_ps(v, other.v);
    return *this;
}
vector4& vector4::sub(float x, float y, float z) {
    __m128 tht = _mm_set_ps(0.0f, z, y, x);
    v = _mm_sub_ps(v, tht);
    return *this;
}

vector4& vector4::mul(float scale) {
    __m128 tht = _mm_set_ps1(scale);
    v = _mm_mul_ps(v, tht);
    return *this;
}
vector4& vector4::mul(float scale, float w_scale) {
    __m128 tht = _mm_set_ps(w_scale, scale, scale, scale);
    v = _mm_mul_ps(v, tht);
    return *this;
}

vector4& vector4::div(float scale) {
    __m128 tht = _mm_set_ps1(scale);
    v = _mm_div_ps(v, tht);
    return *this;
}
vector4& vector4::div(float scale, float w_scale) {
    __m128 tht = _mm_set_ps(w_scale, scale, scale, scale);
    v = _mm_div_ps(v, tht);
    return *this;
}

float vector4::dot(const vector4& other) const {
    __m128 tht = _mm_mul_ps(v, other.v);
    alignas(16) float arr[4];
    _mm_store_ps(arr, tht);
    return arr[0] + arr[1] + arr[2] + arr[3];
}

float vector4::dot(float x, float y, float z) const {
    __m128 tht = _mm_set_ps(0.0f, z, y, x);
    __m128 res = _mm_mul_ps(v, tht);
    alignas(16) float arr[4];
    _mm_store_ps(arr, res);
    return arr[0] + arr[1] + arr[2] + arr[3];
}

float vector4::magnitude() const {
    return std::sqrt(dot(*this));
}

float vector4::magnitude_squared() const {
    return dot(*this);
}

vector4& vector4::normalize() {
    float mag = magnitude();
    if (mag != 0.0f) v = _mm_div_ps(v, _mm_set_ps1(mag));
    return *this;
}

std::ostream& operator<<(std::ostream& os, const vector4& v) {
    os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ", " << v.w() << ")";
    return os;
}
