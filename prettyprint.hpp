// prettyprint.hpp

// Header guard
#ifndef PRETTYPRINT_INCLUDED
#define PRETTYPRINT_INCLUDED

#include<iostream>
#include<iterator>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<set>
#include<stack>
#include<queue>

#define print(i) std::cout << "Line " << __LINE__ << " : " << #i" = " << i << std::endl

// print an array
// Does not work on nested arrays !
#define printarr(arr) std::cout << "Line " << __LINE__ << " : " << #arr" = ";printarray(arr);cout << std::endl;
template<typename T1, size_t Size>void printarray( T1 const( & array )[Size] )
{
	std::cout << "[";
	copy( array, array+Size-1, std::ostream_iterator<T1>( std::cout, ", " ) );
	if ( Size )
	{
		std::cout << array[Size-1];
	}
	std::cout << "]";
}

// print a pair
template<typename T1, typename T2>std::ostream& operator <<( std::ostream& out, const std::pair<T1, T2>& object )
{
	out << "( " << object.first << ", " << object.second << " )";
	return out;
}

// print a vector
template<typename T1>std::ostream& operator <<( std::ostream& out, const std::vector<T1>& object )
{
	out << "[";
	copy( object.begin(), --object.end(), std::ostream_iterator<T1>( out, ", " ) );
	if ( !object.empty() )
	{
		out << *--object.end(); // print the last element separately to avoid the extra characters after.
	}
	out << "]";
	return out;
}

// print a set
template<typename T1>std::ostream& operator <<( std::ostream& out, const std::set<T1>& object )
{
	out << "{";
	copy( object.begin(), --object.end(), std::ostream_iterator<T1>( out, ", " ) );
	if ( !object.empty() )
	{
		out << *--object.end();
	}
	out << "}";
	return out;
}

// print a map
template<typename T1, typename T2>std::ostream& operator <<( std::ostream& out, const std::map<T1, T2>& object )
{
	out << "|";
	copy( object.begin(), --object.end(), std::ostream_iterator<T1>( out, ", " ) );
	if ( !object.empty() )
	{
		out << *--object.end();
	}
	out << "|";
	return out;
}

// print a stack

template<typename T1>std::ostream& operator <<( std::ostream& out, const std::stack<T1>& object )
{
	out << "[";
	std::stack<T1> object_copy( object );
	while ( object_copy.size()>1 ) // print the last element separately to avoid the extra characters after.
	{
		out << object_copy.top() << ", ";
		object_copy.pop();
	}
	if ( !object_copy.empty() )
	{
		out << object_copy.top();
		object_copy.pop();
	}
	out << "]";
	return out;
}

// print a queue

template<typename T1>std::ostream& operator <<( std::ostream& out, const std::queue<T1>& object )
{
	out << "[";
	std::queue<T1> object_copy( object );
	while ( object_copy.size()>1 )
	{
		out << object_copy.front() << ", ";
		object_copy.pop();
	}
	if ( !object_copy.empty() )
	{
		out << object_copy.front();
		object_copy.pop();
	}
	out << "]";
	return out;
}

#endif // PRETTYPRINT_INCLUDED
