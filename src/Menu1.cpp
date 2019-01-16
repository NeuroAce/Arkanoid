#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <Menu1.h>


Menu1::Menu1(float m_X,float m_Y)
{
    MenuBackground.setPosition(m_X,m_Y);
    MenuBackground.setSize({this->menuWidth,this->menuHight});
    MenuBackground.setFillColor(sf::Color(0,51,51));

    fontRegular.loadFromFile("Roboto-Regular.ttf");
    fontBold.loadFromFile("Roboto-Bold.ttf");
    fontThin.loadFromFile("Roboto-Thin.ttf");
    highscoreFile.open( "high_score.txt", std::ios::in | std::ios::out );
    if( highscoreFile.good() == true )
    {
        highscoreFile>>highscore;
        test=highscore;
        highscoreFile.close();
    }


    textNick.setFont(fontBold);
    textNick.setString("Nick: "+nickname);
    textNick.setCharacterSize(fontSize);
    textNick.setFillColor(sf::Color::White);
    textNick.setPosition((menuWidth-textNick.getGlobalBounds().width)/2,30);



    textHighScore=textNick;
    textHighScore.setFont(fontRegular);
    textHighScore.setString("High score: "+highscore);
    textHighScore.setStyle(sf::Text::Regular);
    textHighScore.setPosition((menuWidth-textHighScore.getGlobalBounds().width)/2,30+fontSize+5);

    textLevel=textHighScore;
    textLevel.setString("Level: "+std::to_string(level));
    textLevel.setPosition((menuWidth-textLevel.getGlobalBounds().width)/2,30+(fontSize+5)*2);

    textScore=textHighScore;
    textScore.setString("Score: "+std::to_string(score));
    textScore.setPosition((menuWidth-textScore.getGlobalBounds().width)/2-10,30+(fontSize+5)*3);

    textMouseControl1=textHighScore;
    textMouseControl1.setCharacterSize(fontSizeTips);
    textMouseControl1.setString("Press L key");
    textMouseControl1.setFillColor(sf::Color(137, 193, 114));
    textMouseControl1.setPosition((menuWidth-textMouseControl1.getGlobalBounds().width)/2,30+(fontSizeTips+5)*7);

    textMouseControl2=textMouseControl1;
    textMouseControl2.setString("to use mouse");
    textMouseControl2.setPosition((menuWidth-textMouseControl2.getGlobalBounds().width)/2,30+(fontSizeTips+5)*8);

    textMouseControl3=textMouseControl1;
    textMouseControl3.setString("as a paddle controler");
    textMouseControl3.setPosition((menuWidth-textMouseControl3.getGlobalBounds().width)/2,30+(fontSizeTips+5)*9);

    textRestart1=textMouseControl1;
    textRestart1.setFillColor(sf::Color(162, 173, 164));
    textRestart1.setString("Press Enter");
    textRestart1.setPosition((menuWidth-textRestart1.getGlobalBounds().width)/2,30+(fontSizeTips+5)*11);

    textRestart2=textRestart1;
    textRestart2.setString("to restart the game");
    textRestart2.setPosition((menuWidth-textRestart2.getGlobalBounds().width)/2,30+(fontSizeTips+5)*12);

}
void Menu1::draw(sf::RenderTarget& target,sf::RenderStates state)const
{
    target.draw(this->MenuBackground,state);
    target.draw(this->textNick,state);
    target.draw(this->textHighScore,state);
    target.draw(this->textLevel,state);
    target.draw(this->textScore,state);
    target.draw(this->textMouseControl1,state);
    target.draw(this->textMouseControl2,state);
    target.draw(this->textMouseControl3,state);
    target.draw(this->textRestart1,state);
    target.draw(this->textRestart2,state);
}
void Menu1::scoreUpdate()
{
    score+=level;
    if(score>std::stoi(highscore))
        highscore=std::to_string(score);
    textScore.setString("Score: "+std::to_string(score));
    textHighScore.setString("High score: "+highscore);
    if(score>std::stoi(test))
    {
        highscoreFile.open( "high_score.txt", std::ios::in | std::ios::out );
        highscoreFile<<score;
        highscoreFile.close();

    }
}
std::string Menu1::getscore()
{
    return std::to_string(score);
}
std::string Menu1::getnickname()
{
    return nickname;
}
std::string Menu1::gethighscore()
{
    return highscore;
}
std::string Menu1::getlevel()
{
    return std::to_string(level);
}
int Menu1::getIntlevel()
{
    return level;
}
void Menu1::levelUpdate()
{
    level++;
    textLevel.setString("Level: "+std::to_string(level));
}
void Menu1::resetMenu()
{
    score=0;
    level=1;
    textScore.setString("Score: "+std::to_string(score));
    textLevel.setString("Level: "+std::to_string(level));
}
