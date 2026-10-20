#include <bits/stdc++.h>
using namespace std;

struct PassengerNode {
    int id;
    string name;
    string flightNumber;
    PassengerNode* next;
};

struct CheckInQueue {
    PassengerNode* front;
    PassengerNode* rear;
};

void addPassenger(CheckInQueue& queue, int id, string name, string flightNumber) {
    PassengerNode* newNode = new PassengerNode{id, name, flightNumber, nullptr};

    if (queue.front == nullptr) {
        queue.front = newNode;
        queue.rear = newNode;
    } else {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}

void checkInPassenger(CheckInQueue& queue) {
    if (queue.front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << queue.front->name << " checked in.\n";
    PassengerNode* temp = queue.front;
    queue.front = queue.front->next;
    delete temp;

    if (queue.front == nullptr) {
        queue.rear = nullptr;
    }
}

void peekNextPassenger(CheckInQueue queue) {
    if (queue.front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << queue.front->name << " - " << queue.front->flightNumber << "\n";
}

void displayQueue(CheckInQueue queue) {
    PassengerNode* temp = queue.front;
    while (temp != nullptr) {
        cout << temp->id << " - " << temp->name
             << " - " << temp->flightNumber << "\n";
        temp = temp->next;
    }
}

int countPassengers(CheckInQueue queue) {
    int count = 0;
    PassengerNode* temp = queue.front;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue(CheckInQueue& queue) {
    while (queue.front != nullptr) {
        PassengerNode* temp = queue.front;
        queue.front = queue.front->next;
        delete temp;
    }
    queue.rear = nullptr;
}

int main() {
    CheckInQueue queue{nullptr, nullptr};
    int choice;

    do {
        cout << "\n1. Add Passenger\n2. Check-In Passenger\n";
        cout << "3. Peek Next Passenger\n4. Display Queue\n";
        cout << "5. Count Passengers\n6. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name, flightNumber;

            cout << "Passenger ID: ";
            cin >> id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Flight number: ";
            getline(cin, flightNumber);

            addPassenger(queue, id, name, flightNumber);
        } else if (choice == 2) {
            checkInPassenger(queue);
        } else if (choice == 3) {
            peekNextPassenger(queue);
        } else if (choice == 4) {
            displayQueue(queue);
        } else if (choice == 5) {
            cout << "Passenger count: " << countPassengers(queue) << "\n";
        }
    } while (choice != 6);

    clearQueue(queue);
    return 0;
}

