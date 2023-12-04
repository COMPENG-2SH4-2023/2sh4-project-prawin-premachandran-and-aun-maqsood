#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    
    // Construct the remaining declaration from the project manual.
    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP,INITIAL};  // This is the direction state

        Player(GameMechs* thisGMRef);
        
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        

    private:
        objPos playerPos;   // Upgrade this in iteration 3.

        objPosArrayList* playerPosList;  // New member for snake body
              
        enum Dir myDir;

        int speed_adjustment = 0;
        
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif