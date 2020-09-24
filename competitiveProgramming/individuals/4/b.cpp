#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

ll sum(int n){
  return 1ll*n*(n+1)/2;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n, r;
    cin >> n >> r;
    ll ans = 0;
    int x = min(r, n-1);
    ans += sum(x);
    if(r >= n)ans++;
    cout << ans << endl;
  }

    
  
}

