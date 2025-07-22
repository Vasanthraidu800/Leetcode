char* categorizeBox(int length, int width, int height, int mass) {
    long long volume = (long long)length * width * height;

    int bulky = (length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000);
    int heavy = (mass >= 100);

    char* result = (char*)malloc(10 * sizeof(char)); // Allocate memory for result string

    if (bulky && heavy) {
        strcpy(result, "Both");
    } else if (bulky) {
        strcpy(result, "Bulky");
    } else if (heavy) {
        strcpy(result, "Heavy");
    } else {
        strcpy(result, "Neither");
    }

    return result; // Caller should free this memory
}