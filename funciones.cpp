#include <iostream>
#include <cstdlib>
#include <ctime>
#include "myLib.h"

using namespace std;


int* generarMatrizAdyacencia(int n, int* matriz) {
    // Inicializar todas las entradas con cero
    for (int i = 0; i < n * n; i++) {
        matriz[i] = 0;
    }

    srand(time(NULL)); // Semilla para generador de numeros aleatorios

    // Generador aleatorio de aristas
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            int randomNum = rand() % 2; // Generar un número aleatorio entre 0 y 1

            // Establecer la conexión en ambas direcciones
            matriz[i * n + j] = randomNum;
            matriz[j * n + i] = randomNum;
        }
    }
    return matriz;
}

void liberarMemoria(int* matriz) {
    delete[] matriz;
}

bool sonAdyacentes(int* matriz, int n, int vertice1, int vertice2) {
    return matriz[vertice1 * n + vertice2] != 0; // Verificar si los vértices son adyacentes

}

void userMenu(int choice, int* matriz, int* grafica, int n) {
    int vertice1, vertice2; // Move the variable declaration outside the switch statement

    switch (choice) {

        case 1: // Imprimir matriz de adyacencia
            cout << "Matriz de adyacencia:" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << grafica[i * n + j] << " ";
                }
                cout << endl;
            }
            break;

        case 2: // Verificar si dos vértices son adyacentes

            do {
                cout << "Ingresa el vértice 1: ";
                cin >> vertice1;
            } while (vertice1 < 0 || vertice1 >= n);
            
            do {
                cout << "Ingresa el vértice 2: ";
                cin >> vertice2;
            } while (vertice2 < 0 || vertice2 >= n);

            bool adyacentes = sonAdyacentes(matriz, n, vertice1, vertice2);
            if (adyacentes) {
                cout << "Los vértices " << vertice1 << " y " << vertice2 << " son adyacentes." << endl;
            } else {
                cout << "Los vértices " << vertice1 << " y " << vertice2 << " no son adyacentes." << endl;
            }
            break;

        case 3: // Calcular el grado de un vértice de una gráfica
            cout << "Opción 3 seleccionada." << endl;
            break;

        case 4: // Salir del programa
            liberarMemoria(grafica);
            cout << "Gracias por usar nuestro programa." << endl;
            cout << "Autor: Amado Rosas" << endl;
            break;

        default:
            cout << "Opción inválida." << endl;   
            break;
    }
}
