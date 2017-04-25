#ifndef MAP_H
#define MAP_H

#include "Tree.h"

template<class K , class V>
class Map{


    private:
        Node *root_;
        int size_;
        void erase_node(Node *node);
        void replace_subtree(Node * u, Node * v);
        //meow



    public:
        map() { root = null; size_ = 0;}
        void erase(K key){};
        void erase(){};
        int size(){ return size_;}
        bool empty(){ if(size_ == 0){ return true;} else return false;}
        Node* find(K key){};
        Node *min(K key){};

};




inline void erase_node(Node *node){

    node->parent_ = NULL;
    node->left_  = NULL;
    node->right_ = NULL;

    delete node->parent_, node->left_ , node -> right_;
}


void erase(K key){

    Node * z = find(key);
    if( z -> left_ == NULL){
        replace_subtree(z, z-> right_);
    }else if(z -> right_ == NULL){
        replace_subtree(z, z->left_);
    }else{
        Node * y = min(z->right_);
        if( y != z->right_){
            y->right_ = z->right_;
            y->right_->parent_ = y;
        }
        replace_subtree(z , y);
        y->left_ = z->left_;
        y->left_->parent_ = y;
    }
    z->left_  = z->right_  = NULL;
}

void replace_subtree(Node * u, Node * v){
    //Node * node = root_;
    if( u == root_){
        root_ = v;
        if( v != NULL){
            v->parent_ = NULL;
        }
    }else{
        Node * q = u->parent_;
        if( u == q->left_){
            q->left_ = v;
        }else{ q->right_ = v; }
        if( v != NULL){
            v->parent_ = q;
        }
        u->parent_ = NULL;
        }

    }
}
//Returns the min element
Node *min(){
    Node * node = root_;
        while(node->left_ != NULL){
            node = node->left;
        }
    return node;
}

//find a key
Node * find(K key){

    Node * node = root_;
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
