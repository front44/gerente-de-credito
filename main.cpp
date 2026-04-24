#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct Cliente{
char nome[100];
char cpf[50];
char telefone [50];
char endereco[100];
char telefoneEmergencial[100];
float saldoDevedor;
int limiteCredito;
};

struct Cliente Clientes[100];
int totalClientes = 0;

void cadastrarCliente();
void listarClientes();
void buscarClientes();
void removerClientes();

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
    printf("3 - Buscar clientes\n");
    printf("4 - Remover clientes\n");
    printf("0 - Sair\n\n");
    printf("Escolha: ");

    scanf("%d", &opcao_menu);

    switch (opcao_menu) 
     {
     case 1:
      printf("Cadastrar Cliente\n");
      sleep(1);
      cadastrarCliente();
        break;

     case 2:
      printf("Listar Clientes\n");
      sleep(1);
      listarClientes();
        break;

     case 3:
      printf("Buscar Clientes\n");
      sleep(1);
      buscarClientes();
        break;
        
     case 4:
      printf("Buscar Cliente para remover\n");
      sleep(1);
      removerClientes();
        break;

     case 0 :
      printf("Saindo...\n");
      sleep(1);
        break;
    }
    
   
  } while (opcao_menu != 0);

return(0);
}

void cadastrarCliente()
{
  system("clear");
  printf("---Cadastro de Cliente---\n\n");
  printf("Digite os dados do cliente:\n");

  printf("Nome:\n");
  getchar();
  fgets(Clientes[totalClientes].nome, 100, stdin);

  printf("CPF:\n");
  scanf("%s", Clientes[totalClientes].cpf);
  getchar();

  printf("telefone:\n");
  fgets(Clientes[totalClientes].telefone, 50, stdin);

  printf("Endereço:\n");
  fgets(Clientes[totalClientes].endereco, 100, stdin);

  printf("telefone de emergencia:\n");
  fgets(Clientes[totalClientes].telefoneEmergencial, 50, stdin);

  totalClientes++;

  printf("Cliente cadastrado com sucesso!");
  
  getchar();
  getchar();
}

void listarClientes(){
  system("clear");
  printf("Lista de clientes:\n\n");
  for( int i = 0; i < totalClientes; i++){

    printf("Cliente %d\n" , i + 1);
    printf("Nome: %s\n" , Clientes[i].nome);
    printf("CPF: %s\n" , Clientes[i].cpf);
    printf("Telefone: %s\n" , Clientes[i].telefone);
    printf("Endereço: %s\n" , Clientes[i].endereco);
    printf("Telefone de emergencia: %s\n" , Clientes[i].telefoneEmergencial);
    printf("Saldo Devedor: %.2f\n" , Clientes[i].saldoDevedor);
    printf("Limite de credito: %d\n" , Clientes[i].limiteCredito);
  
  }
   getchar();
   getchar();
}

void buscarClientes(){
    char CPFbusca[50];

    system("clear");
    printf("---BUSCAR CLIENTE PELO CPF---\n\n");

    printf("Digite o CPF do cliente:\n");
    scanf("%s" , CPFbusca);

     for (int i = 0; i < totalClientes; i++) 
     {
       if (strcmp(CPFbusca , Clientes[i].cpf) == 0 )
        {
          printf("\nCliente encontrado!\n\n");
          printf("Nome: %s", Clientes[i].nome);
          printf("CPF: %s\n", Clientes[i].cpf);
          printf("Telefone: %s", Clientes[i].telefone);
          printf("Endereco: %s", Clientes[i].endereco);
          printf("Telefone emergencia: %s", Clientes[i].telefoneEmergencial);

            getchar();
            getchar();
            return;
        }
     }   
     printf("\nCliente nao encontrado!\n");
    getchar();
    getchar();
}

void removerClientes(){
   char CPFbusca[50];

   system("clear");
   printf("---Remover Clientes---\n\n");
   printf("Digirte o CPF do cliente desejado:\n");
   scanf("%s" , CPFbusca);

  for (int i = 0; i < totalClientes; i++)
  {
     if (strcmp(CPFbusca, Clientes[i].cpf)== 0)
     {
        for (int j = i; j < totalClientes - 1; j++)
        {
          Clientes[j] = Clientes[j + 1];
        }
        totalClientes--;
        printf("\nCliente removido com sucesso!\n");
        getchar();
        getchar();
        return;
     }
  }
  printf("\nCliente nao encontrado!\n");
  getchar();
  getchar();
}