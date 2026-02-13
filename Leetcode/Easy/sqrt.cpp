class Solution {
public:
    int mySqrt(int x) {
        long low=0;
        long high=x;
        long index=0;
        while(low<=high){
            long mid=low+(high-low)/2;
            long sqrt= mid*mid;
            if(sqrt>x){
                high=mid-1;
            }
            else if(sqrt<=x){
                low=mid+1;
                index=mid;
            }
        }return (int)index;
    }
};
