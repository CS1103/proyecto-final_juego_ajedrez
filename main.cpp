#include "ajedrez.h"

int main(){
    
    //Definir jugadores
    string jugador_blancas_nombre;
    string jugador_negras_nombre;

    cout << "Introduzca el nombre del jugador de las piezas blancas: " << endl;
    cin >> jugador_blancas_nombre;

    cout << "Introduzca el nombre del jugador de las piezas negras: " << endl;
    cin >> jugador_blancas_nombre;

    Jugador jugador_blancas = Jugador(jugador_blancas_nombre, 1, 0, 1);
    Jugador jugador_negras = Jugador(jugador_negras_nombre, 0, 1, 0);


    //Definir piezas
    Peon peon_blanco_1 = Peon({1,0}, {1,0}, 1, 0, 0);
    Peon peon_blanco_2 = Peon({1,1}, {1,1}, 1, 0, 0);
    Peon peon_blanco_3 = Peon({1,2}, {1,2}, 1, 0, 0);
    Peon peon_blanco_4 = Peon({1,3}, {1,3}, 1, 0, 0);
    Peon peon_blanco_5 = Peon({1,4}, {1,4}, 1, 0, 0);
    Peon peon_blanco_6 = Peon({1,5}, {1,5}, 1, 0, 0);
    Peon peon_blanco_7 = Peon({1,6}, {1,6}, 1, 0, 0);
    Peon peon_blanco_8 = Peon({1,7}, {1,7}, 1, 0, 0);

    Peon peon_negro_1 = Peon({6,0}, {6,0}, 0, 1, 0);
    Peon peon_negro_2 = Peon({6,1}, {6,1}, 0, 1, 0);
    Peon peon_negro_3 = Peon({6,2}, {6,2}, 0, 1, 0);
    Peon peon_negro_4 = Peon({6,3}, {6,3}, 0, 1, 0);
    Peon peon_negro_5 = Peon({6,4}, {6,4}, 0, 1, 0);
    Peon peon_negro_6 = Peon({6,5}, {6,5}, 0, 1, 0);
    Peon peon_negro_7 = Peon({6,6}, {6,6}, 0, 1, 0);
    Peon peon_negro_8 = Peon({6,7}, {6,7}, 0, 1, 0);

    Caballo caballo_blanco_1 = Caballo({0,1}, {0,1}, 1, 0, 0);
    Caballo caballo_blanco_2 = Caballo({0,7}, {0,7}, 1, 0, 0);

    Caballo caballo_negro_1 = Caballo({7,1}, {7,1}, 0, 1, 0);
    Caballo caballo_negro_2 = Caballo({7,7}, {7,7}, 0, 1, 0);

    Alfil alfil_blanco_casillas_negras = Alfil({0,2}, {0,2}, 1, 0, 0);
    Alfil alfil_blanco_casillas_blancas = Alfil({0,6}, {0,6}, 1, 0, 0);

    Alfil alfil_negro_casillas_blancas = Alfil({7,1}, {7,1}, 0, 1, 0);
    Alfil alfil_negro_casillas_negras = Alfil({7,6}, {7,6}, 0, 1, 0);

    Torre torre_blanca_1 = Torre({0,0}, {0,0}, 1, 0, 0);
    Torre torre_blanca_2 = Torre({0,8}, {0,8}, 1, 0, 0);

    Torre torre_negra_1 = Torre({7,0}, {7,0}, 0, 1, 0);
    Torre torre_negra_2 = Torre({7,8}, {7,8}, 0, 1, 0);

    Dama dama_blanca = Dama({0,3}, {0,3}, 1, 0, 0);

    Dama dama_negra = Dama({7,3}, {7,3}, 0, 1, 0);

    Rey rey_blanco = Rey({0,4}, {0,4}, 1, 0, 0);
    
    Rey rey_negro = Rey({7,4}, {7,4}, 0, 1, 0);

    return 0;
}
