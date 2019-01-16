#include <SFML\Graphics.hpp>
#include <Ball.h>
#include <random>

thread_local std::mt19937 gen{std::random_device{}()};

template<typename T>
T random(T min, T max)
{
    return std::uniform_int_distribution<T> {min, max}(gen);
}


Ball::Ball(float t_X,float t_Y)
{
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->BallRadius);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(this->BallRadius,this->BallRadius);
}
void Ball::draw(sf::RenderTarget& target,sf::RenderStates state)const
{
    target.draw(this->shape,state);
}
int Ball::update()
{
    shape.move(this->velocity);

    if(this->left()<=200)
    {
        velocity.x=BallVelocity;
        return 1;
    }
    if(this->right()>=1000)
    {
        velocity.x=-BallVelocity;
        return 1;
    }
    if(this->top()<=0)
    {
        velocity.y=BallVelocity;
        return 1;
    }
    if(this->bottom()>=500)
    {
        velocity.x=0;
        return 0;
    }
}

float Ball::left()
{
    return this->shape.getPosition().x-shape.getRadius();

}

float Ball::right()
{
    return this->shape.getPosition().x+shape.getRadius();

}

float Ball::top()
{
    return this->shape.getPosition().y-shape.getRadius();

}
float Ball::bottom ()
{
    return this->shape.getPosition().y+shape.getRadius();

}

void Ball::moveDown()
{
    this->velocity.y=BallVelocity;

}

void Ball::moveUp()
{
    this->velocity.y=-BallVelocity;
}

void Ball::moveLeft()
{
    this->velocity.x=-BallVelocity;
}

void Ball::moveRight()
{
    this->velocity.x=BallVelocity;
}

sf::Vector2f Ball::getPosition()
{
    return shape.getPosition();
}
void Ball::resetPosition()
{
    shape.setPosition(600,465);
    int type=random(1,2);
    switch (type)
    {
    case 1:
        this->velocity.x=BallVelocity;
        this->velocity.y=-BallVelocity;
        break;
    case 2:
        this->velocity.x=-BallVelocity;
        this->velocity.y=-BallVelocity;
    default:
        break;
    }
}
void Ball::resetSpeed()
{
    BallVelocity= {4.0f};
}
void Ball::SpeedUp()
{
    BallVelocity++;
}
