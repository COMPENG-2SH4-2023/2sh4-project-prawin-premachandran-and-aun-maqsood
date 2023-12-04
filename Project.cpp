#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#define WIDTH 30
#define HEIGHT 15

using namespace std;

#define DELAY_CONST 100000

bool exitFlag = false;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int x;
int y;

GameMechs *gameMechs = new GameMechs();
  
Player *player = new Player(gameMechs); 
objPos playerElement{0,0,0};
objPosArrayList *playerPos;
objPos foodPos;

// Iteration 1
// objPos item1{1,1,'A'};
// objPos item2{2,2,'B'};
// objPos item3{3,3,'C'};
// objPos item4{4,4,'D'};
// objPos item5{5,5,'E'};

int main(void)
{

    Initialize();

    while(!gameMechs->getExitFlagStatus())  
    {
        
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();

        //end game message
        if (gameMechs -> getExitFlagStatus()){
            cout << "Game Over! Thank you for playing :)" << endl;
            MacUILib_Delay(1000*DELAY_CONST);
        } 
    }

    //CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    gameMechs->generateFood(foodPos);
    gameMechs->getFoodPos(foodPos);

}

void GetInput(void)
{
    gameMechs->clearInput();
    char input = gameMechs->getInput();
    gameMechs->setInput(input);
}

void RunLogic(void)
{
 
    player->updatePlayerDir();

    player->movePlayer();

    // if (playerPos.isPosEqual(&foodPos)){
    //     gameMechs->generateFood(foodPos);
    //     gameMechs->incrementScore();
    // }
}

void DrawScreen(void)
{
    // prints and updates score
    MacUILib_printf("Score: %d\n", gameMechs->getScore());
    objPos tempPos;
    // cout << "Player position: (" << playerPos.x << ", " << playerPos.y << ")" << endl;

    // Draws game board screen (20 x 10)
    MacUILib_clearScreen(); 
  
    objPosArrayList *drawBoardList = player->getPlayerPos();
    objPos currentIndex;
   objPos drawBoard{0,0,0};
   bool hasRun = false;

    
    for (drawBoard.y = 0; drawBoard.y < HEIGHT; (drawBoard.y)++) {
        for (drawBoard.x = 0; drawBoard.x < WIDTH; (drawBoard.x)++) {
            hasRun = false;
            
            if (drawBoard.x == 0 || drawBoard.x == WIDTH-1 || drawBoard.y == 0 || drawBoard.y == HEIGHT - 1 && hasRun == false) {
                MacUILib_printf("%c", '#');
                hasRun = true;
               
            }
            // Draw food
            else if (drawBoard.isPosEqual(&foodPos) && hasRun == false) {
                MacUILib_printf("%c", foodPos.getSymbol());
                hasRun = true;
            }
        
           
            
              
            for (int i = 0; i < drawBoardList -> getSize(); i++) {
                
                drawBoardList -> getElement(currentIndex,i);
                if (drawBoard.isPosEqual(&currentIndex) && hasRun == false) {
                    MacUILib_printf("%c", currentIndex.getSymbol());
                    hasRun = true;
                   
                }
            }
            if (drawBoard.x >=1 && drawBoard.y < HEIGHT -1 && hasRun == false){
                
                               MacUILib_printf("%c",' ');


            }

             
            
            // else if (drawBoard.isPosEqual(&item1)){
            //     cout << item1.getSymbol();
            // }
            // else if (drawBoard.isPosEqual(&item2)) {
            //     cout << item2.getSymbol();
            // }
            // else if (drawBoard.isPosEqual(&item3)) {
            //      cout << item3.getSymbol();

            // }
            // else if (drawBoard.isPosEqual(&item4)) {
            //         cout << item4.getSymbol();

            // }
            // else if (drawBoard.isPosEqual(&item5)) {
            //     cout << item5.getSymbol();

            // }
            
                 
            
        }
        MacUILib_printf("%c",'\n');
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
