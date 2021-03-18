#pragma once
#include "State.h"
#include <vector>
#include <map>
#include <functional>
using namespace std;



// class State;

class StateStack
{
public:
    enum Action
    {
        Push,
        Pop,
        Clear
    };


public:
    explicit StateStack(State::Context context);
    
    // template for registering a state
    template <typename T>
    void registerState(States::ID stateID);
    
    void update(const GameTimer& gt);
    void draw();
    // void handleEvent(const )

    void pushState(States::ID);
    void popState();
    void clearStates();

    // determine if stack empty
    bool isEmpty() const;


private:
	struct PendingChange
	{
		explicit PendingChange(Action action, States::ID stateID = States::None);

		Action action;
		States::ID stateID;
	};


    State::Ptr createState(States::ID stateID);
    void StateStack::applyPendingChanges();
    


    // vector for states
    vector<State::Ptr> mStack;
    vector<PendingChange> mPendingList;

    State::Context mContext;
    map<States::ID, function<State::Ptr()>> mFactories;



};

