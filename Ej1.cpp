#include <iostream>
#include <fstream> // Librería fundamental para leer archivos (base de datos)
#include <vector>  // Nos ayuda a leer sin saber el tamaño exacto inicial
#include "Algoritmos ordenamiento/bubbleSort.h" // Incluimos la librería con la función de tu profe

using namespace std;

int main() {
    // 1. Abrir el archivo de la base de datos 
    // Reemplaza "datos.txt" por el nombre exacto del archivo de tu profe
    ifstream archivo("datos.txt"); 
    
    // Verificamos si el archivo se abrió correctamente para evitar errores
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo de la base de datos. Verifica el nombre." << endl;
        return 1; // Salimos del programa con código de error
    }

    // 2. Leer los datos del archivo
    // Usamos un vector temporalmente porque no sabemos cuántos datos hay en el archivo.
    vector<int> datosTemporales;
    int numero;
    
    // Leemos el archivo número por número hasta el final
    while (archivo >> numero) {
        datosTemporales.push_back(numero);
    }
    archivo.close(); // Siempre es buena práctica cerrar el archivo al terminar de leer

    int size = datosTemporales.size();
    
    if (size == 0) {
        cout << "El archivo está vacío o no se encontraron datos válidos." << endl;
        return 1;
    }

    // 3. Convertimos el vector al arreglo de punteros (int *arr) que requiere tu función
    int *baseDeDatos = new int[size];
    for (int i = 0; i < size; i++) {
        baseDeDatos[i] = datosTemporales[i];
    }

    // Mostramos un resumen antes de ordenar
    cout << "--- Base de datos cargada correctamente ---" << endl;
    cout << "Total de elementos a ordenar: " << size << "\n" << endl;

    // 4. Llamar a la función de ordenamiento
    cout << "Iniciando el algoritmo Bubble Sort..." << endl;
    
    // Guardamos lo que retorna la función en una variable
    unsigned long long cantidadComparaciones = bubbleSortOptimizado(baseDeDatos, size);

    // 5. Mostrar los resultados exigidos por el ejercicio
    cout << "\n================ RESULTADOS ================" << endl;
    cout << "Condicionales (comparaciones) requeridas: " << cantidadComparaciones << endl;
    
    // Mostramos los primeros y últimos elementos para comprobar que se ordenó
    cout << "\nPrimeros 5 elementos ordenados: ";
    for (int i = 0; i < (size < 5 ? size : 5); i++) {
        cout << baseDeDatos[i] << " ";
    }
    cout << "..." << endl;

    // 6. Liberar la memoria del arreglo dinámico
    delete[] baseDeDatos;

    return 0;
}