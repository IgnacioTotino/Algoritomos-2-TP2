#pragma once

#include <iostream>
#include "Tablero.h"

bool posicionValida(Tablero *, Posicion);
bool dimensionesValidas(unsigned int, unsigned int, unsigned int);
bool movimientoValido(Posicion, Posicion);
