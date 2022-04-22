#include <SFML/Graphics.hpp>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <iostream>
#include <sys/time.h>
#include <sstream>
#include <string>

int WIDTH = 600;
int HEIGHT = 400;
float RADIUS = 60.f;
int COLORINDEX = -1;
int GLOBALSCORE = 10;
int DELAY_SEGS = 3;
double ACC_TIME = 0.0;
int ROUND = 1;

std::vector<sf::Color> colors = {sf::Color::Yellow, 
                                 sf::Color::Red, 
                                 sf::Color::Cyan, 
                                 sf::Color::Green};

sf::CircleShape randomizeCircle(){
    float x, y;
    
    x = rand() % WIDTH;
    if (x > WIDTH - 2*RADIUS) x -= 2*RADIUS;
    y = rand() % HEIGHT;
    if (y > HEIGHT - 2*RADIUS) y -= 2*RADIUS;
    COLORINDEX = rand() % (int)colors.size();

    sf::CircleShape shape(RADIUS);
    shape.setFillColor(colors[COLORINDEX]);
    shape.setPosition(x, y);

    return shape;
}

template <typename T>
std::string toString(T arg)
{
    std::stringstream ss;
    ss << arg;
    return ss.str();
}

void updateTexts(sf::Text &scoreText, sf::Text &meanText){
    std::string score = toString<int>(GLOBALSCORE);
    std::string mean = toString<double>((double)ACC_TIME/ROUND);
    scoreText.setString("Score: " + score);
    meanText.setString("Mean time: " + mean + "s");
}

int main()
{
    srand (time(NULL));

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Reaction Game");
    sf::CircleShape shape = randomizeCircle();

    struct timeval tempo_inicial, tempo_final;
    int tmicro = 0;
    int delay_usegs = DELAY_SEGS*1000000;
    bool acertou = false;

    sf::Font font;
    sf::Text scoreText, reactionText, meanText, instructionsText;

    font.loadFromFile("/home/angelubuntu/Desktop/STR/reacao_sfml/fonts/arial_narrow_7.ttf");
    
    scoreText.setString("Score: ");
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setPosition(10.f, 5.f);

    reactionText.setString("Reaction time: ");
    reactionText.setFont(font);
    reactionText.setCharacterSize(24);
    reactionText.setPosition(10.f, 30.f);

    meanText.setString("Mean time: ");
    meanText.setFont(font);
    meanText.setCharacterSize(24);
    meanText.setPosition(10.f, 55.f);

    instructionsText.setString("Press:\nLeft Red\nUp Yellow\nRight Blue\nDown Green\nR to Restart");
    instructionsText.setFont(font);
    instructionsText.setCharacterSize(12);
    instructionsText.setPosition(10.f, 315.f);

    

    while (window.isOpen())
    {
        
        gettimeofday(&tempo_inicial, NULL);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed){

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                    if (COLORINDEX == 1) acertou = true;

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                    if (COLORINDEX == 2) acertou = true;

                }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                    if (COLORINDEX == 0) acertou = true;

                }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    if (COLORINDEX == 3) acertou = true;

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                    GLOBALSCORE = 9;
                    ACC_TIME = 0.0;
                    ROUND = 0;
                    tmicro = 0;
                    shape = randomizeCircle();
                    acertou = true;
                    
                }

                double time = (double)tmicro/1000000;
                ACC_TIME += time;

                if (acertou){

                    std::string reaction = toString<double>(time);
                    reactionText.setString("Reaction Time: " + reaction + "s");

                    GLOBALSCORE += 1;
                    acertou = false;
                    ROUND += 1;

                } else {
                    GLOBALSCORE -= 1;
                }

                tmicro = 0;
                shape = randomizeCircle();
                updateTexts(scoreText, meanText);
                
            }
        }

        window.clear();
        window.draw(shape);
        window.draw(scoreText);
        window.draw(reactionText);
        window.draw(meanText);
        window.draw(instructionsText);
        window.display();

        gettimeofday(&tempo_final, NULL);

        if(tempo_inicial.tv_usec > tempo_final.tv_usec)
             tmicro += (tempo_final.tv_usec + 1000000 - tempo_inicial.tv_usec);
        else tmicro += (tempo_final.tv_usec - tempo_inicial.tv_usec);

        if (tmicro > delay_usegs){

            GLOBALSCORE -= 1;
            tmicro = 0;
            shape = randomizeCircle();
            ACC_TIME += (double) DELAY_SEGS;
            updateTexts(scoreText, meanText);

        }
    }

    return 0;
}