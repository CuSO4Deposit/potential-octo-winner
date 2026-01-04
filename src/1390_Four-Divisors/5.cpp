// Dynamically calculate primes > 320, use vector
// 127 ms (< 20.20%), 16.39 MB (< 32.76%)
#include <vector>

class Solution {
public:
    bool isPrime(int n, std::vector<int>& primes) {
        if (n == 1) return false;
        for (int p : primes) {
            if (n == p) return true;
            if (n % p == 0) return false;
        }
        primes.push_back(n);
        return true;
    }

    int sumFourDivisors(std::vector<int>& nums) {
        std::vector<int> prime;
        prime.push_back(2);

        for (int i = 3; i <= 320; i+=2) {
            if (isPrime(i, prime)) prime.push_back(i);
        }

        int result = 0;
        for (int n : nums) {
            for (int p : prime) {
                if (n % p) continue;
                int div = n / p;
                // (n = p * div) or (n = p * p * p)
                if ((div % p == 0 && div / p == p) || (isPrime(div, prime) && (p != div))) {
                    result += 1 + div + p + n;
                    break;
                }
            }
        }

        return result;
    }
};
