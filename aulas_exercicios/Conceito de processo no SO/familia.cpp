// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: familia.cpp
// Objetivo: utilizar as funções getpid() e getppid()

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main ()
{

// declaração de variáveis
  pid_t pid;          // definindo um identificador de processo - inteiro longo
  int idadePai=0, idadeFilho1=0, idadeFilho2=0, idadeNeto1=0, idadeNeto2=0; 
  
   
  printf("Começando o programa Familia ... \n");
  
  printf("Começando o programa Familia ... \n");
  for(int i=0; i<14; i++) {
    idadePai++;
    printf( "\n PAI: meu PID é: %d e tenho %d anos de idade \n", getpid(), idadePai);
    sleep(1); 
  }
  
  
  pid = fork();   // dividindo o processo em dois

  switch(pid)
    {
    case -1:       // erro na abertura do processo filho
      exit(1);  
    case 0:        // execução do processo Filho
      for(int i=0; i<20; i++) {
         idadeFilho1++;
         printf( "\n FILHO1: meu PID é: %d e tenho %d anos de idade \n", getpid(), idadeFilho1);
         sleep(1); 
      }
      pid = fork();
      
      switch(pid)
       {
         case -1:       // erro na abertura do processo neto
          exit(1); 
         case 0:    // Primeiro neto
         for(int i=0; i<60; i++) {
           idadeNeto1++;
           printf( "\n Neto1: meu PID é: %d e tenho %d anos de idade \n", getpid(), idadeNeto1);
           sleep(1); 
         }
         break;
         default:    // Continuação do filho
         for(int i=20; i<60; i++) 
         {
           idadeFilho1++;
           printf( "\n Filho1: meu PID é: %d e tenho %d anos de idade \n", getpid(), idadeFilho1);
           sleep(1); 
         }
         break;
        }
      
    break;
    default:      // excução do processo Pai    
      // Código do PAI
      for(int i=14; i<16; i++) {
        idadePai++;
        printf( "\n PAI: meu PID é: %d e tenho %d anos de idade \n", getpid(), idadePai);
        sleep(1); 
      }
      pid = fork(); // segundo Filho
      
      switch(pid)
       {
         case -1:       // erro na abertura do processo filho
          exit(1); 
         case 0:    // Segundo Filho
         for(int i=0; i<25; i++) {
           idadeFilho2++;
           printf( "\n FILHO2: meu PID é: %d e tenho %d anos de idade \n", getpid(), idadeFilho2);
           sleep(1); 
      	 }
      	 pid = fork();
      	 
      	 switch(pid)
        {
         case -1:       // erro na abertura do processo neto
          exit(1); 
         case 0:    // Segundo neto
         for(int i=0; i<60; i++) {
           idadeNeto2++;
           printf( "\n NETO2: meu PID é: %d e tenho %d anos de idade \n", getpid(), idadeNeto2);
           sleep(1); 
         }
         break;
         default:    // Continuação do filho 2
         for(int i=25; i<60; i++) 
         {
           idadeFilho2++;
           printf( "\n FILHO2: meu PID é: %d e tenho %d anos de idade \n", getpid(), idadeFilho2);
           sleep(1); 
         }
         break;
        }
      	 
         break;
         default:    // Continuação do Pai
         for(int i=16; i<60; i++) {
           idadePai++;
           printf( "\n PAI: meu PID é: %d e tenho %d anos de idade \n", getpid(), idadePai);
           sleep(1); 
         }
         break;
        }
    break;
    }
    
    exit (0);

}
