#include "list.h"
#include <assert.h>
#include <stdio.h>

int main()
{
  unsigned int max;  // m�ximo de elementos no TAD

  // Auxiliares para a interface com o usu�rio
  char cmd = 0;       // comando do usu�rio
  int valor;          // par�metros do comando
  unsigned int idx;   // par�metros do comando

  assert(scanf("%u", &max) == 1);  // de acordo com 'https://en.cppreference.com/w/c/io/fscanf'
  assert(max > 0);

  // Criar o TAD com o n�mero m�ximo solicitado
  LIST *list = list_create(max);
  assert(list != NULL);


  // Interface com o usu�rio
  while (cmd != '0' && scanf(" %c", &cmd) != EOF)
  {

    switch (cmd)
    {
    case 'q':
      printf("%u\n", list_size(list));
      break;

    case '0':
      break;

    case 'a':   // a <valor> <idx>
      assert( scanf(" %d %u", &valor, &idx) == 2 );
      list_change (list, valor, idx);
      break;

    case 'i':   // i <valor> <idx>
      assert( scanf(" %d %u", &valor, &idx) == 2 );
      list_insert (list, valor, idx);
      break;

    case 'd':   // d <idx>
      assert( scanf(" %u", &idx) == 1 );
      list_delete (list, idx);
      break;

    case 'p':   // p <idx>
      assert( scanf(" %u", &idx) == 1 );
      list_print(list, idx);
      break;

    default:
      // pode ser incluido uma mensagem de opera��o inv�lida
      printf("Operacao invalida\n");
      break;
    }
  }



  return 0;
}
