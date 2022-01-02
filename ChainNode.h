#ifndef ChainNode_H
#define ChainNode_H
template<class T>
class ChainNode {
public:
	T data;
	ChainNode* next;
	ChainNode(T data, ChainNode* next) :data(data), next(next) {}
	ChainNode(T data) :data(data), next(nullptr) {}
	ChainNode() :next(nullptr) {}
};
#endif