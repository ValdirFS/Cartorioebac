#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o e mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o das vari�ves/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40]; 
	char cargo[40];
	//Final da cria��o das vari�ves/string
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando as informa��es dos usu�rios
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "w" seguinifica escrever
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ","); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando as informa��es dos usu�rios
	scanf("%s" ,nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, nome); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ","); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando as informa��es dos usu�rios
	scanf("%s" ,sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, sobrenome); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ","); //salvo o valor da vari�ve
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando as informa��es dos usu�rios
	scanf("%s" , cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, cargo); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause");
	  	
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
    char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s" ,cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado. \n");
	}
   
   	while(fgets(conteudo, 200, file) != NULL)
   	{
   		printf("\n essas s�o as informa��es do usu�rio: ");
   		printf("%s", conteudo);
   		printf("\n\n");
	   }
	   
	   system("pause");
	   
	   
}

int deletar() //Fun��o respons�vel por deletar os usu�rios do sistema
{
    char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usu�rio n�o se encontra no sistema Porque j� foi Deletado! . \n");
		system("pause");
	}
	
		
}



int main()
{
	int opcao=0; //Definindo as vari�ves
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); //Respons�vel por limpar a tela
	
	    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	    printf(" ### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Opcao: ");//Final do menu
	
	    scanf("%d", &opcao); //Armazenado a escolha do usu�rio
	
	    system("cls");
	    
	    switch(opcao)//inicio da sele��o do menu
	    {
	    	case 1:
	    	registro();//chamadas de fun��es
		    break;
		
		    case 2:
		    consulta();
		    break;
		
		    case 3:
		    deletar();
		    break;
		
		    default:	
		    printf("Essa op��o n�o est� dispon�vel!\n");
		    system("pause");
		    break;
		} //fim da sele��o
	    
	
	} 
}
