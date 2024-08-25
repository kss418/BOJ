#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;

template <typename T = ll>
class _mst {
public:
    vector<vector<pair<T, ll>>> adj;
    vector<ll> p, size; ll n; T result = 0;
    class edge {
    public:
        ll s, e; T c;
        bool operator>(const edge& ot) const {
            return c > ot.c;
        }
    };
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    _mst(ll n) {
        this->n = n;
        adj.resize(n + 1);
        p.resize(n + 1); size.resize(n + 1);
        fill(p.begin(), p.end(), -1);
        fill(size.begin(), size.end(), 1);
    }

    ll find(ll num) {
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a > b) swap(a, b);
        p[b] = a, size[a] += size[b];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }

    void add(ll st, ll en, T c = 1) { // 양방향
        adj[st].push_back({ c, en });
        adj[en].push_back({ c, st });
        pq.push({ st, en, c });
        pq.push({ en, st, c });
    }

    void init(ll num = 0) { // num 만큼 적게 간선 연결
        ll cnt = 0;
        while (!pq.empty()) {
            auto [st, en, c] = pq.top(); pq.pop();
            if (same(st, en)) continue; merge(st, en);
            result += c; cnt++;
            if (cnt == n - 1 - num) break;
        }
    }

    T ret() {
        return result;
    }
};

int main()
{
    fastio;
    cin >> n >> m >> k;
    _mst mst(n + 1);
    for (int i = 1; i <= k; i++) cin >> t, mst.add(0, t, 0);
    while (m--) {
        ll s, e, c;
        cin >> s >> e >> c;
        mst.add(s, e, c);
    }
    mst.init();

    cout << mst.ret();


    return 0;
}