class Solution {
public:
    static bool comparator(vector<int>&a,vector<int>&b){
        return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
    }

    int binarySearch(vector<int>&nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int pos = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=target){
                pos = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return pos;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comparator);
        vector<int>res;
        for(auto it:envelopes){
            int height = it[1];
            int pos = binarySearch(res,height);
            if(pos==-1){
                res.push_back(height);
            }
            else{
                res[pos] = height;
            }
        }
        return res.size();
    }
};
