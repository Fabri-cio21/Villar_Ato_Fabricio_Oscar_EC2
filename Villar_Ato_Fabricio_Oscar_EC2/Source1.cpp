#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int maxi =50;

int codigos[maxi], stock[maxi], numproduc = 0;
string nombres[maxi];
float precios[maxi];

int comprovan[maxi], cantides[maxi], nuventas = 0;
string clientes[maxi], fechas[maxi];
float totales[maxi];
int numeroComprobante = 1000;

void regis() {
    cout << "\n";
    if (numproduc == maxi) {
        cout << "No se pueden registrar mas productos :(.\n ya llego al maximo de 50 :(";
        return;
    }
    int c;
    cout << "Codigo: "; cin >> c;
    for (int i = 0; i < numproduc; i++)
        if (codigos[i] == c) {
            cout << "ya existe el codigo \n";
            return;
        }
    codigos[numproduc] = c;
    cin.ignore();
    cout << "Nombre: "; 
    getline(cin, nombres[numproduc]);
    cout << "Precio: "; 
    cin >> precios[numproduc];
    cout << "Stock: ";  
    cin >> stock[numproduc];
    numproduc++;
    cout << "Producto registrado.\n";
}

void repo_stoc() {
    cout << "\n";
    if (numproduc == 0) {
        cout << "No hay productos.\n";
        return;
    }
    cout << left << setw(8) << "Codigo" << setw(20) << "Nombre" << setw(10) << "Precio" << "Stock\n";
    for (int i = 0; i < numproduc; i++) {
        cout << setw(8) << codigos[i] << setw(20) << nombres[i]
            << setw(10) << precios[i] << stock[i] << "\n";
    }
}
    


int buscar(int c) {
    for (int i = 0; i < numproduc; i++) {
        if (codigos[i] == c) {
            return i;
        }
    }
    return -1;
}

void consultar() {
    cout << "\n";
    if (numproduc == 0) {
        cout << "No hay productos.\n";
        return;
    }
    int c;
    cout << "Codigo a buscar: "; cin >> c;
    int i = buscar(c);
    if (i == -1) cout << "Producto no encontrado.\n";
    else {
        cout << "Codigo: " << codigos[i] << "\nNombre: " << nombres[i]
            << "\nPrecio: " << precios[i] << "\nStock: " << stock[i] << "\n";
    }
}

void vender() {
    cout << "\n";
    if (numproduc == 0) {
        cout << "No hay productos.\n";
        return;
    }
    int c, cant, i;
    cout << "Codigo producto: "; cin >> c;
    i = buscar(c);
    if (i == -1) {
        cout << "Producto no existe.\n";
        return;
    }
    cout << "Stock disponible: " << stock[i] << "\nCantidad a vender: ";
    cin >> cant;
    if (cant > stock[i]) {
        cout << "Stock insuficiente.\n";
        return;
    }
    cin.ignore();//para k getilne pueda funcionar
    cout << "Nombre cliente: ";
    getline(cin, clientes[nuventas]);
    fechas[nuventas] = "10/06/2025";
    comprovan[nuventas] = numeroComprobante++;
    cantides[nuventas] = cant;
    totales[nuventas] = precios[i] * cant;
    stock[i] -= cant;
    cout << "Venta registrada. Total: " << totales[nuventas] << "\n";
    nuventas++;
}

void reporvent(){
    cout << "\n";
    if (nuventas == 0) {
        cout << "No hay ventas.\n";
        return;
    }
    cout << left << setw(8) << "Compra" << setw(20) << "Cliente" <<
        setw(12) << "Fecha" << setw(10) << "Cantidad" << "Total\n";
    for (int i = 0; i < nuventas; i++) {
        cout << setw(8) << comprovan[i] << setw(20) << clientes[i] << setw(12) << fechas[i]
            << setw(10) << cantides[i] << totales[i] << "\n";
    }     
}