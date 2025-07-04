
#include <iostream>
#include "mostrar_dados.h"
#include "dibujo_dados.h"
using namespace std;


void mostrarDados (int v[],int tam){
		dibujarDadoSuperior(v,tam);
		cout << endl;
        dibujarDadoLineaMedia(v, tam);
        dibujarDadoInferior(v, tam);
		cout << endl;
		mostrarIndiceDado(v, tam);
		cout << endl;
	}


void mostrarIndiceDado(int v[] , int tam){
    for (int i = 0; i < tam; i++) {
        cout <<"   "<< i+1  << " \t";
		}
}

