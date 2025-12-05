#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main (int argc, char *argv[]) {
    if (argc < 2) return 1;

    ifstream archivo(argv[1]);
    if (!archivo.is_open()) return -1;

    vector<pair<long long,long long>> rangos;
    string linea;
    int sol = 0;

    while (getline(archivo, linea)) {
        if (linea == "") break;
        else {
            size_t pos = linea.find('-');
            long long lim1 = stoll(linea.substr(0, pos));
            long long lim2 = stoll(linea.substr(pos + 1));
            rangos.push_back({lim1, lim2});
        }
    }

    sort(rangos.begin(), rangos.end());
    vector<pair<long long,long long>> fusionados;
    fusionados.push_back(rangos[0]);

    for (int i = 1; i < (int)rangos.size(); i++) {
        auto &last = fusionados.back();
        auto &curr = rangos[i];

        if (curr.first <= last.second + 1) {
            last.second = max(last.second, curr.second);
        } else {
            fusionados.push_back(curr);
        }
    }

    long long sol = 0;
    for (auto &r : fusionados)
        sol += (r.second - r.first + 1);

    /* apartado 1:
    while (getline(archivo, linea)) {
        long long ingredient_ID = stoll(linea);
        for (auto &r : rangos)
            if (ingredient_ID >= r.first && ingredient_ID <= r.second) {
                sol++;
                break;
            }
    }
    */
    cout << sol << endl;
    return 0;
}
