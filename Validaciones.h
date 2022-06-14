#pragma once

#ifndef VAL_H_
#define VAL_H_

#include <iostream>
#include <cstdlib>
#include "Tablero.h"

class Tablero;
class Posicion;

bool posicionValida(Tablero *, Posicion);
bool dimensionesValidas(unsigned int, unsigned int, unsigned int);
bool movimientoValido(Posicion, Posicion);

#endif