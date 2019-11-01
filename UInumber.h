//============================
//[UInumber.h]
// ����@�W��
//============================

//============================
//�C���N���[�h
//============================
#include "Sprite.h"
#include "TextureLoader.h"

//============================
//���O��� �萔
//============================
namespace uiNumberNS
{
	enum NUMBER_TYPE
	{
		P1_GREENIG,			//P1�p�Ή���
		P2_GREENIG,			//P2�p�Ή���
		P1_DEFEAT,			//P1�p���ސ�
		P2_DEFEAT,			//P2�p���ސ�
		NUMBER_TYPE_MAX,
	};

	//�����̕\���ʒu
	const int WIDTH_NUMBER = (100);									//�����̕�
	const int HEIGHT_NUMBER = (100);								//�����̍���
	const int DIGIT_NUMBER = 3;										//����
	const D3DXVECTOR3 P1_GREENIG_POS = D3DXVECTOR3(750, 415, 0);	//P1�p�Ή����̕\���ʒu
	const D3DXVECTOR3 P2_GREENIG_POS = D3DXVECTOR3(1710, 415, 0);	//P1�p�Ή����̕\���ʒu
	const D3DXVECTOR3 P1_DEFEAT_POS = D3DXVECTOR3(835, 585, 0);		//P1�p���ސ��̕\���ʒu
	const D3DXVECTOR3 P2_DEFEAT_POS = D3DXVECTOR3(1800, 585, 0);	//P1�p���ސ��̕\���ʒu

	//����
	const D3DXVECTOR3 ROTATION_TEX = D3DXVECTOR3(0, 0, 0);			//��]
	const D3DCOLOR COLOR_TEX = D3DCOLOR_RGBA(255, 255, 255, 255);	//�F
	const int SLIDE_SPEED = 20;										//�X���C�h�C���X�s�[�h
	const float COUNT_TIME = 120.0f;										//�J�E���g�A�b�v�ɂ����鎞��
}
//============================
//�N���X��`
//============================
class UInumber
{
private: //�����o�[�ϐ�
	Sprite * number[uiNumberNS::DIGIT_NUMBER];			//�X�v���C�g�̍쐬
	D3DXVECTOR3    pos[uiNumberNS::DIGIT_NUMBER];		//�\���ʒu�Ǘ��p
	int      num;			//�����Ǘ��p
	float	 time;			//���ԊǗ��p
	float		 displayScore;	//�\������X�R�A
	int		 endScore;		//�ŏI�X�R�A
	int		 keepScore;		//�ۑ��p�X�R�A
	int		 scored;
	D3DXVECTOR3 numberPos;	//�\���ʒu
	D3DXVECTOR2 uvCoord01;	//uv���W�Ǘ��p
	D3DXVECTOR2 uvCoord02;	//uv���W�Ǘ��p
	D3DXVECTOR2 uvCoord03;	//uv���W�Ǘ��p
	D3DXVECTOR2 uvCoord04;	//uv���W�Ǘ��p

public: //�����o�[�֐�
	void initialize(int numType);			//������
	void render();							//�`��
	void update(int score);					//�X�V
	void uninitialize();					//�I��
	void assingUV();						//uv���W�̑���֐�
	void assingPos();						//�\�����W�̑���֐�
	void setNumber(int score);				//�����̐ݒ�p�֐�
	void countUp(int score);				//�J�E���g�A�b�v�֐�
};

