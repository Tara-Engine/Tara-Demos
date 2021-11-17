#include "TilemapLayer.h"
#include "Helpers.h"

#include "Tilemap/TilemapEditorComponent.h"

TilemapLayer::TilemapLayer()
	: Tara::Layer()
{}

TilemapLayer::~TilemapLayer()
{
	Deactivate();
}

void TilemapLayer::Activate()
{
	//open a tileset json file. Ensure that the string inside it is relative to the working directory, not relative to the json file itself.
	Tara::TilesetRef tilesetTerrain = Tara::Tileset::Create("Assets/Tileset_Terrain.json", "tileset_terrain");

	//create a tileset from a texture
	Tara::Texture2DRef imageProps = Tara::Texture2D::Create("Assets/Tileset_Props.png", "tileset_props_image");
	Tara::TilesetRef tilesetProps = Tara::Tileset::Create(imageProps, 16, 16, 0, 0, "tileset_props");
	
	//make a tilemap entity
	Tara::TilemapEntityRef tilemapEntity = Tara::CreateEntity<Tara::TilemapEntity>(
		Tara::EntityNoRef(), weak_from_this(),
		std::initializer_list{tilesetTerrain, tilesetProps},
		TRANSFORM_DEFAULT, "Tilemap Entity"
	);

	//now, fill that tilemap's data from a json file
	tilemapEntity->FillFromJson("assets/Tilemap.json");
	
	//add a new layer (index 3)
	tilemapEntity->PushLayer(); 
	
	//attach a component to the tilemap to edit it with clicks.
	auto editor = Tara::CreateComponent<TilemapEditorComponent>(tilemapEntity, 32, 35, "tilemap editor");
	editor->m_TargetLayer = 3;


	//create a camera and attach a playercontroller to it
	Tara::CameraEntityRef camera = Tara::CreateEntity<Tara::CameraEntity>(Tara::EntityNoRef(), weak_from_this(), Tara::Camera::ProjectionType::Ortographic, TRANSFORM_DEFAULT);
	camera->SetOrthographicExtent(16); //set the camera to view an area 16 units wide (that will be 16 tiles in the tilemap!)

	//Tell the layer we want to use this camera for rendering
	SetLayerCamera(camera);

	//The player needs movement controls.
	Tara::ScriptComponentRef playerController = Tara::CreateComponent<Tara::ScriptComponent>(camera, "assets/PlayerController.lua", "playerController");


}

void TilemapLayer::Deactivate()
{
}

void TilemapLayer::OnEvent(Tara::Event& e)
{
	//make sure to keep default behavior
	Layer::OnEvent(e);

	//if we press esc, then go back to the demo selector layer.
	//this call to filter uses a lambda function. See Selector/Button.cpp for a version that uses a class function.
	Tara::EventFilter filter(e);
	filter.Call<Tara::KeyPressEvent>([this](Tara::KeyPressEvent& ee) {
		if (ee.GetKey() == TARA_KEY_ESCAPE) {
			LayerSwitch("Selector", this->weak_from_this());
			return true;
		}
		return false;
	});


}

