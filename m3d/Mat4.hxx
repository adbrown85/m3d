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
#ifndef M3D_MAT4_HXX
#define M3D_MAT4_HXX
#include "m3d/common.h"
#include "m3d/Mat3.hxx"
#include "m3d/Vec4.hxx"
namespace M3d {


/**
 * Four-by-four matrix for 3D graphics.
 */
class Mat4 {
public:
// Constants
    static const int ORDER = 4; ///< Number of rows and columns
    static const int ORDER_SQUARED = 16; ///< Number of elements in matrix
// Methods
    explicit Mat4();
    explicit Mat4(const double value);
    explicit Mat4(const Mat3& mat);
    static Mat4 fromArrayInColumnMajor(const double[16]);
    static Mat4 fromArrayInColumnMajor(const float[16]);
    static Mat4 fromArrayInColumnMajor(const double[4][4]);
    static Mat4 fromArrayInColumnMajor(const float[4][4]);
    static Mat4 fromArrayInRowMajor(const double[16]);
    static Mat4 fromArrayInRowMajor(const float[16]);
    static Mat4 fromArrayInRowMajor(const double[4][4]);
    static Mat4 fromArrayInRowMajor(const float[4][4]);
    static Mat4 fromColumns(const Vec4& c1, const Vec4& c2, const Vec4& c3, const Vec4& c4);
    static Mat4 fromRows(const Vec4& r1, const Vec4& r2, const Vec4& r3, const Vec4& r4);
    Vec4 getColumn(const int j) const;
    Vec4 getRow(const int i) const;
    void toArrayInColumnMajor(double arr[4][4]) const;
    void toArrayInColumnMajor(float arr[4][4]) const;
    void toArrayInColumnMajor(double arr[16]) const;
    void toArrayInColumnMajor(float arr[16]) const;
    void toArrayInRowMajor(double arr[16]) const;
    void toArrayInRowMajor(float arr[16]) const;
    void toArrayInRowMajor(double arr[4][4]) const;
    void toArrayInRowMajor(float arr[4][4]) const;
    Mat3 toMat3() const;
    std::string toString() const;
// Operators
    bool operator==(const Mat4& mat) const;
    bool operator!=(const Mat4& mat) const;
    const Vec4& operator[](int j) const;
    Vec4& operator[](int j);
    Mat4 operator*(const Mat4& mat) const;
    Vec4 operator*(const Vec4& vec) const;
// Friends
    friend Mat4 inverse(const Mat4& mat);
    friend Mat4 transpose(const Mat4& mat);
    friend class Mat4Test;
private:
// Types
    typedef std::pair<int,int> index_t;
    class MinorChart;
    class SignChart;
// Constants
    static const SignChart SIGN_CHART;
    static const MinorChart MINOR_CHART;
    static const int ORDER_MINUS_ONE = 3;
    static const int ORDER_MINUS_ONE_SQUARED = 9;
// Attributes
    Vec4 columns[4];
// Helpers
    double findMinor(const int row, const int col) const;
    static double findDeterminant(const double [3][3]);
};


/*
 * Chart containing indices for computing matrix of minors.
 */
class Mat4::MinorChart {
public:
// Methods
    explicit MinorChart();
    const index_t* operator()(const int i, const int j) const;
private:
// Attributes
    index_t indices[4][4][9];
// Helpers
    static void findIndices(index_t *idx, const int row, const int col);
};


/*
 * Chart containing signs for computing matrix of cofactors.
 */
class Mat4::SignChart {
public:
// Methods
    explicit SignChart();
    int operator()(const int i, const int j) const;
private:
// Attributes
    int signs[4][4];
};

Mat4 inverse(const Mat4& mat);
Mat4 transpose(const Mat4& mat);

} /* namespace M3d */

std::ostream& operator<<(std::ostream &stream, const M3d::Mat4& mat);

#endif
