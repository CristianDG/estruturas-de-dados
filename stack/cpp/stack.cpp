#include <iostream>

template <typename T>
struct Node{
  T value;
  Node<T>* next;
};

template <typename T>
class Stack{
  Node<T>* m_head;
  int m_length;
public:

  Stack(){
    m_head = NULL;
    m_length = 0;
  }

  void push(T item) {

    auto node = static_cast<Node<T>*>(malloc(sizeof(Node<T>)));

    auto prev_head = m_head;

    m_length++;

    node->value = item;
    m_head = node;
    m_head->next = prev_head;

  }

  auto pop() -> T {

    if (!m_head->next){ return NULL; }

    m_length--;
    auto prev_head = m_head;
    m_head = prev_head->next;
    free(prev_head);

    return m_head->value;

  }

  void print(){
    Node<T>* curr = m_head;

    printf("Stack of leangth %d\n", m_length);
    while (curr) {
      std::cout << "--> " << curr->value << "\n";
      curr = curr->next;
    }

  }


};




int main(){

  auto stack = new Stack<int>();

  stack->push(1);
  stack->push(2);
  stack->push(3);
  stack->print();
  printf("pop: %d\n", stack->pop());
  printf("pop: %d\n", stack->pop());
  stack->print();

  return 0;
}
