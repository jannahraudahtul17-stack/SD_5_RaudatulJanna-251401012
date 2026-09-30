#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;
};

node* front = NULL;
node* rear = NULL;

// FUNSI QUEUE (FIFO)
// 1. Enqueue
void enqueue (int n) {
    node *newnode= new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (front == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear -> next = newnode;
        rear = newnode;
    }
    cout << n << " berhasil di enqueue" << endl;
}

// 2. Dequeue
void dequeue () {
    if (front == NULL) {
        cout << "Queue kosong, tidak bisa dequeue!" << endl;
        return;
    }

    node *temp = front;
    cout << temp -> value << " berhasil di dequeue" << endl;
    front = front -> next;

    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}

// 3. Peek
void peek () {
    if (front == NULL) {
        cout << "Queue kosong!" << endl;
        return;
    }
    cout << "Data paling depan : " << front -> value << endl;
}

// 4. isEmpty
bool isEmpty () {
    return front == NULL;
}

void display () {
    if (isEmpty ()) {
        cout << "Queue kosong!" << endl;
        return;
    }

    node *temp = front;
    cout << "Isi queue : ";
    while (temp != NULL) {
        cout << temp -> value << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main () {
    system ("cls");

    enqueue(10);
    display();
    enqueue(20);
    display();
    enqueue(30);
    display();

    peek();

    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();

    return 0;
}