class Solution {
private:
    vector<vector<int>>rects;
    vector<int>cum;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int totalP = 0;
        for(auto &rect:rects){
            int points = (rect[2]-rect[0]+1)*(rect[3]-rect[1]+1);
            totalP += points;
            cum.push_back(totalP);
        }
        srand(time(0));
    }
    
    vector<int> pick() {
        int target = rand()%cum.back()+1;
        int left = 0;
        int right = cum.size()-1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(cum[mid]<target){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        auto rect = rects[left];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
