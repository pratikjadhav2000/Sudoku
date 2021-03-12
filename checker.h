
#include<iostream>
#include<stack>
using namespace std;

//create a buffer for checking
int buffer_checker[10];
void buffer_checker_reset(){
  for (size_t i = 0; i < 10; i++) {
    buffer_checker[i]=0;
  }
}

  //check specific row
 int check_row( int row,int sudoku[9][9] ){

   buffer_checker_reset();
   for (size_t j = 0; j < 9; j++) {

      if( buffer_checker[ sudoku[row][j] ] != 0 ){
        std::cout << "same values at row"<<row<< '\n';
        return 1;
      }
      buffer_checker[ sudoku[row][j] ] = sudoku[row][j] ;
   }

return 0;
 }
  //check specific column
  int check_column( int column,int sudoku[9][9] ){

    buffer_checker_reset();
    for (size_t i = 0; i < 9; i++) {

       if( buffer_checker[ sudoku[i][column] ] != 0 ){
         std::cout << "same values at column"<<column<< '\n';
         return 1;
       }
       buffer_checker[ sudoku[i][column] ] = sudoku[i][column] ;
    }

 return 0;
  }
  //check specific box
  int check_box( int row,int column,int sudoku[9][9] ){
        int box_no = row - ( row % 3 ) + ( column / 3 ) ;

        //starting row postion of the box
        int starting_row = row - ( row % 3 );

        //starting column postion of the box
        int starting_column = column - ( column % 3 );

        buffer_checker_reset();
        for (size_t i = starting_row ; i < starting_row + 3 ; i++) {
          for (size_t j = starting_column ; j < starting_column + 3 ; j++) {

            if( buffer_checker[ sudoku[i][j] ] != 0 ){
              std::cout << "same values in box"<<box_no<< '\n';
              return 1;
            }
            buffer_checker[ sudoku[i][j] ] = sudoku[i][j] ;
          }
        }

  return 0;
  }

int sudoku_checker(  int sudoku[9][9]  ){

//check the input count
/*
int input_count=0;

for (size_t i = 0; i < 9; i++) {

 int flag=0;

 for (size_t j = 0; j < 9; j++) {
   if( input_count != 17 ){
     flag=1;
     std::cout << "Error : Input is not equal to 17" << '\n';
     break;
   }

   if( sudoku[i][j] > 0 && sudoku[i][j] < 10 )
   input_count++;
 }

 if( flag == 1)
 break;

}
*/

//std::cout << input_count << '\n';

//add the positions of null/zero elements in the stack
       /* todo */
int flag=0;

//check row elements

 for (size_t i = 0; i < 9; i++) {


   buffer_checker_reset();

   for (size_t j = 0; j < 9; j++) {

       if( buffer_checker[sudoku[i][j]] != 0 ){
         flag=1;
         break;
       }
       buffer_checker[sudoku[i][j]] = sudoku[i][j];

   }
   if( flag == 1 ){
     std::cout << "same values found in row "<<i<< '\n';
     return 0;
   }

 }


//check column elements

 flag=0;

 for (size_t j = 0; j < 9; j++) {


   buffer_checker_reset();

   for (size_t i = 0; i < 9; i++) {

       if( buffer_checker[sudoku[i][j]] != 0 ){
         flag=1;
         break;
       }
       buffer_checker[sudoku[i][j]] = sudoku[i][j];

   }
   if( flag == 1 ){
     std::cout << "same values found in column "<<j<< '\n';
     return 0;
   }

 }



//check box elements

 flag=0;

for (size_t i = 0; i < 3; i++) {



 for (size_t j = 0; j < 3; j++) {

   int box_no = (i*3)+j;
   buffer_checker_reset();

   for (size_t k = 0; k < 3; k++) {

     for (size_t l = 0; l < 3; l++) {

             int box_row = (i*3)+k ;
             int box_column = (j*3)+l ;

       if( buffer_checker[sudoku[box_row][box_column]] != 0 ){
         //std::cout << "row"<<box_row<<"column"<<box_column<< '\n';
         flag=1;
         break;
       }
       buffer_checker[sudoku[box_row][box_column]] = sudoku[box_row][box_column];

         //  std::cout << (i*3)+k <<"\t"<<(j*3)+l << '\n';
     }

     if( flag == 1 )
       break;

   }
   if( flag == 1 ){
     std::cout << "same values found in box "<< box_no << '\n';
     break;
   }

 }
 if( flag == 1 )
     return 0;

}


  return 1;
}
