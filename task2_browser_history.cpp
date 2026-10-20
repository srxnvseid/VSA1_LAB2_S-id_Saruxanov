#include <bits/stdc++.h>
using namespace std;

struct PageNode {
    int id;
    string url;
    string visitTime;
    PageNode* next;
};

struct BrowserStack {
    PageNode* top;
};

void visitPage(BrowserStack& history, int id, string url, string visitTime) {
    PageNode* newNode = new PageNode{id, url, visitTime, history.top};
    history.top = newNode;
}

void goBack(BrowserStack& history) {
    if (history.top == nullptr) {
        cout << "History is empty.\n";
        return;
    }

    PageNode* temp = history.top;
    history.top = history.top->next;
    delete temp;
}

void currentPage(BrowserStack history) {
    if (history.top == nullptr) {
        cout << "History is empty.\n";
        return;
    }

    cout << history.top->url << " - " << history.top->visitTime << "\n";
}

void displayHistory(BrowserStack history) {
    PageNode* temp = history.top;
    while (temp != nullptr) {
        cout << temp->id << " - " << temp->url
             << " - " << temp->visitTime << "\n";
        temp = temp->next;
    }
}

int countPages(BrowserStack history) {
    int count = 0;
    PageNode* temp = history.top;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearStack(BrowserStack& history) {
    while (history.top != nullptr) {
        goBack(history);
    }
}

int main() {
    BrowserStack history{nullptr};
    int choice;

    do {
        cout << "\n1. Visit Page\n2. Back\n3. Current Page\n";
        cout << "4. Display History\n5. Count Pages\n6. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string url, visitTime;

            cout << "Page ID: ";
            cin >> id;
            cin.ignore();
            cout << "URL: ";
            getline(cin, url);
            cout << "Visit time: ";
            getline(cin, visitTime);

            visitPage(history, id, url, visitTime);
        } else if (choice == 2) {
            goBack(history);
        } else if (choice == 3) {
            currentPage(history);
        } else if (choice == 4) {
            displayHistory(history);
        } else if (choice == 5) {
            cout << "Page count: " << countPages(history) << "\n";
        }
    } while (choice != 6);

    clearStack(history);
    return 0;
}

