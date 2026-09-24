/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:04:40 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/23 18:04:40 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <stdexcept>

template<typename T>
Array<T>::Array()
{
	cnt = 0;
	arr = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	cnt = n;
	arr = new T[n];
	for (unsigned int i = 0; i < n; i++)
		arr[i] = 0;
}

template<typename T>
Array<T>::~Array()
{
	cnt = 0;
	delete[] arr;
}

template<typename T>
Array<T>::Array(const Array& array) : arr(NULL), cnt(0)
{
	cnt = array.cnt;
	arr = new T[cnt];
	for (unsigned int i = 0; i < array.cnt; i++)
		arr[i] = array.arr[i];
}

template<typename T>
T& Array<T>::operator=(const Array& array)
{
	if (this != &array)
	{
		T*	tmp = new T[array.cnt];
		for (unsigned int i = 0; i < array.cnt; i++)
			tmp[i] = array.arr[i];
		
		delete[] arr;
		arr = tmp;
		cnt = array.cnt;
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= cnt)
		throw std::out_of_range("Index out of range");
	return (arr[i]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= cnt)
		throw std::out_of_range("Index out of range");
	return (arr[i]);
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (cnt);
}
