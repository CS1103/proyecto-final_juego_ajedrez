//
// Created by divoo on 8/4/2021.
//

#ifndef CHESS_CPU_PLAYER_H
#define CHESS_CPU_PLAYER_H
#include <string>
#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Connector.hpp"
#include "ajedrez.h"
#include <deque>

using namespace std;
using namespace sf;


class cpu_player{
private:
    bool loss = false;
public:
    cpu_player(bool _loss){
        loss = _loss;
    }

    deque<pair<int,int>> posibilidadesDePeon(Peon _peonA){
        deque<pair<int,int>> where;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int x = i * 56;
                int y = j * 56;

                if (_peonA.casillaValida(x,y)){
                    where.push_back({i,j});
                }
            }
        }

        return where;
    }
    deque<pair<int,int>> posibilidadesDeTorre(Torre _torreA){
        deque<pair<int,int>> where;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int x = i * 56;
                int y = j * 56;

                if (_torreA.casillaValida(x,y)){
                    where.push_back({x,y});
                }
            }
        }
        return where;
    }
    deque<pair<int,int>> posibilidadesDeCaballo(Caballo _caballoA){
        deque<pair<int,int>> where;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int x = i * 56;
                int y = j * 56;

                if (_caballoA.casillaValida(x,y)){
                    where.push_back({i,j});
                }
            }
        }
        return where;
    }
    deque<pair<int,int>> posibilidadesDeAlfil(Alfil _alfilA){
        deque<pair<int,int>> where;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int x = i * 56;
                int y = j * 56;

                if (_alfilA.casillaValida(x,y)){
                    where.push_back({x,y});
                }
            }
        }
        return where;
    }
    deque<pair<int,int>> posibilidadesDeDama(Dama _damaA){
        deque<pair<int,int>> where;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int x = i * 56;
                int y = j * 56;

                if (_damaA.casillaValida(x,y)){
                    where.push_back({x,y});
                }
            }
        }
        return where;
    }
    deque<pair<int,int>> posibilidadesDeRey(Rey _reyA){
        deque<pair<int,int>> where;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int x = i * 56;
                int y = j * 56;

                if (_reyA.casillaValida(x,y)){
                    where.push_back({x,y});
                }
            }
        }
        return where;
    }

};



#endif //CHESS_CPU_PLAYER_H
