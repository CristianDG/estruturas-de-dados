package main

import (
	"fmt"
)

type Node[T any] struct {
	value T
	next *Node[T]
}


type Stack[T any] struct {
	head *Node[T]
	size uint
}

func (stack *Stack[T]) push(item T) {

	stack.size++
	older_head := stack.head

	node := &Node[T]{value: item, next: older_head}

	stack.head = node

}

func (stack *Stack[T]) pop() interface{} {
	stack.size--
	older_head := stack.head

	if older_head == nil { return nil }

	stack.head = older_head.next

	return older_head.value

}

func (stack *Stack[T]) peek() T {
	return stack.head.value
}

func (stack *Stack[T]) print(){
	fmt.Printf("Stack of size %d\n", stack.size)
	curr := stack.head
	for curr != nil {
		fmt.Println("->", curr.value)
		curr = curr.next
	}
}


func main(){

	stack := Stack[int]{ head:nil }

	stack.push(1)
	stack.push(2)
	stack.push(3)
	stack.print()

	fmt.Println("peek:", stack.peek())
	fmt.Println("pop:", stack.pop())
	fmt.Println("pop:", stack.pop())
	stack.print()

}
