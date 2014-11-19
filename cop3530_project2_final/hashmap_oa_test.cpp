
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "hashmap_oa.h"


static hashmap_oa map1;

TEST_CASE( "Testing the push_back function and verifying with item_at function (SSLL)", "[insert(), size()]" ) {

    bool ins1 = map1.insert(3,'c');
    bool ins2 = map1.insert(3,'a');
    bool ins3 = map1.insert(3,'b');
    bool ins4 = map1.insert(3,'d');
    
        REQUIRE( ins1 );
        REQUIRE( ins2 );
        REQUIRE( ins3 );
        REQUIRE( ins4 );
        
        REQUIRE( map1.size() == 1); 
}

TEST_CASE("doing a test print, clearing, testing size, then printing again", "[clear(), print(), size(), ]") {
   
    
    map1.print(std::cout);
    map1.clear();
    
    REQUIRE(map1.size() == 0);
}

TEST_CASE("", "[]") {
    
}