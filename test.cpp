#include<iostream>

using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node* prev;
    Node (int arg_data) : data (arg_data), next (nullptr), prev (nullptr)
    {}
};

class DoublyLinkedList {

    private:
    Node * head;
    public:

    DoublyLinkedList () {
        head = nullptr;
    }

    // Return the head node.
    Node * GetHead () {
        return head;        
    }

    // Create a head node of the doubly linked list.
    void CreateHead (int data) {
        head = new Node(data);
    }

    // Insert a new node into the doubly-linked list after the first found node.
    void Insert (int data, int after) {

        Node* current = head;

        // Traverse the linked list till the node is found after
        // which the data is to be insert
        while (current != nullptr && current->data != after) {
            current = current->next;
        }

        if (current != nullptr) {
            Node * temp = new Node(data);
            // Save the location of node after current in next_node.
            Node * next_node = current->next;
            // Point current's link to the new node to be inserted.
            current->next = temp;

            // Point new node's next link (to the next node location previously stored).
            // left link to the current node.
            temp->prev  = current;
            temp->next = next_node;

            // Point next node's prev to the newly added node i.e temp.
            if (next_node != nullptr)
                next_node->prev = temp;
        }
    }

    // Delete the first node matching the data from the doubly linked list.
    void Delete (int data_to_be_deleted ) {

        // If the head node is to be deleted, then the node to the next of head becomes the head node.
        if (head->data == data_to_be_deleted ) {
            Node * temp = head->next;
            delete head;
            head = temp;
            head->prev = nullptr;
        } else {
            Node * current = head;
            while (current->data != data_to_be_deleted ) {
                current = current->next;
            }
            // current is to be deleted.
            if (current != nullptr) {
                current->prev->next = current->next; // Update the next link of the node previous of current
                if (current->next != nullptr) {
                    current->next->prev = current->prev; // Update the previous link of the node to the next of current
                }
                delete current;
            }
        }
    }

    // Append a node to the doubly linked list.
    void Append (int data) {

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        Node* temp = new Node(data);
        current->next = temp;
        temp->prev = current;
    }

    // Display all the nodes in the doubly linked list.
    void Display () {

        Node* current = head;
        cout << "[ ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "]";
    }

    // Free the linked list.
    void FreeList () {

        while (head != nullptr) {
            Node * temp = head->next;
            delete head;
            head = temp;
        }
    }
};

int main() {

    DoublyLinkedList s;
    int data, after, opt = 0;

    while (opt != 5) {
        cout << "\n\nOptions" << endl;
        cout << "0. Create head." << endl;
        cout << "1. Insert node." << endl;
        cout << "2. Append node." << endl;
        cout << "3. Delete node." << endl;
        cout << "4. Free the linked list." << endl;
        cout << "5. Exit." << endl;
        cout << "Enter Option : ";
        cin >> opt;
        switch (opt) {

        case 0:
            cout << "Linked list ";
            s.Display();
            if (s.GetHead() != nullptr) {
                cout << "\nHead exist." << endl;
            } else {
                cout << "\nEnter head node (data) : ";
                cin >> data;
                s.CreateHead(data);
                s.Display();
            }
            break;

        case 1:
            cout << "Linked list ";
            s.Display();
            cout << "\nEnter new node (data) : ";
            cin >> data;
            cout << "After node : ";
            cin >> after;
            s.Insert(data, after);
            s.Display();
            break;

        case 2:
            cout << "Linked list ";
            s.Display();
            cout << "\nEnter new node (data) : ";
            cin >> data;
            s.Append(data);
            s.Display();
            break;

        case 3:
            cout << "Linked list ";
            s.Display();
            cout << "\nEnter node (data) to be deleted : ";
            cin >> data;
            s.Delete(data);
            s.Display();
            break;

        case 4:
            cout << "Freeing the linked list." << endl;
            s.FreeList();
            break;
        }
    }
    return 0;
}

