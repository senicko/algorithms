#include <iostream>

struct Node {
  Node *next;
  int value;

  Node(int value) : value(value) {}
};

class LinkedList {
  Node *head = nullptr;

  Node *reverse_rec(Node *prev, Node *current) {
    if (current->next == nullptr) {
      current->next = prev;
      return current;
    }

    Node *next = current->next;
    current->next = prev;
    return reverse_rec(current, next);
  }

public:
  ~LinkedList() {
    while (head != nullptr) {
      Node *next = head->next;
      delete head;
      head = next;
    }
  }

  /// Adds element to the front of linked list
  void push_front(int value) {
    Node *created = new Node(value);
    created->next = head;
    head = created;
  }

  /// reverse the linked list
  void reverse() {
    Node *new_head = reverse_rec(nullptr, head);
    head = new_head;
  }

  /// Prints values stored inside the linkedlist.
  void print() {
    Node *current = head;

    std::cout << "[ ";

    while (current != nullptr) {
      std::cout << current->value << ' ';
      current = current->next;
    }

    std::cout << "]\n";
  }
};

int main() {
  LinkedList *ll = new LinkedList;

  for (int i = 0; i < 15; i++) {
    ll->push_front(i);
  }

  std::cout << "before:\n";
  ll->print();

  ll->reverse();

  std::cout << "after:\n";
  ll->print();

  return 0;
}