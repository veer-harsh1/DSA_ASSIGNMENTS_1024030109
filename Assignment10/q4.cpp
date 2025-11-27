  #include<iostream>
      #include<map>
      using namespace std;
      int main(){
      map<int,int>mp;
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i <n; i++)
        {
           cin>>arr[i];
        }
        for (int i = 0; i < n; i++)
        { 
          mp[arr[i]]++;  
        }
        for (int i = 0; i < n; i++)
        {
        if (mp[arr[i]]==1)
        {
         cout<<arr[i];
         break; 
        }
        
        }
        
        return 0;
    }