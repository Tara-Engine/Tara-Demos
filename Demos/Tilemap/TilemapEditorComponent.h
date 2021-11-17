#pragma once
#include <Tara.h>
#include <random>

/// <summary>
/// This is a custom component intended for user editing of the tilemap it is attached to. It assumes it is attached to a Tara::TilemapEntity
/// 
/// This entity mostly deals with events, particularly OnClick events.
/// </summary>
class TilemapEditorComponent : public Tara::Component {
public:

	/// <summary>
	/// the constructor. Use Tara::CreateComponent instead
	/// </summary>
	/// <param name="parent">the parent entity</param>
	/// <param name="name">the name of the component</param>
	TilemapEditorComponent(Tara::EntityNoRef parent, uint32_t tileRangeStart = 0, uint32_t tileRangeEnd = 0, const std::string& name = "TilemapEditorComponent");

	//default destructor
	virtual ~TilemapEditorComponent() = default;

	virtual void OnBeginPlay() { ListenForEvents(true); }

	/// <summary>
	/// The event handler function.
	/// </summary>
	/// <param name="e"></param>
	virtual void OnEvent(Tara::Event& e) override;

private:

	bool OnClick(Tara::MouseButtonPressEvent& e);

private:
	/// <summary>
	/// The start of the range to randomly pick a tile from (inclusive)
	/// </summary>
	uint32_t m_TileRangeStart;
	/// <summary>
	/// the end of the range to randomly pick a tile from (inclusive)
	/// </summary>
	uint32_t m_TileRangeEnd;

	std::mt19937 m_IntGenerator;
	std::uniform_int_distribution<uint32_t> m_IntDistributer;
public:
	/// <summary>
	/// The layer the tiles should be written to.
	/// This is public because I might want to change it at runtime but am too lazy to write proper protections
	/// </summary>
	int32_t m_TargetLayer;
};