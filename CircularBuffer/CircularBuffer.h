/*
* Circular Buffer of Generic Value-type
* Copyright (c) 2015
*
* Arthur: Chung-Chen (Thomas) Hsieh
* Email: ttoomm318@gmail.com
*
*/

#pragma once

#ifdef _EXPORT
#define CIRCULARBUFFER_API __declspec(dllexport) 
#else
#define CIRCULARBUFFER_API __declspec(dllimport) 
#endif

#include <memory>

// circular buffer class
template<class T>
class CIRCULARBUFFER_API CircularBuffer
{
public:
	explicit CircularBuffer(size_t capacity);
	CircularBuffer(const CircularBuffer& other);
	CircularBuffer(CircularBuffer&& other);
	CircularBuffer& operator=(CircularBuffer other);
	virtual ~CircularBuffer();

	// non-member swap function for the copy-and-swap idiom
	friend void swap(CircularBuffer& first, CircularBuffer& second)
	{
		using std::swap;

		swap(first.capacity_, second.capacity_);
		swap(first.size_, second.size_);
		swap(first.front_, second.front_);
		swap(first.back_, second.back_);
		swap(first.buffer_, second.buffer_);
	}

	void print_buffer();
	void push_back(const T& value); 
	T pop_front();
	void clear();

	// check if the buffer is empty
	bool is_empty() const { return size_ == 0; }

	// return buffer capacity 
	size_t capacity() const { return capacity_; }

	// return buffer size
	size_t size() const { return size_; }

protected:
	// default constructor for optimizing copy-and-swap idiom
	CircularBuffer(){}

	size_t capacity_;
	size_t size_;
	int front_;
	int back_;
	T* buffer_;
};