#include <bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    stack<int> dfs; dfs.push(0);
    unordered_set<int> seen = {0};
    while (!dfs.empty()) {
        int i = dfs.top(); dfs.pop();
        for (int j : rooms[i])
            if (seen.count(j) == 0) {
                dfs.push(j);
                seen.insert(j);
                if (rooms.size() == seen.size()) return true;
            }
    }
    return rooms.size() == seen.size();
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<vector<int>> arr(n);
	    for(int i=0;i<n;i++){
	        int a;
	        cin>>a;
	        for(int j=0;j<a;j++){
	            int b;
	            cin>>b;
                arr[i].push_back(b);    
	        }
	    }
	    if(canVisitAllRooms(arr)){
	        cout<<"YES"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	    
	}
	return 0;
}