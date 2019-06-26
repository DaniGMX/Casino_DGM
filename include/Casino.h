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
        // Jugador getJugador(int index) { return players[index]; }
        Jugador getPlayer(int index) { return players[index]; }
        int getNumeroJugadores() {return players.size(); }
        int getEleccion() { return eleccion; }

        /// Metodos
        void AddJugador();
        void AddPlayers();
        void redimensionarJugadores();
        int Menu();

    private:
        /// Variables
        int salaActual;
        int eleccion;
        int numeroJugadores;
        Jugador* jugadores;
        Ruleta mesaRuleta;

        std::vector<Jugador> players;


        /// Sobrecargas

        /// Metodos
};

#endif // CASINO_H
