#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

#define WIDTH 20
#define HEIGHT 10

using namespace std;

#define DELAY_CONST 100000

// private:
//     char input;
//     bool exitFlag;
//     bool loseFlag;
//     int score;
//     int boardSizeX;
//     int boardSizeY;

//     struct objPos foodPos;

// public:
//     // Constructor
//     gameMechanism() {
//         boardSizeX = 30;
//         boardSizeY = 15;
//         exitFlag = false;
//         loseFlag = false;
//         score = 0;
//     }

//     gameMechanism(int boardX, int boardY) {
//         boardSizeX = boardX;
//         boardSizeY = boardY;
//         exitFlag = false;
//         loseFlag = false;
//         score = 0;
//         generateFood();
//     }

//     ~gameMechanism() {
//         // Destructor
//     }

//     // Getter and setter methods
//     bool getExitFlagStatus() { return exitFlag; }
//     void setExitTrue() { exitFlag = true; }

//     bool getLoseFlagStatus() { return loseFlag; }
//     void setLoseFlag() { loseFlag = true; }

//     char getInput(){
//         if (MacUILib_hasChar()) {
//             input = MacUILib_getChar();
//         } 
//         return input; 
//     }
//     void setInput(char thisInput){ input = thisInput; }

//     void clearInput(){ input = 0; }

//     int getBoardSizeX() { return boardSizeX; }
//     int getBoardSizeY() { return boardSizeY; }

//     int getScore() { return score; }
//     void incrementScore() { score++; }
    
//     void generateFood(objPos blockOff) {
//         srand(time(NULL))
//         do{
//             foodPos.x = rand() % (boardSizeX - 2) + 1;
//             foodPos.y = rand() % (boardSizeY - 2) + 1;
//             foodPos.symbol = ('F');
//         }
//         while (foodPos == blockOff){}
//     }

//     void getFoodPos(objPos &returnPos) {
//         returnPos = foodPos;
//     }


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


Player *player = new player();
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
    player -> movePlayer();
   
}

void RunLogic(void)
{
    player -> updatePlayerDir();
    
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
                cout << player -> playerPos.getSymbol();
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
