class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y < target)return false;
        if(target==0)return true;
        return target%gcd(x,y)==0;
    }
};