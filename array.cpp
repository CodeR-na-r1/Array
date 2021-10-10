#include "Array.h"

#define T long long int 

Array::Array()
{
	size = 0;
	capacity = 10;
	ptr = new T[capacity];
}

Array::Array(const T start_capacity = 10)
{
	size = 0;
	capacity = start_capacity;
	ptr = new T[capacity];
}

Array::Array(const T start_capacity, const T init)
{
	size = 0;
	capacity = start_capacity;
	ptr = new T[capacity];

	for (int i = 0; i < capacity; i++)
	{
		ptr[i] = init;
	}
}

Array::Array(const Array& arr)
{

}

T Array::getSize()
{
	return this->size;
}

T Array::getCapacity()
{
	return this->capacity;
}