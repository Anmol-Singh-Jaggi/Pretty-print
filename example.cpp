#include "debug.h"
#include<cstdlib> // for rand()
using namespace std;

int main()
{
	const int vector_size = 3;
	vector<stack<int>> v1(vector_size); // Works for nested types too !
	for(int i=0;i<vector_size;i++)
	{
		const int stack_size = rand()%10;
		for(int j=0;j<stack_size;j++)
		{
			v1[i].push(rand()%100);
		}
		debug(v1[i]);
	}
	debug(v1);
}
