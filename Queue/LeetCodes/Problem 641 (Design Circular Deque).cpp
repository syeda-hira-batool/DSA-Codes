class MyCircularDeque {
public:

    int arr[1000];
    int front;
    int rear;
    int size;
    int capacity;

    MyCircularDeque(int k) {
        capacity = k;
        front = 0;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value) {

        if(isFull()) {
            return false;
        }

        if(size == 0) {
            front = 0;
            rear = 0;
            arr[front] = value;
        }
        else {
            front = (front - 1 + capacity) % capacity;
            arr[front] = value;
        }

        size++;
        return true;
    }

    bool insertLast(int value) {

        if(isFull()) {
            return false;
        }

        if(size == 0) {
            front = 0;
            rear = 0;
            arr[rear] = value;
        }
        else {
            rear = (rear + 1) % capacity;
            arr[rear] = value;
        }

        size++;
        return true;
    }

    bool deleteFront() {

        if(isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    bool deleteLast() {

        if(isEmpty()) {
            return false;
        }

        rear = (rear - 1 + capacity) % capacity;
        size--;

        return true;
    }

    int getFront() {

        if(isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int getRear() {

        if(isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
