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
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll seq, a[MAX];

void dfs(ll cur, ll cnt, ll num){
    if(cur == 14){
        if(!cnt && seq < n) a[++seq] = num; 
        return;
    }

    if(cnt) dfs(cur + 1, cnt - 1, num | (1ll << cur));
    dfs(cur + 1, cnt, num);
}

ll mn(ll cur){
    for(int i = 0;i < 14;i++){
        if(cur & (1ll << i)) return i;
    }
}

void run(){
    cin >> n;
    for(int i = 2;i <= n;i++) cin >> st[i];
    dfs(0, 7, 0);

    for(int i = 2;i <= n;i++){
        for(int j = 0;j < i - 1;j++){
            ll l = st[i][j] == '1' ? a[j + 1] : ~a[j + 1];
            ll r = st[i][j] == '1' ? ~a[i] : a[i];
            cout << (char)(mn(l & r) + 'a');
        }
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}