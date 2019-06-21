#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

using namespace std;

class Jugador
{
    public:
        /// Constructores
        Jugador();
        Jugador(string _name, int _edad, int _dni, float saldo);

        /// Destructores
        ~Jugador();

        /// Getters & Setters
        string getNombre(){ return this->nombre; }
        int getEdad(){ return this->edad; }
        int getDNI(){ return this->dni; }
        float getSaldo(){ return this->saldo; }

        void setNombre(string _nombre) { this->nombre = _nombre; }
        void setEdad(int _edad) { this->edad = _edad; }
        void setDni(int _dni) { this->dni = _dni; }
        void setSaldo(float _saldo) { this->saldo = _saldo; }

        /// Metodos

    private:
        /// Variables
        string nombre;
        int edad;
        int dni;
        float saldo;

        /// Sobrecargas


        /// Metodos

};

#endif // JUGADOR_H
