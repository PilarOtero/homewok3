#include <concepts>
#include <string>
#include <vector>

template <typename T>
class GeneradorVector {
    private:
        vector<T> vec;
    
    public:
        //Constructor
        GeneradorVector() {};
        
        //Metodos
        void agregar(const T& nuevoDato){
            vec.push_back(nuevoDato);
        }

        void procesamiento() {
            if (vec.empty()) {
                return "El vector esta vacio" << endl;
            }

            //Manejo de datos
            if constexpr(is_same_v<T, double){
                vec_doubles.push_back(data)
            }
            else if constexpr(is_same_v<T, string){
                palabras.push_back(data);
            }
            else if constexpr(is_same_v<T, vector<int>>){
                listas.push_back(data);
            }
            else{
                cout << "Tipo de dato desconocido" << endl;
            }
        }
};