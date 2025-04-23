#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de teto por regi�o
#include <string.h> //biblioteca resposavel por cuidar das string

int registro() //fum��o responsavel por cadastrar usuarios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
    printf("Digite p CPF a ser cadastrado: "); //coletando informa��o do usuario
    scanf("%s", cpf); //%s refere-se a string
		
	strcpy(arquivo, cpf); //resposavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o aruivo e o "w" significa escrever 
	fprintf(file,cpf); //salva o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //salva o arqquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome); //salva o arqquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //salva o arqquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,sobrenome); //salva o arqquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //salva o arqquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,cargo); //salva o arqquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: "); //coletando informa��o do usuario para consulta
    scanf("%s", cpf); //%s refere-se a string
    
    FILE *file; //cria o arquivo
    file = fopen(cpf,"r"); //abre o arquivo
    
    if(file== NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");  //informando ao usuario que dado procurado n�o foi encontrado
	}
    
    while(fgets(conteudo, 20, file)!= NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: "); //quando as informa��es est�o cadastradas e foram encontradas
    	printf("%s", conteudo); 
    	printf("\n\n;");
	}
    
      system("pause"); // resposavel por pausar a tela 
    
}


int deletar()
{
	   char cpf[40];
	   
	   printf("Digite o CPF do usuario a ser deletado: "); //coletando dados do usuario para exclus�o
	   scanf("%s", cpf); //%s refere-se a string
	   
	   remove(cpf); //abre a fun��o deletar
	   
	   FILE *file; //cria o arquivo
	   file = fopen(cpf,"r"); //abre o arquivo
	   
	   if(file == NULL)
	   {
	   	 printf("O usuario n�o se encontra no sistema!\n"); //informando que nao a mais o dado cadastrado
	   	 system("pause"); // resposavel por pausar a tela
	   }
	   
}


int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // responsavel por limpar a tela
	
    	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	    printf("### cart�rio da EBAC ###\n\n"); // inicio do menu
	    printf("Escolha a op��o desejada do menu\n\n"); // escolha de op��es
	    printf("\t1-Registrar nomes\n"); //registra nomes
	    printf("\t2-Consultar nomes\n"); //consukta nomes
	    printf("\t3-Deletar nomes\n\n"); //deleta nomes
	    printf("\t4-sair do sistema\n\n"); //sai do sistema e volta para o menu
	    printf("Op��o: "); // fim do menu
	
	    scanf("%d", &opcao); //armazena a escolha do usuario
	
     	system("cls"); // responsavel por limpar a tela 
	
	
	switch(opcao) //inicio da sele��o
	{
		case 1:
		registro(); // chamada de fun��es
		system("pause"); // resposavel por pausar a tela 
		break; //encerra o case 1
		
		case 2:
		consulta(); //chamada de fun��es
		system("pause"); // resposavel por pausar a tela
		break; //encerra o case 2
		
		case 3:
		deletar(); //chamada de fun��es
		system("pause"); // resposavel por pausar a tela
		break; //encerra o case 3
		
		case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
		
		default:
		printf("Essa op��o n�o est� disponivel!"); //informando que n�o a mais fun��o
		system("pause"); // resposavel por pausar a tela
		break; //encerra o default 
	} //fim da sele��o
  }
}

