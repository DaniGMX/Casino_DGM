#ifndef MESA_H
#define MESA_H

#include <vector>
#include <iostream>

#include "Asiento.h"

using namespace std;

class Mesa
{
    public:
        /// Constructores
        Mesa();

        /// Destructores
        ~Mesa();

        /// Getters & Setters
        Asiento getAsiento(int index) { return asientos[index]; }
        int getNumeroAsientos() { return numeroAsientos; }

        /// Metodos
        void PedirJugadores(vector<Jugador> _jugadoresPosibles);

    private:
        /// Variables
        int banca = 1000000;
        vector<Asiento> asientos;
        int numeroAsientos;

        /// Sobrecargas

        /// Metodos
};

#endif // MESA_H
