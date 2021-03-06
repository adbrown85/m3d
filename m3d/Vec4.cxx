/*
 * Copyright (c) 2012, Andrew Brown
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include "config.h"
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "m3d/Vec4.h"
using namespace std;
namespace M3d {

/**
 * Constructs a vector filled with all zeros.
 */
Vec4::Vec4() : x(0), y(0), z(0), w(0) {
    // pass
}

/**
 * Constructs a vector filled with a single value.
 *
 * @param d Value to store in each component
 */
Vec4::Vec4(double d) : x(d), y(d), z(d), w(d) {
    // pass
}

/**
 * Constructs a vector from a three-component vector and a fourth value.
 *
 * @param v Three-component vector to copy first three components from
 * @param w Value for fourth component
 */
Vec4::Vec4(const Vec3 &v, double w) : x(v.x), y(v.y), z(v.z), w(w) {
    // pass
}

/**
 * Constructs a vector from four values.
 *
 * @param x Value for X component
 * @param y Value for Y component
 * @param z Value for Z component
 * @param w Value for W component
 */
Vec4::Vec4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {
    // pass
}

/**
 * Constructs a vector from a double array.
 *
 * @param arr Double array to make vector from
 */
Vec4::Vec4(double arr[4]) : x(arr[0]), y(arr[1]), z(arr[2]), w(arr[3]) {
    // pass
}

/**
 * Constructs a vector from a float array.
 *
 * @param arr Float array to make vector from
 */
Vec4::Vec4(float arr[4]) : x(arr[0]), y(arr[1]), z(arr[2]), w(arr[3]) {
    // pass
}

/**
 * Computes the dot product of two vectors.
 *
 * @param u First vector
 * @param v Second vector
 * @return Projection of one vector onto another
 */
double dot(const Vec4 &u, const Vec4 &v) {

    const double xx = u.x * v.x;
    const double yy = u.y * v.y;
    const double zz = u.z * v.z;
    const double ww = u.w * v.w;

    return xx + yy + zz + ww;
}

/**
 * Calculates the length of a vector.
 *
 * @param v Vector to compute length of
 * @return Length of the vector
 */
double length(const Vec4 &v) {

    const double xx = v.x * v.x;
    const double yy = v.y * v.y;
    const double zz = v.z * v.z;
    const double ww = v.w * v.w;

    return sqrt(xx + yy + zz + ww);
}

/**
 * Finds the maximum component of a vector.
 *
 * @param v Vector to find maximum component of
 * @return Maximum component of vector
 */
double max(const Vec4& v) {
    return std::max(std::max(std::max(v.x, v.y), v.z), v.w);
}

/**
 * Computes a component-wise maximum of two vectors.
 *
 * @param u First vector
 * @param v Second vector
 * @return Copy of resulting vector
 */
Vec4 max(const Vec4 &u, const Vec4 &v) {

    const double x = std::max(u.x, v.x);
    const double y = std::max(u.y, v.y);
    const double z = std::max(u.z, v.z);
    const double w = std::max(u.w, v.w);

    return Vec4(x, y, z, w);
}

/**
 * Finds the minimum component of a vector.
 *
 * @param v Vector to find minimum component of
 * @return Minimum component of vector
 */
double min(const Vec4 &v) {
    return std::min(std::min(std::min(v.x, v.y), v.z), v.w);
}

/**
 * Computes a component-wise minimum of two vectors.
 *
 * @param u First vector
 * @param v Second vector
 * @return Copy of resulting vector
 */
Vec4 min(const Vec4 &u, const Vec4 &v) {

    const double x = std::min(u.x, v.x);
    const double y = std::min(u.y, v.y);
    const double z = std::min(u.z, v.z);
    const double w = std::min(u.w, v.w);

    return Vec4(x, y, z, w);
}

/**
 * Computes a unit-length direction vector from a vector.
 *
 * @param v Vector to compute direction from
 * @return Copy of resulting vector
 */
Vec4 normalize(const Vec4 &v) {

    const double len = length(v);
    const double x = v.x / len;
    const double y = v.y / len;
    const double z = v.z / len;
    const double w = v.w / len;

    return Vec4(x, y, z, w);
}

/**
 * Returns a copy of a component in this vector by index.
 *
 * @param i Index of component
 * @return Copy of the component
 * @throw std::out_of_range if the index is out of bounds
 */
double Vec4::operator[](int i) const {
    switch (i) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    case 3: return w;
    default:
        throw out_of_range("[Vec4] Index out of bounds!");
    }
}

/**
 * Accesses a component in this vector by index.
 *
 * @param i Index of component
 * @return Reference to the component
 * @throw std::out_of_range if the index is out of bounds
 */
double& Vec4::operator[](int i) {
    switch (i) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    case 3: return w;
    default:
        throw out_of_range("[Vec4] Index out of bounds!");
    }
}

/**
 * Checks if another vector is equal to this one.
 *
 * @param v Vector to check
 * @return `true` if vectors are equal
 */
bool Vec4::operator==(const Vec4 &v) const {
    return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
}

/**
 * Checks if another vector is not equal to this one.
 *
 * @param v Vector to check
 * @return `true` if vectors are not equal
 */
bool Vec4::operator!=(const Vec4 &v) const {
    return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
}

/**
 * Returns a copy of the vector with the same sign.
 */
Vec4 Vec4::operator+() const {
    return Vec4(x, y, z, w);
}

/**
 * Returns the additive inverse of a vector.
 */
Vec4 Vec4::operator-() const {
    return Vec4(-x, -y, -z, -w);
}

/**
 * Adds a value to this vector, making a new vector.
 *
 * @param d Value to add
 * @return Copy of resulting vector
 */
Vec4 Vec4::operator+(double d) const {
    return Vec4((x + d), (y + d), (z + d), (w + d));
}

/**
 * Adds another vector to this vector, making a new vector.
 *
 * @param v Vector to add
 * @return Copy of resulting vector
 */
Vec4 Vec4::operator+(const Vec4 &v) const {
    return Vec4((x + v.x), (y + v.y), (z + v.z), (w + v.w));
}

/**
 * Adds a value to this vector, modifying this vector.
 *
 * @param d Value to add
 * @return Reference to this vector to support chaining
 */
Vec4& Vec4::operator+=(double d) {
    x += d;
    y += d;
    z += d;
    w += d;
    return *this;
}

/**
 * Adds another vector to this vector, modifying this vector.
 *
 * @param v Vector to add
 * @return Reference to this vector to support chaining
 */
Vec4& Vec4::operator+=(const Vec4 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

/**
 * Subtracts a value from this vector, making a new vector.
 *
 * @param d Value to subtract
 * @return Copy of resulting vector
 */
Vec4 Vec4::operator-(double d) const {
    return Vec4((x - d), (y - d), (z - d), (w - d));
}

/**
 * Subtracts another vector from this vector, making a new vector.
 *
 * @param v Vector to subtract
 * @return Copy of resulting vector
 */
Vec4 Vec4::operator-(const Vec4 &v) const {
    return Vec4((x - v.x), (y - v.y), (z - v.z), (w - v.w));
}

/**
 * Subtracts a value from this vector, modifying this vector.
 *
 * @param d Value to subtract
 * @return Reference to this vector to support chaining
 */
Vec4& Vec4::operator-=(double d) {
    x -= d;
    y -= d;
    z -= d;
    w -= d;
    return *this;
}

/**
 * Subtracts another vector from this vector, modifying this vector.
 *
 * @param v Vector to subtract
 * @return Reference to this vector to support chaining
 */
Vec4& Vec4::operator-=(const Vec4 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

/**
 * Multiplies this vector by a value, making a new vector.
 *
 * @param d Value to multiply by
 * @return Copy of resulting vector
 */
Vec4 Vec4::operator*(double d) const {
    return Vec4((x * d), (y * d), (z * d), (w * d));
}

/**
 * Multiplies this vector by another vector, making a new vector.
 *
 * @param v Vector to multiply by
 * @return Copy of resulting vector
 */
Vec4 Vec4::operator*(const Vec4 &v) const {
    return Vec4((x * v.x), (y * v.y), (z * v.z), (w * v.w));
}

/**
 * Multiplies this vector by another vector, modifying this vector.
 *
 * @param v Vector to multiply by
 * @return Reference to this vector to support chaining
 */
Vec4& Vec4::operator*=(const Vec4 &v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w *= v.w;
    return *this;
}

/**
 * Multiplies this vector by a value, modifying this vector.
 *
 * @param d Value to multiply by
 * @return Reference to this vector to support chaining
 */
Vec4& Vec4::operator*=(double d) {
    x *= d;
    y *= d;
    z *= d;
    w *= d;
    return *this;
}

/**
 * Divides this vector by a value, making a new vector.
 *
 * @param d Value to divide by
 * @return Copy of resulting vector
 */
Vec4 Vec4::operator/(double d) const {
    return Vec4((x / d), (y / d), (z / d), (w / d));
}

/**
 * Divides this vector by another vector, making a new vector.
 *
 * @param v Vector to divide by
 * @return Copy of resulting vector
 */
Vec4 Vec4::operator/(const Vec4 &v) const {
    return Vec4((x / v.x), (y / v.y), (z / v.z), (w / v.w));
}

/**
 * Divides this vector by a value, modifying this vector.
 *
 * @param d Value to divide by
 * @return Reference to this vector to support chaining
 */
Vec4& Vec4::operator/=(double d) {
    x /= d;
    y /= d;
    z /= d;
    w /= d;
    return *this;
}

/**
 * Divides this vector by another vector, modifying this vector.
 *
 * @param v Vector to divide by
 * @return Reference to this vector to support chaining
 */
Vec4& Vec4::operator/=(const Vec4 &v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    w /= v.w;
    return *this;
}

/**
 * Copies the vector's components to a double array.
 *
 * @param arr Double array to copy to
 */
void Vec4::toArray(double arr[4]) {
    arr[0] = x;
    arr[1] = y;
    arr[2] = z;
    arr[3] = w;
}

/**
 * Copies the vector's components to a float array.
 *
 * @param arr Float array to copy to
 */
void Vec4::toArray(float arr[4]) {
    arr[0] = (float) x;
    arr[1] = (float) y;
    arr[2] = (float) z;
    arr[3] = (float) w;
}

/**
 * Returns a string representation of this vector.
 */
string Vec4::toString() const {

    stringstream stream;

    stream << (*this);
    return stream.str();
}

/**
 * Creates a vector from the first three components of this vector.
 *
 * @return Vector with a copy of the first three components of this vector
 */
Vec3 Vec4::toVec3() const {
    return Vec3(x, y, z);
}

} /* namespace M3d */

/**
 * Appends a vector to a stream.
 *
 * @param out Stream to append to
 * @param v Vector to append
 * @return Reference to the stream
 */
ostream& operator<<(ostream &out, const M3d::Vec4 &v) {
    out << "[";
    out << v.x << ", " << v.y << ", " << v.z << ", " << v.w;
    out << "]";
    return out;
}
