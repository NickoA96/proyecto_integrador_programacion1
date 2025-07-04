
#include<iostream>
#include <string>

#include "jugar.h"
#include "utilidades.h"
#include "turno_jugador.h"
#include "estadisitica.h"
#include "lanzamiento_dados.h"
#include "mensaje_resultado.h"


using namespace std;


void jugar(string nombreJugador1, string nombreJugador2, string &mejorJugador,
            int &puntajeMax, string &nombreGanador, int &puntajeGanador, bool &existeGanador){
    const int TAM = 12;
	int puntajeJugador1=0;
	int puntajeJugador2=0;
    int vJugador1 [TAM]{};
    int vJugador2 [TAM]{};
    int numeroObjetivo;
    int dadosStockJugador1 = 6;
    int dadosStockJugador2 = 6;
	int sumaSeleccionada;
	bool victoriaAutomatica=false;


    for (int ronda= 1; ronda <= 3; ronda++){

        //jugador 1
        buscarNumeroObjetivo(numeroObjetivo, nombreJugador1);
        cargarVectorDados(vJugador1, dadosStockJugador1);
        jugarTurno(vJugador1,numeroObjetivo, dadosStockJugador1,
                   dadosStockJugador2, nombreJugador1, ronda, sumaSeleccionada,
                   puntajeJugador1,victoriaAutomatica);
        if(victoriaAutomatica==true){
            break;
        }

        //jugador 2
        buscarNumeroObjetivo(numeroObjetivo, nombreJugador2);
        cargarVectorDados(vJugador2, dadosStockJugador2);
        jugarTurno(vJugador2,numeroObjetivo, dadosStockJugador2,
                   dadosStockJugador1, nombreJugador2, ronda, sumaSeleccionada,
                   puntajeJugador2,victoriaAutomatica);
        if(victoriaAutomatica==true){
            break;
        }
	}
	resultadoFinal(nombreJugador1,nombreJugador2,puntajeJugador1,puntajeJugador2
				   ,dadosStockJugador1,dadosStockJugador2,nombreGanador, existeGanador, puntajeGanador); // --> mensaje resultado
    actualizarEstadistica(puntajeMax, mejorJugador, puntajeGanador,nombreGanador);  // --> estadistica
	pausar();
}

void cargarVectorDados(int v[], int tam){
    for (int i = 0; i< tam; i++){
        v[i] = DadoAleatorio(1, 6);
    }
}



