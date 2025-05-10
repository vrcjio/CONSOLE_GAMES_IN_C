#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    int x = 0, y = 0;
    char move;
    int treasureX = 2, treasureY = 3;
    srand(time(0));

    treasureX = rand()%5+1;
    treasureY = rand()%5+1;
    
    printf("\nTreasure at: %d %d",treasureX, treasureY);
    printf("\nTreasure Hunt Begins!\n");

    while(x!=treasureX || y!=treasureY){
        printf("\nYour are at (%d,%d), Move(N/S/E/W): ",x,y);
        scanf("%c",&move);

        if(move =='N'|| move =='n') y++;
        else if(move =='S'|| move =='s')y--;
        else if(move =='E'|| move =='e')x++;
        else if(move =='W'|| move =='w')x--;
        else printf("Invalide move!\n");
    }
    
    printf("\nCongratulations you found the treasure at(%d,%d)!\n",x,y);

    return 0;
}