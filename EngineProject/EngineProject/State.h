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
        Context(Player& player, Game& game);

        void BuildWorld();
        
        // World* world;
        Game* game;
        Player* player;
    };

    State(StateStack* stack, Context* context);

    virtual ~State();
    virtual void draw() = 0 ;
    virtual bool update(const GameTimer& gt) = 0;
    // virtual bool handleEvent()
    bool UpdateObjectCB();



    // get render item list
    std::vector<std::unique_ptr<RenderItem>>& getRenderItems() { return mAllRitems; }
    
    // scene graph
    unique_ptr<SceneNode> mSceneGraph;

    // return state context
    Context* getContext() const;

protected:
    // manipulation method
    void requestStackPush(States::ID stateID);
    void requestStackPop();
    void requestStateClear();


    Context* mContext;



	// List of all the render items.
	vector<unique_ptr<RenderItem>> mAllRitems;


private:
    StateStack* mStack;


    // scene graph
};

