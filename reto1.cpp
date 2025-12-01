#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char *argv[]) {
    ifstream archivo("input");
    int sol = 0;
    int posicion = 50;
    int valor;

    if (archivo.is_open()) {
        string linea;

        while (getline(archivo, linea)) {
            char tipo = linea[0];
            int valor = stoi(linea.substr(1));
            
            if (tipo == 'R') {
                for (int i=0; i<valor; i++){
                    posicion += 1;
                    if (posicion == 0) sol ++;
                    else {
                        posicion %= 100;
                        if (posicion==0) sol ++;
                    }
                }
            }
            else {
                for (int i=0; i<valor; i++){
                    posicion -= 1;
                    if (posicion == 0) sol ++;
                    else {
                        posicion %= 100;
                        if (posicion == 0) sol ++;
                    }
                }
            }
        }
        archivo.close();
        cout << "solución: " << sol << endl;
        
    } else cout << "no se pudo abrir el archivo." << endl;
    
    return 0;
}
