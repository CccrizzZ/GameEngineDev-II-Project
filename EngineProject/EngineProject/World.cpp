#include "World.hpp"

World::World(Game* game)
	: mSceneGraph()
	, mGame(game)
	, mPlayerAircraft(nullptr)
	, mBackground(nullptr)
{

	// mBackground = new SpriteNode(&game);
	// mPlayerAircraft = new Aircraft(Aircraft::Eagle , game);

	// aircraftSize = XMFLOAT3(0.2f, 0.2f, 0.2f);
}

void World::update(const GameTimer& gt)
{


	// // mSceneGraph->update(gt);
	// // mPlayerAircraft->Update(gt);


	// // update scene graph with command queue
	// while (!cQueue.isEmpty())
	// {
	// 	// mPlayerAircraft->onCommand(cQueue.pop(), gt);
	// 	mSceneGraph->onCommand(cQueue.pop(), gt);
	// }

	// // mBackground->Update(gt);


}

void World::draw()
{
	mSceneGraph->draw();
}

void World::buildScene()
{
	// // Player
	// std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Eagle, mGame));
	// mPlayerAircraft = player.get();
	// mPlayerAircraft->setPosition(0.0f, 0.1f, -1.0f);
	// mPlayerAircraft->setScale(aircraftSize);
	// mSceneGraph->attachChild(std::move(player));

	// // Enemy
	// std::unique_ptr<Aircraft> enemy3(new Aircraft(Aircraft::Raptor, mGame));
	// auto raptor3 = enemy3.get();
	// raptor3->setPosition(0.5f, 0.1f, 1.0f);
	// raptor3->setScale(aircraftSize);
	// raptor3->setWorldRotation(0, XM_PI, 0);
	// mSceneGraph->attachChild(std::move(enemy3));


	// // Background
	// std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(&mGame));
	// mBackground = backgroundSprite.get();
	// mBackground->setPosition(0.0f, 0.0f, 0.0f);
	// mBackground->setScale(50.0, 1.0, 50.0);
	// mSceneGraph->attachChild(std::move(backgroundSprite));

	// // title
	// std::unique_ptr<TitleSprite> title(new TitleSprite(mGame));
	// auto title1 = title.get();
	// title1->setPosition(0.5f, 0.1f, 0.5f);
	// title1->setScale(2,2,2);
	// title1->setWorldRotation(0, 0, 0);
	// mSceneGraph->attachChild(std::move(title));


	// mSceneGraph->build();
}

CommandQueue& World::getCommandQueue()
{
	return cQueue;
}
