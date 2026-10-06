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
    size++;
}

void LinkedList::insertBack(int value) {
    Node* p = new Node(value);

    if (head == nullptr) {
        head = p;
        size++;
        return;
    }

    Node* cur = head;

    while (cur->next != nullptr) {
        cur = cur->next;
    }

    cur->next = p;
    size++;
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
    return size;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

bool LinkedList::search(int value) const {
    Node* cur = head;

    while (cur != nullptr) {
        if (cur->data == value) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool LinkedList::getAt(int index, int& value) const {
    if (index < 0 || index >= size) {
    return false;
    }
    Node* cur = head;

    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    value = cur->data;
    return true;
}

bool LinkedList::deleteFront() {
    if (head == nullptr) {
        return false;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    size--;
    return true;
}

bool LinkedList::deleteValue(int value) {
    if (head == nullptr) {
        return false;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;

        size--;
        return true;
    }

    Node* cur = head;

    while (cur->next != nullptr) {
        if (cur->next->data == value) {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;

            size--;
            return true;
        }

        cur = cur->next;
    }

    return false;
}

bool LinkedList::insertAt(int index, int value) {
    if (index < 0 || index > size) {
        return false;
    }

    if (index == 0) {
        insertFront(value);
        return true;
    }

    if (index == size) {
        insertBack(value);
        return true;
    }

    Node* cur = head;

    for (int i = 0; i < index - 1; i++) {
        cur = cur->next;
    }

    Node* p = new Node(value);
    p->next = cur->next;
    cur->next = p;

    size++;
    return true;
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
