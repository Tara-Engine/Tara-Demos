#include "Selector/SelectorLayer.h"
#include "Helpers.h"

SelectorLayer::SelectorLayer()
	: Tara::Layer()
{}

//the layer's activate function is generally where all the things are made
void SelectorLayer::Activate()
{
	//create a camera entity
	//A ScreenCamera is chosen, as it is used for UI. Its worldspace coordinates match device pixel coordinates exactly. It is the only camera with Y pointing down.
	Tara::CameraEntityRef camera = Tara::CreateEntity<Tara::CameraEntity>(Tara::EntityNoRef(), weak_from_this(), Tara::Camera::ProjectionType::Screen, TRANSFORM_DEFAULT);
	//Tell the layer we are using this camera
	SetLayerCamera(camera);

	//load the font
	Tara::FontRef font = Tara::Font::Create("Assets/LiberationSans-Regular.ttf", 1024, 96, "DefaultFont");

	//load the button texture
	//note that if this is not the first time these assets are loaded, the saved copies in the AssetLibrary will be returned instead of loading from file.
	//Three textures are loaded, for normal, hovered, and pressed button states. Disabled state is ignored, as these will not be disabled.
	Tara::Texture2DRef buttonTextureNormal = Tara::Texture2D::Create("Assets/Button.png", "ButtonTextureNormal");
	//A patch is a section of 9 areas, the outer ones do not stretch on the axis perpendicular to their side.
	//IE, corners do not stretch at all, and the middle top piece will not stretch vertically but will stretch horizontally. THe center stretches all ways
	//this allows for scaling without border stretching on UI elements
	Tara::PatchRef buttonPatchNormal = Tara::Patch::Create(buttonTextureNormal, "ButtonPatchNormal");
	//Set the unstretched border area, via pixels.
	buttonPatchNormal->SetBorderPixels(4, 4, 4, 4);

	Tara::Texture2DRef buttonTextureHover = Tara::Texture2D::Create("Assets/Button_Hover.png", "ButtonTextureHover");
	Tara::PatchRef buttonPatchHover = Tara::Patch::Create(buttonTextureHover, "ButtonPatchHover");
	buttonPatchHover->SetBorderPixels(4, 4, 4, 4);

	Tara::Texture2DRef buttonTexturePress = Tara::Texture2D::Create("Assets/Button_Pressed.png", "ButtonTexturePress");
	Tara::PatchRef buttonPatchPress = Tara::Patch::Create(buttonTexturePress, "ButtonPatchPress");
	buttonPatchPress->SetBorderPixels(4, 4, 4, 4);

	//create the UI

	//a base UI to be the root. Fills the screen by default, and resizes to it.
	Tara::UIBaseEntityRef base = Tara::CreateEntity<Tara::UIBaseEntity>(Tara::EntityNoRef(), weak_from_this(), "UIBaseEntity");

	//A list that sits at the center of the screen, to hold our buttons.
	Tara::UIListEntityRef list = Tara::CreateEntity<Tara::UIListEntity>(base, PARENT_LAYER, "UIListEntity");
	//Snap Rules are a bitmask that controls where in its available area it will snap to. There should be at least one vertical and horizontal bit set.
	//multiple bits per axis (ie, TOP | BOTTOM) will cause it to stretch to fill the space.
	list->SetSnapRules(Tara::UISnapRule::CENTER_HORIZONTAL| Tara::UISnapRule::CENTER_VERTICAL);
	//vertical spacing between elements is 25 pixels
	list->SetSpacing(0, 25);

	//create the first button. it is a child of the list. It fills its space
	Tara::UIButtonEntityRef button1 = Tara::CreateEntity<Tara::UIButtonEntity>(list, PARENT_LAYER, buttonPatchNormal, buttonPatchHover, buttonPatchPress, nullptr);
	button1->SetSnapRules(Tara::UISnapRule::TOP | Tara::UISnapRule::LEFT );
	//UIVisualEntity and its subclasses can set its internal border to match the unstretched part of the patch.
	//children will not be drawn over this border.
	button1->SetBorderFromPatch();

	//create a spacer to enforce button size
	Tara::UISpacerEntityRef spacer1 = Tara::CreateEntity<Tara::UISpacerEntity>(button1, PARENT_LAYER);
	//UISpacerEntity can have its minimum size set
	spacer1->SetSize(200, 50);
	

	//create some text for the button. It is centered on its space
	Tara::UITextEntityRef text1 = Tara::CreateEntity<Tara::UITextEntity>(button1, PARENT_LAYER, font);
	text1->SetSnapRules(Tara::UISnapRule::CENTER_HORIZONTAL | Tara::UISnapRule::CENTER_VERTICAL);
	//UITextEntities can have their text, and its pixel size, set.
	text1->SetText("Basic");
	text1->SetTextSize(24);

	//create a lambdaComponent to make the button do things
	//the lambda component takes three lambda functions (or std::function objecs).
	//the first is run on begin play, the second is run every update, the third is run every event.
	//we are only interested in every event, so the other two are left as their macro defaults
	Tara::CreateComponent<Tara::LambdaComponent>(button1, LAMBDA_BEGIN_PLAY_DEFAULT, LAMBDA_UPDATE_DEFAULT,
		//make sure we capture this 
		[this](Tara::LambdaComponent* self, Tara::Event& e) {
			Tara::EventFilter filter(e);
			//the event filter can also take a lambda. make sure to capture this
			filter.Call<Tara::UIToggleEvent>([this](Tara::UIToggleEvent& ee) {
				LayerSwitch("Basic", this->weak_from_this());
				return true;
			});
		}
	);
	
	
	//create the second button. it is a child of the list. It fills its space
	Tara::UIButtonEntityRef button2 = Tara::CreateEntity<Tara::UIButtonEntity>(list, PARENT_LAYER, buttonPatchNormal, buttonPatchHover, buttonPatchPress, nullptr);
	button2->SetSnapRules(Tara::UISnapRule::TOP | Tara::UISnapRule::LEFT);
	button2->SetBorderFromPatch();

	//create a sizer to enforce button size
	Tara::UISpacerEntityRef spacer2 = Tara::CreateEntity<Tara::UISpacerEntity>(button2, PARENT_LAYER);
	spacer2->SetSize(200, 50);


	//create some text for the button. It is centered on its space
	Tara::UITextEntityRef text2 = Tara::CreateEntity<Tara::UITextEntity>(button2, PARENT_LAYER, font);
	text2->SetSnapRules(Tara::UISnapRule::CENTER_HORIZONTAL | Tara::UISnapRule::CENTER_VERTICAL);
	text2->SetText("Tilemap");
	text2->SetTextSize(24);

	//create a lambdaComponent to make the button do things
	Tara::CreateComponent<Tara::LambdaComponent>(button2, LAMBDA_BEGIN_PLAY_DEFAULT, LAMBDA_UPDATE_DEFAULT,
		[this](Tara::LambdaComponent* self, Tara::Event& e) {
			Tara::EventFilter filter(e);
			filter.Call<Tara::UIToggleEvent>([this, self](Tara::UIToggleEvent& ee) {
				LayerSwitch("Tilemap", this->weak_from_this());
				return true;
				});
		}
	);
}

void SelectorLayer::Deactivate()
{
}

