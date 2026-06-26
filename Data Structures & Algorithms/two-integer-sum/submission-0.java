class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        Map<Integer, Integer> vals = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int diff = target - num;
            if (vals.containsKey(diff)) {
                return new int[] {vals.get(diff), i};
            }
            vals.put(num, i);
        }
        return res;
    }
}
