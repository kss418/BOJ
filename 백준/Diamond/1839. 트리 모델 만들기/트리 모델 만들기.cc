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
vector <ll> tmp[MAX], adj[MAX];
multiset <ll> ms[MAX];
ll ind[MAX], cnt, mx, num[MAX];
deque <ll> q;

void init(ll cur, ll pre = -1){
    for(auto& nxt : tmp[cur]){
        if(nxt == pre) continue;
        adj[nxt].push_back(cur);
        ind[cur]++;
        init(nxt, cur);
    }
}

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T now) {
        ll ret = 0;
        memset(ind, 0, sizeof(ind));
        for(int i = 1;i <= n;i++){
            for(auto& nxt : adj[i]) ind[nxt]++;
        }

        for(int i = 1;i <= n;i++) if(ind[i] == 0) q.push_back(i);
        while(!q.empty()){
            ll cur = q.front(); q.pop_front();
            while(ms[cur].size() > 1){
                ll la = *--ms[cur].end(); ret++;
                ms[cur].erase(--ms[cur].end());
                auto ub = ms[cur].upper_bound(now - la);
                if(ub != ms[cur].begin()) ms[cur].erase(--ub);
            }

            while(!ms[cur].empty()){
                ll la = *--ms[cur].end();
                if(la < now) break;
                ms[cur].erase(--ms[cur].end()); ret++;
            }

            for(auto& nxt : adj[cur]){
                for(auto& i : ms[cur]) ms[nxt].insert(i + 1);
                if(ms[cur].empty()) ms[nxt].insert(1);
                if(!--ind[nxt]) q.push_back(nxt);
            }

            if(adj[cur].empty() && !ms[cur].empty()) ret++;
            ms[cur].clear();
        }

        return ret <= cnt;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

void run(){
    cin >> n;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        tmp[s].push_back(e);
        tmp[e].push_back(s);
    }

    bool flag = 0;
    for(int i = 1;i <= n;i++){
        if(tmp[i].size() == 1) continue;
        flag = 1; init(i); break;
    }

    if(!flag) init(1);
    for(int i = 1;i <= n;i++){
        if(!ind[i]) q.push_back(i);
    }

    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        cnt += num[cur] / 2;
        for(auto& nxt : adj[cur]){
            num[nxt]++;
            if(!--ind[nxt]) q.push_back(nxt);
        }

        if(adj[cur].empty()) cnt += num[cur] % 2;
    }

    _bs bs(1ll, n);
    cout << cnt << " " << bs.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}