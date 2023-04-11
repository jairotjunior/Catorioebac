#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string

int registro(){//Função responsável por cadastrar os usuários no sistema.
	
	//Início de criação de variáveis/string
	char arquivo[40];//Definiçõa variáveis
	char cpf[40];//Definiçõa variáveis
	char nome[40];//Definiçõa variáveis
	char sobrenome[40];//Definiçõa variáveis
	char cargo[40];//Definiçõa variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do CPF do usuário
	scanf("%s", cpf);//Adiciona o valor a cima na variável e "%s" = insere o dados na variável como string
	
	strcpy (arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria um arquivo
	file = fopen(arquivo, "w"); //"w" = Cria um novo arquivo de dados e escreve dados no arquivo
	fprintf (file,cpf); //Salva o valor da variável no arquivo
	fprintf(file, ","); //Insere no arquivo uma string
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do Nome do usuário
	scanf("%s", nome);//Adiciona o valor a cima na variável e "%s" = insere o dados na variável como string
	file = fopen(arquivo, "a");//"a" = Faz a edição do arquivo
	fprintf(file,nome);//Insere no arquivo uma string
	fprintf(file, ",");//Insere no arquivo uma string
	fclose(file);//Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Coletando informação do Sobrenome do usuário
	scanf("%s", sobrenome); //Adiciona o valor a cima na variável e "%s" = insere o dados na variável como string
	file = fopen(arquivo, "a");//"a" = Faz a edição do arquivo
	fprintf(file,sobrenome);//Insere no arquivo uma string
	fprintf(file, ",");
	fclose(file);//Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando informação do Cargo do usuário
	scanf("%s", cargo);//Adiciona o valor a cima na variável e "%s" = insere o dados na variável como string
	file = fopen(arquivo, "a");//"a" = Faz a edição do arquivo
	fprintf(file,cargo);//Insere no arquivo uma string
	fclose(file);//Fecha o arquivo
}
int consulta(){//Função responsável por consultar os usuários no sistema.
	setlocale(LC_ALL,"Portuguese");//Faz o sistema reconhecer os acentos da língua "Portuguesa"
	
	//Início de criação de variáveis/string
	char cpf[40];//Definiçõa variáveis
	char conteudo[200];//Definiçõa variáveis
	
	printf("Digite o CPF a ser consultado: ");//Coletando informação do CPF do usuário
	scanf("%s",cpf);//Adiciona o valor a cima na variável e "%s" = insere o dados na variável como string
	
	FILE *file;//Cria um arquivo
	file = fopen(cpf,"r");//"r" faz a leitura do arquivo
	
	if(file == NULL){//Faz a verificação se o CPF digitada consta cadastrado no sistema
		printf("CPF não locaizado.\n");//Mensagem de CPF não cadastrado no sistema
	}
	while(fgets(conteudo, 200, file) != NULL){//Faz a varreduta do CPF digitada e mostra os dados cadastrado
		printf("\n Essas são as informações do usuário: "); //Mensagem de Início
		printf("%s", conteudo);//Imprime os dados no cadastro na tela
		printf("\n\n");//Pula linha par uma melhor vizualização
		fclose(file);
	}
	system("pause");//Pausa o sistema para a vizualição dos dados coletados
}
int deletar(){//Função responsável por deletar os usuários no sistema.
	
	//Início de criação de variáveis/string
	char cpf[40];//Definiçõa variáveis
	
	printf("Digite d CPF do usuário a ser deletado: ");//Coletando informação do CPF do usuário
	scanf("%s",cpf);//Adiciona o valor a cima na variável e "%s" = insere o dados na variável como string
	
	if(remove(cpf) != 0){//Faz a verificação se o CPF digitada consta cadastrado no sistema e caso encontre remove
		printf("\n CPF não encontrado \n\n ");//informa que CPF não encontra-se no sistema
		system("pause");//Pausa o sistema para a vizualição dos dados coletados
	}
	else{//Faz a verificação se o CPF digitada consta cadastrado no sistema
		printf("\n CPF deletado:\n\n");//informa que CPF foi deletado do sistema
		system("pause");//Pausa o sistema para a vizualição dos dados coletados
	}
}
int main()//Início do programa
{
	//Início de criação de variáveis/string
	int opcao=0; //Definiçõa variáveis
	int laco=1;//Definiçõa variáveis
	char senhadigitada[] = "a";//Cria a variável para a senha do login
	int comparacao;//Variável para comparação com senha digitada com a cadastrada
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\n Digite a sua senha: ");//Mensagem para digitar da senha
	scanf("%s", senhadigitada);//Captura a senha digitada e guarda na variável
	
	comparacao = strcmp(senhadigitada, "admin");//Compara campo senha, com a senha cadastrada
	
	if (comparacao == 0){//Ínicio da Validação de senha
		
		system("cls");//Limpa a tela para melhor vizualização
		for(laco=1;laco=1;){//Função de repetição do menu
		
			system("cls");//Responsável por limpar dados digitados e coletados da tela
		
			setlocale(LC_ALL, "Portuguese");//Faz o sistema reconhecer os acentos da língua "Portuguesa"
		
	   		printf("### Cartório da EBAC ###\n\n"); //Início do menu
	 		printf("Escolha a opção desejada do menu: \n\n");//Título do menu
	  		printf("\t 1 - Registrar Nomes \n");//opções a ser realizadas
			printf("\t 2 - Consultar Nomes \n");//opções a ser realizadas
			printf("\t 3 - Deletar Nomes \n");//opções a ser realizadas
			printf("\t 4 - Sair do sistema\n\n");//opções a ser realizadas
			printf("Opção: ");
	 	    
	 	    //Fim do menu
	    
	   	 	scanf("%d", &opcao); //Armazenando a esclolha do usuário
	    
	  		system("cls");//Responsável por limpar dados digitados e coletados da tela
	  		
	  		switch (opcao){
	  			case 1: 
					registro();//Chama a função a ser execultada, após usuário interagir no menu
					break;//Encerra o switch
	    		
				case 2:
					consulta();//Chama a função a ser execultada, após usuário interagir no menu
					break;//Encerra o switch
					
				case 3:
					deletar();//Chama a função a ser execultada, após usuário interagir no menu
					break;//Encerra o switch
					
				case 4:
					printf("Obrigado por utilizar o sistema! \n");//Mensagem de finalizar o login
					system("cls");//Limpa a tela
					return 0;
					break;//Encerra o switch
					
				default: //Execulta em situações não prevista
					printf("Essa opção não está disponível!\n");//Mensagem de opção errada
					system ("pause");//Aguarda açõa do usuário
					break;//Encerra o switch
			}
		}
	}
	else{//Execulta em caso de senha incorreta
		printf("\n Senha digitada errada, Digite novamente! \n\n");//Mensagem de senha errada
		system("pause");//Aguarda açõa do usuário
		system("cls");//Limpa a tela
		main();//Chama a função principal, retorna o programa a tela de login
	}
}
