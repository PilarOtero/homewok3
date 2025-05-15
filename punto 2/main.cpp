#include "clases.h"
#include <iomanip>

int main () {
    //Creacion de puntos
    Punto p1(10,20);
    Punto circle_center(2.5,5.3);
    Punto elipse_center(4.8,7.0);
    Punto rectangle_infV(4.4,4.4);

    //Creacion de figuras
    Circulo c1(5.0, circle_center);
    Elipse e1(elipse_center, 10.9, 15.6);
    Rectangulo r1(rectangle_infV, 5.0, 10.333);

    //Procesadores
    ProcesadorFiguras<Circulo> processed_circle;
    ProcesadorFiguras<Elipse> processed_elipse;
    ProcesadorFiguras<Rectangulo> processed_rectangle;
    ProcesadorFiguras<Punto> processed_point;

    //Defino que el resultado tenga 3 cifras detras de la coma
    cout << fixed << setprecision(3);
    cout << "-----------AREAS-----------" << endl;
    cout << "1. Circulo -> A =  " << processed_circle.calculateArea(c1) << endl;
    cout << "2. Elipse -> A = " << processed_elipse.calculateArea(e1) << endl;
    cout << "3. Rectangulo -> A = " << processed_rectangle.calculateArea(r1) << endl;
    //Prueba con caso generico
    cout << "4. Punto -> A = 0 ("; processed_point.calculateArea(p1); cout << ")" << endl;
}