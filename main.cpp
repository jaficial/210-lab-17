// COMSC-210 | Lab 17 | Jed Aficial
// github link: https://github.com/jaficial/210-lab-17

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};
// CITED: Cited lecture videos and lecture/demo code when rewriting this code, still need to review some concepts
// function prototypes
void output(Node *);
void delete_node(Node *, Node *, int);
void insert_node(Node *, Node *, Node *, int, int);
void add_front_node(Node *, Node *, int);
void add_tail_node();
void delete_linked_list(Node *, Node*);

// To delete node, function requires pointers for current/head node, previous node, and the node being deleted 
void delete_node(Node *current, Node *prev, int entry){
    for (int i = 0; i < (entry - 1); i++){ // traverses through the linked list, then deletes the selected node
        if (i == 0){
            current = current->next;
        }
        else{
            current = current->next;
            prev = prev->next;
        }
    }
    if (current) {
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

/* To insert node, function requires pointers for current, previous, new nodes, 
   the int for which node to insert after, and the int for the value that is being inserted*/
void insert_node(Node *current, Node *prev, Node *newnode, int entry, int value){
    for (int i = 0; i < entry; i++){
        if (i == 0){
            current = current->next;
        }
        else{
            current = current->next;
            prev = prev->next;
        }
    }
    newnode->next = current;
    prev->next = newnode;
}

/* To delete the linked list, function requires current and head node.
   Will need to traverse the linked list, deleting the allocated memory for each node,
   then assigning the node to a null pointer*/
void delete_linked_list(Node *current, Node *head){
    while(current) {
        head = current->next;
        delete current;
        current = head;
    }
}

/* to add a node to the front of the linked list, function requires the 
   pointer to the new value, pointer to the head, and the value that is being inserted. */ 
// NOTE: STILL NEED TO REVIEW THIS POST-ASSIGNMENT DUE DATE
void add_front_node(Node *newVal, Node *head, int tmp_val){
    if (!head){
        head = newVal;
        newVal->next = nullptr;
        newVal->value = tmp_val;
    }
    else{
        newVal->next = head;
        newVal->value = tmp_val;
        head = newVal;
    }
}

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
	    int tmp_val = rand() % 100;
        cout << "this is the tmp_val " << tmp_val << endl;
        Node *newVal = new Node;
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);
	
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    current = head;
    Node *prev = head;

    // Call to delete_node function for deleting a node
    delete_node(current, prev, entry);
    output(head);
   
   // inserting a value after a specified node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    Node * newnode = new Node;
    newnode->value = 10000;
    int value = newnode->value;
    // Call to insert_node function to insert the value
    insert_node(current, prev, newnode, entry, value);
    output(head);

    // deleting the linked list
    current = head;
    delete_linked_list(current, head);
   
    head = nullptr; /* NOTE: assigning head to nullptr must be in main function, 
                             have to investigate why this is the case.*/
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
