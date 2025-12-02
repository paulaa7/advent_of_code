#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    if (argc < 2) {
        cout << "Añadir fichero de entrada\n";
        return 1;
    }

    ifstream archivo(argv[1]);

    if (archivo.is_open()) {
    string linea;
    long long solucion = 0;

        while (getline(archivo, linea, ',')) {
            size_t pos = linea.find('-');
            long long lim1 = stoll(linea.substr(0, pos));
            long long lim2 = stoll(linea.substr(pos + 1));


            for (size_t i=lim1; i<=lim2; i++) {
                string cad1 = to_string(i);
                int tam = cad1.size();

                for (size_t div=tam/2; div>0; div--) {
                    if (tam % div != 0) continue;

                    string p = cad1.substr(0, div);
                    string correcta = "";
                    for(size_t k=0; k<(tam/div); k++)
                        correcta += p;

                    if (cad1 == correcta){ solucion += stoll(cad1); break;}
                }
            }
        }
        cout << solucion << endl;
    }
}

int apartado_uno(int argc, char *argv[]){
    if (argc < 2) {
        cout << "Añadir fichero de entrada\n";
        return 1;
    }

    ifstream archivo(argv[1]);

    if (archivo.is_open()) {
    string linea;
    long long solucion = 0;

        while (getline(archivo, linea, ',')) {
            size_t pos = linea.find('-');
            long long lim1 = stoll(linea.substr(0, pos));
            long long lim2 = stoll(linea.substr(pos + 1));


            for (size_t i=lim1; i<=lim2; i++) {
                string cad = to_string(i);
                int tam = cad.size();
                if (tam % 2 != 0) continue;

                string p = cad.substr(0, tam/2);
                if (cad == p + p) solucion += stoll(cad);
            }
        }
        cout << solucion << endl;
    }
}
