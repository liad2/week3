#pragma once
class Vector
{
public:
	Vector(int n);
	~Vector();
	int size();
	int capacity();
	int resizeFactor();
	bool empty();
	void push_back(const int& val);
	int pop_back();
	void reserve(int n);
	void resize(int n);
	void assign(int val);
	void resize(int n, const int& val);
	Vector& operator=(const Vector& other);
	int& operator[] (int n);
	
 



private:
	int* _elements;
	int _size;
	int _capacity;
	int _resizeFactor;
};

