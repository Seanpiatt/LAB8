#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include "sprite.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <string>
using SpriteID = size_t;

class SpriteManager {
public: 
    sf::Texture& registerTexture(const std::string& filepath){
        auto it = mTextureMap.find(filepath);
        if (it == mTextureMap.end()) {
            it = mTextureMap.emplace(filepath, filepath).first;
        }
        return it->second;
    }

    template <typename... Args>
    SpriteID createSprite(Args&&... args){
        mSprites.emplace_back(std::forward<Args>(args)...);
        return mSprites.size() - 1;
    }

    Sprite& getSprite(SpriteID id){
        return mSprites[id];
    }
private:
    std::unordered_map<std::string, sf::Texture> mTextureMap;
    std::vector<Sprite> mSprites;


};

#endif  // SPRITE_MANAGER_H
