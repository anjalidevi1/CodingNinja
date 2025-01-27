Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move prev to the node just before left
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode* start = prev->next; // Node at position left
        ListNode* then = start->next; // Node at position left + 1

        // Reverse the sublist from left to right
        for (int i = 0; i < right - left; ++i) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }

        return dummy->next;
    }
};
