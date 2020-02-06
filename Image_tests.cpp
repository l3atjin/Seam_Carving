// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(Image_init) {
    Image* img = new Image;
    Image* img1 = new Image;
    //Image* img2 = new Image;
    //string filename = "horses.ppm";
    //stringstream is;

    
    int width = MAX_MATRIX_WIDTH;
    int height = MAX_MATRIX_HEIGHT;
    int width1 = 1;
    int height1 = 1;

    Image_init(img, width, height);
    Image_init(img1, width1, height1);
    ASSERT_EQUAL(Image_height(img), height);
    ASSERT_EQUAL(Image_width(img), width);
    ASSERT_EQUAL(Image_height(img1), height1);
    ASSERT_EQUAL(Image_width(img1), width1);
    
    //Image_init(img2, filename)
   


}

TEST(Image_get_pixel) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  ASSERT_EQUAL(Image_get_pixel(img, 0, 0).r, 255);
  ASSERT_EQUAL(Image_get_pixel(img, 0, 1).g, 255);
  ASSERT_EQUAL(Image_get_pixel(img, 1, 0).b, 255);
  ASSERT_EQUAL(Image_get_pixel(img, 1, 1).r, 255);
  delete img; // delete the Image
}

TEST(Image_width) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};

  Image_init(img, 5, 10);
  Image_fill(img, red);

  ASSERT_EQUAL(Image_width(img), 5);
  ASSERT_EQUAL(Image_height(img), 10);

  delete img; // delete the Image
}

TEST(Image_height) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};

  Image_init(img, 5, 10);
  Image_fill(img, red);

  ASSERT_EQUAL(Image_height(img), 10);

  delete img; // delete the Image
}

TEST(Image_fill) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};

  Image_init(img, 2, 2);
  Image_fill(img, red);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 255 0 0 \n";
  correct << "255 0 0 255 0 0 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(Image_print) {
  Image *img = new Image; // create an Image in dynamic memory

  /*const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};*/
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 3);
  Image_fill(img, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 3\n255\n";
  correct << "255 255 255 255 255 255 \n";
  correct << "255 255 255 255 255 255 \n";
  correct << "255 255 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}


TEST(Image_set_pixel) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel white = {255, 255, 255};
  const Pixel pixel1 = {0, 0, 0};

  Image_init(img, 3, 5);
  Image_fill(img, white);

  Image_set_pixel(img, 0, 0, pixel1);
  Image_set_pixel(img, 0, 2, pixel1);
  Image_set_pixel(img, 4, 0, pixel1);
  Image_set_pixel(img, 4, 2, pixel1);
  Image_set_pixel(img, 1, 1, pixel1);
  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n3 5\n255\n";
  correct << "0 0 0 255 255 255 0 0 0 \n";
  correct << "255 255 255 0 0 0 255 255 255 \n";
  correct << "255 255 255 255 255 255 255 255 255 \n";
  correct << "255 255 255 255 255 255 255 255 255 \n";
  correct << "0 0 0 255 255 255 0 0 0 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
