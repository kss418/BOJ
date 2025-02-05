#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
bool adj[26][26];
ll ind[26];
bool cnt[26], flag, dis;
deque <ll> q;
vector <ll> result;

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(auto& j : st[i]) cnt[j - 'a'] = 1;
    }

    for(int i = 0;i < n;i++){
        for(int k = 0;k < i;k++){
            for(int j = 0;j < max(st[i].size(), st[k].size());j++){
                if(j >= st[i].size()){ dis = 1; break; }
                if(st[i][j] == st[k][j]) continue;
                adj[st[k][j] - 'a'][st[i][j] - 'a'] = 1; break;
            }
        }
    }

    for(int i = 0;i < 26;i++){
        for(int j = 0;j < 26;j++){
            if(adj[i][j]) ind[j]++;
        }
    }

    for(int i = 0;i < 26;i++) if(!ind[i] && cnt[i]) q.push_back(i);
    while(!q.empty()){
        if(q.size() >= 2) flag = 1;
        ll cur = q.front(); q.pop_front();
        result.push_back(cur);
        for(int nxt = 0;nxt < 26;nxt++){
            if(!adj[cur][nxt]) continue;
            if(!--ind[nxt]) q.push_back(nxt);
        }
    }

    if(flag && !dis) cout << "?\n";
    else{
        ll c = 0;
        for(int i = 0;i < 26;i++) c += cnt[i];
        if(c == result.size() && !dis) for(auto& i : result) cout << (char)(i + 'a');
        else cout << "!"; cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}