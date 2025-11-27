#include<iostream>
#include<set>
using namespace std;
int main(){
   set<int>st;
   bool flag=false;
   int n;
   cin>>n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
    cin>>arr[i];
   }
   for (int i = 0; i < n; i++)
   {
    if(st.find(arr[i])!=st.end()){
        cout<<"FOUND";
       return 0;
    }
    st.insert(arr[i]);
   }
  cout<<"NOT FOUND";
}