#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
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
        p.resize(n + 1, -1); size.resize(n + 1, 1);
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
            if (cnt == n - 1 - num) break;
        }
    }

    T ret() {
        return result;
    }
};

void run(){
    while(1){
        cin >> n >> m >> k;
        if(!n) return; _mst r(n), b(n);
        while(m--){
            char c; ll s, e; cin >> c >> s >> e;
            r.add(s, e, c == 'R');
            b.add(s, e, c == 'B');
        }
        r.init(); b.init();
        ll rr = n - r.ret() - 1, rb = b.ret();

        cout << (k <= rr && k >= rb ? 1 : 0) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

