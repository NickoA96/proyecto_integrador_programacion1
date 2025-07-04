#pragma once

void jugarTurno(int v[], int numeroObjetivo, int &dadosStock,
				int &dadosContrincante, std::string nombreJugador, int rondaNumero, int &sumaSeleccionada, int &puntajeJugador, bool &victoriaAutomatica);

bool terminarTurno(int dado, bool &banderaTerminarTurno);

int dadoElegido(int v[], int tam );

bool dadoUsado (int dadosUtilizados ,int posicionDadosUtilizados[] ,int dadoElegido);






