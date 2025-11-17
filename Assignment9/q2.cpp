#include<iostream>
using namespace std;
void dfs(int start,int arr[][100],int n,bool visited[]){
   visited[start]=true;
   cout<<start;
   for(int i=0;i<n;i++){
    if(arr[start][i]==1&&visited[i]==false){
        dfs(i,arr,n,visited);

    }
   }
}
int main(){
  int n,e;
  cin>>n>>e;
  int arr[100][100]={0};
  for(int k=0;k<e;k++){
    int i,j;
    cin>>i>>j;
    arr[i][j]=1;
    arr[j][i]=1;
  }
  bool visited[100]={false};
  int start;
  cin>>start;
  dfs(start,arr,n,visited);
  
}