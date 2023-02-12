#include <iostream>

template <typename T> struct Node {
  Node *next = nullptr;
  Node *prev = nullptr;
  T value;

  Node(T value) : value(value) {}
};

// Doubly linked list allows to delete a node from arbitraty position in O(1)
// time, as we have access to the node preceeding the deleted node.
template <typename T> class DoublyLinkedList {
  // sentinel (dummy, guard) nodes that simplify operations with cost of a
  // bit more memory being used. With them we are guaranteed that whatever
  // we'll do we will operate on a node between two nodes.
  Node<T> *header;
  Node<T> *trailer;
  size_t _size = 0;

  void place_between(T value, Node<T> *predecessor, Node<T> *successor) {
    Node<T> *node = new Node<T>(value);

    node->prev = predecessor;
    node->next = successor;

    predecessor->next = node;
    successor->prev = node;

    _size++;
  }

  void remove(Node<T> *node) {
    Node<T> *predecessor = node->prev;
    Node<T> *successor = node->next;

    predecessor->next = successor;
    successor->prev = predecessor;

    _size--;
    delete node;
  }

public:
  DoublyLinkedList() {
    header = new Node<T>();
    trailer = new Node<T>();

    header->next = trailer;
    trailer->prev = header;
  }

  ~DoublyLinkedList() {
    while (header != nullptr) {
      Node<T> *tmp = header;
      header = header->next;
      delete tmp;
    }
  }

  size_t size() { return _size; }
  bool is_empty() { return _size == 0; }

  Node<T> *first() { return header->next; }
  Node<T> *last() { return trailer->prev; }

  void push_front(T value) { place_between(value, header, header->next); }
  void push_back(T value) { place_between(value, trailer->prev, trailer); }

  void remove_first() {
    if (is_empty())
      return;
    remove(header->next);
  }

  void remove_last() {
    if (is_empty())
      return;
    remove(trailer->prev);
  }
};

int main() { return 0; }