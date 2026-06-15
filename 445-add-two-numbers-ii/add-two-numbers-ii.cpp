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
/*class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1, s2;


        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }


        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }


        int carry = 0;
        ListNode* head = nullptr;


        while(!s1.empty() || !s2.empty() || carry){

            int sum = carry;


            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }


            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }


            ListNode* node = new ListNode(sum % 10);

            // insert at front
            node->next = head;
            head = node;


            carry = sum / 10;
        }


        return head;
    }
}; */
class Solution {
public:

    ListNode* reverse(ListNode* head){

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }


    ListNode* add(ListNode* l1, ListNode* l2){

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        int carry = 0;

        while(l1 || l2 || carry){

            int sum = carry;

            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }


            carry = sum / 10;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy->next;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // reverse input lists
        l1 = reverse(l1);
        l2 = reverse(l2);


        // add normally
        ListNode* ans = add(l1, l2);


        // reverse result to restore most significant digit first
        ans = reverse(ans);


        return ans;
    }
};