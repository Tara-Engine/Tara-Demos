#pragma once
#include <Tara.h>

class TilemapLayer : public Tara::Layer {
public:
	/// <summary>
	/// Constructor
	/// </summary>
	TilemapLayer();

	/// <summary>
	/// Destructor
	/// </summary>
	virtual ~TilemapLayer();

	/// <summary>
	/// Activattion function, called when layer is added to scene.
	/// graphics context and all engine systems are guaranteed to be running
	/// </summary>
	virtual void Activate() override;

	/// <summary>
	/// Deactivation function, called when layer is removed from scene.
	/// </summary>
	virtual void Deactivate() override;

	/// <summary>
	/// Event handler. Called for every window event.
	/// No need to override. If you do, make sure to call Layer::OnEvent(e)
	/// </summary>
	/// <param name="e"></param>
	virtual void OnEvent(Tara::Event& e) override;

private:

};