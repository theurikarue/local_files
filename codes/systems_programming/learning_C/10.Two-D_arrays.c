// Use of 2-D arrays and nested for loops

#include<stdio.h>
#include<stdlib.h>

int main(){

    int numbers [3][3] = {
        {2,5,5},
        {3,4,7},
        {5,7,9},
    };

    // printf("%d\n",numbers[1][2]);
    

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ",numbers[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
