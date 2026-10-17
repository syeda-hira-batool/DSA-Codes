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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        int length = 0;

        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        if(n == length){
            ListNode* toDelete;
            toDelete = head;
            head = head->next;
            delete toDelete;

            return head;
        }

        temp = head;

        for(int i = 0; i < length-n-1; i++){
            temp = temp->next;
        }

        ListNode* toDelete;
        toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};
