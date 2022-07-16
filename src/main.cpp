#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sys/time.h>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <math.h>
#include <sys/resource.h>
#include <sched.h>

int SELECTED_ID = -1;

// SPEEDS
float v_T1 = 50;
float v_T2 = 50;
float v_T3 = 50;
float v_T4 = 50;
int v_max = 5000000;

// PIVOT POSITIONS
float spritew = 30.f;
float borderw = 40.f;
float trailw = 160.f;
float t1px = borderw + trailw / 2;
float t1py = borderw + trailw / 2;
float t2px = t1px + trailw;
float t2py = t1py;
float t3px = t1px;
float t3py = t1py + trailw;
float t4px = t1px + trailw;
float t4py = t1py + trailw;

void func_T1(sf::RectangleShape *sprite)
{

    while (1)
    {
        usleep((100 - v_T1) / 100 * v_max);
        std::cout << "T1: Trilho 1" << std::endl;
        sprite->setPosition(t1px - trailw / 2, t1py);

        usleep((100 - v_T1) / 100 * v_max);
        std::cout << "T1: Trilho 2" << std::endl;
        sprite->setPosition(t1px, t1py - trailw / 2);

        usleep((100 - v_T1) / 100 * v_max);
        std::cout << "T1: Trilho 3" << std::endl;
        sprite->setPosition(t1px + trailw / 2, t1py);

        usleep((100 - v_T1) / 100 * v_max);
        std::cout << "T1: Trilho 4" << std::endl;
        sprite->setPosition(t1px, t1py + trailw / 2);
    }
}

void func_T2(sf::RectangleShape *sprite)
{
    while (1)
    {
        usleep((100 - v_T2) / 100 * v_max);
        std::cout << "T2: Trilho 5" << std::endl;
        sprite->setPosition(t2px, t2py - trailw / 2);

        usleep((100 - v_T2) / 100 * v_max);
        std::cout << "T2: Trilho 6" << std::endl;
        sprite->setPosition(t2px + trailw / 2, t2py);

        usleep((100 - v_T2) / 100 * v_max);
        std::cout << "T2: Trilho 7" << std::endl;
        sprite->setPosition(t2px, t2py + trailw / 2);

        usleep((100 - v_T2) / 100 * v_max);
        std::cout << "T2: Trilho 3" << std::endl;
        sprite->setPosition(t2px - trailw / 2, t2py);
    }
}

void func_T3(sf::RectangleShape *sprite)
{
    while (1)
    {
        usleep((100 - v_T3) / 100 * v_max);
        std::cout << "T3: Trilho 10" << std::endl;
        sprite->setPosition(t3px, t3py + trailw / 2);

        usleep((100 - v_T3) / 100 * v_max);
        std::cout << "T3: Trilho 8" << std::endl;
        sprite->setPosition(t3px - trailw / 2, t3py);

        usleep((100 - v_T3) / 100 * v_max);
        std::cout << "T3: Trilho 4" << std::endl;
        sprite->setPosition(t3px, t3py - trailw / 2);

        usleep((100 - v_T3) / 100 * v_max);
        std::cout << "T3: Trilho 9" << std::endl;
        sprite->setPosition(t3px + trailw / 2, t3py);
    }
}

void func_T4(sf::RectangleShape *sprite)
{
    while (1)
    {
        usleep((100 - v_T4) / 100 * v_max);
        std::cout << "T4: Trilho 11" << std::endl;
        sprite->setPosition(t4px + trailw / 2, t4py);

        usleep((100 - v_T4) / 100 * v_max);
        std::cout << "T4: Trilho 12" << std::endl;
        sprite->setPosition(t4px, t4py + trailw / 2);

        usleep((100 - v_T4) / 100 * v_max);
        std::cout << "T4: Trilho 9" << std::endl;
        sprite->setPosition(t4px - trailw / 2, t4py);

        usleep((100 - v_T4) / 100 * v_max);
        std::cout << "T4: Trilho 7" << std::endl;
        sprite->setPosition(t4px, t4py - trailw / 2);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(620, 420), "Four train system");

    /////////////////// INTERFACE VARIABLES

    sf::Font font;
    font.loadFromFile("/home/angelubuntu/Documents/UFRN/STR_3/test_threads/fonts/arial_narrow_7.ttf");
    float px = 440.f;
    float py = 250.f;
    float hpadding = 5.f;
    float vpadding = 30.f;
    float backpadding = 15.f;
    float forwardpadding = 30.f;
    float boxh = 20.f;
    float boxw = 90.f;
    int font_size = 20;

    sf::Text text;

    /////////////////// TREM 1

    sf::RectangleShape T1Box;
    T1Box.setSize(sf::Vector2f(boxw, boxh));
    T1Box.setOutlineColor(sf::Color::Red);
    T1Box.setPosition(px + forwardpadding, py + vpadding * 0);

    sf::RectangleShape T1Sprite;
    T1Sprite.setSize(sf::Vector2f(spritew, spritew));
    T1Sprite.setFillColor(sf::Color::Yellow);
    T1Sprite.setOutlineThickness(-2);
    T1Sprite.setPosition(t1px, t1py + trailw / 2);

    sf::String T1Input("50");
    sf::Text T1Text;
    T1Text.setFont(font);
    T1Text.setColor(sf::Color::Black);
    T1Text.setCharacterSize(18);
    T1Text.setString(T1Input);
    T1Text.setPosition(px + forwardpadding + hpadding, py + vpadding * 0);

    sf::Text T1Label;
    T1Label.setString("T1:                    %");
    T1Label.setFont(font);
    T1Label.setColor(sf::Color::White);
    T1Label.setCharacterSize(font_size);
    T1Label.setPosition(px - backpadding, py + vpadding * 0 - 3);

    /////////////////// TREM 2

    sf::RectangleShape T2Box;
    T2Box.setSize(sf::Vector2f(boxw, boxh));
    T2Box.setOutlineColor(sf::Color::Red);
    T2Box.setPosition(px + forwardpadding, py + vpadding * 1);

    sf::RectangleShape T2Sprite;
    T2Sprite.setSize(sf::Vector2f(spritew, spritew));
    T2Sprite.setFillColor(sf::Color::Blue);
    T2Sprite.setOutlineThickness(-2);
    T2Sprite.setPosition(t2px - trailw / 2, t2py);

    sf::String T2Input("50");
    sf::Text T2Text;
    T2Text.setFont(font);
    T2Text.setColor(sf::Color::Black);
    T2Text.setCharacterSize(18);
    T2Text.setString(T2Input);
    T2Text.setPosition(px + forwardpadding + hpadding, py + vpadding * 1);

    sf::Text T2Label;
    T2Label.setString("T2:                    %");
    T2Label.setFont(font);
    T2Label.setColor(sf::Color::White);
    T2Label.setCharacterSize(font_size);
    T2Label.setPosition(px - backpadding, py + vpadding * 1 - 3);

    /////////////////// TREM 3

    sf::RectangleShape T3Box;
    T3Box.setSize(sf::Vector2f(boxw, boxh));
    T3Box.setOutlineColor(sf::Color::Red);
    T3Box.setPosition(px + forwardpadding, py + vpadding * 2);

    sf::RectangleShape T3Sprite;
    T3Sprite.setSize(sf::Vector2f(spritew, spritew));
    T3Sprite.setFillColor(sf::Color::Red);
    T3Sprite.setOutlineThickness(-2);
    T3Sprite.setPosition(t3px + trailw / 2, t3py);

    sf::String T3Input("50");
    sf::Text T3Text;
    T3Text.setFont(font);
    T3Text.setColor(sf::Color::Black);
    T3Text.setCharacterSize(18);
    T3Text.setString(T3Input);
    T3Text.setPosition(px + forwardpadding + hpadding, py + vpadding * 2);

    sf::Text T3Label;
    T3Label.setString("T3:                    %");
    T3Label.setFont(font);
    T3Label.setColor(sf::Color::White);
    T3Label.setCharacterSize(font_size);
    T3Label.setPosition(px - backpadding, py + vpadding * 2 - 3);

    /////////////////// TREM 4

    sf::RectangleShape T4Box;
    T4Box.setSize(sf::Vector2f(boxw, boxh));
    T4Box.setOutlineColor(sf::Color::Red);
    T4Box.setPosition(px + forwardpadding, py + vpadding * 3);

    sf::RectangleShape T4Sprite;
    T4Sprite.setSize(sf::Vector2f(spritew, spritew));
    T4Sprite.setFillColor(sf::Color::Green);
    T4Sprite.setOutlineThickness(-2);
    T4Sprite.setPosition(t4px, t4py - trailw / 2);

    sf::String T4Input("50");
    sf::Text T4Text;
    T4Text.setFont(font);
    T4Text.setColor(sf::Color::Black);
    T4Text.setCharacterSize(18);
    T4Text.setString(T4Input);
    T4Text.setPosition(px + forwardpadding + hpadding, py + vpadding * 3);

    sf::Text T4Label;
    T4Label.setString("T4:                    %");
    T4Label.setFont(font);
    T4Label.setColor(sf::Color::White);
    T4Label.setCharacterSize(font_size);
    T4Label.setPosition(px - backpadding, py + vpadding * 3 - 3);

    /////////////////// TRACKS

    sf::RectangleShape TL_Track;
    TL_Track.setSize(sf::Vector2f(trailw, trailw));
    TL_Track.setFillColor(sf::Color::Black);
    TL_Track.setOutlineColor(sf::Color::Yellow);
    TL_Track.setOutlineThickness(-3);
    TL_Track.setPosition(borderw + spritew / 2, borderw + spritew / 2);

    sf::RectangleShape TR_Track;
    TR_Track.setSize(sf::Vector2f(trailw, trailw));
    TR_Track.setFillColor(sf::Color::Black);
    TR_Track.setOutlineColor(sf::Color::Blue);
    TR_Track.setOutlineThickness(-3);
    TR_Track.setPosition(borderw + spritew / 2 + trailw, borderw + spritew / 2);

    sf::RectangleShape BL_Track;
    BL_Track.setSize(sf::Vector2f(trailw, trailw));
    BL_Track.setFillColor(sf::Color::Black);
    BL_Track.setOutlineColor(sf::Color::Red);
    BL_Track.setOutlineThickness(-3);
    BL_Track.setPosition(borderw + spritew / 2, borderw + spritew / 2 + trailw);

    sf::RectangleShape BR_Track;
    BR_Track.setSize(sf::Vector2f(trailw, trailw));
    BR_Track.setFillColor(sf::Color::Black);
    BR_Track.setOutlineColor(sf::Color::Green);
    BR_Track.setOutlineThickness(-3);
    BR_Track.setPosition(borderw + spritew / 2 + trailw, borderw + spritew / 2 + trailw);

    /////////////////// INSTRUCTIONS

    sf::Text InstructionsText;
    InstructionsText.setString("Press Enter to\napply changes\nin speed");
    InstructionsText.setFont(font);
    InstructionsText.setColor(sf::Color::White);
    InstructionsText.setCharacterSize(font_size - 2);
    InstructionsText.setPosition(px + hpadding, py - vpadding * 3);

    /////////////////// THREADS

    sf::Thread thread1(&func_T1, &T1Sprite);
    sf::Thread thread2(&func_T2, &T2Sprite);
    sf::Thread thread3(&func_T3, &T3Sprite);
    sf::Thread thread4(&func_T4, &T4Sprite);

    thread1.launch();
    thread2.launch();
    thread3.launch();
    thread4.launch();

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle text box input
            if (event.type == sf::Event::TextEntered)
            {
                if (SELECTED_ID >= 0)
                {
                    switch (SELECTED_ID)
                    {
                    case 0:
                        if (event.text.unicode == 8)
                        {
                            if (T1Input.getSize() > 0)
                                T1Input.erase(T1Input.getSize() - 1, 1);
                        }
                        else
                            T1Input += event.text.unicode;
                        T1Text.setString(T1Input);
                        break;

                    case 1:
                        if (event.text.unicode == 8)
                        {
                            if (T2Input.getSize() > 0)
                                T2Input.erase(T2Input.getSize() - 1, 1);
                        }
                        else
                            T2Input += event.text.unicode;
                        T2Text.setString(T2Input);
                        break;

                    case 2:
                        if (event.text.unicode == 8)
                        {
                            if (T3Input.getSize() > 0)
                                T3Input.erase(T3Input.getSize() - 1, 1);
                        }
                        else
                            T3Input += event.text.unicode;
                        T3Text.setString(T3Input);
                        break;

                    case 3:
                        if (event.text.unicode == 8)
                        {
                            if (T4Input.getSize() > 0)
                                T4Input.erase(T4Input.getSize() - 1, 1);
                        }
                        else
                            T4Input += event.text.unicode;
                        T4Text.setString(T4Input);
                        break;

                    default:
                        break;
                    }
                }
            }

            // Handle key events
            if (event.type == sf::Event::KeyPressed)
            {
                if (SELECTED_ID < 0)
                {
                    std::string T1_string = T1Input.toAnsiString();
                    std::string T2_string = T2Input.toAnsiString();
                    std::string T3_string = T3Input.toAnsiString();
                    std::string T4_string = T4Input.toAnsiString();

                    if (!T1_string.empty() &&
                        !T2_string.empty() &&
                        !T3_string.empty() &&
                        !T4_string.empty())
                    {

                        if (event.key.code == sf::Keyboard::Enter)
                        {
                            std::cout << "Setting new speeds" << std::endl;
                            v_T1 = std::stoi(T1_string);
                            v_T2 = std::stoi(T2_string);
                            v_T3 = std::stoi(T3_string);
                            v_T4 = std::stoi(T4_string);
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                int x = sf::Mouse::getPosition(window).x;
                int y = sf::Mouse::getPosition(window).y;

                if (y < py || y > py + 4 * vpadding)
                    SELECTED_ID = -1;
                if (y > py && y < py + vpadding)
                    SELECTED_ID = 0;
                if (y > py + vpadding && y < py + 2 * vpadding)
                    SELECTED_ID = 1;
                if (y > py + 2 * vpadding && y < py + 3 * vpadding)
                    SELECTED_ID = 2;
                if (y > py + 3 * vpadding && y < py + 4 * vpadding)
                    SELECTED_ID = 3;

                std::cout << SELECTED_ID << std::endl;

                T1Box.setOutlineThickness(0);
                T2Box.setOutlineThickness(0);
                T3Box.setOutlineThickness(0);
                T4Box.setOutlineThickness(0);

                switch (SELECTED_ID)
                {
                case 0:
                    T1Box.setOutlineThickness(2);
                    break;
                case 1:
                    T2Box.setOutlineThickness(2);
                    break;
                case 2:
                    T3Box.setOutlineThickness(2);
                    break;
                case 3:
                    T4Box.setOutlineThickness(2);
                    break;
                default:
                    break;
                }
            }
        }

        window.clear();
        window.draw(text);

        window.draw(T1Box);
        window.draw(T2Box);
        window.draw(T3Box);
        window.draw(T4Box);

        window.draw(T1Text);
        window.draw(T2Text);
        window.draw(T3Text);
        window.draw(T4Text);

        window.draw(T1Label);
        window.draw(T2Label);
        window.draw(T3Label);
        window.draw(T4Label);

        window.draw(TL_Track);
        window.draw(TR_Track);
        window.draw(BL_Track);
        window.draw(BR_Track);

        window.draw(T1Sprite);
        window.draw(T2Sprite);
        window.draw(T3Sprite);
        window.draw(T4Sprite);

        window.draw(InstructionsText);

        window.display();
    }

    return 0;
}
