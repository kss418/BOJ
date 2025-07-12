#include <bits/stdc++.h>
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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll pre[MAX];

void run(){
    cin >> n >> s;
    for(int i = 0;i < n;i++){
        pre[i + 1] = pre[i];
        if(s[i] == 'H') continue;
        if(i % 2) pre[i + 1]--;
        else pre[i + 1]++;
    }

    if(pre[n]){ cout << -1 << "\n"; return; }
    ll result = 0;
    for(int i = 1;i <= n;i++) result += abs(pre[i]);
    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}