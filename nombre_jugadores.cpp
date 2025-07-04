
# include<iostream>
#include "nombre_jugadores.h"
#include "dibujo_lineas.h"

using namespace std;


void pedirNombre(string &nombreJugador1, string &nombreJugador2){
    lineaSuperior();
    cout << "\t\t\t Ingresar el nombre de los jugadores" << endl;
    lineaInferior();

    cout <<" " <<(char)254 << " Ingrese el nombre del primer participante: ";
    cin >> nombreJugador1;
    cout <<" " <<(char)254 << " Ingrese el nombre del segundo participante: ";
    cin >> nombreJugador2;

}
