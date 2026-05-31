class Solution {
public:
    bool isNumber(string s) {

        bool digitSeen = false;
        bool dotSeen = false;
        bool eSeen = false;

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // digit
            if(isdigit(ch)) {

                digitSeen = true;
            }

            // sign
            else if(ch == '+' || ch == '-') {

                // only valid at beginning
                // or immediately after e/E
                if(i > 0 && s[i-1] != 'e' && s[i-1] != 'E')
                    return false;
            }

            // decimal point
            else if(ch == '.') {

                // only one dot
                // cannot appear after e
                if(dotSeen || eSeen)
                    return false;

                dotSeen = true;
            }

            // exponent
            else if(ch == 'e' || ch == 'E') {

                // only one e
                // must have number before e
                if(eSeen || !digitSeen)
                    return false;

                eSeen = true;

                // now exponent part must contain digits
                digitSeen = false;
            }

            else {

                return false;
            }
        }
        return digitSeen;
    }
};