// Time complexity of O(1) for the push and pop operations, and 
// A space complexity that grows dynamically with the number of elements in the stack. 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;        // Pointer to dynamically allocated array
    int top;          // Index of the top element
    int maxSize;     // Current maximum size of the stack
} Stack;

/**
 * Initialize a new stack.
 * @param initialSize Initial size of the stack.
 */
Stack* createStack(int initialSize) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(initialSize * sizeof(int));
    stack->top = -1;
    stack->maxSize = initialSize;
    return stack;
}

/**
 * Check if the stack is empty.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

/**
 * Resize the stack to a new maximum size.
 * @param stack The stack to resize.
 * @param newSize The new size for the stack.
 */
void resize(Stack *stack, int newSize) {
    stack->data = (int*)realloc(stack->data, newSize * sizeof(int));
    if (stack->data == NULL) {
        fprintf(stderr, "Error: Unable to resize stack\n");
        exit(EXIT_FAILURE);
    }
    stack->maxSize = newSize;
}

/**
 * Push an element onto the stack.
 * @param stack The stack to push to.
 * @param value The value to push.
 * @return 1 if the push was successful, 0 if the stack is full.
 */
int push(Stack *stack, int value) {
    if (stack->top == stack->maxSize - 1) { // If stack is full, resize
        resize(stack, stack->maxSize * 2);
        printf("Resized stack to %d\n", stack->maxSize);
    }
    stack->data[++stack->top] = value;
    return 1;
}

/**
 * Pop an element from the stack.
 * @param stack The stack to pop from.
 * @param value Pointer to store the popped value.
 * @return 1 if the pop was successful, 0 if the stack is empty.
 */
int pop(Stack *stack, int *value) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        return 0;
    }
    *value = stack->data[stack->top--];
    return 1;
}

/**
 * Free the memory allocated for the stack.
 * @param stack The stack to free.
 */
void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

int main() {
    Stack *stack = createStack(5); // Initial size of the stack

    // Push elements onto the stack
    for (int i = 1; i <= 10; i++) {
        push(stack, i * 10); // Pushing 10, 20, ..., 100
    }

    int value;
    // Pop elements from the stack
    while (pop(stack, &value)) {
        printf("Popped value: %d\n", value);
    }

    // Free allocated memory
    freeStack(stack);

    return 0;
}
