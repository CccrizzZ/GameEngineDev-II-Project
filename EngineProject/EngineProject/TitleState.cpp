#include "TitleState.h"
#include "Game.hpp"

TitleState::TitleState(StateStack* stack, Context* context)
    : State(stack, context)
{
    OutputDebugString(L"title init");
    OutputDebugString(L"\n");
    

    
	// Background
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(this));
	bg = backgroundSprite.get();
	bg->setPosition(0.0f, 0.0f, 0.0f);
	bg->setScale(50.0f, 50.0f, 50.0f);
    bg->setVelocity(0.0f, 0.0002f);
	mSceneGraph->attachChild(std::move(backgroundSprite));


    // build scenegraph
    mSceneGraph->build();


    // build render items
    getContext()->game->BuildRenderItems(mAllRitems);

    // build frame resources
    getContext()->game->BuildFrameResources(mAllRitems.size());



    
    
}

void TitleState::draw()
{
    mSceneGraph->draw();
}

bool TitleState::update(const GameTimer& gt)
{


    mSceneGraph->update(gt);

    // press g to goto game state
    // if (GetAsyncKeyState('G') & 0x8000)
    // {
    //     requestStackPop();
    //     requestStackPush(States::Game);
	// }

	bg->Update(gt);

	return true;
}
