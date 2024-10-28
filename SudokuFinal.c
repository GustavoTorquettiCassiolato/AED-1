#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeroDeMatriz;
    scanf("%d", &numeroDeMatriz);

    for (int matrizes = 1; matrizes <= numeroDeMatriz; matrizes++) { //N�mero de matrizes estabelecido
        int sudoku[9][9] = {0};

        //Entrada das linhas do Sudoku
        for (int m = 0; m < 9; m++) {
            for (int n = 0; n < 9; n++) {
                scanf("%d", &sudoku[m][n]);
            }
        }

        int validacao = 1; //Matriz � v�lida

        for (int linhas = 0; linhas < 9; linhas++) {
            int linha[10] = {0}; //Verifica repeti��o em linhas
            int coluna[10] = {0}; //Verifica repeti��o em colunas

            for (int col = 0; col < 9; col++) {
                //Verifica��o de linha
                int numero = sudoku[linhas][col];
                if (numero >= 1 && numero <= 9) {
                    linha[numero]++;
                    if (linha[numero] > 1) {
                        validacao = 0; //Ap�s verificar se o n�mero est� entre 1 e 9, afirma em seu vetor sua apari��o, e caso haja repeti��o, a validacao ser� 0.
                        break;
                    }
                }
                else {
                    validacao = 0; //Caso use um numero abaixo de 1 ou acima de 9.
                }

                //Verifica��o de coluna
                numero = sudoku[col][linhas];
                if (numero >= 1 && numero <= 9) {
                    coluna[numero]++;
                    if (coluna[numero] > 1) {
                        validacao = 0; //Repeticao
                    }
                }
                else {
                    validacao = 0; //Caso use um numero abaixo de 1 ou acima de 9.
                }
            }

            // Verifica��o dos blocos 3x3
            for (int blocol = 0; blocol < 3; blocol++) { //Linha do bloco
                for (int blococ = 0; blococ < 3; blococ++) { //Coluna do bloco
                    int tres[10] = {0};

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            int numero = sudoku[blocol * 3 + i][blococ * 3 + j]; //Verifica cada um elemento dos 9 em cada bloco em busca de repeti��es.

                            if (numero >= 1 && numero <= 9) {
                                tres[numero]++;
                                if (tres[numero] > 1) {
                                    validacao = 0;
                                }
                            } else {
                                validacao = 0; //Mesmo processo, caso o numero esteja acima de 9 ou abaixo de 1, o sudoku ser� invalidado.
                            }
                        }
                    }
                }
            }
        }
        printf("Instancia %d\n", matrizes);
        if (validacao) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
