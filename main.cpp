#include <Novice.h>
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"

const char kWindowTitle[] = "GC1B_04_ゴ_タクウ";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	int bg = Novice::LoadTexture("./bg.png");

	Scene* scene = new Scene();
	Player* player = new Player;
	Enemy* enemy[5];

	enemy[0] = new Enemy(100, 100, 12, 2);
	enemy[1] = new Enemy(300, 230, 17, 5);
	enemy[2] = new Enemy(550, 290, 21, 7);
	enemy[3] = new Enemy(620, 440, 24, 14);
	enemy[4] = new Enemy(980, 540, 30, 10);

	bool isPlayerAlive = player->getIsPlayerAlive();
	//int currentScene = scene->getCurrentScene();
	//Bullet* bullet = new Bullet;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		/// 
		switch (scene->getCurrentScene()) {
		case 0:

			if (keys[DIK_SPACE]) {
				scene->SceneUpdate();
			}

			break;
		case 1:
			if (isPlayerAlive) {
				player->Update(keys, preKeys);
			}

			for (int i = 0; i < 5; i++) {
				if (enemy[i]->Enemy_.isEnemyAlive) {
					enemy[i]->Update();
				}
			}

			for (int i = 0; i < 5; i++) {
				if ((enemy[i]->Enemy_.posX - player->_Bullet_->Bullet_.posX) * (enemy[i]->Enemy_.posX - player->_Bullet_->Bullet_.posX)
					+ (enemy[i]->Enemy_.posY - player->_Bullet_->Bullet_.posY) * (enemy[i]->Enemy_.posY - player->_Bullet_->Bullet_.posY)
					<= (enemy[i]->Enemy_.radius + player->_Bullet_->Bullet_.radius) * (enemy[i]->Enemy_.radius + player->_Bullet_->Bullet_.radius)
					&& enemy[i]->Enemy_.isEnemyAlive) {
					enemy[i]->Enemy_.isEnemyAlive = false;
				}

				if ((enemy[i]->Enemy_.posX - player->getPlayerPosX()) * (enemy[i]->Enemy_.posX - player->getPlayerPosX())
					+ (enemy[i]->Enemy_.posY - player->getPlayerPosY()) * (enemy[i]->Enemy_.posY - player->getPlayerPosY())
					<= (enemy[i]->Enemy_.radius + player->getPlayerRadius()) * (enemy[i]->Enemy_.radius + player->getPlayerRadius())
					&& enemy[i]->Enemy_.isEnemyAlive && isPlayerAlive) {
					isPlayerAlive = false;
				}
			}


			if (keys[DIK_R]) {
				for (int i = 0; i < 5; i++) {
					if (!enemy[i]->Enemy_.isEnemyAlive) {
						enemy[i]->Enemy_.isEnemyAlive = true;
					}
				}
				isPlayerAlive = player->getIsPlayerAlive();
			}
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scene->getCurrentScene()) {
		case 0:
			Novice::ScreenPrintf(10, 10, "press SPACE to start");
			Novice::ScreenPrintf(10, 30, "%d", scene->getCurrentScene());
			Novice::DrawSprite(0, 0, bg, 1, 1, 0, WHITE);
			break;
		case 1:
			if (isPlayerAlive) {
				player->Draw();
			}

			for (int i = 0; i < 5; i++) {
				if (enemy[i]->Enemy_.isEnemyAlive) {
					enemy[i]->Draw();
				}
			}
			Novice::ScreenPrintf(10, 30, "%d", scene->getCurrentScene());
			break;
		}



		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
