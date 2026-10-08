#include <stdio.h>
#include <math.h>

typedef struct {
    float X;
    float Y;
} Punto;

int main() {
    Punto x1, y1;
    Punto x2, y2;
    float dx, dy, dis;

    printf("Introduce la ubicacion del primer punto (x y): ");
    scanf("%f %f", &x1.X, &y1.Y);

    printf("Introduce la ubicacion del segundo punto (x y): ");
    scanf("%f %f", &x2.X, &y2.Y);

    dx = x2.X - x1.X;
    dy = y2.Y - y1.Y;
    dis = sqrt(pow(dx, 2) + pow(dy, 2));

    printf("La distancia medida entre (%f, %f) y (%f, %f) resulta en: %.2f\n", x1.X, y1.Y, x2.X, y2.Y, dis);

    return 0;
}
