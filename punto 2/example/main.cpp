#include "../headers/clases.h"
#include <iomanip>

int main () {
    //Creación de puntos
    Punto p1(10,20);
    Punto centro_circulo(2.5,5.3);
    Punto centro_elipse(4.8,7.0);
    Punto rectangulo_infV(4.4,4.4);

    //Creación de figuras
    Circulo c1(5.0, centro_circulo);
    Elipse e1(centro_elipse, 10.9, 15.6);
    Rectangulo r1(rectangulo_infV, 5.0, 10.333);

    //Procesadores
    ProcesadorFiguras<Circulo> circulo_procesado;
    ProcesadorFiguras<Elipse> elipse_procesada;
    ProcesadorFiguras<Rectangulo> rectangulo_procesado;
    ProcesadorFiguras<Punto> punto_procesado;

    //Defino que el resultado tenga 3 cifras detrás de la coma
    cout << fixed << setprecision(3);

    cout << "-----------AREAS-----------" << endl;
    cout << "1. Círculo -> A =  " << circulo_procesado.calculateArea(c1) << endl;
    cout << "2. Elipse -> A = " << elipse_procesada.calculateArea(e1) << endl;
    cout << "3. Rectángulo -> A = " << rectangulo_procesado.calculateArea(r1) << endl;
    //Prueba caso genérico 
    cout << "4. Punto -> A = 0 ("; punto_procesado.calculateArea(p1); cout << ")" << endl;
}