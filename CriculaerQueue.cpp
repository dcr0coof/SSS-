#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;       
    int capacity;   
    int front;      
    int rear;      
    int size;       

public:
    // 构造函数，初始化队列
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue is full, cannot enqueue!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // 循环队列，尾部指针循环移动
        arr[rear] = value;
        size++;
    }


    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty, cannot dequeue!" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity; 
        size--;
        return value;
    }


    int peek() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << arr[index] << " ";
            index = (index + 1) % capacity;  // 循环输出
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue queue(5); 

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    cout << "Queue after enqueuing elements: ";
    queue.display();

    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    cout << "Queue after dequeuing elements: ";
    queue.display();

    queue.enqueue(60);
    queue.display();

    return 0;
}
