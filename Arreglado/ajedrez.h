#ifndef AJEDREZ_H
#define AJEDREZ_H

#include <string>
#include <iostream>

using namespace std;
//[columna][fila]

class Pieza{
        
    public:
        string color;

        Pieza(string color) : color(color) {

        }
        
        bool MovimientoLegal(int columna_actual, int fila_actual,
                              int columna_destino, int fila_destino, Pieza* tablero[8][8]){

            Pieza* casillaDestino = tablero[columna_destino][fila_destino];

            //Verificar si casilla destino esta vacia, si la ocupa una pieza de otro color, o si actual y destino son distintas
            if(casillaDestino == nullptr || color != casillaDestino->color || (columna_destino != columna_actual && fila_destino != fila_actual) ) {
                
                //Verificar si la pieza puede moverse de esa manera
                return MovimientoPermitido(columna_actual, fila_actual, columna_destino, fila_destino, tablero);
            }
            else {
                return false;
            }

        }

        virtual bool MovimientoPermitido(int columna_actual, int fila_actual, 
                                         int columna_destino, int fila_destino, Pieza* tablero[8][8]) = 0;

        ~Pieza();
    
};

class Peon : public Pieza{

    private:

        bool movido = false;;

    public:

        Peon(string color) : Pieza(color) {

        };

        bool MovimientoPermitido(int columna_actual, int fila_actual, 
                                 int columna_destino, int fila_destino, Pieza* tablero[8][8]) {

            Pieza* casillaDestino = tablero[columna_destino][fila_destino];

            //Verificar si casilla de destino esta vacia
            if(casillaDestino == nullptr) {
                if(color == "Blanco") {
                    //Verificar si peon se ha movido previamente, sino podra moverse 2 casillas
                    if(!movido) {
                        
                        if(columna_actual + 1 == columna_destino  || (columna_actual + 2 == columna_destino && tablero[columna_actual+1][fila_actual] == nullptr)) {
                            return true;
                        } else {
                            return false;
                        }

                        movido = true;
                    //Si ya se ha movido, solo podra moverse una casilla hacia adelante    
                    } else if(movido) {
                        if(columna_actual + 1 == columna_destino ) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                    //De la misma forma para las negras pero en el sentido opuesto de las columnas
                } 
                else if(color == "Negro") {
                    if(!movido) {
                        if(columna_actual - 1 == columna_destino  || (columna_actual - 2 == columna_destino && tablero[columna_actual+1][fila_actual] == nullptr) ) {
                            return true;
                        } else {
                            return false;
                        }

                        movido = true;
                    } else if(movido) {
                        if(columna_actual + 1 == columna_destino ) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                }

            } else if(color == "Blanco"){ 
                //Verificar si el movimiento diagonal es el adecuado
                if(columna_actual + 1 == columna_destino && fila_actual + 1 == fila_destino 
                || columna_actual + 1 == columna_destino && fila_actual - 1 == fila_destino ) {
                    //Come pieza en esa posicion
                    return true;
                } else {
                    return false;
                }
            } else if(color == "Negro") {
                //Igual pero para las negras
                if(columna_actual -1 == columna_destino && fila_actual + 1 == fila_destino 
                || columna_actual -1 == columna_destino && fila_actual - 1 == fila_destino ) {
                    //Come pieza en esa posicion
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }

        };

        ~Peon();

};

class Caballo : public Pieza{

    public:

        Caballo(string color) : Pieza(color) {

        };
        bool MovimientoPermitido(int columna_actual, int fila_actual, 
                                 int columna_destino, int fila_destino, Pieza* tablero[8][8]) {

            if(columna_actual + 1 == columna_destino || columna_actual - 1 == columna_destino) {
                if(fila_actual + 2 == fila_destino || fila_actual - 2 == fila_destino) {
                    //Si hay pieza, come en esa posicion
                    return true;
                }

            } else if(columna_actual + 2 == columna_destino || columna_actual - 2 == columna_destino) {
                if(fila_actual + 1 == fila_destino || fila_actual - 1 == fila_destino) {
                    //Si hay pieza, come en esa posicion
                    return true;
                }
                
            } else {
                return false;
            }

        };

        ~Caballo();

};


class Alfil : public Pieza{

    public:

        Alfil(string color) : Pieza(color) {

        };
        bool MovimientoPermitido(int columna_actual, int fila_actual, 
                                 int columna_destino, int fila_destino, Pieza* tablero[8][8]) {

            bool camino_despejado = true;                         

            for(int i=columna_actual, j=fila_actual; i<columna_destino && j<fila_destino; i++, j++) {
                if (tablero[i][j] != nullptr) {
					    camino_despejado = false;
                    }
            }                

            return camino_despejado;                 

        };
        ~Alfil();

};



class Torre : public Pieza{

    public:

        Torre(string color) : Pieza(color) {
            
        };
        bool MovimientoPermitido(int columna_actual, int fila_actual, 
                                 int columna_destino, int fila_destino, Pieza* tablero[8][8]) {

            bool camino_despejado = true;                         

            if(columna_actual == columna_destino) {
                for(int j = fila_actual; j < fila_destino; j++) {
                    if (tablero[columna_actual][j] != nullptr) {
					    camino_despejado = false;
                    }
				}
                
            }else if(fila_actual == fila_destino)   {
                for(int i = columna_actual; i < columna_destino; i++) {
                    if (tablero[i][fila_actual] != nullptr) {
					    camino_despejado = false;
                    }
				}
            }

            return camino_despejado;                   

        };
        ~Torre();

};

class Dama : public Pieza{

    public:

        Dama(string color) : Pieza(color) {
            
        };
        bool MovimientoPermitido(int columna_actual, int fila_actual, 
                                 int columna_destino, int fila_destino, Pieza* tablero[8][8]) {

            bool camino_despejado = true;                         

            if(columna_actual == columna_destino) {
                for(int j = fila_actual; j < fila_destino; j++) {
                    if (tablero[columna_actual][j] != nullptr) {
					    camino_despejado = false;
                    }
				}
                
            }else if(fila_actual == fila_destino)   {
                for(int i = columna_actual; i < columna_destino; i++) {
                    if (tablero[i][fila_actual] != nullptr) {
					    camino_despejado = false;
                    }
				}
            }else{
                for(int i=columna_actual, j=fila_actual; i<columna_destino && j<fila_destino; i++, j++) {
                    if (tablero[i][j] != nullptr) {
                            camino_despejado = false;
                        }
            }      


            }

            return camino_despejado;                             

        };
        ~Dama();

};

class Rey : public Pieza{

    public:

        Rey(string color) : Pieza(color) {

        };
        bool MovimientoPermitido(int columna_actual, int fila_actual, 
                                 int columna_destino, int fila_destino, Pieza* tablero[8][8]) {

            if(columna_actual + 1 == columna_destino || columna_actual - 1 == columna_destino) {
                if(fila_actual -1 == fila_destino
                || fila_actual == fila_destino
                || fila_actual + 1 == fila_destino) {
                    //if(!EsJaque)
                    //Si hay pieza, come en esa posicion
                    return true;
                }
            }else if(columna_actual == columna_destino) {
                if(fila_actual -1 == fila_destino
                || fila_actual + 1 == fila_destino) {
                    //if(!EsJaque)
                    //Si hay pieza, come en esa posicion
                    return true;
                }
            }else {
                return false;
            }

        };
        

        ~Rey(){};    
};


class Tablero {
        
    public:
        Pieza* tablero[8][8];

        Tablero(){


            for(size_t i=0; i<8; i++) {
                for(size_t j=0; j<8; j++) {
                    tablero[i][j] = nullptr;
                }
            }

            //Piezas blancas
            for(size_t j=0; j<8; j++) {
            tablero[j][1] = new Peon("Blanco");
            }

            tablero[0][0] = new Torre("Blanco");
            tablero[1][0] = new Caballo("Blanco");
            tablero[2][0] = new Alfil("Blanco");
            tablero[3][0] = new Dama("Blanco");
            tablero[4][0] = new Rey("Blanco");
            tablero[5][0] = new Alfil("Blanco");
            tablero[6][0] = new Caballo("Blanco");
            tablero[7][0] = new Torre("Blanco");

            //Piezas negras
            for(size_t j=0; j<8; j++) {
            tablero[j][6] = new Peon("Negro");
            }

            tablero[0][7] = new Torre("Negro");
            tablero[1][7] = new Caballo("Negro");
            tablero[2][7] = new Alfil("Negro");
            tablero[3][7] = new Dama("Negro");
            tablero[4][7] = new Rey("Negro");
            tablero[5][7] = new Alfil("Negro");
            tablero[7][7] = new Caballo("Negro");
            tablero[7][7] = new Torre("Negro");

        }

        ~Tablero(){
        }
};


class Ajedrez{
    private:
        Tablero tablero_actual;
        string turno_color;
    public:
        Ajedrez() : turno_color("Blanco"){

        }

        void IniciarJuego(){
            do {
                MovimientoRealizado(tablero_actual.tablero);
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

        void MovimientoRealizado(Pieza* tablero[8][8]) {

            bool movimientoValido;

            do{

                //Input
                int columna_actual;
                int fila_actual;

                int columna_destino;
                int fila_destino;
                //

                movimientoValido = false;

                Pieza* pieza_actual = tablero[columna_actual][fila_actual];
                

                if(pieza_actual->MovimientoLegal(columna_actual, fila_actual, columna_destino, fila_destino, tablero)) {
                    //Movimiento de piezas
                    movimientoValido = true;
                }

            }while(!movimientoValido);
            
        };

        bool JuegoTerminado() {
            //if EnJaque || Ahogado
            // return true
            //else
            return false;
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



#endif