#include "include/quadro.h"
#include <iostream>

using namespace std;

Quadro::Quadro(){
    arrayBolas = new Bola* [100];
    quantBolas = 0;
}

Quadro::~Quadro(){

    for (int i = 0; i < quantBolas; i++){
        delete arrayBolas[i];
    }

    delete arrayBolas;
}

void Quadro::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    for (int i = 0; i < quantBolas; i++){

        target.draw(*arrayBolas[i]);
    }
}


int Quadro::getQuantBolas(){
    return quantBolas;
}

void Quadro::adicionarBola(Bola* bola){

    if(getQuantBolas() < 100){

        arrayBolas[quantBolas] = bola;

        quantBolas++;
    }
}

void Quadro::updatePos(){

    for(int i = 0; i < quantBolas; i++){

        arrayBolas[i]->updateTime();

    }
}





