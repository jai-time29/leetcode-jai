class Solution {
public:

    vector<int> parse(string s) {

        // remove trailing i
        s.pop_back();


        int pos = s.find('+',1);


        int real = stoi(s.substr(0,pos));

        int imag = stoi(s.substr(pos+1));


        return {real, imag};
    }



    string complexNumberMultiply(string num1, string num2) {


        vector<int> a = parse(num1);
        vector<int> b = parse(num2);


        int real = a[0]*b[0] - a[1]*b[1];

        int imag = a[0]*b[1] + a[1]*b[0];


        return to_string(real) + "+" + to_string(imag) + "i";
    }
};