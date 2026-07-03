#include <bits/stdc++.h>
typedef long long ll;

struct Median {
    multiset<int> lo, hi;
    void rebalance() {
        if (lo.size() < hi.size()) {
            lo.insert(*hi.begin()) ;
            hi.erase(hi.begin()) ;
        }
        if (lo.size() > hi.size() + 1) {
            hi.insert(*(--lo.end())) ;
            lo.erase(--lo.end()) ;
        }
    }

    void insert(int x) {
        if (!hi.empty() && x >= *hi.begin()) {
            hi.insert(x);
        } else {
            lo.insert(x);
        }
        rebalance();
    }

    bool erase(int x) {
        auto it = lo.find(x);
        if (it != lo.end()) {
            lo.erase(it);
            rebalance();
            return true;
        }
        it = hi.find(x);
        if (it != hi.end()) {
            hi.erase(it);
            rebalance();
            return true;
        }
        return false;
    }

    void clear() {
        lo.clear();
        hi.clear();
    }

    int median() const {
        return *(--lo.end());
    }
};

