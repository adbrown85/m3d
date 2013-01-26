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
#ifndef M3D_QUAT_H
#define M3D_QUAT_H
#include "m3d/common.h"
#include <cmath>
#include <iomanip>
#include <sstream>
#include "m3d/Mat3.h"
#include "m3d/Mat4.h"
#include "m3d/Vec3.h"
namespace M3d {


/**
 * Encapsulation of an axis/angle rotation.
 */
class Quat {
public:
// Attributes
    double x; ///< First component of quaternion's vector part
    double y; ///< Second component of quaternion's vector part
    double z; ///< Third component of quaternion's vector part
    double w; ///< Scalar part of quaternion
// Methods
    Quat();
    Quat(double x, double y, double z, double w);
    static Quat fromAxisAngle(const Vec3& axis, const double angle);
    static Quat fromMat3(const Mat3& m);
    static Quat fromMat4(const Mat4& m);
    static Quat identity();
    bool isIdentity() const;
    bool isInfinite() const;
    bool isNaN() const;
    bool operator==(const Quat& q) const;
    bool operator!=(const Quat& q) const;
    double operator[](int i) const;
    double& operator[](int i);
    Quat operator+() const;
    Quat operator-() const;
    Quat operator+(const Quat& q) const;
    Quat operator-(const Quat& q) const;
    Quat operator*(const Quat& q) const;
    Mat3 toMat3() const;
    Mat4 toMat4() const;
    std::string toString() const;
// Friends
    friend Quat conjugate(const Quat& q);
    friend double magnitude(const Quat& q);
    friend Quat normalize(const Quat& q);
};

Quat conjugate(const Quat& q);
double magnitude(const Quat& q);
Quat normalize(const Quat& q);

} /* namespace M3d */

std::ostream& operator<<(std::ostream& stream, const M3d::Quat& q);

#endif
