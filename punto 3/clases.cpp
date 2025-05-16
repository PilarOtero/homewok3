#include <vector>
#include <type_traits>
#include <sstream>
#include <iostream>

using namespace std;

template <typename T>
string toString(const vector<T>& vectorT) {
    //Utilizo el metodo ostringstream para convertir el vector a string de manera mas sencilla
    ostringstream oss;
    oss << "[";

    /* Si el elemento no es el primero, agrego una coma para separar los elementos, caso contrario se imprimirá:
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

        //Manejo la impresion de los datos en funcion de su tipo
        string procesar() const {
            if (vec.empty()) {
                return "[]";
            }
            //DOUBLE
            if constexpr(is_same_v<T, double>){
                return toString(vec);
            }

            //STRING
            else if constexpr(is_same_v<T, string>){
                return toString(vec);
            }

            //VECTOR DE ENTEROS
            else if constexpr(is_same_v<T, vector<int>>){
                string impresion = "[\n";
                for (const auto& lista: vec){
                    impresion += "\t  " + toString(lista);
                    if (lista != vec.back()){
                        impresion += ",\n";
                    }
                }
                impresion += "\n\t  ]";
                return impresion;
            }

            //TIPOS DESCONOCIDOS -> el tipo de dato no es ninguno de los anteriores
            else{
                cout << "Tipo de dato desconocido" << endl;
            }
        }
};

class JSONGenerador {
    private:
        //El primer elemento (key) será el nombre de la lista (valor)
        vector<pair<string, string>> datos;
    
    public:
        template <typename T>
        //Agrego a la impresion el nombre del vector y su vector correspondiente 
        void agregar(const string& nombreVec, const GeneradorVector<T>& valor){
            datos.push_back({nombreVec, valor.procesar()});
        }

        //Impresion de los datos en formato JSON
        void imprimir() const {
            cout << "{";
            for (size_t i = 0; i < datos.size(); i++){
                const auto& dato = datos[i];
                if (i == 0) {
                    cout << " \"" << dato.first << "\": " << dato.second;
                }
                else {
                    cout << "  \"" << dato.first << "\": " << dato.second;
                }
                if (i != datos.size() - 1){
                    cout << ",";
                }
                cout << "\n";
            }
            cout << "}" << endl;
        }
};


