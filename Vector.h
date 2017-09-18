#pragma once
#include <memory>
using std::allocator;
typedef unsigned int size_t;
template <class item>
class Vector {
public:
	allocator<item> allo;
public:
	size_t size() { return len; }
	item at(size_t pos) { return buff[pos]; }
	void clear(){}
	void push_back(const item& it,int pos){ buff[pos] = it; }
	void pop_back();
	Vector(size_t sz):len(sz) { buff = allo.allocate(sz); };
	~Vector(){ allo.deallocate(buff, len); }
private:	
	size_t capacity;
	size_t len;
	item* buff;
};
