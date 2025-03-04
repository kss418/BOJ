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
constexpr ll MAX = 303; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], d[MAX];
bool flag;
vector <ll> vec, result;

bool chk(){
    ll sz = vec.size();
    for(int i = 1;i <= sz;i++){
        ll mx = vec[i - 1], mn = vec[i - 1];
        for(int j = i + 1;j <= sz;j++){
            mx = max(mx, vec[j - 1]);
            mn = min(mn, vec[j - 1]);
            if(a[i][j] != mx - mn) return 0; 
        }
    }
    
    return 1;
}

void bt(){
    if(!chk() || flag) return;
    ll sz = vec.size();
    if(sz == n){ 
        for(auto& i : vec) result.push_back(i);
        flag = 1; return; 
    }

    vec.push_back(vec.back() + d[sz]);
    bt();
    vec.pop_back();
    
    vec.push_back(vec.back() - d[sz]);
    bt();
    vec.pop_back();
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++) cin >> a[i][j];
    }

    for(int i = 1;i < n;i++) d[i] = a[i][i + 1];
    vec.push_back(0); bt();

    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}