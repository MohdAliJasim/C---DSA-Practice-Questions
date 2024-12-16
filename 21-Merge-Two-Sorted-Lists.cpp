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
        ListNode* newHead = nullptr;
        ListNode* temp = nullptr;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(curr1 || curr2){
            ListNode* newNode = nullptr;
            if(curr1 && curr2){
                if(curr1->val < curr2->val){
                    if(newHead == nullptr){
                        newHead = new ListNode(curr1->val);
                        temp = newHead;
                    }
                    else{
                        newNode = new ListNode(curr1->val);
                        temp->next = newNode;
                        temp = newNode;
                    }
                    curr1 = curr1->next;
                }
                else{
                    if(newHead == nullptr){
                        newHead = new ListNode(curr2->val);
                        temp = newHead;
                    }
                    else{
                        newNode = new ListNode(curr2->val);
                        temp->next = newNode;
                        temp = newNode;
                    }
                    curr2 = curr2->next;
                }
            }
            else if(curr1){
                    if(newHead == nullptr){
                        newHead = new ListNode(curr1->val);
                        temp = newHead;
                    }
                    else{
                        newNode = new ListNode(curr1->val);
                        temp->next = newNode;
                        temp = newNode;
                    }
                    curr1 = curr1->next;
            }
            else{
                 if(newHead == nullptr){
                        newHead = new ListNode(curr2->val);
                        temp = newHead;
                    }
                    else{
                        newNode = new ListNode(curr2->val);
                        temp->next = newNode;
                        temp = newNode;
                    }
                    curr2 = curr2->next;
            }
        }
        return newHead;
    }
};