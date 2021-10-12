#include "array.h"

typedef long long int T;

Array::Array()
{
	size = 0;
	capacity = 10;
	ptr = new T[capacity];
}

Array::Array(const T start_size)
{
	size = start_size >= 0 ? start_size : 10;
	capacity = size + 10;
	ptr = new T[capacity];
	for (long long int i = 0; i < size; i++)
	{
		ptr[i] = 0;
	}
}

Array::Array(const T start_size, const T init)
{
	size = start_size >= 0 ? start_size : 10;
	capacity = size + 10;
	ptr = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		ptr[i] = init;
	}
}

Array::Array(const Array& arr)
{
	this->size = arr.size;
	this->capacity = arr.capacity;
	this->ptr = new T[this->size];
	for (long long int i = 0;  i < this->size;  i++)
	{
		ptr[i] = arr.ptr[i];
	}
	return;
}

T Array::getSize() const
{
	return this->size;
}

T Array::getCapacity() const
{
	return this->capacity;
}

T& Array::operator [](const T num) const
{
	if (num < 0 || num >= this->size)
		throw "error index!";
	else
		return this->ptr[num];
}

Array& Array::operator=(const Array& arr)
{
	if (this->ptr == arr.ptr)
		return *this;
	if (this->capacity < arr.size)
	{
		delete[] ptr;
		this->capacity = arr.size + 10;
		ptr = new T[this->capacity];
	}

	this->size = arr.size;

	for (long long int i = 0; i < this->size; i++)
	{
		this->ptr[i] = arr.ptr[i];
	}

	return *this;
}

istream& operator >>(istream& in, Array& arr)
{
	T elem;
	in >> elem;
	arr.insert(elem);
	return in;
}

ostream& operator <<(ostream& out, const Array& arr)
{
	out << "total size = " << arr.size << endl;
	for (long long int i = 0; i < arr.size; i++)
	{
		cout << arr.ptr[i] << endl;
	}
	return out;
}

Array::~Array()
{
	delete[] ptr;
}

bool Array::operator==(const Array& arr)
{
	if (size != arr.size)
		return false;
	for (long long int i = 0; i < size; i++)
	{
		if (ptr[i] != arr[i])
			return false;
	}
	return true;
}

bool Array::operator!=(const Array& arr)
{
	return !(*this == arr);
}

void Array::insert(T num, T index)
{
	if (index < 0 || index > size)
		throw "error index!";
	if (capacity < size + 1)
	{
		increase_capacity(size + 10);
	}
	for (long long int i = size-1; i >= index; --i)
	{
		ptr[i+1] = ptr[i];
	}
	ptr[index] = num;
	++size;
	return;
}

void Array::insert(T num)
{
	insert(num, size);
	return;
}

void Array::insert(const Array& arr, T index)
{
	if (index < 0 || index > size)
		throw "error index!";
	if (capacity < size + arr.size)
	{
		increase_capacity(size + arr.size + 10);
	}
	for (long long int i = size - 1; i >= index; --i)
	{
		ptr[i + arr.size] = ptr[i];
	}
	for (long long int i = index; i < index+arr.size; ++i)
	{
		ptr[i] = arr[i-index];
	}
	size += arr.size;
	return;
}

void Array::remove(T index)
{
	if (index < 0 || index >= size)
		throw "error index!";
	for (long long int i = index; i < size-1; ++i)
	{
		ptr[i] = ptr[i + 1];
	}
	--size;
	return;
}

void Array::increase_capacity(T new_capacity)
{
	capacity = capacity * 2 > new_capacity ? capacity * 2 : new_capacity;
	T* new_ptr = new T[capacity];
	for (long long int i = 0; i < size; i++)
	{
		new_ptr[i] = ptr[i];
	}
	delete[] ptr;
	ptr = new_ptr;
	return;
}