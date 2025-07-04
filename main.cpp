#include <iostream>
#include <ctime>
#include <string>


#include "menu.h"
#include "definir_inicio.h"
#include "jugar.h"
#include "estadisitica.h"
#include "creditos.h"
#include "nombre_jugadores.h"
#include "utilidades.h"


using namespace std;


int main(){
    srand(time(0));
    int confirmacion=1;
    int opcion;
    string nombreJugador1;
    string nombreJugador2;
	string mejorJugador;
	int puntajeMax=0;
	string nombreGanador;
	int puntajeGanador = 0;
	bool existeGanador = false;

    do{
    menu(opcion);


    switch(opcion){

        case 1:
            limpiarConsola();
            pedirNombre(nombreJugador1, nombreJugador2);
            quienEmpieza(nombreJugador1, nombreJugador2);
            jugar(nombreJugador1, nombreJugador2, mejorJugador, puntajeMax, nombreGanador, puntajeGanador, existeGanador);
            limpiarConsola();
            break;
        case 2:
			limpiarConsola();
            mensajeEstadistica(existeGanador, mejorJugador, puntajeMax);
            pausar();
			limpiarConsola();
            break;
        case 3:
            limpiarConsola();
            creditos();
            pausar();
			limpiarConsola();
            break;
        case 0:
            confirmacionSalida(confirmacion);
            break;
    }

    } while(confirmacion !=0);


}


