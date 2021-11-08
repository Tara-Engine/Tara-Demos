/*
Welcome to the Tara Demos!

This file does not do much, it does not even have a layer. However, it Does load the default Demo Selector layer and initialize the Engine
*/

//include Tara
#include <Tara.h>

//helper stuff
#include "Helpers.h"

//the various layers
#include "Selector/SelectorLayer.h"
#include "Basic/BasicLayer.h"




//Our main function, where the engine is intitialized
int main(int argc, char** argv) {

	//first, Tell the script system where to find the script libaries (this will also create the script system, and initialize part of it. The bare minimum.)
	//the path here is relative to the current system path (when running through VS, the project directory), 
	//so, if you change the project structure, you will have to change this
	Tara::Script::Get()->SetDefaultLibraryPath("../Vendor/Tara/Tara/lua"); 

	//next, initialize the engine
	//This will create a window for you
	Tara::Application::Get()->Init(1200, 700, "Tara Demos");

	//now, the engine is fully loaded!
	//we just need to add our demo layer. Sure, it does not render anything, but that is OK.
	Tara::Application::Get()->GetScene()->PushLayer(std::make_shared<SelectorLayer>());

	//now that our scene (and layers) are set up, run the game loop!
	Tara::Application::Get()->Run();
}

//implement that stuff from Helpers.h
void LayerSwitch(const std::string& newLayerName, Tara::LayerNoRef currentLayer)
{
	if (newLayerName == "Selector") {
		Tara::Application::Get()->GetScene()->PushLayer(std::make_shared<SelectorLayer>());
	}
	else if (newLayerName == "Basic") {
		Tara::Application::Get()->GetScene()->PushLayer(std::make_shared<BasicLayer>());
	}
	else {
		LOG_S(WARNING) << "Attempted to switch to unknown layer: " << newLayerName;
		return; //make sure not to unload current layer
	}
	if (currentLayer.lock()) {
		Tara::Application::Get()->GetScene()->RemoveLayer(currentLayer.lock());
	}
}