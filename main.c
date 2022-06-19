#include <stdio.h>
#include <stdlib.h>

#define PLAYER_CHOOSE \
  printf("$:Do you want 'x' or 'o' ? ");

#define BORDER "*-----------*"

#define SEPARATOR \
  printf("|-----------|\n");

void BOARD_PLAY(char *board){
  printf("%s\n",BORDER    );
  printf("| %c | %c | %c |\n",board[0],board[1],board[2]);
  SEPARATOR
  printf("| %c | %c | %c |\n",board[3],board[4],board[5]);
  SEPARATOR
  printf("| %c | %c | %c |\n",board[6],board[7],board[8]);  
  printf("%s\n",BORDER    );
}

void HANDLE_P(char* PLAYER_1,char* PLAYER_2,int *id){
  printf("%s\n",BORDER);
  printf("   PLAYER %d\n",*id);
  printf("%s\n",BORDER);
  PLAYER_CHOOSE
  char INTENT='-';
  while(1){
    scanf("%c",&INTENT);
    if(INTENT == 'o' || INTENT == 'x'){
      *PLAYER_1=*&INTENT;
      if(*PLAYER_1 == 'x'){
        *PLAYER_2='o';
      }else{
        *PLAYER_2='x';
      }
      break;
    }
  }
}
void CONSTRUCT_BOARD(char *board){
  for(int i=0;i<=9;i++){
    board[i]='-';
  }
}
int MALLOC_CONTAINS(int *Malloc,int *n,unsigned int *k){
  for(int i=0;i<*n;i++){
    if(Malloc[i] == *k){
      break;
      return 0;
    }
  }
  return 1;
}
int main(void){

  char PLAYER_1='-',PLAYER_2='-';
  unsigned int B_POSITION_A,B_POSITION_B;
  int GAME_BOARD_SIZE=9;
  char* GAME_BOARD =(char*)malloc(*&GAME_BOARD_SIZE*sizeof(char));
  static unsigned int INDEX_POS=0;
  int * POSITION=(int*)malloc(8*sizeof(int));
  
  for(int i=0;i<9;i++){
      POSITION[i]=-1;
  }
  
  CONSTRUCT_BOARD(GAME_BOARD);
  int id_a=1,id_b=2;
  HANDLE_P(&PLAYER_1,&PLAYER_2,&id_a);
  printf("$:PLAYER 1 '%c' PLAYER 2 '%c'\n",*&PLAYER_1,*&PLAYER_2);
  printf("\n");
  BOARD_PLAY(GAME_BOARD);
  
  while(1==1){
    
    printf("$:PLAYER 1 position ? ");
    scanf("%u",&B_POSITION_A);
    if(B_POSITION_A >=0 && B_POSITION_A <9){
      
      if(MALLOC_CONTAINS(POSITION,&GAME_BOARD_SIZE,&B_POSITION_A) == 1){
        GAME_BOARD[B_POSITION_A]=PLAYER_1;
        POSITION[INDEX_POS]=B_POSITION_A;
        BOARD_PLAY(GAME_BOARD);
        INDEX_POS=-(~INDEX_POS);
      }else{
        printf("$:Position already used\n");
      }
      
    }else{
      while(1 == 1){
        printf("$:PLAYER 1 valid position ? ");
        scanf("%u",&B_POSITION_A);
        if(B_POSITION_A >=0 && B_POSITION_A <9){
          
          if(MALLOC_CONTAINS(POSITION,&GAME_BOARD_SIZE,&B_POSITION_A) == 1){
            GAME_BOARD[B_POSITION_A]=PLAYER_1;
            POSITION[INDEX_POS]=B_POSITION_A;
            BOARD_PLAY(GAME_BOARD);
            INDEX_POS=-(~INDEX_POS);
          }else{
            printf("$:Position already used\n");
          }
          
          break;
        }
      }
    }
    /*for(int i=0;i<9;i++){
      printf("POSITION USED %d\n",POSITION[i]);
    }*/
    
  }
  return 0;
}