class Solution {
    public int maxChunksToSorted(int[] arr) {
         int chunks = 0;
        int prefixMax = 0;

        for(int i = 0; i < arr.length; i++) {
            prefixMax = Math.max(prefixMax, arr[i]);
            if(prefixMax == i) {
                chunks++;
            }
        }
        return chunks;
    }
}