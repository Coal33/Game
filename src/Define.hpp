#pragma once
#include <Siv3D.hpp>

using ll = long long;
using SceneMgr = SceneManager<String>;

String GameName = U"GameName";   //ゲームの名前
String GameVersion = U"v0.0.1";  //ゲームのバージョン名
int buildNumber = 1;             //ビルド番号

struct AbilityValues {
    int hitPoint;      //体力
    int attack;        //攻撃力
    int defence;       //防御力
    int intelligence;  //知能
    int resistance;    //抵抗値
    int speed;         //素早さ
    int avoidance;     //回避
};