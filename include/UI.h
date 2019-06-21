#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <math.h>

#include "Jugador.h"

#define BLANK 00
#define USD 36

#define Q 201   // ╔
#define W 203   // ╦
#define E 187   // ╗
#define A 204   // ╠
#define S 206   // ╬
#define D 185   // ╣
#define Z 200   // ╚
#define X 202   // ╩
#define C 188   // ╝
#define H 205   // ═
#define V 186   // ║

#define TAM 50

using namespace std;

class UI
{
    public:
        /// Constructor
        UI();

        /// Imprimir Cosas
        // Jugador
        void ImprimirJugador(Jugador _jugador);

        /// Puro UI
        void LineaSuperior();
        void LineaInferior();
};

#endif // UI_H
