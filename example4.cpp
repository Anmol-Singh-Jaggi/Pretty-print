#include <iostream>
using namespace std;

// Note : This file is NOT supposed to get compiled successfully.

template<typename T1, size_t Size>ostream& operator <<( ostream& out, T1 const( & array )[Size] )
{
	out << "[";
	copy( array, array + Size - 1, std::ostream_iterator<T1>( out, ", " ) );
	if ( Size )
	{
		out << array[Size - 1];
	}
	out << "]";
	return out;
}

int main()
{
	int arr[] = {1, 2, 3};
	cout << arr << endl;
}
