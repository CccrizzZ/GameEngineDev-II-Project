#include "SpriteNode.h"
#include "Game.hpp"

// SpriteNode::SpriteNode(Game* game) : Entity(game)
// {
// 	backgroundSpeed = -0.0002f;
// }


SpriteNode::SpriteNode(State* state) : Entity(state)
{
	backgroundSpeed = -0.0002f;
	
}

void SpriteNode::drawCurrent() const
{
	renderer->World = getTransform();
	renderer->NumFramesDirty++;
}

void SpriteNode::buildCurrent()
{
	SpriteRenderer = std::make_unique<RenderItem>();
	renderer = SpriteRenderer.get();
	renderer->World = getTransform();
	XMStoreFloat4x4(&renderer->TexTransform, XMMatrixScaling(10.0f, 10.0f, 10.0f));
	renderer->ObjCBIndex = mState->getRenderItems().size();
	renderer->Mat = mState->getContext()->game->getMaterials()["Grass"].get();
	renderer->Geo = mState->getContext()->game->getGeometries()["boxGeo"].get();
	renderer->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = renderer->Geo->DrawArgs["box"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["box"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["box"].BaseVertexLocation;
	
	mState->getRenderItems().push_back(std::move(SpriteRenderer));
}

void SpriteNode::Update(const GameTimer gt)
{
	// move(0.0f, 0.0f, backgroundSpeed);
}

void SpriteNode::UpdateWithCmd(CommandQueue& commands)
{
	// Command moveDown;
	// moveDown.category = Category::Type::BackGround;
	// moveDown.action = BGMover(0.0f, 0.0f, -backgroundSpeed);
	// commands.push(moveDown);
}

void SpriteNode::SetGeoDrawName(string material, string geometry, string shape)
{

	SpriteRenderer = std::make_unique<RenderItem>();
	renderer = SpriteRenderer.get();
	renderer->World = getTransform();
	XMStoreFloat4x4(&renderer->TexTransform, XMMatrixScaling(10.0f, 10.0f, 10.0f));
	renderer->ObjCBIndex = mState->getRenderItems().size();
	// renderer->ObjCBIndex = 0;

	renderer->Mat = mState->getContext()->game->getMaterials()["Grass"].get();
	// renderer->Mat = game->getMaterials()[material].get();
	
	renderer->Geo = mState->getContext()->game->getGeometries()["boxGeo"].get();
	// renderer->Geo = game->getGeometries()[geometry].get();

	renderer->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	renderer->IndexCount = renderer->Geo->DrawArgs["box"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["box"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["box"].BaseVertexLocation;
	// renderer->IndexCount = renderer->Geo->DrawArgs[shape].IndexCount;
	// renderer->StartIndexLocation = renderer->Geo->DrawArgs[shape].StartIndexLocation;
	// renderer->BaseVertexLocation = renderer->Geo->DrawArgs[shape].BaseVertexLocation;

	
	
	mState->getRenderItems().push_back(std::move(SpriteRenderer));
}




