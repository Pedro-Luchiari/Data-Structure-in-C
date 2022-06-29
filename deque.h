/* N�o modifique este arquivo. */

#ifndef DEQUE_H
#define DEQUE_H

typedef struct deque DEQUE;

/*
 * Retorna um deque rec�m-alocada.
 */
DEQUE *deque_create(void);

/*
 * Destr�i um deque previamente criado, liberando toda sua mem�ria.
 */
void deque_destroy(DEQUE *deque);

/*
 * Limpa o deque, removendo todos os elementos.
 */
void deque_empty(DEQUE *deque);

/*
 * Imprime todos os elementos dp deque na mesma linha separados por espa�o.
 * Ao final do deque, um '\n' � escrito.
 */
void deque_print(const DEQUE *deque);

/*
 * Retorna o primeiro elemento do deque.
 */
int deque_first(const DEQUE *deque);

/*
 * Retorna o �ltimo elemento do deque.
 */
int deque_last(const DEQUE *deque);

/*
 * Insere um novo elemento `element` no in�cio do deque.
 */
void deque_insertFirst(DEQUE *deque, int element);

/*
 * Insere um novo elemento `element` no fim do deque.
 */
void deque_insertLast(DEQUE *deque, int element);

/*
 * Remove o primeiro elemento do deque.
 */
void deque_removeFirst(DEQUE *deque);

/*
 * Remove o �ltimo elemento do deque.
 */
void deque_removeLast(DEQUE *deque);

/*
 * Retorna o n�mero de elementos do deque.
 */
int deque_size(const DEQUE *deque);


#endif // DEQUE_H
