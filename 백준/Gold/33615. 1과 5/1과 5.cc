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

void run(){
    cin >> s; ll sum = 0, c1 = 0, c5 = 0;
    for(auto& i : s) {
        sum += i - '0';
        (i == '1' ? c1 : c5)++;
    }

    if(sum % 3 == 0){ cout << 0 << " " << 3 << "\n"; return; }
    if(!c1 || !c5){ cout << s.size() % 2 << " " << 11 << "\n"; return; }
    for(int i = 0;i < s.size();i++){
        if(sum % 3 == 1 && s[i] == '1'){
            cout << i + 1 << " " << 3 << "\n";
            return;
        }
        else if(sum % 3 == 2 && s[i] == '5'){
            cout << i + 1 << " " << 3 << "\n";
            return;
        }
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

