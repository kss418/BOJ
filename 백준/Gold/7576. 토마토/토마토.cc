#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int arr[1001][1001];

int main() {


    int n, m, num,i,j;
    cin >> m >> n;
    for(i = 0;i < n;i++){
        for(int j = 0;j < m; j++){
        cin >> num;
        arr[i][j] = num;
        }
    }

    deque <pair <int,int>> q;
    for(i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if (arr[i][j] == 1){
                q.push_back(make_pair(i,j));
            }
        }
    }
    
    int x[4] = {0,0,1,-1};
    int y[4] = {-1,1,0,0};
    pair <int,int> pairs;

    while (q.size() > 0){
        pairs = q.front();
        q.pop_front();
        for(i = 0;i < 4;i++){
            if (pairs.first + x[i] < 0 || pairs.first + x[i] >= n || pairs.second + y[i] < 0 || pairs.second + y[i] >= m){
                continue;
            }
            if (arr[pairs.first + x[i]][pairs.second + y[i]] != 0){
                continue;
            }
            arr[pairs.first + x[i]][pairs.second + y[i]] = arr[pairs.first][pairs.second] + 1;
            q.push_back(make_pair(pairs.first + x[i],pairs.second + y[i]));
        }
    }
    int max = 0;
    for(i = 0;i < n;i++){
        for(j = 0;j < m;j++){
            if (arr[i][j] == 0){
                max = 0;
                goto result;
            }
            if (arr[i][j] > max){
                max = arr[i][j];
            }
        }
    }
    goto result;
    result:
    cout << max-1 << endl;
    return 0;
}