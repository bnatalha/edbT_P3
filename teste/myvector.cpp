#include "myvector.h"  


int main () {
	int size = 10;
	Myvetor<int> v (size);

	for( int i =0; i< 10; i++)
		v.push_back(i);
	v.print();
	cout << v.back() <<endl;
	cout << v.front() <<endl;
	v.push_back(12);
	v.push_back(13);
	v.push_back(15);
	v.push_back(23);
	v.print();
	v.pop_back();
	v.print();
	v.pop_front();
	v.print();
	v.size();
	v.print();
	v.clear();
	cout << v.empty() << endl;


}