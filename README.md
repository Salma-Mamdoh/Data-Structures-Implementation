# Data Structures Implementation

<p>This project contains implementations of various data structures in C++, including:</p>

<ul>
  <li>Array-Based List</li>
  <li>Single Linked List</li>
  <li>Doubly Linked List</li>
  <li>Circular Linked List</li>
  <li>Stack</li>
  <li>Queue</li>
</ul>

<p>Each data structure has its own set of methods that can be used to interact with the structure. Additionally, there are several problems included that can be solved using these data structures.</p>

<h2>Array-Based List</h2>

<p>The Array-Based List implementation includes the following methods:</p>

<ul>
  <li><code>insert(elementType element): void</code></li>
  <li><code>insertAt(elementType element, int index): void</code></li>
  <li><code>retrieveAt(int index): elementType</code></li>
  <li><code>removeAt(int index): void</code></li>
  <li><code>replaceAt(elementType newElement, int index)</code></li>
  <li><code>isItemAtEqual(elementType element, int index): bool</code></li>
  <li><code>isEmpty(): bool</code></li>
  <li><code>isFull(): bool</code></li>
  <li><code>listSize(): int</code></li>
  <li><code>maxListSize(): int</code></li>
  <li><code>clear(): void</code></li>
  <li><code>print(): void</code></li>
</ul>
<h2>Single Linked List</h2>

<p>The Single Linked List implementation includes the following methods:</p>

<ul>
  <li><code>insertAtHead(elementType element): void</code></li>
  <li><code>insertAtTail(elementType element): void</code></li>
  <li><code>insertAt(elementType element, int index): void</code></li>
  <li><code>removeAtHead(): void</code></li>
  <li><code>removeAtTail(): void</code></li>
  <li><code>removeAt(int index): void</code></li>
  <li><code>retrieveAt(int index): elementType</code></li>
  <li><code>replaceAt(elementType newElement, int index)</code></li>
  <li><code>isExist(elementType element): bool</code></li>
  <li><code>isItemAtEqual(elementType element, int index): bool</code></li>
  <li><code>swap(int firstItemIdx, int secondItemIdx): void</code> (swap two nodes without swapping data)</li>
  <li><code>isEmpty(): bool</code></li>
  <li><code>linkedListSize(): int</code></li>
  <li><code>clear(): void</code></li>
  <li><code>print(): void</code></li>
</ul>

<h2>Doubly Linked List</h2>

<p>The Doubly Linked List implementation includes the following methods:</p>

<ul>
  <li><code>insertAtHead(elementType element): void</code></li>
  <li><code>insertAtTail(elementType element): void</code></li>
  <li><code>insertAt(elementType element, int index): void</code></li>
  <li><code>insertAfter(* prev_node, int data): void</code></li>
  <li><code>removeAtHead(): void</code></li>
  <li><code>removeAtTail(): void</code></li>
  <li><code>removeAt(int index): void</code></li>
  <li><code>retrieveAt(int index): elementType</code></li>
  <li><code>replaceAt(elementType newElement, int index)</code></li>
  <li><code>isExist(elementType element): bool</code></li>
  <li><code>isItemAtEqual(elementType element, int index): bool</code></li>
  <li><code>swap(int firstItemIdx, int secondItemIdx): void</code> (swap two nodes without swapping data)</li>
  <li><code>reverse(): void</code> (reverse the data in the double linked list)</li>
  <li><code>isEmpty(): bool</code></li>
  <li><code>doubleLinkedListSize(): int</code></li>
  <li><code>clear(): void</code></li>
  <li><code>forwardTraversal(): void</code> (Print from head to tail)</li>
  <li><code>backwardTraversal(): void</code> (Print from tail to head)</li>
</ul>

<h2>Circular Linked List</h2>

<p>The Circular Linked List implementation includes the following methods:</p>

<ul>
  <li><code>insertAtHead(elementType element): void</code></li>
  <li><code>insertAtEnd(elementType element): void</code></li>
  <li><code>insertAt(elementType element, int index): void</code></li>
  <li><code>removeAtHead(): void</code></li>
  <li><code>removeAtEnd(): void</code></li>
  <li><code>removeAt(int index): void</code></li>
  <li><code>retrieveAt(int index): elementType</code></li>
  <li><code>replaceAt(elementType newElement, int index)</code></li>
  <li><code>isExist(elementType element): bool</code></li>
  <li><code>isItemAtEqual(elementType element, int index): bool</code></li>
  <li><code>swap(int firstItemIdx, int secondItemIdx): void</code> (swap two nodes without swapping data)</li>
  <li><code>isEmpty(): bool</code></li>
  <li><code>circularLinkedListSize(): int</code></li>
  <li><code>clear(): void</code></li>
  <li><code>print(): void</code></li>
</ul>

<h2>Stack</h2>

<p>The Stack implementation includes the following methods:</p>

<ul>
 <li><code>push(elementType element): void</code></li>
  <li><code>pop(): void</code></li>
  <li><code>top(): elementType</code></li>
  <li><code>isEmpty(): bool</code></li>
  <li><code>isFull(): bool</code></li>
  <li><code>stackSize(): int</code></li>
</ul>

<h2>Queue</h2>

<p>The Queue implementation includes the following methods:</p>

<ul>
  <li><code>enqueue(elementType element): void</code></li>
  <li><code>dequeue(): void</code></li>
  <li><code>front(): elementType</code></li>
  <li><code>isEmpty(): bool</code></li>
  <li><code>isFull(): bool</code></li>
  <li><code>queueSize(): int</code></li>
</ul>

<h2>Problems</h2>

<p>This project includes several problems that can be solved using the implemented data structures. These problems are:</p>

<h2>Linked List Problems</h2>

<h3>Problem 1: Combine Nodes Between Zeros</h3>

<p>Given a linked list containing a sequence of integers separated by 0s, merge all nodes between any two consecutive 0s into a single node whose value is the total of all the merged nodes. There are no two consecutive nodes with value == 0. There should be no 0s in the new list.</p>

<h3>Problem 2: Merge K Sorted Linked Lists</h3>

<p>Given k linked-lists, each linked-list is sorted in ascending order, merge all the linked-lists into one sorted linked-list.</p>

<h2>Stack Problems</h2>

<h3>Problem 1: Convert the Infix Expression to Postfix Expression</h3>

<p>Given a string representing an infix expression, convert it to postfix expression.</p>

<h3>Problem 2: Longest Valid Parentheses</h3>

<p>Given a string containing the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.</p>

<h2>Queue Problems</h2>

<h3>Problem 1: Generate Binary Numbers from 1 to N</h3>

<p>Write a function that generates and prints all binary integers from 1 to N.</p>

<h3>Problem 2: Implement a Stack</h3>

<p>Implement a stack that supports push and pop operations using the enqueue and dequeue operations of the queue. You can use one or more queues.</p>

<h3>Problem 3: Sorting a Queue</h3>

<p>Given a queue with random integer elements, sort it.</p>
