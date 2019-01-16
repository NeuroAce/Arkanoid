#include <SFML\Graphics.hpp>
#include <Ball.h>
#include <Paddle.h>
#include <Block.h>
#include <Menu1.h>
#include <GameOver.h>
#include <vector>

 /* Na pocz¹tku pisa³em t¹ grê ¿eby siê uczyæ. To spowodowa³o, ¿e implementowa³em kolejne rozwi¹zania na oœlep. PóŸniej, gdy by³em w po³owie aplikacji okaza³o siê, ¿e
przyda mi siê do szko³y i musia³em j¹ skoñczyæ jak najszybciej, co z kolei spowodowa³o ¿e pisa³em ¿eby tylko skoñczyæ i podnieœæ sobie ocenê z przedmiotów, uda³o siê wyci¹gn¹æ kilka 6 ,ale te¿ zepsuæ czytelnoœæ i w
niektórych miejscach przesta³em u¿ywaæ funkcji, mimo, ¿e to by³o by wskazane. W pewnym momencie nawet zacz¹³em zmienniaæ styl nazywania zmiennych, na szczêœcie siê wysili³em i pisa³em wci¹¿ po angielsku. */


template<class T1, class T2> bool isIntercecting(T1& A,T2& B)
{
    return (A.right()>=B.left() && A.left()<=B.right()&& A.bottom()>=B.top() && A.top()<=B.bottom());
}

bool collisionTest(Paddle& paddle,Ball& ball)
{
    if(!isIntercecting(paddle,ball))
        return false;
    ball.moveUp();

    if(ball.getPosition().x<paddle.left())
        ball.moveLeft();

    else if(ball.getPosition().x>paddle.right())
        ball.moveRight();
    return true;
}


bool collisionTest(Block& block,Ball& ball,Menu1& menu)
{
    if(!isIntercecting(block,ball))
        return false;
    block.destroy();
    menu.scoreUpdate();

    float overlapLeft{ball.right()-block.left()};
    float overlapRight{block.right()-ball.left()};

    float overlapTop{ball.bottom()-block.top()};
    float overlapBottom{block.bottom()-block.top()};

    bool ballFromLeft(abs(overlapLeft)<abs(overlapRight));
    bool ballFromTop(abs(overlapTop)<abs(overlapBottom));

    float minOverlapX {ballFromLeft ? overlapLeft:overlapRight};
    float minOverlapY {ballFromTop ? overlapTop:overlapBottom};

    if (abs(minOverlapX)<abs(minOverlapY))
    {
        ballFromLeft ? ball.moveLeft():ball.moveRight();
    }
    else
    {
        ballFromTop ? ball.moveUp():ball.moveDown();
    }
    return true;
}

void createBlocks(std::vector<Block>& blocks)
{
    unsigned int blocksX{8},blocksY{6}, blockWidth{85}, blockHight{22};

    for (unsigned int i=0; i<blocksY; i++)
    {
        for(unsigned int j=0; j<blocksX; j++)
        {
            blocks.emplace_back(((j+0.6)*(blockWidth+12))+200,(i+1)*(blockHight+12),blockWidth,blockHight);
        }
    }
}
void nextLevel(Menu1& menu,std::vector<Block>& blocks,Ball& ball,Paddle& paddle,sf::Texture& texture)
{
    menu.levelUpdate();
    createBlocks(blocks);

    for(auto& block : blocks)
    {
        block.update(menu.getIntlevel());
        block.shape.setTexture(&texture);
    }

    ball.resetPosition();
    ball.SpeedUp();
}
void resetGame(Menu1& menu,std::vector<Block>& blocks,Ball& ball,Paddle& paddle,sf::Texture& texture)
{
    menu.resetMenu();
    ball.resetPosition();
    ball.resetSpeed();
    blocks.clear();
    createBlocks(blocks);
    for(auto& block : blocks)
        block.update(1);
    paddle.resetPaddle(600,480);

    for(auto& block : blocks)
        block.shape.setTexture(&texture);

}

int main()
{
    bool gameoverIsActive=false;
    bool mauseUse=false;
    int control=0;

    unsigned windowWidth=1000,windowHight=500;

    Ball ball(windowWidth*0.5f,windowHight*0.5f);

    Paddle paddle(windowWidth*0.5f,windowHight-20);
    sf::Texture texture_paddle;
    texture_paddle.loadFromFile("paddle_zielony.png");
    paddle.shape.setTexture(&texture_paddle);

    Menu1 menu(0,0);
    GameOver gameover(200+(windowWidth-500)/2,125);

    sf::Texture texture_block;
    texture_block.loadFromFile("block_purple.png");


    sf::RenderWindow window{sf::VideoMode{windowWidth,windowHight},"Arkanoid by NeuroAce"};
    window.setFramerateLimit(60);

    std::vector <Block> blocks;
    createBlocks(blocks);

    for(auto& block : blocks)
        block.shape.setTexture(&texture_block);

    sf::Event event;

    while(window.isOpen())
    {
        window.clear(sf::Color::Black);

        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Return)
                {
                    resetGame(menu,blocks,ball,paddle,texture_block);

                    gameoverIsActive=false;
                }
                break;
            default:
                break;
            }
        }
        auto iterator =remove_if(begin(blocks),end(blocks),[](Block& block)
        {
            return block.isDestroyed();
        });

        blocks.erase(iterator,end(blocks));

        if(ball.update()==0)
        {
            gameover.gameover(200+(windowWidth-500)/2,125,menu.getnickname(),menu.gethighscore(),menu.getlevel(),menu.getscore());
            gameoverIsActive=true;
        }

        if(iterator==begin(blocks)&&gameoverIsActive==false)
        {
            nextLevel(menu,blocks,ball,paddle,texture_block);
        }

        paddle.update();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            if(control==2)
                control=0;
            control++;
            switch (control)
            {
            case 1:
                mauseUse=true;
                break;
            case 2:
                mauseUse=false;
                break;
            default:
                break;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)||mauseUse==true)
        {
            paddle.updateByMouse(sf::Mouse::getPosition(window),paddle);
        }

        collisionTest(paddle,ball);


        for(auto& block : blocks)
            if(collisionTest(block,ball,menu))
                break;


        window.draw(ball);
        window.draw(paddle);
        window.draw(menu);

        for(auto& block : blocks)
            window.draw(block);

        if(gameoverIsActive)
            window.draw(gameover);

        window.display();

    }
    return 0;
}
