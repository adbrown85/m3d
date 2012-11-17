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
#ifndef M3D_VEC3_HXX
#define M3D_VEC3_HXX
#include "m3d/common.h"
#include <cmath>
#include <iomanip>
namespace M3d {


/**
 * Three-component vector for 3D graphics.
 */
class Vec3 {
public:
// Attributes
    double x; ///< X coordinate
    double y; ///< Y coordinate
    double z; ///< Z coordinate
// Methods
    explicit Vec3();
    explicit Vec3(double d);
    explicit Vec3(double x, double y, double z);
    explicit Vec3(double arr[3]);
    explicit Vec3(float arr[3]);
    double operator[](int i) const;
    double& operator[](int i);
    Vec3 operator+() const;
    Vec3 operator-() const;
    bool operator==(const Vec3 &v) const;
    bool operator!=(const Vec3 &v) const;
    Vec3 operator+(double d) const;
    Vec3 operator+(const Vec3 &v) const;
    Vec3& operator+=(double d);
    Vec3& operator+=(const Vec3 &v);
    Vec3 operator-(const Vec3 &v) const;
    Vec3 operator-(double d) const;
    Vec3& operator-=(double d);
    Vec3& operator-=(const Vec3 &v);
    Vec3 operator*(double d) const;
    Vec3 operator*(const Vec3 &v) const;
    Vec3& operator*=(double d);
    Vec3& operator*=(const Vec3 &v);
    Vec3 operator/(double d) const;
    Vec3 operator/(const Vec3 &v) const;
    Vec3& operator/=(double d);
    Vec3& operator/=(const Vec3 &v);
    void toArray(double arr[3]) const;
    void toArray(float arr[3]) const;
    std::string toString() const;
// Friends
    friend Vec3 cross(const Vec3 &u, const Vec3 &v);
    friend double dot(const Vec3 &u, const Vec3 &v);
    friend double length(const Vec3 &v);
    friend Vec3 max(const Vec3 &u, const Vec3 &v);
    friend double max(const Vec3 &v);
    friend Vec3 min(const Vec3 &u, const Vec3 &v);
    friend double min(const Vec3 &v);
    friend Vec3 normalize(const Vec3 &v);
};

} // namespace M3d

std::ostream& operator<<(std::ostream &out, const M3d::Vec3 &u);
#endif
