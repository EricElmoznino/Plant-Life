//
//  SeasonsManager.cpp
//  Plant Life
//
//  Created by Olivier Elmoznino on 2017-02-21.
//  Copyright © 2017 Eric Elmoznino. All rights reserved.
//

#include "SeasonsManager.hpp"

SeasonsManager::SeasonsManager(float speed) {
    season = SUMMER;
    progress = 0.0;
    this->speed = speed;
}

Vec3 SeasonsManager::getBackgroundColor() const {
    switch (season) {
        case SUMMER:
            return summerSky.linearInterpolate(fallSky, progress);
            break;
        case FALL:
            return fallSky.linearInterpolate(winterSky, progress);
            break;
        case WINTER:
            return winterSky.linearInterpolate(springSky, progress);
            break;
        case SPRING:
            return springSky.linearInterpolate(summerSky, progress);
            break;
    }
}

Vec3 SeasonsManager::getWaterColor() const {
    switch (season) {
        case SUMMER:
            return water;
            break;
        case FALL:
            return water.linearInterpolate(ice, progress);
            break;
        case WINTER:
            return ice.linearInterpolate(water, progress);
            break;
        case SPRING:
            return water;
            break;
    }
}

float SeasonsManager::getWaterAlpha() const {
    switch (season) {
        case SUMMER:
            return waterAlpha;
            break;
        case FALL:
            return waterAlpha + progress*(iceAlpha - waterAlpha);
            break;
        case WINTER:
            return iceAlpha + progress*(waterAlpha - iceAlpha);
            break;
        case SPRING:
            return waterAlpha;
            break;
    }
}

Vec3 SeasonsManager::getGroundPeakColor() const {
    switch (season) {
        case SUMMER:
            return summerPeak.linearInterpolate(fallPeak, progress);
            break;
        case FALL:
            return fallPeak.linearInterpolate(winterPeak, progress);
            break;
        case WINTER:
            return winterPeak.linearInterpolate(springPeak, progress);
            break;
        case SPRING:
            return springPeak.linearInterpolate(summerPeak, progress);
            break;
    }
}

Vec3 SeasonsManager::getGroundTrothColor() const {
    switch (season) {
        case SUMMER:
            return summerTroth.linearInterpolate(fallTroth, progress);
            break;
        case FALL:
            return fallTroth.linearInterpolate(winterTroth, progress);
            break;
        case WINTER:
            return winterTroth.linearInterpolate(springTroth, progress);
            break;
        case SPRING:
            return springTroth.linearInterpolate(summerTroth, progress);
            break;
    }
}

Vec3 SeasonsManager::getGroundColor(float progressToPeak) const {
    Vec3 troth = getGroundTrothColor();
    Vec3 peak = getGroundPeakColor();
    return troth.linearInterpolate(peak, progressToPeak);
}

Vec3 SeasonsManager::getStemColor() const {
    switch (season) {
        case SUMMER:
            return summerStem.linearInterpolate(fallStem, progress);
            break;
        case FALL:
            return fallStem.linearInterpolate(winterStem, progress);
            break;
        case WINTER:
            return winterStem.linearInterpolate(springStem, progress);
            break;
        case SPRING:
            return springStem.linearInterpolate(summerStem, progress);
            break;
    }
}

Vec3 SeasonsManager::getLeafColor() const {
    switch (season) {
        case SUMMER:
            return summerLeaf.linearInterpolate(fallLeaf, progress);
            break;
        case FALL:
            return fallLeaf.linearInterpolate(winterLeaf, progress);
            break;
        case WINTER:
            return winterLeaf.linearInterpolate(springLeaf, progress);
            break;
        case SPRING:
            return springLeaf.linearInterpolate(summerLeaf, progress);
            break;
    }
}

Vec3 SeasonsManager::getFlowerColor() const {
    switch (season) {
        case SUMMER:
            return summerFlower.linearInterpolate(fallFlower, progress);
            break;
        case FALL:
            return fallFlower.linearInterpolate(winterFlower, progress);
            break;
        case WINTER:
            return winterFlower.linearInterpolate(springFlower, progress);
            break;
        case SPRING:
            return springFlower.linearInterpolate(summerFlower, progress);
            break;
    }
}

Vec3 SeasonsManager::getSnowColor() const {
    return snowColor;
}

float SeasonsManager::getSnowAlpha() const {
    switch (season) {
        case SUMMER:
            return 0.0;
            break;
        case FALL:
            return progress;
            break;
        case WINTER:
            return (1-progress);
            break;
        case SPRING:
            return 0.0;
            break;
    }
}

Season SeasonsManager::getSeason() {
    return season;
}

float SeasonsManager::getProgressThroughSeason() {
    return progress;
}

void SeasonsManager::advanceTime() {
    progress += speed;
    if (progress >= 1.0) {
        progress = 0.0;
        season = (Season)((season + 1) % 4);
    }

}
