int gcd(int a, int b) {
    int r;
    while (a != 0) {
        r = b % a;
        b = a;
        a = r;
    }
    return b < 0 ? -b : b;
}