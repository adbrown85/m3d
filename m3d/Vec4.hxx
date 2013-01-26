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
#ifndef M3D_VEC4_HXX
#define M3D_VEC4_HXX
#include "m3d/common.h"
#include "m3d/Vec3.hxx"
namespace M3d {


/**
 * Four-component vector for 3D graphics.
 */
class Vec4 {
public:
    double x; ///< X coordinate
    double y; ///< Y coordinate
    double z; ///< Z coordinate
    double w; ///< Homogeneous coordinate
public:
    explicit Vec4();
    explicit Vec4(double d);
    explicit Vec4(const Vec3& v, double w);
    explicit Vec4(double x, double y, double z, double w);
    explicit Vec4(double arr[4]);
    explicit Vec4(float arr[4]);
    double operator[](int i) const;
    double& operator[](int i);
    bool operator==(const Vec4 &v) const;
    bool operator!=(const Vec4 &v) const;
    Vec4 operator+() const;
    Vec4 operator-() const;
    Vec4 operator+(double f) const;
    Vec4 operator+(const Vec4 &v) const;
    Vec4& operator+=(double f);
    Vec4& operator+=(const Vec4 &v);
    Vec4 operator-(double f) const;
    Vec4 operator-(const Vec4 &v) const;
    Vec4& operator-=(const Vec4 &v);
    Vec4& operator-=(double f);
    Vec4 operator*(const Vec4 &v) const;
    Vec4 operator*(double f) const;
    Vec4& operator*=(double f);
    Vec4& operator*=(const Vec4 &v);
    Vec4 operator/(const Vec4 &v) const;
    Vec4 operator/(double f) const;
    Vec4& operator/=(const Vec4 &v);
    Vec4& operator/=(double f);
    void toArray(double arr[4]);
    void toArray(float arr[4]);
    std::string toString() const;
    Vec3 toVec3() const;
// Friends
    friend double dot(const Vec4& u, const Vec4 &v);
    friend double length(const Vec4 &v);
    friend double min(const Vec4 &v);
    friend Vec4 min(const Vec4 &u, const Vec4 &v);
    friend double max(const Vec4 &v);
    friend Vec4 max(const Vec4 &u, const Vec4 &v);
    friend Vec4 normalize(const Vec4 &v);
};

double dot(const Vec4& u, const Vec4 &v);
double length(const Vec4 &v);
double min(const Vec4 &v);
Vec4 min(const Vec4 &u, const Vec4 &v);
double max(const Vec4 &v);
Vec4 max(const Vec4 &u, const Vec4 &v);
Vec4 normalize(const Vec4 &v);

} // namespace M3d

std::ostream& operator<<(std::ostream& out, const M3d::Vec4& u);
#endif
