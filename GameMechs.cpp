#include "GameMechs.h"
#include "MacUILib.h"

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
    // generateFood();
}

// do you need a destructor?

// ~GameMechs() {
//         // Destructor
// }


bool GameMechs::getExitFlagStatus()
{
    exitFlag = 0;
    return exitFlag;
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
    // return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
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

// int GameMechs::getScore() { return score; }

// void GameMechs::incrementScore() { score++; }

    
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

