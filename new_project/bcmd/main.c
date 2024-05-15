/*
 *    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2024 reisvictor1 <reisvictor448@gmail.com>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative work from SYSeg (https://gitlab.com/monaco/syseg)
 *  and contains modifications carried out by the following author(s):
 *  reisvictor1 <reisvictor448@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include "bios.h"
#include "utils.h"

#define PROMPT "$ "		/* Prompt sign.      */
#define SIZE 20			/* Read buffer size. */

char buffer[SIZE];		/* Read buffer.      */

void* allocateLargestBlock(size_t* size){

  size_t s0,s1;
  void *p;

  s0 = ~(size_t)0 ^ (~(size_t)0 >> 1);

  while(s0 && (p = malloc(s0)) == NULL){
    s0 >> 1;
  }

  if(p) free(p);

  s1 = s0 >> 1;

  while(s1){
    if((p = malloc(s0 + s1)) != NULL){
      s0 += s1;
      free(p);
    }

    s1 >>= 1;
  }

  while(s0 && (p = malloc(s0)) == NULL){
    s0 ^= s0 & -s0;
  }

  *size = s0;
  return p;

}

size_t print_free_current_memory(void){

  size_t total = 0;
  void *pFirst = NULL;
  void *pLast = NULL;

  for(;;){
    size_t biggest;
    void *p = allocateLargestBlock(&biggest);

    if(biggest < sizeof(void*)){
      if(p != NULL) free(p);

      break;
    }

    *(void **) p = NULL;

    total += biggest;
    if(pFirst == NULL){
      pFirst = p;
    }
   
    if(pLast != NULL) {
      *(void **) pLast = p;
    }

    pLast = p;

  }

  while(pFirst != NULL){
    void* p = *(void **) pFirst;
    free(pFirst);
    pFirst = p; 
  }

  return total;

}

int main()
{
  clear();
  
  println  ("Boot Command 1.0");

  while (1)
    {
      print(PROMPT);		/* Show prompt.               */
      readln(buffer);		/* Read use input.            */

      if (buffer[0])		/* Execute built-in command.  */
	{
    if(!strcmp(buffer, 'printRAM')){
      printf('Memória disponível: %zu\n', print_free_current_memory());
    } else if (!strcmp(buffer,"help"))
	    println("A Beattles's song.");
	  else 
	    println("Unkown command.");
	}
    }
  
  return 0;

}

