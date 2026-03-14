#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelEditorLayer.hpp>

bool dontFade = false;
bool dontEnter = false;
bool noGlow = true;


// Credit to @rgc-exists for the optimizations.
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
	GameObject* createObject(int key, cocos2d::CCPoint position, bool noUndo) {
		GameObject* object = LevelEditorLayer::createObject(key, position, noUndo);

		object->m_hasNoGlow = noGlow;
		object->m_isDontFade = dontFade;
		object->m_isDontEnter = dontEnter;

        return object;
    }
};
