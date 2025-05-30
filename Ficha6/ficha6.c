#define Max 100

/*--------------------------------------- Ficha 6 ----------------------------------------*/

// Exercicio 2
typedef struct staticQueue {
int front;
int length;
int values [Max];
} QUEUE, *SQueue;

// a)
void SinitQueue (SQueue q) {
    q -> front = 0;
    q -> length = 0;
}

// b)
int SisEmptyQ (SQueue q) {
    return (q -> length == 0);
}

// c) 
int Senqueue (SQueue q, int x) {
    int r = 0 , p;
    if (q -> length == Max) r = 1;
    else {
        p = (q -> front + q -> length) % Max;
        q -> values[p] = x;
        q -> length ++;
    }
}

//d)
int Sdequeue (SQueue q, int *x) {
    if (q -> length == 0) return 1;
    *x = q -> values[q -> front];
    q -> length --;
    q -> front ++;
    if (q -> front == Max) q -> front = 0;
    return 0;
}

// e)
int Sfront (SQueue q, int *x) {
    if (q -> length == 0) return 1;
    *x = q -> values[q -> front];
    return 0;
}