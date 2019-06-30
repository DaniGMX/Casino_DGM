#ifndef RULETA_H
#define RULETA_H

#include <Mesa.h>
#include <cstdlib>
#include <iostream>
#include <time.h>

#include "Excepciones.h"

#define VERDE 0
#define ROJO -1
#define NEGRO -2
#define PAR -3
#define IMPAR -4
#define PRIMERAMITAD -5
#define SEGUNDAMITAD -6
#define PRIMERADOCENA -7
#define SEGUNDADOCENA -8
#define TERCERADOCENA -9

#define COLORES 0
#define PARIDAD 1
#define MITADES 2
#define DOCENAS 3
#define NUMEROS 4

using namespace std;

class Ruleta : public Mesa
{
    public:
        /// Constructores
        Ruleta();

        /// Destructores
        ~Ruleta();

        /// Getters & Setters

        /// Sobrecargas
        friend ostream & operator << (ostream &out, const Ruleta &r);

        /// Metodos
        void GenerarNumero();
        void Apostar(int, int, int);
        void RedimensionarCosas(int);
        bool ComprobarApuestas(int);

    private:
        /// Variables
        int numeroCosas;
        int ultimoNumero;
        int numeros[37];
        int colores[37];

        int* tipoApuesta;       // Guarda el tipo de apuesta que hace un jugador
        int* cantidadApuesta;   // Guarda la cantidad de dinero que apuesta un jugador
        int* apuesta;           // Guarda la apuesta que ha realizado un jugador

        /// Sobrecargas

        /// Metodos
};

#endif // RULETA_H
