class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0;
        int rep = 0;
        int maxx = 0;
        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            maxx = max(maxx, freq[s[r]]);
            while (r - l + 1 - maxx > k) {
                freq[s[l]]--;
                l++;
            }
            rep = max(r - l + 1, rep);
        }
        return rep;
    }
};
