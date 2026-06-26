class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false; // impossible 
        }
        vector<int> freq1(26, 0);
        int matches = 0;
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
        }
        for (int r = 0; r < s2.length(); r++) {
            vector<int> freq2(26, 0);
            if (matches == 26) {
                return true;
            }
            matches = 0;
            for (int l = r; l < s1.length() + r; l++) {
                freq2[s2[l] - 'a']++;      
            }
            for (int i = 0; i < 26; i++) {
                if (freq1[i] == freq2[i]) {
                    matches++;
                }
            }
            if (matches == 26) {
                return true;
            }
        }
        return false;
    }
};
