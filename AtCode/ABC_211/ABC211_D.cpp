#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
using mint=modint1000000007;
 
int main(void){
	int n,m;
  	cin>>n>>m;
	vector<vector<int>> to(n);
  rep(i,m){
    /*経路を挿入*/
  	int a,b;
  	cin >> a >> b;
  	--a;
  	--b;
  	to[a].push_back(b);
    to[b].push_back(a);
  }
  const int INF =1001001001;
  vector<int> dist(n,INF);
  vector<int> vs;
  queue<int> q;
  q.push(0);
  dist[0]=0;
  while(q.size()){
  	int v=q.front();
    q.pop();
    vs.push_back(v);
    for(int u : to[v]){
      /*頂点を確認*/
   		if(dist[u] != INF) continue;
      /*距離の算出*/
      	dist[u]=dist[v]+1;
      q.push(u);
    }
  }
  
  vector<mint> dp(n);
  dp[0]=1;
  for(int v : vs){
  	for(int u: to[v]){
    	if(dist[u] == dist[v]+1){
        	dp[u] += dp[v];
        }
    }
  }
  mint ans = dp[n-1];
  cout<<ans.val()<<endl;
  return 0;
  
  
  
  
}