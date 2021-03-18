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

        //calculate box number
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

  //check the specific postion
   int check_position( int i,int j,int sudoku[9][9] ){

          if ( check_row( i, sudoku ) )
          return 1;
          if ( check_column( j,sudoku ) )
          return 1;
          if ( check_box( i,j,sudoku ) )
          return 1;

     return 0;
   }

   //check full sudoku
int sudoku_checker(  int sudoku[9][9]  ){

//check rows
 for (size_t i = 0; i < 9; i++)
   if( check_row(i,sudoku) )
     return 1;

//check columns
 for (size_t j = 0; j < 9; j++)
   if( check_column(j,sudoku) )
     return 1;

//check boxes
for (size_t i = 0; i < 3; i++)
 for (size_t j = 0; j < 3; j++)
      if( check_box( i*3, j*3, sudoku ) )
          return 1;

  return 0;
}
