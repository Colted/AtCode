#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
int main(void){
 
  string A;
  cin >> A;
  string C="chokudai";
  int s=A.size();
  vector dp(s+1,vector<int>(9));
  rep(i,s+1) dp[i][0]=1;
  const int mod=1000000007;
  
  rep(i,s){
  	rep(j,8){
      	if(A[i]==C[j]){
          /*正解*/
        	dp[i+1][j+1] =(dp[i][j+1]+dp[i][j]) % mod;
        }else{
          /*不正解*/
        	dp[i+1][j+1]=dp[i][j+1];
        }
    }
  
  }
  cout<<dp[s][8]<<endl;
  return 0;
}