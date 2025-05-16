#pragma once

using namespace std;

template <typename T>
class GeneradorVector {
    private:
        vector<double> vec_doubles;
        vector<string> palabras;
        vector<vector<int>> listas;
    
    public:
        //Constructor
        //GeneradorVector();
        
        //Metodos
        void agregar(const T& data);
};