#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    int arr[n][n]={0};
    for(int k=0;k<e;k++){
        int i,j;
        cin>>i>>j;
        arr[i][j]=1;
        arr[j][i]=1;

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int start;
    cin>>start;
    int visited[n]={0};
    int queue[n]={0},front=0,rear=0;
    visited[start]=1;
    queue[rear]=start;
    rear++;
    while(front<rear){
        int node=queue[front];
        front++;
        cout<<node<<" ";
        for(int i=0;i<n;i++){
            if(arr[node][i]==1&&visited[i]==0){
                visited[i]=1;
                queue[rear]=i;
                rear++;
            }
        }
    }
    return 0;
}