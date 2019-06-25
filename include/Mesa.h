#ifndef MESA_H
#define MESA_H

#include "Asiento.h"

class Mesa
{
    public:
        /// Constructores
        Mesa();

        /// Destructores
        ~Mesa();

        /// Getters & Setters

        /// Metodos

    private:
        /// Variables
        int banca = 1000000;
        Asiento* asaientos;
        bool sePuedeApostar;

        /// Sobrecargas

        /// Metodos
};

#endif // MESA_H
