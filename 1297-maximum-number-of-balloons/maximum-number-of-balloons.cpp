class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>freq,freq1;
        string s = "balloon";
        for(char c : s){
            freq[c]++;
        }
        for(char c : text){
           freq1[c]++;
        }
        int mini=INT_MAX;
        for(auto it : freq){
            
            mini=min(mini,freq1[it.first]/freq[it.first]);
            
        }
        return mini;
    }
};