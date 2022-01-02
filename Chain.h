#include "ChainNode.h"
#ifndef Chain_H
#define Chain_H

template <class T>
class Chain{
	private:
		ChainNode<T> *first;
	public:
		class ChainIterator;
		Chain();
		Chain(ChainNode<T> *avlist);//available list
		Chain(const Chain<T>&);//copy constructor
		~Chain();
		ChainNode<T>* Get(int index);
		int IndexOf(const T &theElement) const;
		void Delete(int index);
		void Insert(int index,const T &theElement);
		void Print();
		ChainIterator begin();
		ChainIterator end();
		int Length();
		
		void Insert(int index,ChainNode<T> *node);
		void InsertBack(ChainNode<T> *node);
};
#endif
