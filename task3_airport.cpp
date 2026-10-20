#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    string name;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void enqueue(Queue& passengers, int id, string name) { // en sona elave edirik (rear)
    Node* newNode = new Node{id, name, nullptr};

    if (passengers.rear == nullptr) {
        passengers.front = newNode;
        passengers.rear = newNode;
        return;
    }

    passengers.rear->next = newNode;
    passengers.rear = newNode;
}

void dequeue(Queue& passengers) { // en ondekini silirik 
    if (passengers.front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Checked in: " << passengers.front->name << "\n";

    Node* temp = passengers.front;
    passengers.front = passengers.front->next;
    delete temp;

    if (passengers.front == nullptr) {
        passengers.rear = nullptr;
    }
}

void peek(Queue passengers) { // en qabaqdakini cap edirik (ilk node yeni head eslinde front hesab edilir en son node ise rear)
    if (passengers.front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Next passenger: " << passengers.front->name << "\n";
}

void display(Queue passengers) {
    Node* temp = passengers.front;

    while (temp != nullptr) {
        cout << temp->id << " - " << temp->name << "\n";
        temp = temp->next;
    }
}

void clearQueue(Queue& passengers) {
    while (passengers.front != nullptr) {
        Node* temp = passengers.front;
        passengers.front = passengers.front->next;
        delete temp;
    }

    passengers.rear = nullptr;
}

int main() {
    Queue passengers{nullptr, nullptr};

    enqueue(passengers, 1, "Ali");
    enqueue(passengers, 2, "Leyla");
    enqueue(passengers, 3, "Nigar");

    cout << "Passenger queue:\n";
    display(passengers);

    peek(passengers);

    dequeue(passengers);

    cout << "\nAfter check-in:\n";
    display(passengers);

    peek(passengers);

    clearQueue(passengers);

    return 0;
}
