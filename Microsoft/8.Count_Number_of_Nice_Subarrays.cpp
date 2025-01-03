class Solution {
public:
    int countAtMost(vector<int>& nums, int k){
        int start = 0;
        int oddCount = 0;
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                oddCount++;
            }
            while(oddCount>k){
                if(nums[start]%2==1){
                    oddCount--;
                }
                start++;
            }
            count += (i-start+1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums,k)-countAtMost(nums,k-1);
    }
};
