struct empleado {
    char nombre[255];
    int id;
    float sueldo;
    int horas;
};

void mostrarMenu();
void listarEmpleados(struct empleado empleados[100], int num_emp);
int alta(struct empleado empleados[100], int num_emp);
int baja(struct empleado empleados[100], int num_emp);
void consultarEmpleado(struct empleado empleados[100], int num_emp, int id);
void modificarSueldo(struct empleado empleados[100], int num_emp, int id);
void modificarHoras(struct empleado empleados[100], int num_emp, int id);
