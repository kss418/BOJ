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
ll cnt[2][MAX];
bool chk[20][20];

void run(){
    string a, b; cin >> a >> b >> m;
    for(int i = 0;i < a.size();i++) cnt[0][a[i] - 'a']++;
    for(int i = 0;i < b.size();i++) cnt[1][b[i] - 'a']++;

    for(int i = 0;i < 20;i++){
        for(int j = i + 1;j < 20;j++){
            string pre, nxt;
            for(auto& k : a){
                if(k != i + 'a' && k != j + 'a') continue;
                pre.push_back(k);
            }

            for(auto& k : b){
                if(k != i + 'a' && k != j + 'a') continue;
                nxt.push_back(k);
            }
            chk[i][j] = (pre == nxt);
        }
    }

    while(m--){
        string now; cin >> now;
        bool flag = 1;
        ll as = 0, bs = 0;
        for(auto& i : now){
            as += cnt[0][i - 'a'];
            bs += cnt[1][i - 'a'];
        }

        if(as != bs) flag = 0;
        for(auto& i : now){
            for(auto& j : now){
                if(i >= j) continue;
                if(!chk[i - 'a'][j - 'a']) flag = 0;
            }
        }

        cout << (flag ? "Y" : "N");
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}