#ifndef BASIC_TRANSFORM_H
#define BASIC_TRANSFORM_H

#include <cassert>

#include "vector_util.h"
#include <SFML/System/Vector2.hpp>

struct BasicTransform {
    // compose(f, g) is equivalent to first applying g, then applying f.
    static BasicTransform compose(const BasicTransform& f, const BasicTransform& g) {
        sf::Vector2f innerScale = {f.scale *g.scale};
        sf::Vector2f innerTranslation =  {f.scale.x *(g.translation.x) + f.translation.x, f.scale.y *(g.translation.y) + f.translation.y};
        BasicTransform composed = BasicTransform( innerScale, innerTranslation);
        return composed;
    };

    static BasicTransform inverse(const BasicTransform& f) {
        BasicTransform inverse;
        if (f.scale.x != 0 && f.scale.y != 0){
            inverse.scale = {1/f.scale.x,1/f.scale.y};
            inverse.translation = {-(f.translation.x)/f.scale.x , -(f.translation.y)/f.scale.y };
            return inverse;
        }else if(f.scale.x == 0 && f.scale.y !=0 ){
            inverse.scale = {0.f,1/f.scale.y};
            inverse.translation = {-(f.translation.x)/f.scale.x , -(f.translation.y)/f.scale.y };
            return inverse;
        }else if (f.scale.y == 0&& f.scale.x !=0 ){
            inverse.scale = {1/f.scale.x, 0.f };
            inverse.translation = {-(f.translation.x)/f.scale.x , -(f.translation.y)/f.scale.y };
            return inverse;
        }else{
            inverse.scale = {0.f,0.f};
            inverse.translation = {-(f.translation.x) , -(f.translation.y)};
            return inverse;
        }

    };

    constexpr BasicTransform(const sf::Vector2f& scale = {1.f, 1.f},
                             const sf::Vector2f& translation = {0.f, 0.f})
        : scale{scale}, translation{translation} {}

    constexpr sf::Vector2f applyPoint(const sf::Vector2f& p) const {
        // first scale, then translate -- if you do the reverse, the translation gets messed up.
        return {p.x * scale.x + translation.x, p.y * scale.y + translation.y};
    }

    constexpr sf::Vector2f applyVector(const sf::Vector2f& p) const {
        // vectors are not translated by transformations
        return {p.x * scale.x, p.y * scale.y};
    }

    constexpr bool operator==(const BasicTransform& other) const {
        return scale == other.scale && translation == other.translation;
    }

    sf::Vector2f scale;
    sf::Vector2f translation;
};

#endif