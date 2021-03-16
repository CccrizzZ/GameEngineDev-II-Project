#include "Player.h"

Player::Player()
{
    // setup the inputs
    moveLeft.category = Category::Type::PlayerAircraft;
    moveLeft.action = AircraftMover(-playerSpeed, 0.0f, 0.0f);
    moveLeft.isRealtimeAction = true;
    
    moveRight.category = Category::Type::PlayerAircraft;
    moveRight.action = AircraftMover(playerSpeed, 0.0f, 0.0f);
    moveRight.isRealtimeAction = true;

    moveForward.category = Category::Type::PlayerAircraft;
    moveForward.action = AircraftMover(0.0f, 0.0f, playerSpeed);
    moveForward.isRealtimeAction = true;
    
    moveBackward.category = Category::Type::PlayerAircraft;
    moveBackward.action = AircraftMover(0.0f, 0.0f, -playerSpeed);
    moveBackward.isRealtimeAction = true;
    







    // fill key binding map
    mKeyBinding.insert(pair<int, Action>('A', Action::MoveLeft));
    mKeyBinding.insert(pair<int, Action>('D', Action::MoveRight));
    mKeyBinding.insert(pair<int, Action>('W', Action::MoveForward));
    mKeyBinding.insert(pair<int, Action>('S', Action::MoveBackward));



    // fill action binding map
    mActionBinding.insert(pair<Action, Command>(Action::MoveLeft, moveLeft));
    mActionBinding.insert(pair<Action, Command>(Action::MoveRight, moveRight));
    mActionBinding.insert(pair<Action, Command>(Action::MoveForward, moveForward));
    mActionBinding.insert(pair<Action, Command>(Action::MoveBackward, moveBackward));



    // // set all the pairs in action binding map's category to player aircraft
    // // pair second is a command object
    // for(auto& pair : mActionBinding)
    // {
    //     pair.second.category = Category::PlayerAircraft;
    // }


}



void Player::handleEvent(CommandQueue& commands)
{

}


void Player::handleRealtimeInput(CommandQueue& commands)
{


    // push all item in key binding into the command queue
    // pair first = keypressed, second = action enum
    for(auto pair : mKeyBinding)
    {
        if (GetAsyncKeyState(pair.first) && isRealtimeAction(mActionBinding[pair.second]))
        {
            commands.push(mActionBinding[pair.second]);
        }
    }

    // if (GetAsyncKeyState('W') & 0x8000)
    // {
    //     Command moveUP;
    //     moveUP.category = Category::Type::PlayerAircraft;
    //     moveUP.action = AircraftMover(0.0f, 0.0f, playerSpeed);
    //     commands.push(moveUP);
    // }
    
    // if (GetAsyncKeyState('S') & 0x8000)
    // {
    //     Command moveDown;
    //     moveDown.category = Category::Type::PlayerAircraft;
    //     moveDown.action = AircraftMover(0.0f, 0.0f, -playerSpeed);
    //     commands.push(moveDown);
    // }
    
    // if (GetAsyncKeyState('A') & 0x8000)
    // {
    //     Command moveLeft;
    //     moveLeft.category = Category::Type::PlayerAircraft;
    //     moveLeft.action = AircraftMover(-playerSpeed, 0.0f, 0.0f);
    //     commands.push(moveLeft);
    // }
    
    // if (GetAsyncKeyState('D') & 0x8000)
    // {
    //     Command moveRight;
    //     moveRight.category = Category::Type::PlayerAircraft;
    //     moveRight.action = AircraftMover(playerSpeed, 0.0f, 0.0f);
    //     commands.push(moveRight);
    // }



}

void Player::assignKey(Action action, int key)
{
}

string Player::getAssignedKey(Action action) const
{
    return string();
}


bool Player::isRealtimeAction(Command command)
{
    return command.isRealtimeAction;
}
