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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string a, b;

class node{
public:
    ll idx, t, c;
};
deque <node> q;
ll result;

void run(){
    cin >> n >> m >> a >> b;
    for(int i = 0;i < n;i++){
        if(a[i] == b[i]) continue;

        while(!q.empty() && q.front().idx < i){
            auto [idx, t, c] = q.front(); q.pop_front();
            result += c;
            q.push_back({idx + m, t, c});
        }

        if(q.empty() || q.back().t == a[i] - '0'){
            if(!q.empty() && q.front().idx == i) q[0].c++;
            else q.push_front({i, a[i] - '0', 1});
            continue;
        }

        q[0].c--;
        if(!q[0].c) q.pop_front();
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}