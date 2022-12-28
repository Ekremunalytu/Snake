#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define UP "U"
#define DOWN "D"
#define LEFT "L"
#define RIGHT "R"



int main() {
  // temel değişkenler tanımlanıyor 
  int matrix_raw,matrix_column,Food_number;
  int snake = 2;
  int in_game = 1;

  printf("Enter the matrix size\n");
  scanf("%d  %d", &matrix_raw , &matrix_column);
  
  printf("Enter food number\n");
  scanf("%d" , &Food_number);
  
  int matrix_size = matrix_raw*matrix_column;
  if(Food_number > matrix_size){
    printf("Please enter a valid number!!!!!");
  };

  int map [matrix_raw][matrix_column];
  for (int i = 0; i < matrix_raw ; i++){
    for (int j = 0; j < matrix_column ; j++){
      map[i][j] = '_';
    }
  }
 
  int X_Coordinate, Y_Coordinate;
  int Snake_Size_Array[Food_number + 1];
  for (int i = 0 ; i < Food_number  + 2 ; i++){
    X_Coordinate = rand() % matrix_raw  + 1;
    Y_Coordinate = rand() % matrix_column + 1;
    map[X_Coordinate][Y_Coordinate] = 1; 
  }

  
  for (int i = 0; i < matrix_raw ; i++){
    for (int j = 0; j < matrix_column ; j++){
      if(map[i][j] != 1 )
        printf("%c" , map[i][j]);
      else
        printf("%d" , map[X_Coordinate][Y_Coordinate]);
    }
    printf("\n");
  }
  












  return 0;
};