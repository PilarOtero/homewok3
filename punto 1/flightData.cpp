#include "fligthData.h"

/* COMENTARIOS 
-> Al serializar y deserializar se utilizan los propios métodos de serialización y deserialización de la clase base para ahorrar codigo
-> Presion y Posicion, al heredarse de MedicionBase, llaman a su constructor y ahi se produce el problema: esta clase tiene un puntero unique a tiempoMedicion, lo que significa que no se comparte ownership de la dirección de memoria (de modo que no se puede copiar este atributo directamente).
Siguiendo esto, y pensando en que move lo que hace es transferir el ownership, opté por implementar un Copy Constructor para resolver el error SIN transferir la propiedad
*/

//CLASE ABSTRACTA - MEDICION BASE
//Constructor
MedicionBase::MedicionBase(float tiempoMedicion_base) {
    tiempoMedicion = make_unique<float>(tiempoMedicion_base);
}
//Copy Constructor
MedicionBase::MedicionBase(const MedicionBase& other): tiempoMedicion(make_unique<float>(*other.tiempoMedicion)) {};

//Métodos
void MedicionBase:: serializar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

void MedicionBase:: deserializar(ifstream& in) {
    //Creo un puntero unique para el tiempo de medición
    tiempoMedicion = make_unique<float>(0);
    
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

float MedicionBase:: getTiempo() const {
    return *tiempoMedicion;
}

//CLASE DERIVADA PRESIÓN
//Constructor
Presion::Presion(float p, float q, float t): MedicionBase(t), presionEstatica(p), presionDinamica(q) {};

//Métodos
void Presion:: serializar(ofstream& out) const {
    //LLamo al metodo de la clase base para serializar el tiempo de medicion
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion:: deserializar(ifstream& in) {
    //Deserializo el tiempo de medición
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion:: imprimir() const {
    cout << "[PRESION]" << endl;
    cout << "PRESION ESTATICA -> " << presionEstatica << "\nPRESION DINAMICA -> " << presionDinamica << endl;
    cout << "TIEMPO DE MEDICION - presion -> " << *tiempoMedicion << endl;
}

//CLASE DERIVADA POSICIÓN
//Constructor
Posicion::Posicion(float lat, float lon, float alt, float t): MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) {};

//Metodos
void Posicion:: serializar(ofstream& out) const {
    //Serializo el tiempo de medición a partir del método de la clase base
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
}

void Posicion:: deserializar(ifstream& in) {
    //Deserializo el tiempo de medición
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
}

void Posicion:: imprimir() const {
    cout << "\n[POSICION]" << endl;
    cout << "LATITUD -> " << latitud << "\nLONGITUD -> " << longitud << "\nALTITUD -> " << altitud << endl;
    cout << "TIEMPO DE MEDICION - posicion -> " << *tiempoMedicion << endl;
}

//CLASE SAVE FLIGHT DATA
//Constructor
SaveFlightData:: SaveFlightData(const shared_ptr<Posicion>& p, const shared_ptr<Presion>& pr): posicion(p), presion(pr) {};

//Métodos
void SaveFlightData:: serializar(ofstream& out) const {
    //Serializo la posición utilizando su método
    posicion->serializar(out);
    //Serializo la presión utilizando su método
    presion->serializar(out);
}

void SaveFlightData:: deserializar(ifstream& in) {
    //Deserializo la posición utilizando su método
    posicion->deserializar(in);
    //Deserializo la presión utilizando su método
    presion->deserializar(in);
}

void SaveFlightData:: imprimir() const {
    presion->imprimir();
    posicion->imprimir();
}
