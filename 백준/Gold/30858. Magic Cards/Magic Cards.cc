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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll q;
bitset<101> bs[MAX];
unordered_map <bitset<101>, ll> num;

void run(){
    cin >> n >> m >> k >> q;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < k;j++){
            ll now; cin >> now;
            bs[now][i] = 1;
        }
    }

    for(int i = 1;i <= n;i++){
        if(num.count(bs[i])) num[bs[i]] = 0;
        else num[bs[i]] = i;
    }

    while(q--){
        cin >> s; bitset<101> now;
        for(int i = 0;i < s.size();i++){
            if(s[i] == 'N') continue;
            now[i] = 1;
        }

        cout << num[now] << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}