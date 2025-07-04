# include<iostream>
#include <string>
#include "turno_jugador.h"
#include "utilidades.h"
#include "logica_turno.h"
#include "mostrar_dados.h"
#include "dibujo_lineas.h"
#include "mensaje_resultado.h"




using namespace std;

void jugarTurno(int v[], int numeroObjetivo, int &dadosStock,
				int &dadosContrincante, string nombreJugador, int rondaNumero,
				int &sumaSeleccionada, int &puntajeJugador, bool &victoriaAutomatica){
    sumaSeleccionada = 0;
    int dadosUtilizados=0;
    int puntajeASumar=0;
	const int TAM = 12;
	int vecDadosElegidos[TAM]{};
	int vecPosicionDadosUtilizados[TAM]{};


    while (numeroObjetivo > sumaSeleccionada) { // --> modificar a true, y en ese caso corta solamente cuando el jugador quiere o se queda sin dados
        bool banderaTerminarTurno = false;
        mostrarDatosPartida(numeroObjetivo, sumaSeleccionada, nombreJugador, rondaNumero, puntajeJugador, dadosStock);
        int posicionDado = dadoElegido(v,dadosStock);


        // verifica si el jugador quiere terminar el turno
        if (terminarTurno(posicionDado, banderaTerminarTurno) == true){ // 0 -- true | != 0 false
                if (banderaTerminarTurno){  // verifica si la bandera es true
                    break;                  // en caso de que la bandera sea true, termina el turno
                }else{
                    continue;              // en caso de que la bandera sea false, reinicia para volver a pedir un dado
                }
            }

        //actualizamos el dado para poder utilizarlo en el array
        posicionDado--;


        if (dadoUsado(dadosUtilizados,vecPosicionDadosUtilizados, posicionDado) == true){continue;} // en caso de true saltea el resto del codigo y vuelve al principio del bucle

        procesarEleccionDado(v, posicionDado, sumaSeleccionada, vecDadosElegidos, dadosUtilizados, vecPosicionDadosUtilizados); // procesa el dado

        if(numeroObjetivo == sumaSeleccionada){break;} // corta el turno

        if (dadosUtilizados == dadosStock){break;} // corta el turno


    limpiarConsola();
    }
	puntaje(numeroObjetivo,dadosUtilizados,puntajeJugador,sumaSeleccionada,dadosStock,victoriaAutomatica, puntajeASumar); // modifica  puntaje a sumar
	mensajeResultado(sumaSeleccionada,numeroObjetivo,dadosUtilizados,
					 dadosContrincante,vecDadosElegidos,dadosStock,victoriaAutomatica, nombreJugador, puntajeJugador, puntajeASumar); // muestra el resultado del turno
	dadosActualizados(sumaSeleccionada,numeroObjetivo,dadosStock,dadosContrincante,dadosUtilizados,victoriaAutomatica); // actualiza dados del jugador y contrincante
}




int dadoElegido(int v[], int tam){
    int dado;
    cout <<"\t\t\t\t Tirada de dados stock" << endl;
    mostrarDados(v, tam);
    lineaInferior();
    cout << endl;
    cout <<" " <<(char)254 << " Seleccione un dado de la tirada (0 para terminar): ";
    cin >> dado;
    return dado;
}


bool terminarTurno(int dado, bool &banderaTerminarTurno){
    int seleccion;
    if(dado == 0){
        cout <<" " <<(char)254 << " Esta seguro que desea terminar el turno? (0 -SI /1 - NO) : ";
        cin >> seleccion;
        if(seleccion == 0){
            banderaTerminarTurno = true;  // --- en caso de que el jugador ponga 2 veces 0, o sea confirma que quiere terminar el turno
            return true;
        }else{
            return true; // en caso de que el jugador ponga 0 pero despues se arepiente, entonces puede volver a elegir un dado
        }
    }
    return false;  // en caso de que no ponga 0
}




bool dadoUsado(int dadosUtilizados ,int posicionDadosUtilizados[] ,int dadoElegido){
    for (int i =0; i< dadosUtilizados; i++){
            if(dadoElegido == posicionDadosUtilizados[i]){
                cout <<" " <<(char)254 << " Usted ya utilizo este dado, elija otro" << endl;
                pausar();
                return true;
            }
        }
        return false;
}

