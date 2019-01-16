#include <SFML/Graphics.hpp>
#include <Paddle.h>


Paddle::Paddle(float t_X,float t_Y)
{
    shape.setPosition(t_X,t_Y);
    shape.setSize({this->paddleWidth,this->paddleHight});
    //shape.setFillColor(sf::Color(0,102,0));
    shape.setOrigin(paddleWidth/2.f,paddleHight/2.f);
}
void Paddle::draw(sf::RenderTarget& target,sf::RenderStates state)const
{
    target.draw(this->shape,state);
}
void Paddle::update()
{
    this->shape.move(this->velocity);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)&& this->left()>200)
    {
        velocity.x=-paddleVelocity;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)&& this->right()<1000)
    {
        velocity.x=paddleVelocity;
    }
    else
    {
        velocity.x=0;
    }
}
float Paddle::left()
{
    return this->shape.getPosition().x-shape.getSize().x/2.f;

}

float Paddle::right()
{
    return this->shape.getPosition().x+shape.getSize().x/2.f;

}

float Paddle::top()
{
    return this->shape.getPosition().y-shape.getSize().y/2.f;

}
float Paddle::bottom ()
{
    return this->shape.getPosition().y+shape.getSize().y/2.f;

}
sf::Vector2f Paddle::getPosition()
{
    return shape.getPosition();
}
void Paddle::resetPaddle(int x,int y)
{
    shape.setPosition(x,y);
}
void Paddle::updateByMouse(sf::Vector2i mousePosition,Paddle paddle)
{
    sf::Vector2f paddleposition=paddle.getPosition();
    shape.setPosition(mousePosition.x,paddleposition.y);
}
void Paddle::setTexture(sf::Texture* texture)
{
    shape.setTexture(texture);
}
