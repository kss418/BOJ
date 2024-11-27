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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <string> arr;
string color[5] = { "white", "blue", "red", "gray", "green" };
string item[5] = { "Barabashka", "book", "chair", "mouse", "bottle" };
map <string, bool> cnt;


bool alpha(char& c){
    if(c >= 'a' && c <= 'z') return 1;
    if(c >= 'A' && c <= 'Z') return 1;
    return 0;
}

void parsh(string& s){
    string cur; arr.clear();
    for(auto& i : s){
        if(!alpha(i) && !cur.empty()) arr.push_back(cur), cur.clear();
        else if(alpha(i)) cur.push_back(i);
    }
    if(!cur.empty()) arr.push_back(cur);
}

int main() {
    fastio;

    while(getline(cin, s)){
        parsh(s); cnt.clear();
        for(auto& i : arr) cnt[i] = 1;

        ll idx = -1;
        for(int i = 0;i < 5;i++){
            if(!cnt[color[i]] || !cnt[item[i]]) continue;
            idx = i;
        }

        if(idx != -1) cout << color[idx] << " " << item[idx] << "\n";
        else{
            for(int i = 0;i < 5;i++){
                if(cnt[item[i]] || cnt[color[i]]) continue;
                cout << color[i] << " " << item[i] << "\n"; break;
            }
        }
    }
    
     
    return 0;
}