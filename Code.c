#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <time.h>
#define MAX 200


//Função de validação de CPF
int validaCPF(char cpf[12]);
//Função gotoxy da conio.h
void gotoxy(int x, int y);
//Função para impressão de cheque
void impressaoCheque(char nom[10], char sob[30], char cpf[12]);

//Função principal
int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	//struct de cadastro de clientes
	struct cadastro_Cliente
	{
		char nome[15], sobrenome[30], cpf[12];
		float saldo;
		char senha[7];
	};
	
	struct cadastro_Cliente cliente[MAX];
	
	//Seção de declaração de variáveis
	int x=0, y=0, escolha=0, valida1=0, valida2, i=0, j=0;
	int opcaoMenu=0,contador=0,saque=0,saldo=0,deposito=0;
	char icpf[12], validaSenha[7], valSenha;
	int qtdClientes=0, c=0;
	float transferencia=0;
	
	inicio:
	//Menu inicial, opção de cadastro ou acesso ao caixa
	valida1=0;
	do{
		system ("cls");
		if (valida1>0){
			gotoxy (22,7);
			printf("************Opção inválida************");
		}
		gotoxy (10,8);
		printf("-------------------------------------------------------------");
		gotoxy (9,9);
		printf("|                Bem vindo ao sistema bancário                |");
		gotoxy (10,10);
		printf("-------------------------------------------------------------");
		gotoxy (10,11);
		printf("(1)Cadastro de clientes\t(2)Acesso ao caixa\t(3)Sair");
		gotoxy (10,12);
		printf("Digite a opção desejada e depois pressione enter: ");
		scanf ("%d", &escolha);
		valida1++;
	}while ((escolha!=1) && (escolha!=2) && (escolha!=3));
	
	
	switch (escolha){
		//Casdastro de clientes
		case 1:
			do
			{
				//Nome
				valida1=0;
				system("cls");
				
				gotoxy (14,8);
				printf("-----------------------------------------------------");
				gotoxy (13,9);
				printf("|                Cadastro de clientes                 |");
				gotoxy (14,10);
				printf("-----------------------------------------------------");
				gotoxy (14,11);
				printf("Informe o primeiro nome do cliente. Ex: João.");
				gotoxy (14,12);
				printf("Nome: ");
				fflush(stdin);
				gets(cliente[x].nome);
				
				//Sobrenome
				valida1=0;
				system("cls");
				gotoxy (14,8);
				printf("-----------------------------------------------------");
				gotoxy (13,9);
				printf("|                Cadastro de clientes                 |");
				gotoxy (14,10);
				printf("-----------------------------------------------------");
				gotoxy (14,11);
				printf("Informe os sobrenomes do cliente. Ex: Silva de Sousa.");
				gotoxy (14,12);
				printf("Sobrenome: ");
				fflush(stdin);
				gets(cliente[x].sobrenome);
			
				//CPF
				do
				{	
					system("cls");
					gotoxy (14,8);
					printf("-----------------------------------------------------");
					gotoxy (13,9);
					printf("|                Cadastro de clientes                 |");
					gotoxy (14,10);
					printf("-----------------------------------------------------");
					gotoxy (14,11);
					printf("Informe o CPF do cliente sem pontos ou hífen. Ex: 22222222222");
					
					if (valida1>0){
						gotoxy (22,7);
						printf("************CPF inválido************");
					}
					gotoxy (14,12);
					printf("CPF: ");
					fflush(stdin);
					gets(cliente[x].cpf);
					valida2 = validaCPF (cliente[x].cpf);
					valida1++;
					
				}while (valida2==0);
				
				//Saldo
				valida1=0;
				valida2=0;
				do
				{
					system("cls");
					gotoxy (14,8);
					printf("-----------------------------------------------------");
					gotoxy (13,9);
					printf("|                Cadastro de clientes                 |");
					gotoxy (14,10);
					printf("-----------------------------------------------------");
					gotoxy (14,11);
					printf("Informe o saldo inicial do cliente, sendo acima de 0. Ex:289,05");
					
					if (valida1>0){
						gotoxy (21,7);
						printf("************Saldo inválido************");
					}
					gotoxy (14,12);
					printf("Saldo:");
					fflush(stdin);
					scanf("%f", &cliente[x].saldo);
					valida1++;
					valida2=cliente[x].saldo;
				}while (valida2<0);
				
				//Senha
				system("cls");
				gotoxy (14,8);
				printf("-----------------------------------------------------");
				gotoxy (13,9);
				printf("|                Cadastro de clientes                 |");
				gotoxy (14,10);
				printf("-----------------------------------------------------");
				gotoxy (14,11);
				printf("Informe a senha do cliente, esta deverá conter 6 dígitos. Ex:222222");
				gotoxy (14,12);
				printf("Senha:");
				i=0;
	  			do
				{
					valSenha = getch();
				  	if(isdigit(valSenha) && i < 6)
					{
				  		cliente[x].senha[i++] = valSenha;
      					putch(valSenha);
				  	}else if(valSenha == '\b' && i > 0){
      					i--;
     					putch('\b');
      					putch(' ');    
      					putch('\b');
   				  	}     
 	 			} while(i < 6 || (i == 6 && valSenha != '\r'));
 	 			cliente[x].senha[i] = '\0';
				
				//Opção de continuar ou não cadastrando clientes
				valida1=0;
				do 
				{
					system("cls");
					
					if (valida1>0){
						printf("Opção inválida!");
					}
					gotoxy (13,9);
					printf("(1) Sim     (2)Não");
					gotoxy (13,10);
					printf("Deseja continuar cadastrando clientes?\n");
					fflush(stdin);
					scanf("%d", &escolha);
					valida1++;
				}while((escolha!=1) && (escolha!=2));	
				x++;
				
			}while ((x<MAX) &&  (escolha!=2));
			goto inicio;
			
		case 2:
			//Funções do caixa
			valida1=0;
			valida2=0;
			qtdClientes=x;
			//Acesso à conta
			do
			{
				system("cls");
				gotoxy (14,8);
				printf("-----------------------------------------------------");
				gotoxy (13,9);
				printf("|              Bem vindo ao Maçom Bank!              |");
				gotoxy (14,10);
				printf("-----------------------------------------------------");			
		
				if (valida1>0){
					gotoxy (22,7);
					printf("************CPF inválido************");
				}
				gotoxy (14,11);
				printf("Aqui você deverá informar um CPF já cadastrado para acesso à conta.");
				gotoxy (14,12);
				printf("CPF: ");			
				fflush(stdin);
				gets(icpf);
				valida2 = validaCPF (icpf);
				valida1++;
			}while (valida2==0);
		
			// Busca o cliente
			c=0;
			y=0;
			valida1=0;
			for (y=0;y<qtdClientes;y++){
				j=strcmp(icpf,cliente[y].cpf);
				if (j==0){
					c=y;
				}else{
					valida1++;	
				}

			}
			//Caso CPF não esteja cadastrado, voltará ao menu inicial
			if (valida1==qtdClientes){
				system("cls");
				gotoxy (23,9);
				printf("CPF não cadastrado!");	
				gotoxy (13,10);
				system ("PAUSE");
				goto inicio;
			}
		
			//Verificação de senha
			j=1;
			y=0;
			for (y=0;y<3;y++){	
				system("cls");
				gotoxy (14,8);
				printf("-----------------------------------------------------");
				gotoxy (13,9);
				printf("|                                                     |");
				valida1=strlen(cliente[c].nome);
				valida1=valida1/2;
				valida1=38-valida1;
				gotoxy (valida1,9);
				printf ("Olá %s!", cliente[c].nome);
				gotoxy (14,10);
				printf("-----------------------------------------------------");
				if (y>0){
					gotoxy (22,7);
					printf("************Senha inválida************");
				}
				gotoxy (14,11);
				printf("Para sua segurança do cliente, será necessário a senha cadastrada.");	
				gotoxy (14,12);
				printf("Senha: ");
				i=0;
	  			do
				{
					valSenha = getch();
				  	if(isdigit(valSenha) && i < 6)
					{
				  		validaSenha[i++] = valSenha;
      					putch(valSenha);
				  	}else if(valSenha == '\b' && i > 0){
      					i--;
     					putch('\b');
      					putch(' ');    
      					putch('\b');
   				  	}     
 	 			} while(i < 6 || (i == 6 && valSenha != '\r'));
 	 			validaSenha[i] = '\0';
 	 			
				j=strcmp(validaSenha,cliente[c].senha);
				if (j==0){
					break;
				}
			}
			//limite de senhas excedidos, voltará para o menu inicial
			if (y==3){
				system("cls");
				gotoxy (13,9);
				printf("Limite de tentativas excedido! Tente novamente mais tarde.");	
				gotoxy (13,10);
				system ("PAUSE");
				goto inicio;
			}
			
			menuCaixa:
			//Menu do caixa
			//Validação das opções digitadas
			while ( (opcaoMenu<=0) || (opcaoMenu>5) ){
				//Mostra opção inválida após ser digitado a primeira opção
				system ("cls");
				if (contador!=0){  
					gotoxy (22,7);
					printf("********Opção inválida!!********");
					
				}
				gotoxy (3,8);
				printf("---------------------------------------------------------------------------");
				gotoxy (2,9);
				printf("| (1) Saque  |  (2) Saldo  |  (3) Depósito |  (4) Transfência |  (5) Cheque |");
				gotoxy (3,10);
				printf("---------------------------------------------------------------------------");
				gotoxy (3,11);
				printf("Informe a opção de acordo com a opção desejada. Ex: 5");
				gotoxy (3,12);
				printf("Opção desejada: ");
				scanf ("%d",&opcaoMenu);	
				contador++;
			}
			contador=0; //inicializar a varival para ser utilizada novamente
			
			//Switch case utilizado para realizar a operação escolhida
			switch (opcaoMenu){
				case 1:
					
					do{
						system("cls");
						if (contador!=0){ //Entra nessa condição caso o valor informado para saque seja inválido
							gotoxy (14,7);
							printf ("***Valor informado inválido ou não disponível para saque***");
						}
						gotoxy (14,8);
						printf("-------------------------------------------------------------");
						gotoxy (13,9);
						printf("|  Notas disponíveis:   |  R$100  |  R$50  |  R$20  |  R$10   |");
						gotoxy (14,10);
						printf("-------------------------------------------------------------");
						gotoxy (14,11);
						printf("Informe o valor a ser sacado conforme as notas disponíveis em caixa.");
						gotoxy (14,12);
						printf("Saque:");	
						scanf ("%d",&saque);
						contador++;
					}while ((saque<=0) || (saque>cliente[0].saldo) || (saque%10!=0));
					cliente[c].saldo-=saque; //Subtrai o valor sacado do saldo
					
					system("cls");
					gotoxy (14,8);
					printf("-------------------------------------------------------------");
					gotoxy (13,9);
					printf("|                       Saldo atual                          |");
					gotoxy (14,10);
					printf("-------------------------------------------------------------");
					gotoxy (14,11);
					printf("R$ %.2f", cliente[c].saldo);
					break;
				case 2: 
					//Neste caso, somente exibirá o valor disponível em conta
					system("cls");
					gotoxy (14,8);
					printf("-------------------------------------------------------------");
					gotoxy (13,9);			
					printf("|                          Saldo                             |");
					gotoxy (14,10);
					printf("-------------------------------------------------------------");
					gotoxy (14,11);
					printf("Seu saldo disponível é: %.2f,",cliente[c].saldo);
					break;
				case 3:
						contador=0;
					do{
						system("cls");
						if (contador>0){
							gotoxy (14,7);
							printf ("***Valor informado inválido***");
						}
						gotoxy (14,8);
						printf("-------------------------------------------------------------");
						gotoxy (13,9);
						printf("|                         Depósito                            |");
						gotoxy (14,10);
						printf("-------------------------------------------------------------");
						gotoxy (14,11);
						printf("Informe o valor a ser depositado: ");	
						scanf ("%d",&deposito);
						contador++;
					}while(deposito<=0);
					
					cliente[c].saldo+=deposito; // Soma o valor informado ao valor disponível anteriormente
					system("cls");
					gotoxy (14,8);
					printf("-------------------------------------------------------------");
					gotoxy (13,9);
					printf("|                       Saldo atual                          |");
					gotoxy (14,10);
					printf("-------------------------------------------------------------");
					gotoxy (14,11);
					printf("R$ %.2f", cliente[c].saldo);
					break;	
				case 4:
					j=0;
					y=0;
					do{
						system("cls");
						if (y>0){
							gotoxy (14,7);
							printf ("*************CPF inválido*************");
						}
						gotoxy (14,8);
						printf("-------------------------------------------------------------");
						gotoxy (13,9);
						printf("|                      Transferência                          |");
						gotoxy (14,10);
						printf("-------------------------------------------------------------");
						gotoxy (14,11);
						printf("Informe o CPF o qual o dinheiro deverá ser transferido.");
						gotoxy (14,12);
						printf("CPF: ");
						fflush(stdin);
						gets(icpf);
						j=validaCPF(icpf);	
						y++;
					}while(j==0);
					//busca cliente
					y=0;
					i=0;
					for (j=0;j<qtdClientes;j++){
						y=strcmp(icpf,cliente[j].cpf);
						if (y==0){
							valida1=j;
						}else{
							i++;
						}
					}
					//Se o cliente não for cadastrado, voltará ao menu do caixa
					if (i==qtdClientes){
						system("cls");
						gotoxy (13,9);
						printf("Cliente não cadastrado.");	
						gotoxy (13,10);
						system ("PAUSE");
						goto menuCaixa;
					}
					//Valor da transferência e validação deste valor
					contador=0;
					do{
						system("cls");
						if (contador>0){
							gotoxy(14,7);
							printf("***Valor informado inválido***");
						}
						gotoxy(14,8);
						printf("-------------------------------------------------------------");
						gotoxy (13,9);
						printf("|                      Transferência                          |");
						gotoxy(14,10);
						printf("-------------------------------------------------------------");
						gotoxy(14,11);
						printf("Informe o valor a ser transferido.");
						gotoxy(14,12);
						printf("Transferência: ");
						fflush(stdin);
						scanf("%f", &transferencia);
						contador++;
					}while((transferencia<=0) && (transferencia>cliente[c].saldo));
					
					//Realização da transferência
					cliente[c].saldo=cliente[c].saldo-transferencia;
					cliente[valida1].saldo=cliente[valida1].saldo+transferencia;
								
					system ("cls");
					gotoxy (14,8);
					printf("-------------------------------------------------------------");
					gotoxy (13,9);
					printf("|                      Transferência                          |");
					gotoxy (14,10);
					printf("-------------------------------------------------------------");
					gotoxy (14,11);	
					printf("Valor transferido com sucesso!");	
					gotoxy (14,12);	
					printf("Transferido para o cliente %s", cliente[valida1].nome);	
					gotoxy (14,13);	
					printf("Saldo atual %.2f", cliente[c].saldo);			
					break;
				case 5:
					impressaoCheque(cliente[c].nome, cliente[c].sobrenome, cliente[c].cpf);
			}
			
			goto inicio;
		case 3:
			break;
	}
		
			getch();
			return 0;
	}

int validaCPF(char cpf[12])  
{  
	int icpf[12];  
	int i,somador=0,dig1,res1,res2,dig2,valor;  
	

	//Conversão de char para inteiro 
	for(i=0;i<11;i++){  
		icpf[i]=cpf[i]-48;  
	}  
 	
	//Encontra o primeiro dígito
	for(i=0;i<9;i++){  
		somador+=icpf[i]*(10-i);  
	}  
  
	res1=somador%11;  
  
	if((res1==0) || (res1==1)){  
		dig1=0;  
	}else{  
		dig1 = 11-res1;  
	}  
  
	//Encontra o segundo dígito  
	somador=0;  
	for(i=0;i<10;i++){  
		somador+=icpf[i]*(11-i);  
	}  
	  
	valor=(somador/11)*11;  
	res2=somador-valor;  
  
	if((res2==0) || (res2==1)){  
		dig2=0;  
	}else{  
		dig2=11-res2;  
	}  
  
	//Efetua a comparação para validação do CPF  
	if((dig1==icpf[9]) && (dig2==icpf[10])){ 
		//Efetua a exclusão dos cpf com todos os dígitos iguais
		if((strcmp(cpf,"00000000000") != 0) && (strcmp(cpf,"11111111111") !=  0) && (strcmp(cpf,"22222222222") !=  0) &&
        (strcmp(cpf,"33333333333") !=  0) && (strcmp(cpf,"44444444444") !=  0) && (strcmp(cpf,"55555555555") !=  0) &&
        (strcmp(cpf,"66666666666") !=  0) && (strcmp(cpf,"77777777777") != 0) && (strcmp(cpf,"88888888888") !=  0) &&
        (strcmp(cpf,"99999999999") !=  0)){
			return 1; 
		}
	}else{  
		return 0;  
	}  
}  

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}


void impressaoCheque(char nom[10], char sob[30], char cpf[12]){
	

	int x=0, y=0, k=0;
	char nomeCompleto[45];
	char mes[4], dia[3], ano[5];
	
	//União do nome e sobrenome
	strcpy(nomeCompleto, "");
	strcat (nomeCompleto, nom);
	strcat (nomeCompleto, " ");
	strcat (nomeCompleto, sob);
	system("cls");
	
	//Busca de data no sistema
	strcpy(mes, "");
	strcpy(dia, "");
	strcpy(ano, "");
	strncat(mes, __DATE__ , 3);
	strncat(dia, __DATE__ +4, 2);
	strncat(ano, __DATE__ +7, 4);

	

	//Impressão de cheque
	for (x=0;x<81;x++){
		for (y=0;y<25;y++){
			if ((y==7) || ((x==1) && ((y>7) && y<21))){
				gotoxy(x,y);
				printf("*");
			}
			if ((y==21) || ((x==80) && ((y>7) && y<21))){
				gotoxy(x,y);
				printf("*");
			}
		}
	}
	
	gotoxy(1,1);
	printf("                                                                             ");
	gotoxy(2,8);
	printf("|   Nº do cheque  |   Nº do banco   |   Agência   |       CPF      |    R$   |");
	gotoxy(2,9);
	printf("|       0001      |      101021     |    999-4    |   %s  |         |",cpf);
	gotoxy(3,11);
	printf("Valor por extenso:_________________________________________________________");
	gotoxy(3,13);
	printf("___________________________________________________________e centavos acima");
	gotoxy(3,15);
	printf("a______________________________________________________________ou sua ordem");
	gotoxy(45,17);
	printf("Brasília, %s de %s de %s\n", dia, mes, ano);
	gotoxy(40,19);
	printf("_______________________________________");	
	k=strlen(nomeCompleto);
	k=70-k;
	gotoxy(k,20);
	printf("%s",nomeCompleto);
	gotoxy(1,24);
	getch();
}
