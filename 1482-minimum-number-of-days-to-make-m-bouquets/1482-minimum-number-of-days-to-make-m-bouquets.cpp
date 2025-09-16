class Solution {
public:
    bool func(int mid,vector<int>&bloomDay,int m,int k){
        int c=0;
        int b=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                c++;
            }
            else{
                b+=(c/k);
                c=0;
            }
        }
        b+=(c/k);
        return (b>=m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        long long int mx=m*k;
        if(bloomDay.size()<mx) return -1;
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(func(mid,bloomDay,m,k)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};