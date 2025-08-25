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
ll a[MAX], flag, sum, mx, tc;

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
            return c < ot.c;
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
        reverse(all(adj));
        for(auto& i : adj) {
            auto [st, en, c] = i;
            if(same(st, en)){
                mx = max(mx, c);
                sum += c;
                continue;
            }

            merge(st, en);
            result += c; cnt++;
        }

        if(cnt != n - 1 - num) result = MINF;
    }

    T ret() {
        return result;
    }
};

void run(){
    cin >> n >> m; _mst mst(n);
    sum = mx = flag = 0;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        mst.add(s, e, c);
    }

    mst.init();
    cout << "Case #" << ++tc << ": " << sum << " " << mx << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}