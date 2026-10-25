#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
int main() {
    int opci;
    do {
        cout << "1- Registra articulos\n";
        cout << "2- Reporte de stock\n";
        cout << "3- Consultar producto\n";
        cout << "4- Venta de producto\n";
        cout << "5- Reporte de ventas\n";
        cout << "6- Salir\n";
        cout << "Seleccione una de las opcion: ";
        cin >> opci;
        switch (opci) {
        case 1:
            regis();
            break;
        case 2: 
            repo_stoc();
            break;
        case 3:
            consultar();
            break;
        case 4: 
            vender();
            break;
        case 5: 
            reporvent();
            break;
        case 6:
            cout << "Saliendo...\n";
            break;
        default: cout << "escriba bine el digito porfa\n";
        }
    } while (opci != 6);
    return 0;
}