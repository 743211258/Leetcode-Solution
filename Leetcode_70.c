void climb(int n, int current, int * number_of_ways) {
    if (current > n) {
        return;
    } else if (current == n) {
        (*number_of_ways)++;
        return;
    }
    climb(n, current + 1, number_of_ways);
    climb(n, current + 2, number_of_ways);
}

int climbStairs(int n) {
    int answer = 0;
    climb(n, 0, &answer);
    return answer;
}
