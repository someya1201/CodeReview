//===================================================================================================================================
//�yResult.h�z
// [�쐬��]HAL����GP12A332 11 ���� ��
// [�쐬��]2019/09/20
// [�X�V��]2019/09/23
//===================================================================================================================================
#pragma once

//===================================================================================================================================
//�y�C���N���[�h�z
//===================================================================================================================================
#include "AbstractScene.h"
#include "ResultUI.h"
//#include "Sprite.h"
//#include "UIResult.h"
//#include "SceneEffect.h"

//===================================================================================================================================
//�y���O��ԁz
//===================================================================================================================================
namespace resultNS
{
	const D3DXQUATERNION CAMERA_RELATIVE_QUATERNION =	D3DXQUATERNION(0.0f, 20.0f, -40.0f, 0.0f);
}

//===================================================================================================================================
//�y���U���g�V�[���N���X�z
//===================================================================================================================================
class Result :public AbstractScene
{
private:
	ResultUI resultUI;

public:
	Result(void);
	~Result(void);
	virtual void initialize() override;
	virtual void uninitialize(void) override;
	virtual void update(float _frameTime) override;
	virtual void render() override;
	virtual void collisions(void) override;
	virtual void AI(void) override;

	//void render3D(Camera _currentCamera);
	void renderUI();

#ifdef _DEBUG
	virtual void createGUI() override;
#endif
};