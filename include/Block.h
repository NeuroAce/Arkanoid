#include <SFML/Graphics.hpp>

class Block:public sf::Drawable
{
public:
    Block(float t_X,float t_Y,float t_Width,float t_Hight);
    Block()=delete;
    virtual ~Block()=default;

    void update(int level);

    sf::Vector2f getPosition();

    float left();
    float right();
    float top();
    float bottom();

    bool isDestroyed();
    void destroy();


    sf::Vector2f getSize();
    sf::RectangleShape shape;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

    bool destroyed{false};
};
