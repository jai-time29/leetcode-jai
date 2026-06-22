class Solution {
public:
    int compareVersion(string version1, string version2) {

        int n1 = version1.size();
        int n2 = version2.size();

        int i = 0, j = 0;


        while(i < n1 || j < n2) {

            long long num1 = 0;
            long long num2 = 0;


            // extract revision from version1
            while(i < n1 && version1[i] != '.') {

                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }


            // extract revision from version2
            while(j < n2 && version2[j] != '.') {

                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }


            if(num1 < num2)
                return -1;

            if(num1 > num2)
                return 1;


            // skip '.'
            if(i < n1 && version1[i] == '.')
                i++;

            if(j < n2 && version2[j] == '.')
                j++;
        }


        return 0;
    }
};