#ifndef CircularList_H
#define CircularList_H
#include "ChainNode.h" 

template <class T>
class CircularList {
private:
	ChainNode<T>* head;
	ChainNode<T>* tail;
	ChainNode<T>* sentinel;
public:
	static ChainNode<T>* av;

	CircularList();
	~CircularList();
	CircularList(const CircularList<T>&); // copy constructor
	void InsertFront(const T&);
	void InsertTail(const T&);
	void InsertFront(ChainNode<T>*);
	void InsertTail(ChainNode<T>*);
	void InsertSort(ChainNode<T>*, bool(*c)(T,T) = nullptr);
	static ChainNode<T>* GetNode();
	static ChainNode<T>* GetAVlist();
	static void RetNode(ChainNode<T>*&);
	void print();
	void Delete(int);

	class ChainIterator;
	ChainIterator begin();
	ChainIterator end();

	bool comp(T,T);

	ChainNode<T>* GetSentinel();
	int Length();
};
#endif