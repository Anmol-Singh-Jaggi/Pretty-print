#include "prettyprint.hpp"
using namespace std;

int main()
{
	int arr[] = {1, 2, 3};
	cout << arr << endl;
	print( arr );

	int nestedArr[2][5] = {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}};
	cout << nestedArr << endl;
	print( nestedArr );

	char cString[] = "abc";
	cout << cString << endl;
	print( cString );

	char charArr[] = {'a', 'b', 'c', '\0'};
	cout << charArr << endl;
	print( charArr );
}
