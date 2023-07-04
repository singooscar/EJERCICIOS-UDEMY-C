#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"

int comprobarID(struct empleado empleados[100], int num_emp, int id);

void mostrarMenu() {
    printf("\nIntroduce la opción que desee realizar:\n");
    printf("1. Alta empleado\n");
    printf("2. Baja empleado\n");
    printf("3. Listar empleados\n");
    printf("4. Consultar datos empleado\n");
    printf("5. Modificar sueldo\n");
    printf("6. Modificar horas\n");
    printf("7. Salir\n");
}

void listarEmpleados(struct empleado empleados[100], int num_emp) {
    printf("Listando los datos de los empleados:\n");
    for (int i = 0; i < num_emp; i++) {
        printf("Nombre: %s\n", empleados[i].nombre);
        printf("Id del empleado: %d\n", empleados[i].id);
        printf("Sueldo: %.2f\n", empleados[i].sueldo);
        printf("Horas semanales: %d\n", empleados[i].horas);
        printf("\n");
    }
}

int alta(struct empleado empleados[100], int num_emp) {
    int creado = 0;
    struct empleado emp;

    fflush(stdin);
    printf("Introduce nombre y apellidos: ");
    scanf("%s", emp.nombre);

    printf("Introduce el id del empleado: ");
    scanf("%d", &emp.id);

    printf("Introduce sueldo: ");
    scanf("%f", &emp.sueldo);

    printf("Introduce horas semanales trabajadas: ");
    scanf("%d", &emp.horas);

    int existe = comprobarID(empleados, num_emp, emp.id);

    if (num_emp < 100) {
        if (existe == 0) {
            empleados[num_emp] = emp;
            creado = 1;
        } else {
            printf("No se puede crear empleado, ID duplicado\n");
        }
    } else {
        printf("No se puede dar de alta el empleado. Cupo alcanzado\n");
    }

    return creado;
}

int baja(struct empleado empleados[100], int num_emp) {
    int eliminado = 0;
    int id, indice;

    printf("Introduce el ID del empleado a dar de baja: ");
    scanf("%d", &id);

    int existe = comprobarID(empleados, num_emp, id);

    if (existe == 1) {
        for (int i = 0; i < num_emp; i++) {
            if (empleados[i].id == id) {
                indice = i;
                break;
            }
        }

        for (int j = indice; j < num_emp - 1; j++) {
            empleados[j] = empleados[j + 1];
        }

        eliminado = 1;
    } else {
        printf("No se puede dar de baja el empleado, ID no existe\n");
    }

    return eliminado;
}

void consultarEmpleado(struct empleado empleados[100], int num_emp, int id) {
    int encontrado = 0;

    for (int i = 0; i < num_emp; i++) {
        if (empleados[i].id == id) {
            printf("Nombre: %s\n", empleados[i].nombre);
            printf("Id del empleado: %d\n", empleados[i].id);
            printf("Sueldo: %.2f\n", empleados[i].sueldo);
            printf("Horas semanales: %d\n", empleados[i].horas);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró un empleado con el ID proporcionado\n");
    }
}

void modificarSueldo(struct empleado empleados[100], int num_emp, int id) {
    int encontrado = 0;

    for (int i = 0; i < num_emp; i++) {
        if (empleados[i].id == id) {
            printf("Introduce el nuevo sueldo para el empleado: ");
            scanf("%f", &empleados[i].sueldo);
            printf("Sueldo modificado con éxito\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró un empleado con el ID proporcionado\n");
    }
}

void modificarHoras(struct empleado empleados[100], int num_emp, int id) {
    int encontrado = 0;

    for (int i = 0; i < num_emp; i++) {
        if (empleados[i].id == id) {
            printf("Introduce las nuevas horas para el empleado: ");
            scanf("%d", &empleados[i].horas);
            printf("Horas modificadas con éxito\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró un empleado con el ID proporcionado\n");
    }
}

int comprobarID(struct empleado empleados[100], int num_emp, int id) {
    for (int i = 0; i < num_emp; i++) {
        if (empleados[i].id == id) {
            return 1; 
        }
    }
    return 0; 
}
