class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        int closex, closey;

        if (xCenter < x1)
            closex = x1;
        else if (xCenter > x2)
            closex = x2;
        else
            closex = xCenter;

        if (yCenter < y1)
            closey = y1;
        else if (yCenter > y2)
            closey = y2;
        else
            closey = yCenter;

        if ((closex-xCenter)*(closex-xCenter) +
            (closey-yCenter)*(closey-yCenter) <= radius*radius)
            return true;

        return false;
    }
};