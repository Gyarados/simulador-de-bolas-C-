#include "include/bola.h"
#include <iostream>

using namespace std;

Bola::Bola(float raio, float posX, float posY, sf::Color cor): raio(raio), posX(posX), posY(posY), cor(cor){
    circulo.setRadius(raio);
    circulo.setFillColor(cor);
    circulo.setOutlineColor(cor);
    circulo.setOutlineThickness(1);
    circulo.setPosition(posX, posY);

    sf::Clock clock;
    tempo = clock.getElapsedTime();
}

Bola::~Bola(){

}

void Bola::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    target.draw(circulo);

}

void Bola::setPosition(float x, float y){
    circulo.setPosition(x, y);
}

sf::CircleShape Bola::getCirculo(){
    return circulo;
}

void Bola::updateTime(){
    tempo = clock.getElapsedTime();
    float deslocV = (tempo.asSeconds()*tempo.asSeconds()*5);
    circulo.setPosition(circulo.getPosition().x , circulo.getPosition().y + deslocV);


}



