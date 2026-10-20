#include <iostream>
#include <string>
using namespace std;

struct Node { // websitelar haqqinda melumat saxlamaq ucun node 
    int id;
    string pageName;
    Node* next;
};

struct Stack { // node icinde stack da yalniz top ( ilk node var )
    Node* top;
};

void push(Stack& history, int id, string pageName) {
    Node* newNode = new Node{id, pageName, history.top};
    history.top = newNode;
}

void pop(Stack& history) {
    if (history.top == nullptr) {
        cout << "History is empty.\n";
        return;
    }

    Node* temp = history.top;
    history.top = history.top->next;
    delete temp;
}

void peek(Stack history) {
    if (history.top == nullptr) {
        cout << "History is empty.\n";
        return;
    }

    cout << "Current page: " << history.top->pageName << "\n";
}

void display(Stack history) {
    Node* temp = history.top;

    while (temp != nullptr) {
        cout << temp->id << " - " << temp->pageName << "\n";
        temp = temp->next;
    }
}

void clearStack(Stack& history) {
    while (history.top != nullptr) {
        pop(history);
    }
}

int main() {
    Stack history{nullptr};

    push(history, 1, "Google");
    push(history, 2, "YouTube");
    push(history, 3, "GitHub");

    cout << "Browser history:\n";
    display(history);

    peek(history);

    pop(history);

    cout << "\nAfter pressing Back:\n";
    display(history);

    peek(history);

    clearStack(history);

    return 0;
}
