#include "ChainIterator.h"

template <class T>
Chain<T>::Chain(){
	first = nullptr;
}


template <class T>
Chain<T>::Chain(ChainNode<T> *avlist){
	first = avlist;
}



template <class T>
Chain<T>::Chain(const Chain<T> & b){
	if (b.first == nullptr) {
		first = nullptr;
		return;
	}
	
	ChainNode<T> *current;
	ChainNode<T> *b_current = b.first;
	ChainNode<T> *prev;
	current = new ChainNode<T>(b_current->data);
	first = current;
	prev = current;
	b_current = b_current->next;
	while(b_current != nullptr){
		current = new ChainNode<T>(b_current->data);
		b_current = b_current->next;
		prev->next = current;
		prev = current;
	}
	current->next = nullptr;
}


template <class T>
Chain<T>::~Chain(){
	while(first != nullptr){
		ChainNode<T> *next = first->next;
		delete first;
		first = next;
	}
}

template <class T>
ChainNode<T>* Chain<T>::Get(int index){
	ChainNode<T> *current = first;
	while(index--){
		if (current == nullptr) throw "out of range";
		current = current->next;
	}
	return current;
}

template<class T>
void Chain<T>::Insert(int theIndex,const T& theElement){
    if (theIndex < 0)
        throw "out of range";
    if (theIndex == 0)
        first = new ChainNode<T>(theElement, first);
    else
    {  
        ChainNode<T>* p = first;
        for (int i = 0; i < theIndex - 1; i++){
            if (p == 0) 
                throw "Bad insert index";
            p = p->next;
        } 
        p->next = new ChainNode<T>(theElement, p->next);
    }
}

template<class T>
void Chain<T>::Insert(int index,ChainNode<T> *node){
	if (index < 0)
        throw "out of range";
    if (index == 0){
    	node->next = first;
		first = node;
	}
    else
    {  
        ChainNode<T>* p = first;
        for (int i = 0; i < index - 1; i++){
            if (p == 0) 
                throw "Bad insert index";
            p = p->next;
        } 
        node->next = p->next;
        p->next = node;
    }
} 


template<class T>
void Chain<T>::InsertBack(ChainNode<T> *node){
	ChainNode<T> *p = first;
	if (p == nullptr){
		//insrt first
		node->next = nullptr;
		first = node;
		
		return;
	}
	
	while(p->next != nullptr){
		p = p->next;
	}// to last
	p->next = node;
	node->next = nullptr;
} 

template<class T>
void Chain<T>::Delete(int theIndex){
    if (first == 0) 
        throw "underflow";
    ChainNode<T>* deleteNode;
    if (theIndex == 0){
        deleteNode = first;
        first = first->next;
    }
    else {
        ChainNode<T>* p = first;
        for (int i = 0; i < theIndex - 1; i++){
            if (p == 0) 
                throw "Delete element does not exist?";
            p = p->next;
        }
        if (p->next == nullptr) throw "Delete element does not exist?";
        deleteNode = p->next;
        p->next = p->next->next; 
    }
    delete deleteNode;
}

template<class T>
int Chain<T>::IndexOf(const T& theElement) const{
    ChainNode<T>* currentNode = first;
    int index = 0;  
    while (currentNode != nullptr && currentNode->data != theElement){
        currentNode = currentNode->next;
        index++;
    }
    if (currentNode == nullptr) 
        return -1;
    else
        return index;
}

#include <iostream>

template<class T>
void Chain<T>::Print(){
	ChainNode<T> *current = first;
	while(current != nullptr){
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

template<class T>
typename Chain<T>::ChainIterator Chain<T>::begin(){
	return Chain<T>::ChainIterator(first);
} 


template<class T>
typename Chain<T>::ChainIterator Chain<T>::end(){
	return Chain<T>::ChainIterator(nullptr);
} 


template<class T>
int Chain<T>::Length(){
	int len = 0;
	ChainNode<T> *current = first;
	while(current != NULL){
		current = current->next;
		len++;
	}
	return len;
} 
