#include <vector>
#include <type_traits>
#include <sstream>
#include <iostream>

using namespace std;

template <typename T>
string toString(const vector<T>& vectorT) {
    ostringstream oss;
    oss << "[";

    bool first = true;
    for(const auto& elem: vectorT){
        if (!first) oss << ",";
        first = false;

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
        void agregar(const T& nuevoDato){
            vec.push_back(nuevoDato);
        }

        string procesar() const {
            if (vec.empty()) {
                return "[]";
            }
            //Manejo de datos
            if constexpr(is_same_v<T, double>){
                return toString(vec);
            }

            else if constexpr(is_same_v<T, string>){
                return toString(vec);
            }

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
            else{
                cout << "Tipo de dato desconocido" << endl;
            }
        }
};

class JSONGenerador {
    private:
        //El primer elemento (key) sera el nombre de la lista (valor)
        vector<pair<string, string>> datos;
    
    public:
        template <typename T>
        void agregar(const string& nombreVec, const GeneradorVector<T>& valor){
            datos.push_back({nombreVec, valor.procesar()});
        }

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

int main() {
    //Genero los vectores
    GeneradorVector<double> vec_doubles;
    GeneradorVector<string> palabras;
    GeneradorVector<vector<int>> listas;
    JSONGenerador generador;

    //Agrego los datos a los vectores
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
    return 0;
}
