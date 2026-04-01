import java.util.*;

class Solution {
    public int findMinDifference(List<String> timePoints) {
    
        List<Integer> list = new ArrayList<>();
        
        for (String t : timePoints) {
            String[] parts = t.split(":");
            int hours = Integer.parseInt(parts[0]);
            int minutes = Integer.parseInt(parts[1]);
            list.add(hours * 60 + minutes);
        }
        Collections.sort(list);

    
        int minDiff = 1440;
        
        for (int i = 1; i < list.size(); i++) {
            int diff = list.get(i) - list.get(i - 1);
            minDiff = Math.min(minDiff, diff);
        }

        // Step 4: Check circular difference (last and first)
        int circularDiff = 1440 - list.get(list.size() - 1) + list.get(0);
        minDiff = Math.min(minDiff, circularDiff);

        return minDiff;
    }
}