#include <iostream>
#include "estadisitica.h"
#include "dibujo_lineas.h"

using namespace std;

void mensajeEstadistica(bool existeGanador, string mejorJugador, int puntajeMax){
        lineaSuperior();
        lineaTitulo();
        lineaInferior();
    if(existeGanador == true){ // bandera que es modificada en resultado final (mensaje_resultado.cpp)
        cout << "      El jugador con mayor puntaje fue "<< mejorJugador << " con un total de: " << puntajeMax << " puntos." << endl;
	    lineaInferior();
        cout << endl;
	}else{
        cout << "                       No se registraron jugadas aun.                    "<< endl;
        lineaInferior();
        cout << endl;
	}
}


void actualizarEstadistica( int &puntajeMax, string &mejorJugador, int puntajeGanador, string nombreGanador){
        if (puntajeMax == 0){ // si el puntaje max es 0
            mejorJugador = nombreGanador;
            puntajeMax = puntajeGanador;
        }else if(puntajeGanador > puntajeMax){
            mejorJugador = nombreGanador;
            puntajeMax = puntajeGanador;
        }

}
