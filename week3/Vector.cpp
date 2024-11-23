#include "Vector.h"
#include <iostream>

#define MIN_CAPACITY 2

Vector::Vector(int n)
{
	_capacity = n;
	if (_capacity < MIN_CAPACITY)
		_capacity = MIN_CAPACITY;

	_elements = new int[_capacity];
	_size = n;
	_resizeFactor = 20;
}

Vector::~Vector() 
{
	delete[] _elements;
}

int Vector::size()
{
	return _size;
}
int Vector::capacity()
{
	return _capacity;
}
int Vector::resizeFactor()
{
	return _resizeFactor;

}
bool Vector::empty()
{
	return (_size == 0);
}

void Vector::push_back(const int& val) 
{
	if (_size < _capacity) 
	{
		_elements[_size] = val;
		_size++;
	}
	else
	{
		int* p = new int[_capacity + _resizeFactor];
		int i = 0;
		for (i = 0; i < _size; i++) 
		{
			p[i] = _elements[i];
		}
		delete[] _elements;
		_elements = p;
		_capacity += _resizeFactor;
	} 

	
}
int Vector::pop_back() 
{
	if (empty()) 
	{
		std::cout << "vector error: pop from empty" << std::endl;
		return -9999;
	}
	_size--;
	return _elements[_size];
}
void Vector::reserve(int n) 
{
	if (_capacity < n)
	{
		int new_capacity = 0;
		int needed = (n - _capacity);
		int increase = (needed / _resizeFactor) * _resizeFactor;
		if (increase < needed)
			increase += _resizeFactor;
		new_capacity += increase;
		int* p = new int[_capacity + increase];
		int i = 0;
		for (i = 0; i < _size; i++)
		{
			p[i] = _elements[i];
		}
		delete[] _elements;
		_elements = p;
		_capacity = new_capacity;
	}
}

void Vector::resize(int n) 
{
	if (n > _capacity)
	{
		reserve(n);
	}
	else
	{
		_size = n;
	}
	
}
void Vector::assign(int val)
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		_elements[i] = val;
	}
}
void Vector::resize(int n, const int& val)
{
	resize(val);
	int i = 0;
	for (i = 0; i < _capacity - _size; i++) {
		_elements[i] = val;
	}
}

Vector& Vector::operator=(const Vector& other)
{
	if (this == &other)
		return *this;
	delete[] _elements;
	_elements = new int[other._capacity];
	int i = 0;
	for (i = 0; i < other._size; i++) 
	{
		_elements[i] = other._elements[i];
	}
	_size = other._size;
	_capacity = other._capacity;
	return *this;


}

int& Vector::operator[](int n)
{
	if (n >= _size || n < 0) 
	{
		std::cerr << "ERROR invalid vector index" << std::endl;
		return _elements[0];
	}
	return _elements[n];
}





