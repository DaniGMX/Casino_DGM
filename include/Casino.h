#ifndef CASINO_H
#define CASINO_H

#include <iostream>
#include <cstdlib>
#include <vector>

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
        Jugador getJugador(int index) { return jugadores[index]; }
        int getNumeroJugadores() {return jugadores.size(); }
        int getEleccion() { return eleccion; }

        /// Metodos
        void AddJugador();
        void JugarRuleta();
        int Menu();

    private:
        /// Variables
        int salaActual;
        int eleccion;
        int numeroJugadores;
        Ruleta mesaRuleta;
        vector<Jugador> jugadores;

        /// Sobrecargas

        /// Metodos
};

#endif // CASINO_H
