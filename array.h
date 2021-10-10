#pragma once
typedef long long int T;

#include <iostream>

using namespace std;

class Array
{
public:
	Array();
	Array(const T start_capacity=10);
	Array(const T start_capacity, const T init);
	Array(const Array& arr);
	T getSize();
	T getCapacity();
	T& operator[](T size);
	T& operator=(T elem);
	T& operator=(Array& arr);
	friend istream& operator>> (istream& in, Array& arr);
	friend ostream& operator<< (ostream& out, Array& arr);
	~Array();

private:
	T* ptr;
	T size;
	T capacity;
};