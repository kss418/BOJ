#include <iostream>
#include <stack>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;


stack <char> st;
bool chk(string& s){
    for(int i = 0;i < s.size();i++){
        if(s[i] == '(' || s[i] == '[') st.push(s[i]);
        else{
            if(st.empty()) return 0;
            if(s[i] == ')' && st.top() == '[') return 0;
            else if(s[i] == ']' && st.top() == '(') return 0;
            st.pop();
        }
    }

    return 1;
}

int result[31];
int main(){
    fastio;
    string s; cin >> s;
    if(!chk(s)){
        cout << 0; return 0;
    }

    int cnt = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '(' || s[i] == '[') cnt++;
        else if(s[i] == ')'){
            cnt--;
            result[cnt] += 2 * max(result[cnt + 1], 1);
            result[cnt + 1] = 0;
        }
        else{
            cnt--;
            result[cnt] += 3 * max(result[cnt + 1], 1);
            result[cnt + 1] = 0;
        }
    }

    cout << result[0];
    return 0;
}