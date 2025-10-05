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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll sz[MAX];
deque <char> tr[2];

void cal(ll cur, ll now, ll idx){
    if(cur == 1) return;
    if(cur > sz[now - 2] + 1){
        tr[idx].push_back('R');
        cal(cur - sz[now - 2] - 1, now - 1, idx);
    }
    else{
        tr[idx].push_back('L');
        cal(cur - 1, now - 2, idx);
    }
}

void run(){
    cin >> n >> m >> k; sz[0] = sz[1] = 1;
    for(int i = 2;i <= n;i++) sz[i] = sz[i - 1] + sz[i - 2] + 1;

    bool sw = m > k; if(sw) swap(m, k);
    cal(m, n, 0); cal(k, n, 1);

    while(!tr[0].empty() && !tr[1].empty()){
        if(tr[0].front() != tr[1].front()) break;
        tr[0].pop_front();
        tr[1].pop_front();
    }

    for(auto& i : tr[0 ^ sw]) cout << "U";
    for(auto& i : tr[1 ^ sw]) cout << i;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}