#include <stdio.h>

int main(){
    char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int navio1[3]; // navio horizontal
    int navio2[3]; // navio vertical

    //Criando o tabuleiro
    int tabuleiro [10][10];
    
   // Preencher tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //navio na horizontal
    int linha1 = 2;
    int coluna1 = 3;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha1][coluna1 + i] = 3;
    }

    //Navio na vertical
    int linha2 = 5;
    int coluna2 = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha2 + i][coluna2] = 3;
    }

    // Imprimir cabeçalho (letras A-J)
    printf("   ");
    for (int i = 0; i < 10; i++){
        printf(" %c", linha[i]);  
    }

    printf("\n");

    // Imprimir o tabuleiro com números nas linhas
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);  // linha numerada com alinhamento
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}