class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagrams = new HashMap<>();
        for (int i = 0; i < strs.length; i++) {
            String s = strs[i];
            char[] charArr = s.toCharArray();
            Arrays.sort(charArr);
            String lol = new String(charArr);

            if (!anagrams.containsKey(lol)) {
                anagrams.put(lol, new ArrayList<>());
            }
            anagrams.get(lol).add(s);
        }
        return new ArrayList<>(anagrams.values()); 
    }
}
