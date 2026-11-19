#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BIN "huracanes.dat"
#define TMP "auxiliar.dat"
#define TXT "reporte_huracanes.txt"

struct huracan {
    char nom[50];
    int cat;
    char fec[30];
    float tam;
    char ori[50];
    float vel;
};

void alta(void);
void editar(void);
void borrar(void);
void reporte(void);

int main() {
    int op;

    do {
        printf("\n--- REGISTRO DE HURACANES ---\n");
        printf("1. Ingresar huracan\n");
        printf("2. Modificar datos\n");
        printf("3. Eliminar huracan\n");
        printf("4. Generar reporte\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                alta();
                break;
            case 2:
                editar();
                break;
            case 3:
                borrar();
                break;
            case 4:
                reporte();
                break;
            case 5:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opcion incorrecta.\n");
        }
    } while (op != 5);

    return 0;
}

void alta(void) {
    FILE *fp;
    struct huracan h;

    fp = fopen(BIN, "ab");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("\n--- NUEVO HURACAN ---\n");
    printf("Nombre: ");
    scanf(" %49[^\n]", h.nom);

    printf("Categoria (1 a 5): ");
    scanf("%d", &h.cat);

    printf("Fecha de clasificacion: ");
    scanf(" %29[^\n]", h.fec);

    printf("Tamaño (radio en grados o km): ");
    scanf("%f", &h.tam);

    printf("Origen (coordenadas): ");
    scanf(" %49[^\n]", h.ori);

    printf("Velocidad maxima: ");
    scanf("%f", &h.vel);

    fwrite(&h, sizeof(struct huracan), 1, fp);
    fclose(fp);
    printf("Huracan registrado.\n");
}

void editar(void) {
    FILE *fp;
    struct huracan h;
    char bus[50];
    int ok = 0;

    fp = fopen(BIN, "r+b");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("\n--- MODIFICAR HURACAN ---\n");
    printf("Nombre del huracan a buscar: ");
    scanf(" %49[^\n]", bus);

    while (fread(&h, sizeof(struct huracan), 1, fp) == 1) {
        if (strcmp(h.nom, bus) == 0) {
            printf("Nuevo nombre: ");
            scanf(" %49[^\n]", h.nom);

            printf("Nueva categoria (1 a 5): ");
            scanf("%d", &h.cat);

            printf("Nueva fecha: ");
            scanf(" %29[^\n]", h.fec);

            printf("Nuevo tamaño: ");
            scanf("%f", &h.tam);

            printf("Nuevo origen: ");
            scanf(" %49[^\n]", h.ori);

            printf("Nueva velocidad maxima: ");
            scanf("%f", &h.vel);

            fseek(fp, -(long)sizeof(struct huracan), SEEK_CUR);
            fwrite(&h, sizeof(struct huracan), 1, fp);
            ok = 1;
            printf("Registro actualizado.\n");
            break;
        }
    }

    if (ok == 0) {
        printf("No se encontro ese huracan.\n");
    }

    fclose(fp);
}

void borrar(void) {
    FILE *fp, *aux;
    struct huracan h;
    char bus[50];
    int ok = 0;

    fp = fopen(BIN, "rb");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    aux = fopen(TMP, "wb");
    if (aux == NULL) {
        printf("Error al crear archivo temporal.\n");
        fclose(fp);
        return;
    }

    printf("\n--- ELIMINAR HURACAN ---\n");
    printf("Nombre del huracan a eliminar: ");
    scanf(" %49[^\n]", bus);

    while (fread(&h, sizeof(struct huracan), 1, fp) == 1) {
        if (strcmp(h.nom, bus) != 0) {
            fwrite(&h, sizeof(struct huracan), 1, aux);
        } else {
            ok = 1;
        }
    }

    fclose(fp);
    fclose(aux);

    if (ok == 1) {
        remove(BIN);
        rename(TMP, BIN);
        printf("Huracan eliminado.\n");
    } else {
        remove(TMP);
        printf("No se encontro ese huracan.\n");
    }
}

void reporte(void) {
    FILE *fp, *rep;
    struct huracan h;

    fp = fopen(BIN, "rb");
    if (fp == NULL) {
        printf("No hay registros guardados.\n");
        return;
    }

    rep = fopen(TXT, "w");
    if (rep == NULL) {
        printf("No se pudo crear el reporte.\n");
        fclose(fp);
        return;
    }

    printf("\nNombre\tCategoria\tFecha\tTamaño\tOrigen\tVelocidad\n");
    fprintf(rep, "Nombre\tCategoria\tFecha\tTamaño\tOrigen\tVelocidad\n");

    while (fread(&h, sizeof(struct huracan), 1, fp) == 1) {
        printf("%s\t%d\t%s\t%.2f\t%s\t%.2f\n", h.nom, h.cat, h.fec, h.tam, h.ori, h.vel);
        fprintf(rep, "%s\t%d\t%s\t%.2f\t%s\t%.2f\n", h.nom, h.cat, h.fec, h.tam, h.ori, h.vel);
    }

    fclose(fp);
    fclose(rep);
    printf("\nReporte guardado en %s\n", TXT);
}
