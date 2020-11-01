#include <Siv3D.hpp>

void Main() {
    Scene::SetBackground(ColorF(0.8, 0.9, 1.0));

    const Font font(60);
    const Texture unko(Emoji(U"💩"));

    Vec2 catPos(640, 450);

    while(System::Update()) {
        font(U"Hello, Siv3D!🐣").drawAt(Scene::Center(), Palette::Black);

        unko.resized(100 + Periodic::Sine0_1(1s) * 20).drawAt(catPos);

        Circle(Cursor::Pos(), 40).draw(ColorF(1, 0, 0, 0.5));

        if(KeyA.down()) {
            Print << U"Hello!";
        }

        if(SimpleGUI::Button(U"Move the Unko", Vec2(600, 20))) {
            catPos = RandomVec2(Scene::Rect());
        }
    }
}