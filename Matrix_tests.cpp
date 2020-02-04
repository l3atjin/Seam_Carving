// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(Matrix_init) {
  Matrix *mat = new Matrix;
  Matrix *mat1 = new Matrix;
  Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int width1 = MAX_MATRIX_WIDTH;
  const int height1 = MAX_MATRIX_HEIGHT;
  const int width2 = 1;
  const int height2 = 1;
  Matrix_init(mat, width, height);
  Matrix_init(mat1, width1, height1);
  Matrix_init(mat2, width2, height2);

  ASSERT_EQUAL(mat->height, height);
  ASSERT_EQUAL(mat->width, width);
  ASSERT_EQUAL(mat1->height, height1);
  ASSERT_EQUAL(mat1->width, width1);
  ASSERT_EQUAL(mat2->height, height2);
  ASSERT_EQUAL(mat2->width, width2);

  delete mat;
  delete mat2;
  delete mat1; // delete the Matrix
}

TEST(Matrix_print) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 5);
  Matrix_fill(mat, 10);
  ostringstream expected;
  expected << "5 5" << std::endl 
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl;
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());

  delete mat;
}

TEST(Matrix_width) {
  Matrix *mat = new Matrix;
  Matrix *mat1 = new Matrix;
  Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int width1 = MAX_MATRIX_WIDTH;
  const int height1 = MAX_MATRIX_HEIGHT;
  const int width2 = 1;
  const int height2 = 1;
  Matrix_init(mat, width, height);
  Matrix_init(mat1, width1, height1);
  Matrix_init(mat2, width2, height2);

  ASSERT_EQUAL(Matrix_width(mat), width);
  ASSERT_EQUAL(Matrix_width(mat1), width1);
  ASSERT_EQUAL(Matrix_width(mat2), width2);

  delete mat;
  delete mat2;
  delete mat1; // delete the Matrix
}

TEST(Matrix_height) {
  Matrix *mat = new Matrix;
  Matrix *mat1 = new Matrix;
  Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int width1 = MAX_MATRIX_WIDTH;
  const int height1 = MAX_MATRIX_HEIGHT;
  const int width2 = 1;
  const int height2 = 1;
  Matrix_init(mat, width, height);
  Matrix_init(mat1, width1, height1);
  Matrix_init(mat2, width2, height2);

  ASSERT_EQUAL(Matrix_height(mat), height);
  ASSERT_EQUAL(Matrix_height(mat1), height1);
  ASSERT_EQUAL(Matrix_height(mat2), height2);
  
  delete mat;
  delete mat2;
  delete mat1; // delete the Matrix
}

TEST(Matrix_at) {
  Matrix *mat = new Matrix;

  const int width = 5;
  const int height = 5;


  Matrix_init(mat, width, height);
  Matrix_fill(mat, 0);
  *Matrix_at(mat, 0, 0) = 5;
  *Matrix_at(mat, 0, 4) = 6;
  *Matrix_at(mat, 4, 0) = 7;
  *Matrix_at(mat, 4, 4) = 8;
  *Matrix_at(mat, 2, 2) = 9;
  *Matrix_at(mat, 3, Matrix_height(mat) - 1) = 10;

  ostringstream expected;
  expected << "5 5" << std::endl 
           << "5 0 0 0 6" << std::endl
           << "0 0 0 0 0" << std::endl
           << "0 0 9 0 0" << std::endl
           << "0 0 0 0 10" << std::endl
           << "7 0 0 0 8" << std::endl;
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());
  
  delete mat;
}

TEST(Matrix_row) {
  Matrix *mat = new Matrix;

  const int width = 5;
  const int height = 5;


  Matrix_init(mat, width, height);
  Matrix_fill(mat, 0);
  *Matrix_at(mat, 0, 0) = 5;
  *Matrix_at(mat, 0, 4) = 6;
  *Matrix_at(mat, 4, 0) = 7;
  *Matrix_at(mat, 4, 4) = 8;
  *Matrix_at(mat, 2, 2) = 9;
  *Matrix_at(mat, 3, Matrix_height(mat) - 1) = 10;

  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 0, 0)), 0);
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 0, 4)), 0);
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 4, 0)), 4);
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 4, 4)), 4);
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 2, 2)), 2);
  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 3, Matrix_height(mat) - 1)), 3);
  
  delete mat;
}

TEST(Matrix_column) {
  Matrix *mat = new Matrix;

  const int width = 5;
  const int height = 5;


  Matrix_init(mat, width, height);
  Matrix_fill(mat, 0);
  *Matrix_at(mat, 0, 0) = 5;
  *Matrix_at(mat, 0, 4) = 6;
  *Matrix_at(mat, 4, 0) = 7;
  *Matrix_at(mat, 4, 4) = 8;
  *Matrix_at(mat, 2, 2) = 9;
  *Matrix_at(mat, 3, Matrix_height(mat) - 1) = 10;

  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 0)), 0);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 4)), 4);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 4, 0)), 0);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 4, 4)), 4);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 2, 2)), 2);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 3, Matrix_height(mat) - 1)), Matrix_height(mat) - 1);
  
  delete mat;
}

TEST(Matrix_fill_border) {
  Matrix *mat = new Matrix;
  Matrix *mat1 = new Matrix;
  Matrix *mat2 = new Matrix;

  const int width = 5;
  const int height = 5;
  const int width1 = 1;
  const int height1 = 1;
  const int width2 = 3;
  const int height2 = 5;


  Matrix_init(mat, width, height);
  Matrix_init(mat1, width1, height1);
  Matrix_init(mat2, width2, height2);

  Matrix_fill(mat, 0);
  Matrix_fill(mat1, 0);
  Matrix_fill(mat2, 0);

  Matrix_fill_border(mat, 1);
  Matrix_fill_border(mat1, 1);
  Matrix_fill_border(mat2, 1);

  /*ostringstream expected1;
  expected1 << "5 5" << std::endl 
           << "1 1 1 1 1" << std::endl
           << "1 10 10 10 10" << std::endl
           << "1 10 10 10 10" << std::endl
           << "1 10 10 10 10" << std::endl
           << "1 1 1 1 1" << std::endl;
  ostringstream actual1;
  Matrix_print(mat, actual1);
  ASSERT_EQUAL(expected1.str(), actual1.str());*/

  /*ostringstream expected2;
  expected2 << "5 5" << std::endl 
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl;
  ostringstream actual2;
  Matrix_print(mat1, actual2);
  ASSERT_EQUAL(expected2.str(), actual2.str());*/

  ostringstream expected3;
  expected3 << "5 5" << std::endl 
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl
           << "10 10 10 10 10" << std::endl;
  ostringstream actual3;
  Matrix_print(mat2, actual3);
  ASSERT_EQUAL(expected3.str(), actual3.str());
  
  delete mat;
  delete mat1;
  delete mat2;
}

TEST(Matrix_column) {
  Matrix *mat = new Matrix;

  const int width = 5;
  const int height = 5;


  Matrix_init(mat, width, height);
  Matrix_fill(mat, 0);
  *Matrix_at(mat, 0, 0) = 5;
  *Matrix_at(mat, 0, 4) = 6;
  *Matrix_at(mat, 4, 0) = 7;
  *Matrix_at(mat, 4, 4) = 8;
  *Matrix_at(mat, 2, 2) = 9;
  *Matrix_at(mat, 3, Matrix_height(mat) - 1) = 10;

  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 0)), 0);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 4)), 4);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 4, 0)), 0);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 4, 4)), 4);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 2, 2)), 2);
  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 3, Matrix_height(mat) - 1)), Matrix_height(mat) - 1);
  
  delete mat;



// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.



// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
