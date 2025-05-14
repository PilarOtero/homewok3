#include <iostream>
#include <string>
#include "clases.h"

using namespace std;

//PUNTO
//Constructor
Punto::Punto(float x, float y): x(x), y(y) {};

//Getters
float Punto::getX() const { return x; }
float Punto::getY() const { return y; }

//Setters (this para referir a la instancia actual de la clase)
void Punto::setX(float x_p) { this->x = x_p; }
void Punto::setY(float y_p) { this->y = y_p; }


//CIRCULO
//Constructor
Circulo::Circulo(float radio_circle, Punto& position_circle): radio(radio_circle), position(position_circle) {};

//Getters
float Circulo::getRadio() const { return radio; }
Punto Circulo::getPosition() const { return position; }

//Setters (this para referir a la instancia actual de la clase)
void Circulo::setRadio(float r) { this->radio = r; }
void Circulo::setPosition(Punto& p) { this->position = p; }


//ELIPSE

//Constructor
Elipse::Elipse(Punto& center_e, float a_e, float b_e): center(center_e), a(a_e), b(b_e) {};
//Getters
//Punto Elipse::getCenter() const { return center; }
float Elipse::getA() const { return a; }
float Elipse::getB() const { return b; }

//Setters (this para referir a la instancia actual de la clase)
//void Elipse::setCenter(Punto& p) { this->center = p; }
void Elipse::setA(float major) { this->a = major; }
void Elipse::setB(float minor) { this->b = minor; }     


//RECTANGULO
//Constructor
Rectangulo::Rectangulo(Punto left_inferior_vertex_r, float width_r, float length_r): left_inferior_vertex(left_inferior_vertex_r), width(width_r), length(length_r) {};

//Getters
Punto Rectangulo::getLeftInferiorVertex() const { return left_inferior_vertex; }
float Rectangulo::getWidth() const { return width; }
float Rectangulo::getLength() const { return length; }

//Setters (this para referir a la instancia actual de la clase)
void Rectangulo::setLeftInferiorVertex(Punto& p) { this->left_inferior_vertex = p; }
void Rectangulo::setWidth(float w) { this->width = w; }
void Rectangulo::setLength(float l) { this->length = l; }







