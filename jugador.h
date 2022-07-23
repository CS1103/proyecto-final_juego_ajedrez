//
// Created by divoo on 8/5/2021.
//

#ifndef CHESS_JUGADOR_H
#define CHESS_JUGADOR_H

#include <string>
#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Connector.hpp"

using namespace std;
using namespace sf;

class jugador {
private:
    int puntaje = 0;
public:
    jugador(int puntaje) : puntaje(puntaje) {}

    void increace(int _puntaje){
        puntaje = _puntaje;
    }
    int getPuntaje(){
        return puntaje;
    }
};


#endif //CHESS_JUGADOR_H
