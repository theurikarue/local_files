#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n, i, *ptr,*ptr1;

    //getting n 
    printf("Enter number of elements: ");
    scanf("%d", &n);

    //allocating memory for n elements
    ptr = (int*) malloc(n * sizeof(int));

    //Taking input
    printf("Enter the elements in their respective order: ");
    for (i = 0; i < n; i++){
        scanf("%d", ptr + i);
    }
    

    printf("Enter updated value of n: ");
    scanf("%d", &n);


    //reallocating memory for n elements
    ptr1=(int*)realloc(ptr, n * sizeof(int));


    printf("Previous Address:%d new address:%d\n",ptr,ptr1);


    printf("The entered values are: ");
    for(i=0;i<n;i++){
        printf("%d ", *(ptr1 + i));
    }

    free(ptr);
    // free(ptr1);

    ptr=NULL;

    
    return 0;

}