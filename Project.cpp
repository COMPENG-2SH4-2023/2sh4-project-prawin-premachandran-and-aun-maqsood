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
objPos playerElement{0, 0, 0};
objPosArrayList *playerPos;
objPos foodPos;

int main(void)
{
    Initialize();

    while (!gameMechs->getExitFlagStatus())
    {
        // updates player and food position for every loop
        gameMechs->getFoodPos(foodPos);

        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();

        // end game message
        if (gameMechs->getExitFlagStatus())
        {
            cout << "Game Over! Thank you for playing :)" << endl;
        }
    }

    // CleanUp();
}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = gameMechs->getExitFlagStatus();
    gameMechs->generateFood(foodPos);
    gameMechs->getFoodPos(foodPos);
}

void GetInput(void)
{
    gameMechs->clearInput();
    char input = gameMechs->getInput();
    gameMechs->setInput(input);

    // Check for spacebar input to set the exitFlag directly
    if (input == ' ')
    {
        exitFlag = true;
        cout << "ExitFlag set to true." << endl;
    }
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();

    objPosArrayList *playerPosList = player->getPlayerPos(); // Get the playerPosList

    objPos headPos;
    playerPosList->getHeadElement(headPos);

    if (headPos.isPosEqual(&foodPos))
    {
        // The player ate the food, generate a new food position
        gameMechs->generateFood(foodPos);
        gameMechs->getFoodPos(foodPos);
        gameMechs->incrementScore();
    }
}

void DrawScreen(void)
{
    // prints and updates score (for every loop)
    cout << "Current Score: " << gameMechs->getScore() << endl;

    //prints rest of screen elements
    cout << "==============================" << endl;
    cout << "Prawin & Aun's Final Project" << endl;
    cout << "==============================" << endl;
    cout << "Board Size: " << gameMechs->getBoardSizeX() << " X " << gameMechs->getBoardSizeY() << endl;

    // Clears screen for every loop (frame)
    MacUILib_clearScreen();

    //declaring variables
    objPosArrayList *drawBoardList = player->getPlayerPos();
    objPos currentIndex;
    objPos drawBoard{0, 0, 0};

    //boolean which checks if each element on game board has been printed (except spaces)
    //initially set to false
    bool hasRun = false;

    for (drawBoard.y = 0; drawBoard.y < HEIGHT; (drawBoard.y)++)
    {
        for (drawBoard.x = 0; drawBoard.x < WIDTH; (drawBoard.x)++)
        {
            hasRun = false;

            //Print board outline
            if (drawBoard.x == 0 || drawBoard.x == WIDTH - 1 || drawBoard.y == 0 || drawBoard.y == HEIGHT - 1 && hasRun == false)
            {
                MacUILib_printf("%c", '#');
                //set to true to avoid repeating
                hasRun = true;
            }

            // Print food
            else if (drawBoard.isPosEqual(&foodPos) && hasRun == false)
            {
                MacUILib_printf("%c", foodPos.getSymbol());
                hasRun = true;
            }

            // Print player symbol
            for (int i = 0; i < drawBoardList->getSize(); i++)
            {
                drawBoardList->getElement(currentIndex, i);
                if (drawBoard.isPosEqual(&currentIndex) && hasRun == false)
                {
                    MacUILib_printf("%c", currentIndex.getSymbol());
                    hasRun = true;
                }
            }

            //Print spaces
            if (drawBoard.x >= 1 && drawBoard.y < HEIGHT - 1 && hasRun == false)
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("%c", '\n');
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