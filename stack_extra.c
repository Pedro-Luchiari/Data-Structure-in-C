#include "stack_extra.h"
#include<stdio.h>
#include<assert.h>


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
