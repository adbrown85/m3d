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
#ifndef M3D_MAT3_HXX
#define M3D_MAT3_HXX
#include <iostream>
#include "m3d/common.h"
#include "m3d/Vec3.hxx"
namespace M3d {


/**
 * Three-by-three matrix for 3D graphics.
 */
class Mat3 {
public:
// Constants
    static const int ORDER = 3; ///< Number of rows and columns
    static const int ORDER_SQUARED = 9; ///< Number of elements in matrix
// Methods
    explicit Mat3();
    explicit Mat3(const double value);
    static Mat3 fromArrayInColumnMajor(const float arr[9]);
    static Mat3 fromArrayInColumnMajor(const double arr[9]);
    static Mat3 fromArrayInColumnMajor(const double arr[3][3]);
    static Mat3 fromArrayInColumnMajor(const float arr[3][3]);
    static Mat3 fromArrayInRowMajor(const float arr[9]);
    static Mat3 fromArrayInRowMajor(const double arr[9]);
    static Mat3 fromArrayInRowMajor(const float arr[3][3]);
    static Mat3 fromArrayInRowMajor(const double arr[3][3]);
    static Mat3 fromColumns(const Vec3& c1, const Vec3& c2, const Vec3& c3);
    static Mat3 fromRows(const Vec3& r1, const Vec3& r2, const Vec3& r3);
    Vec3 getColumn(const int j) const;
    Vec3 getRow(const int i) const;
    void toArrayInColumnMajor(double arr[3][3]) const;
    void toArrayInColumnMajor(float arr[3][3]) const;
    void toArrayInColumnMajor(double arr[9]) const;
    void toArrayInColumnMajor(float arr[9]) const;
    void toArrayInRowMajor(double arr[9]) const;
    void toArrayInRowMajor(float arr[9]) const;
    void toArrayInRowMajor(double arr[3][3]) const;
    void toArrayInRowMajor(float arr[3][3]) const;
    std::string toString() const;
// Operators
    bool operator==(const Mat3& mat) const;
    bool operator!=(const Mat3& mat) const;
    const Vec3& operator[](int j) const;
    Vec3& operator[](int j);
    Mat3 operator*(const Mat3& mat) const;
    Vec3 operator*(const Vec3& vec) const;
// Friends
    friend Mat3 inverse(const Mat3& mat);
    friend Mat3 transpose(const Mat3& mat);
    friend class Mat3Test;
    friend class Mat4;
private:
// Types
    typedef std::pair<int,int> index_t;
    class SignChart;
    class MinorChart;
// Constants
    static const int ORDER_MINUS_ONE = 2;
    static const int ORDER_MINUS_ONE_SQUARED = 4;
    static const MinorChart MINOR_CHART;
    static const SignChart SIGN_CHART;
// Helpers
    static double findDeterminant(double arr[2][2]);
    double findMinor(const int i, const int j) const;
// Attributes
    Vec3 columns[3];
};


/*
 * Chart containing indices for computing matrix of minors.
 */
class Mat3::MinorChart {
public:
// Methods
    explicit MinorChart();
    const index_t* operator()(const int i, const int j) const;
private:
// Attributes
    index_t indices[ORDER][ORDER][ORDER_MINUS_ONE_SQUARED];
// Helpers
    static void findIndices(index_t* idx, const int row, const int col);
};


/*
 * Chart containing indices for computing matrix of cofactors.
 */
class Mat3::SignChart {
public:
// Methods
    explicit SignChart();
    int operator()(const int i, const int j) const;
private:
// Attributes
    int signs[ORDER][ORDER];
};

} /* namespace M3d */

std::ostream& operator<<(std::ostream &stream, const M3d::Mat3& mat);
#endif
