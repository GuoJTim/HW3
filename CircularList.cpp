#include "CircularList.h"
#include "ChainIterator.h"
#include <iostream>


template <class T>
ChainNode<T>* CircularList<T>::av = nullptr;

template<class T>
CircularList<T>::CircularList() {

	sentinel = new ChainNode<T>(); // sentinel 
	sentinel->next = sentinel;
	head = sentinel->next;
	tail = sentinel->next;
	tail->next = sentinel;
}

template<class T>
CircularList<T>::CircularList(const CircularList<T>& b) {
	sentinel = new ChainNode<T>(); // sentinel 
	sentinel->next = sentinel;
	head = sentinel->next;
	tail = sentinel->next;
	tail->next = sentinel;
	ChainNode<T>* prev = sentinel, * current, * b_current = b.head;
	if (b_current == b.sentinel || b_current == nullptr) {// circular list b is empty
		return;
	}
	else {
		current = new ChainNode<T>(b_current->data);
		head = current;
		prev->next = current;
		prev = current;
		b_current = b_current->next;
		while (b_current != b.sentinel) {
			current = new ChainNode<T>(b_current->data);
			prev->next = current;
			prev = current;
			b_current = b_current->next;
		}
		tail = current;
		tail->next = sentinel;
	}
}


template<class T>
void CircularList<T>::InsertFront(const T& e) {
	ChainNode<T>* newNode = new ChainNode<T>(e);
	InsertFront(newNode);
}

template<class T>
void CircularList<T>::InsertFront(ChainNode<T>* newNode) {
	if (head != sentinel) {
		newNode->next = sentinel->next;
		sentinel->next = newNode;
		head = newNode;
	}
	else {
		head = newNode;
		tail = newNode;
		newNode->next = sentinel;
		sentinel->next = newNode;
	}
}


template<class T>
void CircularList<T>::InsertTail(const T& e) { // insert last
	ChainNode<T>* newNode = new ChainNode<T>(e);
	InsertTail(newNode);
}

template<class T>
void CircularList<T>::InsertTail(ChainNode<T>* newNode) { // insert last
	if (tail != sentinel) {
		newNode->next = sentinel;
		tail->next = newNode;
		tail = newNode;
	}
	else {
		//empty list
		head = newNode;
		tail = newNode;
		newNode->next = sentinel;
		sentinel->next = newNode;
	}
}

template<class T>
void CircularList<T>::print() {
	ChainNode<T>* current = head;
	if (head == nullptr || sentinel == nullptr) return;
	while (current != sentinel) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}


template <class T>
void CircularList<T>::Delete(int index) {
	ChainNode<T>* current = head;
	if (head->next == sentinel && index == 0) {
		//only have 1 node (sentinel)
		delete head;
		head = sentinel;
		tail = sentinel;
		sentinel->next = sentinel;
	}
	else if (index == 0) {
		//remove head
		ChainNode<T>* deleteNode = head;
		head = head->next;
		sentinel->next = head;
		delete deleteNode;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			if (current->next == sentinel) {
				throw "out of range";
			}
			current = current->next;

		}
		if (current->next == sentinel) throw "out of range";
		ChainNode<T>* deleteNode = current->next;
		current->next = current->next->next;
		delete deleteNode;
	}
	if (current->next == tail) tail = current;
}



template<class T>
typename CircularList<T>::ChainIterator CircularList<T>::begin() {
	return CircularList<T>::ChainIterator(head);
}


template<class T>
typename CircularList<T>::ChainIterator CircularList<T>::end() {
	return CircularList<T>::ChainIterator(sentinel);
}



template <class T>
ChainNode<T>* CircularList<T>::GetSentinel() {
	return sentinel;
}

template <class T>
int CircularList<T>::Length() {
	ChainNode<T>* current = head;
	int size = 0;
	if (head == sentinel || sentinel == nullptr) return 0;
	while (current != sentinel) {
		size++;
		current = current->next;
	}
	return size;
}



template<class T>
ChainNode<T>* CircularList<T>::GetNode() {
	ChainNode<T>* x;
	if (av) {
		x = av;
		av = av->next;
		x->next = nullptr;// remove next link
	}
	else x = nullptr;// return empty 
	return x;
}


template<class T>
ChainNode<T>* CircularList<T>::GetAVlist() {
	ChainNode<T>* x;
	if (av) {
		x = av;
		av = nullptr;
	}
	else x = nullptr;// return empty 
	return x;
}


template<class T>
void CircularList<T>::RetNode(ChainNode<T>*& x) {
	x->next = av;
	av = x;
	x = 0;
}

template <class T>
CircularList<T>::~CircularList() {
	if (head != sentinel) {
		tail->next = av;
		av = head;
		tail = sentinel;
		head = sentinel;
	}
}

template <class T>
bool CircularList<T>::comp(T a, T b) {
	return true;//default compare function
}

template <class T>
void CircularList<T>::InsertSort(ChainNode<T> *newNode, bool(*c)(T,T) ) {
	ChainNode<T>* prev = sentinel, * current = head;
	int index = 0;
	if (c == nullptr) {
		while (current != sentinel && comp(newNode->data, current->data)) {
			prev = current;
			current = current->next;
			index++;
		}
	}
	else {
		while (current != sentinel && (*c)(newNode->data, current->data)) {
			prev = current;
			current = current->next;
			index++;
		}
	}
	if (index == 0) {
		//add front
		// change head
		InsertFront(newNode);

	}
	else if (current == sentinel) {
		//add last
		// change tail
		InsertTail(newNode);

	}
	else {
		// just add
		newNode->next = prev->next;
		prev->next = newNode;

	}
}