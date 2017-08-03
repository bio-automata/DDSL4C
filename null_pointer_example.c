/**
  Created by Rodrigo Cezar Silveira
  july 30, 2017
 */

/*
    Este simples exemplo fora elaborado na intenção de ilustrar a forma como ponteiros nulos podem 
    ser utilisados para referenciar diferentes tipos de dados, característica responsável por conferir 
    maior  flexibilidade às nossas funções e estruturas de dados.
 
    para maiores informações consulte a documentação disponível em: 
   */

#include <stdio.h>
int main(){  
  //variáveis de diferentes tipos
  int i;    
  char c;
  float f;
  
  //declaração do ponteiro nulo; 
  void *p;
    
  p = &i;   //ponteiro nulo referencia o endereço de memória da variável inteira
  
  //atribuindo um valor para o ponteiro, não podemos acessar ou definir seu conteúdo diretamente
  *((int*)p) = 2;   //primeiramente convertemos e então desreferenciamos (duas etapas em uma)
  printf("%d\n", i);    //acessa o valor da variável
  
   /*
      poderiamos ainda realizar este mesmo procedimento de uma forma diferente,
      realizando a conversão e o desreferenciamento em duas etapas distintas.
   */
  
  int* p_aux_int;   //declaramos um ponteiro auxiliar do tipo <<int*>>
  p_aux_int = (int*)p;  //convertemos o ponteiro nulo e o atribuimos ao ponteiro auxiliar
  *p_int = 2;   //desreferenciamos o ponteiro auxiliar
  printf("%d\n", i);
  
  p = &c;
  c = 'a';
  printf("%c\n", *((char*)p));  //convertemos o ponteiro para o tipo <<char*>> e então o desreferenciamos
  
  f = 3.1415;   
  p = &f;
  printf("%.4f\n", *((float*)p));
  
  return 0;
}

