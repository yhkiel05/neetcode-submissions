class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        // compare matches now
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (freq1[i] == freq2[i]) {
                matches++;
            }
        }
        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            if (matches == 26) {
                return true;
            }
            int index = s2[r] - 'a';
            freq2[index]++;
            if (freq1[index] == freq2[index]) {
                matches++;
            } else if (freq1[index] + 1 == freq2[index]) {
                matches--;
            }
            index = s2[l] - 'a';
            freq2[index]--;
            if (freq1[index] == freq2[index]) {
                matches++;
            } else if (freq1[index] - 1 == freq2[index]) {
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};
