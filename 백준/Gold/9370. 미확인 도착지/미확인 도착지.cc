#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll; 
using pi = pair<int, int>; using pll = pair<ll, ll>; 
using ull = unsigned long long; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 2010;
ll dp[MAX][2], st, tra[2], dist[MAX][MAX];
vector <ll> prob, arr[MAX], result;

class node{
  public:
    ll num, dist;
};
deque <node> q;


int main() { 
  fastio;

  cin >> t;

  while(t--){
    memset(dp, 0x3f, sizeof(dp));
    memset(dist, 0x3f, sizeof(dist));
    result.clear();
    prob.clear();
    for(int i = 1;i <= 2000;i++) arr[i].clear();
    
    cin >> n >> m >> k;
    cin >> st >> tra[0] >> tra[1];
    
    for(int i = 1; i <= m; i++) {
      ll st, en, d;
      cin >> st >> en >> d;
      arr[st].push_back(en);
      arr[en].push_back(st);
      dist[st][en] = dist[en][st] = d;
    }

    for(int i = 1;i <= k;i++){
      ll num;
      cin >> num, prob.push_back(num);
    }

    q.push_back({st, 0});
    while(!q.empty()){
      node cur = q.front(); q.pop_front();
      ll curn = cur.num, curd = cur.dist;
      if(dp[curn][0] <= curd) continue;
      dp[curn][0] = curd;

      for(auto i : arr[curn]){
        ll nxtn = i, nxtd = dist[curn][nxtn];
        if(dp[nxtn][0] <= dp[curn][0] + nxtd) continue;
        q.push_back({nxtn, dp[curn][0] + nxtd});
      }
    }
    ll mx, mn;
    if(dp[tra[0]][0] > dp[tra[1]][0]) mx = tra[0], mn = tra[1];
    else mn = tra[0], mx = tra[1];
    

    q.push_back({mx, 0});
    while(!q.empty()){
      node cur = q.front(); q.pop_front();
      ll curn = cur.num, curd = cur.dist;
      if(dp[curn][1] <= curd) continue;
      dp[curn][1] = curd;

      for(auto i : arr[curn]){
        ll nxtn = i, nxtd = dist[curn][nxtn];
        if(dp[nxtn][1] <= dp[curn][1] + nxtd) continue;
        q.push_back({nxtn, dp[curn][1] + nxtd});
      }
    }

    sort(prob.begin(), prob.end());
    for(auto i : prob) if(dp[i][0] == dp[mn][0] + dp[i][1] + dist[tra[0]][tra[1]]) cout << i << " ";
    cout << "\n";
  }
  
  
  return 0;
}

