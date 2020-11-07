#include <Siv3D.hpp>
#include "Define.hpp"
#include "TitleScene.hpp"
#include "GameScene.hpp"
#include "SettingScene.hpp"

void Main() {
	Scene::SetBackground(ColorF(0.8, 0.9, 1.0));
	Window::SetTitle(gameName + U" " + gameVersion);
	System::SetTerminationTriggers(UserAction::CloseButtonClicked);  // Escで終了しないようにする
	SceneMgr smgr;
	smgr
	    .add<TitleScene>(SceneState::Title)
	    .add<GameScene>(SceneState::Game)
	    .add<SettingScene>(SceneState::Setting)
	    .setFadeColor(ColorF(1.0));
	while(System::Update()) {
	}
}