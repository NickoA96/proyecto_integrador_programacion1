
#include <iostream>
#include <string>

#include "definir_inicio.h"
#include "lanzamiento_dados.h"
#include "dibujo_lineas.h"
#include "utilidades.h"

using namespace std;


void quienEmpieza(string &nombreJugador1, string &nombreJugador2){
    int numeroJugador1;
    int numeroJugador2;
    string guardarNombre;
    tirarDadosEmpezar(numeroJugador1,numeroJugador2,nombreJugador1,nombreJugador2 );
    while (numeroJugador1 == numeroJugador2){
        lineaSuperior();
        cout << "                                 Empate" << endl;
        lineaInferior();
        pausar();
        limpiarConsola();
        tirarDadosEmpezar( numeroJugador1,  numeroJugador2,nombreJugador1,nombreJugador2 );
    }

    if (numeroJugador1 < numeroJugador2){
        guardarNombre = nombreJugador1;
        nombreJugador1 = nombreJugador2;
        nombreJugador2 = guardarNombre;
        }
        lineaSuperior();
        cout << "                                Empieza " << nombreJugador1  << endl;
        lineaInferior();
        pausar();
}
