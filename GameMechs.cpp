#include <iostream>
#include "GameMechs.h"
#include "MacUILib.h"

void GameMechs::generateFood(objPos blockOff) {
    // Implement your random food generation logic here
    // Make sure it does not generate food on the player (blockOff)

    // Example random generation:
    foodPos.x = rand() % (getBoardSizeX() - 2) + 1;
    foodPos.y = rand() % (getBoardSizeY() - 2) + 1;
    foodPos.symbol = 'O'; // You can use any symbol for food
    
}

void GameMechs::getFoodPos(objPos& returnPos) {
    returnPos = foodPos;
}

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

// do you need a destructor?

// GameMechs::~GameMechs() {
//         // Destructor
// }


bool GameMechs::getExitFlagStatus()
{
    bool status = exitFlag;
    exitFlag = false; // Reset exitFlag to false
    return status;
}

bool GameMechs::getLoseFlagStatus() { return loseFlag; }
    
char GameMechs::getInput()
{
    if (MacUILib_hasChar()) {
        input = MacUILib_getChar();
    } 
    return input; 
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
    // std::cout << "Game over!" << std::endl;
}

void GameMechs::setLoseFlag() { loseFlag = true; }

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

int GameMechs::getScore() { return score; }

void GameMechs::incrementScore() { score++; }

    
// void GameMechs::generateFood(objPos blockOff) {
//     srand(time(NULL))
//     do{
//         foodPos.x = rand() % (boardSizeX - 2) + 1;
//         foodPos.y = rand() % (boardSizeY - 2) + 1;
//         foodPos.symbol = ('F');
//     }
//     while (foodPos == blockOff){}
// }

// void GameMechs::getFoodPos(objPos &returnPos) {
//     returnPos = foodPos;
// }

