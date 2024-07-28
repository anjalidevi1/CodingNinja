You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.

Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.
Illustration :
The following images depict how the deletion has been performed.
Image-I :


Image-II :


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Explanation of Sample Output 1 :
The data in the node with index 3 is 2 which has been removed.
Sample Input 2 :
3 4 5 2 6 1 9 -1
0
Sample Output 2 :
4 5 2 6 1 9
Constraints :
0 <= N <= 10^5
POS >= 0

Time Limit: 1sec
Expected Complexity :
Time Complexity  : O(N)
Space Complexity  : O(1)



Node *deleteNode(Node *head, int pos)
{
    // If the linked list is empty or pos is less than 0, return the head
    if (!head || pos < 0) return head;

    // If the node to be deleted is the head node
    if (pos == 0) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Traverse the linked list to find the node just before the one to be deleted
    Node* current = head;
    for (int i = 0; current != nullptr && i < pos - 1; ++i) {
        current = current->next;
    }

    // If position is greater than the number of nodes
    if (current == nullptr || current->next == nullptr) {
        return head;
    }

    // Node current->next is the node to be deleted
    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;

    // Free memory
    delete nodeToDelete;

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
