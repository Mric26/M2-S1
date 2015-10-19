#define BOOST_TEST_MODULE MyTest

#include <iostream>
#include <Eigen>
#include <boost>

using namespace Eigen;
using namespace std;
using namespace boost::numeric::ublas;

BOOST_AUTO_TEST_CASE(testTime) {
	
	boost::posix_time::ptime t1 = boost::posix_time::second_clock::local_time();
    boost::this_thread::sleep(boost::posix_time::millisec(500));
    boost::posix_time::ptime t2 = boost::posix_time::second_clock::local_time();
    boost::posix_time::time_duration diff = t2 - t1;
    
}

BOOST_AUTO_TEST_CASE(testEigenMatriceVector) {
	MatrixXd m(3,3);
	m(0,0) = 1;
	m(0,1) = 1;
	m(0,2) = 1;
	m(1,0) = 1;
	m(1,1) = 1;
	m(1,2) = 1;
	m(2,0) = 1;
	m(2,1) = 1;
	m(2,2) = 1;
	
	VectorXd v(3);
	v << 1, 2, 3;
	
	mult = m * v;
	
	VectorXd s(3);
	s << 6, 6, 6;
	
	for( int c = 0; c<4; c++){
		BOOST_CHECK_EQUAL(mult(c), s(c));
	}
	
}

BOOST_AUTO_TEST_CASE(testEigenMatriceMatrice) {
	MatrixXd m1(3,3);
	m1(0,0) = 1;
	m1(0,1) = 1;
	m1(0,2) = 1;
	m1(1,0) = 1;
	m1(1,1) = 5;
	m1(1,2) = 1;
	m1(2,0) = 1;
	m1(2,1) = 1;
	m1(2,2) = 1;
	
	MatrixXd m2(3,3);
	m2(0,0) = 2;
	m2(0,1) = 2;
	m2(0,2) = 2;
	m2(1,0) = 2;
	m2(1,1) = 0;
	m2(1,2) = 2;
	m2(2,0) = 2;
	m2(2,1) = 2;
	m2(2,2) = 2;
	
	mutl = m1 * m2;
	
	MatrixXd res(3,3);
	res(0,0) = 6;
	res(0,1) = 4;
	res(0,2) = 6;
	res(1,0) = 14;
	res(1,1) = 4;
	res(1,2) = 14;
	res(2,0) = 6;
	res(2,1) = 4;
	res(2,2) = 6;
	
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			BOOST_CHECK_EQUAL(mult(i,j), res(i,j));
		}
	}
}
	
BOOST_AUTO_TEST_CASE(testTime) {
	MatrixXd m1(3,3);
	m1(0,0) = 1;
	m1(0,1) = 1;
	m1(0,2) = 1;
	m1(1,0) = 1;
	m1(1,1) = 1;
	m1(1,2) = 1;
	m1(2,0) = 1;
	m1(2,1) = 1;
	m1(2,2) = 1;
	
	MatrixXd m2(3,3);
	m2(0,0) = 2;
	m2(0,1) = 2;
	m2(0,2) = 2;
	m2(1,0) = 2;
	m2(1,1) = 2;
	m2(1,2) = 2;
	m2(2,0) = 2;
	m2(2,1) = 2;
	m2(2,2) = 2;
	
	boost::posix_time::ptime t1 = boost::posix_time::second_clock::local_time();
    MatrixXd mutl = m1 * m2;
    boost::posix_time::ptime t2 = boost::posix_time::second_clock::local_time();
    boost::posix_time::ptime eigentime = t2 - t1;
    
    matrix<double> m1(3, 3);
    for (unsigned i = 0; i < m1.size1(); ++ i){
        for (unsigned j = 0; j < m1.size2(); ++ j){
            m1(i, j) = 1;
        }
	}
            
    matrix<double> m2(3, 3);
    for (unsigned i = 0; i < m2.size1(); ++ i){
        for (unsigned j = 0; j < m2.size2(); ++ j){
            m2(i, j) = 2;
		}
	}
	
	matrix<double> res(3, 3);
	boost::posix_time::ptime t3 = boost::posix_time::second_clock::local_time();
    axpy_prod(m1, m2, res, true);
    boost::posix_time::ptime t4 = boost::posix_time::second_clock::local_time();
    boost::posix_time::ptime boosttime = t4 - t3;
    
	
}
