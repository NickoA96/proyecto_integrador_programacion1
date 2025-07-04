#pragma once

void procesarEleccionDado(int v[], int posicionDado, int &sumaSeleccionada, int vecDadosElegidos [], int &dadosUtilizados, int vecPosicionDadosUtilizados[]);

void dadosActualizados(int sumaSeleccionada, int numeroObjetivo, int &dadosStock, int &dadosContrincante, int dadosUtilizados, bool &victoriaAutomatica);

bool verificarJugada(int sumaSeleccionada, int numeroObjetivo, int dadosUtilizados,int dadosStock, bool &victoriaAutomatica);

int puntaje(int numeroObjetivo, int dadosUtilizados,int &puntajeJugador, int sumaSeleccionada, int dadosStock, bool &victoriaAutomatica, int &puntajeASumar);
