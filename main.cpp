#include <iostream>
#include "myLib.h"


using namespace std;

int main() {
    int choice = 0;
    int n = 0;  // Número de vértices

    cout << "Número de vértices: ";
    cin >> n;

    int* matriz = new int[n * n]; // Crear la matriz de adyacencia como un arreglo unidimensional 
    int* grafica = generarMatrizAdyacencia(n, matriz); // Generar la gráfica

    cout << endl << "La gráfica ha sido generada con éxito." << endl;

    do {
        cout << endl << "Selecciona una de las siguientes opciones" << endl;
        cout << "\t(1) Imprimir matriz de adyacencia" << endl;
        cout << "\t(2) Verificar si dos vértices son adyacentes" << endl;
        cout << "\t(3) Calcular el grado de un vértice de la gráfica" << endl;
        cout << "\t(4) Salir" << endl;

        cout << "Ingrese una opción: ";
        cin >> choice;
        cout << endl;

        userMenu(choice, matriz, grafica, n);

    } while (choice != 4);

    return 0;
}
