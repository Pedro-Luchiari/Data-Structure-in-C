/* Não modifique este arquivo. */

#include "stack_extra.h"

#include <stdio.h>
#include<assert.h>

typedef struct stack STACK;

struct stack
{
    int elem;
    STACK *prox;
};

STACK *stack_create(void)
{
    STACK *pilha;
    pilha = (STACK*)malloc(sizeof(STACK));
    assert (pilha != NULL);
    pilha->prox = NULL;
    return pilha;
}

void stack_destroy(STACK *pilha)
{
    STACK *aux;
    while(pilha->prox != NULL)
    {
        aux = pilha->prox;
        pilha->prox = aux->prox;
        free(aux);
    }
    free(pilha);
}

bool stack_isEmpty(const STACK *pilha)
{
    if(pilha->prox == NULL) return true;
    else return false;
}

int stack_top(const STACK *pilha)
{
    if(pilha->prox != NULL) return pilha->prox->elem;
    else printf("ERRO: pilha vazia");
}

void stack_push(STACK *pilha, int element)
{
    STACK *aux;
    aux = (STACK*)malloc(sizeof(STACK));
    aux->prox = pilha->prox;
    pilha->prox = aux;
    aux->elem = element;
}

void stack_pop(STACK *pilha)
{
    STACK *aux;
    if(pilha->prox != NULL)
    {
        aux = pilha->prox;
        pilha->prox = aux->prox;
        free(aux);
    }
    else printf("Pilha vazia\n");
}


static void check_stack(STACK *stack) {
  while (!stack_isEmpty(stack))
    printf("%d ", stack_top(stack)), stack_pop(stack);
  printf("\n");
}

void stack_printTopDown(STACK *pilha)
{
    STACK *P = stack_create();
    while(!stack_isEmpty(pilha))
    {
        printf("%d ", stack_top(pilha));
        stack_push(P, stack_top(pilha));
        stack_pop(pilha);
    }
    while(!stack_isEmpty(P))
    {
        stack_push(pilha, stack_top(P));
        stack_pop(P);
    }
    stack_destroy(P);
    printf("\n");
}


    STACK *stack_reverse(STACK *pilha)
{
    STACK *P = stack_create();
    STACK *Pi = stack_create();
    while(!stack_isEmpty(pilha))
    {
        stack_push(P, stack_top(pilha));
        stack_push(Pi, stack_top(pilha));
        stack_pop(pilha);
    }
    while(!stack_isEmpty(Pi))
    {
        stack_push(pilha, stack_top(Pi));
        stack_pop(Pi);
    }
    stack_destroy(Pi);
    return P;
}

void stack_printBottomUp(STACK *pilha)
{
    STACK *P = stack_reverse(pilha);
    stack_printTopDown(P);
}

void stack_stack(STACK *a, STACK *b)
{
    STACK *c = stack_create();
    c = stack_reverse(b);
    while(!stack_isEmpty(c))
    {
        stack_push(a, stack_top(c));
        stack_pop(c);
    }
    while(!stack_isEmpty(b))
    {
        stack_pop(b);
    }
}


int main() {

  char cmd;
  int element, size_a, size_b;
  STACK *a, *b;

  while (scanf("%c", &cmd) != EOF) {

    switch (cmd) {
    case 't':
      a = stack_create();

      scanf("%d", &size_a);
      while (size_a-- > 0)
        scanf("%d", &element), stack_push(a, element);

      stack_printTopDown(a);
      check_stack(a);
      stack_destroy(a);

      break;

    case 'b':
      a = stack_create();

      scanf("%d", &size_a);
      while (size_a-- > 0)
        scanf("%d", &element), stack_push(a, element);

      stack_printBottomUp(a);
      check_stack(a);
      stack_destroy(a);

      break;

    case 'r':
      a = stack_create();

      scanf("%d", &size_a);
      while (size_a-- > 0)
        scanf("%d", &element), stack_push(a, element);

      b = stack_reverse(a);

      check_stack(b);
      check_stack(a);

      stack_destroy(b);
      stack_destroy(a);

      break;

    case 's':
      a = stack_create();
      b = stack_create();

      scanf("%d %d", &size_a, &size_b);

      while (size_a-- > 0)
        scanf("%d", &element), stack_push(a, element);

      while (size_b-- > 0)
        scanf("%d", &element), stack_push(b, element);

      stack_stack(a, b);

      check_stack(a);
      check_stack(b);

      stack_destroy(a);
      stack_destroy(b);

      break;
    }
  }

  return 0;
}
