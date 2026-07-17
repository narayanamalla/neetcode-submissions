class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        for(int i = 0; i<2*n;i++){
            if(i < n){
                answer.push_back(nums[i]);
            }
            else{
                answer.push_back(nums[i - n]);
            }
        }
        return answer;

    }
};