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
        float calculateArea() {
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
        float calculateArea(Circulo& c) {
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
        float calculateArea(Elipse& e) {
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
        float calculateArea(Rectangulo& r) {
            return r.getWidth() * r.getLength();
        }
};