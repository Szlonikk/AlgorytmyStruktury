#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/included/unit_test.hpp>
using namespace boost;
int dodaj( int i, int j )
{
    return i + j;
}

BOOST_AUTO_TEST_CASE( testDodaj )
{
    BOOST_CHECK( dodaj( 2, 2 ) == 4 );
}
