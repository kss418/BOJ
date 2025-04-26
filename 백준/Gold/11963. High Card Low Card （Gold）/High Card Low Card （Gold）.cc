#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result;
bool v[MAX];
deque <ll> q;
vector <ll> gv, lv;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], v[a[i]] = 1;
    for(int i = 1;i <= 2 * n;i++) if(!v[i]) q.push_back(i);
    for(int i = 1;i <= n;i++) (i <= n / 2 ? gv : lv).push_back(a[i]);

    sort(all(gv), greater<ll>());
    sort(all(lv));

    for(auto& i : gv){
        if(i >= q.back()) continue;
        q.pop_back(); result++;
    }
    
    for(auto& i : lv){
        if(i <= q.front()) continue;
        q.pop_front(); result++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}