#include<stdio.h>
#include<string.h>
int main() {
    int o, v, i, j, d=0, l, p, b;
    char h[20];
    int a[32];
    printf("--- MENU DE CONVERSIONES ---\n1. Decimal a Binario\n2. Binario a Decimal\n3. Decimal a Octal\n4. Octal a Decimal\n5. Decimal a Hexadecimal\n6. Hexadecimal a Decimal\nSeleccione una opcion: ");
    scanf("%d", &o);
    if(o==1 || o==3 || o==5) {
        printf("Ingrese el valor decimal: ");
        scanf("%d", &v);
        b = 2;
        if(o==3) b = 8;
        if(o==5) b = 16;
        i = 0;
        if(v==0) printf("0");
        while(v>0) {
            a[i] = v % b;
            v = v / b;
            i++;
    }
        printf("Valor convertido: ");
        for(j=i-1; j>=0; j--) {
            if(a[j]<10)
                printf("%d", a[j]);
            else
                printf("%c", 'A' + a[j] - 10);
    }
        printf("\n");
    } else if(o==2 || o==4) {
        printf("Ingrese la cantidad a convertir: ");
        scanf("%d", &v);
        b = (o==2)? 2 : 8;
        p = 1;
        while(v>0) {
            d = d + (v%10)*p;
            v = v / 10;
            p = p * b;
    }
        printf("Equivalente en decimal: %d\n", d);
    } else if(o==6) {
        printf("Ingrese el codigo hexadecimal: ");
        scanf("%s", h);
        l = strlen(h);
        p = 1;
        for(i=l-1; i>=0; i--) {
            if(h[i]>='0' && h[i]<='9')
                d = d + (h[i]-'0')*p;
            else if(h[i]>='A' && h[i]<='F')
                d = d + (h[i]-'A'+10)*p;
            else if(h[i]>='a' && h[i]<='f')
                d = d + (h[i]-'a'+10)*p;
            p = p * 16;
    }
        printf("Equivalente en decimal: %d\n", d);
    }
    return 0;
}
