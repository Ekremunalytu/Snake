#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define UP 'U'
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'



int main() {
  // temel değişkenler tanımlanıyor 
  int Matrix_Raw,Matrix_Column,Food_Number;
  int snake = 1;
  int in_game = 1;

  printf("Enter the matrix size\n");
  scanf("%d  %d", &Matrix_Raw , &Matrix_Column);
  
  printf("Enter food number\n");
  scanf("%d" , &Food_Number);

  int Snake_Size[Food_Number];
  Snake_Size[0] = 1;
  for(int i = 1 ; i < Food_Number ; i++){
    Snake_Size[i] = -1;
  }
  
  int Matrix_Size = Matrix_Raw*Matrix_Column;
  if(Food_Number > Matrix_Size){
    printf("Please enter a valid number!!!!!");
  };

  int map [Matrix_Raw][Matrix_Column];
  for (int i = 0; i < Matrix_Raw ; i++){
    for (int j = 0; j < Matrix_Column ; j++){
      map[i][j] = -1 ;
    }
  }
 
  srand(time(0));
  for (int i = 0 ; i < Food_Number ; i++){
    int X_Coordinate,Y_Coordinate;
    do{
    X_Coordinate = rand() % Matrix_Raw;
    Y_Coordinate = rand() % Matrix_Column;
    } while (map[X_Coordinate][Y_Coordinate] != -1);
    map[X_Coordinate][Y_Coordinate] = '0'; 
  }


  int Snake_X_Coordinate = rand() % Matrix_Raw;
  int Snake_Y_Coordinate = rand() % Matrix_Column;
  map[Snake_X_Coordinate][Snake_Y_Coordinate] = 1;
  //printf("%d %d \n" , Snake_X_Coordinate , Snate_Y_Coordinate); doğru kordinat atanıyor mu diye kontrol ediyorum
  printf("\n Beggining of the game");
  for (int i = 0; i < Matrix_Raw ; i++){
    for (int j = 0; j < Matrix_Column ; j++){
     if(map[i][j] != 1 )
       printf("%c" , map[i][j]);
     else 
      printf("%d" , map[Snake_X_Coordinate][Snake_Y_Coordinate]);
    }
  printf("\n");
  }
  int Move_Count = 0;
  
  int Food_Eaten = 0;

  int Food_Number_Backup = Food_Number;
  
  int Length_Controller = 1;
 
  while(in_game){
    
    printf("\nEnter your movement\n");
    
    printf("\nU for up D for Down L for left and R for right:  ");
    printf("\nIf you want to quit press Q\n");
    char Move;
    scanf("%c" , &Move);

    if(Move == UP){
      if(map[Snake_X_Coordinate-1][Snake_Y_Coordinate] == '0')
        Food_Number--;
      map[Snake_X_Coordinate][Snake_Y_Coordinate] = -1;
      Snake_X_Coordinate--;
      map[Snake_X_Coordinate][Snake_Y_Coordinate] = 1;
    }else if(Move == DOWN){
      if(map[Snake_X_Coordinate+1][Snake_Y_Coordinate] == '0')
        Food_Number--;
      map[Snake_X_Coordinate][Snake_Y_Coordinate] = -1;
      Snake_X_Coordinate++;
      map[Snake_X_Coordinate][Snake_Y_Coordinate] = 1;
    }else if(Move == LEFT){
      if(map[Snake_X_Coordinate][Snake_Y_Coordinate-1] == '0')
        Food_Number--;
      map[Snake_X_Coordinate][Snake_Y_Coordinate] = -1;
      Snake_Y_Coordinate--;
      map[Snake_X_Coordinate][Snake_Y_Coordinate] = 1;
    }else if(Move == RIGHT){
      if(map[Snake_X_Coordinate][Snake_Y_Coordinate+1] == '0')
        Food_Number--;
      map[Snake_X_Coordinate][Snake_Y_Coordinate] = -1;
      Snake_Y_Coordinate++;
      map[Snake_X_Coordinate][Snake_Y_Coordinate] = 1;

    }

    Move_Count = Move_Count + 1;
    

    for (int i = 0; i < Matrix_Raw ; i++){
      for (int j = 0; j < Matrix_Column ; j++){
        if(map[i][j] == 0 ){
          printf("%d" , map[i][j]);
        }
        else if(map[i][j] == 1)
          printf("%d" , map[i][j]);
       else
          printf("%c" , map[i][j]);
      }
      printf("\n");
    }  
    
    


   
    printf("Snake Coordinates: %d %d", Snake_X_Coordinate, Snake_Y_Coordinate);
    printf("\nMove_count:  %d", Move_Count);
    //printf("\nFood Eaten: %d" , Food_Eaten);
    printf("\nFood left: %d", Food_Number);
    if(Snake_X_Coordinate < 0 || Snake_X_Coordinate > Matrix_Raw ){
      printf("\nGame over\n");
      printf("\nYour score is:  %d\n", Food_Eaten);
      printf("Your movement count is %d" , Move_Count);
      in_game = 0;
    }
    
    if( Snake_Y_Coordinate < 0 || Snake_Y_Coordinate > Matrix_Column ){
      printf("\nGame over\n");
      printf("\nYour score is:  %d\n", Food_Eaten);
      printf("Your movement count is %d" , Move_Count);
      in_game = 0;
    }
    
    if(Food_Number == 0){
      printf("You won!!!");
      in_game = 0;
    }



     
  }











 
  


  
}