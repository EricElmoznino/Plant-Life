//
//  Vec3.hpp
//  Plant Life
//
//  Created by Eric Elmoznino on 2017-02-17.
//  Copyright © 2017 Eric Elmoznino. All rights reserved.
//

#ifndef Vec3_hpp
#define Vec3_hpp

class Vec3 {
public:
    float x, y, z;
    
    Vec3();
    Vec3(float x, float y, float z);
    // default copy constructor suffices
    
    float magnitude() const;
    Vec3 normalized() const;
    
    float dot(const Vec3 &other) const;
    Vec3 crossUnit(const Vec3 &other) const;    // normalized cross product
    
    Vec3 operator+(const Vec3 &other) const;
    Vec3 operator-(const Vec3 &other) const;
    Vec3 operator*(float scale) const;          // vec * scalar
    
    bool operator==(const Vec3 &other) const;
    bool operator!=(const Vec3 &other) const;
    
    Vec3 linearInterpolate(const Vec3 &end, float progress) const; // progress: [0,1]
    
    // debugging
    void printVec3(void) const;
};

Vec3 operator*(float scale, const Vec3& vec); // scalar * vec

#endif /* Vec3_hpp */
