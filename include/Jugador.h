#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

using namespace std;

class Jugador
{
    public:
        /// Constructores
        Jugador();
        Jugador(string _name, int _edad, int _saldo);
        Jugador(const Jugador &_jugador);

        /// Destructores
        ~Jugador();

        /// Getters & Setters
        string getAlias(){ return this->alias; }
        int getEdad(){ return this->edad; }
        int getSaldo(){ return this->saldo; }

        void setAlias(string _alias) { this->alias = _alias; }
        void setEdad(int _edad) { this->edad = _edad; }
        void setSaldo(int _saldo) { this->saldo = _saldo; }

        /// Metodos

    private:
        /// Variables
        string alias;
        int edad;
        int saldo;

        /// Sobrecargas


        /// Metodos
        void ImprimirJugador();
        bool JugadorCorrecto();
};

#endif // JUGADOR_H
