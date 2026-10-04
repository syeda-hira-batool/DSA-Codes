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

    ListNode* getNode(ListNode* head, int pos) {
        ListNode* temp = head;

        for(int i = 0; temp != NULL && i < pos; i++) {
            temp = temp->next;
        }

        return temp;
    }

    ListNode* swapPairs(ListNode* head) {

        int length = 0;

        ListNode* curr = head;

        while(curr != NULL) {
            length++;
            curr = curr->next;
        }

        if(length < 2) {
            return head;
        }

        int i = 0;
        ListNode* prev = NULL;  //connects the list

       while(i < length - 1) {

            ListNode* a = getNode(head, i);
            ListNode* b = getNode(head, i + 1);

            a->next = b->next;
            b->next = a;

            if(prev != NULL) {
                prev->next = b;
            }
            else {
                head = b;
            }

            prev = a;

            i = i + 2;
        }

        return head;
    }
};
