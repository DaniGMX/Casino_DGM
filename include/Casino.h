#ifndef CASINO_H
#define CASINO_H

#include <iostream>
#include <cstdlib>

#include "Jugador.h"
#include "Ruleta.h"

using namespace std;

class Casino
{
    public:
        /// Constructores
        Casino();

        /// Destructores
        ~Casino();

        /// Getters & Setters
        Jugador getJugador(int index) { return jugadores[index];}
        int getNumeroJugadores() {return numeroJugadores; }
        int getEleccion() { return eleccion; }

        /// Metodos
        void AddJugador();
        void redimensionarJugadores();
        int Menu();

    private:
        /// Variables
        int salaActual;
        int eleccion;
        int numeroJugadores;
        Jugador* jugadores;
        Ruleta mesaRuleta;

        /// Sobrecargas

        /// Metodos
};

#endif // CASINO_H
