#include "clases.cpp"

int main() {
    //Genero los vectores
    GeneradorVector<double> vec_doubles;
    GeneradorVector<string> palabras;
    GeneradorVector<vector<int>> listas;
    JSONGenerador generador;

    //Agrego los datos a su respectivo vector
    vec_doubles.agregar(1.3);
    vec_doubles.agregar(2.1);
    vec_doubles.agregar(3.2);

    palabras.agregar("Hola");
    palabras.agregar("Mundo");

    listas.agregar({1, 2});
    listas.agregar({3, 4});

    generador.agregar("vec_doubles", vec_doubles);
    generador.agregar("palabras", palabras);
    generador.agregar("listas", listas);

    generador.imprimir();
}