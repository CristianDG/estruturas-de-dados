#include <stdio.h>
#include <stdlib.h>
#include <optional>

template <typename T>
struct Node{
  T value;
  Node<T>* next;
};

template <typename T>
class Stack {
  Node<T>* m_head;
  int m_size;
public:

  Stack(){
    m_head = NULL;
    m_size = 0;
  }

  void push(T item) {

    auto node = static_cast<Node<T>*>(malloc(sizeof(Node<T>)));

    auto prev_head = m_head;

    m_size++;

    node->value = item;
    m_head = node;
    m_head->next = prev_head;

  }

  auto peek() -> T {
    return m_head->value;
  }

  auto pop() -> T {

    // FIXME nem me fale disso :)
    if (!m_head->next){ return -1; }

    m_size--;
    auto prev_head = m_head;
    auto value = prev_head->value;
    m_head = prev_head->next;
    free(prev_head);

    return value;

  }

  void print(){
    Node<T>* curr = m_head;

    printf("Stack of size %d\n", m_size);
    while (curr) {
      printf("-> %d\n", curr->value);
      curr = curr->next;
    }

  }


};



int main(){

  auto stack = Stack<int>();

  stack.push(1);
  stack.push(2);
  stack.push(3);

  stack.print();

  printf("peek: %d\n", stack.peek());
  printf("pop: %d\n", stack.pop());
  printf("pop: %d\n", stack.pop());

  stack.print();

  return 0;
}
