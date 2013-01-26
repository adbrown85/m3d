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
#include <limits>
#include "m3d/common.h"
#include "m3d/Vec4.hxx"
using namespace std;


/**
 * Unit test for Vec4.
 */
class Vec4Test : public CppUnit::TestFixture {
public:

    /**
     * Ensures add operation works correctly.
     */
    void testAdd() {
        M3d::Vec4 A(2, 2, 2, 0);
        M3d::Vec4 B(2, 4, 5, 0);
        M3d::Vec4 C = A + B;
        CPPUNIT_ASSERT_EQUAL(4.0, C.x);
        CPPUNIT_ASSERT_EQUAL(6.0, C.y);
        CPPUNIT_ASSERT_EQUAL(7.0, C.z);
        CPPUNIT_ASSERT_EQUAL(0.0, C.w);
    }

    /**
     * Ensures subtract operation works correctly.
     */
    void testSubtract() {
        M3d::Vec4 A(2, 2, 2, 0);
        M3d::Vec4 B(2, 4, 5, 0);
        M3d::Vec4 C = A - B;
        CPPUNIT_ASSERT_EQUAL( 0.0, C.x);
        CPPUNIT_ASSERT_EQUAL(-2.0, C.y);
        CPPUNIT_ASSERT_EQUAL(-3.0, C.z);
        CPPUNIT_ASSERT_EQUAL( 0.0, C.w);
    }

    /**
     * Ensures multiply operation works correctly.
     */
    void testMultiply() {
        M3d::Vec4 A(2, 2, 2, 0);
        M3d::Vec4 B(2, 4, 5, 0);
        M3d::Vec4 C = A * B;
        CPPUNIT_ASSERT_EQUAL( 4.0, C.x);
        CPPUNIT_ASSERT_EQUAL( 8.0, C.y);
        CPPUNIT_ASSERT_EQUAL(10.0, C.z);
        CPPUNIT_ASSERT_EQUAL( 0.0, C.w);
    }

    /**
     * Ensures divide operation works correctly.
     */
    void testDivide() {
        M3d::Vec4 A(2, 2, 2, 0);
        M3d::Vec4 B(2, 4, 5, 0);
        M3d::Vec4 C = A / B;
        CPPUNIT_ASSERT_EQUAL(1.0, C.x);
        CPPUNIT_ASSERT_EQUAL(0.5, C.y);
        CPPUNIT_ASSERT_EQUAL(0.4, C.z);
        CPPUNIT_ASSERT(C.w != C.w);
    }

    /**
     * Ensures the unary plus operator works correctly.
     */
    void testOperatorUnaryPlus() {

        M3d::Vec4 v1(1, 2, 3, 4);
        M3d::Vec4 v2 = +v1;

        CPPUNIT_ASSERT_EQUAL(1.0, v1.x);
        CPPUNIT_ASSERT_EQUAL(2.0, v1.y);
        CPPUNIT_ASSERT_EQUAL(3.0, v1.z);
        CPPUNIT_ASSERT_EQUAL(4.0, v1.w);
    }

    /**
     * Ensures `Vec4::toVec3` works correctly.
     */
    void testToVec3() {
        const M3d::Vec4 v4(1, 2, 3, 4);
        const M3d::Vec3 v3 = v4.toVec3();
        CPPUNIT_ASSERT_EQUAL(v4.x, v3.x);
        CPPUNIT_ASSERT_EQUAL(v4.y, v3.y);
        CPPUNIT_ASSERT_EQUAL(v4.z, v3.z);
    }

    CPPUNIT_TEST_SUITE(Vec4Test);
    CPPUNIT_TEST(testAdd);
    CPPUNIT_TEST(testSubtract);
    CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST(testDivide);
    CPPUNIT_TEST(testOperatorUnaryPlus);
    CPPUNIT_TEST(testToVec3);
    CPPUNIT_TEST_SUITE_END();
};

int main(int argc, char *argv[]) {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(Vec4Test::suite());
    runner.run();
    return 0;
}
