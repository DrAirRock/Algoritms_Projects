#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <cstdlib>

using std::cout;

// Prototype for Map
template<class K, class V>
class Map;

// Prototype for Iterator
template<class K, class V>
class Iterator;


//////////////////// START NODE IMPLEMENTATION ////////////////////

// An individual node of the binary tree
// Contains a pointer to left child, right child, and parent. Also contains
// the key and value
// NOTE: Everything is private
//
// Used with Maps and Iterators to keep track of position in the tree
// Friendship granted to Maps and Iterators
template<class K, class V>
class Node{

	// Friendship!
	friend class Map<K, V>;
	friend class Iterator<K, V>;

    private:
    K key_;
    V value_;
    Node *right_, *left_, *parent_;
    Node() { right_ = NULL; left_ = NULL; parent_ = NULL;}

};

//////////////////// END NODE IMPLEMENTATION ////////////////////


//////////////////// START ITERATOR IMPLEMENTATION ////////////////////


// Used to move through the tree in order starting with the node initially given
// For the user to use, but not to make
//
// Used by Map to give the user a method of moving about the tree
// Uses Node to maintain position
// Uses std::pair to return a constant pointer the user can use but not change
// Friendship granted to Map
template<class K, class V>
class Iterator{

	friend class Map<K, V>;

	private:
		Iterator(){ node = NULL;}
		Iterator(Node<K, V> * otherNode){ node = otherNode;}

		Node<K, V> * getNode(){return node;}

		Node<K, V> * node;
		std::pair<K, V>  pair;

	public:
		const std::pair<K, V> *operator*();
		void operator++();
		void operator++(int);
		bool operator==(Iterator<K, V> otherIt){return node == otherIt.node;}
		bool operator!=(Iterator<K, V> otherIt){return node != otherIt.node;}
};


// Dereferences the iterator, returns a constant pointer to the std::pair corresponding
// to the key and value stored in the node
// NOTE: May return NULL
//
// If node is NULL return NULL
// Else return pointer to std::pair object
template<class K, class V>
inline const std::pair<K, V>* Iterator<K, V>::operator*(){
	// If node is not NULL, get a pair and return a constant
	// pointer to it
	if (node != NULL){
		pair = std::make_pair(node->key_, node->value_);

		const std::pair<K, V> *p = &pair;

		return p;
	}
	// If node is NULL, just return NULL
	else
		return NULL;
}



// Gets the next largest element in the tree and updates node accordingly.
// NOTE: A modified version of successor() is used
//
// Creates a dummy map to use the successor() method
// Prefix version (++it)
template<class K, class V>
void Iterator<K,V>::operator++(){
	// This is an exact match of successor() except
	// instead of returning, node is updated

	// If node has right child, get the min
	if (node->right_ != NULL){
		node = node->right_;
        while(node->left_ != NULL){
            node = node->left_;
        }
	}

	// Otherwise find the next right parent of node
	else{
		Node<K, V> *y = node->parent_;
		while( y != NULL && node == y->right_){
			node = y;
			y = node->parent_;
		}
		node = y;
	}
}



// Gets the next largest element in the tree and updates node accordingly.
// NOTE: A modified version of successor() is used
//
// Uses the successor() method from Map
// Postfix version (it++)
template<class K, class V>
void Iterator<K,V>::operator++(int){
	// This is an exact match of successor() except
	// instead of returning, node is updated

	// If node has right child, get the min
	if (node->right_ != NULL){
		node = node->right;
        while(node->left_ != NULL){
            node = node->left_;
        }
	}

	// Otherwise find the next right parent of node
	else{
		Node<K, V> *y = node->parent_;
		while( y != NULL && node == y->right){
			node = y;
			y = node->parent_;
		}
		y = NULL;
	}
}


//////////////////// END ITERATOR IMPLEMENTATION ////////////////////


//////////////////// START MAP IMPLEMENTATION ////////////////////

// The class that brings it all together!
// Map is used to create a Binary Search Tree that maps keys to values
// The user has various methods at their disposal to navigate the tree
// NOTE: Tree may become unbalanced
//
// Uses Node class as the points on the tree and to store appropriate key and values
// Uses Iterator class to allow the user to navigate the tree safely
template<class K , class V>
class Map{

    private:
        Node<K, V> *root_;
        int size_;

        void replace_subtree(Node<K, V> * &u, Node<K, V> * &v);
        Node<K, V> *successor(Node<K, V> *node);
        Node<K, V> *erase_all(Node<K, V> *&node);
        void erase_node(Node<K,V> *&node);
        Node<K, V>* get_root(){return root_; }
        Node<K ,V> *max(Node<K, V> * root);
        Node<K, V> *min(Node<K, V> * root);
        Node<K, V>* find_node(K key);
        Node<K,V> * copy_node(Node<K,V> node);
		void insert(const K &key, const V &value);
		Node<K, V> * insert(const K &key);
		void deepCopy(Node<K, V> * &node);
		void printTree();
        void printNode(Node<K, V> * node);


    public:
        Map() { root_ = NULL; size_ = 0;}

		Map<K, V>(const Map<K, V> &otherMp);

		// Begin Iterator is the node with the smallest key or NULL if empty
		Iterator<K, V> begin(){
			if (root_ != NULL)
				return Iterator<K, V>( min(root_) );
			else
				return Iterator<K, V>();
		}
		// End Iterator is an Iterator with the node pointing to NULL
		// NOTE: This is done by the default constructor
		Iterator<K, V> end(){return Iterator<K, V>();}

        bool erase(K key);
        Iterator<K, V> erase(Iterator<K, V> it);
        int  size(){ return size_;}
        bool empty(){ if(size_ == 0){ return true;} else return false;}
        void clear();
        Iterator<K, V> find(K key);
		void swap(Map<K, V> &otherMp);
        V& operator[](K index);
    //    void erase(K key){
        //destructor
        ~Map() { clear(); }
};


// Copy constructor
// NOTE: Performs a deep copy
template <class K, class V>
Map<K, V>::Map(const Map<K, V> &otherMp){

	root_ = NULL;
	size_ = 0;

	Node<K, V> * node = otherMp.root_;
	deepCopy(node);
}


// Helper function, peforms a deep copy to the given node
// NOTE: Done recursively
template <class K, class V>
void Map<K, V>::deepCopy(Node<K, V> * &node){
	// While the node is not null, insert it first then its children
	if (node != NULL){
		insert(node->key_, node->value_);
		deepCopy(node->left_);
		deepCopy(node->right_);
	}
}



// Swaps the contents of our current map with the given map
template<class K, class V>
void Map<K, V>::swap(Map<K, V> &otherMp){

	// Put info in temp variables
	Node<K, V> * tempRoot = root_;
	int tempSize = size_;

	// Make these the current map's variables
	root_ = otherMp.root_;
	size_ = otherMp.size_;

	// Update otherMp
	otherMp.size_ = tempSize;
	otherMp.root_ = tempRoot;
}


//indexing operator
template <class K, class V>
V& Map<K,V>::operator[](K index){
    Node<K,V> * node = find_node(index);

	if (node == NULL)
		node = insert(index);

    return node->value_;
}

// Debugging method
// NOTE: Should be made private when not in use
template <class K, class V>
void Map<K, V>::printTree(){
    cout<<"Printing Tree...\n";
    if(root_ != NULL){
    	Node<K, V>* node = min(root_);
    	int numElement = 1;
    	while(node != NULL){
    		cout << "Element " << numElement << ":\n";
    		cout << "Key: " << node->key_ << '\n';
    		cout << "Value: " << node->value_ << '\n';
            cout << "Size: " << size_ <<"\n\n";
    		node = successor(node);
    		++numElement;
    	}
    }
}


// Debugging method
// NOTE: Should be made private when not in use
template <class K, class V>
inline void Map<K, V>::printNode(Node<K, V> * node){
        if(root_ != NULL){
    	//	cout << "Element " << numElement << ":\n";
    		cout << "Key: " << node->key_ << '\n';
    		cout << "Value: " << node->value_ << '\n';
            cout << "Size: " << size_ <<"\n\n";
        }

}


// Grabs the next highest element to the node given as the argument
// NOTE: May return NULL
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


// Inserts a node into the Binary Tree based on the given key and value
// NOTE: Nodes are dynamically allocated

template <class K, class V>
void Map<K, V>::insert(const K &key, const V &value){
	// Allocate a new node and set accordingly
	Node<K, V> *z = new Node<K, V>;
	z->key_ = key;
	z->value_ = value;

    ++size_;

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


// Same as above except no value is given
template <class K, class V>
Node<K, V> *  Map<K, V>::insert(const K &key){
	// Allocate a new node and set accordingly
	Node<K, V> *z = new Node<K, V>;
	z->key_ = key;

    ++size_;

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

	return z;

}

// Deallocates every node in the tree efficiently
template<class K, class V>
void Map<K, V>::clear(){

    erase_all(root_);
    size_ = 0;
}

// Helper method to clear()
template<class K, class V>
Node<K, V>* Map<K,V>::erase_all(Node<K,V> * &node){
    //post order tree traversal
    if( node != NULL){
    erase_all(node->left_);
    erase_all(node->right_);
    erase_node(node);
    }
}

// Completely deallocates the given node
// NOTE: Node is assumed to already have been removed from the tree
template<class K, class V>
void Map<K, V>::erase_node(Node<K, V> * &node){

    node->parent_ = NULL;
    node->right_ = NULL;
    node->left_ = NULL;
    delete node;
	node = NULL;
    //size_--;
}

// Removes the node with the given key and deallocates the node
template <class K, class V>
bool Map<K, V>::erase(K key){

    Node<K, V> * z = find_node(key);
	if (z != NULL){
        size_--;
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
		z = NULL;
		return true;
	}

	else
		return false;
}

// Removes the node with the given key and deallocates the node
template <class K, class V>
Iterator<K, V> Map<K, V>::erase(Iterator<K, V> it){

    Node<K, V> * z = it.getNode();

	if (z != NULL){
        size_--;
		Iterator<K, V> returnItr(successor(z));

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
		z = NULL;
		return returnItr;
	}

	else
		return Iterator<K, V>();
}



// Replaces one subtree with another
// Used with erase() methods
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


// Nabs the node with the largest key
template<class K, class V>
Node<K, V> * Map<K,V>::max(Node<K, V> *root){
    Node<K , V> * node = root;
    while( node->right_ !=NULL){
        node = node->right_;
    }
    return node;
}


//Nabs the node with the smallest key
template <class K, class V>
Node<K, V> * Map<K, V>::min(Node<K, V> *root){
    Node<K, V> * node = root;
        while(node->left_ != NULL){
            node = node->left_;
        }
    return node;
}


//Finds the Node with the given key
template <class K, class V>
Node<K, V> * Map<K, V>::find_node(K key){

    Node<K, V> * node = root_;
    while( node != NULL){
        if(key < node->key_){
            node = node->left_;
        }
        else if (node->key_ < key){
            node = node->right_;
        }
		else
			break;
    }
    return node;
}


// Returns an iterator pointing to the node with the given key
template <class K, class V>
Iterator<K, V> Map<K, V>::find(K key){

    Node<K, V> * node = root_;
    while( node != NULL ){
		// Key is less than node's
        if(key < node->key_){
            node = node->left_;
        }
		// Key is greater than node's
        else if (node->key_ < key){
            node = node->right_;
        }
		else // Keys are equal
			break;
    }
    return Iterator<K,V>(node);
}

//////////////////// END MAP IMPLEMENTATION ////////////////////

#endif
