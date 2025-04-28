#include "Vector3.h"
#include <sstream>


std::string Vector3::toString() const {
    std::ostringstream ss;
    ss << x << ", " << y << ", " << z;
    return ss.str();
}
