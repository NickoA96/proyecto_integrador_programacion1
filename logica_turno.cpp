# include<iostream>
#include "logica_turno.h"

void procesarEleccionDado(int v[], int posicionDado, int &sumaSeleccionada, int vecDadosElegidos [], int &dadosUtilizados, int vecPosicionDadosUtilizados[]){
            sumaSeleccionada += v[posicionDado];
			vecDadosElegidos[dadosUtilizados]= v[posicionDado];   // mostrar dados
            vecPosicionDadosUtilizados[dadosUtilizados] = posicionDado; // verifcar dado usado
			dadosUtilizados++;
    }


bool verificarJugada(int sumaSeleccionada, int numeroObjetivo, int dadosUtilizados,
					 int dadosStock, bool &victoriaAutomatica){
    if (sumaSeleccionada == numeroObjetivo){ // verifica si la jugada fue exitosa
        if(dadosUtilizados==dadosStock){  // verifica si es victoriia automatica
			victoriaAutomatica=true;
		}
		return true;
    }else {
            return false;
    }
}

void dadosActualizados(int sumaSeleccionada, int numeroObjetivo, int &dadosStock, int &dadosContrincante, int dadosUtilizados, bool &victoriaAutomatica){
            if(verificarJugada(sumaSeleccionada,numeroObjetivo,dadosUtilizados,dadosStock,victoriaAutomatica) == true){
                dadosStock = dadosStock - dadosUtilizados;
                dadosContrincante += dadosUtilizados;
            }else{
                if(dadosContrincante>1){
                dadosStock ++;
                dadosContrincante --;
                }
            }
}


int puntaje(int numeroObjetivo, int dadosUtilizados,int &puntajeJugador,
			 int sumaSeleccionada, int dadosStock, bool &victoriaAutomatica, int &puntajeASumar){ // devuelve puntaje a sumar modificado

	if(verificarJugada(sumaSeleccionada,numeroObjetivo,dadosUtilizados,dadosStock,victoriaAutomatica)==true){
		if(victoriaAutomatica==true){
			puntajeASumar=10000;
			puntajeJugador+= puntajeASumar;
		}
		else{
			puntajeASumar=numeroObjetivo*dadosUtilizados;
			puntajeJugador+= puntajeASumar;
		}
        return puntajeASumar; // puntaje modificado segun si es victoria automatica o tirada exitosa
	}
	return puntajeASumar;  // 0
}


