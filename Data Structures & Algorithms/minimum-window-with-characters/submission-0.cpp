class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> t_freq(128, 0);
        for (char c : t) {
            t_freq[c]++;
        }

        int required = 0;
        for (int count : t_freq) {
            if (count > 0) required++;
        }

        vector<int> window_freq(128, 0);
        int formed = 0; 

        int left = 0;
        int min_len = INT_MAX;
        int min_start = 0;

        for (int right = 0; right < s.length(); ++right) {
            char right_char = s[right];
            window_freq[right_char]++;

           
            if (t_freq[right_char] > 0 && window_freq[right_char] == t_freq[right_char]) {
                formed++;
            }

           
            while (formed == required) {
               
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }

                char left_char = s[left];
                window_freq[left_char]--;

               
                if (t_freq[left_char] > 0 && window_freq[left_char] < t_freq[left_char]) {
                    formed--;
                }
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};