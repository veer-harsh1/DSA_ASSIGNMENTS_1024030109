#include<iostream>
   #include<unordered_map>
   using namespace std;
   int main(){
      unordered_map<int,int>mp;
      int n;
      cin>>n;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
       cin>>arr[i];
      }
      for (int i = 0; i <n; i++)
      {
        mp[arr[i]]++;
      }

      for (auto i = mp.begin(); i!=mp.end(); i++)
      {
        cout<<i->first<<"->"<<i->second<<endl;
      }
      return 0;
      
   }