#pragma once
#include <memory>
#include "SceneNode.hpp"
// #include "Game.hpp"
using namespace std;

class World;
class Player;
class StateStack;

namespace States
{
	enum ID
	{
		None,
		Title,
		Menu,
		Game,
		Loading,
		Pause
	};
}


class StateStack;

class State
{
public:
    typedef unique_ptr<State> Ptr;

    // context for each state object
    struct Context
    {
        // Context() = default;

        Context(Player& player, Game& game);

        void BuildWorld();
        
        Game* game;
        World* world;
        Player* player;
    };

    State(StateStack& stack, Context context);
    virtual ~State();
    virtual void draw() = 0 ;
    virtual bool update(const GameTimer& gt) = 0;
    // virtual bool handleEvent()
    
protected:
    // manipulation method
    void requestStackPush(States::ID stateID);
    void requestStackPop();
    void requestStateClear();

    // return state context
    Context getContext() const;

private:
    StateStack* mStack;
    Context mContext;

};

