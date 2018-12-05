#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void pvp();
int EscolhaJogador();
void tabuleiro1(char matriz[3][3]);
void tabuleiro2(char matrizes[5][5]);
void logica1(int entrada);
void logica2(int entrada);
void BemVindo();


int main (){
	setlocale(LC_ALL,"portuguese");
	BemVindo();
	system("pause");
	system("cls");

	int Escolha;
		do{
			printf("\nBem vindo! Favor escolher sua forma de jogo abaixo\nDigite 1 -> pvp\nDigite 2 -> Sair\n");
			scanf("%d", &Escolha);
			switch(Escolha){
					case(1):
							pvp();
							break;
					case(2):
							printf("Até logo!");
							return 0;
					default:
							printf("Escolha inexistente, tente novamente.");
							break;
			}
		}while(Escolha != 3);
	return 0;
}

void pvp(){
	int EscolherTamanho;
	char matriz[3][3] = {{' ', ' ', ' '},
						 {' ', ' ', ' '},
						 {' ', ' ', ' '}};

	char matrizes[5][5] = {{' ', ' ', ' ', ' ', ' ',},
						   {' ', ' ', ' ' , ' ', ' '},
						   {' ', ' ', ' ', ' ', ' '}};

	printf("\nDigite 1 -> Jogar 3x3\nDigite 2 -> Jogar 5x5\n");
	scanf("%d", &EscolherTamanho);
	if(EscolherTamanho == 1){
		tabuleiro1(matriz);
		logica1(EscolhaJogador());
	}
	else if(EscolherTamanho == 2){
		tabuleiro2(matrizes);
		logica2(EscolhaJogador());
	}
	else{
		printf("Opção inválida. Tente novamente!\n\n");
	}
}
void tabuleiro1(char matriz[3][3]){
	system("cls");
	printf("\n      Jogo da velha 3x3\n\n");
	printf("\t %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", matriz[2][0], matriz[2][1], matriz[2][2]);
}

void tabuleiro2(char matrizes[5][5]){
	system("cls");
	printf("\n         Jogo da velha 5x5\n\n");
	printf("\t %c | %c | %c | %c | %c \n", matrizes[0][0], matrizes[0][1], matrizes[0][2], matrizes[0][3], matrizes[0][4]);
	printf("\t-------------------\n");
	printf("\t %c | %c | %c | %c | %c \n", matrizes[1][0], matrizes[1][1], matrizes[1][2], matrizes[1][3], matrizes[1][4]);
	printf("\t-------------------\n");
	printf("\t %c | %c | %c | %c | %c \n", matrizes[2][0], matrizes[2][1], matrizes[2][2], matrizes[2][3], matrizes[2][4]);
	printf("\t-------------------\n");
	printf("\t %c | %c | %c | %c | %c \n", matrizes[3][0], matrizes[3][1], matrizes[3][2], matrizes[3][3], matrizes[3][4]);
	printf("\t-------------------\n");
	printf("\t %c | %c | %c | %c | %c \n", matrizes[4][0], matrizes[4][1], matrizes[4][2], matrizes[4][3], matrizes[4][4]);
}

int EscolhaJogador(){
	char aux, jogador1, jogador2;
	printf("Jogador 1 será X ou O ? [Digite 1 para X, Digite 2 para O]:\n");
	scanf("%d",&aux);
	if (aux == 1)
	{
		aux = 'X';
		return 0;
	}
	else
	{
		aux = 'O';
		return 1;
	}
}

void logica1(int entrada){

	char matriz[3][3] = {{'1', '2', '3'},
						{'4', '5', '6'},
						{'7', '8', '9'}};

	char RespostaUsuario,aux;
  	int ContadorJogadas, linha, coluna, vez = entrada, i, j, venc1 = 0, venc2 = 0, empate = 0, cpu;
  	do{
  		ContadorJogadas = 1;
  		for (i = 0; i < 3; i++){
  			for(j = 0; j < 3; j++){
  				matriz [i][j] = ' ';
			  }
		  }
  		do{
  			tabuleiro1(matriz);
  			if(vez%2 == 0){
				printf("Jogador X:");
			}
			else{
				printf("Jogador O:");
			}
  			printf("\nDigite a Linha:\n");
			scanf("%i", &linha);
			printf("Digite a Coluna:\n");
			scanf("%i", &coluna);
			if(linha < 1 || linha > 3 || coluna < 1 || coluna > 3){
				printf("Opção inválida. Tente novamente!\n");
			}else if(matriz[linha-1][coluna-1] != ' '){
				linha = 0;
				coluna = 0;
			}else{
				if(vez %2 == 0){
					matriz[linha-1][coluna-1] = 'X';
				}else{
					matriz[linha-1][coluna-1] = 'O';
				}
				vez++;
				ContadorJogadas++;
			}
			// Verificação das linhas para 'X'
			if(matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X'){ContadorJogadas = 11;}
			if(matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X'){ContadorJogadas = 11;}
			if(matriz[2][0] == 'X' && matriz[2][1] == 'X' && matriz[2][2] == 'X'){ContadorJogadas = 11;}
			// Verificação das colunas para 'X'
			if(matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X'){ContadorJogadas = 11;}
			if(matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X'){ContadorJogadas = 11;}
			if(matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X'){ContadorJogadas = 11;}
			// Verificação das diagonais para 'X'
			if(matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X'){ContadorJogadas = 11;}
			if(matriz[2][0] == 'X' && matriz[1][1] == 'X' && matriz[0][2] == 'X'){ContadorJogadas = 11;}

			// Verificação das linhas para 'O'
			if(matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O'){ContadorJogadas = 12;}
			if(matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O'){ContadorJogadas = 12;}
			if(matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O'){ContadorJogadas = 12;}
			// Verificação das colunas para 'O'
			if(matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O'){ContadorJogadas = 12;}
			if(matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O'){ContadorJogadas = 12;}
			if(matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O'){ContadorJogadas = 12;}
			// Verificação das diagonais para 'O'
			if(matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O'){ContadorJogadas = 12;}
			if(matriz[2][0] == 'O' && matriz[1][1] == 'O' && matriz[0][2] == 'O'){ContadorJogadas = 12;}
		}while(ContadorJogadas <= 9);
			tabuleiro1(matriz);
			if(ContadorJogadas == 10){
				printf("\nJogo empatado!\n\n");
				empate++;
			}
			if(ContadorJogadas == 11){
				printf("\nFim de jogo! Vencedor foi -> X <-\n\n");
				venc1++;
			}
			if(ContadorJogadas == 12){
				printf("\nFim de jogo! Vencedor foi -> O <-\n\n");
				venc2++;
			}
			printf("Vitórias do jogador X: %i\n", venc1);
			printf("Vitórias do jogador O: %i\n", venc2);
			printf("Empates:               %i\n\n", empate);
	  printf("Deseja jogar novamente?[S-N]\n");
	  scanf("%s", &RespostaUsuario);
  	}while(RespostaUsuario=='s');
}

void logica2(int entrada){

	char matrizes[5][5] = {{' ', ' ', ' ', ' ', ' '},
						 {' ', ' ', ' ', ' ', ' '},
						 {' ', ' ', ' ', ' ', ' '}};

	char RespostaUsuario,aux;
  	int ContadorJogadas, linha, coluna, vez = entrada, i, j, venc1 = 0, venc2 = 0, empate = 0;
  	do{
  		ContadorJogadas = 1;
  		for (i = 0; i < 5; i++){
  			for(j = 0; j < 5; j++){
  				matrizes [i][j] = ' ';
			  }
		  }
  		do{
  			tabuleiro2(matrizes);
  			if(vez%2 == 0){
				printf("Jogador X:");
			}
			else{
				printf("Jogador O:");
			}
  			printf("\nDigite a Linha:\n");
			scanf("%i", &linha);
			printf("Digite a Coluna:\n");
			scanf("%i", &coluna);
			if(linha < 1 || linha > 5 || coluna < 1 || coluna > 5){
				printf("Opção inválida. Tente novamente!\n");
			}else if(matrizes[linha-1][coluna-1] != ' '){
				linha = 0;
				coluna = 0;
			}else{
				if(vez %2 == 0){
					matrizes[linha-1][coluna-1] = 'X';
				}else{
					matrizes[linha-1][coluna-1] = 'O';
				}
				vez++;
				ContadorJogadas++;
			}
			// Verificação das linhas para 'X'
			if(matrizes[0][0] == 'X' && matrizes[0][1] == 'X' && matrizes[0][2] == 'X' && matrizes[0][3] == 'X' && matrizes[0][4] == 'X'){ContadorJogadas = 27;}
			if(matrizes[1][0] == 'X' && matrizes[1][1] == 'X' && matrizes[1][2] == 'X' && matrizes[1][3] == 'X' && matrizes[1][4] == 'X'){ContadorJogadas = 27;}
			if(matrizes[2][0] == 'X' && matrizes[2][1] == 'X' && matrizes[2][2] == 'X' && matrizes[2][3] == 'X' && matrizes[2][4] == 'X'){ContadorJogadas = 27;}
			if(matrizes[3][0] == 'X' && matrizes[3][1] == 'X' && matrizes[3][2] == 'X' && matrizes[3][3] == 'X' && matrizes[3][4] == 'X'){ContadorJogadas = 27;}
			if(matrizes[4][0] == 'X' && matrizes[4][1] == 'X' && matrizes[4][2] == 'X' && matrizes[4][3] == 'X' && matrizes[4][4] == 'X'){ContadorJogadas = 27;}
			// Verificação das colunas para 'X'
			if(matrizes[0][0] == 'X' && matrizes[1][0] == 'X' && matrizes[2][0] == 'X' && matrizes[3][0] == 'X' && matrizes[4][0] == 'X'){ContadorJogadas = 27;}
			if(matrizes[0][1] == 'X' && matrizes[1][1] == 'X' && matrizes[2][1] == 'X' && matrizes[3][1] == 'X' && matrizes[4][1] == 'X'){ContadorJogadas = 27;}
			if(matrizes[0][2] == 'X' && matrizes[1][2] == 'X' && matrizes[2][2] == 'X' && matrizes[3][2] == 'X' && matrizes[4][2] == 'X'){ContadorJogadas = 27;}
			if(matrizes[0][3] == 'X' && matrizes[1][3] == 'X' && matrizes[2][3] == 'X' && matrizes[3][3] == 'X' && matrizes[4][3] == 'X'){ContadorJogadas = 27;}
			if(matrizes[0][4] == 'X' && matrizes[1][4] == 'X' && matrizes[2][4] == 'X' && matrizes[3][4] == 'X' && matrizes[4][4] == 'X'){ContadorJogadas = 27;}
			// Verificação das diagonais para 'X'
			if(matrizes[0][0] == 'X' && matrizes[1][1] == 'X' && matrizes[2][2] == 'X' && matrizes[3][3] == 'X' && matrizes[4][4] == 'X'){ContadorJogadas = 27;}
			if(matrizes[4][0] == 'X' && matrizes[3][1] == 'X' && matrizes[2][2] == 'X' && matrizes[1][3] == 'X' && matrizes[0][4] == 'X'){ContadorJogadas = 27;}

			// Verificação das linhas para 'O'
			if(matrizes[0][0] == 'O' && matrizes[0][1] == 'O' && matrizes[0][2] == 'O' && matrizes[0][3] == 'O' && matrizes[0][4] == 'O'){ContadorJogadas = 28;}
			if(matrizes[1][0] == 'O' && matrizes[1][1] == 'O' && matrizes[1][2] == 'O' && matrizes[1][3] == 'O' && matrizes[1][4] == 'O'){ContadorJogadas = 28;}
			if(matrizes[2][0] == 'O' && matrizes[2][1] == 'O' && matrizes[2][2] == 'O' && matrizes[2][3] == 'O' && matrizes[2][4] == 'O'){ContadorJogadas = 28;}
			if(matrizes[3][0] == 'O' && matrizes[3][1] == 'O' && matrizes[3][2] == 'O' && matrizes[3][3] == 'O' && matrizes[3][4] == 'O'){ContadorJogadas = 28;}
			if(matrizes[4][0] == 'O' && matrizes[4][1] == 'O' && matrizes[4][2] == 'O' && matrizes[4][3] == 'O' && matrizes[4][4] == 'O'){ContadorJogadas = 28;}
			// Verificação das colunas para 'O'
			if(matrizes[0][0] == 'O' && matrizes[1][0] == 'O' && matrizes[2][0] == 'O' && matrizes[3][0] == 'O' && matrizes[4][0] == 'O'){ContadorJogadas = 28;}
			if(matrizes[0][1] == 'O' && matrizes[1][1] == 'O' && matrizes[2][1] == 'O' && matrizes[3][1] == 'O' && matrizes[4][1] == 'O'){ContadorJogadas = 28;}
			if(matrizes[0][2] == 'O' && matrizes[1][2] == 'O' && matrizes[2][2] == 'O' && matrizes[3][2] == 'O' && matrizes[4][2] == 'O'){ContadorJogadas = 28;}
			if(matrizes[0][3] == 'O' && matrizes[1][3] == 'O' && matrizes[2][3] == 'O' && matrizes[3][3] == 'O' && matrizes[4][3] == 'O'){ContadorJogadas = 28;}
			if(matrizes[0][4] == 'O' && matrizes[1][4] == 'O' && matrizes[2][4] == 'O' && matrizes[3][4] == 'O' && matrizes[4][4] == 'O'){ContadorJogadas = 28;}
			// Verificação das diagonais para 'O'
			if(matrizes[0][0] == 'O' && matrizes[1][1] == 'O' && matrizes[2][2] == 'O' && matrizes[3][3] == 'O' && matrizes[4][4] == 'O'){ContadorJogadas = 28;}
			if(matrizes[4][0] == 'O' && matrizes[3][1] == 'O' && matrizes[2][2] == 'O' && matrizes[1][3] == 'O' && matrizes[0][4] == 'O'){ContadorJogadas = 28;}
		}while(ContadorJogadas <= 25);
		  	tabuleiro2(matrizes);
		  	if(ContadorJogadas == 26){
		  		printf("\nJogo empatado!\n\n");
		  		empate++;
			  }
			if(ContadorJogadas == 27){
				printf("\nFim de jogo! Vencedor foi -> X <-\n\n");
				venc1++;
			}
			if(ContadorJogadas == 28){
				printf("\nFim de jogo! Vencedor foi -> O <-\n\n");
				venc2++;
			}
			printf("Vitórias do jogador X: %i\n", venc1);
			printf("Vitórias do jogador O: %i\n", venc2);
			printf("Empates:               %i\n", empate);
	  printf("\nDeseja jogar novamente?[S-N]\n");
	  scanf("%s", &RespostaUsuario);
  	}while(RespostaUsuario=='s');
}
void BemVindo(void)
{
	int escolha;
  printf("     *-------*   *----*    *-----*   *----* \n");
  printf("     |__. .__|  |      |  |  .__.|  |      |\n");
  printf("        | |     | *--* |  | |       | *--* |\n");
  printf("        | |     | |  | |  | |  *-*  | |  | |\n");
  printf("     *--* |     | *--* |  | |  | |  | *--* |\n");
  printf("     |    |     |      |  | *--* |  |      |\n");
  printf("     *----*      *----*    *----*    *----*\n");
  printf("                    -> DA <-\n");
  printf("                       *-*\n");
  printf("                      / /\n");
  printf("                     *-*\n");
  printf("       *--* *--*  *------*  *---*      *    \n");
  printf("       |  | |  |  |  ____|  |   |     / \\   \n");
  printf("       *  * *  *  | |__.    |   |    /   \\  \n");
  printf("        \\  *  /   |  __|    |   |   /  *  \\  \n");
  printf("         \\   /    | |____.  |   |  *  * *  *\n");
  printf("          \\ /     |      |  |   |  |  | |  |\n");
  printf("           *      *------*  *---*  *--* *--*\n");
}
