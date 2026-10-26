#include <iostream>
#include <string>
using namespace std;

const int capacity = 100;

class Job {
	
	public:
	    string name;
	    int priority;
	    int arrival;
	
	    Job() {
	        name = "";
	        priority = 0;
	        arrival = 0;
	    }
	
	    Job(string n, int p, int a) {
	        name = n;
	        priority = p;
	        arrival = a;
	    }
};

class PriorityQueue {
	
	private:
	    Job heap[capacity];
	    int size;
	    int arrivalCounter;
	
	public:
	    PriorityQueue() {
	        size = 0;
	        arrivalCounter = 0;
	    }
	
	    bool higherPriority(Job a, Job b) {
	        if (a.priority != b.priority) {
	            if (a.priority < b.priority) {
	                return true;
	            }
	            else {
	                return false;
	            }
	        }
	
	        if (a.arrival < b.arrival) {  //if not on priority then on basis of arrival
	            return true;
	        }
	        else {
	            return false;
	        }
	    }
	
	    void push(string name, int priority) {
	        if (size == capacity) {
	            cout << "Priority queue is full!" << endl;
	            return;
	        }
	
	        heap[size].name = name;
	        heap[size].priority = priority;
	        heap[size].arrival = arrivalCounter++;
	
	        int i = size;
	        size++;
	
	        while (i > 0) {
	            int parent = (i - 1) / 2;
	
	            if (higherPriority(heap[i], heap[parent])) {
	                swap(heap[i], heap[parent]);
	                i = parent;
	            }
	            else {
	                break;
	            }
	        }
	    }
	
	    string pop() {
	        if (size == 0) {
	            cout << "Priority queue is empty!" << endl;
	            return "";
	        }
	
	        string jobName = heap[0].name;
	
	        heap[0] = heap[size - 1];
	        size--;
	
	        int i = 0;
	
	        while (true) {
	            int left = 2 * i + 1;
	            int right = 2 * i + 2;
	            int small = i;
	
	            if (left < size && higherPriority(heap[left], heap[small])) {
	                small = left;
	            }
	
	            if (right < size && higherPriority(heap[right], heap[small])) {
	                small = right;
	            }
	
	            if (small == i) {
	                break;
	            }
	
	            swap(heap[i], heap[small]);
	            i = small;
	        }
	
	        return jobName;
	    }
	
	    string peek() {
	        if (size == 0) {
	            cout << "Priority queue is empty!" << endl;
	            return "";
	        }
	
	        return heap[0].name;
	    }
};

int main() {
	
    PriorityQueue p;

    p.push("J1", 3);
    p.push("J2", 1);
    p.push("J3", 2);
    cout << "POP: " << p.pop() << endl;
    p.push("J4", 1);
    p.push("J5", 3);
    cout << "POP: " << p.pop() << endl;
    cout << "POP: " << p.pop() << endl;
    p.push("J6", 2);
    cout << "POP: " << p.pop() << endl;
    cout << "POP: " << p.pop() << endl;
    cout << "POP: " << p.pop() << endl;

    //(b):

    cout << endl;
    
    int heapB[capacity];
    string jobsB[capacity];
    int sizeB = 0;

    // pushing A, B, C, all w priority = 1
    heapB[sizeB] = 1;
    jobsB[sizeB] = "A";
    sizeB++;

    heapB[sizeB] = 1;
    jobsB[sizeB] = "B";
    sizeB++;

    heapB[sizeB] = 1;
    jobsB[sizeB] = "C";
    sizeB++;

    cout << "POP: " << jobsB[0] << endl;

    // last job (C) moved to root
    jobsB[0] = jobsB[sizeB - 1];
    heapB[0] = heapB[sizeB - 1];
    sizeB--;

    cout << "POP: " << jobsB[0] << endl;
    cout << "POP: " << jobsB[1] << endl;   //expected: A,C,B


    return 0;
}

//(a):
//POP: J2
//POP: J4
//POP: J3
//POP: J6
//POP: J1
//POP: J5

//(b):
//POP: A
//POP: C
//POP: B

//(c): 
//the whole code implementation

//(d): 
//in the hand written assignment
