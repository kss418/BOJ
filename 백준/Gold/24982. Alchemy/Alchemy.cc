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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
i128 cnt[MAX], now[MAX];
vector <ll> adj[MAX];


template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1;i <= n;i++) now[i] = a[i];
        cnt[n] = cur;

        for(int i = n;i >= 1;i--){
            if(cnt[i] <= a[i]){
                cnt[i] -= a[i];
                continue;
            }

            if(adj[i].empty()) return 0;
            ll mn = min(cnt[i], now[i]);
            cnt[i] -= mn; now[i] -= mn;
            for(auto& nxt : adj[i]) {
                cnt[nxt] += cnt[i];
                if(cnt[nxt] >= 2e6) return 0;
            }
        }
       
        return 1;
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
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> m;
    while(m--){
        ll s, sz; cin >> s >> sz;
        for(int i = 1;i <= sz;i++){
            ll e; cin >> e;
            adj[s].push_back(e);
        }
    }

    _bs <ll> bs(0, 2e6);
    cout << bs.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}