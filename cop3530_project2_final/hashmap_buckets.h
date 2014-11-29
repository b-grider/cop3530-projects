/* 
 * File:   hashmap_buckets.h
 * Author: Ben
 *
 * Created on November 17, 2014, 2:33 PM
 */

#ifndef HASHMAP_BUCKETS_H
#define HASHMAP_BUCKETS_H

#include<iostream>


class hashmap_buckets {
    
           //=======================
           // DATA MEMBERS / FIELDS
           //=======================
    
     struct item {
            int key;
            char value;
            item* next;

            item(int thisKey, char thisValue) : key(thisKey), value(thisValue), next(nullptr) {}
            item(int thisKey, char thisValue, item* nextOne) : key(thisKey), value(thisValue), next(nextOne) {}
        };
        
       //typedef item* link;
    
        //=============================
        //FIELDS    FIELDS      FIELDS
        //=============================
    
    item** kvpairs;
    int numberOfItems;
    
    
            //===========================
            //  PRIVATE MEMBER FUNCTIONS
            //===========================
    
            bool exists(item* thisItem, int key) {
                bool retval=false;

                while(thisItem != nullptr) {
                    if(thisItem->key == key) {
                        retval = true;
                    }
                    thisItem=thisItem->next;
                }

                return retval;
            }
            
            void replaceValue(item* thisItem, char value ) {
                thisItem->value = value;
            }
            
            int primaryHash(int key) {
                return key%50;
            }
            
            int secondaryHash(int key) {
                return ((key%43)+1);
            }
    
    
public:
    
    //=============================
    //  CONSTRUCTORS  CONSTRUCTORS
    //=============================
    
    hashmap_buckets() {
        kvpairs = new item*[50];
        
            for(int i=0; i<50; i++) {
                kvpairs[i] = nullptr;       //initialize all array slots as empty
            }
    }
    
    //========================
    //     PUBLIC MEMBERS
    //======================== 
    
bool insert( int key, char value ) {
    
    bool retval;
                        
         int i=key%50;            //starting array index is key%50 (naive hash)
         int count = 0;           //Start with the count at 0 break if we hit 50
         item* temptr = kvpairs[i];
         
            while((temptr) && (temptr->key != key)) {
                temptr = temptr->next;
            }
         
         if(this->exists(temptr, key)) {
             this->replaceValue(temptr, value );
             retval=true;
            // numberOfItems++;         don't increment the size; something is being replaced
         }
         else if(temptr == nullptr) {
             temptr = new item(key, value);
             retval=true;
             numberOfItems++;
         }
         
    return retval;
}
    
// — if there is space available, adds the specified key/value-pair to the hash map and returns true; 
//otherwise returns false. If an item already exists in the map with the same key, replace its value.

bool remove( std::string key, int value) {
    
    return true;
}
//— if there is an item matching key, removes the key/value-pair from the map, stores it's value in value, 
//and returns true; otherwise returns false.

bool search( int key, int value ) {
    
    bool retval=false;
    int index = key%50;
    item* temptr = kvpairs[index];
    int cap = this->capacity();
    
    while(temptr != nullptr) {
            if(this->exists(temptr, key)) {                     //If an item with the same key exists
                temptr->value = value;         //access it and replace the value with this value
                retval = true;
            }
        }
    
    return retval;
}

//— if there is an item matching key, stores it's value in value, and returns true (the item remains in the map);
//otherwise returns false.

void clear() {
    
    for(int i=0; i<50; i++) {
        
        if(kvpairs[i]) {
            item* temptr1 = kvpairs[i];
            item* temptr2;
            
                while(temptr1 != nullptr) {
                    temptr2 = temptr1->next;
                    delete temptr1;
                    temptr1=temptr2;
                }
            
        }
        
    }
    numberOfItems=0;
    
    return;
}

//— removes all items from the map.

bool is_empty() {
    
    bool retval;
    
        (numberOfItems == this->capacity())? retval=true: retval=false;
    
    return retval;
}
//— returns true IFF the map contains no elements.

std::size_t capacity() {
    return 50;
} 
//— returns the number of slots in the map.

std::size_t size() {
    return numberOfItems;
}
//— returns the number of items actually stored in the map.

double load() {
    return ((this->size())/(this->capacity()));
}
//— returns the map's load factor (size = load * capacity).

std::ostream& print( std::ostream& o ) {
    
    int s = this->capacity();
    
        for(int i=0; i<s; i++) {
            if(kvpairs[i] == nullptr) {
                o << "-, ";
            }
            else {
                item* temptr = kvpairs[i];
                    while(temptr!=nullptr) {
                        o << temptr->key << ", ";
                        temptr = temptr->next;
                    }
            }
        }
    return o;
}
//— inserts into the ostream, the backing array's contents in sequential order. 
//Empty slots shall be denoted by a hyphen, non-empty slots by that item's key. 
//[This function will be used for debugging/monitoring].
    
};

#endif  /* hashmap_buckets_H */

