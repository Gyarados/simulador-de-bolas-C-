#ifndef BOLA_H
#define BOLA_H

#include <SFML/Graphics.hpp>

class Bola: public sf::Drawable
{
public:
    Bola(float raio, float posX, float posY, sf::Color cor);
    virtual ~Bola();
    void setPosition(float x, float y);
    sf::CircleShape getCirculo();
    void updateTime();

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::CircleShape circulo;
    float raio, posX, posY;
    sf::Color cor;
    sf::Time tempo;
    sf::Clock clock;
};

#endif // BOLA_H
