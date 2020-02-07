// Project UID af1f95f547e44c8ea88730dfb185559ds

#include <cassert>
#include "Matrix.h"
#include <iostream>

//using namespace std;


// REQUIRES: mat points to a Matrix
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Matrix_init(Matrix* mat, int width, int height) {
  //assert(0 < width && width <= MAX_MATRIX_WIDTH);
  //assert(0 < height && height <= MAX_MATRIX_HEIGHT);
  // Make a temporary matrix
  mat->width = width;
  mat->height = height;
   // TODO Replace with your implementation!
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix* mat, std::ostream& os) {
  // Figure out endl
  os <<  mat->width << " " << mat->height << std::endl;
   // TODO Replace with your implementation!
  for (int row = 0; row < mat->height; row++)
  {
    for (int col = 0; col < mat->width; col++)
    {
      os << *Matrix_at(mat, row, col) << " ";
    }
    os << std::endl;
  }
  
}

// REQUIRES: mat points to an valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix* mat) {
// TODO Replace with your implementation!
  return mat->width;
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix* mat) {
  return mat->height;
}

// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix* mat, const int* ptr) {
  const int* first_ptr = &mat->data[0];
  int index = ptr - first_ptr;
  int width = Matrix_width(mat);
  return index/width;
}

// REQUIRES: mat points to a valid Matrix
//           ptr point to an element in the Matrix
// EFFECTS:  Returns the column of the element pointed to by ptr.
int Matrix_column(const Matrix* mat, const int* ptr) {
  const int* first_ptr = &mat->data[0];
  int index = ptr - first_ptr;
  if(index < Matrix_width(mat))
  {
    return index;
  }
  return index%mat->width;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int* Matrix_at(Matrix* mat, int row, int column) {
  //assert(0 <= row && row < Matrix_height(mat));
  //assert(0 <= column && column < Matrix_width(mat)); 

  //get index
  int index = Matrix_width(mat) * row + column;

  //return the pointer
  return &mat->data[index];
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int* Matrix_at(const Matrix* mat, int row, int column) {
  //assert(0 <= row);
  //assert(0 <= column); // TODO Replace with your implementation!

  //get index
  int index = Matrix_width(mat) * row + column;

  //return the pointer
  return &mat->data[index];
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix* mat, int value) {
  // TODO Replace with your implementation!
  for (int row = 0; row < Matrix_height(mat); row++)
  {
    for (int col = 0; col < Matrix_width(mat); col++)
    {
      *Matrix_at(mat, row, col) = value;
    }
  }
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix* mat, int value) {
  for (int col = 0; col < Matrix_width(mat); col++)
  {
    *Matrix_at(mat, 0, col) = value;
    *Matrix_at(mat, Matrix_height(mat) - 1, col) = value;
  }
  for (int row = 0; row < Matrix_height(mat); row++)
  {
    *Matrix_at(mat, row, 0) = value;
    *Matrix_at(mat, row, Matrix_width(mat) - 1) = value;
  }
  
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix* mat) {
  int maxNum = *Matrix_at(mat, 0, 0);

  for (int row = 0; row < Matrix_height(mat); row++)
  {
    for (int col = 0; col < Matrix_width(mat); col++)
    {
      if(*Matrix_at(mat, row, col) > maxNum)
      {
        maxNum = *Matrix_at(mat, row, col);
      }
    }
  }
  return maxNum;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The region is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix* mat, int row,
                                      int column_start, int column_end) 
{
  int currentMin = *Matrix_at(mat, row, column_start);
  int currentCol = column_start;

  for (int col = column_start; col < column_end; col++)
  {
    if(*Matrix_at(mat, row, col) < currentMin)
    {
      currentCol = col;
      currentMin = *Matrix_at(mat, row, col);
    }
  }
  return currentCol;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix* mat, int row,
                            int column_start, int column_end) {
  int currentMin = *Matrix_at(mat, row, column_start);
  for (int col = column_start; col < column_end; col++)
  {
    if(*Matrix_at(mat, row, col) < currentMin)
    {
      currentMin = *Matrix_at(mat, row, col);
    }
  }
  return currentMin;
}
