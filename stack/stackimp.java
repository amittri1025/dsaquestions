import java.util.*;

class Stack{
	int size = 10;
	int [] stackarr;
	
	Stack(int size){
		this.size = size;
		stackarr = new int[size];
	}
	
	
	int pos = 0;
	
	void insert(int val){
		stackarr[pos] = val;
		pos++;
	}
	
	void pop(){
		stackarr[pos] = 0;
		pos--;
	}
	
	void print(){
		for(int i=0; i<pos; i++){
			System.out.println(stackarr[i]);
		}
		
	}
}

public class stackimp{
	public static void main(String[] args){
	// am i gonna implement stack
	Stack st = new Stack(10);
	st.insert(10);
	st.insert(20);
	st.insert(30);
	st.insert(40);
	st.insert(50);
	st.print();
	System.out.println("after popping");
	st.pop();
	st.pop();
	st.print();
	System.out.println("after inserting");
	st.insert(600);
	st.insert(700);
	st.print();

		}
}
