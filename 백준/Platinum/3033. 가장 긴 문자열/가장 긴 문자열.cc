#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
vector <ll> num[200003];

class _hash { // 0-based index
public:
    // ll mod[4] = { MOD, 998244353, 100000223, 922337203685471 };
    // ll key[4] = {29, 31, 200003, 27};
    ll n, m, mod, key;
    vector <ll> h;

    _hash(ll n, ll m, ll mod, ll key = 2) {
        this->n = n; this->m = m;
        this->mod = mod; this->key = key;
        h.resize(n + 1, 0);
    }

    ll mo(ll n) {
        if (n % mod >= 0) return n % mod;
        else return (n % mod) + mod;
    }

    ll init(string& arr) {
        ll pow = 1;
        for (int i = 0; i < m; i++) {
            h[0] = mo(h[0] + arr[m - i - 1] * pow);
            if (i != m - 1) pow = mo(key * pow);
        }
       
        for (int i = 1; i <= n - m; i++) {
            h[i] = mo(key * mo(h[i - 1] - arr[i - 1] * pow) + arr[i + m - 1]);                
        }

        for (int i = 0; i <= n - m; i++) {
            num[h[i]].clear();
        }

        for (int i = 0; i <= n - m; i++) {
            num[h[i]].push_back(i);
            for (int j = 0; j < num[h[i]].size() - 1; j++) {
                ll flag = 1;
                ll pre = num[h[i]][j], cur = i;
                for (int k = 0; k < m; k++) {
                    if (s[pre + k] == s[cur + k]) continue;
                    flag = 0; break;
                }

                if (flag) return 1;
            }
        }

        return 0;
    }

    ll ret(ll a) {
        return mo(h[a]);
    }
};


class _bs { 
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll mod = 200003;
        ll key = 27;
        _hash a(n, cur, mod, key);     

        return a.init(s);
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) >> 1;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

int main() {
    fastio;
    cin >> n >> s;
    _bs bs(0, n);

    cout << bs.ret();

    return 0;
}