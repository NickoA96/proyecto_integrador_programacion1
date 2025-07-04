# include<iostream>

#include "creditos.h"
#include "dibujo_lineas.h"

using namespace std;



void creditos(){
    lineaSuperior();
    lineaTitulo();
    lineaInferior();
    cout << (char)186<<"Materia: Programacion 1 \t\t\t                               "<< (char)186<< endl;
    cout << (char)186<<"Nombre de equipo: Grupo 29                                                    " << (char)186<< endl;
	cout << (char)186<<"Autores: Guido Barbieri (Legajo: 32.282) / Nicolas Albornoz (Legajo: 33.120)  " << (char)186<< endl;
	cout << (char)186<<"Juego inventado por Angel Simon. Levemente inspirado en el juego Mafia.       " << (char)186<< endl;
	cout << (char)186<<"Profesores: Brian Lara Campos, Daniel Kloster, Veronica Carbonari,            " << (char)186<< endl;
	cout << (char)186<<"            Andres Olguin" << "\t\t\t\t\t\t       " << (char)186 << endl;
	lineaInferior();
}
