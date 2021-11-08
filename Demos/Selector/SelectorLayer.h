#pragma once
#include <Tara.h>

//a layer is almost a complete world object. The difference is that technically, there can be multiple layers loaded at once. 
class SelectorLayer : public Tara::Layer {
public:
	// basic constructor
	// Engine is not guaranteed to be fully loaded.
	// It normally is, but it is not guaranteed
	SelectorLayer();

	// virtual descrutor
	virtual ~SelectorLayer() {}

	// the activation function is called when the layer is loaded.
	// Engine is guaranteed to be fully loaded at this stage.
	void Activate();

	void Deactivate();
};
