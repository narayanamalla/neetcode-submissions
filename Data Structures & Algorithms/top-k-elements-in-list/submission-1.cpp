class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int num : nums){
            freq[num]++;
        }

        vector<int> result;

        while(k--){
            int maxFreq = 0;
            int element;

            for(auto it : freq){
                if(it.second > maxFreq){
                    maxFreq = it.second;
                    element = it.first;
                }
            }

            result.push_back(element);
            freq.erase(element); 
        }

        return result;
    }
};