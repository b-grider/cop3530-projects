/* 
 * File:   hashmap_oa.h
 * Author: Ben
 *
 * Created on November 17, 2014, 2:33 PM
 */
/*
#ifndef HASHMAP_OA_H
#define	HASHMAP_OA_H

#include<iostream>
//#include<>

class hashmap_oa {
    
           //=======================
           // DATA MEMBERS / FIELDS
           //=======================
    
     struct item {
            int key;
            char value;

            item(int key, int value) : key(this->key), value(this->value) {} 
        };
        
        typedef item* link;
    
        //=============================
        //FIELDS    FIELDS      FIELDS
        //=============================
    
    link kvpairs;
    int size;
    
    
            //===========================
            //  PRIVATE MEMBER FUNCTIONS
            //===========================
    
            bool exists(link thisItem, int key) {
                bool retval;

                    if(thisItem->key == key) {     //If an item with the same key exists
                        retval = true;                                                      //return true
                    }
                    else {
                        retval=false;
                    }

                return retval;
            }
            
            void replaceValue(link thisItem, char value ) {
                thisItem->value = value;
            }
            
            int primaryHash(int key) {
                return key%50;
            }
            
            int secondaryHash(int key) {
                return ((key%97)+1);
            }
    
    
public:
    
    //=============================
    //  CONSTRUCTORS  CONSTRUCTORS
    //=============================
    
    hashmap_oa() {
        kvpairs = new link[50];
        
            for(int i=0; i<50; i++) {
                kvpairs[i] = nullptr;       //initialize all array slots as empty
            }
    }
    
    //========================
    //     PUBLIC MEMBERS
    //======================== */
    
/*bool insert( int key, char value ) {
    
    bool retval;
                        
         int i=key%50;            //starting array index is key%50 (naive hash)
         int count = 0;           //Start with the count at 0 break if we hit 50
         
            while((kvpairs[i] != nullptr) && !(this->exists(kvpairs[i], key))) {
                (i<49)? i++: i=0;       //wrap around
                count++;                //increment count for every comparison
                if(count == 50) {
                   retval=false;        //we will return false;
                   break;               //If we've traversed every item and there's nowhere to insert
                }
            }
         
         if(this->exists(kvpairs[i], key)) {
             this->replaceValue(kvpairs[i], value );
             retval=true;
         }
         else if(kvpairs[i] == nullptr) {
             kvpairs[i] = new item(key, value);
             retval=true;
         }
         
    return retval;
}*/
    
// — if there is space available, adds the specified key/value-pair to the hash map and returns true; 
//otherwise returns false. If an item already exists in the map with the same key, replace its value.

/*bool remove( std::string key, int value) {
    
    return true;
}*/
//— if there is an item matching key, removes the key/value-pair from the map, stores it's value in value, 
//and returns true; otherwise returns false.

/*bool search( std::string key, int value ) {
    
    bool retval;
    
        if(this->exists(key)) {                     //If an item with the same key exists
            kvpairs[key%50]->value = value;         //access it and replace the value with this value
            retval = true;
        }
        else {
            retval=false;                           //otherwise, we're gonna return false;
        }
    
    return retval;
}*/

//— if there is an item matching key, stores it's value in value, and returns true (the item remains in the map);
//otherwise returns false.

/*void clear() {
    
    for(int i=0; i<50; i++) {
        if(kvpairs[i]!=nullptr) {
            delete kvpairs[i];
            kvpairs[i] = nullptr;
        }
    }
    
    return;
}*/

//— removes all items from the map.

/*bool is_empty() {
    
    bool retval;
    
        (size == 50)? retval=true: retval=false;
    
    return retval;
}*/
//— returns true IFF the map contains no elements.

/*std::size_t capacity() {
    return 50;
} */
//— returns the number of slots in the map.

/*std::size_t size() {
    return 27;
}*/
//— returns the number of items actually stored in the map.

/*double load() {
    return 27.7;
}*/
//— returns the map's load factor (size = load * capacity).

/*std::ostream& print( std::ostream& o ) {
    return o;
} */
//— inserts into the ostream, the backing array's contents in sequential order. 
//Empty slots shall be denoted by a hyphen, non-empty slots by that item's key. 
//[This function will be used for debugging/monitoring].
    
//};

//#endif	/* HASHMAP_OA_H */

