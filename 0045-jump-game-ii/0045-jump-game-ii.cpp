class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,jumps=0;
        while(r<nums.size()-1){
            int far=0;
            for(int i=l;i<=r;i++){
                far=max((nums[i]+i),far);
            }
            l=r+1;
            r=far;
            jumps++;
        }
        return jumps;
    }
};