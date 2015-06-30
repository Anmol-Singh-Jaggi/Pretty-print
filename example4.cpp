#include <iostream>
using namespace std;

// Note : This file is NOT supposed to get compiled successfully.

template<typename T1, size_t arrSize>
ostream& operator <<( ostream& out, T1 const( & arr )[arrSize] )
{
	out << "[";
	if ( arrSize )
	{
		const char* separator = "";
		for ( const auto& element : arr )
		{
			out << separator;
			out << element;
			separator = ", ";
		}
	}
	out << "]";
	return out;
}

int main()
{
	int arr[] = {1, 2, 3};
	cout << arr << endl;
}
