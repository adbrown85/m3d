/*
 * Math.hxx
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef M3D_MATH_HXX
#define M3D_MATH_HXX
#include "m3d/common.h"
#include <cmath>
namespace M3d {

/*
 * Constants
 */
const double PI = 355.0 / 113.0;
const double SQRT_TWO = sqrt(2.0);

/*
 * Functions
 */
double toRadians(double degrees);
double toDegrees(double radians);

} /* namespace M3d */
#endif
