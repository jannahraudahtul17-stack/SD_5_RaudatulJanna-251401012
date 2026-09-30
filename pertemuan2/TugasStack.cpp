#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;
};

node* top = NULL;

// FUNGSI STACK (LIFO)
// 1. Push
void push (int n) {
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = top;
    top = newnode;

    cout << n << " berhasil di push" << endl;
}

// 2. Pop
void pop () {
    if (top == NULL) {
        cout << "Stack kosong, tidak bisa pop!" << endl;
        return;
    }

    node *temp = top;
    cout << temp -> value << " berhasil di pop" << endl;
    top = top -> next;

    delete temp;
}

// 3. Peek
void peek () {
    if (top == NULL) {
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Data palin atas : " << top -> value << endl;
}

// 4. isEmpty
bool isEmpty () {
    return top == NULL;
}

void display () {
    if (isEmpty ()) {
        cout << "Stack kosong!" << endl;
        return;
    }

    node *temp = top;
    cout << "Isi satck : ";
    while (temp != NULL) {
        cout << temp -> value << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main (){
    system ("cls");

    push(10);
    display();
    push(20);
    display();
    push(30);
    display();

    peek();

    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();

    return 0;
}