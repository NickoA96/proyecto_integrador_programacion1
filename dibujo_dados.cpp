#include <iostream>
#include "dibujo_dados.h"
using namespace std;




void dibujarDadoSuperior(int v[], int tam){
    for(int i = 0; i< tam; i++){
        for(int j = 0; j<6; j++){
            if(j == 0){
                cout << (char)201;
            }else if (j == 5){
                cout << (char)187;
            }else{
                cout << (char)205;
            }
        }
            cout << "\t";
    }
}


void dibujarDadoLineaMedia(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << (char)186; // ║
        if (v[i] < 10) {
            cout << "  " << v[i] << " "; // Para números de 1 dígito
        } else {
            cout <<" "<< v[i] << " "; // Para números de 2 dígitos (queda un poco desalineado)
        }
        cout << (char)186 << "  "; // ║ + separación
    }
    cout << endl;
}


void dibujarDadoInferior(int v[], int tam){
    for(int i = 0; i< tam; i++){
        for(int j = 0; j<6; j++){
            if(j == 0){
                cout << (char)200;
            }else if (j == 5){
                cout << (char)188;
            }else{
                cout << (char)205;
            }
        }
            cout << "\t";
    }
}


void dadoUnicoSuperior(){
    for(int j = 0; j<6; j++){
        if(j == 0){
            cout << (char)201;
        }else if (j == 5){
            cout << (char)187;
        }else{
            cout << (char)205;
        }
    }
    cout << endl;
}

void dadoUnicoMedio(int numeroDado){
    cout << (char)186; // ║
    cout << "  " << numeroDado << " "; // Para números de 1 dígito
    cout << (char)186 << "  "; // ║
    cout << endl;

}


void dadoUnicoInferior(){
    for(int j = 0; j<6; j++){
        if(j == 0){
            cout << (char)200;
        }else if (j == 5){
            cout << (char)188;
        }else{
            cout << (char)205;
        }
    }
    cout << endl;
}


