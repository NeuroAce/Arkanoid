#include <SFML/Graphics.hpp>
#include <fstream>

class Menu1 : public sf::Drawable
{
public:
    Menu1(float m_X=0,float m_Y=0);
    Menu1()=delete ;
    virtual ~Menu1()=default;
    std::fstream highscoreFile;

    void scoreUpdate();
    void levelUpdate();
    std::string getscore();
    std::string getnickname();
    std::string gethighscore();
    std::string getlevel();
    int getIntlevel();
    void resetMenu();

protected:

private:
    void draw(sf::RenderTarget& target,sf::RenderStates state) const override;
    sf::RectangleShape MenuBackground;
    const float menuWidth{200.0f};
    const float menuHight{500.0f};

    sf::Font fontBold;
    sf::Font fontRegular;
    sf::Font fontThin;
    int fontSize=19;
    int fontSizeTips=17;
    std::string nickname="Neuro Ace";
    std::string highscore="default";
    std::string test="1";
    int level=1;
    int score=0;

    sf::Text textNick;
    sf::Text textHighScore;
    sf::Text textLevel;
    sf::Text textScore;
    sf::Text textMouseControl1;
    sf::Text textMouseControl2;
    sf::Text textMouseControl3;
    sf::Text textRestart1;
    sf::Text textRestart2;

};
