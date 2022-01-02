#ifndef ChainIterator_H
#define ChainIterator_H
#include "CircularList.h"
#include "Chain.h"

template <class T>
class CircularList<T>::ChainIterator{
	private:
		ChainNode<T> *current;
	public:
		ChainIterator(ChainNode<T> *startNode = 0);
		T& operator*();
		T* operator->();
		CircularList<T>::ChainIterator& operator++();
		CircularList<T>::ChainIterator& operator++(int);
		bool operator !=(const ChainIterator right);
		bool operator ==(const ChainIterator right);
		operator bool();
};


template <class T>
class Chain<T>::ChainIterator {
private:
	ChainNode<T>* current;
public:
	ChainIterator(ChainNode<T>* startNode = 0);
	T& operator*() const;
	T* operator->() const;
	Chain<T>::ChainIterator& operator++();
	Chain<T>::ChainIterator& operator++(int);
	bool operator !=(const ChainIterator right) const;
	bool operator ==(const ChainIterator right) const;
	operator bool();
};
#endif