#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <memory>

using namespace std;

class IMediciones {
    public:
        virtual void serializar(ofstream& out) const = 0;
        virtual void deserializar(ifstream& in) = 0;

        //Destructor
        virtual ~IMediciones() = default;
};

class MedicionBase: public IMediciones {
    protected:
        unique_ptr<float> tiempoMedicion;
    
    public:
        //Constructor
        MedicionBase(float tiempoMedicion);
        //Constructor de copia
        MedicionBase(const MedicionBase& other);

        //Metodos
        virtual void serializar(ofstream& out) const override;
        virtual void deserializar(ifstream& in) override;
        virtual void imprimir() const = 0;
        float getTiempo() const;

        //Destructor
        virtual ~MedicionBase() = default;
};

class Presion: public MedicionBase {
    public:
        float presionEstatica;
        float presionDinamica;
        //Constructor -> p = presionEstatica, q = presionDinamica, t = tiempoMedicion
        Presion(float p, float q, float t);
        //Constructor de copia 
        Presion(const Presion& other);

        //Metodos
        virtual void serializar(ofstream& out) const override;
        virtual void deserializar(ifstream& in) override;
        virtual void imprimir() const override;

        //Destructor
        ~Presion() = default;
};

class Posicion: public MedicionBase {
    public:
        float latitud;
        float longitud;
        float altitud;
        //Constructor
        Posicion(float lat, float lon, float alt, float t);
        //Constructor de copia
        Posicion(const Posicion& other);

        //Metodos
        virtual void serializar(ofstream& out) const override;
        virtual void deserializar(ifstream& in) override;
        virtual void imprimir() const override;

        //Destructor
        ~Posicion() = default;
};

class SaveFlightData {
    public:
        shared_ptr<Posicion> posicion;
        shared_ptr<Presion> presion;
        //Constructor
        SaveFlightData(const shared_ptr<Posicion>& p, const shared_ptr<Presion>& pr);

        //Metodos
        void serializar(ofstream& out) const;
        void deserializar(ifstream& in);
        void imprimir() const;

        //Destructor
        ~SaveFlightData() = default;
};