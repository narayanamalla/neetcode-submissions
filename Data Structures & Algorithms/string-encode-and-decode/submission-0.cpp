class Solution {
public:
    
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& str : strs) {
            
            encoded += to_string(str.length()) + "#" + str;
        }
        return encoded;
    }

    
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.length()) {
            
            int delimiter_pos = s.find('#', i);
            
            
            int length = stoi(s.substr(i, delimiter_pos - i));
            
           
            string str = s.substr(delimiter_pos + 1, length);
            decoded.push_back(str);
            
           
            i = delimiter_pos + 1 + length;
        }
        
        return decoded;
    }
};