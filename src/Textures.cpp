#include "Textures.h"
#include <iostream>
Textures::Textures(const std::string& filename)
{
    texture.loadFromFile(filename);
}
sf::Texture Textures::getTexture()
{
    return texture;
}
