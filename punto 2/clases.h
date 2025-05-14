#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//PUNTO
class Punto {
    private:
        double x;
        double y;

    public:
        //Constructor
        Punto(double x, double y);

        //Getters
        double getX() const;
        double getY() const;

        //Setters
        void setX(double x_p);
        void setY(double y_p);
};

//CIRCULO
class Circulo {
    private:
        double radio;
        Punto position;
    
    public:
        //Constructor
        Circulo(double radio_circle, Punto position_circle);

        //Getters
        double getRadio() const;
        Punto getPosition() const;

        //Setters 
        void setRadio(double r);
        void setPosition(Punto& p);
};

//ELIPSE
class Elipse {
    private:
        Punto center;
        //Semieje mayor
        double a;
        //Semieje menor
        double b;

    public:
        //Constructor
        Elipse(Punto center_e, double a_e, double b_e);

        //Getters
        Punto getCenter() const;
        double getA() const;
        double getB() const;

        //Setters
        void setCenter(Punto& p);
        void setA(double major);
        void setB(double minor); 
};

//RECTANGULO
class Rectangulo {
    private:
        Punto left_inferior_vertex;
        double width;
        double length;

    public:
        //Constructor
        Rectangulo(Punto left_inferior_vertex_r, double width_r, double length_r);

        //Getters
        Punto getLeftInferiorVertex() const;
        double getWidth() const;
        double getLength() const;

        //Setters (this para referir a la instancia actual de la clase)
        void setLeftInferiorVertex(Punto& p);
        void setWidth(double w);
        void setLength(double l);
};

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