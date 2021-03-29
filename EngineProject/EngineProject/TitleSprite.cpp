#include "TitleSprite.h"
#include "Game.hpp"


// TitleSprite::TitleSprite(Game* game) : Entity(game)
// {


// }


TitleSprite::TitleSprite(State* state) : Entity(state)
{


}


void TitleSprite::Update(const GameTimer gt)
{
}

void TitleSprite::UpdateWithCmd(CommandQueue& commands)
{
}

void TitleSprite::drawCurrent() const
{
    renderer->World = getTransform();
	renderer->NumFramesDirty++;
}

void TitleSprite::buildCurrent()
{
    // auto render = std::make_unique<RenderItem>();
	// renderer = render.get();
	// renderer->World = getTransform();
	// XMStoreFloat4x4(&renderer->TexTransform, XMMatrixScaling(10.0f, 10.0f, 10.0f));
	// renderer->ObjCBIndex = game->getRenderItems().size();
	// renderer->Mat = game->getMaterials()["Title"].get();
	// renderer->Geo = game->getGeometries()["boxGeo"].get();
	// renderer->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	// renderer->IndexCount = renderer->Geo->DrawArgs["box"].IndexCount;
	// renderer->StartIndexLocation = renderer->Geo->DrawArgs["box"].StartIndexLocation;
	// renderer->BaseVertexLocation = renderer->Geo->DrawArgs["box"].BaseVertexLocation;

	// game->getRenderItems().push_back(std::move(render));
}
