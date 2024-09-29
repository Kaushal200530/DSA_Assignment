#include<iostream>
using namespace std;

class Node {
public:
    int coeff;
    int pow;
    Node* next;
    Node() {
        coeff = 0;
        pow = 0;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head = nullptr;

    void create_node(int x, int y) {
        Node* nn = new Node();
        nn->coeff = x;
        nn->pow = y;
        if (head == nullptr) {
            head = nn;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }

    void polyadd(LinkedList l1, LinkedList l2) {
        Node* p1 = l1.head;
        Node* p2 = l2.head;
        Node* result = new Node();
        Node* curr = result;
        while (p1 != nullptr && p2 != nullptr) {
            Node* nn = new Node();
            if (p1->pow > p2->pow) {
                nn->pow = p1->pow;
                nn->coeff = p1->coeff;
                p1 = p1->next;
            } else if (p1->pow < p2->pow) {
                nn->pow = p2->pow;
                nn->coeff = p2->coeff;
                p2 = p2->next;
            } else {
                nn->pow = p1->pow;
                nn->coeff = p1->coeff + p2->coeff;
                p1 = p1->next;
                p2 = p2->next;
            }
            curr->next = nn;
            curr = curr->next;
        }
        while (p1 != nullptr) {
            curr->next = p1;
            curr = curr->next;
            p1 = p1->next;
        }
        while (p2 != nullptr) {
            curr->next = p2;
            curr = curr->next;
            p2 = p2->next;
        }
        head = result->next;
    }

    void print_poly() {
        if (head != nullptr) {
            Node* temp = head;
            while (temp->next != nullptr) {
                cout << temp->coeff << "x^" << temp->pow << "+";
                temp = temp->next;
            }
            cout << temp->coeff << "x^" << temp->pow;
        }
    }
};

int main() {
    LinkedList l1, l2, l3;
    l1.create_node(3, 5);
    l1.create_node(5, 3);
    l1.create_node(2, 1);
    l1.create_node(1,0);
    l2.create_node(8, 4);
    l2.create_node(2,3);
    l2.create_node(7,1);
    l2.create_node(2,0);
    l1.print_poly();
    cout << endl;
    l2.print_poly();
    cout << endl;
    l3.polyadd(l1, l2);
    l3.print_poly();
    cout << endl;
    return 0;
}
