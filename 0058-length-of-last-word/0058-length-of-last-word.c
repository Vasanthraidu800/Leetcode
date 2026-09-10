int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int i = len - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count the length of the last word
    int count = 0;
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
}