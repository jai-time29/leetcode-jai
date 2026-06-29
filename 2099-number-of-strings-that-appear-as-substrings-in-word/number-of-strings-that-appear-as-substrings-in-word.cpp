// class Solution {
// public:
//     int numOfStrings(vector<string>& patterns, string word) {

//         unordered_set<string> st;

//         int n = word.size();


//         // generate all substrings
//         for(int i = 0; i < n; i++) {

//             string temp = "";

//             for(int j = i; j < n; j++) {

//                 temp += word[j];

//                 st.insert(temp);
//             }
//         }


//         int ans = 0;


//         // check patterns
//         for(string &s : patterns) {

//             if(st.count(s))
//                 ans++;
//         }


//         return ans;
//     }
// };


class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int ans = 0;

        for(string &pat : patterns) {

            if(word.find(pat) != string::npos) {
                ans++;
            }

        }

        return ans;
    }
};