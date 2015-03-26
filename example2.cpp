#include "prettyprint.hpp"
using namespace std;

int main()
{
	vector<stack<int>> v1(3); // Works for nested types too !
	for(size_t i=0;i<v1.size();i++)
	{
		for(size_t j=0;j<5;j++)
		{
			v1[i].push(i*j);
		}
		cout << v1[i] << endl;
		//print(v1[i]);
	}
	cout << v1 << endl;
	print(v1); // This prints the variable name as well as the line number of the source code on which it is invoked.
}
