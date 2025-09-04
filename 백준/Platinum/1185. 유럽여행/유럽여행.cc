#include <bits/stdc++.h>
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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result = INF, sum;
vector <ll> comp[MAX];

template <typename T = ll>
class _mst {
public:
    vector<ll> p, size; T result = 0;
    ll n, cnt = 0;
    class edge {
    public:
        ll s, e; T c;
        bool operator>(const edge& ot) const {
            return c > ot.c;
        }

        bool operator<(const edge& ot) const {
            return a[s] + a[e] + 2 * c < a[ot.s] + a[ot.e] + 2 * ot.c;
        }
    };
    vector <edge> adj;

    _mst(ll n) {
        this->n = n;
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
        adj.push_back({ st, en, c });
    }

    void init(ll num = 0) { // num 만큼 적게 간선 연결
        cnt = 0; result = 0;
        sort(all(adj));
        for(auto& i : adj) {
            auto [st, en, c] = i;
            if (same(st, en)) continue; merge(st, en);
            comp[st].push_back(en);
            comp[en].push_back(st);
            sum += 2 * c; cnt++;
            if (cnt == n - 1 - num) break;
        }

        if(cnt != n - 1 - num) result = MINF;
    }

    T ret() {
        return result;
    }
};

void run(){
    cin >> n >> m; _mst mst(n);
    for(int i = 1;i <= n;i++) cin >> a[i];
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        mst.add(s, e, c);
    }

    mst.init(); mst.ret();
    for(int i = 1;i <= n;i++){
        sum += a[i] * comp[i].size();
    }

    for(int i = 1;i <= n;i++){
        result = min(result, sum + a[i]);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}