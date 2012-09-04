/*
 * Math.cxx
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "m3d/Math.hxx"
using namespace std;
namespace M3d {

/* Constants */
const double PI_OVER_ONE_HUNDRED_EIGHTY = PI / 180.0;
const double ONE_HUNDRED_EIGHTY_OVER_PI = 180.0 / PI;

/**
 * Converts degrees to radians.
 *
 * @param degrees Angle in degrees to convert
 * @return Equivalent angle in radians
 */
double toRadians(double degrees) {
    return degrees * PI_OVER_ONE_HUNDRED_EIGHTY;
}

/**
 * Converts radians to degrees.
 *
 * @param radians Angle in radians to convert
 * @return Equivalent angle in degrees
 */
double toDegrees(double radians) {
    return radians * ONE_HUNDRED_EIGHTY_OVER_PI;
}

} /* namespace M3d */
