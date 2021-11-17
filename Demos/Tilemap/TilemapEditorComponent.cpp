#include "TilemapEditorComponent.h"
#include <random>

TilemapEditorComponent::TilemapEditorComponent(Tara::EntityNoRef parent, uint32_t tileRangeStart, uint32_t tileRangeEnd, const std::string& name)
	: Tara::Component(parent, name),
	m_TileRangeStart(tileRangeStart),
	m_TileRangeEnd(tileRangeEnd),
	m_TargetLayer(0),
	m_IntGenerator(std::random_device()()), //initialize with a random device seed. 
											//Yes, that is two parenthesis. The first is for the constructor, 
											//the second is the overloaded operator() on the reusulting object
	m_IntDistributer(tileRangeStart, tileRangeEnd)	//Make the int distributer tool
{}

void TilemapEditorComponent::OnEvent(Tara::Event & e)
{
	//quickly just pass clicks to the OnClick component
	//the reason that the MouseButtonPressEvent is used is because of 2 reasons:
	// 1. At the point when I am writing this, Tilemaps do not have a specific bounding box, and thus will not respond to OnClick
	// 2. Even if they did, that would only work if their specific bounding box was infinite, as you should be able to click anywhere and add a tile.
	Tara::EventFilter filter(e);
	filter.Call<Tara::MouseButtonPressEvent>(TARA_BIND_FN(TilemapEditorComponent::OnClick));
}

bool TilemapEditorComponent::OnClick(Tara::MouseButtonPressEvent& e)
{
	auto parent = std::dynamic_pointer_cast<Tara::TilemapEntity>(GetParent().lock());
	if (parent) {
		//we have a parent!

		//get the mouse pos on the screen
		glm::vec2 mousepos = Tara::Input::Get()->GetMousePos();
		
		//try and get a camera
		Tara::CameraEntityRef camEntity = parent->GetOwningLayer().lock()->GetLayerCamera().lock();
		if (camEntity) {

			//get the mouse pos in the world using the camera
			std::pair<Tara::Vector, Tara::Vector> ray = camEntity->GetCamera()->GetRayFromScreenCoordinate(mousepos.x, mousepos.y);

			//now, we have the world location of the click. Translate that to be within the parent's transform
			//well, sort of. We will assume that the parent's global transform is TRANSFORM_DEFAULT. Because doing anything else would require lots of math
			
			int32_t tileX = (int32_t)floorf(ray.first.x);
			int32_t tileY = (int32_t)floorf(ray.first.y);


			//if there is no tile, set one. Otherwise, remove it!
			if (parent->GetTile(tileX, tileY, m_TargetLayer) == Tara::TilemapEntity::NO_TILE) {
				//use the distributer and generator together to get an int in the range. Range is set up in constructor
				uint32_t tile = m_IntDistributer(m_IntGenerator); 

				//set the tile. This is the faster function call, but does not change cell metadata.
				//we are not using cell metadata, so its better to use this.
				parent->SwapTile(tileX, tileY, m_TargetLayer, tile);
			}
			else {
				//set the cell to empty.
				parent->SwapTile(tileX, tileY, m_TargetLayer, Tara::TilemapEntity::NO_TILE);
			}

		}


	}
	return false;
}
