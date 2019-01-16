#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <GameOver.h>
#include <Menu1.h>



void GameOver::gameover(unsigned int g_X,unsigned g_Y,std::string nickname,std::string highscore,std::string level,std::string score)
{
    font.loadFromFile("Roboto-Thin.ttf");

    textGameOver.setFont(font);
    textGameOver.setString("Game Over");
    textGameOver.setCharacterSize(GameOverFontSize);
    textGameOver.setFillColor(sf::Color::White);
    textGameOver.setStyle(sf::Text::Bold);
    textGameOver.setPosition(g_X+(GameOverWidth-textGameOver.getGlobalBounds().width)/2,g_Y+45);

    textNick=textGameOver;
    textNick.setString("Nick: "+nickname);
    textNick.setCharacterSize(fontSize);
    textNick.setFillColor(sf::Color::White);
    textNick.setStyle(sf::Text::Regular);
    textNick.setPosition(g_X+(GameOverWidth-textNick.getGlobalBounds().width)/2,g_Y+45+GameOverFontSize+fontSize+9);

    textHighScore=textNick;
    textHighScore.setString("High score: "+highscore);
    textHighScore.setPosition(g_X+(GameOverWidth-textHighScore.getGlobalBounds().width)/2,g_Y+45+GameOverFontSize+(fontSize+2)*2+9);

    textLevel=textNick;
    textLevel.setString("Level: "+level);
    textLevel.setPosition(g_X+(GameOverWidth-textLevel.getGlobalBounds().width)/2,g_Y+45+GameOverFontSize+(fontSize+2)*3+9);

    textScore=textNick;
    textScore.setString("Score: "+score);
    textScore.setPosition(g_X+(GameOverWidth-textScore.getGlobalBounds().width)/2,g_Y+45+GameOverFontSize+(fontSize+2)*4+9);

}

GameOver::GameOver(unsigned int g_X,unsigned g_Y)
{
    GameOverBackground.setPosition(g_X,g_Y);
    GameOverBackground.setSize({this->GameOverWidth,this->GameOverHight});
    GameOverBackground.setFillColor(sf::Color(55,55,55));
}
void GameOver::draw(sf::RenderTarget& target,sf::RenderStates state)const
{
    target.draw(this->GameOverBackground,state);
    target.draw(this->textGameOver,state);
    target.draw(this->textNick,state);
    target.draw(this->textHighScore,state);
    target.draw(this->textLevel,state);
    target.draw(this->textScore,state);
}
