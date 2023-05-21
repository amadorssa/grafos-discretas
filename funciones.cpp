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

int calcularGradoVertice(int* matriz, int n, int vertice) {
    int grado = 0;
    
    for (int i = 0; i < n; i++) {
        if (matriz[vertice * n + i] != 0) {
            grado++;
        }
    }
    return grado;
}

int vertice1, vertice2, grado;
bool adyacentes;

void userMenu(int choice, int* matriz, int* grafica, int n) {
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
                cout << "Ingresa el vértice 1 [1," << n << "]: ";
                cin >> vertice1;
            } while (vertice1 < 1 || vertice1 > n);
            
            do {
                cout << "Ingresa el vértice 2 [1," << n << "]: ";
                cin >> vertice2;
            } while (vertice2 < 1 || vertice2 > n);

            adyacentes = sonAdyacentes(matriz, n, vertice1-1, vertice2-1);
                if (adyacentes) {
                    cout << endl << "Los vértices " << vertice1 << " y " << vertice2 << " son adyacentes." << endl;
                } else {
                    cout << endl << "Los vértices " << vertice1 << " y " << vertice2 << " no son adyacentes." << endl;
                }
            break;

        case 3: // Calcular el grado de un vértice
            do {
                cout << "Ingresa el vértice al que deseas calcular el grado [1," << n << "]: ";
                cin >> vertice1;
            } while (vertice1 < 1 || vertice1 > n);
            
            grado = calcularGradoVertice(matriz, n, vertice1-1);  // Calcula el grado del vértice 0
            cout << endl << "El grado del vértice " << vertice1 << " es: " << grado << endl;
            break;

        case 4: // Salir del programa
            liberarMemoria(grafica);
            cout << "Gracias por usar nuestro programa." << endl;
            break;

        default:
            cout << "Opción inválida." << endl;   
            break;
    }
}
