#include "Player.h"
#include "GameMechs.h"
#include "MacUILib.h"

#define DELAY_CONST 1000000

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerPos.x = mainGameMechsRef->getBoardSizeX() / 2;
    playerPos.y = mainGameMechsRef->getBoardSizeY() / 2;
    playerPos.symbol = '@';

    myDir = STOP;


    // more actions to be included
}


Player::~Player()
{
    delete mainGameMechsRef;

    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    
    returnPos = playerPos;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    bool exitFlag = mainGameMechsRef->getExitFlagStatus();

    if (input != 0) // if not null character
    {
        // Add more key processing here
        // Add more key processing here
        // Add more key processing here 

        switch (input)
        {
            case ' ': // exit
                mainGameMechsRef->setExitTrue();
                break;

            case 'W':
            case 'w':
                if (myDir != DOWN)
                {
                    myDir = UP;
                }
                break;
            case 'S':
            case 's':
                if (myDir != UP)
                {
                    myDir = DOWN;
                }
                break;
            case 'A':
            case 'a':
                if (myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;
            case 'D':
            case 'd':
                if (myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;
            default:
                myDir = INITIAL;
                break;
        }
        input = 0;
    }
    // PPA3 input processing logic        
}

int speed_adjustment = 0;

void Player::movePlayer()
{
    int height = mainGameMechsRef->getBoardSizeY();
    int width = mainGameMechsRef->getBoardSizeX();

    if (myDir != INITIAL)
    {
        //to avoid overflow
        if (speed_adjustment > 1000){
            speed_adjustment = 0;
        }
        speed_adjustment++;
        //reduces player speed by a factor of 5
        if (speed_adjustment % 5 == 0){

        switch (myDir)
        {
            case UP:
                if (playerPos.y > 1) {
                    playerPos.y--;
                }
                else {
                    playerPos.y = height - 2;
                }
                break;
            case DOWN:
                if (playerPos.y < height - 2) {
                    playerPos.y++;
                }
                else {
                    playerPos.y = 1;
                }
                break;
            case LEFT:
                if (playerPos.x > 1) {
                    playerPos.x--;
                }
                else {
                    playerPos.x = width - 2;
                }
                break;
            case RIGHT:
                if (playerPos.x < width - 2) {
                    playerPos.x++;
                }
                else {
                    playerPos.x = 1;
                }
                break;
            default:
                break;
        }}
    }

    // PPA3 Finite State Machine logic
}
