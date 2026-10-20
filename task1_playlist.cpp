#include <bits/stdc++.h>
using namespace std;

struct Node { // mahnilari saxlayacaq bir node 
    int id;
    string name;
    Node* next;
};

Node* addSong(Node* head, int id, string name) {
    Node* newNode = new Node{id, name, nullptr};

    if (head == nullptr) { 
        return newNode;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

void displaySongs(Node* head) {
    Node* temp = head;

    while (temp != nullptr) { // null olana qeder gezib pointerle cap edirik
        cout << temp->id << " - " << temp->name << "\n";
        temp = temp->next;
    }
}

void searchSong(Node* head, int id) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "Found: " << temp->name << "\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Song not found.\n";
}

Node* deleteSong(Node* head, int id) {
    if (head == nullptr) {          // node bosdursa emeliyyat olmur 
        return head;
    }

    if (head->id == id) { // ilk yerde eger dayanibsa 
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;

    while (temp->next != nullptr && temp->next->id != id) {  // sona qeder yoxlanir dayandigi yerden evveldeki hisse ile sonraki node birlesir cari node silinir 
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* deletedNode = temp->next;
        temp->next = deletedNode->next;
        delete deletedNode;
    }

    return head;
}

int countSongs(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

Node* playNextSong(Node* head) {
    if (head == nullptr) {
        cout << "Playlist is empty.\n";
        return head;
    }

    cout << "Playing: " << head->name << "\n";

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

void clearPlaylist(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    head = addSong(head, 1, "Song1");
    head = addSong(head, 2, "Song2");
    head = addSong(head, 3, "Song3");

    cout << "Playlist:\n";
    displaySongs(head);

    searchSong(head, 2);

    head = deleteSong(head, 2);

    cout << "\nAfter deletion:\n";
    displaySongs(head);

    cout << "\nSong count: " << countSongs(head) << "\n";

    head = playNextSong(head);

    cout << "\nRemaining songs:\n";
    displaySongs(head);

    clearPlaylist(head);

    return 0;
}
