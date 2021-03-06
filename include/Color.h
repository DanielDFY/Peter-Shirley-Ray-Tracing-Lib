#pragma once

#include <iostream>

#include <Vec3.h>

#include <helperUtils.h>

class Color : public Vec3 {
public:
    Color() = default;
    Color(double e1, double e2, double e3) : Vec3(e1, e2, e3) {}
    Color(Vec3 v) : Color(v.x(), v.y(), v.z()) {}

    void gammaCorrect() {
        // gamma-correct for gamma=2.0.
        _elem[0] = sqrt(_elem[0]);
        _elem[1] = sqrt(_elem[1]);
        _elem[2] = sqrt(_elem[2]);
    }
	
    double r() const { return clamp(_elem[0], 0.0, 1.0); }
    double g() const { return clamp(_elem[1], 0.0, 1.0); }
    double b() const { return clamp(_elem[2], 0.0, 1.0); }

    double r8bit() const { return 255 * clamp(_elem[0], 0.0, 1.0); }
    double g8bit() const { return 255 * clamp(_elem[1], 0.0, 1.0); }
    double b8bit() const { return 255 * clamp(_elem[2], 0.0, 1.0); }
};

inline void writeColor8bit(std::ostream& out, Color color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(color.r8bit()) << ' '
        << static_cast<int>(color.g8bit()) << ' '
        << static_cast<int>(color.b8bit()) << '\n';
}