//
//  SeasonsManager.hpp
//  Plant Life
//
//  Created by Olivier Elmoznino on 2017-02-21.
//  Copyright © 2017 Eric Elmoznino. All rights reserved.
//

#ifndef SeasonsManager_hpp
#define SeasonsManager_hpp

#include "Vec3.hpp"


enum Season {SUMMER = 0, FALL = 1, WINTER = 2, SPRING = 3};

class SeasonsManager {
private:
    // Constants
    const Vec3 summerSky = Vec3(0.57, 0.73, 1.0);
    const Vec3 fallSky = Vec3(0.62, 0.56, 0.64);
    const Vec3 winterSky = Vec3(0.93, 0.94, 0.97);
    const Vec3 springSky = Vec3(0.76, 0.90, 0.82);
    
    const Vec3 water = Vec3(0.0, 0.25, 0.4);
    const float waterAlpha = 0.75;
    const Vec3 ice = Vec3(0.69, 0.78, 0.86);
    const float iceAlpha = 0.95;
    
    const Vec3 summerTroth = Vec3(0.2, 0.2, 0.3);
    const Vec3 summerPeak = Vec3(0.6, 0.8, 0.3);
    const Vec3 fallTroth = Vec3(0.2, 0.2, 0.3);
    const Vec3 fallPeak = Vec3(0.62, 0.45, 0.15);
    const Vec3 winterTroth = Vec3(0.50, 0.52, 0.59);
    const Vec3 winterPeak = Vec3(0.79, 0.82, 0.87);
    const Vec3 springTroth = Vec3(0.77, 0.64, 0.66);
    const Vec3 springPeak = Vec3(0.84, 0.88, 0.45);
    
    const Vec3 summerStem = Vec3(0.39, 0.62, 0.31);
    const Vec3 fallStem = Vec3(0.39, 0.62, 0.31);
    const Vec3 winterStem = Vec3(0.62, 0.56, 0.51);
    const Vec3 springStem = Vec3(0.39, 0.62, 0.31);
    
    const Vec3 summerLeaf = Vec3(0.5, 0.9, 0.5);
    const Vec3 fallLeaf = Vec3(1.0, 1.0, 1.0);
    const Vec3 winterLeaf = Vec3(1.0, 1.0, 1.0);
    const Vec3 springLeaf = Vec3(0.5, 0.9, 0.5);
    
    const Vec3 summerFlower = Vec3(1.0, 1.0, 0.0);
    const Vec3 fallFlower = Vec3(1.0, 1.0, 1.0);
    const Vec3 winterFlower = Vec3(1.0, 1.0, 1.0);
    const Vec3 springFlower = Vec3(1.0, 0.0, 1.0);
    
    const Vec3 snowColor = Vec3(1.0, 1.0, 1.0);
    
    const float baseFallSpeed = 0.05;
    const float fallSpeedDeviation = 0.04;
    const float baseFallTime = 0.4;
    const float fallTimeDeviation = 0.6;
    
    // Variables to keep track of the season state
    Season season;
    float progress;
    float speed;
    
    // Private functions
    Vec3 getGroundPeakColor() const;
    Vec3 getGroundTrothColor() const;
    
public:
    SeasonsManager(float speed);
    Vec3 getBackgroundColor() const;
    Vec3 getWaterColor() const;
    float getWaterAlpha() const;
    Vec3 getGroundColor(float progressToPeak) const;
    Vec3 getStemColor() const;
    Vec3 getLeafColor() const;
    Vec3 getFlowerColor() const;
    Vec3 getSnowColor() const;
    float getSnowAlpha() const;
    float getRandomFallSpeed() const;
    float getRandomFallTime() const;
    
    Season getSeason();
    float getProgressThroughSeason();
    void advanceTime();
};

#endif /* SeasonsManager_hpp */
