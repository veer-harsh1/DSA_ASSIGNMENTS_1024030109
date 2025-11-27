#include<iostream>
  #include<set>
  using namespace std;
  int main(){
    set<int>st;
    int n1,n2;
    cin>>n1>>n2;
    int arr1[n1];
    int arr2[n2];
    int final[100];
    for (int i = 0; i < n1; i++)
    {
      cin>>arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
      cin>>arr2[i];
    }
    for (int i = 0; i < n2; i++)
    {
      st.insert(arr2[i]);
    }
    int mini=min(n1,n2);
    for (int i = 0; i < n1; i++)
    {
      if (st.find(arr1[i])!=st.end())
      {
        cout<<arr1[i]<<" ";
      }
      
    }
    return 0;
}