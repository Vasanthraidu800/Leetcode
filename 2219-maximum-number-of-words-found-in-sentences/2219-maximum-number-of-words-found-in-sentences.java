class Solution {
    public int mostWordsFound(String[] sentences) {
        int max_space_cnt = 0;

        for (int i = 0; i < sentences.length; i++) {
            int space_cnt = 0;

            for (int j = 0; j < sentences[i].length(); j++) {
                if (sentences[i].charAt(j) == ' ')
                    space_cnt++;
            }

            if (space_cnt > max_space_cnt)
                max_space_cnt = space_cnt;
        }

        return max_space_cnt + 1; 
    }
}
