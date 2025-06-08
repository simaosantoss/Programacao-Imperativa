#define Max 100

/*--------------------------------------- Ficha 6 ----------------------------------------*/

// Exercicio 1

typedef struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

// a)

void SinitStack (SStack s)
{
    s->sp = 0;
}

// b) 
int SisEmpty (SStack s)
{
    return s->sp == 0;
}

// c)
int Spush (SStack s, int x)
{
    if (s->sp == Max) // sp já aponta para o máximo (stack cheia)
            return 1;

    else
    {
        s->values[s->sp] = x;
        s->sp++; // Avança para a próxima posição
        return 0;
    }
}

// d)
int Spop (SStack s, int *x)
{
    if (s->sp == 0) //stack vazia
        return 1;

    else
    {
        s->sp--;               // recua o pointer, para apontar para o topo real
        *x = s->values[s->sp]; // guarda o valor do topo (que está agora em s->sp)
        return 0;
    }
}

// e) 

int Stop (SStack s, int *x)
{
    if (s->sp == 0)
        return 1;

    else
    {
        *x = s->values[s->sp - 1];
        return 0;
    }
}

// Exercicio 2
typedef struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;

// a)
void SinitQueue (SQueue q) 
{
    q->length = 0;
    q->front = 0;
}

// b)
int SisEmptyQ (SQueue q)
{
    return (q->length == 0);
}

// c)
int Senqueue (SQueue q, int x)
{
    int p; 

    if (q->length == Max)
        return 1;

    else
    {
        p = (q->front + q->length) % Max;
        q->values[p] = x;
        q->length++;
        return 0;
    }
}

// d) 
int Sdequeue (SQueue q, int *x) 
{
    if (q->length == 0)
        return 1;

    *x = q->values[q->front];
    q->front = (q->front + 1) % Max;
    q->length--;

    return 0; 
}

// e)
int Sfront(SQueue q, int *x) 
{
    if (q->length == 0)
        return 1;

    *x = q->values[q->front];
    return 0;
}
