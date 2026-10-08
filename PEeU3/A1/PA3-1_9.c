#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char n[20] = "";
    int m = 0;
    int a = 0;

    printf("Introduce el dia de la semana: ");
    scanf("%19s", n);

    a = strlen(n);

    while (m <= a) {
        n[m] = tolower(n[m]);
        m++;
    }

    if (strcmp(n, "lunes") == 0) {
        printf("Es inicio de semana.\n");
        return 0;
    }

    if (strcmp(n, "sabado") == 0 || strcmp(n, "domingo") == 0) {
        printf("Es fin de semana.\n");
        return 0;
    }

    printf("Estas entre semana.\n");

    return 0;
}
