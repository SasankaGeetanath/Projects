public class Operations {
    protected int top, N;
    protected int[] stack; 

    public Operations( int value ) {
        top = -1;
        N = value;
        stack = new int[N];
    }

    public boolean search( int value ) {
        boolean searchVariable = false;
        for( int i = 0; i <= top; ++i) {
            if( value == stack[i]) {
                searchVariable = true;
                break;
            }
        }
        return searchVariable;
    }

    public int size() {
        return top + 1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == N - 1;
    }

    public void push( int value ) {
        top++;
        stack[top] = value;
    }

    public void pop() {
        System.out.print("THE DELETED ELEMENT IS " + stack[top]);
        top--;
    }

    public void display() {
        for( int i = 0; i <= top; ++i )
            System.out.print("->" + stack[i] + "\t");
    }
}