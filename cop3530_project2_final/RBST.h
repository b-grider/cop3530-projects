/* 
 * File:   RBST.h
 * Author: Ben
 *
 * Created on December 1, 2014, 3:15 PM
 */

#ifndef RBST_H
#define	RBST_H

#include<iostream>
#include<limits>


namespace cop3530 {

template<typename KEY, typename VALUE,bool op_equals = true, 
        typename EQ_FUNC = bool, EQ_FUNC eq_test = false, 
        bool op_lessthan = true, 
        typename LESSTHAN = bool, LESSTHAN less_than = false>
class RBST {
    
    struct node {
        KEY key;
        VALUE value;
        int left;
        int right;
    };
    
    
    //Leaf nodes will be specified by BOTH left and right members being == -1
    
    
    node* data;
    int root;
    int freeHead;
    double cap;
    double noItems;
    
    
    //=================================
    //  CONSTRUCTORS/PUBLIC MEMBERS
    //=================================
    
    public:
        
        RBST(int capacity) {
            
            data = new node[capacity];
            root = -1;
            freeHead = 0;
            cap=capacity;
            noItems=0;
            
                for(int i=0; i<(capacity-1); i++) {
                    data[i].left = (i+1);
                }
            data[capacity-1].left = -2;                      //-2 marks the end of free list
        }
        
        //if there is space available, adds the specified key/value-pair to the tree and returns 
        //the number of nodes visited, V; otherwise returns -1 * V. If an item already exists in 
        //the tree with the same key, replace its value.
        
        int insert(KEY key, VALUE value) {
            return 1;
        }
    
        /*if there is an item matching key, removes the key/value-pair from the tree, 
         * stores it's value in value, and returns the number of probes required, V; 
         * otherwise returns -1 * V.*/
        
        int remove(KEY key, VALUE &value) {
            return 1;
        }
        
        /*if there is an item matching key, stores it's value in value, and returns the number of nodes visited, V; 
         * otherwise returns -1 * V. Regardless, the item remains in the tree.*/
        int search( KEY key, VALUE &value ) {
            return 1;
        }
        
        bool is_empty() {
            return (noItems == 0);
        }
        
        std::size_t capacity() {
            return cap;
        }
        
        std::size_t size() {
            return noItems;
        }
        
        double load() {
            return (noItems/cap);
        }
        
        std::ostream& print( std::ostream& o ) {
            return o;
        }
        
        void cluster_distribution(std::vector<int>& out) {
            return;
        }
        
        KEY remove_random() {
            KEY k = data[0].key;
            return k;
        }
        
};

}
#endif	/* RBST_H */

