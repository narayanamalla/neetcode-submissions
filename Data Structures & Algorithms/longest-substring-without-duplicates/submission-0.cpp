class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int Hashlen = 256;
        int hash[Hashlen];
        for(int i = 0; i < Hashlen;i++){
            hash[i] = -1;
        }
        int l = 0, r= 0, maxlen = 0;
        while(r<n){
            if(hash[s[r]] != -1){
                l = max(hash[s[r]]+1,l);
            }
            maxlen = max(maxlen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};