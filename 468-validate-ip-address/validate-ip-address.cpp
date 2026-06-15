class Solution {
public:

    bool checkIPv4(string s){

        vector<string> parts;
        string temp;

        for(char c:s){

            if(c=='.'){
                parts.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }

        parts.push_back(temp);


        if(parts.size()!=4)
            return false;


        for(string &x:parts){

            if(x.empty() || x.size()>3)
                return false;


            // only digits
            for(char c:x){
                if(!isdigit(c))
                    return false;
            }


            // leading zero
            if(x.size()>1 && x[0]=='0')
                return false;

            
            int num=stoi(x);

            if(num>255 ||num<0)
                return false;
        }


        return true;
    }



    bool checkIPv6(string s){

        vector<string> parts;
        string temp;


        for(char c:s){

            if(c==':'){
                parts.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }

        parts.push_back(temp);



        if(parts.size()!=8)
            return false;



        for(string &x:parts){

            if(x.size()<1 || x.size()>4)
                return false;


            for(char c:x){

                if(!isdigit(c) &&
                   !(c>='a' && c<='f') &&
                   !(c>='A' && c<='F'))
                    return false;
            }
        }


        return true;
    }



    string validIPAddress(string queryIP) {

        bool hasDot=false;
        bool hasColon=false;


        for(char c:queryIP){

            if(c=='.')
                hasDot=true;

            if(c==':')
                hasColon=true;
        }


        if(hasDot && hasColon)
            return "Neither";


        if(hasDot){

            if(checkIPv4(queryIP))
                return "IPv4";
        }


        if(hasColon){

            if(checkIPv6(queryIP))
                return "IPv6";
        }


        return "Neither";
    }
};