/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:31:27 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/22 16:31:27 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cassert>
// *Can write "class" instead of "typename"


// In c++20:
/*
CONCEPTS:

template<typename T>
concept SupportsLessThan = requires (T x) {x < x; }

// requires std::copyable<T> && SupportsLessThan<T>

*/
template <typename T>
T	mymax(T a, T b)
{
	return (b < a ? a : b);
}

// Multiple parameters.
template <typename T1, typename T2>
auto mymin(T1 a, T2 b) // <------ Let the compiler decide the return type.
{
	return b > a ? a : b;
}

// iterate over elemtns of different containers
// template<class T>
// void	print(const T& col1)
// {
// 	for (const auto& elem : col1)
// 	{
// 		std::cout << elem << '\n'; 
// 	}
// }

template<typename T>
class Stack
{
	private:
		std::vector<T>	elems;

	public:
		Stack();
		void	push(const T&);
		T	pop();
		T	top() const;
		bool empty() const
		{
			return elems.empty();
		}
};

template<typename T>
Stack<T>::Stack()
{
	//
}

template<typename T>
void	Stack<T>::push(const T& elem)
{
	elems.push_back(elem);
}

template<typename T>
T	Stack<T>::pop()
{
	assert(!elems.empty());
	T	elem = elems.back();
	elems.pop_back();
	return (elem);
}

template<typename T>
T Stack<T>::top() const
{
	assert(!elems.empty());
	return (elems.back());
}

// Array:
template<typename T, size_t	SZ>
struct array
{
	T	elems[SZ];

	size_t	size() const { return SZ; }

	T&	operator[] (size_t idx) { return elems[idx]; }

	const	T&	operator[] (size_t idx) const { return elems[idx]; }

	typedef	T*	iterator;
	T*	begin() {return &elems[0];}
	T*	end() {return &elems[0] + SZ;}
};

template<typename ElemT, typename... Types> // <--- any number of types
void	print(ElemT firstArg, Types... args) // <--- any number of arguments (of any type)
{
	std::cout << firstArg << '\n';
	if constexpr(sizeof...(args) > 0)
	{
		print(args...);
	}
}

/*
template<typename col>
concept HasPushBack = requires (Col c, Col::value_type v) {
	c.push_back(v);
};

void	add(HasPushBack auto& coll, const auto& val)
{
	coll.push_back(val);
}

void	add(auto& coll, const auto& val)
{
	coll.insert(val);
}
*/

