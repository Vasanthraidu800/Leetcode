class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        
        for (string  sentence : sentences) {
            int spaceCount = 0;
            for (char ch : sentence) {
                if (ch == ' ') {
                    spaceCount++;
                }
            }
            int wordCount = spaceCount + 1;
            if (wordCount > maxWords) {
                maxWords = wordCount;
            }
        }

        return maxWords;
    }
};
