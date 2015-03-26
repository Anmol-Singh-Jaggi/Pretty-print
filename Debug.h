// Debug.h

// Header guard
#if !defined DEBUG_INCLUDED && defined __cplusplus
#define DEBUG_INCLUDED

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<set>
#include<stack>
#include<queue>

#define debug(i) std::cout << "Line " << __LINE__ << " : " << #i" = " << i << std::endl

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
	for ( const auto& it : object )
	{
		out << it << ", ";
	}
	if ( object.size() )
	{
		out << "\b\b";
	}
	out << "]";
	return out;
}

// print a set
template<typename T1>std::ostream& operator <<( std::ostream& out, const std::set<T1>& object )
{
	out << "{";
	for ( const auto& it : object )
	{
		out << it << ", ";
	}
	if ( object.size() )
	{
		out << "\b\b";
	}
	out << "}";
	return out;
}

// print a map
template<typename T1, typename T2>std::ostream& operator <<( std::ostream& out, const std::map<T1, T2>& object )
{
	out << "|";
	for ( const auto& it : object )
	{
		out << it << ", ";
	}
	if ( object.size() )
	{
		out << "\b\b";
	}
	out << "|";
	return out;
}

// print a stack
template<typename T1>std::ostream& operator <<( std::ostream& out, const std::stack<T1>& object )
{
	out << "[";
	std::stack<T1> object_copy( object );
	while ( !object_copy.empty() )
	{
		out << object_copy.top() << ", ";
		object_copy.pop();
	}
	if ( object.size() )
	{
		out << "\b\b";
	}
	out << "]";
	return out;
}

// print a queue
template<typename T1>std::ostream& operator <<( std::ostream& out, const std::queue<T1>& object )
{
	out << "[";
	std::queue<T1> object_copy( object );
	while ( !object_copy.empty() )
	{
		out << object_copy.front() << ", ";
		object_copy.pop();
	}
	if ( object.size() )
	{
		out << "\b\b";
	}
	out << "]";
	return out;
}

#endif // DEBUG_INCLUDED
