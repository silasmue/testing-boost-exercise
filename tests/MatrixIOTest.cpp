#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <fstream>
#include <string>
#include "matrixIO.hpp"

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(TestCsvRead3x3)
{
  const std::string csvName = "test_3x3.csv";
  const int         dim     = 3;

  {
    std::ofstream csvFile(csvName);
    BOOST_REQUIRE(csvFile.is_open());
    csvFile << "1.0, 0.0, 0.0\n";
    csvFile << "0.0, 5.0, 0.0\n";
    csvFile << "0.0, 0.0, 9.0\n";
  }

  Eigen::MatrixXd loadedMatrix = matrixIO::openData(csvName, dim);

  BOOST_CHECK_EQUAL(loadedMatrix.rows(), dim);
  BOOST_CHECK_EQUAL(loadedMatrix.cols(), dim);

  BOOST_CHECK_EQUAL(loadedMatrix(0, 0), 1.0);
  BOOST_CHECK_EQUAL(loadedMatrix(1, 1), 5.0);
  BOOST_CHECK_EQUAL(loadedMatrix(2, 2), 9.0);

  std::remove(csvName.c_str());
}

BOOST_AUTO_TEST_SUITE_END()