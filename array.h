#pragma once
typedef long long int T;

#include <iostream>

using namespace std;

class Array
{
public:
	Array();
	Array(const T start_size);
	Array(const T start_size, const T init);
	Array(const Array& arr);

	T getSize() const;
	T getCapacity() const;

	void insert(T num, T index);
	void insert(T num);
	void insert(const Array& arr, T index);
	void remove(T index);

	T& operator[](const T num) const;
	Array& operator=(const Array& arr);
	bool operator==(const Array& arr);
	bool operator!=(const Array& arr);
	friend istream& operator >>(istream& in, Array& arr);
	friend ostream& operator <<(ostream& out,const Array& arr);

	~Array();

private:
	T* ptr = nullptr;
	T size = 0;
	T capacity = 0;
	void increase_capacity(T new_capacity);
};