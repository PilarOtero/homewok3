#include <vector>
#include <type_traits>
#include <sstream>
#include <iostream>

using namespace std;

//Defino los alias a utilizar
using vecInt = vector<int>;
using datosJSON = vector<pair<string, string>>;

template <typename T>
string toString(const vector<T>& vectorT) {
    //Utilizo el método ostringstream para convertir el vector a string de manera más sencilla
    ostringstream oss;
    oss << "[";

    /* Si no se está en la primera posición, agrego una coma para separar los elementos, caso contrario se imprimirá:
    { "vec_doubles": [1.32.13.2],
      "palabras": ["Hola""Mundo"],
      "listas": [
              [12],
              [34]
              ]
    } */
    bool first = true;
    //Itero sobre el vector y convierto sus elementos a string
    for(const auto& elem: vectorT){
        if (!first) oss << ",";
        first = false;

        //Si el elemento es un string, lo imprimo entre comillas (escapeo las comillas para que se impriman)
        if constexpr(is_same_v<T, string>){
            oss << "\"" << elem << "\"";
        }
        else {
            oss << elem;
        }
    }

    oss << "]";
    return oss.str();
}

template <typename T>
class GeneradorVector {
    private:
        vector<T> vec;
    
    public:
        //Agrego un elemento al vector
        void agregar(const T& nuevoDato){
            vec.push_back(nuevoDato);
        }

        //Manejo la impresión de los datos en función de su tipo
        string procesar() const {
            if (vec.empty()) {
                return "[]";
            }
            //Double
            if constexpr(is_same_v<T, double>){
                return toString(vec);
            }

            //String
            else if constexpr(is_same_v<T, string>){
                return toString(vec);
            }

            //Vector de int
            else if constexpr(is_same_v<T, vecInt>){
                string impresion = "[\n";
                for (const auto& lista: vec){
                    impresion += "\t  " + toString(lista);
                    // .back() devuelve el último elemento del vector -> si no es el último elemento, agrego una coma
                    if (lista != vec.back()){
                        impresion += ",\n";
                    }
                }
                impresion += "\n\t ]";
                return impresion;
            }

            //Tipo desconocido -> el tipo de dato no es ninguno de los anteriores
            else{
                cout << "Tipo de dato desconocido" << endl;
            }
        }
};

class JSONGenerador {
    private:
        //El primer elemento (key) será el nombre de la lista (valor)
        datosJSON datos;
    
    public:
        template <typename T>
        //Agrego a la impresión el nombre del vector y su vector correspondiente 
        void agregar(const string& nombreVec, const GeneradorVector<T>& valor){
            datos.push_back({nombreVec, valor.procesar()});
        }

        //Impresión de los datos en formato JSON
        void imprimir() const {
            cout << "{";
            for (const auto& dato:datos){
                //El elemento es el primero
                if (dato == datos.front()) {
                    cout << " \"" << dato.first << "\": " << dato.second;
                }
                else {
                    cout << "  \"" << dato.first << "\": " << dato.second;
                }
                //Imprimo una coma después del elemento si no es el último
                if (dato != datos.back()){
                    cout << ",";
                }
                cout << "\n";
            }
            cout << "}" << endl;
        }
};


int main() {
    //Genero los vectores
    GeneradorVector<double> vec_doubles;
    GeneradorVector<string> palabras;
    GeneradorVector<vecInt> listas;
    JSONGenerador generador;

    //Agrego los datos a su respectivo vector
    vec_doubles.agregar(1.3);
    vec_doubles.agregar(2.1);
    vec_doubles.agregar(3.2);

    palabras.agregar("Hola");
    palabras.agregar("Mundo");

    listas.agregar({1,2});
    listas.agregar({3,4});

    generador.agregar("vec_doubles", vec_doubles);
    generador.agregar("palabras", palabras);
    generador.agregar("listas", listas);

    generador.imprimir();
}