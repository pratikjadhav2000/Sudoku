 #include<iostream>
 #include<vector>
 #include "checker.h"
 using namespace std;

 //input your sudoku here

    int sudoku[9][9]=
 {
   0,0,0,0,0,0,6,0,9,
   1,0,0,0,0,4,0,0,0,
   0,0,5,3,0,6,8,2,1,
   0,0,4,6,7,0,0,5,0,
   0,0,7,0,0,0,9,0,0,
   0,0,0,5,4,0,0,0,0,
   3,7,0,4,0,5,2,0,6,
   0,0,0,0,0,0,5,1,0,
   0,6,0,0,2,0,0,3,7
 };

vector<int> get_possible_values( int row , int column ){

  vector<int> result;
  vector<int> possible_values_buffer(10);

  //row
  for (size_t j = 0; j < 9; j++) {

    if( sudoku[row][j] != 0 ){
          possible_values_buffer[ sudoku[row][j] ]= sudoku[row][j] ;
    }

  }
  //column
  for (size_t i = 0; i < 9; i++) {

    if( sudoku[i][column] != 0 ){
          possible_values_buffer[ sudoku[i][column] ]= sudoku[i][column] ;
    }

  }

  //calculate box number
  int box_no = row - ( row % 3 ) + ( column / 3 ) ;
  //starting row postion of the box
  int starting_row_box = row - ( row % 3 );
  //starting column postion of the box
  int starting_column_box = column - ( column % 3 );

  for (size_t i = starting_row_box ; i < starting_row_box + 3 ; i++) {
    for (size_t j = starting_column_box ; j < starting_column_box + 3 ; j++) {

      if( sudoku[i][j] != 0 ){
            possible_values_buffer[ sudoku[i][j] ]= sudoku[i][j] ;
      }

    }
  }

  //collect zero values and put into result
  for (size_t i = 1; i < 10; i++) {
        if( possible_values_buffer[i] == 0 )
        result.push_back(i);
  }

  return result;
}

int solve(){

  int return_flag=0;

  //stack to add the positions & possible_values of null/zero elements in the stack
  vector< vector<int> > possible_values(89);
  vector<int> positions;

  //add the empty positions from the sudoku in the stack
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
          if( sudoku[i][j] == 0 ){

            int position = ( i * 10 ) + j;
            positions.push_back( position );

          }
    }
  }

  for (size_t i = 0; i < positions.size() ; i++) {

        int row = positions[i] / 10;
        int column = positions[i] % 10;
        vector<int> values = get_possible_values( row , column);

        possible_values[ positions[i] ] = values;

        if( values.size() == 1 ){
          sudoku[ row ][ column ]= values[0];
          return_flag=1;
        }

  }

return return_flag;
}


 int main(){

std::cout << "                  Given Sudoku" << "\n \n \n";
  
    //sudoku input
   for (size_t i = 0; i < 9; i++) {
     std::cout << "" << '\n';
     for (size_t j = 0; j < 9; j++) {
       std::cout <<sudoku[i][j]<<"\t";

     }
   }
  
std::cout << "\n \n \n" << '\n';

// Solve the Sudoku
while( solve() ){}


std::cout << "                  Solved Sudoku" << "\n \n \n";
  
  //sudoku output
for (size_t i = 0; i < 9; i++) {
  std::cout << "" << '\n';
  for (size_t j = 0; j < 9; j++) {
    std::cout <<sudoku[i][j]<<"\t";

  }
}
  
std::cout << "\n \n \n" << '\n';


if( sudoku_checker( sudoku ) )
std::cout << "Sudoku check : Fail" << '\n';
else
std::cout << "Sudoku check : Ok!" << '\n';


   return 0;
 }

 /*
 Some examples to test as input 
 
 Perfect Sudoku :
 {
 4,3,5,2,6,9,7,8,1,
 6,8,2,5,7,1,4,9,3,
 1,9,7,8,3,4,5,6,2,
 8,2,6,1,9,5,3,4,7,
 3,7,4,6,8,2,9,1,5,
 9,5,1,7,4,3,6,2,8,
 5,1,9,3,2,6,8,7,4,
 2,4,8,9,5,7,1,3,6,
 7,6,3,4,1,8,2,5,9
 };

Puzzle Sudoku :
//moderate
{
5,8,0,6,7,0,1,0,0,
2,0,9,8,0,4,0,5,0,
0,1,0,0,5,0,6,2,8,
0,0,2,1,0,0,8,3,5,
8,3,0,0,2,5,0,0,1,
1,0,7,4,0,3,0,0,9,
0,0,0,7,4,1,3,8,0,
0,7,1,0,3,8,0,4,2,
3,4,8,0,0,0,5,0,0
};

{
  0,0,0,0,0,0,6,0,9,
  1,0,0,0,0,4,0,0,0,
  0,0,5,3,0,6,8,2,1,
  0,0,4,6,7,0,0,5,0,
  0,0,7,0,0,0,9,0,0,
  0,0,0,5,4,0,0,0,0,
  3,7,0,4,0,5,2,0,6,
  0,0,0,0,0,0,5,1,0,
  0,6,0,0,2,0,0,3,7
};

