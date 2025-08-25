class Solution {
    public int canBeTypedWords(String text, String bl) {
          String[] words = text.split(" ");
           char[] chars = bl.toCharArray();
           int brokenCount=0;

          for (int i = 0; i < words.length; i++) 
          {
             for(int j=0;j<chars.length;j++)
            {
                if(words[i].contains(String.valueOf(chars[j])))
                {
                    brokenCount++;
                    break;
                }
            }
        }
        return words.length - brokenCount;
    }
}