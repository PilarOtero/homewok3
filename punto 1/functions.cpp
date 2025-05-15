#include "functions.h"
#include <iostream>

void handle_serializationYdeserializacion(SaveFlightData& flightIntel){
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
    cout << "----- INFORMACION DE VUELO -----" << endl;
    flightIntel.imprimir();
    cout << "-------------------------------------------------" << endl;
}
