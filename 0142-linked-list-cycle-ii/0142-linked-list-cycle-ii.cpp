/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        map<ListNode*, int> mpp;
        int count = 0;
        while(temp && mpp.find(temp) == mpp.end()){
            mpp[temp] = count;
            count++;
            temp = temp->next;
        }
        if(temp){
           return temp; 
        }
        return NULL;
    }
};