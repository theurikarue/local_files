public class DynamicStack {
    private int[] data;        // Array to store stack elements
    private int top;          // Index of the top element
    private int maxSize;     // Current maximum size of the stack

    /**
     * Initialize a new stack.
     * @param initialSize Initial size of the stack.
     */
    public DynamicStack(int initialSize) {
        this.data = new int[initialSize];
        this.top = -1;
        this.maxSize = initialSize;
    }

    /**
     * Check if the stack is empty.
     * @return true if the stack is empty, false otherwise.
     */
    public boolean isEmpty() {
        return top == -1;
    }

    /**
     * Resize the stack to a new maximum size.
     * @param newSize The new size for the stack.
     */
    private void resize(int newSize) {
        int[] newData = new int[newSize];
        // Copy existing elements to new array
        System.arraycopy(data, 0, newData, 0, maxSize);
        data = newData;
        maxSize = newSize;
        System.out.println("Resized stack to " + maxSize);
    }

    /**
     * Push an element onto the stack.
     * @param value The value to push.
     */
    public void push(int value) {
        if (top == maxSize - 1) { // If stack is full, resize
            resize(maxSize * 2);
        }
        data[++top] = value;
    }

    /**
     * Pop an element from the stack.
     * @return The popped value.
     * @throws IllegalStateException if the stack is empty.
     */
    public int pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Error: Stack underflow");
        }
        return data[top--];
    }

    /**
     * Main method to demonstrate stack operations.
     */
    public static void main(String[] args) {
        DynamicStack stack = new DynamicStack(5); // Initial size of the stack

        // Push elements onto the stack
        for (int i = 1; i <= 10; i++) {
            stack.push(i * 10); // Pushing 10, 20, ..., 100
        }

        // Pop elements from the stack
        while (!stack.isEmpty()) {
            try {
                System.out.println("Popped value: " + stack.pop());
            } catch (IllegalStateException e) {
                System.out.println(e.getMessage());
                break;
            }
        }
    }
}
