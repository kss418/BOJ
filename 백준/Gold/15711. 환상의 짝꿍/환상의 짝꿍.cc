#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 20101;
constexpr ll MOD = 1e9 + 7;
vector <ll> p;

class _es {
public:
    ll n; vector <ll> p, pn;
    _es(ll n) {
        this->n = n;
        p.resize(n + 1, -1);
    }

    void init() {
        p[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (p[i] != -1) continue; p[i] = i;
            pn.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                if (p[j] == -1) p[j] = i;
            }
        }
    }

    ll mp(ll n) { // 최소 소인수 반환
        return p[n];
    }

    vector<ll> ret() { // 소수 벡터 반환
        return pn;
    }

    bool prime(ll n) { // 소수 판별
        if (n == 1) return 0;
        return p[n] == n;
    }
};

bool prime(ll num) {
    for (auto& i : p) {
        if (i * i > num) break;
        if (num % i) continue;
        return 0;
    }

    return 1;
}

int main() {
    fastio;
   
    _es es(2010101);
    es.init(); p = es.ret();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll sum = n + m;

        if (sum < 4) cout << "NO\n";
        else if (sum % 2 == 0) cout << "YES\n";
        else {
            if (prime(sum - 2)) cout << "YES\n";
            else cout << "NO\n";
        }
    }


    return 0;
}