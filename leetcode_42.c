int trap(int* height, int heightSize) {
    int start = 0;
    int start_index = 0;
    int blocked = 0;
    int result = 0;

    int hash[20001] = {0};

    for (int i = 0; i < heightSize; i++) {
        if (height[i] < start) {
            blocked += height[i];
        } else {
            int volume_filled = start * (i - start_index - 1) - blocked;
            if (volume_filled != 0) {
                hash[start_index] = 1;
                hash[i] = 1;
            }
            result += volume_filled;
            start = height[i];
            start_index = i;
            blocked = 0;
        }
    }

    start = 0;
    start_index = heightSize - 1;
    blocked = 0;
    for (int i = heightSize - 1; i >= 0; i--) {
        if (height[i] < start) {
            blocked += height[i];
        } else {
            if (hash[i] == 0 || hash[start_index] == 0) {
                result += start * (start_index - i - 1) - blocked;
            }
            start = height[i];
            start_index = i;
            blocked = 0;
        }
    }
    return result;
}
