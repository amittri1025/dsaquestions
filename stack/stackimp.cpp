#include <iostream>
using namespace std;

class Stack{
	public:
		int *arr;
		int data;
		int size;
		int top	;
		
		Stack(int size){
		this->size = size;
		arr = new int[size];
		top = -1;
		}
		
	// implementation
	void push(int element){
		if(size>top){
			top++;	
			arr[top] = element;
		}else{
			cout<<"Stack overflow"<<endl;
		}
	}
	
	void pop(){
		if(top>=1){
			top--;
		}else{
			cout<<"Stack is already Empty"<<endl;
		}
	}
	
	void peek(){
		if(top>=0){
			cout<<arr[top]<<endl;
		}else{
			cout<<"Stack is empty"<<endl;
		}
	}
	
	bool isEmpty(){
		if(top>=1) return true;
		else return false;
	}
	
	void print(){
		for(int i=0; i<=size; i++){
			cout<<arr[i]<<"  ";
		}
	}
};

int main(){
		Stack st(5);
	
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5):
		st.push(6);
		//~ overflow
		st.push(7);
		
	
		st.print();
	return 0;

}
