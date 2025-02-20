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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        if(head == nullptr) return head;
        vector<int>ans;
        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        sort(ans.begin(),ans.end());
        temp = head;
        int i = 0;
        while(temp){
            temp->val = ans[i];
            temp= temp->next;
            i++;
        }
        return head;
    }
};