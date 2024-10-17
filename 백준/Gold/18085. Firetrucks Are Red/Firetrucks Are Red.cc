#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX];
vector <tll> ret;

template <typename T = ll>
class _mst {
public:
    vector<vector<pair<T, ll>>> adj;
    vector<ll> p, size; T result = 0;
    ll n, cnt = 0;
    class edge {
    public:
        ll s, e; T c;
        bool operator>(const edge& ot) const {
            return c > ot.c;
        }

        bool operator<(const edge& ot) const {
            return c < ot.c;
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
        cnt = 0; result = 0;
        while (!pq.empty()) {
            auto [st, en, c] = pq.top(); pq.pop();
            if (same(st, en)) continue; merge(st, en);
            result += c; cnt++;
            ret.push_back({st, en, c});
            if (cnt == n - 1 - num) break;
        }
    }
};
map <ll, vector<ll>> num;

int main() {
    fastio;

    cin >> n; _mst mst(n);
    for(int i = 1;i <= n;i++){
        ll m; cin >> m;
        for(int j = 1;j <= m;j++) cin >> k, num[k].push_back(i);
    }

    for(auto& i : num){
        auto& vec = i.y;
        for(int j = 1;j < vec.size();j++) mst.add(vec[0], vec[j], i.x);
    }
    mst.init();

    if(ret.size() != n - 1) cout << "impossible";
    else for(auto& i : ret){
        auto [st, en, co] = i;
        cout << st << " " << en << " " << co << "\n";
    }


    return 0;
}
