#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool getBit(ll num, int idx) {
	return ((num >> idx) & 1);
}
ll setBit(ll num, int idx, bool val) {
	return val ? (num | (1LL << idx)) : (num & ~(1LL << idx));
}
ll flipBit(ll num, int idx) {
	return (num ^ (1LL << idx));
}

ll leastBit(ll num) {
	return (num & -num);
}
template<class Int>
Int turnOnLastZero(Int num) {
	return num | num + 1;
}
template<class Int>
Int turnOnLastConsecutiveZeroes(Int num) {
	return num | num - 1;
}
template<class Int>
Int turnOffLastBit(Int num) {
	return num & num - 1;
}
template<class Int>
Int turnOffLastConsecutiveBits(Int num) {
	return num & num + 1;
}
//num%mod, mod is a power of 2
ll Mod(ll num, ll mod) {
	return (num & mod - 1);
}
bool isPowerOfTwo(ll num) {
	return (num & num - 1) == 0;
}
void genAllSubmask(int mask) {
	for (int subMask = mask;; subMask = (subMask - 1) & mask) {
		//code
		if (subMask == 0)break;
	}
}
int LOG2(int x) { //floor(log2(x))
	return 31 - __builtin_clz(x);
}
int LOG2(long long x) { //floor(log2(x))
	return 63 - __builtin_clzll(x);
}

// Count numbers in [1, r] whose 'bit'-th bit is set.
// Time: O(1)
int countOnes(int r, int bit) {
	int period = 1 << (bit + 1);
	int half = period >> 1;

	int full = (r + 1) / period;
	int rem = (r + 1) % period;

	return full * half + max(0, rem - half);
}

// Count numbers in [1, r] whose 'bit'-th bit is not set.
// Time: O(1)
int countZeros(int r, int bit) {
	return r - countOnes(r, bit);
}