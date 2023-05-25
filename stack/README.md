
# Stack

## Descrição
Estrutura LIFO (o último a entrar é o primeiro a sair)

## Exemplos

```javascript
const s = new Stack()       // s = Stack [ ]

s.push(1)                   // s = Stack [ 1 ]
s.push(2)                   // s = Stack [ 2, 1 ]
s.push(3)                   // s = Stack [ 3, 2, 1 ]

const valor_peek = s.peek() // s = Stack [ 3, 2, 1 ] & valor_peek = 3

const valor_a = s.pop()     // s = Stack [ 2, 1 ]    & valor_a = 3 
const valor_b = s.pop()     // s = Stack [ 1 ]       & valor_b = 2 
const valor_c = s.pop()     // s = Stack [ ]         & valor_c = 1 
```


