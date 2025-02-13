#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n, i, *ptr;

    //getting n 
    printf("Enter number of elements: ");
    scanf("%d", &n);


    //allocating memory for n elements
    ptr = (int*)calloc(n, sizeof(int));

    // //Taking input
    printf("Enter the elements in their respective order: ");
    for (i = 0; i < n; i++){
        scanf("%d", ptr + i);
    }
    
    //printing the elements
    printf("The elements are: ");
    for(i=0;i<n;i++){
        printf("%d ", *(ptr + i));
    }
    
    free(ptr);
    ptr=NULL;

    return 0;
}