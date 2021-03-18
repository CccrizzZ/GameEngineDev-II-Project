#pragma once
#include <memory>
#include "SceneNode.hpp"
#include "Game.hpp"
using namespace std;


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

    struct Context
    {
        // Context() = default;

        Context(World& world, Player& player);

        World* world;
        Player* player;
    };

    State(StateStack& stack, Context context);
    virtual ~State();
    virtual void draw();
    virtual bool update(const GameTimer& gt);
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

