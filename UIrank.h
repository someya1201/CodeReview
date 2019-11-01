//============================
//[UIrank.h]
// ����@�W��
//============================

//============================
//�C���N���[�h
//============================
#include "Sprite.h"
#include "TextureLoader.h"
#include "Input.h"

//============================
//���O��� �萔
//============================
namespace uiRankNS
{
	//�����N�̎��
	enum UIRANK_TYPE
	{
		EXCELLENT,
		GREAT,
		CLEARE,
		FAILED,
		RANK_MAX,
	};

	//�����N�̕\���ʒu
	const int WIDTH_RANK = (2960);	//�����̕�
	const int HEIGHT_RANK = (2551);	//�����̍���
	const int END_WIDTH_RANK = (740);		//�ŏI�̕�
	const int END_HEIGHT_RANK = (331);		//�ŏI�̍���
	const D3DXVECTOR3 POSITION_RANK_P1 = D3DXVECTOR3(480, 825, 0);//�v���C���[�P�p�̕\���ʒu
	const D3DXVECTOR3 POSITION_RANK_P2 = D3DXVECTOR3(1440, 825, 0);//�v���C���[2�p�̕\���ʒu
	
	//����
	const D3DXVECTOR3 ROTATION_TEX = D3DXVECTOR3(0, 0, 0);			//��]
	const D3DCOLOR COLOR_TEX = D3DCOLOR_RGBA(255, 255, 255, 255);	//�F
	const int SHRINK_SPEED = 20;									//�k���X�s�[�h
}
//============================
//�N���X��`
//============================
class UIrank
{
public: //�����o�[�ϐ�
	Sprite * rank[uiRankNS::RANK_MAX];			//�X�v���C�g�̍쐬
	int widthSize;								//���̃T�C�Y�Ǘ��p
	int heightSize;								//�����T�C�Y�Ǘ��p

public: //�����o�[�֐�
	void initialize(int rankType, int playerType);
	void render(int rankType);
	void update(int rankType);
	void uninitialize(int rankType);
	void changeSize(int rankType);		//�g��k���֐�
};
