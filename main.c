#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 15  

int main() {
    system("chcp 65001");
    
    int X[N], A, i, j, tmp, flag = 0;

    printf("1)Введіть 15 елементів масиву:\n");
    for (i = 0; i < N; i+=1) {
        scanf("%d", &X[i]);
    }

    printf("2)Введіть число для пошуку (A): ");
    scanf("%d", &A);

    for (i = 0; i < N; i+=1) {
        if (X[i] == A) {
        printf("3)Лінійний пошук A: %d\n", i);
        flag = 1;
        break;
        }
    }
    if (!flag){
    printf("3)Лінійний пошук: A не знайдено\n");
    }
    for (i = 0; i < N - 1; i+=1) {
        for (j = i + 1; j < N; j+=1) {
            if (X[j] > X[i]) { 
                tmp = X[i];
                X[i] = X[j];
                X[j] = tmp;
            }
        }
    }

    printf("4)Відсортований масив: ");
    for (i = 0; i < N; i+=1) {
    printf("%d ", X[i]);
    printf("\n");
    }

    int left = 0, right = N - 1, mid;
    flag = 0;
    while (left <= right) {
        mid = (int)((left + right) / 2);
        if (X[mid] == A) {
            printf("5)Бінарний пошук A: %d\n", mid);
            flag = 1;
            break;
        }
        if (X[mid] < A) {
            right = mid - 1 ;
        }
        else left = mid + 1;
    }
    if (!flag) {
        printf("Бінарний пошук: A не знайдено\n");
    }

    return 0;
}
