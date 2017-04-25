#ifndef TREE_H
#define TREE_H

#include <cstdlib>
//implametation of tree class

template<class K, class V>
class Node{

    public:
    K key_;
    V value_;
    Node *right_, *left_, *parent_;
    Node() { right_ = NULL; left_ = NULL; parent_ = NULL;}
    

};



#endif
