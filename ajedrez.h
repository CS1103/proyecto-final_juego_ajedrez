#ifndef AJEDREZ_H
#define AJEDREZ_H

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Jugador{
    private:
        string nombre;
        bool blancas;
        bool negras;
        bool turno;
    public:
        Jugador(string, bool, bool, bool);
        ~Jugador();
};

Jugador::Jugador(string nombre, bool blancas, bool negras, bool turno) 
                : nombre(nombre), blancas(blancas), negras(negras), turno(turno) {
};

Jugador::~Jugador() {
};


class Pieza{

    protected:
        pair<int, int> position;
        pair<int, int> next_position;
        bool blanca;
        bool negra;
        bool selected;
        bool movido;
    public:
        Pieza(pair<int, int>, pair<int, int>, bool, bool, bool);
        ~Pieza();
        virtual void move(pair<int, int>, pair<int, int>, bool);
    
};

Pieza::Pieza(pair<int, int> position, pair<int, int> next_position, bool blanca, bool negra, bool selected) 
            : position(position), next_position(next_position), blanca(blanca), negra(negra), selected(selected) {

};

Pieza::~Pieza() {
};

void Pieza::move(pair<int, int> position, pair<int, int> next_position, bool movido) {
    this->position;
    this->movido;
    position = next_position;
    movido = 1;
};

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);

        return h1 ^ h2;  
    }
};


/*
class Tablero{
    private:

};

*/

unordered_map <pair<int,int>,Pieza*> tablero;


class Peon : public Pieza{

    private:
        bool movido;

    public:
        Peon(pair<int, int>, pair<int, int>, bool, bool, bool);
        ~Peon();
        bool movimiento_permitido_peon();
        //void move(pair<int, int>, pair<int, int>, bool); 

};


Peon::Peon(pair<int, int> position, pair<int, int> next_position, bool blanca, bool negra, bool selected) 
            : Pieza(position, next_position, blanca, negra, selected) {

};

Peon::~Peon() {
};

bool Peon::movimiento_permitido_peon(){

    if(next_position.first == position.first + 2 && !movido) { //&& next_position empty
        return true;
    }
    else if(next_position.first == position.first + 1) { //&& next_position empty
        return true;
    }
    else {
        return false;
    } 
};

/*
void Peon::move(pair<int, int> position, pair<int, int> next_position, bool) {
    this->position;
    position = next_position;
    movido = 1;
};
*/

class Alfil : public Pieza{

    public:
        Alfil(pair<int, int>, pair<int, int>, bool, bool, bool);
        ~Alfil();
        void movimiento_permitido_alfil();

};

Alfil::Alfil(pair<int, int> position, pair<int, int> next_position, bool blanca, bool negra, bool selected) 
            : Pieza(position, next_position, blanca, negra, selected) {

};

Alfil::~Alfil() {
};




class Caballo : public Pieza{

    public:
        Caballo(pair<int, int>, pair<int, int>, bool, bool, bool);
        ~Caballo();
    
};

Caballo::Caballo(pair<int, int> position, pair<int, int> next_position, bool blanca, bool negra, bool selected) 
            : Pieza(position, next_position, blanca, negra, selected) {

};

Caballo::~Caballo() {
};

class Torre : public Pieza{

    public:
        Torre(pair<int, int>, pair<int, int>, bool, bool, bool);
        ~Torre();
    
};

Torre::Torre(pair<int, int> position, pair<int, int> next_position, bool blanca, bool negra, bool selected) 
            : Pieza(position, next_position, blanca, negra, selected) {

};

Torre::~Torre() {
};


class Dama : public Pieza{

    public:
        Dama(pair<int, int>, pair<int, int>, bool, bool, bool);
        ~Dama();
    
};

Dama::Dama(pair<int, int> position, pair<int, int> next_position, bool blanca, bool negra, bool selected) 
            : Pieza(position, next_position, blanca, negra, selected) {

};

Dama::~Dama() {
};

class Rey : public Pieza{

    public:
        Rey(pair<int, int>, pair<int, int>, bool, bool, bool);
        ~Rey();
    
};

Rey::Rey(pair<int, int> position, pair<int, int> next_position, bool blanca, bool negra, bool selected) 
            : Pieza(position, next_position, blanca, negra, selected) {

};
Rey::~Rey() {
};

#endif