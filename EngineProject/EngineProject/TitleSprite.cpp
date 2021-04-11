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
	SpriteRenderer = std::make_unique<RenderItem>();
	renderer = SpriteRenderer.get();
	renderer->World = getTransform();
	XMStoreFloat4x4(&renderer->TexTransform, XMMatrixScaling(1.0f, 1.0f, 1.0f));
	renderer->ObjCBIndex = mState->getRenderItems().size();
	renderer->Mat = mState->getContext()->game->getMaterials()[TextureName].get();
	renderer->Geo = mState->getContext()->game->getGeometries()["boxGeo"].get();
	renderer->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = renderer->Geo->DrawArgs["box"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["box"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["box"].BaseVertexLocation;
	
	mState->getRenderItems().push_back(std::move(SpriteRenderer));
}

