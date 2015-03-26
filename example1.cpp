#include "prettyprint.hpp"
using namespace std;

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	printarray( arr ); // "cout << arr;" wont work !
	cout << endl;
	printarr( arr ); // This prints the variable name as well as the line number of the source code on which it is invoked.

	vector<int> v1( arr, arr + sizeof( arr ) / sizeof( arr[0] ) ); // Initialize the vector from the array
	cout << v1 << endl;
	print( v1 ); // This prints the variable name as well as the line number of the source code on which it is invoked.
}
