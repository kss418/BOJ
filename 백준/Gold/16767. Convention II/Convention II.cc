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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
class node{
public:
    ll s, e, idx;
    bool operator < (const node& ot) const{
        return s < ot.s;
    }
}; node a[MAX];
priority_queue <pll, vector<pll>, greater<pll>> pq;
ll now, result;

void run(){
    cin >> n; 
    for(int i = 1;i <= n;i++) cin >> a[i].s >> a[i].e, a[i].idx = i;
    sort(a + 1, a + n + 1);

    ll idx = 2; pq.push({a[1].idx, 1});
    while(!pq.empty()){
        auto [org, cur] = pq.top(); pq.pop();
        result = max(result, now - a[cur].s);
        now = max(a[cur].s + a[cur].e, now + a[cur].e);

        while(idx <= n && a[idx].s <= now){
            pq.push({a[idx].idx, idx}); idx++;
        }

        if(idx <= n && pq.empty()) pq.push({a[idx].idx, idx}), idx++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

