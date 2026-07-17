#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> anagram_groups;
        
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end()); 
            anagram_groups[key].push_back(s);
        }
        
       
        vector<vector<string>> result;
        result.reserve(anagram_groups.size()); 
        
        for (auto& pair : anagram_groups) {
           
            result.push_back(move(pair.second)); 
        }
        
        return result;
    }
};