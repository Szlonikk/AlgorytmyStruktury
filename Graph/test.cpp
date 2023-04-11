#define BOOST_TEST_MODULE GraphTest
#define BOOST_TEST_DYN_LINK
    
#include <boost/test/unit_test.hpp>
#include "Graph.hpp"

BOOST_AUTO_TEST_SUITE (GraphTestSuite)

BOOST_AUTO_TEST_CASE (HasEdgeTest) {

    Graph gr;
    
    gr.addEdge(1,2);
    gr.addEdge(1,3);
    gr.addEdge(3,5);
    gr.addEdge(5,1);
    gr.addEdge(5,2);
    gr.addEdge(18,23);
    gr.addEdge(23,3);

    BOOST_CHECK_EQUAL(gr.hasEdge(1,2), true);
    BOOST_CHECK_EQUAL(gr.hasEdge(1,3), true);
    BOOST_CHECK_EQUAL(gr.hasEdge(1,5), false);
    BOOST_CHECK_EQUAL(gr.hasEdge(5,4), false);
    BOOST_CHECK_EQUAL(gr.hasEdge(5,2), true);
    BOOST_CHECK_EQUAL(gr.hasEdge(4,7), false);
    BOOST_CHECK_EQUAL(gr.hasEdge(7,8), false);
    BOOST_CHECK_EQUAL(gr.hasEdge(18,23), true);
    BOOST_CHECK_EQUAL(gr.hasEdge(23,3), true);
    BOOST_CHECK_EQUAL(gr.hasEdge(18,3), false);
    
}

BOOST_AUTO_TEST_CASE (TestReturnSet) {
    Graph gr;
    gr.addEdge(1,2);
    gr.addEdge(1,3);
    gr.addEdge(3,5);
    gr.addEdge(5,1);
    gr.addEdge(5,2);
    gr.addEdge(18,23);
    gr.addEdge(23,3);
    Set<int> s1=gr.outConnections(5);
    BOOST_CHECK_EQUAL(s1.isMember(1),true);
    BOOST_CHECK_EQUAL(s1.isMember(2),true);
    BOOST_CHECK_EQUAL(s1.isMember(3),false);

    Set<int> s2=gr.inConnections(3); 
    BOOST_CHECK_EQUAL(s2.isMember(23),true);
    BOOST_CHECK_EQUAL(s2.isMember(1),true);
    BOOST_CHECK_EQUAL(s2.isMember(18),false);

    Set<int> s3=gr.allConnections(3);
    BOOST_CHECK_EQUAL(s3.isMember(23),true);
    BOOST_CHECK_EQUAL(s3.isMember(1),true);
    BOOST_CHECK_EQUAL(s3.isMember(5),true);
    BOOST_CHECK_EQUAL(s3.isMember(18),false);
    BOOST_CHECK_EQUAL(s3.isMember(4),false);
    
}
BOOST_AUTO_TEST_CASE(BFSTest) {
    Graph gr;
    gr.addEdge(0, 1);
    gr.addEdge(0, 2);
    gr.addEdge(1, 2);
    gr.addEdge(2, 3);
    gr.addEdge(3, 4);

    int distances[5];
    BFS(gr, 0, distances);

    BOOST_CHECK_EQUAL(distances[0], 0);
    BOOST_CHECK_EQUAL(distances[1], 1);
    BOOST_CHECK_EQUAL(distances[2], 1);
    BOOST_CHECK_EQUAL(distances[3], 2);
    BOOST_CHECK_EQUAL(distances[4], 3);
}


BOOST_AUTO_TEST_SUITE_END()
