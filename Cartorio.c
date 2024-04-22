#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço e memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação das variáves/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40]; 
	char cargo[40];
	//Final da criação das variáves/string
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando as informações dos usuários
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "w" seguinifica escrever
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ","); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando as informações dos usuários
	scanf("%s" ,nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, nome); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ","); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando as informações dos usuários
	scanf("%s" ,sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, sobrenome); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ","); //salvo o valor da variáve
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando as informações dos usuários
	scanf("%s" , cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, cargo); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause");
	  	
}

int consulta() //Função responsável por consultar os usuários no sistema
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
		printf("Não foi possível abrir o arquivo, não localizado. \n");
	}
   
   	while(fgets(conteudo, 200, file) != NULL)
   	{
   		printf("\n essas são as informações do usuário: ");
   		printf("%s", conteudo);
   		printf("\n\n");
	   }
	   
	   system("pause");
	   
	   
}

int deletar() //Função responsável por deletar os usuários do sistema
{
    char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usuário não se encontra no sistema Porque já foi Deletado! . \n");
		system("pause");
	}
	
		
}



int main()
{
	int opcao=0; //Definindo as variáves
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); //Responsável por limpar a tela
	
	    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	    printf(" ### Cartório da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Opcao: ");//Final do menu
	
	    scanf("%d", &opcao); //Armazenado a escolha do usuário
	
	    system("cls");
	    
	    switch(opcao)//inicio da seleção do menu
	    {
	    	case 1:
	    	registro();//chamadas de funções
		    break;
		
		    case 2:
		    consulta();
		    break;
		
		    case 3:
		    deletar();
		    break;
		
		    default:	
		    printf("Essa opção não está disponível!\n");
		    system("pause");
		    break;
		} //fim da seleção
	    
	
	} 
}
