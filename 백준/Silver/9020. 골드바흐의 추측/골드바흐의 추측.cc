#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101;
constexpr ll MOD = 1e9 + 7;

class _es {
public:
    ll n; vector <ll> p;
    _es(ll n) {
        this->n = n;
        p.resize(n + 1, -1);
    }

    void init() {
        p[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (p[i] != -1) continue; p[i] = i;
            for (int j = 2 * i; j <= n; j += i) {
                if (p[j] == -1) p[j] = i;
            }
        }
    }

    vector<ll> ret() {
        return p;
    }

    ll prime(ll n) {
        if (n == 1) return 0;
        return p[n] == n;
    }
};




int main() {
    fastio;
   
    _es es(MAX);
    es.init();
    
    cin >> t;
    while (t--) {
        cin >> n;

        pll result;
        for (int i = 2; 2 * i <= n; i++) {
            ll pre = i, nxt = n - i;
            if (!es.prime(pre) || !es.prime(nxt)) continue;
            result = { pre, nxt };
        }

        cout << result.first << " " << result.second << '\n';
    }

    return 0;
}