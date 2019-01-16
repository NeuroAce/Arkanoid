#include <SFML/Graphics.hpp>
#include <Block.h>

Block::Block(float t_X,float t_Y,float t_Width,float t_Hight)
{
    shape.setPosition(t_X,t_Y);
    shape.setSize({t_Width,t_Hight});
    //texture_block.loadFromFile("block_purple.png");
    //shape.setTexture(&texture_block);
    shape.setFillColor(sf::Color(148,0,211));
    shape.setOrigin(t_Width/2.f,t_Hight/2.f);
}
void Block::draw(sf::RenderTarget& target,sf::RenderStates state)const
{
    target.draw(this->shape,state);
}
float Block::left()
{
    return this->shape.getPosition().x-shape.getSize().x/2.f;

}

float Block::right()
{
    return this->shape.getPosition().x+shape.getSize().x/2.f;

}

float Block::top()
{
    return this->shape.getPosition().y-shape.getSize().y/2.f;

}
float Block::bottom()
{
    return this->shape.getPosition().y+shape.getSize().y/2.f;

}
sf::Vector2f Block::getPosition()
{
    return shape.getPosition();
}

bool Block::isDestroyed()
{
    return this->destroyed;
}

void Block::destroy()
{
    this->destroyed=true;
}

sf::Vector2f Block::getSize()
{
    return shape.getSize();
}

void Block::update(int level)
{
    switch (level)
    {
    case 1:
        shape.setFillColor(sf::Color(148,0,211));
        break;
    case 2:
        shape.setFillColor(sf::Color(75,0,130));
        break;
    case 3:
        shape.setFillColor(sf::Color::Blue);
        break;
    case 4:
        shape.setFillColor(sf::Color::Green);
        break;
    case 5:
        shape.setFillColor(sf::Color::Yellow);
        break;
    case 6:
        shape.setFillColor(sf::Color(255,127,0));
        break;
    case 7:
        shape.setFillColor(sf::Color::Red);
        break;
    default:
        break;
    }
}
