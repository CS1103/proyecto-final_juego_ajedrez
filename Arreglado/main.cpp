#include "ajedrez.h"

int main(){

    //Definir jugadores
    string jugador_blancas_nombre;
    string jugador_negras_nombre;

    cout << "Introduzca el nombre del jugador de las piezas blancas: " << endl;
    cin >> jugador_blancas_nombre;

    cout << "Introduzca el nombre del jugador de las piezas negras: " << endl;
    cin >> jugador_blancas_nombre;

    Jugador jugador_blancas = Jugador(jugador_blancas_nombre, "Blanco");
    Jugador jugador_negras = Jugador(jugador_negras_nombre, "Negro");

    //Crear partida
    Ajedrez partida;

    partida.IniciarJuego();

    return 0;
}
