#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//PUNTO
class Punto {
    private:
        float x;
        float y;

    public:
        //Constructor
        Punto(float x, float y);

        //Getters
        float getX() const;
        float getY() const;

        //Setters
        void setX(float x_p);
        void setY(float y_p);
};

//CIRCULO
class Circulo {
    private:
        float radio;
        Punto position;
    
    public:
        //Constructor
        Circulo(float radio_circle, Punto& position_circle);

        //Getters
        float getRadio() const;
        Punto getPosition() const;

        //Setters 
        void setRadio(float r);
        void setPosition(Punto& p);
};

//ELIPSE
class Elipse {
    private:
        Punto center;
        //Semieje mayor
        float a;
        //Semieje menor
        float b;

    public:
        //Constructor
        Elipse(Punto& center_e, float a_e, float b_e);

        //Getters
        //Punto getCenter() const;
        float getA() const;
        float getB() const;

        //Setters
        //void setCenter(Punto& p);
        void setA(float major);
        void setB(float minor); 
};

//RECTANGULO
class Rectangulo {
    private:
        Punto left_inferior_vertex;
        float width;
        float length;

    public:
        //Constructor
        Rectangulo(Punto left_inferior_vertex_r, float width_r, float length_r);

        //Getters
        Punto getLeftInferiorVertex() const;
        float getWidth() const;
        float getLength() const;

        //Setters (this para referir a la instancia actual de la clase)
        void setLeftInferiorVertex(Punto& p);
        void setWidth(float w);
        void setLength(float l);
};

//PROCESADOR DE FIGURAS
//Caso generico
template <typename T>
class ProcesadorFiguras {
    public:
        //Metodo para calcular el area
        void calculateArea(T& figure) {
            cout << "Tipo de figura generica" << endl;
        }
};

//Caso especializacion Circulo
template <>
class ProcesadorFiguras<Circulo> {
    public:
        //Calculo del area
        float calculateArea(Circulo& c) {
            return M_PI * pow(c.getRadio(),2);
        }
};

//Caso especializacion Elipse
template<>
class ProcesadorFiguras<Elipse> {
    public:
        //Calculo del area
        float calculateArea(Elipse& e) {
            return M_PI * e.getA() * e.getB();
        }
};

//Caso especializacion Rectangulo
template<>
class ProcesadorFiguras<Rectangulo> {
    public:
        //Calculo del area
        float calculateArea(Rectangulo& r) {
            return r.getWidth() * r.getLength();
        }
};