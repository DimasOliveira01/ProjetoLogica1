#include<stdio.h>
#include<locale.h>
#include<stdlib.h>/*biblioteca para utilizar o rand()*/
#include <string.h> /* para poder usar strcpy */
//#include <conio.h>

struct arquivo{
	char pista[20];
	char palavra[3][20];
}; typedef struct arquivo Arquivo;

struct premio{
	char premios[12][5];
};typedef struct premio Premio;
	
int sorteio_numero(int sort); 								//protótipos das funções
void ler_arquivo_premios(float premios[12]);
void ler_arquivo(char palavras[5][3][17], char pista[5][17]);
void tela_2(int *i, int *numero_letras, int pista_escolhida, int palavra_escolhida, float *premio, char palavras[5][3][17], char pista[5][17], char vetor_underline[17], char jogador[3][17]);
void tela_3(int *i, int *numero_letras, int pista_escolhida, int palavra_escolhida, float *premio, char palavras[5][3][17], char pista[5][17], float premios[12], char vetor_underline[17], char jogador[3][17]);
void tela_4(int *i, int *numero_letras, int pista_escolhida, int palavra_escolhida, float *premio, char palavras[5][3][17], char pista[5][17], float premios[12], char vetor_underline[17], char jogador[3][17]);

main(){														//função principal
	int i, k, pista_escolhida, palavra_escolhida, numero_letras;
	float premio[3], premios[12];
	char palavras[5][3][17], pista[5][17], vetor_underline[17], jogador[3][17], opcao;

	setlocale(LC_ALL, "portuguese");

	ler_arquivo_premios(premios);							//le o arquivo de premios
	
	ler_arquivo(palavras, pista);							//le o arquivo de pista e palavras e joga os dados no char palavras[5][3][17]
	
	do{
	
	pista_escolhida = sorteio_numero(5);					//sorteia a palavra associada ao roda-roda(linha) palavra[5][3][17]
	palavra_escolhida = sorteio_numero(3);					//sorteia a palavra a ser decifrada(coluna) palavra[5][3][17]
	
	printf("\n\n\t\t\t---------------BEM VINDO AO RODA A RODA!---------------\n\n");
	for(k=0; k<3; k++){
		printf("Digite o nome do jogador %d: ", k+1);		//dá a entrada dos jogadores
		fflush(stdin);
		gets(jogador[k]);
		premio[k]=0;										//inicia o prêmio de cada jogador
	}
	system("cls");											//limpa a tela
	
	tela_2(&i, &numero_letras, pista_escolhida, palavra_escolhida, premio, palavras, pista, vetor_underline, jogador);												//chama a função tela 2, para imprimir a tela do jogo
	
	tela_3(&i, &numero_letras, pista_escolhida, palavra_escolhida, premio, palavras, pista, premios, vetor_underline, jogador);												//chama a função tela 3, para imprimir a tela do jogo
	
	tela_4(&i, &numero_letras, pista_escolhida, palavra_escolhida, premio, palavras, pista, premios, vetor_underline, jogador);												////chama a função tela 4, para imprimir a tela do jogo
	
	getch();
	system("cls");
	printf("\n\n\t\t\t----------------------RODA RODA---------------------------------\n");
	printf("\t\t\t-----------------Deseja jogar novamente? s/n------------------------\n");
	fflush(stdin);
	scanf("%c", &opcao);
		system("cls");
	}while(opcao=='s'||opcao=='S');

	system("pause");
}

int sorteio_numero(int sort){
	int sorteio;
	srand(time(NULL)); /* Garante que os números sorteados não se repitam */
	sorteio = rand()%sort;/* o %sort(5) sorteia um prêmio entre zero e 4*/
	return sorteio;
}

void ler_arquivo_premios(float premios[12]){
	FILE *file;
	Premio premio;
	int j=0, k;
	file=fopen("premios.dat", "rb");
	if(file==NULL){
		printf("Não foi possível abrir o arquivo.");
		system("Pause");
		exit(0);
	}
	while(fread(&premio, sizeof(Premio), 1, file)){				
		strcpy(premio.premios[j], premio.premios[0]);			
		j++;
	}
	for(k=0;k<12;k++){
		premios[k]=atof(premio.premios[k]);
	}
	fclose(file);
}

void ler_arquivo(char palavras[5][3][17], char pista[5][17]){										//le o arquivo da struct arquivo(pista e palavras)
	FILE *file;
	int j=0, m;
	Arquivo arquivo;
	Arquivo arq[5];
	file=fopen("palavras.dat", "rb");
	if(file==NULL){
		printf("Não foi possível abrir o arquivo!");
		system("Pause");
		exit(0);
	}
	
	while(fread(&arquivo, sizeof(Arquivo), 1, file)==1){
		strcpy(arq[j].pista, arquivo.pista);
		strcpy(arq[j].palavra[0], arquivo.palavra[0]);
		strcpy(arq[j].palavra[1], arquivo.palavra[1]);
		strcpy(arq[j].palavra[2], arquivo.palavra[2]);
		j++;
	}
	
	for(m=0;m<5;m++){								//organiza a pista na matriz
		strcpy(pista[m], arq[m].pista);
	}

	for(m=0;m<5;m++){									//organiza as palavras na matriz para o roda roda
		strcpy(palavras[m][0], arq[m].palavra[0]);
		strcpy(palavras[m][1], arq[m].palavra[1]);
		strcpy(palavras[m][2], arq[m].palavra[2]);
	}
	
	fclose(file);
}

void tela_2(int *i, int *numero_letras, int pista_escolhida, int palavra_escolhida, float *premio, 
char palavras[5][3][17], char pista[5][17], char vetor_underline[17], char jogador[3][17]){
	int j=0;
	while(palavras[pista_escolhida][palavra_escolhida][j]!='\0'){			//conta o número de letras da palavra escolhida e preenche o vetor_underline
		vetor_underline[j]='_';
		j++;
	}
	
	*numero_letras=j;
	
	printf("\t\t----------------------------------------------------------------------------------\n");			//tela número 2
	printf("\t\t\t\t\tA palavra está associada com: %s\n\n\n", pista[pista_escolhida]);							//tela número 2
	printf("\t\t\t\t\t      Acerte a palavra: ");
	for(j=0;j<*numero_letras;j++){
		printf(" %c", vetor_underline[j]);
	}
	printf("\n\n");
	printf("\t\t\t\t%s\t\t\t %s   \t\t %s\n", jogador[0], jogador[1], jogador[2]);								//tela número 2
	printf("\t\t\t\t====== \t\t\t ====== \t\t ======\n");									 					//tela número 2
	printf("\t\t\t\tR$%4.2f \t\t\t R$%4.2f \t\t R$%4.2f\n", premio[0], premio[1], premio[2]);					//tela número 2
	printf("\t\t----------------------------------------------------------------------------------\n\n\n");		//tela número 2
	
	system("cls");
}	

void tela_3(int *i, int *numero_letras, int pista_escolhida, int palavra_escolhida, float *premio, 
char palavras[5][3][17], char pista[5][17], float premios[12], char vetor_underline[17], char jogador[3][17]){																									//inicio tela 3
	int j, n=0, sorteio, cont;
	char digitados[26], letra;
	*i=0;
	
	cont = *numero_letras;

	while(cont>3){		
	
		sorteio=sorteio_numero(12);																					//sorteia o premio
	
		printf("\t\t----------------------------------------------------------------------------------\n");			//tela número 3
		printf("\t\t\t\t\tA palavra está associada com: %s\n\n\n", pista[pista_escolhida]);							//tela número 3
		printf("\t\t\t\t\t      Acerte a palavra: ");
		for(j=0;j<*numero_letras;j++){
			printf(" %c", vetor_underline[j]);
		}
		printf("\n\n");
		printf("\t\t\t\t%s \t\t\t %s  \t\t %s\n", jogador[0], jogador[1], jogador[2]);								//tela número 3
		printf("\t\t\t\t====== \t\t\t ====== \t\t ======\n");									 					//tela número 3
		printf("\t\t\t\tR$%4.2f \t\t\tR$%4.2f\t\t R$%4.2f\n\n", premio[0], premio[1], premio[2]);					//tela número 3
		printf("\t\t\t\t\t%s pressione enter para RODAR A RODA!\n\n", jogador[*i]);
		getch();	
		
		if(premios[sorteio]==0){
			printf("\t\t\t\t\t%s perdeu a vez!\n", jogador[*i]);
			getch();
			goto b;
		}
		
		if(premios[sorteio]==1){
			printf("\t\t\t\t\t%s você perdeu todo o seu valor acumulado!", jogador[*i]);								//tela número 3
			premio[*i]=0;
			getch();
			goto b;
		}
		
		q:
		printf("\t\tRoda a roda!\n\t\t%s uma letra por R$ %.2f: ", jogador[*i], premios[sorteio]);					//tela número 3
		fflush(stdin);
		scanf("%c", &letra);
		
		if(letra>=97){
			letra=letra-32;																						//passa a letra para maíscula
		}
		
		for(j=0;j<=n;j++){																						//valida se a letra é repetida
			if(digitados[j]==letra){
				printf("\n\t\tEsta letra já foi digitada, tente outra letra!\n");
				goto q;
			}
		}
		digitados[n]=letra;																					//salva as letras digitadas pelos usuários
		n++;
		
		for(j=0;j<*numero_letras;j++){
			if(palavras[pista_escolhida][palavra_escolhida][j]==letra){
				vetor_underline[j]=letra;
				cont--;
				premio[*i]=premio[*i]+premios[sorteio];
			}
		}
		
		b:
		
		*i=*i+1;

		if(*i>2){
			*i=0;
		}
		system("cls");	
	}
}																													//fim da tela número 3

void tela_4(int *i, int *numero_letras, int pista_escolhida, int palavra_escolhida, float *premio, 
char palavras[5][3][17], char pista[5][17], float premios[12], char vetor_underline[17], char jogador[3][17]){		//inicio da tela 4														//inicio tela número 4
	int z=0, j, sorteio, cont_falta_palavra, p, w;																
	char palavra[17];																	//o z é para verificar as 3 tentativas para acertar a palavra
	float vencedor;
	
	c:
	if(z>2){
			printf("\n\n\t\t----------------------------------------------------------------------------------\n");	
			printf("\t\t\t\t\tO jogo não teve nenhum vencedor!\n");
			printf("\t\t----------------------------------------------------------------------------------\n");	
			printf("\n\n");
			printf("\t\t\t\t%s \t\t\t %s \t\t         %s\n", jogador[0], jogador[1], jogador[2]);								//tela número 4
			printf("\t\t\t\t====== \t\t\t ====== \t\t ======\n");									 					//tela número 4
			printf("\t\t\t\tR$%4.2f \t\t R$%4.2f   \t\t R$%4.2f\n\n", premio[0], premio[1], premio[2]);						//tela número 4
			printf("Pressione enter para finalizar o jogo.\n\n");
		}

	while(z<3){
		m:
		sorteio=sorteio_numero(12);																				//sorteia o prêmio
		if(premios[sorteio]==0){
			goto m;
		}
		printf("\t\t----------------------------------------------------------------------------------\n");			
		printf("\t\t\t\t\tA palavra está associada com: %s\n\n\n", pista[pista_escolhida]);							
		printf("\t\t\t\t\t      Acerte a palavra: ");
		cont_falta_palavra=0;
		for(j=0;j<*numero_letras;j++){
			printf(" %c", vetor_underline[j]);
			if(vetor_underline[j]=='_'){
				cont_falta_palavra++;
			}
		}
		printf("\n\n");
		printf("\t\t\t\t%s \t\t\t %s \t\t         %s\n", jogador[0], jogador[1], jogador[2]);								//tela número 4
		printf("\t\t\t\t====== \t\t\t ====== \t\t ======\n");									 					//tela número 4
		printf("\t\t\t\tR$%4.2f \t\t R$%4.2f   \t\t R$%4.2f\n\n", premio[0], premio[1], premio[2]);						//tela número 4
		printf("\t\tRoda a roda!\n\n\t\t%s faltam %d letras para completar a palavra!\n ", jogador[*i], cont_falta_palavra);
		printf("\t\tCada letra valendo R$%4.2f para completar a palavra!\n ", premios[sorteio]);
		printf("\t\tValendo R$ %4.2f, a palavra é: ", cont_falta_palavra*premios[sorteio]);
		fflush(stdin);
		gets(palavra);
		strupr(palavra); 																						// PASSA PARA MAIÚSCULA
		printf("\n\n");	
		z++;																				
		if(strcmp(palavra,palavras[pista_escolhida][palavra_escolhida])==0){
			system("cls");
			premio[*i]=premio[*i]+cont_falta_palavra*premios[sorteio];
			printf("\t\t----------------------------------------------------------------------------------\n");			//tela número 4
			printf("\t\t\t\t\tA palavra está associada com: %s\n\n\n", pista[pista_escolhida]);							//tela número 4
			printf("\t\t\t\t  Parabéns %s você acertou a palavra: %s", jogador[*i], palavra);
			printf("\n\n");
			printf("\t\t\t\t%s \t\t\t %s \t\t         %s\n", jogador[0], jogador[1], jogador[2]);								//tela número 4
			printf("\t\t\t\t====== \t\t\t ====== \t\t ======\n");									 					//tela número 4
			printf("\t\t\t\tR$%4.2f \t\t R$%4.2f \t\t R$%4.2f\n\n", premio[0], premio[1], premio[2]);						//tela número 4
			
			for(w=0; w<3; w++){
				if(w==0){
					vencedor=premio[w];
					p=w;
				}else{
					if(vencedor<premio[w]){
						vencedor = premio[w];
						p=w;
					}
				}
			}
			
			if(p==0){
				printf("\t\t\t\tVENCEDOR \t\t\t        \t\t       \n");
			}else{
				if(p==1){
					printf("\t\t\t\t       \t\t\tVENCEDOR \t\t       \n");
				}else{
					printf("\t\t\t\t       \t\t\t        \t\tVENCEDOR\n");
				}
			}
			printf("\n\n\n\n");
			printf("\t\t\t\tPressione enter para finalizar este jogo.\n");
			z=5;	
		}else{
			*i=*i+1;
			if(*i>2){
				*i=0;
				system("cls");
				goto c;
			}else{
				system("cls");
				goto c;
			}
		}
		getch();
		}
}
