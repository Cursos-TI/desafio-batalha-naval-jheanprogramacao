#include <stdio.h>
#include <stdlib.h>

#define linhas 10
#define colunas 10
#define TAM_HAB 5

int main(){
    char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Criando o tabuleiro
    int tabuleiro [10][10];
    //Habilidades
    int cone[5][5], cruz[5][5], octaedro[5][5];
    
   // Preencher tabuleiro com 0
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    //Lógica do cone
    for (int i = 0; i < 3; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            if (j >= 0 && j < 5) cone[i][j] = 1;
        }
    }

    //Lógica da cruz
    for (int i = 0; i < TAM_HAB; i++) {
        cruz[2][i] = 1;
        cruz[i][2] = 1;
    }

    //Lógica do octaedro
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }
    
    //Exibição do cone
    int origemConeLinha = 2;
    int origemConeColuna = 7;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int l = origemConeLinha + i - 2;
                int c = origemConeColuna + j - 2;
                if (l >= 0 && l < 10 && c >= 0 && c < 10)
                    tabuleiro[l][c] = 5; // valor da habilidade cone
            }
        }
    }

    //Exibição da cruz
    int origemCruzLinha = 4;
    int origemCruzColuna = 2;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int l = origemCruzLinha + i - 2;
                int c = origemCruzColuna + j - 2;
                if (l >= 0 && l < 10 && c >= 0 && c < 10)
                tabuleiro[l][c] = 1; // valor da habilidade cruz
            }
        }
    }

    //Exibição do octaedro
    int origemOctaLinha = 7;
    int origemOctaColuna = 7;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int l = origemOctaLinha + i - 2;
                int c = origemOctaColuna + j - 2;
                if (l >= 0 && l < 10 && c >= 0 && c < 10)
                tabuleiro[l][c] = 7; // valor da habilidade octaedro
            }
        }
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