/*
Welcome to the Tara Game Template code file!

This code file does 2 simple things: 
	1: it makes a really quick and empty subclass of Tara::Layer, 
	2: it makes a main function where the Engine is initialized and run

This is intended to be a "start from here" project, you should probably change nearly all settings, names, etc.
*/

#include <Tara.h>

//a layer is almost a complete world object. The difference is that technically, there can be multiple layers loaded at once. 
class DemoLayer : public Tara::Layer {
public:
	// basic constructor
	// Engine is not guaranteed to be fully loaded.
	// It normally is, but it is not guaranteed
	DemoLayer() {}

	// virtual descrutor
	virtual ~DemoLayer() {}

	// the activation function is called when the layer is loaded.
	// Engine is guaranteed to be fully loaded at this stage.
	void Activate() {

		//Here is where you should create entities and components.

		//make sure to make a Tara::CameraEntity, and then pass it to SetLayerCamera() to set this layer's default camera
		//if you don't you will not get anything rendering!
		
	}

	// run when the layer is removed. 
	/*
	void Deactivate() {}
	*/

	// Layer's Update function. Called every frame. If you want Entities in the layer to be updated, make sure to call
	// Layer::Update. Or just don't override.
	/*
	void Update(float deltaTime) {
		Layer::Update(deltaTime);
	};
	*/

	// Layer's Draw function. Called every frame. If you want Entities in the layer to be drawn, make sure to call
	// Layer::Draw. Or, more likely, don't override. This one you are likely not to need to.
	/*
	void Draw(float deltaTime) {
		Layer::Draw(deltaTime);
	}
	*/

	// Layer's Event function. Used for handling native window events. This Does not receive game events. 
	// If you want Entities to recieve events as per default behavior (IE, they can choose to listen for them),
	// make sure to call Layer::OnEvent. Again, you are not likely going to need to override.
	/*
	void OnEvent(Tara::Event& e) {
		Layer::OnEvent(e);
	}
	*/
};





//Our main function, where the engine is intitialized
int main(int argc, char** argv) {

	//first, Tell the script system where to find the script libaries (this will also create the script system, and initialize part of it. The bare minimum.)
	//the path here is relative to the current system path (when running through VS, the project directory), 
	//so, if you change the project structure, you will have to change this
	Tara::Script::Get()->SetDefaultLibraryPath("../Vendor/Tara/Tara/lua"); 

	//next, initialize the engine
	//This will create a window for you
	Tara::Application::Get()->Init(1200, 700, "Tara Template Project");

	//now, the engine is fully loaded!
	//we just need to add our demo layer. Sure, it does not render anything, but that is OK.
	Tara::Application::Get()->GetScene()->PushLayer(std::make_shared<DemoLayer>());

	//now that our scene (and layers) are set up, run the game loop!
	Tara::Application::Get()->Run();
}