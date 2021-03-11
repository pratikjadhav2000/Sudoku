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

 int main(){

//input your sudoku here

/*
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

*/

   int sudoku[9][9]=
{
4,3,5,2,6,9,7,8,1,
6,8,2,5,7,1,4,9,3,
1,9,7,8,3,4,5,6,2,
8,2,6,1,9,5,3,4,7,
3,7,4,6,8,2,9,1,5,
9,5,1,7,4,3,6,2,8,
5,1,9,3,2,6,8,7,4,
2,4,8,9,5,7,1,0,6,
7,6,3,4,1,8,2,5,9
};

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


//check row elements

  for (size_t i = 0; i < 9; i++) {

    int flag=0;
    buffer_checker_reset();

    for (size_t j = 0; j < 9; j++) {

        if( buffer_checker[sudoku[i][j]] != 0 ){
          flag=1;
          break;
        }
        buffer_checker[sudoku[i][j]] = sudoku[i][j];

    }
    if( flag==1 ){
      std::cout << "same values found in row "<<i<< '\n';
      break;
    }

  }



//check column elements



  for (size_t j = 0; j < 9; j++) {

    int flag=0;
    buffer_checker_reset();

    for (size_t i = 0; i < 9; i++) {

        if( buffer_checker[sudoku[i][j]] != 0 ){
          flag=1;
          break;
        }
        buffer_checker[sudoku[i][j]] = sudoku[i][j];

    }
    if( flag==1 ){
      std::cout << "same values found in column "<<j<< '\n';
      break;
    }

  }



//check box elements

for (size_t i = 0; i < 3; i++) {
  int flag=0;


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
  if( flag==1 )
      break;

}




   return 0;
 }
