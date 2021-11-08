#pragma once
#include <Tara.h>

/*
* This Button entity is a good example of an entity that automatically makes children for itself.
* It is also a good example of a UI tool. Eventually, the engine itself will have something like this, but better.
*/

/// <summary>
/// The ButtonEntity class. It is based on Tara::Sprite
/// </summary>
class ButtonEntity : public Tara::SpriteEntity {
public:

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="parent">the parent entity</param>
	/// <param name="owningLayer">the owning layer</param>
	/// <param name="onClick">a void(void) function that must be supplied to be called every click</param>
	/// <param name="transform">the transform, defaults to TRANSFORM_DEFAULT</param>
	/// <param name="name">the name, defaults to "Button"</param>
	ButtonEntity(Tara::EntityNoRef parent, Tara::LayerNoRef owningLayer,
		std::function<void(void)> onClick,
		Tara::Transform transform = TRANSFORM_DEFAULT,
		const std::string& name = "Button"
	);

	/// <summary>
	/// Basic destructor
	/// </summary>
	virtual ~ButtonEntity() {};

	/// <summary>
	/// OnBeginPlay runs as part of creation, once added to the scene tree
	/// </summary>
	virtual void OnBeginPlay() override;

	/// <summary>
	/// OnEvent runs for every event the entity receives.
	/// </summary>
	/// <param name="e"></param>
	virtual void OnEvent(Tara::Event& e) override;

	virtual bool OnClick(Tara::ClickEvent& e);

private:
	std::function<void(void)> m_ClickFunction;

};