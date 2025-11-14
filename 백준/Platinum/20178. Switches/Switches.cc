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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
bool a[MAX][MAX];
bitset <MAX> bs[MAX], rev[MAX];

void run(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cin >> a[j][i];
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) bs[i][j] = a[i][j];
        rev[i][i] = 1;
    }

    for(int i = 0;i < n;i++){
        bool flag = 1;
        for(int j = i;j < n;j++){
            if(!bs[j][i]) continue;
            swap(bs[i], bs[j]); 
            swap(rev[i], rev[j]);
            flag = 0; break;
        }

        if(flag){ cout << -1; return; }
        for(int j = 0;j < n;j++){
            if(!bs[j][i] || i == j) continue;
            bs[j] ^= bs[i];
            rev[j] ^= rev[i];
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(!rev[j][i]) continue;
            cout << j + 1 << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}