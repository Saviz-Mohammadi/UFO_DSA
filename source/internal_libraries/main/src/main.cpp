#include <iostream>
#include "main.hpp"

#include <sstream>

#include "vector.hpp" // Include the header file for ufo::Vector

int main() {
    // Test 1: Default constructor and push_back
    ufo::Vector<int> vec1;
    std::cout << "Initial vec1 (empty): " << vec1 << std::endl;

    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    std::cout << "vec1 after push_back(10, 20, 30): " << vec1 << std::endl;

    // Test 2: Copy constructor
    ufo::Vector<int> vec2 = vec1;
    std::cout << "vec2 (copy of vec1): " << vec2 << std::endl;

    // Test 3: Move constructor
    ufo::Vector<int> vec3 = std::move(vec1);
    std::cout << "vec3 (moved from vec1): " << vec3 << std::endl;
    std::cout << "vec1 after move (should be empty): " << vec1 << std::endl;

    // Test 4: Push back and pop back
    vec3.push_back(40);
    std::cout << "vec3 after push_back(40): " << vec3 << std::endl;
    vec3.pop_back();
    std::cout << "vec3 after pop_back(): " << vec3 << std::endl;

    // Test 5: Comparison operators
    ufo::Vector<int> vec4 = {10, 20, 30};
    ufo::Vector<int> vec5 = {10, 20, 30};
    ufo::Vector<int> vec6 = {30, 20, 10};

    std::cout << "vec4 == vec5: " << (vec4 == vec5 ? "true" : "false") << std::endl;
    std::cout << "vec4 != vec6: " << (vec4 != vec6 ? "true" : "false") << std::endl;
    std::cout << "vec4 < vec6: " << (vec4 < vec6 ? "true" : "false") << std::endl;

    // Test 6: Stream input (using stringstream for testing purposes)
    std::cout << "Enter a vector of integers (e.g., [1, 2, 3]): ";
    ufo::Vector<int> vec7;
    std::cin >> vec7;
    std::cout << "vec7 after input: " << vec7 << std::endl;

    // Test 7: Move assignment
    ufo::Vector<int> vec8;
    vec8.push_back(100);
    vec8.push_back(200);
    std::cout << "vec8 before move assignment: " << vec8 << std::endl;
    vec8 = std::move(vec3); // Move assignment
    std::cout << "vec8 after move assignment: " << vec8 << std::endl;

    return 0;
}


// int main() {
//     ufo::HashTable<int, std::string> hashTable(5);

//     // Inserting some elements
//     hashTable.insert(1, "One");
//     hashTable.insert(2, "Two");
//     hashTable.insert(3, "Three");

//     // Displaying the hash table
//     std::cout << "HashTable: " << hashTable << std::endl;

//     // Finding an element
//     try {
//         std::cout << "Key 2 maps to: " << hashTable.find(2) << std::endl;
//     } catch (const std::out_of_range& e) {
//         std::cout << e.what() << std::endl;
//     }

//     // Comparing hash tables
//     ufo::HashTable<int, std::string> otherTable(5);
//     otherTable.insert(1, "One");
//     otherTable.insert(2, "Two");
//     otherTable.insert(3, "Three");

//     if (hashTable == otherTable) {
//         std::cout << "Hash tables are equal." << std::endl;
//     } else {
//         std::cout << "Hash tables are not equal." << std::endl;
//     }

//     // Using stream extraction operator
//     std::string input = "{ 4: Four, 5: Five }";
//     std::istringstream inputStream(input);
//     ufo::HashTable<int, std::string> newTable;
//     inputStream >> newTable;
//     std::cout << "Extracted HashTable: " << newTable << std::endl;

//     return 0;
// }

// int main() {
//     // Create a PriorityQueue object for testing
//     ufo::PriorityQueue<int> pq;

//     // Enqueue elements
//     pq.enqueue(10);
//     pq.enqueue(20);
//     pq.enqueue(5);
//     pq.enqueue(30);
//     pq.enqueue(15);

//     std::cout << "Priority Queue after enqueuing elements: " << pq << std::endl;

//     // Peek at the top element
//     std::cout << "Peek at max element: " << pq.peek() << std::endl;

//     // Dequeue the top element
//     std::cout << "Dequeued max element: " << pq.dequeue() << std::endl;
//     std::cout << "Priority Queue after dequeuing: " << pq << std::endl;

//     // Test comparison operators
//     ufo::PriorityQueue<int> pq2;
//     pq2.enqueue(15);
//     pq2.enqueue(10);
//     pq2.enqueue(5);
//     pq2.enqueue(30);
//     pq2.enqueue(20);

//     if (pq == pq2) {
//         std::cout << "pq is equal to pq2" << std::endl;
//     } else {
//         std::cout << "pq is not equal to pq2" << std::endl;
//     }

//     // Test stream input (enter values like "25 35 40 5" and then a non-integer to stop)
//     ufo::PriorityQueue<int> pq3;
//     std::cout << "Enter elements to insert into pq3 (non-integer to stop): ";
//     std::cin >> pq3;
//     std::cout << "pq3 after input: " << pq3 << std::endl;

//     return 0;
// }

// int main() {
//     // Create two MaxHeap objects for testing
//     ufo::MaxHeap<int> heap1;
//     ufo::MaxHeap<int> heap2;

//     // Insert elements into the first heap
//     heap1.insert(10);
//     heap1.insert(20);
//     heap1.insert(5);
//     heap1.insert(30);
//     heap1.insert(15);

//     std::cout << "Heap 1 after insertions: " << heap1 << std::endl;

//     // Get the maximum element
//     std::cout << "Max element in Heap 1: " << heap1.getMax() << std::endl;

//     // Extract the maximum element
//     std::cout << "Extracted max from Heap 1: " << heap1.extractMax() << std::endl;
//     std::cout << "Heap 1 after extracting max: " << heap1 << std::endl;

//     // Insert elements into the second heap
//     heap2.insert(15);
//     heap2.insert(10);
//     heap2.insert(5);
//     heap2.insert(30);
//     heap2.insert(20);

//     std::cout << "Heap 2 after insertions: " << heap2 << std::endl;

//     // Testing comparison operators
//     if (heap1 == heap2) {
//         std::cout << "Heap 1 is equal to Heap 2" << std::endl;
//     } else {
//         std::cout << "Heap 1 is not equal to Heap 2" << std::endl;
//     }

//     if (heap1 < heap2) {
//         std::cout << "Heap 1 is less than Heap 2" << std::endl;
//     }

//     // Stream extraction: add elements to a new heap using cin (you can enter values like "25 35 40 5")
//     ufo::MaxHeap<int> heap3;
//     std::cout << "Enter elements to insert into Heap 3 (non-integer to stop): ";
//     std::cin >> heap3;
//     std::cout << "Heap 3 after input: " << heap3 << std::endl;

//     // Stream insertion for displaying heap contents
//     std::cout << "Heap 1: " << heap1 << std::endl;
//     std::cout << "Heap 2: " << heap2 << std::endl;
//     std::cout << "Heap 3: " << heap3 << std::endl;

//     return 0;
// }

// Testing code for the "ufo" namespace AVLTree
// void testAVLTree() {
//     ufo::AVLTree<int> tree;

//     // Test Insertion
//     std::cout << "Inserting elements into the AVL tree...\n";
//     tree.insert(10);
//     tree.insert(20);
//     tree.insert(30);
//     tree.insert(40);
//     tree.insert(50);
//     tree.insert(25);

//     tree.printTree();

//     std::cout << "In-order traversal after insertions: ";
//     tree.printInOrder();

//     // Test Traversals
//     std::cout << "Pre-order traversal: ";
//     tree.printPreOrder();

//     std::cout << "Post-order traversal: ";
//     tree.printPostOrder();

//     std::cout << "Level-order traversal: ";
//     tree.printLevelOrder();

//     // Test Depth Check
//     std::cout << "Tree depth: " << tree.depth() << std::endl;

//     // Test Deletion
//     std::cout << "\nDeleting an element (40) from the AVL tree...\n";
//     tree.remove(40);

//     std::cout << "In-order traversal after deletion: ";
//     tree.printInOrder();

//     std::cout << "Pre-order traversal after deletion: ";
//     tree.printPreOrder();

//     std::cout << "Post-order traversal after deletion: ";
//     tree.printPostOrder();

//     std::cout << "Level-order traversal after deletion: ";
//     tree.printLevelOrder();

//     // Test Comparison Operators
//     std::cout << "\nTesting comparison operators...\n";
//     ufo::AVLTree<int> anotherTree;
//     anotherTree.insert(10);
//     anotherTree.insert(20);
//     anotherTree.insert(30);
//     anotherTree.insert(50);
//     anotherTree.insert(25);

//     std::cout << "Are the two trees equal? " << (tree == anotherTree ? "Yes" : "No") << std::endl;

//     anotherTree.remove(30);
//     std::cout << "Are the two trees equal after modification? " << (tree == anotherTree ? "Yes" : "No") << std::endl;

//     // Test Stream Operators
//     std::cout << "\nTesting stream operators...\n";
//     std::cout << "Tree contents (in-order) using << operator: " << tree << std::endl;

//     std::cout << "Enter values to insert into a new AVL tree (end input with a non-integer): ";
//     ufo::AVLTree<int> inputTree;
//     std::cin >> inputTree;
//     std::cout << "Contents of the new AVL tree: " << inputTree << std::endl;

//     // Test Depth of new tree
//     std::cout << "Depth of the new AVL tree: " << inputTree.depth() << std::endl;
// }

// int main() {
//     std::cout << "Testing AVL tree with int data type:\n";
//     testAVLTree();

//     return 0;
// }

// void testQueueOperations() {
//     ufo::Queue<int> queue;

//     std::cout << "Testing enqueue and size...\n";
//     queue.enqueue(10);
//     queue.enqueue(20);
//     queue.enqueue(30);

//     std::cout << "Queue contents after enqueuing 10, 20, 30: " << queue << "\n";
//     std::cout << "Expected size: 3, Actual size: " << queue.size() << "\n\n";

//     std::cout << "Testing front and dequeue...\n";
//     std::cout << "Front element: " << queue.front() << " (Expected: 10)\n";
//     queue.dequeue();
//     std::cout << "Queue after one dequeue: " << queue << "\n";
//     std::cout << "Front element: " << queue.front() << " (Expected: 20)\n\n";

//     std::cout << "Testing is_empty...\n";
//     std::cout << "Is queue empty? " << std::boolalpha << queue.is_empty() << "\n";
//     queue.dequeue();
//     queue.dequeue();
//     std::cout << "Is queue empty after two more dequeues? " << queue.is_empty() << "\n\n";
// }

// void testCopyConstructorAndAssignment() {
//     ufo::Queue<int> queue1;
//     queue1.enqueue(1);
//     queue1.enqueue(2);
//     queue1.enqueue(3);

//     std::cout << "Testing copy constructor...\n";
//     ufo::Queue<int> queue2 = queue1;
//     std::cout << "Original queue: " << queue1 << "\n";
//     std::cout << "Copied queue: " << queue2 << "\n";

//     std::cout << "\nTesting copy assignment operator...\n";
//     ufo::Queue<int> queue3;
//     queue3.enqueue(99); // Add some initial value to check overwrite
//     queue3 = queue1;
//     std::cout << "Original queue: " << queue1 << "\n";
//     std::cout << "Assigned queue: " << queue3 << "\n\n";
// }

// void testComparisonOperators() {
//     ufo::Queue<int> queue1, queue2;
//     queue1.enqueue(10);
//     queue1.enqueue(20);
//     queue1.enqueue(30);

//     queue2.enqueue(10);
//     queue2.enqueue(20);
//     queue2.enqueue(30);

//     std::cout << "Testing comparison operators...\n";
//     std::cout << "Queue1: " << queue1 << "\n";
//     std::cout << "Queue2: " << queue2 << "\n";
//     std::cout << "Are Queue1 and Queue2 equal? " << (queue1 == queue2) << "\n";

//     queue2.dequeue();
//     queue2.enqueue(40);

//     std::cout << "Modified Queue2: " << queue2 << "\n";
//     std::cout << "Are Queue1 and Queue2 equal? " << (queue1 == queue2) << "\n";
//     std::cout << "Is Queue1 less than Queue2? " << (queue1 < queue2) << "\n";
//     std::cout << "Is Queue1 greater than Queue2? " << (queue1 > queue2) << "\n\n";
// }

// void testStreamOperators() {
//     ufo::Queue<int> queue;
//     std::istringstream input("5 15 25 35");
//     input >> queue;

//     std::cout << "Testing input and output operators...\n";
//     std::cout << "Queue after input >> operator: " << queue << "\n";

//     std::ostringstream output;
//     output << queue;
//     std::cout << "Output << operator result: " << output.str() << "\n";
// }

// int main() {
//     std::cout << "==== Queue Operations Test ====\n";
//     testQueueOperations();

//     std::cout << "\n==== Copy Constructor and Assignment Test ====\n";
//     testCopyConstructorAndAssignment();

//     std::cout << "\n==== Comparison Operators Test ====\n";
//     testComparisonOperators();

//     std::cout << "\n==== Stream Operators Test ====\n";
//     testStreamOperators();

//     return 0;
// }

// int main() {
//     ufo::ListSingle<int> list;

//     // Test append and prepend
//     std::cout << "Testing append and prepend:" << std::endl;
//     list.append(3);
//     list.append(1);
//     list.prepend(5);
//     list.prepend(7);
//     list.append(2);
//     std::cout << "List after append and prepend operations: " << list << std::endl;

//     // Test contains
//     std::cout << "\nTesting contains:" << std::endl;
//     std::cout << "Contains 3? " << (list.contains(3) ? "Yes" : "No") << std::endl;
//     std::cout << "Contains 8? " << (list.contains(8) ? "Yes" : "No") << std::endl;

//     // Test pop_front
//     std::cout << "\nTesting pop_front:" << std::endl;
//     list.pop_front();
//     std::cout << "List after popping the front element: " << list << std::endl;

//     // Test pop_target
//     std::cout << "\nTesting pop_target (removing element 1):" << std::endl;
//     list.pop_target(1);
//     std::cout << "List after popping target element 1: " << list << std::endl;

//     // Test reverse
//     std::cout << "\nTesting reverse:" << std::endl;
//     list.reverse();
//     std::cout << "List after reverse operation: " << list << std::endl;

//     // Test sort
//     std::cout << "\nTesting sort:" << std::endl;
//     list.sort();
//     std::cout << "List after sort operation: " << list << std::endl;

//     // Test clear
//     std::cout << "\nTesting clear:" << std::endl;
//     list.clear();
//     std::cout << "List after clear operation (should be empty): " << list << std::endl;

//     return 0;
// }

// int main()
// {
//     // Test creation and basic operations
//     ufo::Stack<int> stack;
//     std::cout << "Stack created. Is empty? " << (stack.is_empty() ? "Yes" : "No") << "\n";

//     // Test push and peek
//     stack.push(10);
//     stack.push(20);
//     stack.push(30);
//     std::cout << "After pushing 10, 20, 30: " << stack << "\n";
//     std::cout << "Peek top element: " << stack.peek() << "\n";

//     // Test size
//     std::cout << "Stack size: " << stack.size() << "\n";

//     // Test pop
//     std::cout << "Pop element: " << stack.pop() << "\n";
//     std::cout << "Stack after pop: " << stack << "\n";
//     std::cout << "Stack size after pop: " << stack.size() << "\n";

//     // Test comparison operators
//     ufo::Stack<int> stack2;
//     stack2.push(10);
//     stack2.push(20);
//     std::cout << "Stack2 created with elements 10, 20: " << stack2 << "\n";

//     std::cout << "Are stack and stack2 equal? " << (stack == stack2 ? "Yes" : "No") << "\n";
//     stack2.push(30);
//     std::cout << "Stack2 after pushing 30: " << stack2 << "\n";
//     std::cout << "Are stack and stack2 equal? " << (stack == stack2 ? "Yes" : "No") << "\n";
//     std::cout << "Is stack < stack2? " << (stack < stack2 ? "Yes" : "No") << "\n";

//     // Test clear
//     stack.clear();
//     std::cout << "Stack after clear: " << stack << "\n";
//     std::cout << "Is stack empty after clear? " << (stack.is_empty() ? "Yes" : "No") << "\n";

//     // Test input stream operator >>
//     std::cout << "Enter an integer to push onto stack2: ";
//     std::cin >> stack2;
//     std::cout << "Stack2 after pushing from input: " << stack2 << "\n";

//     return 0;
// }

// int main() {

//     return 0;
// }
