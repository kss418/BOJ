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
constexpr ll MID = 10010;
ll a[MAX], dp[MAX][20101], pre[MAX][20101], pl;
deque <ll> tr, result;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dp[2][MID + a[1] - a[2]] = 1;
    
    for(int i = 3;i <= n;i++){
        for(int j = a[i];j + a[i] < 20101;j++){
            if(dp[i - 1][j - a[i]]) dp[i][j] = 1, pre[i][j] = j - a[i];
            if(dp[i - 1][j + a[i]]) dp[i][j] = 1, pre[i][j] = j + a[i];
        }
    }

    ll cur = n, num = MID + m;
    while(cur > 1){
        ll nxt = pre[cur][num];
        tr.push_back((nxt > num ? -1 : 1));
        num = nxt; cur--;
    }
    tr.pop_back(); reverse(all(tr));

    ll cnt = 2;
    while(!tr.empty()){
        if(tr.front() == 1) result.push_back(cnt);
        else pl++, cnt++;
        tr.pop_front();
    }

    result.push_back(1);
    while(pl--) result.push_back(1);
    for(auto& i : result) cout << i << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

