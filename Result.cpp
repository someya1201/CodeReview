//===================================================================================================================================
//【Result.cpp】
// [作成者]HAL東京GP12A332 11 菅野 樹
// [作成日]2019/09/20
// [更新日]2019/09/23
//===================================================================================================================================

//===================================================================================================================================
//【インクルード】
//===================================================================================================================================
#include "Result.h"
#include "Sound.h"

//===================================================================================================================================
//【using宣言】
//===================================================================================================================================
using namespace resultNS;

//===================================================================================================================================
//【コンストラクタ】
//===================================================================================================================================
Result::Result(void)
{
	// 今のシーン( リザルト )
	sceneName = ("Scene -Result-");

	// 次のシーン( タイトル )
	nextScene = SceneList::TITLE;
}

//===================================================================================================================================
//【デストラクタ】
//===================================================================================================================================
Result::~Result(void)
{
	// サウンドの停止
	//sound->stop(soundNS::TYPE::BGM_RESULT);
}

//===================================================================================================================================
//【初期化】
//===================================================================================================================================
void Result::initialize()
{
	// サウンドの再生
	//sound->play(soundNS::TYPE::BGM_RESULT, soundNS::METHOD::LOOP);

	// Camera
	//camera = new Camera[PLAYER_TYPE::PLAYER_TYPE_MAX];

	//for (int i = 0; i < PLAYER_TYPE::PLAYER_TYPE_MAX; i++)
	//{
	//	camera[i].initialize(WINDOW_WIDTH, WINDOW_HEIGHT);
	//	//camera[i].setTarget(player[i].getPosition());
	//	//camera[i].setTargetX(&player[i].getAxisX()->direction);
	//	//camera[i].setTargetY(&player[i].getAxisY()->direction);
	//	//camera[i].setTargetZ(&player[i].getAxisZ()->direction);
	//	camera[i].setRelative(CAMERA_RELATIVE_QUATERNION[0]);
	//	camera[i].setGaze(D3DXVECTOR3(0, 0, 0));
	//	camera[i].setRelativeGaze(D3DXVECTOR3(0, 0, 0));
	//	camera[i].setUpVector(D3DXVECTOR3(0, 1, 0));
	//	camera[i].setFieldOfView(D3DX_PI / 2.5);
	//}

	// Light
	//light = new Light;
	//light->initialize(_direct3D9);

	// リザルトUIの初期化
	//uiResult.initialize(_direct3D9->device, _textureLoader, _textManager, gameMaster);

	// シーンエフェクト初期化
	//sceneEffect.initialize(_direct3D9->device, textureLoader, *shaderLoader->getEffect(shaderNS::INSTANCE_BILLBOARD));

	//リザルトUIの初期化
	resultUI.initialize();

}

//===================================================================================================================================
//【終了処理】
//===================================================================================================================================
void Result::uninitialize(void)
{
	resultUI.uninitialize();
}

//===================================================================================================================================
//【更新】
//===================================================================================================================================
void Result::update(float _frameTime)
{
	sceneTimer += _frameTime;
	frameTime = _frameTime;

	//UIの更新処理
	resultUI.update(frameTime);

	//リザルトフェイズが5の時のみ Enterまたは〇ボタンでタイトルへ
	if (resultUI.resultPhase == resultUiNS::PHASE_05&&
		input->wasKeyPressed(VK_RETURN) ||
		input->getController()[inputNS::DINPUT_1P]->wasButton(virtualControllerNS::A) ||
		input->getController()[inputNS::DINPUT_2P]->wasButton(virtualControllerNS::A))
	{
		// サウンドの再生
		//sound->play(soundNS::TYPE::SE_DECISION, soundNS::METHOD::PLAY);
		// シーン遷移
		changeScene(nextScene);
	}

}

//===================================================================================================================================
//【描画】
//===================================================================================================================================
void Result::render()
{
	//描画対象をウィンドウ全体に切替
	direct3D9->changeViewportFullWindow();

	//render3D(camera[PLAYER_TYPE::PLAYER_1]);

	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);			// αブレンドをつかう
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// αソースカラーの指定
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);	// αデスティネーションカラーの指定

	//UI
	renderUI();
}

//===================================================================================================================================
//【3D描画】
//===================================================================================================================================
//void Result::render3D(Camera _currentCamera)
//{
	// シーンエフェクトの描画
	//sceneEffect.render(direct3D9->device, _currentCamera.view, _currentCamera.projection, _currentCamera.position);

//}

//===================================================================================================================================
//【2D[UI]描画】
//===================================================================================================================================
void Result::renderUI()
{
	// リザルトUI
	resultUI.render();
}

//===================================================================================================================================
//【衝突処理】
//===================================================================================================================================
void Result::collisions(void)
{
	// None
}

//===================================================================================================================================
//【AI処理】
//===================================================================================================================================
void Result::AI(void)
{
	// None
}

//===================================================================================================================================
//【GUI作成処理】
//===================================================================================================================================
#ifdef _DEBUG
void Result::createGUI()
{
	ImGui::Text(sceneName.c_str());
	ImGui::Text("sceneTime = %f", sceneTimer);
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}
#endif // _DEBUG
