#include <stdio.h>
#include <string.h>

#define DAT "cuentas.bin"
#define TXT "reporte.txt"

struct cuenta {
    int cuenta;
    char nombre[30];
    float balance;
};

void alta(void);
int buscar(int cta);
int subMenu(void);
void verRep(int op);

int main() {
    int op, sub;

    do {
        printf("\n--- CONTROL DE CUENTAS ---\n");
        printf("1. Agregar cuenta\n");
        printf("2. Reportes\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                alta();
                break;
            case 2:
                do {
                    sub = subMenu();
                    if (sub >= 1 && sub <= 4) {
                        verRep(sub);
                    } else if (sub != 5) {
                        printf("Opcion no valida.\n");
                    }
                } while (sub != 5);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (op != 3);

    return 0;
}

int subMenu(void) {
    int sub;
    printf("\n--- MENU DE REPORTES ---\n");
    printf("1. Cuentas con balance 0\n");
    printf("2. Cuentas con balance de credito\n");
    printf("3. Cuentas con balance de debito\n");
    printf("4. Reporte general\n");
    printf("5. Salir\n");
    printf("Opcion: ");
    scanf("%d", &sub);
    return sub;
}

int buscar(int cta) {
    FILE *fp = fopen(DAT, "rb");
    struct cuenta reg;

    if (fp == NULL) {
        return 0;
    }

    while (fread(&reg, sizeof(struct cuenta), 1, fp) == 1) {
        if (reg.cuenta == cta) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void alta(void) {
    struct cuenta reg;
    FILE *fp;

    printf("\nNo. cuenta: ");
    scanf("%d", &reg.cuenta);

    if (buscar(reg.cuenta)) {
        printf("La cuenta ya existe.\n");
        return;
    }

    printf("Nombre: ");
    scanf(" %29[^\n]", reg.nombre);

    printf("Balance: ");
    scanf("%f", &reg.balance);

    fp = fopen(DAT, "ab");
    if (fp == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fwrite(&reg, sizeof(struct cuenta), 1, fp);
    fclose(fp);
    printf("Cuenta guardada.\n");
}

void verRep(int op) {
    FILE *fp = fopen(DAT, "rb");
    FILE *rep;
    struct cuenta reg;
    int n0 = 0, nc = 0, nd = 0;
    float sc = 0.0, sd = 0.0;

    if (fp == NULL) {
        printf("No hay cuentas registradas.\n");
        return;
    }

    rep = fopen(TXT, "w");
    if (rep == NULL) {
        printf("No se pudo crear el archivo de reporte.\n");
        fclose(fp);
        return;
    }

    if (op == 1) {
        printf("\nReporte de cuentas con balance 0\n");
        fprintf(rep, "Reporte de cuentas con balance 0\n");
    } else if (op == 2) {
        printf("\nReporte de cuentas con balance de credito\n");
        fprintf(rep, "Reporte de cuentas con balance de credito\n");
    } else if (op == 3) {
        printf("\nReporte de cuentas con balance de debito\n");
        fprintf(rep, "Reporte de cuentas con balance de debito\n");
    } else {
        printf("\nReporte general\n");
        fprintf(rep, "Reporte general\n");
    }

    printf("%-12s %-25s %s\n", "No. cuenta", "Nombre", "Balance");
    fprintf(rep, "%-12s %-25s %s\n", "No. cuenta", "Nombre", "Balance");

    while (fread(&reg, sizeof(struct cuenta), 1, fp) == 1) {
        if (reg.balance == 0) {
            n0++;
            if (op == 1 || op == 4) {
                printf("%-12d %-25s %.2f\n", reg.cuenta, reg.nombre, reg.balance);
                fprintf(rep, "%-12d %-25s %.2f\n", reg.cuenta, reg.nombre, reg.balance);
            }
        } else if (reg.balance < 0) {
            nc++;
            sc += reg.balance;
            if (op == 2 || op == 4) {
                printf("%-12d %-25s %.2f\n", reg.cuenta, reg.nombre, reg.balance);
                fprintf(rep, "%-12d %-25s %.2f\n", reg.cuenta, reg.nombre, reg.balance);
            }
        } else {
            nd++;
            sd += reg.balance;
            if (op == 3 || op == 4) {
                printf("%-12d %-25s %.2f\n", reg.cuenta, reg.nombre, reg.balance);
                fprintf(rep, "%-12d %-25s %.2f\n", reg.cuenta, reg.nombre, reg.balance);
            }
        }
    }

    if (op == 1) {
        printf("\nTotal cuentas: %d\n", n0);
        fprintf(rep, "\nTotal cuentas: %d\n", n0);
    } else if (op == 2) {
        printf("\nTotal cuentas: %d\nBalance total en creditos: %.2f\n", nc, sc);
        fprintf(rep, "\nTotal cuentas: %d\nBalance total en creditos: %.2f\n", nc, sc);
    } else if (op == 3) {
        printf("\nTotal cuentas: %d\nBalance total en debito: %.2f\n", nd, sd);
        fprintf(rep, "\nTotal cuentas: %d\nBalance total en debito: %.2f\n", nd, sd);
    } else if (op == 4) {
        printf("\nTotal cuentas con balance 0: %d\n", n0);
        printf("Total cuentas con balance de credito: %d\n", nc);
        printf("Total cuentas con balance de debito: %d\n\n", nd);
        printf("Balance total en creditos: %.2f\n", sc);
        printf("Balance total en debito: %.2f\n", sd);

        fprintf(rep, "\nTotal cuentas con balance 0: %d\n", n0);
        fprintf(rep, "Total cuentas con balance de credito: %d\n", nc);
        fprintf(rep, "Total cuentas con balance de debito: %d\n\n", nd);
        fprintf(rep, "Balance total en creditos: %.2f\n", sc);
        fprintf(rep, "Balance total en debito: %.2f\n", sd);
    }

    fclose(fp);
    fclose(rep);
}
