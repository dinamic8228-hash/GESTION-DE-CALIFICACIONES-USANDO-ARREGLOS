#include <iostream>
using namespace std;

int main() {
    int cantidadEstudiantes;

    // Solicitar la cantidad de estudiantes
    cout << "Ingrese la cantidad de estudiantes (maximo 20): ";
    cin >> cantidadEstudiantes;

    // Validar la cantidad
    while (cantidadEstudiantes <= 0 || cantidadEstudiantes > 20) {
        cout << "Cantidad invalida, intente nuevamente: ";
        cin >> cantidadEstudiantes;
    }

    // Declaracion de arreglos
    float calificaciones[20][4];
    float promedioEstudiantes[20];

    float sumaGeneral = 0;
    float calificacionMayor = 0;
    float calificacionMenor = 100;

    int cantidadAprobados = 0;
    int cantidadReprobados = 0;

    // Ingreso de calificaciones
    for (int estudiante = 0; estudiante < cantidadEstudiantes; estudiante++) {
        float sumaCalificaciones = 0;

        cout << "\nEstudiante " << estudiante + 1 << endl;

        for (int calificacion = 0; calificacion < 4; calificacion++) {
            cout << "Ingrese la calificacion " << calificacion + 1 << ": ";
            cin >> calificaciones[estudiante][calificacion];

            // Validar rango de la calificacion
            while (calificaciones[estudiante][calificacion] < 0 || calificaciones[estudiante][calificacion] > 100) {
                cout << "Calificacion invalida (0 a 100). Intente nuevamente: ";
                cin >> calificaciones[estudiante][calificacion];
            }

            sumaCalificaciones = sumaCalificaciones + calificaciones[estudiante][calificacion];

            // Verificar calificacion mayor
            if (calificaciones[estudiante][calificacion] > calificacionMayor) {
                calificacionMayor = calificaciones[estudiante][calificacion];
            }

            // Verificar calificacion menor
            if (calificaciones[estudiante][calificacion] < calificacionMenor) {
                calificacionMenor = calificaciones[estudiante][calificacion];
            }
        }

        // Calcular promedio del estudiante
        promedioEstudiantes[estudiante] = sumaCalificaciones / 4;
        sumaGeneral = sumaGeneral + promedioEstudiantes[estudiante];

        // Determinar si aprobo o reprobo
        if (promedioEstudiantes[estudiante] >= 70) {
            cantidadAprobados = cantidadAprobados + 1;
        }
        else {
            cantidadReprobados = cantidadReprobados + 1;
        }
    }

    // Mostrar resultados
    cout << "\n===== RESULTADOS =====\n";

    for (int estudiante = 0; estudiante < cantidadEstudiantes; estudiante++) {
        cout << "\nEstudiante " << estudiante + 1 << ": ";

        for (int calificacion = 0; calificacion < 4; calificacion++) {
            cout << calificaciones[estudiante][calificacion] << " ";
        }

        cout << "Promedio: " << promedioEstudiantes[estudiante];
    }

    float promedioGeneral = sumaGeneral / cantidadEstudiantes;

    cout << "\n\nPromedio general del grupo: " << promedioGeneral;
    cout << "\nCalificacion mas alta: " << calificacionMayor;
    cout << "\nCalificacion mas baja: " << calificacionMenor;
    cout << "\nCantidad de estudiantes aprobados: " << cantidadAprobados;
    cout << "\nCantidad de estudiantes reprobados: " << cantidadReprobados << endl;

    return 0;
}