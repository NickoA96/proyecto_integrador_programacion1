#pragma once


void mensajeResultado(int sumaSeleccionada, int numeroObjetivo, int dadosUtilizados,
					 int dadosContrincante,int dadosElegidos[], int dadosStock, bool &victoriaAutomatica, std::string nombreJugador, int &puntajeJugador, int &puntaASumar);

void mostrarDatosPartida(int numeroObjetivo, int sumaSeleccionada, std::string nombreJugador,int rondaNumero, int puntajeJugador, int dadosStock);

void resultadoFinal(std::string nombreJugador1,std::string nombreJugador2,int puntajeJugador1, int puntajeJugador2, int dadosStockJugador1,int dadosStockJugador2,
                    std::string &nombreGanador, bool &existeGanador, int &puntajeGanador);
