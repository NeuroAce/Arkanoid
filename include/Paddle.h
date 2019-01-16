#include <SFML/Graphics.hpp>

class Paddle : public sf::Drawable
{
public:
    Paddle(float t_X,float t_Y);
    Paddle()=delete ;
    virtual ~Paddle()=default;

    void update();
    void resetPaddle(int x,int y);
    void updateByMouse(sf::Vector2i position,Paddle paddle);
    void setTexture(sf::Texture* texture);

    sf::Vector2f getPosition();

    float left();
    float right();
    float top();
    float bottom();
    sf::RectangleShape shape;

protected:

private:
    void draw(sf::RenderTarget& target,sf::RenderStates state) const override;

    const float paddleWidth{120.0f};
    const float paddleHight{18.0f};
    const float paddleVelocity{17.0f};
    sf::Vector2f velocity{paddleVelocity,0.f};

};
