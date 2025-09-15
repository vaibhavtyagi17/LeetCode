class Solution {
public:
    int func(int m,vector<int>&weights){
        int c=0,d=1;
        for(int i=0;i<weights.size();i++){
            if(c+weights[i]>m){
                d++;
                c=weights[i];
            }
            else c+=weights[i];
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=0,ans=0;
        for(int w:weights){
            h+=w;
        }
        while(l<=h){
            int m=(l+h)/2;
            int daysr=func(m,weights);
            if(daysr<=days){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};