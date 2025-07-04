#include <iostream>
#include "lanzamiento_dados.h"
#include "utilidades.h"
#include "dibujo_lineas.h"
#include "dibujo_dados.h"
#include "mostrar_dados.h"
using namespace std;



int DadoAleatorio(int inicio, int fin){
    int dado;
    dado = rand() % (fin-inicio +1)+inicio;
    return dado;
}


void tirarDadosEmpezar(int &numeroJugador1, int &numeroJugador2, string nombreJugador1, string nombreJugador2){
    numeroJugador1 = DadoAleatorio(1,6);
    numeroJugador2 = DadoAleatorio(1,6);
    limpiarConsola();

    lineaSuperior();
    cout  << "\t\t\t\t Quien empieza?  " << endl;
    lineaInferior();

    cout <<(char)254 <<" " << nombreJugador1 << " tira: " << endl;
    dadoUnicoSuperior();
    dadoUnicoMedio(numeroJugador1);
    dadoUnicoInferior();

    cout <<(char)254 <<" " << nombreJugador2 << " tira: " << endl;
    dadoUnicoSuperior();
    dadoUnicoMedio(numeroJugador2);
    dadoUnicoInferior();

}

void buscarNumeroObjetivo(int &numeroObjetivo, string nombreJugador){
    numeroObjetivo = 0;
    const int TAM = 2;
    int v[TAM]{};
    for (int i = 0; i< TAM; i++){
        v[i]= DadoAleatorio(1,12);
        numeroObjetivo += v[i];
    }
    limpiarConsola();
    lineaSuperior();
    cout  << "\t\t\t\t Numero Objetivo  " << endl;
    lineaInferior();
    cout << " " <<(char)254 << " " << nombreJugador << " tira 2 dados de 12 caras en busca del numero objetivo: " << endl;
    mostrarDados(v, TAM);
    lineaInferior();
    lineaSuperior();
    cout << " " << (char)254 << " El numero objetivo de "<< nombreJugador << " obtenido es: " << numeroObjetivo << endl;
    lineaInferior();
    pausar();

}

