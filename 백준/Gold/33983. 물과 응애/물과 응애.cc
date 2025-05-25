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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
deque <ll> q;
bool flag = 1;

void run(){
    cin >> n >> s;
    for(int i = 0;i < n;i++){
        if(s[i] == 'H') q.push_back(i);
        else{
            if(q.empty()) flag = 0;
            else q.pop_front();
        }
    }

    for(int i = 0;i < n;i++){
        if(s[i] == 'H') continue;
        if(q.empty() || q.front() <= i) flag = 0;
        else q.pop_front();
    }

    if(!q.empty()) flag = 0;
    cout << (flag ? "pure" : "mix");
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}