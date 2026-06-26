class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> dupe = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (dupe.contains(nums[i])) {
                return true;
            }
            else {
                dupe.add(nums[i]);
            }
        }
        return false;
    }
}
