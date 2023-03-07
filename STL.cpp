//~ to include all the libraries
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	//~ pair<int, int> p= {1, 2};
	//~ cout<<p.first<<" "<<p.second<<endl;
	
	
	//~ pair<int, pair<int, int>> q = {1, {1,2}};
	//~ cout<<q.first<<" "<<q.second.first<<" "<<q.second.second<<endl;
	
	//~ pair<int, int > arr[] = {{1,2}, {2,3}, {3,4}};
	//~ cout<<arr[0].first<<arr[1].second<<endl;
	
	//~ vector<int> v ;
	//~ v.push_back(1);
	//~ v.push_back(2);
	//~ v.push_back(3);
	//~ v.push_back(4);
	
	//~ for(vector<int>::iterator it = v.begin(); it!=v.end(); it++){
		//~ cout<<*(it)<<" "<<endl;
	//~ }
	
	//~ for(auto i = v.begin(); i!=v.end(); i++){
		//~ cout<<*(i)<<endl;
	//~ }
	
	//~ v.erase(v.begin()+5);
	//~ v.erase(v.begin()+3, v.begin()+6);
	
	//~ insert operation, used to insert things at places within an array
	
	//~ for(int i=0; i<10; i++){
		//~ v.insert(v.begin()+i, i);
	//~ }
	
	// 0 1 2 3.. 9 1 2 3 4
	
	//~ copy method
	

	//~ vector<int> amit(2,99);
	//~ v.insert(v.begin(), amit.begin(), amit.end());
	
	//~ v.pop_back(); // removes the first ellement
	//~ v.clear();
	//~ cout<<"size of vector"<<v.size()<<endl;
	
 	//~ for(auto i:v){
		//~ cout<<i<<endl;
	//~ }
	
	
	//~ vector<int> v1 = {1, 2};
	//~ vector<int> v2 = {5, 7};
	
	//~ v1.swap(v2);
	
	//~ for(auto i:v1){
		//~ cout<<i<<endl;
	//~ }
	
	//~ for(auto i:v2){
		//~ cout<<i<<endl;
	//~ }
	
	
	//~ queue <int> q;
	//~ q.push(1);
	//~ q.push(2);
	//~ q.push(3);
	//~ q.push(4);
	//~ q.push(5);
	
	//~ while(!q.empty()){
		//~ cout<<q.front()<<endl;
		//~ q.pop();
	//~ }
	
	//~ set<int> st;
	//~ st.insert(1);
	//~ st.insert(2);
	//~ st.insert(3);
	//~ st.insert(4);
	
	
	//~ auto it =st.find(3);
	//~ auto it = st.find(6); 	

	//~ st.erase(2, 12);
	
	map<int, int> mpp;
	
	mpp[0] = 1;
	mpp.emplace({3, 4});
	mpp.insert({2,4});
	mpp[{2,3}] = 10;
	
	cout<<mpp[1];
	cout<<mpp[2];
	cout<<mpp[3];

	return 0;
}
