#include "ChainIterator.h"
#include "Chain.h"


template <class T>
CircularList<T>::ChainIterator::ChainIterator(ChainNode<T>* startNode) {
	current = startNode;
}

template <class T>
T& CircularList<T>::ChainIterator::operator*(){
	return current->data;
}


template <class T>
T* CircularList<T>::ChainIterator::operator->(){
	return &current->data;
}

template <class T>
typename CircularList<T>::ChainIterator& CircularList<T>::ChainIterator::operator++() {
	current = current->next;
	return *this;
}

template <class T>
typename CircularList<T>::ChainIterator& CircularList<T>::ChainIterator::operator++(int) {
	CircularList<T>::ChainIterator* old = this;
	current = current->next;
	return *old;
}

template <class T>
bool CircularList<T>::ChainIterator::operator!=(const CircularList<T>::ChainIterator right){
	return current != right.current;
}

template <class T>
bool CircularList<T>::ChainIterator::operator==(const CircularList<T>::ChainIterator right){
	return current == right.current;
}

template <class T>
CircularList<T>::ChainIterator::operator bool() {
	return (bool)(current != nullptr);
}

template <class T>
Chain<T>::ChainIterator::ChainIterator(ChainNode<T>* startNode) {
	current = startNode;
}

template <class T>
T& Chain<T>::ChainIterator::operator*() const {
	return current->data;
}


template <class T>
T* Chain<T>::ChainIterator::operator->() const {
	return &current->data;
}

template <class T>
typename Chain<T>::ChainIterator& Chain<T>::ChainIterator::operator++() {
	current = current->next;
	return *this;
}

template <class T>
typename Chain<T>::ChainIterator& Chain<T>::ChainIterator::operator++(int) {
	Chain<T>::ChainIterator* old = this;
	current = current->next;
	return *old;
}

template <class T>
bool Chain<T>::ChainIterator::operator!=(const Chain<T>::ChainIterator right) const {
	return current != right.current;
}

template <class T>
bool Chain<T>::ChainIterator::operator==(const Chain<T>::ChainIterator right)const {
	return current == right.current;
}

template <class T>
Chain<T>::ChainIterator::operator bool() {
	return (bool)(current != nullptr);
}