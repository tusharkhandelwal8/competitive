string Solution::fractionToDecimal(int A, int B) {
    if (A == 0)
        return "0";
    
    // Check the sign, assign to long long for the test case A = -2^31 or B = -2^31.
    string s;
    if (A < 0 && B < 0) {
    } else if (A < 0 || B < 0) {
        s += '-';
    }
    
    long long N = std::abs((long long) A);
    long long D = std::abs((long long) B);

    // Integral part.
    s += to_string(N / D);
    N %= D;
    if (N == 0)
        return s;

    // Non-recurring part.
    s += '.';
    int d = gcd(N, D);
    N /= d;
    D /= d;
    
    while (N != 0 && gcd(D, 10) > 1) {
        N *= 10;
        s += to_string(N / D);
        N %= D;

        int d = gcd(N, D);
        N /= d;
        D /= d;
    }
    
    if (N == 0)
        return s;
    
    // Recurring part.
    s += '(';
    int oldN = N;
    do {
        N *= 10;
        s += to_string(N / D);
        N %= D;
    } while (oldN != N);
    s += ')';
    
    return s;
}
