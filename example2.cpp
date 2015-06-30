#include "prettyprint.hpp"
using namespace std;

int main()
{
	vector<stack<int>> vec( 3 );
	for ( size_t i = 0; i < vec.size(); i++ )
	{
		for ( size_t j = 0; j < 5; j++ )
		{
			vec[i].push( i * j );
		}
		cout << vec[i] << endl;
		//print(vec[i]);
	}
	cout << vec << endl;
	print( vec ); // This prints the variable name as well as the line number of the source code on which it is invoked.
}
