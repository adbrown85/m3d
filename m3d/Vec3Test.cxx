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
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include "m3d/common.h"
#include "m3d/Math.h"
#include "m3d/Vec3.h"
using namespace std;

const double COS_FORTY_FIVE = cos(M3d::toRadians(45));
const double SIN_FORTY_FIVE = sin(M3d::toRadians(45));

/**
 * Unit test for Vec3.
 */
class Vec3Test : public CppUnit::TestFixture {
public:

    /**
     * Ensures operator[] const works correctly.
     */
    void testOperatorIndexConst() {

        M3d::Vec3 u(1, 2, 3);

        CPPUNIT_ASSERT_EQUAL(1.0, u[0]);
        CPPUNIT_ASSERT_EQUAL(2.0, u[1]);
        CPPUNIT_ASSERT_EQUAL(3.0, u[2]);
    }

    /**
     * Ensures toArray works correctly.
     */
    void testToArray() {

        M3d::Vec3 u(1, 2, 3);
        double arr[3];

        u.toArray(arr);
        CPPUNIT_ASSERT_EQUAL(1.0, arr[0]);
        CPPUNIT_ASSERT_EQUAL(2.0, arr[1]);
        CPPUNIT_ASSERT_EQUAL(3.0, arr[2]);
    }

    /**
     * Ensures operator== returns true when it should.
     */
    void testOperatorEqualsWithTrue() {

        M3d::Vec3 u(1, 2, 3);
        M3d::Vec3 v(1, 2, 3);

        CPPUNIT_ASSERT_EQUAL(true, u == v);
    }

    /**
     * Ensures operator== returns false when it should.
     */
    void testOperatorEqualsWithFalse() {
        M3d::Vec3 u(1, 2, 3);
        M3d::Vec3 v(4, 5, 6);

        CPPUNIT_ASSERT_EQUAL(u == v, false);
    }

    /**
     * Ensures operator!= returns true when it should.
     */
    void testOperatorNotEqualsWithTrue() {

        M3d::Vec3 u(1, 1, 1);
        M3d::Vec3 v(1, 1, 2);

        CPPUNIT_ASSERT_EQUAL(true, u != v);
    }

    /**
     * Ensures operator!= returns false when it should
     */
    void testOperatorNotEqualsWithFalse() {
        M3d::Vec3 u(1, 1, 1);
        M3d::Vec3 v(1, 1, 1);

        CPPUNIT_ASSERT_EQUAL(u != v, false);
    }

    /**
     * Ensures operator+(Vec3,Vec3) works correctly.
     */
    void testOperatorAddVec3Vec3() {
        M3d::Vec3 u(1, 2, 3);
        M3d::Vec3 v(4, 5, 6);
        M3d::Vec3 r = u + v;

        CPPUNIT_ASSERT_EQUAL(5.0, r.x);
        CPPUNIT_ASSERT_EQUAL(7.0, r.y);
        CPPUNIT_ASSERT_EQUAL(9.0, r.z);
    }

    /**
     * Ensures operator-(Vec3,Vec3) works correctly.
     */
    void testOperatorSubtractVec3Vec3() {

        M3d::Vec3 u(1, 2, 3);
        M3d::Vec3 v(6, 5, 4);
        M3d::Vec3 r = u - v;

        CPPUNIT_ASSERT_EQUAL(-5.0, r.x);
        CPPUNIT_ASSERT_EQUAL(-3.0, r.y);
        CPPUNIT_ASSERT_EQUAL(-1.0, r.z);
    }

    /**
     * Ensures operator*(Vec3,Vec3) works correctly.
     */
    void testOperatorMultiplyVec3Vec3() {

        M3d::Vec3 u(1, 2, 3);
        M3d::Vec3 v(4, 5, 6);
        M3d::Vec3 r = u * v;

        CPPUNIT_ASSERT_EQUAL( 4.0, r.x);
        CPPUNIT_ASSERT_EQUAL(10.0, r.y);
        CPPUNIT_ASSERT_EQUAL(18.0, r.z);
    }

    /**
     * Ensures operator/(Vec3,Vec3) works correctly.
     */
    void testOperatorDivideVec3Vec3() {

        M3d::Vec3 u(1, 2, 3);
        M3d::Vec3 v(4, 5, 6);
        M3d::Vec3 r = u / v;

        CPPUNIT_ASSERT_EQUAL(0.25, r.x);
        CPPUNIT_ASSERT_EQUAL(0.40, r.y);
        CPPUNIT_ASSERT_EQUAL(0.50, r.z);
    }

    /**
     * Ensures operator+(Vec3,double) works correctly.
     */
    void testOperatorAddVec3Float() {

        M3d::Vec3 u(1, 2, 3);
        M3d::Vec3 r = u + 4;

        CPPUNIT_ASSERT_EQUAL(5.0, r.x);
        CPPUNIT_ASSERT_EQUAL(6.0, r.y);
        CPPUNIT_ASSERT_EQUAL(7.0, r.z);
    }

    /**
     * Ensures operator-(Vec3,double) works correctly.
     */
    void testOperatorSubtractVec3Float() {

        M3d::Vec3 u(1, 2, 3);
        M3d::Vec3 r = u - 4;

        CPPUNIT_ASSERT_EQUAL(-3.0, r.x);
        CPPUNIT_ASSERT_EQUAL(-2.0, r.y);
        CPPUNIT_ASSERT_EQUAL(-1.0, r.z);
    }

    /**
     * Ensures operator*(Vec3,double) works correctly.
     */
    void testOperatorMultiplyVec3Float() {

        M3d::Vec3 u(1, 2, 3);
        M3d::Vec3 r = u * 4;

        CPPUNIT_ASSERT_EQUAL( 4.0, r.x);
        CPPUNIT_ASSERT_EQUAL( 8.0, r.y);
        CPPUNIT_ASSERT_EQUAL(12.0, r.z);
    }

    /**
     * Ensures operator/(Vec3,double) works correctly.
     */
    void testOperatorDivideVec3Float() {

        M3d::Vec3 u(1, 2, 3);
        M3d::Vec3 r = u / 4;

        CPPUNIT_ASSERT_EQUAL(0.25, r.x);
        CPPUNIT_ASSERT_EQUAL(0.50, r.y);
        CPPUNIT_ASSERT_EQUAL(0.75, r.z);
    }

    /**
     * Ensures the unary plus operator works correctly.
     */
    void testOperatorUnaryPlus() {

        M3d::Vec3 v1(1, 2, 3);
        M3d::Vec3 v2 = +v1;

        CPPUNIT_ASSERT_EQUAL(1.0, v2.x);
        CPPUNIT_ASSERT_EQUAL(2.0, v2.y);
        CPPUNIT_ASSERT_EQUAL(3.0, v2.z);
    }

    /**
     * Ensures cross works correctly with the X and Y axes.
     */
    void testCrossWithXY() {

        M3d::Vec3 u(1, 0, 0);
        M3d::Vec3 v(0, 1, 0);
        M3d::Vec3 r = M3d::cross(u, v);

        CPPUNIT_ASSERT_EQUAL(0.0, r.x);
        CPPUNIT_ASSERT_EQUAL(0.0, r.y);
        CPPUNIT_ASSERT_EQUAL(1.0, r.z);
    }

    /**
     * Ensures cross works correctly with the Y and X axes.
     */
    void testCrossWithYX() {

        M3d::Vec3 u(0, 1, 0);
        M3d::Vec3 v(1, 0, 0);
        M3d::Vec3 r = M3d::cross(u, v);

        CPPUNIT_ASSERT_EQUAL( 0.0, r.x);
        CPPUNIT_ASSERT_EQUAL( 0.0, r.y);
        CPPUNIT_ASSERT_EQUAL(-1.0, r.z);
    }

    /**
     * Ensures dot works correctly with the X and Y axes.
     */
    void testDotWithXY() {
        M3d::Vec3 u(1, 0, 0);
        M3d::Vec3 v(0, 1, 0);
        double r = M3d::dot(u, v);

        CPPUNIT_ASSERT_EQUAL(0.0, r);
    }

    /**
     * Ensures dot works correctly with the Y axis.
     */
    void testDotWithYY() {

        M3d::Vec3 u(0, 1, 0);
        M3d::Vec3 v(0, 1, 0);
        double r = M3d::dot(u, v);

        CPPUNIT_ASSERT_EQUAL(1.0, r);
    }

    /**
     * Ensures length works correctly.
     */
    void testLength() {

        M3d::Vec3 u(5, 5, 0);
        double r = M3d::length(u);

        CPPUNIT_ASSERT_DOUBLES_EQUAL(5 * M3d::SQRT_TWO, r, 0.01);
    }

    /**
     * Ensures normalize works correctly.
     */
    void testNormalize() {

        M3d::Vec3 u(5, 5, 0);
        M3d::Vec3 r = M3d::normalize(u);

        CPPUNIT_ASSERT_DOUBLES_EQUAL(COS_FORTY_FIVE, r.x, 0.01);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(SIN_FORTY_FIVE, r.y, 0.01);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(0.00, r.z, 0.01);
    }

    /**
     * Ensures min works correctly.
     */
    void testMin() {

        M3d::Vec3 u(1, 5, 3);
        M3d::Vec3 v(4, 2, 6);
        M3d::Vec3 r = M3d::min(u, v);

        CPPUNIT_ASSERT_EQUAL(1.0, r.x);
        CPPUNIT_ASSERT_EQUAL(2.0, r.y);
        CPPUNIT_ASSERT_EQUAL(3.0, r.z);
    }

    /**
     * Ensures max works correctly.
     */
    void testMax() {

        M3d::Vec3 u(1, 5, 3);
        M3d::Vec3 v(4, 2, 6);
        M3d::Vec3 r = M3d::max(u, v);

        CPPUNIT_ASSERT_EQUAL(4.0, r.x);
        CPPUNIT_ASSERT_EQUAL(5.0, r.y);
        CPPUNIT_ASSERT_EQUAL(6.0, r.z);
    }

    /**
     * Ensures `Vec3::Vec3(double)` works correctly.
     */
    void testVec3Double() {
        M3d::Vec3 v(5);
        CPPUNIT_ASSERT_EQUAL(5.0, v.x);
        CPPUNIT_ASSERT_EQUAL(5.0, v.y);
        CPPUNIT_ASSERT_EQUAL(5.0, v.z);
    }

    CPPUNIT_TEST_SUITE(Vec3Test);
    CPPUNIT_TEST(testOperatorIndexConst);
    CPPUNIT_TEST(testToArray);
    CPPUNIT_TEST(testOperatorEqualsWithTrue);
    CPPUNIT_TEST(testOperatorEqualsWithFalse);
    CPPUNIT_TEST(testOperatorNotEqualsWithTrue);
    CPPUNIT_TEST(testOperatorNotEqualsWithFalse);
    CPPUNIT_TEST(testOperatorAddVec3Vec3);
    CPPUNIT_TEST(testOperatorSubtractVec3Vec3);
    CPPUNIT_TEST(testOperatorMultiplyVec3Vec3);
    CPPUNIT_TEST(testOperatorDivideVec3Vec3);
    CPPUNIT_TEST(testOperatorAddVec3Float);
    CPPUNIT_TEST(testOperatorSubtractVec3Float);
    CPPUNIT_TEST(testOperatorMultiplyVec3Float);
    CPPUNIT_TEST(testOperatorDivideVec3Float);
    CPPUNIT_TEST(testOperatorUnaryPlus);
    CPPUNIT_TEST(testCrossWithXY);
    CPPUNIT_TEST(testCrossWithYX);
    CPPUNIT_TEST(testDotWithXY);
    CPPUNIT_TEST(testDotWithYY);
    CPPUNIT_TEST(testLength);
    CPPUNIT_TEST(testNormalize);
    CPPUNIT_TEST(testMin);
    CPPUNIT_TEST(testMax);
    CPPUNIT_TEST(testVec3Double);
    CPPUNIT_TEST_SUITE_END();
};

int main(int argc, char *argv[]) {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(Vec3Test::suite());
    runner.run();
    return 0;
}
