#include <Siv3D.hpp>

void Main() {
    Window::Resize(640, 480);
    constexpr ColorF background(0.6, 0.8, 0.7);
    Scene::SetBackground(background);

    constexpr Ellipse buttonLB(160, 140, 50, 24);
    constexpr Ellipse buttonRB(520, 140, 50, 24);

    constexpr RectF leftTrigger(150, 16, 40, 100);
    constexpr RectF rightTrigger(500, 16, 40, 100);

    constexpr Circle buttonLThumb(170, 250, 35);
    constexpr Circle buttonRThumb(420, 350, 35);
    constexpr Circle buttonDPad(260, 350, 40);

    constexpr Circle buttonA(510, 300, 20);
    constexpr Circle buttonB(560, 250, 20);
    constexpr Circle buttonX(460, 250, 20);
    constexpr Circle buttonY(510, 200, 20);
    constexpr Circle buttonBack(270, 250, 15);
    constexpr Circle buttonStart(410, 250, 15);

    // ユーザインデックス (0 - 3)
    size_t userIndex = 0;

    // デッドゾーンの有効無効
    bool deadZone = false;

    // 振動 (0.0 - 1.0)
    double leftV = 0.0, rightV = 0.0;

    while(System::Update()) {
        // 指定したユーザインデックスの XInput コントローラを取得
        auto controller = XInput(userIndex);

        if(deadZone) {
            controller.setLeftTriggerDeadZone();
            controller.setRightTriggerDeadZone();
            controller.setLeftThumbDeadZone();
            controller.setRightThumbDeadZone();
        } else {
            controller.setLeftTriggerDeadZone(DeadZone::Disabled());
            controller.setRightTriggerDeadZone(DeadZone::Disabled());
            controller.setLeftThumbDeadZone(DeadZone::Disabled());
            controller.setRightThumbDeadZone(DeadZone::Disabled());
        }

        // 振動
        controller.setVibration(leftV, rightV);

        buttonLB.draw(ColorF(controller.buttonLB.pressed() ? 1.0 : 0.7));
        buttonRB.draw(ColorF(controller.buttonRB.pressed() ? 1.0 : 0.7));

        Ellipse(340 + 3.0 * Random(leftV + rightV), 480, 300, 440)
            .draw(ColorF(0.9));
        Ellipse(340, 40, 220, 120).draw(background);
        Circle(340, 660, 240).draw(background);

        Circle(340, 250, 30).draw(ColorF(0.6));

        // コントローラの接続の有無
        if(controller.isConnected()) {
            Circle(340, 250, 32)
                .drawPie(-0.5_pi + 0.5_pi * controller.userIndex, 0.5_pi,
                         ColorF(0.7, 1.0, 0.5));
        }

        Circle(340, 250, 25).draw(ColorF(0.6));

        leftTrigger.draw(AlphaF(0.25));
        leftTrigger
            .stretched((controller.leftTrigger - 1.0) * leftTrigger.h, 0, 0, 0)
            .draw();

        rightTrigger.draw(AlphaF(0.25));
        rightTrigger
            .stretched((controller.rightTrigger - 1.0) * rightTrigger.h, 0, 0,
                       0)
            .draw();

        buttonLThumb.draw(
            ColorF(controller.buttonLThumb.pressed() ? 0.85 : 0.5));
        Circle(buttonLThumb.center +
                   Vec2(controller.leftThumbX, -controller.leftThumbY) * 25,
               20)
            .draw();

        buttonRThumb.draw(
            ColorF(controller.buttonRThumb.pressed() ? 0.85 : 0.5));
        Circle(buttonRThumb.center +
                   Vec2(controller.rightThumbX, -controller.rightThumbY) * 25,
               20)
            .draw();

        buttonDPad.draw(ColorF(0.5));

        const Vec2 direction(
            controller.buttonRight.pressed() - controller.buttonLeft.pressed(),
            controller.buttonDown.pressed() - controller.buttonUp.pressed());

        if(!direction.isZero()) {
            Circle(buttonDPad.center + direction.normalized() * 25, 15).draw();
        }

        buttonA.draw(ColorF(0.0, 1.0, 0.3)
                         .setA(controller.buttonA.pressed() ? 1.0 : 0.3));
        buttonB.draw(ColorF(1.0, 0.0, 0.3)
                         .setA(controller.buttonB.pressed() ? 1.0 : 0.3));
        buttonX.draw(ColorF(0.0, 0.3, 1.0)
                         .setA(controller.buttonX.pressed() ? 1.0 : 0.3));
        buttonY.draw(ColorF(1.0, 0.5, 0.0)
                         .setA(controller.buttonY.pressed() ? 1.0 : 0.3));

        buttonBack.draw(ColorF(controller.buttonBack.pressed() ? 1.0 : 0.7));
        buttonStart.draw(ColorF(controller.buttonStart.pressed() ? 1.0 : 0.7));

        SimpleGUI::RadioButtons(userIndex, {U"1P", U"2P", U"3P", U"4P"},
                                Vec2(10, 10));
        SimpleGUI::CheckBox(deadZone, U"DeadZone", Vec2(240, 10));
        SimpleGUI::Slider(U"left", leftV, Vec2(240, 50));
        SimpleGUI::Slider(U"right", rightV, Vec2(240, 90));
    }
}