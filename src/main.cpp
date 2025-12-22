#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelEditorLayer.hpp>

bool dontFade = true;
bool dontEnter = true;
bool noGlow = false;
$execute{
	dontFade = Mod::get()->getSettingValue<bool>("dont-fade");
	listenForSettingChanges("dont-fade", [](bool value) {
		dontFade = value;
	});

	dontEnter = Mod::get()->getSettingValue<bool>("dont-enter");
	listenForSettingChanges("dont-enter", [](bool value) {
		dontEnter = value;
	});

	noGlow = Mod::get()->getSettingValue<bool>("no-glow");
	listenForSettingChanges("no-glow", [](bool value) {
		noGlow = value;
	});
}

class $modify(LevelEditorLayerHook, LevelEditorLayer) {
	GameObject* createObject(int key, CCPoint position, bool noUndo) {
		GameObject* object = LevelEditorLayer::createObject(key, position, noUndo);
		
		object->m_isDontFade = dontFade;
		object->m_isDontEnter = dontEnter;
		object->m_hasNoGlow = noGlow;

		return object;
	}
};