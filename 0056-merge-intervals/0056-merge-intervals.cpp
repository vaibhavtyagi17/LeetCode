class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>mergedIntervals;
        vector<int>tempi=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(tempi[1]>=intervals[i][0]){
                tempi[1]=max(tempi[1],intervals[i][1]);
            }
            else{
                mergedIntervals.push_back(tempi);
                tempi=intervals[i];
            }
        }
        mergedIntervals.push_back(tempi);
        return mergedIntervals;
    }
};