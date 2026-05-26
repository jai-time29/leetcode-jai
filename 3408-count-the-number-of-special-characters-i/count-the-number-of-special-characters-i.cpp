class Solution {
public:

    int numberOfSpecialChars(string word) {

        unordered_set<char> seen;

        unordered_set<char> counted;

        int cnt = 0;

        for (char ch : word) {

            // lowercase
            if (islower(ch)) {

                char up = toupper(ch);

                if (seen.count(up) &&
                    !counted.count(ch)) {

                    cnt++;

                    counted.insert(ch);
                }
            }

            // uppercase
            else {

                char low = tolower(ch);

                if (seen.count(low) &&
                    !counted.count(low)) {

                    cnt++;

                    counted.insert(low);
                }
            }

            seen.insert(ch);
        }

        return cnt;
    }
};