#ifndef RULETA_H
#define RULETA_H

#include <Mesa.h>


class Ruleta : public Mesa
{
    public:
        /// Constructores
        Ruleta();

        /// Destructores
        ~Ruleta();

        /// Getters & Setters

        /// Metodos

    private:
        /// Variables
        int historial[10];
        int ultimoNumero;

        /// Sobrecargas

        /// Metodos
};

#endif // RULETA_H
