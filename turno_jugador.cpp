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
        if (terminarTurno(posicionDado, banderaTerminarTurno) == true){
                if (banderaTerminarTurno == true){
                    break;
                }else{
                    continue;              // reinicia
                }
            }

        //resta uno al dado elegido
        posicionDado--;


        if (dadoUsado(dadosUtilizados,vecPosicionDadosUtilizados, posicionDado) == true){continue;}

        procesarEleccionDado(v, posicionDado, sumaSeleccionada, vecDadosElegidos, dadosUtilizados, vecPosicionDadosUtilizados); // procesa el dado

        if(numeroObjetivo == sumaSeleccionada){break;}

        if (dadosUtilizados == dadosStock){break;}


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
            banderaTerminarTurno = true;
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

