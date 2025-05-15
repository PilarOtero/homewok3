#include "fligthData.h"

//COMENTARIO -> al serializar y deserializar se utilizan los propios metodos de serializacion y deserializacion de la clase base para ahorrar codigo

//CLASE ABSTRACTA - MEDICION BASE
//Constructor
MedicionBase::MedicionBase(float tiempoMedicion_base) {
    tiempoMedicion = make_unique<float>(tiempoMedicion_base);
}

//Metodos
void MedicionBase:: serializar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

void MedicionBase:: deserializar(ifstream& in) {
    //Creo un puntero unique para el tiempo de medicion
    tiempoMedicion = make_unique<float>(0);
    
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

float MedicionBase:: getTiempo() const {
    return *tiempoMedicion;
}

//CLASE DERIVADA PRESION
//Constructor
Presion::Presion(float p, float q, float t): MedicionBase(t), presionEstatica(p), presionDinamica(q) {};

//Metodos
void Presion:: serializar(ofstream& out) const {
    //LLamo al metodo de la clase base para serializar el tiempo de medicion
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion:: deserializar(ifstream& in) {
    //Deserializo el tiempo de medicion
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion:: imprimir() const {
    cout << "----PRESION----" << endl;
    cout << "PRESION ESTATICA -> " << presionEstatica << "\nPRESION DINAMICA -> " << presionDinamica << endl;
    cout << "TIEMPO DE MEDICION - presion -> " << *tiempoMedicion << endl;
}

//CLASE DERIVADA POSICION
//Constructor
Posicion::Posicion(float lat, float lon, float alt, float t): MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) {};

//Metodos
void Posicion:: serializar(ofstream& out) const {
    //Serializo el tiempo de medicion a partir del metodo de la clase base
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
}

void Posicion:: deserializar(ifstream& in) {
    //Deserializo el tiempo de medicion
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
}

void Posicion:: imprimir() const {
    cout << "\n----POSICION----" << endl;
    cout << "LATITUD -> " << latitud << "\nLONGITUD -> " << longitud << "\nALTITUD -> " << altitud << endl;
    cout << "TIEMPO DE MEDICION - posicion -> " << *tiempoMedicion << endl;
}

//CLASE SAVE FLIGHT DATA
//Constructor
SaveFlightData:: SaveFlightData(const shared_ptr<Posicion>& p, const shared_ptr<Presion>& pr): posicion(p), presion(pr) {};

//Metodos
void SaveFlightData:: serializar(ofstream& out) const {
    //Serializo la posicion utilizando su metodo
    posicion->serializar(out);
    //Serializo la presion utilizando su metodo
    presion->serializar(out);
}

void SaveFlightData:: deserializar(ifstream& in) {
    //Deserializo la posicion utilizando su metodo
    posicion->deserializar(in);
    //Deserializo la presion utilizando su metodo
    presion->deserializar(in);
}

void SaveFlightData:: imprimir() const {
    presion->imprimir();
    posicion->imprimir();
}
