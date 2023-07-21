#include <iostream>
#include <stack>

using namespace std;

int main(){
	string s = "Tripathi";
	stack<char> st;
	//~ to reverse this 
	
	for(int i=0; i<s.size(); i++){
		char ch = s[i];
		st.push(ch);
	}
	
	//~ now popping outstack_t
	
	string ans = "";
	
	while(!st.empty()){
		char ch = st.top();
		ans  = ans + ch;
		
		st.pop();
	}
	
	cout<<ans;
	
	
}
