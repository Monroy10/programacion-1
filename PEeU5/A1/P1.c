#include <stdio.h>
#include <string.h>

void decabin() {
    int v, i = 0, j, a[32];
    printf("Ingrese el valor decimal: ");
    scanf("%d", &v);
    if(v == 0) printf("0");
    while(v > 0) {
        a[i] = v % 2;
        v = v / 2;
        i++;
    }
    printf("Valor convertido: ");
    for(j = i - 1; j >= 0; j--) {
        printf("%d", a[j]);
    }
    printf("\n");
}

void binadec() {
    char b[35];
    int d = 0, p = 1, l, i;
    printf("Ingrese la cantidad a convertir: ");
    scanf("%s", b);
    l = strlen(b);
    for(i = l - 1; i >= 0; i--) {
        if(b[i] == '1') {
            d = d + p;
        }
        p = p * 2;
    }
    printf("Equivalente en decimal: %d\n", d);
}

void decaoct() {
    int v, i = 0, j, a[32];
    printf("Ingrese el valor decimal: ");
    scanf("%d", &v);
    if(v == 0) printf("0");
    while(v > 0) {
        a[i] = v % 8;
        v = v / 8;
        i++;
    }
    printf("Valor convertido: ");
    for(j = i - 1; j >= 0; j--) {
        printf("%d", a[j]);
    }
    printf("\n");
}

void octadec() {
    char o[20];
    int d = 0, p = 1, l, i;
    printf("Ingrese la cantidad a convertir: ");
    scanf("%s", o);
    l = strlen(o);
    for(i = l - 1; i >= 0; i--) {
        if(o[i] >= '0' && o[i] <= '7') {
            d = d + (o[i] - '0') * p;
        }
        p = p * 8;
    }
    printf("Equivalente en decimal: %d\n", d);
}

void decahex() {
    int v, i = 0, j, a[32];
    printf("Ingrese el valor decimal: ");
    scanf("%d", &v);
    if(v == 0) printf("0");
    while(v > 0) {
        a[i] = v % 16;
        v = v / 16;
        i++;
    }
    printf("Valor convertido: ");
    for(j = i - 1; j >= 0; j--) {
        if(a[j] < 10)
            printf("%d", a[j]);
        else
            printf("%c", 'A' + a[j] - 10);
    }
    printf("\n");
}

void hexadec() {
    char h[20];
    int d = 0, p = 1, l, i;
    printf("Ingrese el codigo hexadecimal: ");
    scanf("%s", h);
    l = strlen(h);
    for(i = l - 1; i >= 0; i--) {
        if(h[i] >= '0' && h[i] <= '9')
            d = d + (h[i] - '0') * p;
        else if(h[i] >= 'A' && h[i] <= 'F')
            d = d + (h[i] - 'A' + 10) * p;
        else if(h[i] >= 'a' && h[i] <= 'f')
            d = d + (h[i] - 'a' + 10) * p;
        p = p * 16;
    }
    printf("Equivalente en decimal: %d\n", d);
}

int main() {
    int o;
    printf("--- MENU DE CONVERSIONES ---\n1. Decimal a Binario\n2. Binario a Decimal\n3. Decimal a Octal\n4. Octal a Decimal\n5. Decimal a Hexadecimal\n6. Hexadecimal a Decimal\nSeleccione una opcion: ");
    scanf("%d", &o);

    switch(o) {
        case 1: decabin(); break;
        case 2: binadec(); break;
        case 3: decaoct(); break;
        case 4: octadec(); break;
        case 5: decahex(); break;
        case 6: hexadec(); break;
        default: printf("Opcion invalida\n");
    }
    return 0;
}
