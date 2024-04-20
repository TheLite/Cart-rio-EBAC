#include <stdio.h> //biblioteca de comunica��o com o usuario.
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> //biblioteca de aloca��o de linguagem
#include <string.h> //biblioteca de aloca��o de string


int main ()
{
	int opcao=0; //Usamos int para definir as vari�veis (por enquanto relativo �s op��es que podemos escolher)
	int laco=1; //O mesmo acima vale para essa linha, por�m agora a inten��o � criar um loop (Inicio de declara��o da variavel p/ loop)
	
	int reg() //Abreviei todas as fun��es, para esclarecer reg=registrar cons=consultar e del=deletar (Se caso outros lerem � bom registrar para evitar d�vidas)
	{
		setlocale(LC_ALL, "Portuguese");
		char arquivo[40];
		char nome[40];
		char sobrenome[40]; 
		char cpf[11];
		char cargo[40];
		
		printf("Digite o CPF a ser cadastrado:");
		scanf("%s", cpf); //Bom, ja sabemos que o scanf armazena vari�veis por�m dessa vez ele vai armazenar strings ao inv�s de um numero inteiro.
		strcpy(arquivo, cpf); //Serve para copiar o valor das strings 
		
		FILE *file; //FILE em maiusculo � a chaamada de uma fun��o ja pronta, o file em minusculo vai criar um arquivo.
		
		file = fopen(arquivo, "a"); // Inverti a ordem de abertura para no final ficar especificado certinho
	 	fprintf(file,"\tCPF   ");  // seguindo a ordem que estava antes, quando eu tentei deixar cada coisa com o nome certinho ele pulava o cargo e bom, ficava bem confuso...
	 	fclose(file);  //tentei deixar melhor invertendo a ordem.
	 	
		file = fopen(arquivo, "w"); //Criando uma variavel com o cpf q foi informado
		fprintf(file, cpf); 
	 	fclose(file);
	 	
	 	file = fopen(arquivo,"a");
	 	fprintf(file,"\tNOME: ");
	 	fclose(file);
	 	
		printf("Digite o nome para cadastro:"); //Chamando cadastro para nome 
	 	scanf("%s", nome);
	 	file = fopen(arquivo, "a");
	 	fprintf(file, nome);
	 	fclose(file);
	 	
	 	file = fopen(arquivo,"a");
	 	fprintf(file,"\tSOBRENOME: ");
	 	fclose(file);
	 	
	 	
		printf("Digite o sobrenome para cadastro:"); //Chamando cadastro para sobrenome
	 	scanf("%s", sobrenome);
	 	file = fopen(arquivo, "a"); 
	 	fprintf(file, sobrenome);
	 	fclose(file);
	 	
		file = fopen(arquivo,"a");
	 	fprintf(file,"\tCARGO: ");
	 	fclose(file);
	 	
	 	printf("Digite o cargo para cadastro:"); //Chamando cadastro para cargo. 
	 	scanf("%s", cargo);
	 	file = fopen(arquivo,"a");
	 	fprintf(file, cargo);
	 	fclose(file);
	 	
	 	
	 	
	 	system("pause");
	 	
	}
	
	int cons()
	{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[11];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado:");
		scanf("%s", cpf);
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL) 
		{
			printf("CPF N�o localizado! ");
			system("pause");
		}
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nInforma��es do CPF consultado: ");
			printf("%s", conteudo);
			printf("\n\n\n");
			
			system("pause");
		}
		
		
	}
	
	int del()
	{
		char cpf[11];
		printf("Informe o cadastro a ser deletado: ");
		scanf("%s", cpf);
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL) //fiz assim, se for nulo printa isso
		{
			printf("CPF n�o encontrado para dele��o!\n");
			system("pause");
			
		}
		else
		{
			printf("Usu�rio deletado com sucesso!\n");
			system("pause");
		}
		
		
		
	}
	
	for (laco=1;laco=1;) //Enquanto o la�o for 1, ele vai continuar repetindo (Inicio do la�o)
	{
	
		system("cls"); //Limpa a tela, evita polui��o visual.
		
    	setlocale(LC_ALL, "Portuguese"); //Aqui definimos a lingua (PT-BR) 

    	printf("Cadastro de Alunos EBAC \n\n"); //printf � o meio de comunica��o entre o sistema e o user. Estrutura��o do menu, em tese o que o usu�rio pode escolher. Na pr�tica � s� texto por enquanto. - Inicio visivel p/user
    	printf("Escolha a op��o desejada:\n\n"); // \t(x) gera um t�pico com um numero atribuido (Funciona com letras, por�m a variavel n�o pode ser inteira se for o caso). 
    	printf("\t1 Registrar Nomes.\n"); // \n = pular uma linha, evita polui��o visual.
    	printf("\t2 Consultar Nomes.\n");
    	printf("\t3 Deletar Nomes.\n"); 
		printf("Op��o:"); //fim do menu visivel p/ user
    
   		scanf("%d", &opcao); //Armazenamento de escolhas para o usu�rio sendo o scanf("%d"[aqui alocamos a variavel inteira], &opcao [& serve para demonstrar **onde a variavel ser� armazenada)
   
   		system ("cls"); //Descarregando a interface de excesso de info dos outros menus - importante para guiar melhor o user.
   
   		
		
		
			switch (opcao) //Come�o das entradas de variaveis //Cada if representa uma op��o criada de menu, portanto ele vai armazenar as variaveis e relacionar com a op��o do menu, ou se n�o houver rela��o vai informar ao user.
			{	case 1:    //Como o if foi substituido pelo case � importante lembrar que o come�o do comando � com switch e para cada caso declarar 1 variavel
		    	reg();
   				break; //Cada vari�vel deve terminar com um "break". 
   			
				case 2:
					cons();
	   			break;
	   			
	   			case 3:
	   				del();
	   			break;
	   			
	   			default: //Quando quisermos colocar uma op��o para uma variavel n�o prevista usaremos "default". Ou seja por padr�o se a variavel n�o for 1,2 ou 3 ent�o <resultado abaixo>.
	   				printf("Op��o inv�lida, escolha uma op��o de 1 a 3.\n"); //default n�o precisa de break 
	   				system("pause");
			}
	}
}
