#include <iostream>

template <typename T> struct Node {
  T value;
  Node *next = nullptr;

  Node(T value) : value(value) {}
};

// Implementation of a circurarly linked list it the same as regular linked
// list. The only difference is that tail points to head.
//
// Circurarly likned list can be used for example for sheduling using some sort
// of algorithm known as round-robin scheduling.

template <typename T> class CircularlyLinkedList {
  Node<T> *tail = nullptr;
  size_t _size = 0;

public:
  ~CircularlyLinkedList() {
    while (tail != nullptr) {
      Node<T> *tmp = tail;
      tail = tail->next;
      delete tmp;
    }
  }

  size_t size() { return _size; }
  bool is_empty() { return _size == 0; }

  Node<T> *first() { return tail->next; }
  Node<T> *last() { return tail; }

  // Rotates tail by a single node.
  void rotate() {
    if (!is_empty())
      tail = tail->next;
  }

  // Add element after the tail.
  void push_front(T value) {
    Node<T> *created = new Node<T>(value);

    if (is_empty()) {
      created->next = created;
      tail = created;
    } else {
      created->next = tail->next;
      tail->next = created;
    }

    _size++;
  }

  // Push front but with single rotate.
  void push_back(T value) {
    push_front(value);
    rotate();
  }

  // Removes the next element after the tail.
  void remove_first() {
    if (is_empty())
      return;

    if (tail == tail->next) {
      tail = nullptr;
    } else {
      Node<T> *tmp = tail->next;
      tail = tmp->next;
      delete tmp;
    }

    _size--;
  }
};

int main() {
  CircularlyLinkedList<int> *list = new CircularlyLinkedList<int>();

  list->push_back(1);
  list->push_back(2);
  list->push_back(3);
  list->push_back(4);
  list->push_back(5);
  list->push_back(6);
  list->push_back(7);
  list->push_front(0);

  for (int i = 0; i < 10; i++) {
    std::cout << "current element: " << list->first()->value << std::endl;
    list->rotate();
  }

  return 0;
}