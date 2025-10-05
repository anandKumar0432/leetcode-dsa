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
        int count = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }
        int del = count - n;
        temp = head;
        if(n == count){
            ListNode* t = head;
            head = head->next;
            delete t;
            return head;
        }
        while(temp && del > 1){
            temp = temp->next;
            del--;
        }
        if(temp && temp->next){
            ListNode* t = temp->next;
            temp->next = temp->next->next;
            delete t;
        }
        return head;
    }
};