#include <iostream>
#include "menu.h"
#include "dibujo_lineas.h"
#include "utilidades.h"
using namespace std;



void menu (int &opcion){
    lineaSuperior();
    lineaTitulo();
    lineaInferior();
    cout <<(char)186 << "1 - JUGAR  \t\t\t                                               " <<(char)186<< endl;
    cout <<(char)186 << "2 - ESTADISTICAS  \t\t\t                                       "<<(char)186<< endl;
    cout <<(char)186 << "3 - CREDITOS  \t\t\t                                               "<<(char)186<< endl;
    cout <<(char)186 << "---------------  \t\t\t                                       "<<(char)186<< endl;
    cout <<(char)186 << "0 - SALIR \t\t\t                                               "<<(char)186<< endl;
    lineaInferior();
    cout <<" " <<(char)254  << " Opcion: ";
    validadOpcion(opcion);

}


void validadOpcion (int &opcion){
    cin >> opcion;
    while(opcion < 0 || opcion > 3){
        cout <<" " <<(char)254  << " Opcion invalida" << endl;
        cout <<" " <<(char)254  << " Opcion: ";
        cin >> opcion;
    }
}


void confirmacionSalida(int &confirmacion){
    cout << "Estas seguro que queres salir? (0-SI, 1-NO)" <<endl;
    cin >> confirmacion;
    if(confirmacion == 1){
        limpiarConsola();
    }
}
