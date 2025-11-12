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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], p[MAX], ind[MAX], sum[MAX], mx;
vector <ll> tmp[MAX], arr[MAX];
deque <ll> q;

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
            arr[i].clear(); sum[i] = a[i];
            if(p[i] == -1) continue;
            ind[p[i]]++;
        }

        for(int i = 1;i <= n;i++){
            if(!ind[i]) q.push_back(i);
        }

        while(!q.empty()){
            ll cur = q.front(); q.pop_front();
            sort(all(arr[cur]));
            for(auto& i : arr[cur]){
                if(sum[cur] + i > now) ret++;
                else sum[cur] += i;
            }

            ll nxt = p[cur];
            if(nxt == -1) break;
            arr[nxt].push_back(sum[cur]);
            if(!--ind[nxt]) q.push_back(nxt);
        }

        return ret <= m;
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

void init(ll cur = 1, ll pre = -1){
    for(auto& nxt : tmp[cur]){
        if(pre == nxt) continue;
        p[nxt] = cur;
        init(nxt, cur);
    }
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) tmp[i].clear(); mx = 0;
    for(int i = 1;i <= n;i++) cin >> a[i], mx = max(mx, a[i]);
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        tmp[s].push_back(e);
        tmp[e].push_back(s);
    }

    _bs <ll> bs(mx, 2e14);
    memset(p, -1, sizeof(p)); init();
    cout << bs.ret() << "\n";
}   

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}