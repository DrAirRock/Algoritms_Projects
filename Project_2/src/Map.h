#ifndef MAP_H
#define MAP_H

#include "Tree.h"
#include <iostream>
#include <cstdlib>

using std::cout;

template<class K , class V>
class Map{


    private:
        Node<K, V> *root_;
        int size_;
        void replace_subtree(Node<K, V> * &u, Node<K, V> * &v);
		Node<K, V> *successor(Node<K, V> *node);
        //meow


    public:
        Map() { root_ = NULL; size_ = 0;}
        void erase(K key);
        void erase(){};
        int size(){ return size_;}
        bool empty(){ if(size_ == 0){ return true;} else return false;}
        Node<K, V>* find(K key);
        Node<K, V> *min(Node<K, V> * root);
		void insert(const int &key, const int &value);
		void printTree();

};


template <class K, class V>
void Map<K, V>::printTree(){
	Node<K, V>* node = min(root_);
	int numElement = 1;
	while(node != NULL){
		cout << "Element " << numElement << ":\n";
		cout << "Key: " << node->key_ << '\n';
		cout << "Value: " << node->value_ << '\n';

		node = successor(node);
		++numElement;
	}
}



template <class K, class V>
Node<K, V> * Map<K, V>::successor(Node<K, V> *node){
	// If node has right child, get the min
	if (node->right_ != NULL)
		return min(node->right_);

	// Otherwise find the next right parent of node
	else{
		Node<K, V> *y = node->parent_;
		while( y != NULL && node == y->right_){
			node = y;
			y = node->parent_;
		}
		return y;
	}
}




template <class K, class V>
void Map<K, V>::insert(const int &key, const int &value){
	// Allocate a new node and set accordingly
	Node<K, V> *z = new Node<K, V>;
	z->key_ = key;
	z->value_ = value;

	// If no root, make z the root
	if (root_ == NULL)
		root_ = z;

	// The fun case!
	// If you need to go left, go left
	// If right go right
	// Keep going until you hit NULL
	else{
		Node<K, V> *q = root_;
		bool done = false;
		while(!done){
			// If go left
			if (z->key_ < q->key_){
				if (q->left_ == NULL){
					q->left_ = z;
					done = true;
				}
				else
					q = q->left_;
			}
			// Else go right
			else{
				if (q->right_ == NULL){
					q->right_ = z;
					done = true;
				}
				else
					q = q->right_;
			}
		}
		// Set parent to q and we are done!
		z->parent_ = q;
	}

}


template <class K, class V>
void Map<K, V>::erase(K key){

    Node<K, V> * z = find(key);
	if (z != NULL){
    	if( z -> left_ == NULL){
        	replace_subtree(z, z-> right_);
    	}else if(z -> right_ == NULL){
        	replace_subtree(z, z->left_);
    	}else{
        	Node<K, V> * y = min(z->right_);
        	if( y != z->right_){
				replace_subtree(y, y->right_);
            	y->right_ = z->right_;
            	y->right_->parent_ = y;
        	}
        	replace_subtree(z , y);
        	y->left_ = z->left_;
        	y->left_->parent_ = y;
    	}
    	z->left_  = z->right_  = NULL;
		delete z;
	}
}

template <class K, class V>
void Map<K, V>::replace_subtree(Node<K, V> * &u, Node<K, V> * &v){
    //Node * node = root_;
    if( u == root_){
        root_ = v;
        if( v != NULL){
            v->parent_ = NULL;
        }
    }else{
        Node<K, V> * q = u->parent_;
        if( u == q->left_){
            q->left_ = v;
        }else{ q->right_ = v; }
        if( v != NULL){
            v->parent_ = q;
        }
        u->parent_ = NULL;
    }
}



//Returns the min element
template <class K, class V>
Node<K, V> * Map<K, V>::min(Node<K, V> *root){
    Node<K, V> * node = root;
        while(node->left_ != NULL){
            node = node->left_;
        }
    return node;
}

//find a key
template <class K, class V>
Node<K, V> * Map<K, V>::find(K key){

    Node<K, V> * node = root_;
    while( node != NULL && node->key_ != key){
        if(key < node->key_){
            node = node->left_;
        }
        else{
            node = node->right_;
        }

    }
    return node;
}


#endif
