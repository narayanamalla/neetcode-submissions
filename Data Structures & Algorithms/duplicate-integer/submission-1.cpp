class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       if (nums.empty()) return false;
       sort(nums.begin(), nums.end());
       int i = 0;
       int j = 1;
       for(; j < nums.size(); ){
        if(nums[i] != nums[j]){
            i++;
            j++;
        }
        else{
            return true;
        }
       }
       return false;
    }
};