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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], l[MAX], r[MAX], cnt;
vector <pll> tr;
bool v[MAX], flag = 1;
set <ll> ms;

void op(ll idx){
    ll s = l[idx], e = r[idx]; 
    bool f = 1; cnt++;
    if(s > e) swap(s, e), f = 0;

    vector <pll> tmp;
    while(s < e){
        auto ub = min<ll>(upper_bound(a + 1, a + m + 2, a[s] + k) - a - 1, e);
        if(s == ub){ flag = 0; return; }
        pll now = {s, ub};
        if(!f) swap(now.x, now.y);
        tmp.push_back(now); s = ub;
    }

    if(!f) reverse(all(tmp));
    for(auto& i : tmp) tr.push_back(i);
}

void run(){
    cin >> n >> m >> k; a[m + 1] = INF;
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> l[i], ms.insert(a[l[i]]);
    for(int i = 1;i <= n;i++) cin >> r[i];
    ms.insert(INF); ms.insert(MINF);

    for(int i = 1;i < n;i++){
        ll d1 = a[l[i + 1]] - a[l[i]];
        ll d2 = a[r[i + 1]] - a[r[i]];
        if(d1 <= k || d2 <= k) flag = 0;
    }

    if(!flag){ cout << -1; return; }
    while(cnt != n){
        if(!flag) break;
        for(int i = 1;i <= n;i++){
            if(v[i]) continue;
            ll s = l[i], e = r[i];
            if(s > e){
                ll lb = *--ms.lower_bound(a[s]);
                if(lb >= a[s] - k) continue;
            }
            else{
                ll lb = *ms.upper_bound(a[s]);
                if(lb <= a[e] + k) continue;
            }

            ms.erase(ms.find(a[s]));
            v[i] = 1; op(i);
        }
    }

    if(!flag){ cout << -1; return; }
    cout << tr.size() << "\n";
    for(auto& [s, e] : tr) cout << s << " " << e << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}