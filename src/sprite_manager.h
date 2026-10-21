#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include "sprite.h"
#include <SFML/Graphics.hpp>

using SpriteID = size_t;

class SpriteManager {
    
    sf::Texture& registerTexture(const std::string& filepath){}

    template <typename... Args> 
    SpriteID createSprite(Args&&... args){}
    
    Sprite& getSprite(SpriteID id){
        //return &SpriteID;
    }

};

#endif  // SPRITE_MANAGER_H
