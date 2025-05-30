#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
  char *nome;
  int nr;
  int nota;
} Aluno;

typedef struct cel {
  Aluno aluno;
  struct cel *prox;
} *Turma;

int adicionaAluno(Turma *t, char *nome, int nr, int nota) {
 Aluno novo_aluno;
 novo_aluno.nome = malloc(sizeof(char) * (strlen(nome) + 1));
 if (novo_aluno.nome == NULL) {
  return 1; 
 }
 strcpy(novo_aluno.nome, nome); 
 novo_aluno.nr = nr;
 novo_aluno.nota = nota;
 struct cel *nova_cel = malloc(sizeof(struct cel)); 
 if (nova_cel == NULL) {
  free(novo_aluno.nome);
  return 1; 
 }
 nova_cel->aluno = novo_aluno; 
 
 while (*t != NULL && (*t)->aluno.nota < nota) { 
  t = &((*t)->prox);
 }
 
 nova_cel->prox = *t;
 *t = nova_cel;
 return 0; 
}

// Função para imprimir a turma
void imprimeTurma(Turma t) {
    while (t != NULL) {
        printf("Nome: %s, Número: %d, Nota: %d\n", t->aluno.nome, t->aluno.nr, t->aluno.nota);
        t = t->prox;
    }
}

// Função para liberar a memória da turma
void liberaTurma(Turma t) {
    while (t != NULL) {
        Turma temp = t;
        t = t->prox;
        free(temp->aluno.nome);
        free(temp);
    }
}

int main(void) {
    Turma turma = NULL;

    // Adiciona alguns alunos
    adicionaAluno(&turma, "Joao", 1, 15);
    adicionaAluno(&turma, "Maria", 2, 18);
    adicionaAluno(&turma, "Ana", 3, 12);
    adicionaAluno(&turma, "Pedro", 4, 14);

    // Imprime a turma
    printf("Turma ordenada por nota:\n");
    imprimeTurma(turma);

    // Libera a memória alocada
    liberaTurma(turma);

    return 0;
}

