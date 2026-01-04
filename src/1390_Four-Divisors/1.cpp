// 1139 ms (< 17.24%), 22.10 MB (< 23.40%)
#include <unordered_set>
#include <vector>

class Solution {
public:
    int sumFourDivisors(std::vector<int>& nums) {
        std::vector<int> prime;
        prime.push_back(2);

        for (int i = 3; i <= 50000; i+=2) {
            bool isPrime = true;
            for (int p : prime) {
                if (!isPrime) break;
                if (i % p == 0) {
                    isPrime = false;
                };
            }
            if (isPrime) prime.push_back(i);
        }
        std::unordered_set<int> primeSet(prime.begin(), prime.end());

        int result = 0;
        for (int n : nums) {
            for (int p : prime) {
                if (n % p) continue;
                int div = n / p;
                // (n = p * div) or (n = p * p * p)
                if ((primeSet.contains(div) && (p != div)) || (div % p == 0 && div / p == p)) {
                    result += 1 + div + p + n;
                    break;
                }
            }
        }

        return result;
    }
};
