#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
int n,k;
int ans;
const int di[]={-1,0,1,0};
const int dj[]={0,-1,0,1};
 
void dfs(vector<string> s){
    int cnt=0;
    rep(i,n)rep(j,n) if(s[i][j]=='o') cnt++;
    if(cnt == k){
    	ans++;
     return;
    }
  rep(i,n)rep(j,n){
    if(s[i][j] != '.') continue;
    if(cnt != 0){
    	bool ok=false;
        rep(v,4){
    	    int ni=i+di[v],nj=j+dj[v];
      	    if(ni<0 || nj<0 ||ni>=n || nj>=n) continue;
      	    if(s[ni][nj]=='o') ok = true;
        }
        if(!ok) continue;
    }
	s[i][j]='o';
	dfs(s);
  	s[i][j]='#';
  	dfs(s);
  	return;
  }
}
int main(void){
  cin>>n>>k;
  
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  dfs(s);
  cout <<ans<<endl;
  return 0;
  
}