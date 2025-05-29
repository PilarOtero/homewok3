#include "../headers/functions.h"
#include "../headers/flightData.h"

int main () {
    //Creación de Objetos
    shared_ptr<Posicion> posicion = make_shared<Posicion>(-34.6f, -58.4f, 950.0f, 5.3);
    shared_ptr<Presion> presion = make_shared<Presion>(101.3f, 5.8f, 6.1f);
    SaveFlightData flightIntel(posicion, presion);

    //Serialización y deserialización
    handle_serializationYdeserializacion(flightIntel);

    return 0;
}
    
