#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "persistencias.h"

int main() {
    int opcion = 0;
    int num_emp = 0;
    struct empleado empleados[100];

    num_emp = cargarEmpleados(empleados);

    printf("Bienvenidos al gestor de empleados\n");
    mostrarMenu();
    scanf("%d", &opcion);

    while (opcion != 7) {
        if (opcion == 1) {
            int creado = alta(empleados, num_emp);
            if (creado == 1) {
                num_emp++;
            }
        } else if (opcion == 2) {
            int eliminado = baja(empleados, num_emp);
            if (eliminado == 1) {
                num_emp--;
            }
        } else if (opcion == 3) {
            listarEmpleados(empleados, num_emp);
        } else if (opcion == 4) {
            int id;
            printf("Introduce el ID del empleado a consultar: ");
            scanf("%d", &id);
            consultarEmpleado(empleados, num_emp, id);
        } else if (opcion == 5) {
            int id;
            printf("Introduce el ID del empleado a modificar el sueldo: ");
            scanf("%d", &id);
            modificarSueldo(empleados, num_emp, id);
        } else if (opcion == 6) {
            int id;
            printf("Introduce el ID del empleado a modificar las horas: ");
            scanf("%d", &id);
            modificarHoras(empleados, num_emp, id);
        }
        mostrarMenu();
        scanf("%d", &opcion);
    }

    guardarEmpleados(empleados, num_emp);

    printf("Gracias por usar el gestor de empleados. ¡HASTA PRONTO!\n\n");

    return 0;
}
