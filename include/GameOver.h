#include <SFML/Graphics.hpp>
#include <fstream>

class GameOver : public sf::Drawable
{
public:
    GameOver(unsigned int g_X,unsigned g_Y);
    virtual ~GameOver()=default;
    void gameover(unsigned int g_X,unsigned g_Y,std::string nickname,std::string highscore,std::string level,std::string score);

protected:

private:
    void draw(sf::RenderTarget& target,sf::RenderStates state) const override;
    sf::RectangleShape GameOverBackground;
    const float GameOverWidth{300.0f};
    const float GameOverHight{225.0f};

    sf::Font font;
    int fontSize=20;
    int GameOverFontSize=40;

    sf::Text textGameOver;
    sf::Text textNick;
    sf::Text textHighScore;
    sf::Text textLevel;
    sf::Text textScore;

};
