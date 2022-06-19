#include <stdio.h>
#include <stdlib.h>

#define PLAYER_CHOOSE \
  printf("$:DO YOU WANT 'x' OR 'o' ? ");
#define BORDER "*-----------*"
#define ALREADY_USED\
  printf("$:YOU HAVE MISSED A SHOT\n");
#define INTENT_POSITION(_) printf("$:[PLAYER-%d] WHICH POSITION ? ",_);
#define WINNER_X \
  printf("$:[GAME] THE WINNER IS x\n");
#define WINNER_O \
  printf("$:[GAME] THE WINNER IS o\n");
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
      return 1;
    }
  }
  return 0;
}

int CHECK_WINNER(char *board){
  
  /*CASE 1*/
  if(board[0] == 'x' && board[1] == 'x' && board[2] == 'x'){
    WINNER_X
    return 0;
  }else if(board[0] == 'o' && board[1] == 'o' && board[2] == 'o'){
    WINNER_O
    return 0;
  }
  /*CASE 2*/
  else if(board[0] == 'x' && board[3] == 'x' && board[6] == 'x'){
    WINNER_X
    return 0;
  }
  else if(board[0] == 'o' && board[3] == 'o' && board[6] == 'o'){
    WINNER_O
    return 0;
  }
  /*CASE 3*/
  else if(board[6] == 'x' && board[7] == 'x' && board[8] == 'x'){
    WINNER_X
    return 0;
  }
  else if(board[6] == 'o' && board[7] == 'o' && board[8] == 'o'){
    WINNER_O
    return 0;
  }
  /*CASE 4*/
  else if(board[2] == 'x' && board[5] == 'x' && board[8] == 'x'){
    WINNER_X
    return 0;
  }
  else if(board[2] == 'o' && board[5] == 'o' && board[8] == 'o'){
    WINNER_O
    return 0;
  }
  /*CASE 5*/
  else if(board[3] == 'x' && board[4] == 'x' && board[5] == 'x'){
    WINNER_X
    return 0;
  }
  else if(board[3] == 'o' && board[4] == 'o' && board[5] == 'o'){
    WINNER_O
    return 0;
  }
  /*CASE 6*/
  else if(board[0] == 'x' && board[4] == 'x' && board[8] == 'x'){
    WINNER_X
    return 0;
  }
  else if(board[0] == 'o' && board[4] == 'o' && board[8] == 'o'){
    WINNER_O
    return 0;
  }
  /*CASE 7*/
  else if(board[1] == 'x' && board[4] == 'x' && board[7] == 'x'){
    WINNER_X
    return 0;
  }
  else if(board[1] == 'o' && board[4] == 'o' && board[7] == 'o'){
    WINNER_O
    return 0;
  }
  /*CASE 8*/
  else if(board[6] == 'x' && board[4] == 'x' && board[2] == 'x'){
    WINNER_X
    return 0;
  }
  else if(board[6] == 'o' && board[4] == 'o' && board[2] == 'o'){
    WINNER_O
    return 0;
  }  
  
  return -1;
}
int main(void){
  
  char PLAYER_1='-',PLAYER_2='-';
  unsigned int B_POSITION_A,B_POSITION_B;
  int GAME_BOARD_SIZE=9;
  
  char* GAME_BOARD =(char*)malloc(*&GAME_BOARD_SIZE*sizeof(char));
  static unsigned int INDEX_POS=0;
  
  int * POSITION   = (int*)malloc(8*sizeof(int));
  int   POSITION_S = 0;
  
  for(int i=0;i<9;i++){
      POSITION[i]=-1;
  }
  
  CONSTRUCT_BOARD(GAME_BOARD);
  int id_a=1,id_b=2;
  HANDLE_P(&PLAYER_1,&PLAYER_2,&id_a);
  
  printf("$:PLAYER 1 '%c' PLAYER 2 '%c'\n",*&PLAYER_1,*&PLAYER_2);
  BOARD_PLAY(GAME_BOARD);
  
  while(1 == 1){
    
    INTENT_POSITION(1)
    scanf("%u",&B_POSITION_A);
    
    if(B_POSITION_A >=0 && B_POSITION_A <9){
      int __=MALLOC_CONTAINS(POSITION,&GAME_BOARD_SIZE,&B_POSITION_A);
      if(__ == 0){
        
        GAME_BOARD[B_POSITION_A]=PLAYER_1;
        POSITION[INDEX_POS]=B_POSITION_A;
        BOARD_PLAY (GAME_BOARD);
        INDEX_POS=-(~INDEX_POS);
        
        int WINNER_G=CHECK_WINNER(GAME_BOARD);
        if(WINNER_G == 0){break;}
        
      }else if(__ == 1){
        ALREADY_USED
      }
    }else{
      while(1 == 1){
          printf("$:PLAYER-1 VALID POSITION ? ");
          scanf("%u",&B_POSITION_A);
          if(B_POSITION_A >=0 && B_POSITION_A <9){
            int __=MALLOC_CONTAINS(POSITION,&GAME_BOARD_SIZE,&B_POSITION_A);
            if(__ == 0){
              GAME_BOARD[B_POSITION_A]=PLAYER_1;
              POSITION[INDEX_POS]=B_POSITION_A;
              BOARD_PLAY (GAME_BOARD);
              INDEX_POS=-(~INDEX_POS);
              
              int WINNER_G=CHECK_WINNER(GAME_BOARD);
              if(WINNER_G == 0){break;}
              
            }else{
              ALREADY_USED
            }
            break;
          }
      }
    }
    
    INTENT_POSITION(2)
    scanf("%u",&B_POSITION_B);
        if(B_POSITION_B >=0 && B_POSITION_B <9){
      int __=MALLOC_CONTAINS(POSITION,&GAME_BOARD_SIZE,&B_POSITION_B);
      if(__ == 0){
        GAME_BOARD[B_POSITION_B]=PLAYER_2;
        POSITION[INDEX_POS]=B_POSITION_B;
        
        BOARD_PLAY (GAME_BOARD);
        INDEX_POS=-(~INDEX_POS);
        
        int WINNER_G=CHECK_WINNER(GAME_BOARD);
        if(WINNER_G == 0){break;}
        
      }else if(__ == 1){
        ALREADY_USED
      }
    }else{
        while(1 == 1){
          printf("$:PLAYER-2 VALID POSITION ? ");
          scanf("%u",&B_POSITION_B);
          if(B_POSITION_B >=0 && B_POSITION_B <9){
            
            int __=MALLOC_CONTAINS(POSITION,&GAME_BOARD_SIZE,&B_POSITION_B);
            if(__ == 0){
              
              GAME_BOARD[B_POSITION_B]=PLAYER_2;
              POSITION[INDEX_POS]=B_POSITION_B;
              BOARD_PLAY (GAME_BOARD);
              INDEX_POS=-(~INDEX_POS);

              int WINNER_G=CHECK_WINNER(GAME_BOARD);
              if(WINNER_G == 0){break;}
              
            }else{
              ALREADY_USED
            }
            break;
          }
      }
    }
    

  }
  return 0;
}
