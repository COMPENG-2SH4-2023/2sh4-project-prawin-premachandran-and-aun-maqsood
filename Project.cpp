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
objPos drawBoard{0,0,0};
objPos *player = new objPos(WIDTH/2,HEIGHT/2,'@');
objPos *item1 = new objPos(1,1,'A');
objPos *item2 = new objPos(2,2,'B');
objPos *item3 = new objPos(3,3,'C');
objPos *item4 = new objPos(4,4,'D');
objPos *item5 = new objPos(5,5,'E');


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
     for (drawBoard.y = 0; drawBoard.y < HEIGHT; (drawBoard.y)++) {
        for (drawBoard.x = 0; drawBoard.x < WIDTH; (drawBoard.x)++) {
            if (drawBoard.x == 0 || drawBoard.x == WIDTH - 1 || drawBoard.y == 0 || drawBoard.y == HEIGHT - 1) {
                cout << '#';
            }
            else if (drawBoard.isPosEqual(player)) {
                cout << player ->getSymbol();
            }
            else if (drawBoard.isPosEqual(item1)){
                cout << item1 -> getSymbol();
            }
             else if (drawBoard.isPosEqual(item2)) {
                cout << item2 -> getSymbol();
            }
            else if (drawBoard.isPosEqual(item3)) {
                 cout << item3 -> getSymbol();

            }
             else if (drawBoard.isPosEqual(item4)) {
                    cout << item4 -> getSymbol();

            }
             else if (drawBoard.isPosEqual(item5)) {
                cout << item5 -> getSymbol();

            }
            else {
                cout << " ";
                 
            }
        }
        cout << endl;
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
