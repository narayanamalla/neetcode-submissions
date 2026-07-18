class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(j > i){
            int currsum = numbers[i] + numbers[j];
            if(currsum == target){
                return {i+1,j+1};
            }
            else if( currsum > target){
                j--;
            }
            else{
                i++;
            }
        }
        return{-1,-1};
    }
};
