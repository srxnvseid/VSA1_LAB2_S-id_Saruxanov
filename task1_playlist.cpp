#include <bits/stdc++.h>
using namespace std;

struct SongNode {
    int id;
    string name;
    string artist;
    double duration;
    SongNode* next;
};

void addSong(SongNode*& head, int id, string name, string artist, double duration) {
    SongNode* newNode = new SongNode{id, name, artist, duration, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    SongNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteSong(SongNode*& head, int id) {
    if (head == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    if (head->id == id) {
        SongNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Song deleted.\n";
        return;
    }

    SongNode* temp = head;
    while (temp->next != nullptr && temp->next->id != id) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Song not found.\n";
        return;
    }

    SongNode* deletedNode = temp->next;
    temp->next = deletedNode->next;
    delete deletedNode;
    cout << "Song deleted.\n";
}

void searchSong(SongNode* head, int id) {
    while (head != nullptr) {
        if (head->id == id) {
            cout << head->name << " - " << head->artist
                 << " - " << head->duration << " minutes\n";
            return;
        }
        head = head->next;
    }
    cout << "Song not found.\n";
}

void displayPlaylist(SongNode* head) {
    while (head != nullptr) {
        cout << head->id << " - " << head->name << " - "
             << head->artist << " - " << head->duration << " minutes\n";
        head = head->next;
    }
}

int countSongs(SongNode* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

void playNextSong(SongNode*& head) {
    if (head == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "Playing: " << head->name << "\n";
    SongNode* temp = head;
    head = head->next;
    delete temp;
}

void clearPlaylist(SongNode*& head) {
    while (head != nullptr) {
        SongNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    SongNode* head = nullptr;
    int choice;

    do {
        cout << "\n1. Add Song\n2. Delete Song\n3. Search Song\n";
        cout << "4. Display Playlist\n5. Play Next Song\n";
        cout << "6. Count Songs\n7. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name, artist;
            double duration;

            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Artist: ";
            getline(cin, artist);
            cout << "Duration: ";
            cin >> duration;

            addSong(head, id, name, artist, duration);
        } else if (choice == 2) {
            int id;
            cout << "ID: ";
            cin >> id;
            deleteSong(head, id);
        } else if (choice == 3) {
            int id;
            cout << "ID: ";
            cin >> id;
            searchSong(head, id);
        } else if (choice == 4) {
            displayPlaylist(head);
        } else if (choice == 5) {
            playNextSong(head);
        } else if (choice == 6) {
            cout << "Song count: " << countSongs(head) << "\n";
        }
    } while (choice != 7);

    clearPlaylist(head);
    return 0;
}

