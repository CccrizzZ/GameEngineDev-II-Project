#include "TitleState.h"
#include "Game.hpp"

TitleState::TitleState(StateStack* stack, Context* context)
    : State(stack, context)
{
    OutputDebugString(L"title init");
    OutputDebugString(L"\n");
    
    mAllRitems.clear();

	// Background
	std::unique_ptr<TitleSprite> backgroundSprite(new TitleSprite(this));
	bg = backgroundSprite.get();
	bg->setPosition(0.0f, 1.0f, 0.0f);
	bg->setScale(2.5f, 1.0f, 1.5f);
    bg->setVelocity(0.0f, 0.0002f);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	std::unique_ptr<TitleSprite> backgroundSprite2(new TitleSprite(this));
	bg2 = backgroundSprite2.get();
	bg2->setPosition(0.0f, 1.0f, 0.0f);
	bg2->setScale(2.5f, 1.0f, 1.5f);
    bg2->setVelocity(0.0f, 0.0002f);
	mSceneGraph->attachChild(std::move(backgroundSprite2));

	std::unique_ptr<TitleSprite> backgroundSprite3(new TitleSprite(this));
	bg3 = backgroundSprite3.get();
	bg3->setPosition(0.0f, 1.0f, 0.0f);
	bg3->setScale(2.5f, 1.0f, 1.5f);
    bg3->setVelocity(0.0f, 0.0002f);
	mSceneGraph->attachChild(std::move(backgroundSprite3));


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
    if (GetAsyncKeyState('G') & 0x8000)
    {
        requestStackPop();
        requestStackPush(States::Game);
        return false;
    }

	bg->Update(gt);

	return true;
}
