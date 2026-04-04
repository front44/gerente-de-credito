#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  int opcao_menu;

  printf("Carregando sistema...\n");
  fflush(stdout);

  sleep(2);// aguarda 2 segundos
  system("clear");

  do{  
    system("clear");
    printf ("!!!Sistema de emprestimos iniciado!!!\n\n");
    printf ("1 - Cadastrar Cliente\n");
    printf("2 - listar clientes\n");
    printf("0 - Sair\n\n");
    printf("Escolha: ");

    scanf("%d", &opcao_menu);

    switch (opcao_menu) 
     {
     case 1:
      printf("Cadastrar Cliente\n");
      sleep(1);
        break;

     case 2:
      printf("Listar Clientes\n");
      sleep(1);
        break;

     case 0 :
      printf("Saindo...\n");
      sleep(1);
        break;
    }
    
   
} while (opcao_menu != 0);

return(0);

}