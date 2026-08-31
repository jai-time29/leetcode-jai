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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2,-1);
        int ind=0;
        int lastc=-1,firstc=-1;
        if(!head || !head->next || !head->next->next)return ans;
        ListNode*curr=head->next;
        ListNode*prev=head;
        int mini=INT_MAX,maxi=INT_MIN;
        while(curr->next){
            int temp=curr->val;
            if(temp>prev->val && temp>curr->next->val){
               if(firstc<0)firstc=ind;
                if(lastc!=-1)mini=min(mini,ind-lastc);
                lastc=ind;
                maxi=max(maxi,ind-firstc);
            }
            else if(temp<prev->val && temp<curr->next->val){
                if(firstc<0)firstc=ind;
                if(lastc!=-1)mini=min(mini,ind-lastc);
                lastc=ind;
                maxi=max(maxi,ind-firstc);
            }
            ind++;
            prev=curr;
            curr=curr->next;
        }
        if(mini!=INT_MAX && maxi!=INT_MIN)ans={mini,maxi};
        return ans;
    }
};