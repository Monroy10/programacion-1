#include <stdio.h>
#include <unistd.h>
int main(void) {
    for (int h = 0; h < 24; h++) {
        for (int m = 0; m < 60; m++) {
            for (int s = 0; s < 60; s++) {
                printf("\033[H\033[J");
                printf("%02d:%02d:%02d\n", h, m, s);
                usleep(1000);
            }
        }
    }
    printf("Despierta ya es otro dia\n");
    return 0;
}
