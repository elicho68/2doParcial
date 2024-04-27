#include <iostream>
#include <cstring>
#include <cstdio>

#define MAX_ESTUDIANTES 100

using namespace std;

// Definición de la estructura para almacenar la información del estudiante
struct Estudiante {
    int id;
    char nombres[50];
    char apellidos[50];
    float notas[4];
    float promedio;
    char resultado[10];
};

// Función para agregar un nuevo estudiante
void agregarEstudiante(Estudiante estudiantes[], int &numEstudiantes) {
	system("cls");
    if (numEstudiantes >= MAX_ESTUDIANTES) {
        cout << "No se pueden agregar más estudiantes." << endl;
        return;
    }

    Estudiante nuevoEstudiante;
    cout << "Ingrese el ID del estudiante: ";
    cin >> nuevoEstudiante.id;
    cin.ignore(); // Para consumir el salto de línea después del número
    cout << "Ingrese el nombre del estudiante: ";
    cin.getline(nuevoEstudiante.nombres, 50);
    cout << "Ingrese el apellido del estudiante: ";
    cin.getline(nuevoEstudiante.apellidos, 50);
    cout << "Ingrese las notas del estudiante (nota1 nota2 nota3 nota4): ";
    for (int i = 0; i < 4; i++) {
        cin >> nuevoEstudiante.notas[i];
    }

    // Calcular el promedio
    float suma = 0;
    for (int i = 0; i < 4; i++) {
        suma += nuevoEstudiante.notas[i];
    }
    nuevoEstudiante.promedio = suma / 4;

    // Determinar si aprobó o reprobó
    if (nuevoEstudiante.promedio >= 60) {
        strcpy(nuevoEstudiante.resultado, "Aprobado");
    } else {
        strcpy(nuevoEstudiante.resultado, "Reprobado");
    }

    // Agregar el nuevo estudiante al arreglo
    estudiantes[numEstudiantes] = nuevoEstudiante;
    numEstudiantes++;
}

// Función para guardar los estudiantes en un archivo binario
void guardarEstudiantes(Estudiante estudiantes[], int numEstudiantes, const char* nombre_archivo) {
	system("cls");
    FILE* archivo = fopen(nombre_archivo, "w+b");
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    fwrite(estudiantes, sizeof(Estudiante), numEstudiantes, archivo);

    fclose(archivo);
    cout << "Estudiantes guardados en el archivo " << nombre_archivo << "." << endl;
}

// Función para leer los estudiantes desde un archivo binario
void leerEstudiantes(Estudiante estudiantes[], int &numEstudiantes, const char* nombre_archivo) {
    system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        cout << "No se encontró el archivo " << nombre_archivo << ". Se creará uno nuevo." << endl;
        archivo = fopen(nombre_archivo, "w+b");
        if (!archivo) {
            cout << "Error al crear el archivo " << nombre_archivo << "." << endl;
            return;
        }
    }

    numEstudiantes = fread(estudiantes, sizeof(Estudiante), MAX_ESTUDIANTES, archivo);

    fclose(archivo);
}

// Función para mostrar la información de todos los estudiantes
void mostrarEstudiantes(Estudiante estudiantes[], int numEstudiantes) {
	system("cls");    
	cout << "ID\tNombres\t\t\tApellidos\tPromedio\tResultado" << endl;
    for (int i = 0; i < numEstudiantes; i++) {
        cout << estudiantes[i].id << "\t" << estudiantes[i].nombres << "\t\t\t" << estudiantes[i].apellidos << "\t\t" 
             << estudiantes[i].promedio << "\t\t" << estudiantes[i].resultado << endl;
    }
}

// Función para actualizar un estudiante por su ID
void actualizarEstudiante(Estudiante estudiantes[], int numEstudiantes) {
	system("cls");
    int id;
    cout << "Ingrese el ID del estudiante que desea actualizar: ";
    cin >> id;

    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].id == id) {
            cout << "Ingrese el nuevo nombre del estudiante: ";
            cin.ignore();
            cin.getline(estudiantes[i].nombres, 50);
            cout << "Ingrese el nuevo apellido del estudiante: ";
            cin.getline(estudiantes[i].apellidos, 50);
            cout << "Ingrese las nuevas notas del estudiante (nota1 nota2 nota3 nota4): ";
            for (int j = 0; j < 4; j++) {
                cin >> estudiantes[i].notas[j];
            }

            // Recalcular el promedio
            float suma = 0;
            for (int j = 0; j < 4; j++) {
                suma += estudiantes[i].notas[j];
            }
            estudiantes[i].promedio = suma / 4;

            // Determinar si aprobó o reprobó
            if (estudiantes[i].promedio >= 60) {
                strcpy(estudiantes[i].resultado, "Aprobado");
            } else {
                strcpy(estudiantes[i].resultado, "Reprobado");
            }

            cout << "Estudiante actualizado correctamente." << endl;
            return;
        }
    }

    cout << "No se encontró un estudiante con el ID proporcionado." << endl;
}

// Función para eliminar un estudiante por su ID
void eliminarEstudiante(Estudiante estudiantes[], int &numEstudiantes) {
	system("cls"); 
    int id;
    cout << "Ingrese el ID del estudiante que desea eliminar: ";
    cin >> id;

    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].id == id) {
            for (int j = i; j < numEstudiantes - 1; j++) {
                estudiantes[j] = estudiantes[j + 1];
            }
            numEstudiantes--;
            cout << "Estudiante eliminado correctamente." << endl;
            return;
        }
    }

    cout << "No se encontró un estudiante con el ID proporcionado." << endl;
}

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes = 0;
    int opcion;

    leerEstudiantes(estudiantes, numEstudiantes, "notas.dat");

    do {
        cout << "\n1. Agregar estudiante" << endl;
        cout << "2. Guardar estudiantes en archivo" << endl;
///        cout << "3. Leer estudiantes desde archivo" << endl;
        cout << "3. Mostrar estudiantes" << endl;
        cout << "4. Actualizar estudiante" << endl;
        cout << "5. Eliminar estudiante" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarEstudiante(estudiantes, numEstudiantes);
                break;
            case 2:
                guardarEstudiantes(estudiantes, numEstudiantes, "notas.dat");
                break;
//            case 3:
//                leerEstudiantes(estudiantes, numEstudiantes, "notas.dat");
//                break;
            case 3:
                mostrarEstudiantes(estudiantes, numEstudiantes);
                break;
            case 4:
                actualizarEstudiante(estudiantes, numEstudiantes);
                break;
            case 5:
                eliminarEstudiante(estudiantes, numEstudiantes);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
