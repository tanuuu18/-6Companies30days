class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        unordered_map<string,int>cnt;
        int n = s.length();
        for(int i=0;i<=n-10;i++){
            string temp = s.substr(i,10);
            cnt[temp]++;
            if(cnt[temp]==2){
                res.push_back(temp);
            }
        }
        return res;
    }
};
