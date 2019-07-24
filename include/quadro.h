#ifndef QUADRO_H
#define QUADRO_H

#include <vector>
#include "bola.h"

using namespace std;

class Quadro: public sf::Drawable
{
public:
    Quadro();
    ~Quadro();

    void adicionarBola(Bola* bola);
    int getQuantBolas();
    void updatePos();

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Bola** arrayBolas;
    int quantBolas;
};

#endif // QUADRO_H
