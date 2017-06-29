#include "myvectorsearch.h"

int main()
{
	long int size = 10;
	long int l = 0;
	long int d = 10;
	long int x = 10;
	vector<long int> v (size);
	randomFill( v, size, 1);
	sort ( v.begin(), v.end());
	busca_sequencial_iterativa ( v, x, l, d );
	print(v);
	return 0;
}