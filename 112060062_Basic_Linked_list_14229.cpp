#include <iostream>
#include <cassert>
using namespace std;

class Node {
public:
    int val;
    Node *prev, *next;

    Node(int data) : val(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head != nullptr) {
            remove_head();
        }
    }

    void insert_after(Node* pre, int data) {
        Node* nd = new Node(data);
        Node* nex = pre->next;
        nd->prev = pre;
        nd->next = nex;
        pre->next = nd;
        if (nex) nex->prev = nd;
        if (pre == tail) tail = nd;
    }

    void insert_before(Node* nxt, int data) {
        Node* nd = new Node(data);
        Node* pre = nxt->prev;
        nd->next = nxt;
        nd->prev = pre;
        nxt->prev = nd;
        if (pre) pre->next = nd;
        if (nxt == head) head = nd;
    }

    void insert_head(int data) {
        if (head == nullptr) {
            head = tail = new Node(data);
        } else {
            Node* nd = new Node(data);
            nd->next = head;
            head->prev = nd;
            head = nd;
        }
    }

    void insert_tail(int data) {
        if (head == nullptr) {
            head = tail = new Node(data);
        } else {
            Node* nd = new Node(data);
            nd->prev = tail;
            tail->next = nd;
            tail = nd;
        }
    }

    void remove_head() {
        if (head == nullptr) return;
        Node* nd = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete nd;
    }

    void remove_tail() {
        if (head == nullptr) return;
        Node* nd = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete nd;
    }

    char search(int data) {
        if (head==nullptr) return 'E';
        for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) {
            if (ptr->val == data) return 'Y';
        }
        return 'N';
    }

    void output() {
        if (head == nullptr) {
            cout << "E\n";
            return;
        }
        for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) {
            cout << ptr->val;
            if (ptr->next) cout << ' ';
            else cout << '\n';
        }
    }
};

int main() {
    int q;
    cin >> q;
    DoublyLinkedList dll;

    while (q--) {
        string op;
        cin >> op;
        if (op == "IH") {
            int i;
            cin >> i;
            dll.insert_head(i);
        } else if (op == "IT") {
            int i;
            cin >> i;
            dll.insert_tail(i);
        } else if (op == "RH") {
            dll.remove_head();
        } else if (op == "RT") {
            dll.remove_tail();
        } else if (op == "S") {
            int i;
            cin >> i;
            char ans = dll.search(i);
            cout << ans << '\n';
        } else if (op == "O") {
            dll.output();
        } else {
            assert(false && "unreachable");
        }
    }

    return 0;
}
