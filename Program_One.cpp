#include <iostream>
#include <string>

using namespace std;

const int MAX_ESTUDIANTES = 100; // Definimos el máximo de estudiantes

struct Estudiante {
    int id;
    char nombres[50];
    char apellidos[50];
    float notas[4]; // arreglo para las 4 notas
    float promedio;
    bool aprobado;
};

int main() {
    int n;
    cout << "Ingrese el numero de estudiantes: ";
    cin >> n;
    cin.ignore(); // Limpiar el buffer del salto de línea
    
    Estudiante estudiantes[MAX_ESTUDIANTES];

    // Ingresar información de cada estudiante
    for (int i = 0; i < n; ++i) {
        cout << "\nIngrese la informacion del estudiante " << i+1 << ":\n";
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cin.ignore(); // Limpiar el buffer del salto de línea
        cout << "Nombres: ";
        cin.getline(estudiantes[i].nombres, 50);
        cout << "Apellidos: ";
        cin.getline(estudiantes[i].apellidos, 50);

        // Ingresar las 4 notas y calcular el promedio
        float suma = 0;
        for (int j = 0; j < 4; ++j) {
            cout << "Nota " << j+1 << ": ";
            cin >> estudiantes[i].notas[j];
            suma += estudiantes[i].notas[j];
        }
        estudiantes[i].promedio = suma / 4;

        // Determinar si el estudiante aprobó o reprobó
        estudiantes[i].aprobado = estudiantes[i].promedio >= 60 ? true : false;
        cin.ignore(); // Limpiar el buffer del salto de línea
    }

    // Mostrar información de cada estudiante y si aprobó o reprobó
    cout << "\n\nInformacion de los estudiantes:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nEstudiante " << i+1 << ":\n";
        cout << "ID: " << estudiantes[i].id << endl;
        cout << "Nombres: " << estudiantes[i].nombres << endl;
        cout << "Apellidos: " << estudiantes[i].apellidos << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        if (estudiantes[i].aprobado)
            cout << "Estado: Aprobado\n";
        else
            cout << "Estado: Reprobado\n";
    }

    return 0;
}
