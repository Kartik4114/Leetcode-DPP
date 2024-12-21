class Solution {
public:
    vector<int> getLeftMax(vector<int> &height){
        
        int n=height.size();
        vector<int> leftMax(n);

        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }

        return leftMax;
    }
    vector<int> getRightMax(vector<int> &height){
        
        int n=height.size();
        vector<int> rightMax(n);

        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }

        return rightMax;
    }

    int a1(vector<int> &height){

        int n=height.size();
        if(n<=1) return 0;

        vector<int> leftMax=getLeftMax(height);
        vector<int> rightMax=getRightMax(height);;

        int result=0;
        for(int i=0;i<n;i++){

            result+=min(leftMax[i],rightMax[i]) -height[i];
        }

        return result;
    }

    int a2(vector<int> &height){

        int n=height.size();
        int left=0;
        int right=n-1;

        int leftMax=0,rightMax=0;

        int result=0;
        while(left<=right){

            if(height[left]<=height[right]){

                if(height[left]>=leftMax){
                    leftMax=height[left];
                } else {
                    result+=leftMax-height[left];
                }
                left++;
            } else {
                if(height[right]>=rightMax){
                    rightMax=height[right];
                } else {
                    result+=rightMax-height[right];
                }

                right--;
            }

        }
        return result;
    }
    int trap(vector<int>& height) {
        
        // APPROACH 1:-
        // T.C :- O(n) , S.C :- O(n)
        // return a1(height);

        // APPROACH 2:- 
        // T.C :- O(n) , S.C :-O(1)
        return a2(height);

    }
};