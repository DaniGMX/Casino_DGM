#ifndef ASIENTO_H
#define ASIENTO_H

#include "Jugador.h"

class Asiento
{
    public:
        /// Constructores
        Asiento();
        Asiento(Jugador* _propietario);

        /// Destructores
        ~Asiento();

        /// Getters & Setters
        Jugador getPropietario() { return propietario; }
        int getApuesta() { return apuesta; }
        void setPropietario(Jugador _propietario) { propietario = _propietario; }

        /// Metodos

    private:
        /// Variables
        Jugador propietario;
        int apuesta;

        /// Sobrecargas

        /// Metodos
};

#endif // ASIENTO_H
