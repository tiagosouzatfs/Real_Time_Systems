/* 
 Descria��o:
 - Programa que cria um vetor de threads.
 Compilar: g++ -pthread -o nomeExecutavel nomeDesseArquivo
*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 10  // quantidade d ethreads a serem criadas

// Fun��o auxiliar da thread
void* funcaoHelper(void* idThread) {
  sleep(3);
  printf("Vai finalizar a thread: %d\n", idThread);
  //Finalizar com o c�digo de retorno igual ao idThread
  pthread_exit((void *) idThread);
}  

int main(int argc, char *argv[]){

  //Vetor de threads
  pthread_t vetorThreads[NUM_THREADS];

  //Status de cria��o
  int statusRetorno;

  //Status de finaliza��o da thread
  void * statusFinalizacao;

  //Loop para criar as threads
  for(int i=0; i < NUM_THREADS; i++){
      printf("Main - criando a thread: %d\n", i);
      //Criar a thread i
      statusRetorno = pthread_create(&vetorThreads[i], NULL, funcaoHelper, (void *)i);
      //Verificando a exist�ncia de erros na cria��o
      if (statusRetorno){
         printf("Erro ao criar a thread: %d\n", statusRetorno);
         exit(-1);
      }
   }
    
  //Realizando um join com todas as threads
  for (int i=0; i < NUM_THREADS; i++){
      //Main fica bloqueado at� vetorThreads[i] finalizar
      statusRetorno = pthread_join(vetorThreads[i], &statusFinalizacao);
       if (statusRetorno){
         printf("Erro ao executar thread_join: %d\n", statusRetorno);
         exit(-1);
      }
      printf("Join finalizado para a thread: %d com o codigo: %d\n", i, statusFinalizacao);
   }
   printf("Finalizando o m�todo main\n");
   pthread_exit(NULL);
}
