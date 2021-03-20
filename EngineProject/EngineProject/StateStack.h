#pragma once
#include "State.h"
#include <vector>
#include <map>
#include <functional>
using namespace std;


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
    void registerState(States::ID stateID)
    {
        mFactories[stateID] = [this]()
        {
            return State::Ptr(new T(*this, mContext));
        };
    }

    void update(const GameTimer& gt);
    void draw();
    // void handleEvent(const )

    void pushState(States::ID);
    void popState();
    void clearStates();

    // determine if stack empty
    bool isEmpty() const;

    // build state world
    void BuildStateWorld();

    State::Context mContext;
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

    map<States::ID, function<State::Ptr()>> mFactories;



};

