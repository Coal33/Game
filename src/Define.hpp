#pragma once
#include <Siv3D.hpp>

using ll = long long;
using SceneMgr = SceneManager<String>;

struct AbilityValues {
    int hitPoint;      //体力
    int attack;        //攻撃力
    int defence;       //防御力
    int intelligence;  //知能
    int resistance;    //抵抗値
    int speed;         //素早さ
    int avoidance;     //回避
};