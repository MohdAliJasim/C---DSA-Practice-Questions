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
    int gcd(int a , int b){
        if(a == 0 ) return b;
        if(b == 0) return a;
        if(a > b) return gcd(a%b,b);
        return gcd(a , b%a);
        
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp->next){
            int a = temp->val;
            int b = temp->next->val;

            int c = gcd(a,b);
            ListNode* newNode = new ListNode(c);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        return head;
    }
};