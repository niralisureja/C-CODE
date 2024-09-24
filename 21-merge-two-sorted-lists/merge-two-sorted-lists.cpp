/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If one of the lists is empty, return the other
        if (!list1) return list2;
        if (!list2) return list1;
        
        // Create a dummy node to start the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // Traverse both lists and add the smaller node to the merged list
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        // Add remaining nodes of list1, if any
        if (list1) current->next = list1;
        
        // Add remaining nodes of list2, if any
        if (list2) current->next = list2;
        
        // Return the head of the merged list (skip the dummy node)
        return dummy->next;
    }
};