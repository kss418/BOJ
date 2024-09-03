#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;
constexpr ll MOD = 1e9 + 7;


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

    vector<ll> ret() {
        return pn;
    }

    ll is_p(ll n) {
        if (n == 1) return 0;
        return p[n] == n;
    }
};
ll arr[101010], cnt[MAX];

int main() {
    fastio;

    _es es(MAX);
    es.init();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; cnt[arr[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        ll cur = arr[i];
        ll ret = cnt[arr[i]] - 1;
        if (cur != 1) ret += cnt[1];

        for (int j = 2; j * j <= cur; j++) {
            if (cur % j) continue;
            if (j * j == cur) ret += cnt[j];
            else ret += cnt[j], ret += cnt[cur / j];
        }

        cout << ret << '\n';
    }





    return 0;
}