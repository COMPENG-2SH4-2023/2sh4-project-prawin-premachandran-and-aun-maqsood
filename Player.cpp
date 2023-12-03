#include "Player.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include "objPosArrayList.h"

#define DELAY_CONST 1000000

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
   
    playerPos.symbol = '*';
    playerPosList = new objPosArrayList();
    playerPosList -> getHeadElement(playerPos);
    

    myDir = STOP;


    // more actions to be included
}


Player::~Player()
{
    delete mainGameMechsRef;

    // delete any heap members here
}

void Player::getPlayerPos(objPosArrayList* returnPos)
{
    
    returnPos = playerPosList;
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
                    playerPosList->insertHead(playerPos);
                    playerPosList->removeTail();
                }
                else {
                    playerPos.y = height - 2;
                }
                break;
            case DOWN:
                if (playerPos.y < height - 2) {
                    playerPos.y++;
                    playerPosList->insertHead(playerPos);
                    playerPosList->removeTail();
                }
                else {
                    playerPos.y = 1;
                    playerPosList->insertHead(playerPos);
                    playerPosList->removeTail();
                }
                break;
            case LEFT:
                if (playerPos.x > 1) {
                    playerPos.x--;
                    playerPosList->insertHead(playerPos);
                    playerPosList->removeTail();
                }
                else {
                    playerPos.x = width - 2;
                }
                break;
            case RIGHT:
                if (playerPos.x < width - 2) {
                    playerPos.x++;
                    playerPosList->insertHead(playerPos);
                    playerPosList->removeTail();
                    
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
