#include<stack>
#include<iostream>

using namespace std;


class queue{
	public:
	int size=0;
	int *arr;
	queue(int s){
		size = s;
		arr=new int[size];
	
	}

	int rear = -1;
	int front = 0;
	
	//~ size = 3, 
	void push(int num){
		if(rear<size-1){
			rear++;
			arr[rear] = num;			
		}else{ 
			cout<<"Queue Overflow"<<endl;
		}
	}
	
	void pop(){
		if(front==rear){
			cout<<"Queue underflow"<<endl;

		}else{
			front++;
			if(front==rear){ 
			front = 0;
			rear = 0;
			}
		}
	}
	
	void isEmpty(){
		if(front>rear){
			cout<<"queue is empty"<<endl;
		}else{
			cout<<"queue is not empty"<<endl;
		}
	}
	
	void printAll(){
		for(int i= front; i<=rear; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){		
	queue qu(10);
	
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.printAll();
	
	qu.pop();
	qu.pop();
	
	qu.printAll();
	
	qu.isEmpty();
	
	return 0;
}

