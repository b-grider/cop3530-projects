/* 
 * File:   multi_hashmap.h
 * Author: Ben
 *
 * Created on November 30, 2014, 2:36 PM
 */

#ifndef MULTI_HASHMAP_H
#define	MULTI_HASHMAP_H

namespace cop3530 {

template<typename KEY, typename VALUE, 
          typename HASH_FUNC, HASH_FUNC hash, 
          bool double_hash, typename PROBE_FUNC, PROBE_FUNC probe,
          bool op_equals = true, typename EQ_FUNC = bool, EQ_FUNC eq_test = false>
class multi_hash {
    
    
    
};

}

#endif	/* MULTI_HASHMAP_H */

