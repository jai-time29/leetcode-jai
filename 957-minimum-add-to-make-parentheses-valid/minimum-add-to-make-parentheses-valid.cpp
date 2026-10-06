class Solution {
public:
    int minAddToMakeValid(string s) {
        int moves = 0, count = 0;

for(char c : s) {
    if(c == '(') count++;
    else count--;

    if(count < 0) {
        moves++;
        count = 0;
    }
}

moves += count;
return moves;
    }
};