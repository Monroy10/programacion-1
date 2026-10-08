#include <stdio.h>

#define MAX_L 5
#define MAX_U 3
#define VACIO -1

typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int anio;
    char editorial[100];
    int paginas;
    int disponible;
    int prestado_a;
} libro;

typedef struct {
    int id;
    char nombre[100];
    char direccion[100];
    char telefono[15];
    int edad;
    int prestamos;
    int libros[3];
} usuario;

void cargar_datos(libro cat[], usuario usr[]);
void procesar_prestamo(libro cat[], usuario usr[]);
void procesar_devolucion(libro cat[], usuario usr[]);
void mostrar_libros(libro cat[]);
void mostrar_usuarios(usuario usr[], libro cat[]);

int main() {
    int n = 0;
    libro cat[MAX_L];
    usuario usr[MAX_U];

    cargar_datos(cat, usr);

    do {
        printf("\n=================================\n");
        printf("    GESTION DE BIBLIOTECA\n");
        printf("=================================\n");
        printf("1. Prestamo\n");
        printf("2. Devolucion\n");
        printf("3. Consulta de libros\n");
        printf("4. Consulta de usuarios\n");
        printf("5. Salir\n");
        printf("Elija una opcion: ");

        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            n = 0;
        }

        switch (n) {
            case 1:
                procesar_prestamo(cat, usr);
                break;
            case 2:
                procesar_devolucion(cat, usr);
                break;
            case 3:
                mostrar_libros(cat);
                break;
            case 4:
                mostrar_usuarios(usr, cat);
                break;
            case 5:
                printf("\nFinalizando programa...\n");
                break;
            default:
                printf("\nOpcion invalida. Intente de nuevo.\n");
                break;
        }
    } while (n != 5);

    return 0;
}

void cargar_datos(libro cat[], usuario usr[]) {
    libro base_libros[MAX_L] = {
        {100, "Proyecto Hail Mary", "Andy Weir", 2021, "Ballantine Books", 496, 0, 2},
        {101, "Maze Runner", "James Dashner", 2009, "Delacorte Press", 375, 0, 1},
        {102, "Dune", "Frank Herbert", 1965, "Chilton Books", 412, 1, VACIO},
        {103, "The Hunger Games", "Suzanne Collins", 2008, "Scholastic", 374, 0, 1},
        {104, "Ready Player One", "Ernest Cline", 2011, "Crown Publishing", 374, 0, 2}
    };

    usuario base_usuarios[MAX_U] = {
        {1, "Samuel de Luque", "Andorra", "34 6000 0001", 37, 2, {103, 101, VACIO}},
        {2, "Ricardo Perez", "CDMX", "55 1234 5678", 29, 2, {100, 104, VACIO}},
        {3, "Cristiano Ronaldo", "Riad", "96 6000 0007", 41, 0, {VACIO, VACIO, VACIO}}
    };

    int i = 0;
    for (i = 0; i < MAX_L; i++) {
        cat[i] = base_libros[i];
    }
    for (i = 0; i < MAX_U; i++) {
        usr[i] = base_usuarios[i];
    }
}

void procesar_prestamo(libro cat[], usuario usr[]) {
    int id_u = 0;
    int id_l = 0;
    int i = 0, k = 0, a = 0;

    printf("\n--- REGISTRO DE PRESTAMO ---\n");
    printf("Ingrese ID del usuario: ");
    scanf("%d", &id_u);

    for (i = 0; i < MAX_U; i++) {
        if (usr[i].id == id_u) {
            if (usr[i].prestamos >= 3) {
                printf("El usuario ha alcanzado el limite de prestamos.\n");
                return;
            }

            printf("Ingrese ID del libro solicitado: ");
            scanf("%d", &id_l);

            for (k = 0; k < MAX_L; k++) {
                if (cat[k].id == id_l) {
                    if (cat[k].disponible == 1) {
                        cat[k].disponible = 0;
                        cat[k].prestado_a = usr[i].id;
                        usr[i].prestamos++;

                        for (a = 0; a < 3; a++) {
                            if (usr[i].libros[a] == VACIO) {
                                usr[i].libros[a] = cat[k].id;
                                printf("Prestamo autorizado exitosamente.\n");
                                return;
                            }
                        }
                    } else {
                        printf("El libro no esta disponible actualmente.\n");
                        return;
                    }
                }
            }
            printf("Libro no encontrado.\n");
            return;
        }
    }
    printf("Usuario no encontrado.\n");
}

void procesar_devolucion(libro cat[], usuario usr[]) {
    int id_l = 0;
    int i = 0, k = 0, a = 0;
    int encontrado = 0;

    printf("\n--- REGISTRO DE DEVOLUCION ---\n");
    printf("Ingrese ID del libro a devolver: ");
    scanf("%d", &id_l);

    for (i = 0; i < MAX_U; i++) {
        for (a = 0; a < 3; a++) {
            if (usr[i].libros[a] == id_l) {
                usr[i].libros[a] = VACIO;
                usr[i].prestamos--;

                for (k = 0; k < MAX_L; k++) {
                    if (cat[k].id == id_l) {
                        cat[k].disponible = 1;
                        cat[k].prestado_a = VACIO;
                        printf("Devolucion realizada con exito.\n");
                        encontrado = 1;
                        break;
                    }
                }
                break;
            }
        }
        if (encontrado) break;
    }

    if (!encontrado) {
        printf("El libro no consta como prestado a ningun usuario.\n");
    }
}

void mostrar_libros(libro cat[]) {
    int i = 0;

    printf("\n--- CONSULTA DE CATALOGO ---\n");
    for (i = 0; i < MAX_L; i++) {
        printf("Registro #%d\n", i + 1);
        printf("ID: %d\n", cat[i].id);
        printf("Titulo: %s\n", cat[i].titulo);
        printf("Autor: %s\n", cat[i].autor);
        printf("Anio: %d\n", cat[i].anio);
        printf("Editorial: %s\n", cat[i].editorial);
        printf("Paginas: %d\n", cat[i].paginas);

        if (cat[i].disponible == 1) {
            printf("Estado: DISPONIBLE\n");
        } else {
            printf("Estado: PRESTADO (Usuario ID: %d)\n", cat[i].prestado_a);
        }
        printf("-----------------------------\n");
    }
}

void mostrar_usuarios(usuario usr[], libro cat[]) {
    int id_u = 0;
    int i = 0, a = 0, k = 0;

    printf("\n--- CONSULTA DE USUARIO ---\n");
    printf("Ingrese ID del usuario: ");
    scanf("%d", &id_u);

    for (i = 0; i < MAX_U; i++) {
        if (usr[i].id == id_u) {
            printf("ID: %d\n", usr[i].id);
            printf("Nombre: %s\n", usr[i].nombre);
            printf("Direccion: %s\n", usr[i].direccion);
            printf("Telefono: %s\n", usr[i].telefono);
            printf("Edad: %d\n", usr[i].edad);
            printf("Prestamos activos: %d\n", usr[i].prestamos);

            if (usr[i].prestamos > 0) {
                printf("Libros en posesion:\n");
                for (a = 0; a < 3; a++) {
                    if (usr[i].libros[a] != VACIO) {
                        for (k = 0; k < MAX_L; k++) {
                            if (cat[k].id == usr[i].libros[a]) {
                                printf(" - [%d] %s\n", cat[k].id, cat[k].titulo);
                                break;
                            }
                        }
                    }
                }
            } else {
                printf("El usuario no registra prestamos vigentes.\n");
            }
            return;
        }
    }
    printf("Usuario no registrado.\n");
}
