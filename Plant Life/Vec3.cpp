//
//  Vec3.cpp
//  Plant Life
//
//  Created by Eric Elmoznino on 2017-02-17.
//  Copyright © 2017 Eric Elmoznino. All rights reserved.
//

#include "Vec3.hpp"
#include <math.h>

Vec3::Vec3() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vec3::Vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vec3::magnitude() const {
    return sqrtf(this->dot(*this));
}

Vec3 Vec3::normalized() const {
    return 1.0/(this->magnitude()) * (*this);
}

float Vec3::dot(const Vec3 &other) const {
    return this->x*other.x + this->y*other.y + this->z*other.z;
}

Vec3 Vec3::crossUnit(const Vec3 &other) const {
    return Vec3(this->y*other.z - this->z*other.y,
                other.x*this->z - other.z*this->x,
                this->x*other.y - this->y*other.x)
    .normalized();
}

Vec3 Vec3::operator+(const Vec3 &other) const {
    return Vec3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vec3 Vec3::operator-(const Vec3 &other) const {
    return Vec3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vec3 Vec3::operator*(float scale) const {
    return Vec3(this->x * scale, this->y * scale, this->z * scale);
}

Vec3 operator*(float scale, const Vec3& vec) {
    return vec*scale;
}
