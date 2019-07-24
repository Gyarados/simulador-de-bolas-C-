#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/bola.h"
#include "include/quadro.h"

using namespace std;

int main()
{
    unsigned int escala = 1;
    unsigned int window_width = 960;
    unsigned int window_height = 960;

    sf::RenderWindow window(sf::VideoMode(escala*window_width, escala*window_height), "janela SFML");

    sf::Vector2i vetor_window(-8, 0);
    window.setPosition(vetor_window);

    Bola bolaMouse(30, 0, 0, sf::Color::Blue);

    Bola bola1(30, 200, 200, sf::Color::Magenta);
    Bola* pbola1 = &bola1;

    Bola bola2(30, 300, 200, sf::Color::Red);
    Bola* pbola2 = &bola2;

    Bola bola3(30, 400, 200, sf::Color::Green);
    Bola* pbola3 = &bola3;

    sf::Font font_do_textao;
    if (!font_do_textao.loadFromFile("Afterglow-Regular.ttf")){
        return EXIT_FAILURE;
    }
    sf::Text textao("Simulador de bolas caindo. Clique para ver mais bolas caindo.", font_do_textao, 30);
    textao.setFillColor(sf::Color::Black);
    textao.setPosition(50, 0);

    sf::Clock clock;

    Quadro quadro;

    quadro.adicionarBola(pbola1);

    quadro.adicionarBola(pbola2);

    quadro.adicionarBola(pbola3);

    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed){

                Bola* pBolaMouse = new Bola(30, bolaMouse.getCirculo().getPosition().x, bolaMouse.getCirculo().getPosition().y, sf::Color::Blue);
                quadro.adicionarBola(pBolaMouse);

            }
        }

        bolaMouse.setPosition(sf::Mouse::getPosition(window).x-10, sf::Mouse::getPosition(window).y-10);
        window.draw(bolaMouse);
        quadro.updatePos();
        window.draw(quadro);

        window.draw(textao);

        window.display();

    }

    return 0;
}
