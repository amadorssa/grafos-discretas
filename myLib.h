#include <string>

using namespace std;

int* generarMatrizAdyacencia(int n, int* matriz);
void liberarMemoria(int* matriz);
bool sonAdyacentes(int* matriz, int n, int vertice1, int vertice2);
void userMenu(int choice, int* matriz, int* grafica, int n);

