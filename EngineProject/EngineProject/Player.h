#pragma once
#include "CommandQueue.h"
#include "Aircraft.hpp"
#include "World.hpp"
#include <map>
using namespace std;




class Player
{
    // struct for moving the player
    struct AircraftMover
    {
        XMFLOAT3 velocity;
        
        AircraftMover(float vx, float vy, float vz) : velocity(vx, vy, vz)
        {

        }

        void operator() (SceneNode& node, const GameTimer& gt) 
        {
            Aircraft& aircraft = static_cast<Aircraft&>(node);
            aircraft.move(velocity);
        }        
    };

    // enum for player action keybinding
    enum Action
    {
        MoveLeft,
        MoveRight,
        MoveForward,
        MoveBackward
    };





public:
    Player();
    


    // player speed
    const float playerSpeed = 0.001f;

    // called in game class to handle player input
    void handleEvent(CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);




    // assign action to target key
    void assignKey(Action action, int key);
    
    // get action assigned key
    string getAssignedKey(Action action) const;

private:
    // returns if action is realtime
    static bool isRealtimeAction(Command command);

    // map for key and action binding
    map<int, Action> mKeyBinding;
    map<Action, Command> mActionBinding;


    // player commands
    Command moveLeft;
    Command moveRight;
    Command moveForward;
    Command moveBackward;






};

