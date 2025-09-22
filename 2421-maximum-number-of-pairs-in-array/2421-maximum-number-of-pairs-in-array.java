class Solution {
    public int[] numberOfPairs(int[] nums) {
        HashMap<Integer,Integer>map = new HashMap<>();
         for (int x : nums) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
         int pairs=0;
         int left_over=0;
         int[] res = new int[2];
        for(int cnt :map.values())
        {
            pairs += cnt/2;
            left_over += cnt%2;
        }
        res[0]=pairs;
        res[1]=left_over;
        return res;
    }
}