//============================
//[UInumber.cpp]
//����W��
//============================

//============================
//�C���N���[�h
//============================
#include "UInumber.h"

//============================
//�yusing�錾�z
//============================
using namespace uiNumberNS;

//============================
//�O���[�o���ϐ�
//============================

//============================
//������
//�������F�ǂ��̐����Ȃ̂����w��
//============================
void UInumber::initialize(int numType)
{
	//�ǂ��̐��������Q�Ƃ������ʒu�̐ݒ�
	switch (numType)
	{
	case P1_GREENIG:
		numberPos = P1_GREENIG_POS;
		break;

	case P2_GREENIG:
		numberPos = P2_GREENIG_POS;
		break;

	case P1_DEFEAT:
		numberPos = P1_DEFEAT_POS;
		break;

	case P2_DEFEAT:
		numberPos = P2_DEFEAT_POS;
		break;

	default:
		break;

	}
	
	//�������̃X�v���C�g�̍쐬�Ə�����
	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		number[i] = new Sprite;
		number[i]->initialize(
			*textureNS::reference(textureNS::NUMBER)	//�e�N�X�`��
			, SpriteNS::CENTER							//���S
			, WIDTH_NUMBER								//����
			, HEIGHT_NUMBER								//�c��
			, numberPos									//�\���ʒu
			, ROTATION_TEX								//��]
			, COLOR_TEX);								//�F
	}

	//uv���W�̑��
	assingUV();

	//�\�����W�̑��
	assingPos();

	//�\�����鐔���̏�����
	displayScore = 0;
}


//============================
//�`��
//������:�X�R�A���������set����
//============================
void UInumber::render()
{
	setNumber((int)displayScore);

	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		pos[i].x = -WIDTH_NUMBER * i + numberPos.x;
		number[i]->setPosition(pos[i]);
		number[i]->setVertex();
		number[i]->render();
	}
}

//============================
//�X�V
//============================
void UInumber::update(int score)
{
	countUp(score);
}


//=============================
//�I������
//=============================
void UInumber::uninitialize()
{
	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		delete number[i];
	}
}


//============================
//uv���W�̑���֐�
//============================
void UInumber::assingUV()
{
	uvCoord01 = D3DXVECTOR2(0.0, 0.0);
	uvCoord02 = D3DXVECTOR2(1.0, 0.0);
	uvCoord03 = D3DXVECTOR2(0.0, 1.0);
	uvCoord04 = D3DXVECTOR2(1.0, 1.0);
}

//============================
//�|�W�V�����̑���֐�
//============================
void UInumber::assingPos()
{
	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		pos[i] = numberPos;
	}
}

//============================
//�X�R�A�̐�����ݒ�
//============================
void UInumber::setNumber(int score)
{
	num = score;

	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		float x = (float)(num % 10);
		uvCoord01.x = 0.1*x;
		uvCoord02.x = 0.1 *(x + 1);
		uvCoord03.x = 0.1 *x;
		uvCoord04.x = 0.1 *(x + 1);
		num /= 10;
		number[i]->setUVCoord(uvCoord01, uvCoord02, uvCoord03, uvCoord04);
	}
}

//==============================
//�J�E���g�A�b�v�֐�
//==============================
void UInumber::countUp(int score)
{
	// �ŏI�I�ɕ\���������X�R�A����\�����̃X�R�A���Ђ��č������o��
	if (displayScore < score)
	{
		//�ۑ��p�ϐ��ɕ\�����Ă���X�R�A�ƍŏI�I�ɕ\���������X�R�A�̍���������
		keepScore = (score)-(displayScore);
		//�\�����Ă���X�R�A�ɍ������J�E���g�A�b�v�ɂ����������̂Ŋ��������̂𑫂�
		displayScore += (keepScore / COUNT_TIME);
		//�����_�؂�グ�̂���
		displayScore += 0.9;
	}
	else
	{
		displayScore = score;
	}
}