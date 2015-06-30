#include "prettyprint.hpp"
using namespace std;

int main()
{
	vector<vector<int> > vec;
	vec.push_back( vector<int> {1, 2, 3, 4, 5} );
	vec.push_back( vector<int> {5, 4, 3, 2, 1} );

	cout << vec << endl;
	print( vec ); // This prints the variable name as well as the line number of the source code on which it is invoked.
}
