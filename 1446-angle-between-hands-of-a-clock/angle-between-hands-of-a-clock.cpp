class Solution {
public:
    double angleClock(int hour, int minutes) {
        double teta1,teta2;
        if(hour==12)teta1=0.5*minutes;
        else teta1=hour*30+0.5*minutes;
        teta2=minutes*6;
        double ans = abs(teta1-teta2);
        return (ans>180)?360-ans:ans;
    }
};