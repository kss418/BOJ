#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
vector <ll> p;
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

bool is_prime(ll n) {
    if (n < MAX) return (p[n] == n && n != 1);
    for (ll i = 2; i * i <= n; i++) {
        if (n % i) continue;
        return 0;
    }

    return 1;
}

vector <ll> b, pr, result;
void bt(ll n) {
    if (b.size() == n) {
        ll cur = b[0];
        if (!is_prime(cur)) return;
        for (int i = 1; i < n;i++) {
            cur *= 10; cur += b[i];
            if (!is_prime(cur)) return;
        }
        result.push_back(cur);

        return;
    }

    for (auto& i : pr) {
        b.push_back(i);
        bt(n);
        b.pop_back();
    }
}

int main() {
    fastio;
   
    _es es(MAX);
    es.init();
    p = es.ret();

    cin >> n;
    pr = { 1,2,3,5,7,9 };
    bt(n);

    for (auto& i : result) cout << i << "\n";

    return 0;
}