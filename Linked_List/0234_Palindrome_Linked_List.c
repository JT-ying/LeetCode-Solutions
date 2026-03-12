/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    if (head == NULL || head->next == NULL) {
        return true;
    }

    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode* curr = slow->next;
    struct ListNode* prev = NULL;
    struct ListNode* next = curr;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    while(prev != NULL){
        if(prev->val == head->val){
            prev = prev->next;
            head = head->next;
        }
        else{
            return false;
        }
    }
    return true;
    
}
