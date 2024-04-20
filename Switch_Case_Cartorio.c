#include <stdio.h> //biblioteca de comunicação com o usuario.
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocação de linguagem
#include <string.h> //biblioteca de alocação de string


int main ()
{
	int opcao=0; //Usamos int para definir as variáveis (por enquanto relativo às opções que podemos escolher)
	int laco=1; //O mesmo acima vale para essa linha, porém agora a intenção é criar um loop (Inicio de declaração da variavel p/ loop)
	
	int reg() //Abreviei todas as funções, para esclarecer reg=registrar cons=consultar e del=deletar (Se caso outros lerem é bom registrar para evitar dúvidas)
	{
		setlocale(LC_ALL, "Portuguese");
		char arquivo[40];
		char nome[40];
		char sobrenome[40]; 
		char cpf[11];
		char cargo[40];
		
		printf("Digite o CPF a ser cadastrado:");
		scanf("%s", cpf); //Bom, ja sabemos que o scanf armazena variáveis porém dessa vez ele vai armazenar strings ao invés de um numero inteiro.
		strcpy(arquivo, cpf); //Serve para copiar o valor das strings 
		
		FILE *file; //FILE em maiusculo é a chaamada de uma função ja pronta, o file em minusculo vai criar um arquivo.
		
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
			printf("CPF Não localizado! ");
			system("pause");
		}
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nInformações do CPF consultado: ");
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
			printf("CPF não encontrado para deleção!\n");
			system("pause");
			
		}
		else
		{
			printf("Usuário deletado com sucesso!\n");
			system("pause");
		}
		
		
		
	}
	
	for (laco=1;laco=1;) //Enquanto o laço for 1, ele vai continuar repetindo (Inicio do laço)
	{
	
		system("cls"); //Limpa a tela, evita poluição visual.
		
    	setlocale(LC_ALL, "Portuguese"); //Aqui definimos a lingua (PT-BR) 

    	printf("Cadastro de Alunos EBAC \n\n"); //printf é o meio de comunicação entre o sistema e o user. Estruturação do menu, em tese o que o usuário pode escolher. Na prática é só texto por enquanto. - Inicio visivel p/user
    	printf("Escolha a opção desejada:\n\n"); // \t(x) gera um tópico com um numero atribuido (Funciona com letras, porém a variavel não pode ser inteira se for o caso). 
    	printf("\t1 Registrar Nomes.\n"); // \n = pular uma linha, evita poluição visual.
    	printf("\t2 Consultar Nomes.\n");
    	printf("\t3 Deletar Nomes.\n"); 
		printf("Opção:"); //fim do menu visivel p/ user
    
   		scanf("%d", &opcao); //Armazenamento de escolhas para o usuário sendo o scanf("%d"[aqui alocamos a variavel inteira], &opcao [& serve para demonstrar **onde a variavel será armazenada)
   
   		system ("cls"); //Descarregando a interface de excesso de info dos outros menus - importante para guiar melhor o user.
   
   		
		
		
			switch (opcao) //Começo das entradas de variaveis //Cada if representa uma opção criada de menu, portanto ele vai armazenar as variaveis e relacionar com a opção do menu, ou se não houver relação vai informar ao user.
			{	case 1:    //Como o if foi substituido pelo case é importante lembrar que o começo do comando é com switch e para cada caso declarar 1 variavel
		    	reg();
   				break; //Cada variável deve terminar com um "break". 
   			
				case 2:
					cons();
	   			break;
	   			
	   			case 3:
	   				del();
	   			break;
	   			
	   			default: //Quando quisermos colocar uma opção para uma variavel não prevista usaremos "default". Ou seja por padrão se a variavel não for 1,2 ou 3 então <resultado abaixo>.
	   				printf("Opção inválida, escolha uma opção de 1 a 3.\n"); //default não precisa de break 
	   				system("pause");
			}
	}
}
