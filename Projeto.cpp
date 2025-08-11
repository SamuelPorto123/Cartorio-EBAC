#include <stdio.h>  //Biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o.
#include <string.h> //Biblioteca de armazenamento de Strings

int registro()
{
    
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s",cpf);
    
    strcpy(arquivo,cpf);
    
    FILE *file; // cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // cria o arquivo
    fprintf(file,cpf); // salva o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("\nDigite o Nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen (arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
    file= fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("\nDigite o Sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file= fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file= fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("\nDigite o Cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file= fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
    file= fopen(arquivo,"a");
    fprintf(file,".");
    fclose(file);
    
    system("pause");
    
}

int consulta()
{
    char cpf[40];
    char conteudo[200];
    
    setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
	{
		printf("N�o foi possivel encontrar esse CPF cadastrado! \n");
	}
    
    while(fgets(conteudo, 200, file) !=NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
}

int deletar(){
    printf("Voc� escolheu Deletar Nomes!\n\n");
	system("pause");
}

int main(){


	int opcao=0; //definindo vari�veis
    int laco=1;  //definindo vari�veis para la�o
    
    for(laco=1;laco==1;)
	{
	
	  system("cls");
	
	  setlocale(LC_ALL, "Portuguese");
	
      printf("### Cart�rio da EBAC ###\n\n"); //Inicio do Menu
	  printf("Escolha a op��o desejada de menu:\n\n");
	  printf("\t1 Registrar Nomes\n");
	  printf("\t2 Consultar Nomes\n");
	  printf("\t3 Deletar Nomes\n");
	  printf("\t4 Sair do Sistema\n\n");
	  printf("Op��o: "); //Fim do menu
	
	  scanf("%d", &opcao); //Armazenamento de dados do usu�rio.
	
	  system("cls");
	
	  switch(opcao) // Inicio da Sele��o
	{
		case 1:
		registro();
		break;
		
	    case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("\nObrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o est� Dispon�vel\n\n");
		system("pause");
		break;	// Fim da Sele��o
	}


}

}

		
	
 
