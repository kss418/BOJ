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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
bool oa[MAX][MAX], adj[MAX][MAX];
ll org[MAX], ind[MAX];
vector <ll> tmp;
set <pll> ms;

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T now) {
        ll ret = m;
        for(int i = 1;i <= n;i++){
            ind[i] = org[i];
            for(int j = 1;j <= n;j++) adj[i][j] = oa[i][j];
        }

        deque <ll> arr(n);
        iota(all(arr), 1);

        while(!arr.empty()){
            sort(all(arr), [](ll a, ll b){
                return ind[a] > ind[b];
            });

            ms.clear();
            for(int i = 1;i <= n;i++) ms.insert({-ind[i], i});
            auto cur = arr.front(); arr.pop_front();
            for(auto& [ni, nxt] : ms){
                if(adj[cur][nxt]) continue;
                if(ind[cur] - ni < now) continue;
                ind[cur]++; ind[nxt]++; ret++;
                adj[cur][nxt] = adj[nxt][cur] = 1;
            }
        }

        return ret == (n * (n - 1)) / 2;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) / (T)2;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        ll s, e; cin >> s >> e;
        oa[s][e] = oa[e][s] = 1;
        org[s]++; org[e]++;
    }

    for(int i = 1;i <= n;i++) oa[i][i] = 1;

    _bs <ll> bs(0, 2 * n);
    cout << bs.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}