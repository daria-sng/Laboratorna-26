#include <stdio.h>
#include <stdlib.h>
#define N 4

int main(){
    system("chcp 65001");
    int **array = (int**)malloc(N*sizeof(int*));
    if (array == NULL){
        printf("Помилка виділення пам'яті!");
        return 1;
    }
    int i;
    for(i=0;i<N;i+=1){
        array[i]=(int*)malloc(N*sizeof(int));
        if(array == NULL){
            printf("Помилка виділення пам'яті!");
            return 2;
        }
    }

    printf("Введіть цілочислені значення елементів масиву (4х4): \n");
    int j;
    for(i=0;i<N;i+=1){
        for(j=0;j<N;j+=1){
            scanf("%d", &array[i][j]);
        }
    }

    int sum_main = 0;
    int multiplication_main = 1;
    int sum_side = 0;
    int multiplication_side = 1;

    for(i=0;i<N;i+=1){
        sum_main += array[i][i];
        multiplication_main *= array[i][i];

        sum_side += array[i][N-1-i];
        multiplication_side *= array[i][N-1-i];
    }
    printf("Сума елементів головної діагоналі:\n%d\n", sum_main);
    printf("Добуток елементів головної діагоналі:\n%d\n", multiplication_main);

    printf("Сума елементів побічної діагоналі:\n%d\n", sum_side);
    printf("Добуток елементів побічної діагоналі:\n%d\n", multiplication_side);

    for (i=0;i<N;i+=1){
        free (array[i]);
    }
    free (array);
    return 0;
}