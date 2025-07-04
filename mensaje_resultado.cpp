
#include <iostream>

#include "mensaje_resultado.h"
#include "dibujo_lineas.h"
#include "utilidades.h"
#include "logica_turno.h"
#include "mostrar_dados.h"

using namespace std;


void mensajeResultado(int sumaSeleccionada, int numeroObjetivo, int dadosUtilizados,
					 int dadosContrincante,int dadosElegidos[], int dadosStock, bool &victoriaAutomatica, string nombreJugador, int &puntajeJugador, int &puntajeASumar){ //puntaje jugador y puntaje a sumar
	limpiarConsola();
    lineaSuperior();
    lineaTitulo();
    lineaInferior();

	if (verificarJugada(sumaSeleccionada,numeroObjetivo,dadosUtilizados,dadosStock,victoriaAutomatica)==true){
		if(victoriaAutomatica==true){
            cout << " \t\t\t " <<(char)176 <<"     MUCHAS FELICIDADES    "<< (char)176<< endl <<endl;
			cout <<" "<< (char)254 <<"  El jugador " << nombreJugador << " ha logrado una victoria automatica." << endl;
			cout <<" "<< (char)254 <<"  Utiliando todos los dados disponibles: " << dadosStock << endl;
		}
		else{
			cout << " " <<(char)254 <<"  Tirada Exitosa, "<< nombreJugador<< " resta la cantidad de: " << dadosUtilizados <<" dados de su stock." << endl;
			cout << " " <<(char)254 <<"  Suma la cantidad de: "<< puntajeASumar << " puntos." << endl;
            cout << " " <<(char)254 <<"  El nuevo puntaje es: "<< puntajeJugador << " puntos." << endl;
			cout << " " <<(char)254 <<"  Los dados utilizados fueron: " << endl;
            mostrarDados(dadosElegidos,dadosUtilizados);
		}
			lineaInferior();
	}
	else{
		if(dadosContrincante>1){
			cout << " " <<(char)254 << "  Tirada Fallida, "<< nombreJugador << " no suma puntos y agrega un dado a su stock." << endl;
			cout << " " <<(char)254 << "  El puntaje sigue siendo de: "<< puntajeJugador << " puntos." << endl;
			lineaInferior();
		}
		else{
			cout << " " <<(char)254 <<"  Tirada Fallida, no suma puntos y no agrega dado (Jugador contricante" <<endl;
			cout << "     " << "tiene solamente un dado)." << endl;
			cout << " " <<(char)254 << "  El puntaje sigue siendo de: "<< puntajeJugador << " puntos." << endl;
			lineaInferior();
		}
	}
	pausar();
	limpiarConsola();
}

void mostrarDatosPartida(int numeroObjetivo, int sumaSeleccionada, string nombreJugador, int rondaNumero, int puntajeJugador, int dadosStock ){
        limpiarConsola();
        lineaSuperior();
        cout << "\t\t\t\t Ronda " << rondaNumero << " de 3"<< endl;
        cout << " " << (char)254 << " Turno "<< nombreJugador <<endl;
        cout << " " << (char)254 << " El stock de dados es de : " << dadosStock << " dados" << endl;
        cout << " " << (char)254 << " El numero objetivo es : " << numeroObjetivo << endl;
        //cout << " " << (char)254 << " la suma es de :" << sumaSeleccionada << endl; // LINEA QUE UTILIZAMOS PARA CONTROLAR QUE CORTE BIEN
        lineaInferior();

}


void resultadoFinal(string nombreJugador1,string nombreJugador2,int puntajeJugador1, int puntajeJugador2, int dadosStockJugador1,int dadosStockJugador2,
                    string &nombreGanador, bool &existeGanador, int &puntajeGanador){
    limpiarConsola();
    lineaSuperior();
    cout << "\t\t\t\tResultado Final " << endl;
    lineaInferior();
    cout << "\t\t\t\t Jugador 1: " << endl;
    cout << " " << (char)254 <<" Nombre: " << nombreJugador1 << endl;
    cout << " " << (char)254 << " Puntaje: " << puntajeJugador1 << endl;
    lineaInferior();
    cout << "\t\t\t\t Jugador 2: " << endl;
    cout << " " << (char)254 <<  " Nombre: " << nombreJugador2 << endl;
    cout << " " << (char)254 << " Puntaje: " << puntajeJugador2 << endl;
    lineaInferior();
    lineaSuperior();

	if(puntajeJugador1!=puntajeJugador2){
        existeGanador = true;  // BANDERA PARA MOSTRAR EN ESTADISTICA UN MSJ O EL OTRO
		if(puntajeJugador1>puntajeJugador2){
			nombreGanador=nombreJugador1;
			puntajeGanador= puntajeJugador1;
		}
		else{
			nombreGanador=nombreJugador2;
			puntajeGanador= puntajeJugador2;
		}
        cout << " \t\t\t" << (char)254 <<  " El ganador fue: " << nombreGanador << endl;
	}
	else{
        cout << " \t\t\t" << (char)254 <<  " No hay ganador, empate." << endl;
	}
	    lineaInferior();
}


