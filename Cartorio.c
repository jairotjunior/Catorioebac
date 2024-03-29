#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int registro(){//Fun��o respons�vel por cadastrar os usu�rios no sistema.
	
	//In�cio de cria��o de vari�veis/string
	char arquivo[40];//Defini��a vari�veis
	char cpf[40];//Defini��a vari�veis
	char nome[40];//Defini��a vari�veis
	char sobrenome[40];//Defini��a vari�veis
	char cargo[40];//Defini��a vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do CPF do usu�rio
	scanf("%s", cpf);//Adiciona o valor a cima na vari�vel e "%s" = insere o dados na vari�vel como string
	
	strcpy (arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria um arquivo
	file = fopen(arquivo, "w"); //"w" = Cria um novo arquivo de dados e escreve dados no arquivo
	fprintf (file,cpf); //Salva o valor da vari�vel no arquivo
	fprintf(file, ","); //Insere no arquivo uma string
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do Nome do usu�rio
	scanf("%s", nome);//Adiciona o valor a cima na vari�vel e "%s" = insere o dados na vari�vel como string
	file = fopen(arquivo, "a");//"a" = Faz a edi��o do arquivo
	fprintf(file,nome);//Insere no arquivo uma string
	fprintf(file, ",");//Insere no arquivo uma string
	fclose(file);//Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Coletando informa��o do Sobrenome do usu�rio
	scanf("%s", sobrenome); //Adiciona o valor a cima na vari�vel e "%s" = insere o dados na vari�vel como string
	file = fopen(arquivo, "a");//"a" = Faz a edi��o do arquivo
	fprintf(file,sobrenome);//Insere no arquivo uma string
	fprintf(file, ",");
	fclose(file);//Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando informa��o do Cargo do usu�rio
	scanf("%s", cargo);//Adiciona o valor a cima na vari�vel e "%s" = insere o dados na vari�vel como string
	file = fopen(arquivo, "a");//"a" = Faz a edi��o do arquivo
	fprintf(file,cargo);//Insere no arquivo uma string
	fclose(file);//Fecha o arquivo
}
int consulta(){//Fun��o respons�vel por consultar os usu�rios no sistema.
	setlocale(LC_ALL,"Portuguese");//Faz o sistema reconhecer os acentos da l�ngua "Portuguesa"
	
	//In�cio de cria��o de vari�veis/string
	char cpf[40];//Defini��a vari�veis
	char conteudo[200];//Defini��a vari�veis
	
	printf("Digite o CPF a ser consultado: ");//Coletando informa��o do CPF do usu�rio
	scanf("%s",cpf);//Adiciona o valor a cima na vari�vel e "%s" = insere o dados na vari�vel como string
	
	FILE *file;//Cria um arquivo
	file = fopen(cpf,"r");//"r" faz a leitura do arquivo
	
	if(file == NULL){//Faz a verifica��o se o CPF digitada consta cadastrado no sistema
		printf("CPF n�o locaizado.\n");//Mensagem de CPF n�o cadastrado no sistema
	}
	while(fgets(conteudo, 200, file) != NULL){//Faz a varreduta do CPF digitada e mostra os dados cadastrado
		printf("\n Essas s�o as informa��es do usu�rio: "); //Mensagem de In�cio
		printf("%s", conteudo);//Imprime os dados no cadastro na tela
		printf("\n\n");//Pula linha par uma melhor vizualiza��o
		fclose(file);
	}
	system("pause");//Pausa o sistema para a vizuali��o dos dados coletados
}
int deletar(){//Fun��o respons�vel por deletar os usu�rios no sistema.
	
	//In�cio de cria��o de vari�veis/string
	char cpf[40];//Defini��a vari�veis
	
	printf("Digite d CPF do usu�rio a ser deletado: ");//Coletando informa��o do CPF do usu�rio
	scanf("%s",cpf);//Adiciona o valor a cima na vari�vel e "%s" = insere o dados na vari�vel como string
	
	if(remove(cpf) != 0){//Faz a verifica��o se o CPF digitada consta cadastrado no sistema e caso encontre remove
		printf("\n CPF n�o encontrado \n\n ");//informa que CPF n�o encontra-se no sistema
		system("pause");//Pausa o sistema para a vizuali��o dos dados coletados
	}
	else{//Faz a verifica��o se o CPF digitada consta cadastrado no sistema
		printf("\n CPF deletado:\n\n");//informa que CPF foi deletado do sistema
		system("pause");//Pausa o sistema para a vizuali��o dos dados coletados
	}
}
int main()//In�cio do programa
{
	//In�cio de cria��o de vari�veis/string
	int opcao=0; //Defini��a vari�veis
	int laco=1;//Defini��a vari�veis
	char senhadigitada[] = "a";//Cria a vari�vel para a senha do login
	int comparacao;//Vari�vel para compara��o com senha digitada com a cadastrada
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\n Digite a sua senha: ");//Mensagem para digitar da senha
	scanf("%s", senhadigitada);//Captura a senha digitada e guarda na vari�vel
	
	comparacao = strcmp(senhadigitada, "admin");//Compara campo senha, com a senha cadastrada
	
	if (comparacao == 0){//�nicio da Valida��o de senha
		
		system("cls");//Limpa a tela para melhor vizualiza��o
		for(laco=1;laco=1;){//Fun��o de repeti��o do menu
		
			system("cls");//Respons�vel por limpar dados digitados e coletados da tela
		
			setlocale(LC_ALL, "Portuguese");//Faz o sistema reconhecer os acentos da l�ngua "Portuguesa"
		
	   		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	 		printf("Escolha a op��o desejada do menu: \n\n");//T�tulo do menu
	  		printf("\t 1 - Registrar Nomes \n");//op��es a ser realizadas
			printf("\t 2 - Consultar Nomes \n");//op��es a ser realizadas
			printf("\t 3 - Deletar Nomes \n");//op��es a ser realizadas
			printf("\t 4 - Sair do sistema\n\n");//op��es a ser realizadas
			printf("Op��o: ");
	 	    
	 	    //Fim do menu
	    
	   	 	scanf("%d", &opcao); //Armazenando a esclolha do usu�rio
	    
	  		system("cls");//Respons�vel por limpar dados digitados e coletados da tela
	  		
	  		switch (opcao){
	  			case 1: 
					registro();//Chama a fun��o a ser execultada, ap�s usu�rio interagir no menu
					break;//Encerra o switch
	    		
				case 2:
					consulta();//Chama a fun��o a ser execultada, ap�s usu�rio interagir no menu
					break;//Encerra o switch
					
				case 3:
					deletar();//Chama a fun��o a ser execultada, ap�s usu�rio interagir no menu
					break;//Encerra o switch
					
				case 4:
					printf("Obrigado por utilizar o sistema! \n");//Mensagem de finalizar o login
					system("cls");//Limpa a tela
					return 0;
					break;//Encerra o switch
					
				default: //Execulta em situa��es n�o prevista
					printf("Essa op��o n�o est� dispon�vel!\n");//Mensagem de op��o errada
					system ("pause");//Aguarda a��a do usu�rio
					break;//Encerra o switch
			}
		}
	}
	else{//Execulta em caso de senha incorreta
		printf("\n Senha digitada errada, Digite novamente! \n\n");//Mensagem de senha errada
		system("pause");//Aguarda a��a do usu�rio
		system("cls");//Limpa a tela
		main();//Chama a fun��o principal, retorna o programa a tela de login
	}
}
