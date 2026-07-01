class Solution {
public:

    vector<string> words;
    string result;

    unordered_map<char,int> mp;
    vector<int> used = vector<int>(10,0);

    bool dfs(int col, int row, int sum, int carry) {


        // all result columns processed
        if(col == result.size()) {
            return carry == 0;
        }

 unordered_set<char> leading;

        for(auto &w: words)
    if(w.size()>1)
        leading.insert(w[0]);

if(result.size()>1)
    leading.insert(result[0]);
        // process all words for this column
        if(row < words.size()) {

            if(col >= words[row].size()) {
                return dfs(col,row+1,sum,carry);
            }


            char c = words[row][words[row].size()-1-col];


            if(mp.count(c)) {

                return dfs(col,row+1,
                           sum+mp[c],
                           carry);
            }


            else {

                for(int d=0; d<=9; d++) {

                    if(used[d])
                        continue;


                    // leading zero not allowed
                    if(d==0 && leading.count(c))
    continue;

                    mp[c]=d;
                    used[d]=1;


                    if(dfs(col,row+1,sum+d,carry))
                        return true;


                    used[d]=0;
                    mp.erase(c);
                }

            }
        }


        else {

            // now check result character

            int total=sum+carry;

            int digit=total%10;
            int newCarry=total/10;


            char c=result[result.size()-1-col];


            if(mp.count(c)) {

                if(mp[c]!=digit)
                    return false;

                return dfs(col+1,0,0,newCarry);
            }


            else {


                if(used[digit])
                    return false;


                if(digit==0 && leading.count(c))
    return false;

                mp[c]=digit;
                used[digit]=1;


                if(dfs(col+1,0,0,newCarry))
                    return true;


                used[digit]=0;
                mp.erase(c);

            }

        }


        return false;
    }



    bool isSolvable(vector<string>& w, string r) {

        words=w;
        result=r;

int mx = 0;

for(auto &w : words)
    mx = max(mx, (int)w.size());

if(result.size() < mx || result.size() > mx + 1)
    return false;
        // More than 10 unique letters impossible
       
        unordered_set<char> st;

        for(auto &x:words)
            for(char c:x)
                st.insert(c);

        for(char c:result)
            st.insert(c);


        if(st.size()>10)
            return false;


        return dfs(0,0,0,0);
    }
};