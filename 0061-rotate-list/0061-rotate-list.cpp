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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 1;
        if(!head){
            return nullptr;
        }
        if(k==0){
            return head;
        }
        while(temp && temp->next){
            n++;
            temp = temp->next;
        }
        temp->next = head; // making list circular first

        k = k % n;
        k = n - k; // for right rotation
        temp = head;
        while(k != 0){
            temp = head;
            head = head->next;
            k--;
        }
        temp->next = nullptr;
        return head;
    }
};