class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int n=intervals.size();
        int count =0;
        int i=1; vector<int>l=intervals[0];
        while(i<n){
           int curr_end=intervals[i][1];
           int curr_start=intervals[i][0];
           int last_end=l[1];
           if(curr_start>=last_end){
            l=intervals[i];
            i++;
           }
           else if (curr_end>=last_end){
            count++;
            i++;
           }
           else if(last_end>curr_end){
            l=intervals[i];
           
            i++;
             count++;
           }
        }
        return count;
    }
};