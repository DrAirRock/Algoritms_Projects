#ifndef MAP_H
#define MAP_H

#include "Tree.h"

template<class K , class V>
class Map{


    private:
        Node *root;
        int size_;
        void erase_node();
        //meow



    public:
        map() { root = null; size_ = 0;}
        void erase();
        int size(){ return size_;}
        bool empty(){ if(size_ == 0){ return true;} else return false;}
        void find(){}


}




#endif
