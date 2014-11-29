/* 
 * File:   hashmap_oa.h
 * Author: Ben
 *
 * Created on November 17, 2014, 2:33 PM
 */

#ifndef HASHMAP_OA_H
#define	HASHMAP_OA_H

#include<iostream>


class hashmap_oa {
    
           //=======================
           // DATA MEMBERS / FIELDS
           //=======================
    
     struct item {
            int key;
            char value;

            item(int thisKey, char thisValue) : key(thisKey), value(thisValue) {} 
        };
        
    
        //=============================
        //FIELDS    FIELDS      FIELDS
        //=============================
    
    item** kvpairs;
    int numberOfItems;
    
    
            //===========================
            //  PRIVATE MEMBER FUNCTIONS
            //===========================
    
            bool exists(item* thisItem, int k) {
                bool retval = false;

                if(thisItem) {
                    if(thisItem->key == k) {     //If an item with the same key exists
                            retval = true;                                                      //return true
                     }
                }

                return retval;
            }
            
            
            item* getItem(int key) {
                int location = key%50;
                int original = location;
                
                while((kvpairs[location]) && (kvpairs[location]->key != key)) {
                    (location<49)? location++: location=0;
                    if(location == (original-1)) {
                        return nullptr;
                    }
                }
               
                return kvpairs[location];
            }
            
            
            void replaceValue(item* thisItem, char value ) {
                thisItem->value = value;
                return;
            }
            
            int primaryHash(int key) {
                return key%50;
            }
            
            int secondaryHash(int key) {
                return ((key%97)+1);
            }
            
            
            void reInsert(item** start) {        //This will linearly re-insert all items after the given start pointer.
                while((*start) != nullptr) {                  //While the examined slot is not empty.
                    item** temp = start;
                    int k = (*temp)->key;
                    char c = (*temp)->value;
                    delete *temp;
                    insert(k, c);
                    start++;
                }
                return;
            }
    
    
public:
    
    //=============================
    //  CONSTRUCTORS  CONSTRUCTORS
    //=============================
    
    hashmap_oa() {
        kvpairs = new item*[50];
        
            for(int i=0; i<50; i++) {
                kvpairs[i] = nullptr;       //initialize all array slots as empty
            }
    }
    
    ~hashmap_oa() {
        delete [] kvpairs;
    }
    
   /* operator=(const hashmap_oa& src) {
        int count = 50;
        while(count != 0) {
            
        }
    }*/
    
    //========================
    //   OTHER PUBLIC MEMBERS
    //======================== 
    
bool insert( int key, char value ) {
    
    bool retval=false;
                        
         int i=key%50;            //starting array index is key%50 (naive hash)
         int count = 0;           //Start with the count at 0 break if we hit 50
         
            while((kvpairs[i]) && !(this->exists(kvpairs[i], key))) {
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
            // numberOfItems++;         don't increment the size; something is being replaced
         }
         else if(kvpairs[i] == nullptr) {
             kvpairs[i] = new item(key, value);
             retval=true;
             numberOfItems++;
         }
         
    return retval;
}
    
// — if there is space available, adds the specified key/value-pair to the hash map and returns true; 
//otherwise returns false. If an item already exists in the map with the same key, replace its value.

bool remove( int key, char &value) {
    
    bool retval = false;
    item* i = getItem(key);
    item** re= &i; 
    re++;
    
    if(i) {
        value = i->value;
        delete i;
        numberOfItems--;
        retval = true;
        reInsert(re);
    }
    
    return retval;
}
//— if there is an item matching key, removes the key/value-pair from the map, stores it's value in value, 
//and returns true; otherwise returns false.

bool search( int key, char &value ) {
    
    bool retval=false;
    item* i = getItem(key);
    
    if(i) {
        value = i->value;
        retval = true;
    }
    
    return retval;
}

//— if there is an item matching key, stores it's value in value, and returns true (the item remains in the map);
//otherwise returns false.

void clear() {
    
    for(int i=0; i<50; i++) {
        if(kvpairs[i]) {
            delete kvpairs[i];
            kvpairs[i] = nullptr;
        }
    }
    numberOfItems=0;
    
    return;
}

//— removes all items from the map.

bool is_empty() {
    
    bool retval;
    
        (numberOfItems == 0)? retval=true: retval=false;
    
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
                o << "-";
            }
            else {
                o << kvpairs[i]->key;
            }
            o << ", ";
        }
    return o;
}
//— inserts into the ostream, the backing array's contents in sequential order. 
//Empty slots shall be denoted by a hyphen, non-empty slots by that item's key. 
//[This function will be used for debugging/monitoring].
    
};

#endif	/* HASHMAP_OA_H */

