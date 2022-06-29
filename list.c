#include "list.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct list  //criacao da estrutura list
{
    int *p;
    unsigned int maxi, size;
};

LIST *list_create(unsigned int max)
{
    LIST* L;
    L = (LIST*)malloc(sizeof(LIST));
    L->maxi = max;
    L->size = 0; //inicialmente nao ha elementos
    L->p = (int*)malloc(max*sizeof(int)); //aloca espaco para o vetor de int
    return L;
}

void list_destroy(LIST *list)  //destroi a lista
{
    free(list);
}

unsigned int list_max(LIST *list)   //retorna o maior valor possivel da lista
{
    return list->maxi;
}

unsigned int list_size(LIST *list)   //retorna o tamanho atual da lista
{
    return list->size;
}

void list_print(LIST *list, unsigned int idx)   //printa o elemento em posicao determinada
{
    int value = list_value(list, idx);
    printf("%d\n", value);
}



void list_insert(LIST *list, int value, unsigned int k)   //insere o int value na posicao k
{
    if (list->size >= list->maxi || k > list->size)
    {
        printf("ERRO!\n");
    }
    else
    {
        int i;
        list->p[k] = value;
        list->size++;
    }
}

void list_delete(LIST *list, unsigned int k)   //deleta elemento em posicao determinada
{
    if (k >= list->size) printf("ERRO!\n"); //absurdo
    else
    {
        for(int i = k; i < list->size - 1; i++)
        {
            list->p[i] = list->p[i+1]; //recursivamente alteramos os elementos da k-esima posicao em diante
        }
        list->size--; //o numero de elementos da lista diminui em uma unidade
    }
}

int list_value(LIST *list, unsigned int idx)   //retorna o valor de posicao determinada
{
    return(list->p[idx]);
}

void list_change(LIST *list, int value, unsigned int idx)   //altera o valor em uma posicao determinada
{
    if(idx >= list->size)  //absurdo
    {
        printf ("ERRO!\n");
    }
    list->p[idx] = value;
}


