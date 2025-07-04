#include <iostream>
#include "estadisitica.h"
#include "dibujo_lineas.h"

using namespace std;

void mensajeEstadistica(bool existeGanador, string mejorJugador, int puntajeMax){
        lineaSuperior();
        lineaTitulo();
        lineaInferior();
    if(existeGanador == true){ // bandera que es modificada en la fn resultadoFinal (mensaje_resultado)
        cout << "      El jugador con mayor puntaje fue "<< mejorJugador << " con un total de: " << puntajeMax << " puntos." << endl;
	    lineaInferior();
        cout << endl;
	}else{
        cout << "                       No se registraron jugadas aun.                    "<< endl;
        lineaInferior();
        cout << endl;
	}
}


void actualizarEstadistica( int &puntajeMax, string &mejorJugador, int puntajeGanador, string nombreGanador){ // SIEMPRE SE ACTUALIZA PERO SOLAMENTE SE MUESTRA
        if (puntajeMax == 0){                                                                                   // UNA VEZ LA BANDERA ES CAMBIADA TRUE
            mejorJugador = nombreGanador;
            puntajeMax = puntajeGanador;
        }else if(puntajeGanador > puntajeMax){
            mejorJugador = nombreGanador;
            puntajeMax = puntajeGanador;
        }
}
