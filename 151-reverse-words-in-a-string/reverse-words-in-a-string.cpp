class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);
        vector<string> words;

        string word;

        while(ss >> word)
            words.push_back(word);


        reverse(words.begin(), words.end());

        string ans;
        if(words.size()>0)ans+=words[0];
        for(int i=1;i<words.size();i++){

            ans += " ";

            ans += words[i];
        }

        return ans;
    }
};