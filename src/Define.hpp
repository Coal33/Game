#pragma once
#include <Siv3D.hpp>

enum class SceneState {
	Title,
	Game,
	Setting,
};

using ll       = long long;
using SceneMgr = SceneManager<SceneState>;


static const String gameName     = U"GameName";  //ゲームの名前
static const String gameVersion  = U"v0.0.1";    //ゲームのバージョン名
static const int m_buildNumber   = 1;            //ビルド番号
static const String tweetMessage = U"";          //ツイートメッセージ


struct AbilityValues {
	int hitPoint;      //体力
	int attack;        //攻撃力
	int defence;       //防御力
	int intelligence;  //知能
	int resistance;    //抵抗値
	int speed;         //素早さ
	int avoidance;     //回避
};