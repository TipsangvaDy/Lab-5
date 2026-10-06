#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value);
};

Node::Node(int value) : data(value), next(nullptr) {}

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void insertFront(int value);
    void insertBack(int value);
    void print();

    int getSize() const;
    bool isEmpty() const;
    bool search(int value) const;
    bool getAt(int index, int& value) const;
    bool deleteFront();
    bool deleteValue(int value);
    bool insertAt(int index, int value);
};

LinkedList::LinkedList() : head(nullptr), size(0) {}

void LinkedList::insertFront(int value) {
    Node* p = new Node(value);
    p->next = head;
    head = p;
}

void LinkedList::insertBack(int value) {
    Node* p = new Node(value);

    if (head == nullptr) {
        head = p;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = p;
}

void LinkedList::print() {
    cout << "List: ";
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

LinkedList::~LinkedList() {
    Node* cur = head;
    while (cur != nullptr) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
}

int LinkedList::getSize() const {
    return 0;
}

bool LinkedList::isEmpty() const {
    return true;
}

bool LinkedList::search(int value) const {
    return false;
}

bool LinkedList::getAt(int index, int& value) const {
    return false;
}

bool LinkedList::deleteFront() {
    return false;
}

bool LinkedList::deleteValue(int value) {
    return false;
}

bool LinkedList::insertAt(int index, int value) {
    return false;
}

int main() {
    LinkedList list;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "insertFront") {
            int value;
            cin >> value;
            list.insertFront(value);
        } else if (cmd == "insertBack") {
            int value;
            cin >> value;
            list.insertBack(value);
        } else if (cmd == "print") {
            list.print();
        } else if (cmd == "size") {
            cout << "size: " << list.getSize() << endl;
        } else if (cmd == "empty") {
            cout << "empty: " << (list.isEmpty() ? "yes" : "no") << endl;
        } else if (cmd == "search") {
            int value;
            cin >> value;
            cout << "search " << value << ": "
                 << (list.search(value) ? "yes" : "no") << endl;
        } else if (cmd == "getAt") {
            int index;
            cin >> index;
            int value = -1;
            if (list.getAt(index, value))
                cout << "getAt " << index << ": " << value << endl;
            else
                cout << "getAt " << index << ": fail" << endl;
        } else if (cmd == "deleteFront") {
            cout << "deleteFront: "
                 << (list.deleteFront() ? "yes" : "no") << endl;
        } else if (cmd == "deleteValue") {
            int value;
            cin >> value;
            cout << "delete " << value << ": "
                 << (list.deleteValue(value) ? "yes" : "no") << endl;
        } else if (cmd == "insertAt") {
            int index, value;
            cin >> index >> value;
            cout << "insertAt " << index << " " << value << ": "
                 << (list.insertAt(index, value) ? "yes" : "no") << endl;
        }
    }

    return 0;
}
