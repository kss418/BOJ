#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n, k;

int dm(ll cur) {
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        if (cur % i == 0) {
            cnt += min(cur / i - 1, n);
        }
        else {
            cnt += min(cur / i, n);
        }
        if (cnt >= k) {
            return 0;
        }
    }

    if (cnt >= k) {
        return 0;
    }
    else {
        return 1;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    ll st = 1, en = 10000000000;

    ll mid = (st + en + 1) / 2;
    while (en > st) {
        mid = (st + en + 1) / 2;
        if (dm(mid)) {
            st = mid;
        }
        else {
            en = mid - 1;
        }
    }

    cout << st;
    

    return 0;
}