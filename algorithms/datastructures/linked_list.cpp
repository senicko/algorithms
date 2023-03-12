#include <iostream>

template <typename T> struct Node {
  Node *next = nullptr;
  T value;

  Node(T value) : value(value) {}
};

template <typename T> class LinkedList {
  Node<T> *head = nullptr;
  Node<T> *tail = nullptr;
  size_t _size = 0;

public:
  ~LinkedList() {
    while (head != nullptr) {
      Node<T> *next = head->next;
      delete head;
      head = next;
    }
  }

  size_t size() { return _size; }
  bool is_empty() { return _size == 0; }

  Node<T> *last() { return tail; }
  Node<T> *first() { return head; }

  /// Prints values stored inside the linkedlist.
  void print() {
    Node<T> *current = head;

    std::cout << "[ ";

    while (current != nullptr) {
      std::cout << current->value << ' ';
      current = current->next;
    }

    std::cout << "]\n";
  }

  /// Adds a new node to the front of the linked list.
  /// time complexity - O(1)
  void push_front(T value) {
    Node<T> *created = new Node<T>(value);
    created->next = head;
    head = created;

    if (is_empty())
      tail = head;

    _size++;
  }

  /// Adds a new node to the back of the linked list.
  /// time complexity - O(1)
  void push_back(T value) {
    Node<T> *created = new Node<T>(value);

    if (is_empty())
      head = created;
    else
      tail->next = created;

    tail = created;
    _size++;
  }

  /// Removes first element from the linked list.
  void remove_first() {
    if (is_empty())
      return;

    Node<T> *tmp = head;
    head = head->next;
    delete tmp;
    _size--;

    if (is_empty())
      tail = nullptr;
  }
};

int main() {
  LinkedList<int> *list = new LinkedList<int>;

  list->push_front(10);
  list->print();

  std::cout << list->last()->value << std::endl;

  list->remove_first();
  list->print();

  if (!list->last())
    std::cout << "list is empty" << std::endl;

  delete list;
  return 0;
}