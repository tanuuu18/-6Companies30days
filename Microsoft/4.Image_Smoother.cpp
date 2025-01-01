class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum = 0;
                int cnt = 0;
                for(int r = i-1;r<=i+1;r++){
                    for(int c = j-1;c<=j+1;c++){
                        if(r>=0&&r<n&&c>=0&&c<m){
                            sum += img[r][c];
                            cnt++;
                        }
                    }
                }
                res[i][j] = sum/cnt;
            }
        }
        return res;
    }
};
