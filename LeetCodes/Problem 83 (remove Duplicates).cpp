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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL) {

            ListNode* temp = curr;

            while(temp->next != NULL && temp->val == temp->next->val) {

                ListNode* toDelete = temp->next;

                temp->next = toDelete->next;

                delete toDelete;
            }

            curr = curr->next;
        }

        return head;
    }
};

