#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 51;
constexpr ll MOD = 1e9 + 7;
class _bm { // 1-based index
public:
    ll as, bs; vector<vector<ll>> adj;
    vector<ll> av, bv; vector<bool> v;

    _bm(ll a, ll b) {
        as = a; bs = b;
        av.resize(a + 1, -1); bv.resize(b + 1, -1);
        adj.resize(a + 1); v.resize(a + 1);
    }

    void addsol(ll st, ll en) {
        adj[st].push_back(en);
    }

    bool dfs(ll a) {
        v[a] = 1;
        for (auto& b : adj[a]) {
            if (bv[b] == -1 || !v[bv[b]] && dfs(bv[b])) {
                av[a] = b; bv[b] = a;
                return 1;
            }
        }
        return 0;
    }

    ll ret() {
        fill(av.begin(), av.end(), -1);
        fill(bv.begin(), bv.end(), -1);
        ll result = 0;

        for (int i = 1; i <= as; i++) {
            if (av[i] != -1) continue;
            fill(v.begin(), v.end(), 0);
            if (dfs(i)) result++;
        }

        return result;
    }

    void clear() {
        for (int i = 1; i <= as; i++) adj[i].clear();
    }
};
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

ll arr[MAX];
vector <ll> num[2], result;

int main() {
    fastio;

    _es es(2010); es.init();

    cin >> n;
    _bm bm(1010, 1010);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; num[arr[i] % 2].push_back(arr[i]);
    }

    ll fi = arr[1] % 2;
    for (int i = 0; i < num[fi ^ 1].size(); i++) {
        if (!es.prime(arr[1] + num[fi ^ 1][i])) continue;
        bm.clear(); bm.addsol(arr[1], num[fi ^ 1][i]);

        for (int a = 1; a < num[fi].size(); a++) {
            for (int b = 0; b < num[fi ^ 1].size(); b++) {
                if (b == i) continue;
                if (!es.prime(num[fi][a] + num[fi ^ 1][b])) continue;
                bm.addsol(num[fi][a], num[fi ^ 1][b]);
            }
        }

        if (bm.ret() == n / 2) result.push_back(num[fi ^ 1][i]);
    }
    sort(result.begin(), result.end());

    if (!result.size()) cout << -1;
    for (auto& i : result) cout << i << " ";


    return 0;
}