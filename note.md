# My LeetCode Note

## Index

[21. Merge Two Sorted Lists](#21)

[53. Maximum Subarray](#53)

[121. Best Time to Buy and Sell Stock](#121)

[205. Isomorphic Strings](#205)

[206. Reverse Linked List](#206)

[217. Contains Duplicate](#217)

[322. Coin Change](#322)

[383. Ransom Note](#383)

[392. Is Subsequence](#392)

[412. Fizz Buzz](#412)

[724. Find Pivot Index](#724)

[876. Middle of the Linked List](#876)

[1342. Number of Steps to Reduce a Number to Zero](#1342)

[1480. Running Sum of 1d Array](#1480)

[1672. Richest Customer Wealth](#1672)

### 21

### 53

[Loading...](https://leetcode.com/problems/maximum-subarray/discuss/2540458/O(n)-solution)

[Loading...](https://leetcode.com/problems/maximum-subarray/discuss/1354533/PYTHON-Divide-and-Conquer)

[Loading...](https://leetcode.com/problems/maximum-subarray/discuss/1795358/Divide-and-Conqure)

This problem is quite hard for me, I discussed about it on algorithm with a friend of mine.

Our algorithm is based on 2 facts:

- The MaxSubarray must have its leftmost and rightmost element positive.

- If a positive element is in MaxSubarray, then its neighbor positive elements must be all included in MaxSubarray. Negative elements have the same nature.

We define a recursive function `int MaxSubarray(int* array, int l, int r)`, in which `array` is the array in which we search MaxSubarray, this function returns the MaxSubarray sum in `array[l..r]`. We make use of the 2 facts above, try to reduce the size of array searched in each recursion layer, while ensuring in each layer it takes $O(1)$ time complexity (So that the full algorithm takes $O(n)$). The more detailed description of algorithm is in the code comments.

The followings are elegant solutions by others:

**Kadane's Algorithm** 

Kadane's algorithm is based on DP. This algorithm can be used to solve the max sum of subarray. We take `dp[j]` as the max sum of subarray which ends at `A[j]` :

$\text{dp}[j] = \max_{i\in[0..j-1]} (A[i]+A[i+1]+\dots+A[j]).$ 

Then consider `dp[j+1]` , we have:

$\text{dp}[j + 1] = A[j + 1] + \max\{\text{dp}[j],\ 0\}.$

$\max_j \text{dp}[j]$ is the solution.

Algorithm:

```c
int ans = 0; int cur = 0;
for(i = 0; i < A.length; i++){
    cur = A[i] + max(cur, 0);    // cur is dp[i]
    ans = max(ans, cur);    // max dp[j] among all j-s
}
return ans;
```

**Divide and Conquer**

### 121

Simple DP: Find array max, s.t. max[i] := max{a[j], j >= i}.

### 205

hashmap.

1. No two characters may map to the same character.

2. No one character may map to two characters.

Characters must form a one-to-one mapping. The simplest thought is to take 2 arrays to record the two maps (s -> t and t -> s).

### 206

This can be done in place, reverse the linked list as traversing it: repeatedly let the current node point to the previous node.

### 217

My First thought is to use python, and take the advantage of its built-in data structures.

First lesson: **Do not operate on a list while iterating over it.**

This will disturb python's pointer and cause unpredictable result. Try:

```python
for i in list:
    list.remove(i)
print(list)
```

Then I create a new list to store iterated value, and test if value in this list when iterating. Sadly this solution got `TLE`. (Actually this is NOT a hash, because I did not take advantage of the info in the value. I just use python to skip the loop code, but it's still O(n^2) ).

Then I use open hash in C. Time complexity is O(n).

Among others' solutions, another widely-used alg is sort. But it will get a O(nlogn) complexity.

C built-in func: `void qsort(void* ptr, size_t count, size_t size. int(*comp)(const void*, const void*))` defined in `<stdlib.h>`, do a quick sort on `ptr` array.

Sorts the given array pointed to by `ptr` in ascending order. The array contains `count` elements of `size` bytes. Function pointed to by `comp` is used for object comparison.

### 322

Simple DP.

### 383

I just fell again on this: Remember, always use `while(*ptr)` instead of `while(ptr)`when iterating over a string. 

`char` cast to `int` : `*ptr - 'a'`may be better than `(int)*ptr - 95`.

### 392

Try to imitate the `strcpy()` func style(x).

### 412

`sprintf` in C: can convert numbers (int, float, ...) to string in formatted way.

Use a hash table may be a way to get rid of if-else structure. But in C it's hard to impl.

### 724

Take the sum (O(n))

then use a pointer to traverse the array, compare the sum of leftside  (RunningSum) and rightside (Sum - RunningSum - pivot).

### 876

I have once encountered this algorithm. Discussed here:[单链表的含环和相交性质探究过程记录 &#8211; CuSO4_Deposit](https://depoze.xyz/2021/09/23/%e5%8d%95%e9%93%be%e8%a1%a8%e7%9a%84%e5%90%ab%e7%8e%af%e5%92%8c%e7%9b%b8%e4%ba%a4%e6%80%a7%e8%b4%a8%e6%8e%a2%e7%a9%b6%e8%bf%87%e7%a8%8b%e8%ae%b0%e5%bd%95/)

### 1342

`x & 1` is to judge whether x is odd.

Don't forget the `=` when you want to left/right shift some int!

In problems related to divide-by-2, think to the deepest on binary aspect. There may be quite simple solutions.

### 1480

Use the input array as output, may reduce space complexity.

### 1672

Initialize varible in each loop fastened the program. Maybe test more later.
