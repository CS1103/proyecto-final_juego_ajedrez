#ifndef AJEDREZ_H
#define AJEDREZ_H

#include <string>
#include <iostream>

using namespace std;

class Pieza{
        
    public:
        string color;
        Pieza(string color) : color(color) {

        }

        ~Pieza();
    
};

class Peon : public Pieza{

    public:

        Peon(string color) : Pieza(color) {

        };
        ~Peon();

};


class Rey : public Pieza{

    public:

        Rey(string color) : Pieza(color) {

        };
        ~Rey(){};    
};



class Alfil : public Pieza{

    public:

        Alfil(string color) : Pieza(color) {

        };
        ~Alfil();

};

class Caballo : public Pieza{

    public:

        Caballo(string color) : Pieza(color) {

        };
        ~Caballo();

};

class Torre : public Pieza{

    public:

        Torre(string color) : Pieza(color) {
            
        };
        ~Torre();

};

class Dama : public Pieza{

    public:

        Dama(string color) : Pieza(color) {
            
        };
        ~Dama();

};

class Ajedrez{
    private:
        string turno_color;
    public:
        Ajedrez() : turno_color("Blanco"){

        }

        void IniciarJuego(){
            do {
                MovimientoRealizado();
                CambiarTurnos();
                //Imprimir SFML
            }while(!JuegoTerminado());
        }

        void CambiarTurnos() {

            if(turno_color == "Blanco") {
                turno_color == "Negro";
            }else if(turno_color == "Negro") {
                turno_color == "Blanco";
            }
        }

        void MovimientoRealizado() {

            bool movimientoValido;

            do{
                //moverPiezas
            }while(!movimientoValido);
            
        };

        bool JuegoTerminado() {
            //if jaqueMate || Ahogado
            // return true
        }

};

class Jugador{
    private:
        string nombre;
        string color;
    public:
        Jugador(string, string);
        ~Jugador();
};

Jugador::Jugador(string nombre, string color) 
                : nombre(nombre), color(color){
};

Jugador::~Jugador() {
};

class Tablero {
        
    public:

        

        Tablero(){

            Pieza* tablero[8][8];


            for(size_t i=0; i<8; i++) {
                for(size_t j=0; j<8; j++) {
                    tablero[i][j] = nullptr;
                }
            }

            //Piezas blancas
            for(size_t j=0; j<8; j++) {
            tablero[1][j] = new Peon("Blanco");
            }

            tablero[0][0] = new Torre("Blanco");
            tablero[0][1] = new Caballo("Blanco");
            tablero[0][2] = new Alfil("Blanco");
            tablero[0][3] = new Dama("Blanco");
            tablero[0][4] = new Rey("Blanco");
            tablero[0][5] = new Alfil("Blanco");
            tablero[0][6] = new Caballo("Blanco");
            tablero[0][7] = new Torre("Blanco");

            //Piezas negras
            for(size_t j=0; j<8; j++) {
            tablero[6][j] = new Peon("Negro");
            }

            tablero[7][0] = new Torre("Negro");
            tablero[7][1] = new Caballo("Negro");
            tablero[7][2] = new Alfil("Negro");
            tablero[7][3] = new Dama("Negro");
            tablero[7][4] = new Rey("Negro");
            tablero[7][5] = new Alfil("Negro");
            tablero[7][6] = new Caballo("Negro");
            tablero[7][7] = new Torre("Negro");

        }

        ~Tablero(){
        }
};





#endif