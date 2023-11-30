#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#define WIDTH 20
#define HEIGHT 10

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int x;
int y;
objPos item1 = objPos(WIDTH/2,HEIGHT/2,'@');
objPos item2 = objPos(x,y,)

int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
     for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1) {
                printf("%c", '#');
            }
            else if (y == player.y && x == player.x) {
                printf("%c", player.symbol);
            }
             else if (y == itemBin[0].y && x == itemBin[0].x) {
                printf("%c", itemBin[0].symbol);
            }
            else if (y == itemBin[1].y && x == itemBin[1].x) {
                printf("%c", itemBin[1].symbol);
            }
             else if (y == itemBin[2].y && x == itemBin[2].x) {
                printf("%c", itemBin[2].symbol);
            }
             else if (y == itemBin[3].y && x == itemBin[3].x) {
                printf("%c", itemBin[3].symbol);
            }
             else if (y == itemBin[4].y && x == itemBin[4].x) {
                printf("%c", itemBin[4].symbol);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }   

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
