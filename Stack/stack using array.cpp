#include <iostream>
using namespace std;

class Stack{
	private:
	    int stack[10];
	    int top;
	
	public:
	
	    Stack(){
	        top = -1;
	    }
	
	    int isEmpty(){
	        return top == -1;
	    }
	
	    int isFull(){
	        return top == 9;
	    }
	
	    void push(int item){
	        if (!isFull()){
	            top++;
	            stack[top] = item;
	        }
	        else
	        {
	            cout << "Stack Overflow!" << endl;
	        }
	    }
	
	    int pop(){
	        if (!isEmpty()){
	            int item = stack[top];
	            top--;
	            return item;
	        }
	        else{
	            cout << "Stack Underflow!" << endl;
	            return -1;
	        }
	    }
	
	    int peek(){
	        if (!isEmpty())
	            return stack[top];
	
	        cout << "Stack is empty!" << endl;
	        return -1;
	    }
	    
	    void display(){
	    	for(int i=0; i<=top; i++){
	    		cout << stack[i] << endl;
			}
		}
};

int main(){
	
	Stack s1;
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(7);
	s1.push(9);
	s1.push(1);
	cout << "POP: "<<s1.pop()<<endl;
	s1.push(2);
	cout << "PEEK: "<<s1.peek()<<endl;
	s1.display();
	
	return 0;
	
}
