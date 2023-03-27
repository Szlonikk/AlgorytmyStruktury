#define BOOST_TEST_MODULE PriorityQueueTest
#define BOOST_TEST_DYN_LINK
    
#include <boost/test/unit_test.hpp>
#include "PriorityQueue.hpp"

BOOST_AUTO_TEST_SUITE (PriorityQueueTestSuite)

BOOST_AUTO_TEST_CASE (TestInsertExtractMax) {

    PriorityQueue<int> pq;
    
    pq.insert(1, 1);
    pq.insert(2, 2);
    pq.insert(3, 3);
    pq.insert(4, 4);
    pq.insert(5, 5);
    
    BOOST_CHECK_EQUAL(pq.size(), 5);
    
    PriorityQueue<int>::QueueElement max = pq.ExtractMax();
    BOOST_CHECK_EQUAL(max.GetObj(), 5);
    BOOST_CHECK_EQUAL(max.GetPrio(), 5);
    BOOST_CHECK_EQUAL(pq.size(), 4);
    
    max = pq.ExtractMax();
    BOOST_CHECK_EQUAL(max.GetObj(), 4);
    BOOST_CHECK_EQUAL(max.GetPrio(), 4);
    BOOST_CHECK_EQUAL(pq.size(), 3);
    
    max = pq.ExtractMax();
    BOOST_CHECK_EQUAL(max.GetObj(), 3);
    BOOST_CHECK_EQUAL(max.GetPrio(), 3);
    BOOST_CHECK_EQUAL(pq.size(), 2);
    
    max = pq.ExtractMax();
    BOOST_CHECK_EQUAL(max.GetObj(), 2);
    BOOST_CHECK_EQUAL(max.GetPrio(), 2);
    BOOST_CHECK_EQUAL(pq.size(), 1);
    
    max = pq.ExtractMax();
    BOOST_CHECK_EQUAL(max.GetObj(), 1);
    BOOST_CHECK_EQUAL(max.GetPrio(), 1);
    BOOST_CHECK_EQUAL(pq.size(), 0);
    
    BOOST_CHECK_THROW(pq.ExtractMax(), std::out_of_range);
}

BOOST_AUTO_TEST_CASE (TestIncreaseKey) {

    PriorityQueue<int> pq;
    
    pq.insert(1, 1);
    pq.insert(2, 2);
    pq.insert(3, 3);
    pq.insert(4, 4);
    pq.insert(5, 5);
    
    BOOST_CHECK_EQUAL(pq.size(), 5);
    
    pq.increaseKey(3, 10);
    PriorityQueue<int>::QueueElement max = pq.ExtractMax();
    BOOST_CHECK_EQUAL(max.GetObj(), 1);
    BOOST_CHECK_EQUAL(max.GetPrio(), 10);
    BOOST_CHECK_EQUAL(pq.size(), 4);
    
    pq.increaseKey(0, 7);
    max = pq.ExtractMax();
    BOOST_CHECK_EQUAL(max.GetObj(), 5);
    BOOST_CHECK_EQUAL(max.GetPrio(), 7);
    BOOST_CHECK_EQUAL(pq.size(), 3);
    
    pq.increaseKey(1, 12);
    max = pq.ExtractMax();
    BOOST_CHECK_EQUAL(max.GetObj(), 3);
    BOOST_CHECK_EQUAL(max.GetPrio(), 12);
    BOOST_CHECK_EQUAL(pq.size(), 2);
    
    pq.increaseKey(1, 8);
    max = pq.ExtractMax();
    BOOST_CHECK_EQUAL(max.GetObj(), 2);
    BOOST_CHECK_EQUAL(max.GetPrio(), 8);
    BOOST_CHECK_EQUAL(pq.size(), 1);
    
    pq.increaseKey(0, 15);
    max = pq.ExtractMax();
    BOOST_CHECK_EQUAL(max.GetObj(), 4);
    BOOST_CHECK_EQUAL(max.GetPrio(), 15);
    BOOST_CHECK_EQUAL(pq.size(), 0);
    
    BOOST_CHECK_THROW(pq.increaseKey(0, 11), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()
