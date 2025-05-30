#include <stdio.h>

// 1º teste online da cadeira de Programação Imperativa do ano letivo 2024/2025 da licenciatura em Engenharia Informática da Universidade do Minho

int main() {
    long x = 28, y = 2;
    int v = 10;
    char d = 's';
    int max_distance = 0;
    int current_distance = 0; 

    for (int t = 1; t <= 10000; t++) {
        if (t % 3 == 0 && t % 5 == 0) {           
            if (d == 'n') d = 'e';
            else if (d == 'e') d = 's';
            else if (d == 's') d = 'w';
            else d = 'n';
            current_distance = 0; 
        } else if (t % 3 == 0) {
            v += 2;
        } else if (t % 5 == 0) {
            v -= 1;
        } else {
            if (d == 'n') y += v;
            else if (d == 'e') x += v;
            else if (d == 's') y -= v;
            else x -= v;
            current_distance += v; 
            if (current_distance > max_distance) {
                max_distance = current_distance; 
            }
        }
    }

    printf("Posição final x: %ld\n", x);
    printf("Maior distância percorrida continuamente numa só direção: %d\n", max_distance);

    return 0;
}

// Resultado final: 2/2