#include <SFML/Graphics.hpp>

class Ball:public sf::Drawable
{
public:

    Ball(float t_X,float t_Y);

    Ball()=delete;
    virtual ~Ball()=default;

    int update();
    void resetPosition();
    void resetSpeed();
    void SpeedUp();

    sf::Vector2f getPosition();

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    float left();
    float right();
    float top();
    float bottom();

    sf::CircleShape shape;

private:



    float BallRadius{8.0f};
    float BallVelocity{4.0f};

    sf::Vector2f velocity{BallVelocity,BallVelocity};

    void draw(sf::RenderTarget& target,sf::RenderStates state) const override;
};
