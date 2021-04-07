#include <iostream> 
using namespace std; 

template <typename T>
void bubbleSort(T a[], int n) { 
    for (int i = 0; i < n - 1; i++) 
        for (int j = n - 1; i < j; j--) 
            if (a[j] < a[j - 1]) 
              swap(a[j], a[j - 1]); 
} 
   
int main() { 
	int size = 5;
	int a[size] = {10, 50, 20, 5, 40};
	char c[size] = {'a', 'z', 'e', 'b', 'c'};
	string s[size] = {"luke", "leia", "obi-wan", "darth-vader", "han"};

	bubbleSort(a ,size);
	for(int i=0; i<size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	bubbleSort(c ,size);
	for(int i=0; i<size; i++) {
		cout << c[i] << " ";
	}
	cout << endl;

	bubbleSort(s ,size);
	for(int i=0; i<size; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	return EXIT_SUCCESS; 
} 
