class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        string mx = s;
        char ch = 0;

        for(char c : mx){
            if(c != '9'){
                ch = c;
                break;
            }
        }

        if(ch){
            for(char &c : mx){
                if(c == ch) c = '9';
            }
        }

        string mn = s;
        ch = mn[0];

        for(char &c : mn){
            if(c == ch) c = '0';
        }

        return stoi(mx) - stoi(mn);
    }
};