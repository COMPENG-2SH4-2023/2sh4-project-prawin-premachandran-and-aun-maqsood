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

objPosArrayList* Player::getPlayerPos()
{
    
    return playerPosList;
    // return the reference to the playerPos arrray list
}

void Player::increasePlayerLength(){
        // Get the current head position of the player
    objPos headPos;
    playerPosList->getHeadElement(headPos);

    // Create a new position for the new head
    objPos newHeadPos;

    // Adjust the new head position based on the current direction of the player
    switch (myDir) {
        case UP:
            newHeadPos.x = headPos.x;
            newHeadPos.y = headPos.y - 1;
            break;
        case DOWN:
            newHeadPos.x = headPos.x;
            newHeadPos.y = headPos.y + 1;
            break;
        case LEFT:
            newHeadPos.x = headPos.x - 1;
            newHeadPos.y = headPos.y;
            break;
        case RIGHT:
            newHeadPos.x = headPos.x + 1;
            newHeadPos.y = headPos.y;
            break;
        default:
            // If the current direction is not set, do nothing
            return;
    }

    // Insert the new head position to the front of the player's position list
    playerPosList->insertHead(newHeadPos);
}

// bool Player::checkSelfCollision(){
//     if head = tail

// }

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
        }
    }
    // PPA3 Finite State Machine logic
}
