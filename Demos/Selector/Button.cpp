#include "Button.h"


//first, the constructor.
ButtonEntity::ButtonEntity(
	Tara::EntityNoRef parent, Tara::LayerNoRef owningLayer, 
	std::function<void(void)> onClick, 
	Tara::Transform transform, const std::string& name
)
//this bit is where the superconstructor is called, and default member values are set up
	: Tara::SpriteEntity(parent, owningLayer, transform, name, nullptr),
	m_ClickFunction(onClick)
{
	//this is the bit with the code.

	//set the sprite from a specific sprite in the asset library
	SetSprite(Tara::AssetLibrary::Get()->GetAssetIf<Tara::Sprite>("ButtonSprite"));
}

void ButtonEntity::OnBeginPlay()
{
	//auto-create a clickable component attatched to this entity.
	Tara::CreateComponent<Tara::ClickableComponent>(weak_from_this(), "Clickable");

	//get the default front (loaded in SelectorLayer.cpp) from the AssetManager
	auto font = Tara::AssetLibrary::Get()->GetAssetIf<Tara::Font>("DefaultFont");

	//create a default child
	Tara::CreateEntity<Tara::TextEntity>(weak_from_this(), GetOwningLayer(), font, GetName(), TRANSFORM_2D(0.05, 0.1, 0, 0.2f, 0.95f), "ButtonText");
}

void ButtonEntity::OnEvent(Tara::Event& e)
{
	//make an event filter object to parse the event
	Tara::EventFilter filter(e);
	//if the event is a ClickEvent, pass to the dedicated function.
	filter.Call<Tara::ClickEvent>(TARA_BIND_FN(ButtonEntity::OnClick));
}

bool ButtonEntity::OnClick(Tara::ClickEvent& e)
{
	//log the click event
	LOG_S(INFO) << e.ToString();

	//call the function
	m_ClickFunction();
	return true;
}
