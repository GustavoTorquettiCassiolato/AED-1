#include <stdio.h>
int main(){
    float M[12][12];
    int L;
    scanf("%i\n", &L);
    char O;

    scanf(" %c", &O);

    int i, j = 0;
    for (i = 0; i <12; ++i){
        for (j = 0; j < 12; ++j){
            scanf("%f", &M[i][j]);
        }
    }
    float soma = 0;
    if (O == 'S'){
        for (i = 0; i < 12; ++i){
                for (j=0; j<11-i; ++j){
                    soma = soma + M[i][j];
                }
        }
        printf("%.1f\n", soma);
    }
    float media = 0;
    int quantia = 0;
    if (O == 'M'){
        for (i = 0; i < 12; ++i){
                for (j=0; j<11-i; ++j){
                    media = media + M[i][j];
                    quantia = quantia + 1;
                }
        }
        printf("%.1f\n", media/quantia);
    }

}
