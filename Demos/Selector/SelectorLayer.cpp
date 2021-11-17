#include "Selector/SelectorLayer.h"
#include "Selector/Button.h"
#include "Helpers.h"

SelectorLayer::SelectorLayer()
	: Tara::Layer()
{}

//the layer's activate function is generally where all the things are made
void SelectorLayer::Activate()
{
	//create a camera entity
	Tara::CameraEntityRef camera = Tara::CreateEntity<Tara::CameraEntity>(Tara::EntityNoRef(), weak_from_this(), Tara::Camera::ProjectionType::Ortographic, TRANSFORM_DEFAULT);
	//set its view area to have a width of 100 units.
	camera->SetOrthographicExtent(100); 
	//Tell the layer we are using this camera
	SetLayerCamera(camera);

	//load the font
	Tara::FontRef font = Tara::Font::Create("Assets/LiberationSans-Regular.ttf", 1024, 96, "DefaultFont");

	//load the button texture
	//note that if this is not the first time these assets are loaded, the saved copies in the AssetLibrary will be returned instead of loading from file.
	Tara::Texture2DRef buttonTexture = Tara::Texture2D::Create("Assets/Button.png", "ButtonTexture");
	Tara::SpriteRef buttonSprite = Tara::Sprite::Create(buttonTexture, 1, 1, "ButtonSprite"); //the name here is the same as in ButtonEntity's constructor, for loading this asset from the asset manager

	//create the buttons
	auto button1 = Tara::CreateEntity<ButtonEntity>(Tara::EntityNoRef(), weak_from_this(), [this]() {
		LayerSwitch("Basic", this->weak_from_this());
	}, TRANSFORM_2D(-8, 20, 0, 16, 4), "Basic Layer");

	auto button2 = Tara::CreateEntity<ButtonEntity>(Tara::EntityNoRef(), weak_from_this(), [this]() {
		LayerSwitch("Tilemap", this->weak_from_this());
	}, TRANSFORM_2D(-8, 12, 0, 16, 4), "Tilemap Layer");
}

void SelectorLayer::Deactivate()
{
}

