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
#include "m3d/common.h"
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include "m3d/Mat3.h"
using namespace std;
namespace M3d {

/*
 * Constants
 */
const double TOLERANCE = 1e-9;


/**
 * Unit test for Mat3.
 */
class Mat3Test : public CppUnit::TestFixture {
private:
    Mat3 m1, m2, m3;
public:

    /**
     * Prepares the fixture before running each test case.
     */
    void setUp() {

        double arr[3][3];
        arr[0][0] = 1; arr[1][0] = 6; arr[2][0] = 5;
        arr[0][1] = 7; arr[1][1] = 2; arr[2][1] = 8;
        arr[0][2] = 4; arr[1][2] = 9; arr[2][2] = 3;

        m1 = Mat3::fromArrayInColumnMajor(arr);
        m2 = Mat3(1.0);
        m3 = Mat3(1.0);
    }

    /**
     * Ensures the sign chart used for calculating a matrix of cofactors was set up correctly.
     */
    void testCreateSignChart() {
        CPPUNIT_ASSERT_EQUAL(+1, Mat3::SIGN_CHART(0,0));
        CPPUNIT_ASSERT_EQUAL(-1, Mat3::SIGN_CHART(0,1));
        CPPUNIT_ASSERT_EQUAL(+1, Mat3::SIGN_CHART(0,2));
        CPPUNIT_ASSERT_EQUAL(-1, Mat3::SIGN_CHART(1,0));
        CPPUNIT_ASSERT_EQUAL(+1, Mat3::SIGN_CHART(1,1));
        CPPUNIT_ASSERT_EQUAL(-1, Mat3::SIGN_CHART(1,2));
        CPPUNIT_ASSERT_EQUAL(+1, Mat3::SIGN_CHART(2,0));
        CPPUNIT_ASSERT_EQUAL(-1, Mat3::SIGN_CHART(2,1));
        CPPUNIT_ASSERT_EQUAL(+1, Mat3::SIGN_CHART(2,2));
    }

    /**
     * Ensures the chart used for calculating a matrix of minors was set up correctly.
     */
    void testCreateMinorChart() {

        typedef Mat3::index_t index_t;
        const index_t *idx;

        // Index 0,0
        idx = Mat3::MINOR_CHART(0,0);
        CPPUNIT_ASSERT_EQUAL(index_t(1,1), idx[0]);
        CPPUNIT_ASSERT_EQUAL(index_t(1,2), idx[1]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,1), idx[2]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,2), idx[3]);

        // Index 0,1
        idx = Mat3::MINOR_CHART(0,1);
        CPPUNIT_ASSERT_EQUAL(index_t(1,0), idx[0]);
        CPPUNIT_ASSERT_EQUAL(index_t(1,2), idx[1]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,0), idx[2]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,2), idx[3]);

        // Index 0,2
        idx = Mat3::MINOR_CHART(0,2);
        CPPUNIT_ASSERT_EQUAL(index_t(1,0), idx[0]);
        CPPUNIT_ASSERT_EQUAL(index_t(1,1), idx[1]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,0), idx[2]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,1), idx[3]);

        // Index 1,0
        idx = Mat3::MINOR_CHART(1,0);
        CPPUNIT_ASSERT_EQUAL(index_t(0,1), idx[0]);
        CPPUNIT_ASSERT_EQUAL(index_t(0,2), idx[1]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,1), idx[2]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,2), idx[3]);

        // Index 1,1
        idx = Mat3::MINOR_CHART(1,1);
        CPPUNIT_ASSERT_EQUAL(index_t(0,0), idx[0]);
        CPPUNIT_ASSERT_EQUAL(index_t(0,2), idx[1]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,0), idx[2]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,2), idx[3]);

        // Index 1,2
        idx = Mat3::MINOR_CHART(1,2);
        CPPUNIT_ASSERT_EQUAL(index_t(0,0), idx[0]);
        CPPUNIT_ASSERT_EQUAL(index_t(0,1), idx[1]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,0), idx[2]);
        CPPUNIT_ASSERT_EQUAL(index_t(2,1), idx[3]);

        // Index 2,0
        idx = Mat3::MINOR_CHART(2,0);
        CPPUNIT_ASSERT_EQUAL(index_t(0,1), idx[0]);
        CPPUNIT_ASSERT_EQUAL(index_t(0,2), idx[1]);
        CPPUNIT_ASSERT_EQUAL(index_t(1,1), idx[2]);
        CPPUNIT_ASSERT_EQUAL(index_t(1,2), idx[3]);

        // Index 2,1
        idx = Mat3::MINOR_CHART(2,1);
        CPPUNIT_ASSERT_EQUAL(index_t(0,0), idx[0]);
        CPPUNIT_ASSERT_EQUAL(index_t(0,2), idx[1]);
        CPPUNIT_ASSERT_EQUAL(index_t(1,0), idx[2]);
        CPPUNIT_ASSERT_EQUAL(index_t(1,2), idx[3]);

        // Index 2,2
        idx = Mat3::MINOR_CHART(2,2);
        CPPUNIT_ASSERT_EQUAL(index_t(0,0), idx[0]);
        CPPUNIT_ASSERT_EQUAL(index_t(0,1), idx[1]);
        CPPUNIT_ASSERT_EQUAL(index_t(1,0), idx[2]);
        CPPUNIT_ASSERT_EQUAL(index_t(1,1), idx[3]);
    }

    /**
     * Ensures `Mat3::operator==` returns `true` for equal instances.
     */
    void testEqualityOperatorWithEqualInstances() {
        double arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        M3d::Mat3 m1 = Mat3::fromArrayInColumnMajor(arr);
        M3d::Mat3 m2 = Mat3::fromArrayInColumnMajor(arr);
        CPPUNIT_ASSERT(m1 == m2);
    }

    /**
     * Ensures `Mat3::operator==` returns `false` for matrices with unequal first columns.
     */
    void testEqualityOperatorWithUnequalFirstColumns() {

        // Make first matrix
        M3d::Mat3 m1;
        m1[0] = M3d::Vec3(0.0);
        m1[1] = M3d::Vec3(1.0);
        m1[2] = M3d::Vec3(2.0);

        // Make second matrix
        M3d::Mat3 m2(m1);
        m2[0] = M3d::Vec3(-1.0);

        // Assert not equal
        CPPUNIT_ASSERT(!(m1 == m2));
    }

    /**
     * Ensures `Mat3::operator==` returns `false` for matrices with unequal second columns.
     */
    void testEqualityOperatorWithUnequalSecondColumns() {

        // Make first matrix
        M3d::Mat3 m1;
        m1[0] = M3d::Vec3(0.0);
        m1[1] = M3d::Vec3(1.0);
        m1[2] = M3d::Vec3(2.0);

        // Make second matrix
        M3d::Mat3 m2(m1);
        m2[1] = M3d::Vec3(-1.0);

        // Assert not equal
        CPPUNIT_ASSERT(!(m1 == m2));
    }

    /**
     * Ensures `Mat3::operator==` returns `false` for matrices with unequal third columns.
     */
    void testEqualityOperatorWithUnequalThirdColumns() {

        // Make first matrix
        M3d::Mat3 m1;
        m1[0] = M3d::Vec3(0.0);
        m1[1] = M3d::Vec3(1.0);
        m1[2] = M3d::Vec3(2.0);

        // Make second matrix
        M3d::Mat3 m2(m1);
        m2[2] = M3d::Vec3(-1.0);

        // Assert not equal
        CPPUNIT_ASSERT(!(m1 == m2));
    }

    /**
     * Ensures fromArrayInColumnMajor works with a one-dimensional double array.
     */
    void testFromArrayInColumnMajorDoubleArray() {

        // Make an array in column-major order
        double arr[9];
        arr[0] = 1; arr[3] = 2; arr[6] = 3;
        arr[1] = 4; arr[4] = 5; arr[7] = 6;
        arr[2] = 7; arr[5] = 8; arr[8] = 9;

        // Make a matrix from the array
        Mat3 m = Mat3::fromArrayInColumnMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, m[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, m[1][0]);
        CPPUNIT_ASSERT_EQUAL(3.0, m[2][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, m[0][1]);
        CPPUNIT_ASSERT_EQUAL(5.0, m[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, m[2][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, m[0][2]);
        CPPUNIT_ASSERT_EQUAL(8.0, m[1][2]);
        CPPUNIT_ASSERT_EQUAL(9.0, m[2][2]);
    }

    /**
     * Ensures fromArrayInColumnMajor works with a one-dimensional float array.
     */
    void testFromArrayInColumnMajorFloatArray() {

        // Make an array in column-major order
        float arr[9];
        arr[0] = 1; arr[3] = 2; arr[6] = 3;
        arr[1] = 4; arr[4] = 5; arr[7] = 6;
        arr[2] = 7; arr[5] = 8; arr[8] = 9;

        // Make a matrix from the array
        Mat3 m = Mat3::fromArrayInColumnMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, m[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, m[1][0]);
        CPPUNIT_ASSERT_EQUAL(3.0, m[2][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, m[0][1]);
        CPPUNIT_ASSERT_EQUAL(5.0, m[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, m[2][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, m[0][2]);
        CPPUNIT_ASSERT_EQUAL(8.0, m[1][2]);
        CPPUNIT_ASSERT_EQUAL(9.0, m[2][2]);
    }

    /**
     * Ensures fromArrayInColumnMajor works with a two-dimensional double array.
     */
    void testFromArrayInColumnMajorDoubleArrayArray() {

        // Make an array
        double arr[3][3];
        arr[0][0] = 1; arr[1][0] = 2; arr[2][0] = 3;
        arr[0][1] = 4; arr[1][1] = 5; arr[2][1] = 6;
        arr[0][2] = 7; arr[1][2] = 8; arr[2][2] = 9;

        // Make a matrix from the array
        Mat3 m = Mat3::fromArrayInColumnMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, m[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, m[1][0]);
        CPPUNIT_ASSERT_EQUAL(3.0, m[2][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, m[0][1]);
        CPPUNIT_ASSERT_EQUAL(5.0, m[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, m[2][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, m[0][2]);
        CPPUNIT_ASSERT_EQUAL(8.0, m[1][2]);
        CPPUNIT_ASSERT_EQUAL(9.0, m[2][2]);
    }

    /**
     * Ensures fromArrayInColumnMajor works with a two-dimensional float array.
     */
    void testFromArrayInColumnMajorFloatArrayArray() {

        // Make an array
        float arr[3][3];
        arr[0][0] = 1; arr[1][0] = 2; arr[2][0] = 3;
        arr[0][1] = 4; arr[1][1] = 5; arr[2][1] = 6;
        arr[0][2] = 7; arr[1][2] = 8; arr[2][2] = 9;

        // Make a matrix from the array
        Mat3 m = Mat3::fromArrayInColumnMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, m[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, m[1][0]);
        CPPUNIT_ASSERT_EQUAL(3.0, m[2][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, m[0][1]);
        CPPUNIT_ASSERT_EQUAL(5.0, m[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, m[2][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, m[0][2]);
        CPPUNIT_ASSERT_EQUAL(8.0, m[1][2]);
        CPPUNIT_ASSERT_EQUAL(9.0, m[2][2]);
    }

    /**
     * Ensures fromArrayInRowMajor works with a one-dimensional double array.
     */
    void testFromArrayInRowMajorDoubleArray() {

        // Make an array in row major
        double arr[9];
        arr[0] = 1; arr[1] = 2; arr[2] = 3;
        arr[3] = 4; arr[4] = 5; arr[5] = 6;
        arr[6] = 7; arr[7] = 8; arr[8] = 9;

        // Make a matrix from the array
        Mat3 m = Mat3::fromArrayInRowMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, m[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, m[1][0]);
        CPPUNIT_ASSERT_EQUAL(3.0, m[2][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, m[0][1]);
        CPPUNIT_ASSERT_EQUAL(5.0, m[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, m[2][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, m[0][2]);
        CPPUNIT_ASSERT_EQUAL(8.0, m[1][2]);
        CPPUNIT_ASSERT_EQUAL(9.0, m[2][2]);
    }

    /**
     * Ensures fromArrayInRowMajor works with a one-dimensional float array.
     */
    void testFromArrayInRowMajorFloatArray() {

        // Make an array in row major
        float arr[9];
        arr[0] = 1; arr[1] = 2; arr[2] = 3;
        arr[3] = 4; arr[4] = 5; arr[5] = 6;
        arr[6] = 7; arr[7] = 8; arr[8] = 9;

        // Make a matrix from the array
        Mat3 m = Mat3::fromArrayInRowMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, m[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, m[1][0]);
        CPPUNIT_ASSERT_EQUAL(3.0, m[2][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, m[0][1]);
        CPPUNIT_ASSERT_EQUAL(5.0, m[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, m[2][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, m[0][2]);
        CPPUNIT_ASSERT_EQUAL(8.0, m[1][2]);
        CPPUNIT_ASSERT_EQUAL(9.0, m[2][2]);
    }

    /**
     * Ensures fromArrayInRowMajor works with a two-dimensional double array.
     */
    void testFromArrayInRowMajorDoubleArrayArray() {

        // Make an array in row major
        double arr[3][3];
        arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 3;
        arr[1][0] = 4; arr[1][1] = 5; arr[1][2] = 6;
        arr[2][0] = 7; arr[2][1] = 8; arr[2][2] = 9;

        // Make a matrix from the array
        Mat3 m = Mat3::fromArrayInRowMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, m[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, m[1][0]);
        CPPUNIT_ASSERT_EQUAL(3.0, m[2][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, m[0][1]);
        CPPUNIT_ASSERT_EQUAL(5.0, m[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, m[2][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, m[0][2]);
        CPPUNIT_ASSERT_EQUAL(8.0, m[1][2]);
        CPPUNIT_ASSERT_EQUAL(9.0, m[2][2]);
    }

    /**
     * Ensures fromArrayInRowMajor works with a two-dimensional float array.
     */
    void testFromArrayInRowMajorFloatArrayArray() {

        // Make an array in row major
        float arr[3][3];
        arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 3;
        arr[1][0] = 4; arr[1][1] = 5; arr[1][2] = 6;
        arr[2][0] = 7; arr[2][1] = 8; arr[2][2] = 9;

        // Make a matrix from the array
        Mat3 m = Mat3::fromArrayInRowMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, m[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, m[1][0]);
        CPPUNIT_ASSERT_EQUAL(3.0, m[2][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, m[0][1]);
        CPPUNIT_ASSERT_EQUAL(5.0, m[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, m[2][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, m[0][2]);
        CPPUNIT_ASSERT_EQUAL(8.0, m[1][2]);
        CPPUNIT_ASSERT_EQUAL(9.0, m[2][2]);
    }

    /**
     * Ensures fromColumns works correctly.
     */
    void testFromColumns() {

        // Make rows
        const Vec3 c1(1, 4, 7);
        const Vec3 c2(2, 5, 8);
        const Vec3 c3(3, 6, 9);

        // Make matrix from rows
        const Mat3 mat = Mat3::fromColumns(c1, c2, c3);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, mat[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, mat[1][0]);
        CPPUNIT_ASSERT_EQUAL(3.0, mat[2][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, mat[0][1]);
        CPPUNIT_ASSERT_EQUAL(5.0, mat[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, mat[2][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, mat[0][2]);
        CPPUNIT_ASSERT_EQUAL(8.0, mat[1][2]);
        CPPUNIT_ASSERT_EQUAL(9.0, mat[2][2]);
    }

    /**
     * Ensures fromRows works correctly.
     */
    void testFromRows() {

        // Make rows
        const Vec3 r1(1, 2, 3);
        const Vec3 r2(4, 5, 6);
        const Vec3 r3(7, 8, 9);

        // Make matrix from rows
        const Mat3 mat = Mat3::fromRows(r1, r2, r3);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, mat[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, mat[1][0]);
        CPPUNIT_ASSERT_EQUAL(3.0, mat[2][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, mat[0][1]);
        CPPUNIT_ASSERT_EQUAL(5.0, mat[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, mat[2][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, mat[0][2]);
        CPPUNIT_ASSERT_EQUAL(8.0, mat[1][2]);
        CPPUNIT_ASSERT_EQUAL(9.0, mat[2][2]);
    }

    /**
     * Ensures `Mat3::operator!=` returns `false` for equal instances.
     */
    void testInequalityOperatorWithEqualInstances() {
        double arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        M3d::Mat3 m1 = Mat3::fromArrayInColumnMajor(arr);
        M3d::Mat3 m2 = Mat3::fromArrayInColumnMajor(arr);
        CPPUNIT_ASSERT(!(m1 != m2));
    }

    /**
     * Ensures `Mat3::operator!=` returns `true` for matrices with unequal first columns.
     */
    void testInequalityOperatorWithUnequalFirstColumns() {

        // Make first matrix
        M3d::Mat3 m1;
        m1[0] = M3d::Vec3(0.0);
        m1[1] = M3d::Vec3(1.0);
        m1[2] = M3d::Vec3(2.0);

        // Make second matrix
        M3d::Mat3 m2(m1);
        m2[0] = M3d::Vec3(-1.0);

        // Check not equal
        CPPUNIT_ASSERT(m1 != m2);
    }

    /**
     * Ensures `Mat3::operator!=` returns `true` for matrices with unequal second columns.
     */
    void testInequalityOperatorWithUnequalSecondColumns() {

        // Make first matrix
        M3d::Mat3 m1;
        m1[0] = M3d::Vec3(0.0);
        m1[1] = M3d::Vec3(1.0);
        m1[2] = M3d::Vec3(2.0);

        // Make second matrix
        M3d::Mat3 m2(m1);
        m2[1] = M3d::Vec3(-1.0);

        // Check not equal
        CPPUNIT_ASSERT(m1 != m2);
    }

    /**
     * Ensures `Mat3::operator!=` returns `true` for matrices with unequal third columns.
     */
    void testInequalityOperatorWithUnequalThirdColumns() {

        // Make first matrix
        M3d::Mat3 m1;
        m1[0] = M3d::Vec3(0.0);
        m1[1] = M3d::Vec3(1.0);
        m1[2] = M3d::Vec3(2.0);

        // Make second matrix
        M3d::Mat3 m2(m1);
        m2[2] = M3d::Vec3(-1.0);

        // Check not equal
        CPPUNIT_ASSERT(m1 != m2);
    }

    /**
     * Ensures the inverse function works correctly.
     */
    void testInverse() {

        m2 = M3d::inverse(m1);
        m3 = m1 * m2;

        for (int i = 0; i < Mat3::ORDER; ++i) {
            CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, m3[i][i], TOLERANCE);
        }

        for (int i = 0; i < Mat3::ORDER; ++i) {
            for (int j = i + 1; j < Mat3::ORDER; ++j) {
                CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, m3[j][i], TOLERANCE);
            }
        }

        for (int i = 1; i < Mat3::ORDER; ++i) {
            for (int j = 0; j < i; ++j) {
                CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, m3[j][i], TOLERANCE);
            }
        }
    }

    /**
     * Ensures creating a matrix from a one dimensional array works correctly.
     */
    void testSetArray() {

        double arr[9] = {
                1.0, 4.0, 7.0,
                2.0, 5.0, 8.0,
                3.0, 6.0, 9.0 };
        m2 = Mat3::fromArrayInColumnMajor(arr);

        for (int i = 0; i < Mat3::ORDER; ++i) {
            for (int j = 0; j < Mat3::ORDER; ++j) {
                CPPUNIT_ASSERT_DOUBLES_EQUAL(arr[j * Mat3::ORDER + i], m2[j][i], TOLERANCE);
            }
        }
    }

    /**
     * Ensures toArrayInColumnMajor works with a one-dimensional double array.
     */
    void testToArrayInColumnMajorDoubleArray() {

        // Make a matrix
        Mat3 m;
        m[0][0] = 1; m[1][0] = 2; m[2][0] = 3;
        m[0][1] = 4; m[1][1] = 5; m[2][1] = 6;
        m[0][2] = 7; m[1][2] = 8; m[2][2] = 9;

        // Make an array from it
        double arr[9];
        m.toArrayInColumnMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, arr[0]);
        CPPUNIT_ASSERT_EQUAL(4.0, arr[1]);
        CPPUNIT_ASSERT_EQUAL(7.0, arr[2]);
        CPPUNIT_ASSERT_EQUAL(2.0, arr[3]);
        CPPUNIT_ASSERT_EQUAL(5.0, arr[4]);
        CPPUNIT_ASSERT_EQUAL(8.0, arr[5]);
        CPPUNIT_ASSERT_EQUAL(3.0, arr[6]);
        CPPUNIT_ASSERT_EQUAL(6.0, arr[7]);
        CPPUNIT_ASSERT_EQUAL(9.0, arr[8]);
    }

    /**
     * Ensures toArrayInColumnMajor works with a one-dimensional float array.
     */
    void testToArrayInColumnMajorFloatArray() {

        // Make a matrix
        Mat3 m;
        m[0][0] = 1; m[1][0] = 2; m[2][0] = 3;
        m[0][1] = 4; m[1][1] = 5; m[2][1] = 6;
        m[0][2] = 7; m[1][2] = 8; m[2][2] = 9;

        // Make an array from it
        float arr[9];
        m.toArrayInColumnMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0f, arr[0]);
        CPPUNIT_ASSERT_EQUAL(4.0f, arr[1]);
        CPPUNIT_ASSERT_EQUAL(7.0f, arr[2]);
        CPPUNIT_ASSERT_EQUAL(2.0f, arr[3]);
        CPPUNIT_ASSERT_EQUAL(5.0f, arr[4]);
        CPPUNIT_ASSERT_EQUAL(8.0f, arr[5]);
        CPPUNIT_ASSERT_EQUAL(3.0f, arr[6]);
        CPPUNIT_ASSERT_EQUAL(6.0f, arr[7]);
        CPPUNIT_ASSERT_EQUAL(9.0f, arr[8]);
    }

    /**
     * Ensures toArrayInColumnMajor works with a two-dimensional double array.
     */
    void testToArrayInColumnMajorDoubleArrayArray() {

        // Make a matrix
        Mat3 m;
        m[0][0] = 1; m[1][0] = 2; m[2][0] = 3;
        m[0][1] = 4; m[1][1] = 5; m[2][1] = 6;
        m[0][2] = 7; m[1][2] = 8; m[2][2] = 9;

        // Make an array from it
        double arr[3][3];
        m.toArrayInColumnMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, arr[0][0]);
        CPPUNIT_ASSERT_EQUAL(4.0, arr[0][1]);
        CPPUNIT_ASSERT_EQUAL(7.0, arr[0][2]);
        CPPUNIT_ASSERT_EQUAL(2.0, arr[1][0]);
        CPPUNIT_ASSERT_EQUAL(5.0, arr[1][1]);
        CPPUNIT_ASSERT_EQUAL(8.0, arr[1][2]);
        CPPUNIT_ASSERT_EQUAL(3.0, arr[2][0]);
        CPPUNIT_ASSERT_EQUAL(6.0, arr[2][1]);
        CPPUNIT_ASSERT_EQUAL(9.0, arr[2][2]);
    }

    /**
     * Ensures toArrayInColumnMajor works with a two-dimensional float array.
     */
    void testToArrayInColumnMajorFloatArrayArray() {

        // Make a matrix
        Mat3 m;
        m[0][0] = 1; m[1][0] = 2; m[2][0] = 3;
        m[0][1] = 4; m[1][1] = 5; m[2][1] = 6;
        m[0][2] = 7; m[1][2] = 8; m[2][2] = 9;

        // Make an array from it
        float arr[3][3];
        m.toArrayInColumnMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0f, arr[0][0]);
        CPPUNIT_ASSERT_EQUAL(4.0f, arr[0][1]);
        CPPUNIT_ASSERT_EQUAL(7.0f, arr[0][2]);
        CPPUNIT_ASSERT_EQUAL(2.0f, arr[1][0]);
        CPPUNIT_ASSERT_EQUAL(5.0f, arr[1][1]);
        CPPUNIT_ASSERT_EQUAL(8.0f, arr[1][2]);
        CPPUNIT_ASSERT_EQUAL(3.0f, arr[2][0]);
        CPPUNIT_ASSERT_EQUAL(6.0f, arr[2][1]);
        CPPUNIT_ASSERT_EQUAL(9.0f, arr[2][2]);
    }

    /**
     * Ensures toArrayInRowMajor works with a one-dimensional double array.
     */
    void testToArrayInRowMajorDoubleArray() {

        // Make a matrix
        Mat3 m;
        m[0][0] = 1; m[1][0] = 2; m[2][0] = 3;
        m[0][1] = 4; m[1][1] = 5; m[2][1] = 6;
        m[0][2] = 7; m[1][2] = 8; m[2][2] = 9;

        // Make an array from it
        double arr[9];
        m.toArrayInRowMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, arr[0]);
        CPPUNIT_ASSERT_EQUAL(2.0, arr[1]);
        CPPUNIT_ASSERT_EQUAL(3.0, arr[2]);
        CPPUNIT_ASSERT_EQUAL(4.0, arr[3]);
        CPPUNIT_ASSERT_EQUAL(5.0, arr[4]);
        CPPUNIT_ASSERT_EQUAL(6.0, arr[5]);
        CPPUNIT_ASSERT_EQUAL(7.0, arr[6]);
        CPPUNIT_ASSERT_EQUAL(8.0, arr[7]);
        CPPUNIT_ASSERT_EQUAL(9.0, arr[8]);
    }

    /**
     * Ensures toArrayInRowMajor works with a one-dimensional float array.
     */
    void testToArrayInRowMajorFloatArray() {

        // Make a matrix
        Mat3 m;
        m[0][0] = 1; m[1][0] = 2; m[2][0] = 3;
        m[0][1] = 4; m[1][1] = 5; m[2][1] = 6;
        m[0][2] = 7; m[1][2] = 8; m[2][2] = 9;

        // Make an array from it
        float arr[9];
        m.toArrayInRowMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0f, arr[0]);
        CPPUNIT_ASSERT_EQUAL(2.0f, arr[1]);
        CPPUNIT_ASSERT_EQUAL(3.0f, arr[2]);
        CPPUNIT_ASSERT_EQUAL(4.0f, arr[3]);
        CPPUNIT_ASSERT_EQUAL(5.0f, arr[4]);
        CPPUNIT_ASSERT_EQUAL(6.0f, arr[5]);
        CPPUNIT_ASSERT_EQUAL(7.0f, arr[6]);
        CPPUNIT_ASSERT_EQUAL(8.0f, arr[7]);
        CPPUNIT_ASSERT_EQUAL(9.0f, arr[8]);
    }

    /**
     * Ensures toArrayInRowMajor works with a two-dimensional double array.
     */
    void testToArrayInRowMajorDoubleArrayArray() {

        // Make a matrix
        Mat3 m;
        m[0][0] = 1; m[1][0] = 2; m[2][0] = 3;
        m[0][1] = 4; m[1][1] = 5; m[2][1] = 6;
        m[0][2] = 7; m[1][2] = 8; m[2][2] = 9;

        // Make an array from it
        double arr[3][3];
        m.toArrayInRowMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0, arr[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0, arr[0][1]);
        CPPUNIT_ASSERT_EQUAL(3.0, arr[0][2]);
        CPPUNIT_ASSERT_EQUAL(4.0, arr[1][0]);
        CPPUNIT_ASSERT_EQUAL(5.0, arr[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0, arr[1][2]);
        CPPUNIT_ASSERT_EQUAL(7.0, arr[2][0]);
        CPPUNIT_ASSERT_EQUAL(8.0, arr[2][1]);
        CPPUNIT_ASSERT_EQUAL(9.0, arr[2][2]);

    }

    /**
     * Ensures toArrayInRowMajor works with a two-dimensional float array.
     */
    void testToArrayInRowMajorFloatArrayArray() {

        // Make a matrix
        Mat3 m;
        m[0][0] = 1; m[1][0] = 2; m[2][0] = 3;
        m[0][1] = 4; m[1][1] = 5; m[2][1] = 6;
        m[0][2] = 7; m[1][2] = 8; m[2][2] = 9;

        // Make an array from it
        float arr[3][3];
        m.toArrayInRowMajor(arr);

        // Compare
        CPPUNIT_ASSERT_EQUAL(1.0f, arr[0][0]);
        CPPUNIT_ASSERT_EQUAL(2.0f, arr[0][1]);
        CPPUNIT_ASSERT_EQUAL(3.0f, arr[0][2]);
        CPPUNIT_ASSERT_EQUAL(4.0f, arr[1][0]);
        CPPUNIT_ASSERT_EQUAL(5.0f, arr[1][1]);
        CPPUNIT_ASSERT_EQUAL(6.0f, arr[1][2]);
        CPPUNIT_ASSERT_EQUAL(7.0f, arr[2][0]);
        CPPUNIT_ASSERT_EQUAL(8.0f, arr[2][1]);
        CPPUNIT_ASSERT_EQUAL(9.0f, arr[2][2]);
    }

    /**
     * Ensures toString returns the correct string.
     */
    void testToString() {

        // Make a matrix
        Mat3 mat;
        mat[0][0] = 1; mat[1][0] = 2; mat[2][0] = 3;
        mat[0][1] = 4; mat[1][1] = 5; mat[2][1] = 6;
        mat[0][2] = 7; mat[1][2] = 8; mat[2][2] = 9;

        // Make expected and actual strings, and compare
        const string expect = "[[1, 4, 7], [2, 5, 8], [3, 6, 9]]";
        const string result = mat.toString();
        CPPUNIT_ASSERT_EQUAL(expect, result);
    }

    /**
     * Ensures transposing a matrix works correctly.
     */
    void testTranspose() {
        m2 = M3d::transpose(m1);
        for (int i = 0; i < Mat3::ORDER; ++i) {
            for (int j = 0; j < Mat3::ORDER; ++j) {
                CPPUNIT_ASSERT_DOUBLES_EQUAL(m1[j][i], m2[i][j], TOLERANCE);
            }
        }
    }

    /**
     * Ensures multiplying by a matrix works correctly.
     */
    void testMultiplyMatrix() {

        m3 = m1 * m2;

        for (int i = 0; i < Mat3::ORDER; ++i) {
            for (int j = 0; j < Mat3::ORDER; ++j) {
                CPPUNIT_ASSERT_DOUBLES_EQUAL(m1[j][i], m3[j][i], TOLERANCE);
            }
        }
    }

    /**
     * Ensures multiplying a vector by a matrix works correctly.
     */
    void testMultiplyVector() {

        double arr[3][3];
        arr[0][0] = 1; arr[1][0] = 7; arr[2][0] = 4;
        arr[0][1] = 6; arr[1][1] = 2; arr[2][1] = 9;
        arr[0][2] = 5; arr[1][2] = 8; arr[2][2] = 3;

        Vec3 u(8.0, 3.0, 5.0);
        Vec3 v = m1 * u;

        // v.x = (1 * 8) + (6 * 3) + (5 * 5)
        // v.y = (7 * 8) + (2 * 3) + (8 * 5)
        // v.z = (4 * 8) + (9 * 3) + (3 * 5)

        // v.x = 8 + 18 + 25
        // v.y = 56 + 6 + 40
        // v.z = 32 + 27 + 15

        // v.x = 51
        // v.y = 102
        // v.z = 74

        CPPUNIT_ASSERT_DOUBLES_EQUAL( 51.0, v.x, TOLERANCE);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(102.0, v.y, TOLERANCE);
        CPPUNIT_ASSERT_DOUBLES_EQUAL( 74.0, v.z, TOLERANCE);
    }

    CPPUNIT_TEST_SUITE(Mat3Test);
    CPPUNIT_TEST(testCreateSignChart);
    CPPUNIT_TEST(testCreateMinorChart);
    CPPUNIT_TEST(testEqualityOperatorWithEqualInstances);
    CPPUNIT_TEST(testEqualityOperatorWithUnequalFirstColumns);
    CPPUNIT_TEST(testEqualityOperatorWithUnequalSecondColumns);
    CPPUNIT_TEST(testEqualityOperatorWithUnequalThirdColumns);
    CPPUNIT_TEST(testFromArrayInColumnMajorDoubleArray);
    CPPUNIT_TEST(testFromArrayInColumnMajorFloatArray);
    CPPUNIT_TEST(testFromArrayInColumnMajorDoubleArrayArray);
    CPPUNIT_TEST(testFromArrayInColumnMajorFloatArrayArray);
    CPPUNIT_TEST(testFromArrayInRowMajorDoubleArray);
    CPPUNIT_TEST(testFromArrayInRowMajorFloatArray);
    CPPUNIT_TEST(testFromArrayInRowMajorDoubleArrayArray);
    CPPUNIT_TEST(testFromArrayInRowMajorFloatArrayArray);
    CPPUNIT_TEST(testFromColumns);
    CPPUNIT_TEST(testFromRows);
    CPPUNIT_TEST(testInequalityOperatorWithEqualInstances);
    CPPUNIT_TEST(testInequalityOperatorWithUnequalFirstColumns);
    CPPUNIT_TEST(testInequalityOperatorWithUnequalSecondColumns);
    CPPUNIT_TEST(testInequalityOperatorWithUnequalThirdColumns);
    CPPUNIT_TEST(testInverse);
    CPPUNIT_TEST(testSetArray);
    CPPUNIT_TEST(testToArrayInColumnMajorDoubleArray);
    CPPUNIT_TEST(testToArrayInColumnMajorFloatArray);
    CPPUNIT_TEST(testToArrayInColumnMajorDoubleArrayArray);
    CPPUNIT_TEST(testToArrayInColumnMajorFloatArrayArray);
    CPPUNIT_TEST(testToArrayInRowMajorDoubleArray);
    CPPUNIT_TEST(testToArrayInRowMajorFloatArray);
    CPPUNIT_TEST(testToArrayInRowMajorDoubleArrayArray);
    CPPUNIT_TEST(testToArrayInRowMajorFloatArrayArray);
    CPPUNIT_TEST(testToString);
    CPPUNIT_TEST(testTranspose);
    CPPUNIT_TEST(testMultiplyVector);
    CPPUNIT_TEST(testMultiplyMatrix);
    CPPUNIT_TEST_SUITE_END();
};

} /* namespace M3d */

int main(int argc, char *argv[]) {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(M3d::Mat3Test::suite());
    runner.run();
    return 0;
}

std::ostream& operator<<(std::ostream& stream, const std::pair<int,int> &pair) {
    stream << "[";
    stream << pair.first;
    stream << ", ";
    stream << pair.second;
    stream << "]";
    return stream;
}
