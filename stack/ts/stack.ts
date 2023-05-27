
class StackNode<T>{
    public next: StackNode<T> = null
    constructor(public value: T){}
}

class Stack<T>{
    private size: number = 0
    private head: StackNode<T> = null
    constructor(){}

    get length(): number {
        return this.size
    }

    public push(value: T): void {
        const node = new StackNode(value)
        const prev_head = this.head

        node.next = prev_head
        this.head = node
        this.size++
    }

    public pop(): T {
        if(!this.head){
            return null
        }

        const prev_head = this.head
        this.head = prev_head.next
        this.size--
        return prev_head.value
    }

    public peek(): T {
        return this.head.value
    }

    public print(): void{
        console.log("Stack of size %d", this.size)
        let curr = this.head
        while (curr) {
            console.log("->", curr.value)
            curr = curr.next
        }
    }

}

const stack = new Stack<number>()
stack.push(1)
stack.push(2)
stack.push(3)

stack.print()

console.log("peek:", stack.peek())

console.log("pop:", stack.pop())
console.log("pop:", stack.pop())

stack.print()
