#include<iostream>
using namespace std;
class maxHeap{
	int *arr;
	int size;
	int cap;
public:
	maxHeap(int n){
		arr=new int[n];
		size=0;
		cap=n;
	}
	void insert(int value){
		if(size==cap){
			cout<<"Heap Overflow"<<endl;
			return;
		}
		arr[size]=value;
		size++;
		int ind=(size-1);
		while(ind>0 && arr[ind]>arr[(ind-1)/2]){
			swap(arr[ind],arr[(ind-1)/2]);
			ind=(ind-1)/2;
		}
	}
	void heapify(int index){
		int largest=index;
		int left=index*2+1;
		int right=index*2+2;
		if(left<size && arr[left]>arr[largest]) largest=left;
		if(right<size && arr[right]>arr[largest]) largest=right;
		if(largest!=index){
			swap(arr[largest],arr[index]);
			heapify(largest);
		}
	}
	void remove(){
		if(size==0){
			cout<<"Heap Underflow"<<endl;
			return;
		}
		int ind=size-1;
		size--;
		swap(arr[0],arr[ind]);
		heapify(0);
	}
};
int main(){

}
