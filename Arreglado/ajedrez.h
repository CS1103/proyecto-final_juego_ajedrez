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
        
        bool CasillaPermitida(int columna_actual, int fila_actual,
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
            //if EnJaque || Ahogado
            // return true
            //else return false
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