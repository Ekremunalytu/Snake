#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {

  int matrix_raw,matrix_column,Food_number;

  printf("Enter the matrix size\n");
  scanf("%d  % d", &matrix_raw , &matrix_column);

  printf("Enter food number\n");
  scanf("%d" , &Food_number);
  printf("%d" , Food_number);
  
  int matrix_size = matrix_raw*matrix_column;
  //if(Food_number > matrix_size){
    //printf("Please enter a valid number!!!!!");
  //};

  int map [matrix_raw][matrix_column];
  for (int i = 0; i < matrix_raw ; i++){
    for (int j = 0; j < matrix_column ; j++){
      map[i][j] = 0;
    }
  }







  return 0;
};