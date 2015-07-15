// prettyprint.hpp

#ifndef PRETTYPRINT_INCLUDED
#define PRETTYPRINT_INCLUDED


#include <iterator>
#include <iosfwd>
#include <vector>
#include <stack>
#include <queue>


// Macro to wrap the actual function calls around some extra useful information like the line number
// on which they were called, and to insert some formatting too.
#define print(i) std::cout << "Line " << __LINE__ << " : " << #i " = " << (i) << std::endl

#define PRETTYPRINT_GENERIC_CONTAINER_OUTPUT_NAMED_HOOK(obj, strm, whilehook, outhook, posthook) \
	auto separator = "";                                                                           \
	while(whilehook) {                                                                             \
		(strm) << separator;                                                                         \
		(strm) outhook;                                                                              \
		(posthook);                                                                                  \
		separator = ", ";                                                                            \
	}

#define PRETTYPRINT_GENERIC_CONTAINER_OUTPUT_NAMED(obj, strm) \
	auto separator = "";                                        \
	for(const auto & element : (obj)) {                         \
		(strm) << separator << element;                           \
		separator = ", ";                                         \
	}

#define PRETTYPRINT_GENERIC_CONTAINER_OUTPUT PRETTYPRINT_GENERIC_CONTAINER_OUTPUT_NAMED(object, out)


template <class T1, class T2>
std::ostream & operator<<(std::ostream & out, const std::pair<T1, T2> & object) {
	out << '(' << object.first << ", " << object.second << ')';
	return out;
}

template <class T1, size_t arrSize, class = std::enable_if_t<!std::is_same<T1, char>::value>>
std::ostream & operator<<(std::ostream & out, const T1(&object)[arrSize]) {
	out << '[';
	PRETTYPRINT_GENERIC_CONTAINER_OUTPUT
	out << ']';
	return out;
}


/// Primary template for all self-respecting containers
template <class... ContA, template <class...> class Cont, class = std::enable_if_t<!std::is_same<Cont<ContA...>, std::string>::value>>
std::ostream & operator<<(std::ostream & out, const Cont<ContA...> & object) {
	out << '[';
	PRETTYPRINT_GENERIC_CONTAINER_OUTPUT
	out << ']';
	return out;
}


/// Wrappers

// Print a stack
template <class... T1>
std::ostream & operator<<(std::ostream & out, const std::stack<T1...> & object) {
	out << '[';
	auto object_copy(object);
	PRETTYPRINT_GENERIC_CONTAINER_OUTPUT_NAMED_HOOK(object_copy, out, !object_copy.empty(), << object_copy.top(), object_copy.pop());
	out << ']';
	return out;
}

// Print a queue
#define PRETTYPRINT_QUEUE_CONTAINER_OUTPUT_NAMED(q, topfun)                                                                              \
	template <class... T1>                                                                                                                 \
	std::ostream & operator<<(std::ostream & out, const q<T1...> & object) {                                                               \
		out << '[';                                                                                                                          \
		auto object_copy(object);                                                                                                            \
		PRETTYPRINT_GENERIC_CONTAINER_OUTPUT_NAMED_HOOK(object_copy, out, !object_copy.empty(), << object_copy.topfun(), object_copy.pop()); \
		out << ']';                                                                                                                          \
		return out;                                                                                                                          \
	}

PRETTYPRINT_QUEUE_CONTAINER_OUTPUT_NAMED(std::queue, front)
PRETTYPRINT_QUEUE_CONTAINER_OUTPUT_NAMED(std::priority_queue, top)


#endif  // PRETTYPRINT_INCLUDED
