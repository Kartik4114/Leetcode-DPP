class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        
        int height1 = 0;
    bool useRed = true;  // Start with red on the first row
    int currentRow = 1;
        
    int red1=red;
    int blue1=blue;
    
    while (true) {
        if (useRed) {
            if (red1 >= currentRow) {
                red1 -= currentRow;
                height1++;
                currentRow++;
                useRed = !useRed;
            } else {
                break;
            }
        } else {
            if (blue1 >= currentRow) {
                blue1 -= currentRow;
                height1++;
                currentRow++;
                useRed = !useRed;
            } else {
                break;
            }
        }
    }
        
    int height2 = 0;
    bool useBlue = true;  // Start with red on the first row
    int r2 = 1;
    
    
    while (true) {
        if (useBlue) {
            if (blue >= r2) {
                blue -= r2;
                height2++;
                r2++;
                useBlue = !useBlue;
            } else {
                break;
            }
        } else {
            if (red >= r2) {
                red -= r2;
                height2++;
                r2++;
                useBlue = !useBlue;
            } else {
                break;
            }
        }
    }
    
    return max(height1,height2);
        
    }
};