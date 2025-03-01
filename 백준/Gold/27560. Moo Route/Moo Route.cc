#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
ll a[MAX], all;
vector <char> result;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], all += a[i];

    ll cur = 0, dir = 1;
    while(result.size() != all){
        if(cur == n || !a[cur + 1]) dir = -1;
        else if(a[cur + 1] >= a[cur]) dir = 1;

        if(dir == 1) a[cur + 1]--;
        else a[cur]--;

        cur += dir; result.push_back(dir == 1 ? 'R' : 'L');
    }
    
    for(auto& i : result) cout << i;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

