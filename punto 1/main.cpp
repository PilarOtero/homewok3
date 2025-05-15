#include "fligthData.h"

int main () {
    //Creacion de Objetos
    shared_ptr<Posicion> posicion = make_shared<Posicion>(-34.6f, -58.4f, 950.0f, 5.3);
    shared_ptr<Presion> presion = make_shared<Presion>(101.3f, 5.8f, 6.1f);

    SaveFlightData flightIntel(posicion, presion);

    //Serializo
    ofstream out("flightData.bin", ios::binary);
    if (out.is_open()){ 
        flightIntel.serializar(out); 
        out.close(); 
    }

    //Creo los objetos donde se guardara la informacion al deserializar
    shared_ptr<Posicion> posicion2 = make_shared<Posicion>(0.0f,0.0f,0.0f,0.0f);
    shared_ptr<Presion> presion2 = make_shared<Presion>(0.0f,0.0f,0.0f);
    SaveFlightData flightIntel2(posicion2, presion2);

    //Deserializo
    ifstream in("flightData.bin", ios::binary);
    if (in.is_open()){
        flightIntel2.deserializar(in);
        in.close();
    }

    //Imprimo la informacion
    cout << "----- INFORMACION DE VUELO (deserializada) -----" << endl;
    flightIntel2.imprimir();
    cout << "-------------------------------------------------" << endl;
}
    
