class MyStack {
public:

    int topIndex;
    int stack[100];

    MyStack() {
        topIndex = -1;
    }
    
    void push(int x) {

        topIndex++;
        stack[topIndex] = x;
    }
    
    int pop() {

        int y = stack[topIndex];
        topIndex--;

        return y;
    }
    
    int top() {

        return stack[topIndex];
    }
    
    bool empty() {

        if(topIndex == -1) {
            return true;
        }

        return false;
    }
};
