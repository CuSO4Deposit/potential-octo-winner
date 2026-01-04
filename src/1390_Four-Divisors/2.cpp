// Dynamically calculate primes > 320
// 70 ms (< 30.05%), 16.90 MB (< 27.09%)
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool isPrime(int n, std::unordered_set<int>& primes) {
        if (n == 1) return false;
        if (primes.contains(n)) return true;
        for (int p : primes) {
            if (n % p == 0) return false;
        }
        primes.insert(n);
        return true;
    }

    int sumFourDivisors(std::vector<int>& nums) {
        std::vector<int> prime;
        prime.push_back(2);

        for (int i = 3; i <= 320; i+=2) {
            bool isPrimeFlag = true;
            for (int p : prime) {
                if (!isPrimeFlag) break;
                if (i % p == 0) {
                    isPrimeFlag = false;
                };
            }
            if (isPrimeFlag) prime.push_back(i);
        }
        std::unordered_set<int> primeSet(prime.begin(), prime.end());

        int result = 0;
        for (int n : nums) {
            for (int p : prime) {
                if (n % p) continue;
                int div = n / p;
                // (n = p * div) or (n = p * p * p)
                if ((isPrime(div, primeSet) && (p != div)) || (div % p == 0 && div / p == p)) {
                    result += 1 + div + p + n;
                    break;
                }
            }
        }

        return result;
    }
};
