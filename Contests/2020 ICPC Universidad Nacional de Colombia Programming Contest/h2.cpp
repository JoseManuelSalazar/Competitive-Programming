//https://codeforces.com/gym/102700
#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int alfa = 26;
const char L = 'a';

struct node {
  int next[alfa], link, len;
  ll cnt;
  node(int x, int l = 0, ll c = 1): len(x), link(l), cnt(c){
    memset(next, 0, sizeof next);
  }
  int& operator[](int i) { return next[i]; }
};

struct palindromic_tree {
  vector<node> tree;
  string s;
  int n;
  int last;
  palindromic_tree(string t = ""){
    n = last = 0;
    tree.pb(node(-1));
    tree.pb(node(0));
    for(auto &c: t)add_char(c);
  }

  int getlink(int p){
    while(s[n - tree[p].len - 1] != s[n])p = tree[p].link;
    return p;
  }

  void add_char(char ch){
    s.pb(ch);
    int p = getlink(last), c = ch - L;
    if(!tree[p][c]){
      int link = getlink(tree[p].link);
      link = max(1, tree[link][c]);
      tree[p][c] = SZ(tree);
      tree.pb(node(tree[p].len + 2,link, 0));
    }
    last = tree[p][c];
    tree[last].cnt++;
    n++;
  }

  int getans(){
    int ans = 0;
    forn(i, 2, tree.size()){
        if(tree[i].len&1 && tree[i].len > 1)ans++;
    }
    return ans;
  }

};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main d.cpp
  //./main < d.txt

  int n;
  string s;
  cin >> n >> s;
  palindromic_tree pt(s);

  cout << pt.getans() << endl;

}