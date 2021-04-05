#include<iostream>

using namespace std;

void fun(int);

void fun(int size) {
	int *ptr = new int(size);
	cout<<"Enter some intergers"<< endl;
	int k=0;
	while(k!=size){
		int a;
		cin>>a;
		if(a < 0){
			cout<<"Invalid number"<<endl;
			return;
		}
		*(ptr+k) = a;
		k++;
	}

	for(int i=0; i<size; i++){
		cout<<"Num #"<<(i+1)<<": "<<*(ptr+i)<<endl;
		if(i!=0)
			*ptr += *(ptr+i);
	}

	cout<<"Sum is: "<< *ptr << endl;

	delete ptr;
}

int main() {
	fun(3);
	cout<<"Complete"<<endl;
	return EXIT_SUCCESS;
}
