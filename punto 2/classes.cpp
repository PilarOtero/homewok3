
#include <cmath>
#include "classes.h"

using namespace std;

//PUNTO

        //Constructor
        Punto:: Punto(double x, double y): x(x), y(y) {};

        //Getters
        double Punto:: getX() const { return x; }
        double Punto:: getY() const { return y; }

        //Setters (this para referir a la instancia actual de la clase)
        void Punto:: setX(double x_p) { this->x = x_p; }
        void Punto:: setY(double y_p) { this->y = y_p; }


//CIRCULO

        //Constructor
        Circulo:: Circulo(double radio_circle, Punto position_circle): radio(radio_circle), position(position_circle) {};

        //Getters
        double Circulo:: getRadio() const { return radio; }
        Punto Circulo:: getPosition() const { return position; }

        //Setters (this para referir a la instancia actual de la clase)
        void Circulo:: setRadio(double r) { this->radio = r; }
        void Circulo:: setPosition(Punto& p) { this->position = p; }

//ELIPSE

        //Constructor
        Elipse:: Elipse(Punto center_e, double a_e, double b_e): center(center_e), a(a_e), b(b_e) {};

        //Getters
        Punto Elipse:: getCenter() const { return center; }
        double Elipse:: getA() const { return a; }
        double Elipse:: getB() const { return b; }

        //Setters (this para referir a la instancia actual de la clase)
        void Elipse:: setCenter(Punto& p) { this->center = p; }
        void Elipse:: setA(double major) { this->a = major; }
        void Elipse:: setB(double minor) { this->b = minor; }     


//RECTANGULO

        //Constructor
        Rectangulo:: Rectangulo(Punto left_inferior_vertex_r, double width_r, double length_r): left_inferior_vertex(left_inferior_vertex_r), width(width_r), length(length_r) {};

        //Getters
        Punto Rectangulo:: getLeftInferiorVertex() const { return left_inferior_vertex; }
        double Rectangulo:: getWidth() const { return width; }
        double Rectangulo:: getLength() const { return length; }

        //Setters (this para referir a la instancia actual de la clase)
        void Rectangulo:: setLeftInferiorVertex(Punto& p) { this->left_inferior_vertex = p; }
        void Rectangulo:: setWidth(double w) { this->width = w; }
        void Rectangulo:: setLength(double l) { this->length = l; }

//PROCESADOR DE FIGURAS
//Caso generico
template <typename T>
class ProcesadorFiguras {
    private:
        T figure;
    public:
        //Constructor
        ProcesadorFiguras(T figure_f): figure(figure_f) {};

        //Getters
        T getFigura() const { return figure; }

        //Setters (this para referir a la instancia actual de la clase)
        void setFigura(T& f) { this->figure = f; }

        //Metodo para calcular el area
        double calculateArea() {
            cout << "Tipo de figura generica" << endl;
            return 0.0;
        }
};

//Caso especializacion Circulo
template <>
class ProcesadorFiguras<Circulo> {
    private:
        Circulo circle;

    public:
        //Constructor
        ProcesadorFiguras(Circulo c1): circle(c1) {};

        //Calculo del area
        double calculateArea(Circulo& c) {
            return M_PI * pow(c.getRadio(),2);
        }
};

//Caso especializacion Elipse
template<>
class ProcesadorFiguras<Elipse> {
    private:
        Elipse elipse;
    public:
        //Constructor
        ProcesadorFiguras(Elipse e1): elipse(e1) {};

        //Calculo del area
        double calculateArea(Elipse& e) {
            return M_PI * e.getA() * e.getB();
        }
};

//Caso especializacion Rectangulo
template<>
class ProcesadorFiguras<Rectangulo> {
    private:
        Rectangulo rectangle;
    public:
        //Constructor
        ProcesadorFiguras(Rectangulo r1): rectangle(r1) {};
        //Calculo del area
        double calculateArea(Rectangulo& r) {
            return r.getWidth() * r.getLength();
        }
};





