#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Introducir fichero de entrada\n";
        return 1;
    }

    ifstream archivo(argv[1]);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo\n";
        return 1;
    }

    vector<string> grid;
    string linea;
    while (getline(archivo, linea)) {
        grid.push_back(linea);
    }

    int filas = grid.size();
    int cols = grid[0].size();
    int solucion = 0;

    int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
    int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '@') {
                int vecinos = 0;

                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < filas &&
                        nj >= 0 && nj < cols &&
                        grid[ni][nj] == '@') {
                        vecinos++;
                    }
                }
                if (vecinos < 4)
                    solucion++;
            }
        }
    }

    cout << solucion << endl;
    return 0;
}
