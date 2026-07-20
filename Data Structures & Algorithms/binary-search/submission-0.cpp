class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        while(left <= right){
            int middle = left + (right - left)/2;
            if(nums[middle] == target){
                return middle;
            }
            else if( nums[middle] < target){
                left++;
            }
            else{
                right--;
            }
        }
        return -1;
    }
};
