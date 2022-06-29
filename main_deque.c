/* Não modifique este arquivo. */

#include "deque.h"

#include <assert.h>
#include <stdio.h>

typedef struct noh noh;
struct noh{
    int elem;
    noh* prev;
    noh* prox;
};

struct deque{ /*lembrar que DEQUE = struct deque*/
    noh* ini;
    noh* fim;
};


DEQUE *deque_create(){
    DEQUE* O;
    O = (DEQUE*)malloc(sizeof(DEQUE));
    assert(O != NULL);
    O->ini = (noh*)malloc(sizeof(noh));
    assert(O->ini != NULL);
    O->ini->prev = NULL;
    O->ini->prox = NULL;
    O->fim = O->ini;
    return O;
}

void deque_empty(DEQUE *deque){
    noh* aux1, *aux2;
    while(deque->fim != deque->ini){
        aux1 = deque->fim;
        aux2 = deque->fim->prev;
        deque->fim = aux2;
        free(aux1);
        aux2->prox = NULL;
    }
}

void deque_destroy(DEQUE* deque){
     noh* aux1, *aux2;
    while(deque->fim != deque->ini){
        aux1 = deque->fim;
        aux2 = deque->fim->prev;
        deque->fim = aux2;
        free(aux1);
        aux2->prox = NULL;
    }
    free(aux2);
    free(deque);
}

void deque_print(const DEQUE *deque){
    noh* aux = deque->ini->prox;
    while(aux != NULL){
        printf("%d ", aux->elem);
        aux = aux->prox;
    }
    printf("\n");
}

int deque_first(const DEQUE *deque){
    return (deque->ini->prox->elem);
}

int deque_last(const DEQUE *deque){
    return (deque->fim->elem); //antes estava deque->fim->prev->elem
}

void deque_insertLast(DEQUE *deque, int element){
    noh* aux;
    aux = (noh*)malloc(sizeof(noh));
    deque->fim->prox = aux;
    aux->prev = deque->fim;
    deque->fim = aux;
    aux->prox = NULL;
    aux->elem = element;
}

void deque_insertFirst(DEQUE *deque, int element){
    noh* aux;
    aux = (noh*)malloc(sizeof(noh));
    if(deque->ini->prox == NULL){
        deque->ini->prox = aux;
        aux->prox = NULL;
        aux->prev = deque->ini;
        aux->elem = element;
        deque->fim = aux;
    }
    else{
        deque->ini->prox->prev = aux;
        aux->prox = deque->ini->prox;
        deque->ini->prox = aux;
        aux->prev = deque->ini;
        aux->elem = element;
    }
}

void deque_removeLast(DEQUE *deque){
    deque->fim = deque->fim->prev;
    free(deque->fim->prox);
    deque->fim->prox = NULL;
}

void deque_removeFirst(DEQUE *deque){
    deque->ini = deque->ini->prox;
    free(deque->ini->prev);
    deque->ini->prev = NULL;
}

int deque_size(const DEQUE *deque){
    int i = 0;
    noh* aux = deque->ini->prox;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}





int main() {
  char cmd;
  int top = 0;
  DEQUE *deques[100];

  int element;
  char pos;

  while (scanf("%c", &cmd) != EOF) {
    assert(top >= 0);
    assert(top < 100);

    switch (cmd) {
    case 'c':
      deques[top++] = deque_create();
      break;

    case 'd':
      deque_destroy(deques[--top]);
      break;

    case 'e':
      deque_empty(deques[top - 1]);
      break;

    case 'p':
      deque_print(deques[top - 1]);
      break;

    case 'a':
      scanf("%c", &pos);
      printf("%d\n", (pos == 'f' ? deque_first : deque_last)(deques[top - 1]));
      break;

    case 'i':
      scanf("%c %d", &pos, &element);
      (pos == 'f' ? deque_insertFirst : deque_insertLast)(deques[top - 1],
                                                          element);
      break;

    case 'r':
      scanf("%c", &pos);
      (pos == 'f' ? deque_removeFirst : deque_removeLast)(deques[top - 1]);
      break;

    case 's':
      printf("%d\n", deque_size(deques[top - 1]));
      break;
    }
  }

  return 0;
}
