//============================
//[UItex.cpp]
//����W��
//============================

//============================
//�C���N���[�h
//============================
#include "UIrank.h"

//============================
//�yusing�錾�z
//============================
using namespace uiRankNS;

//============================
//�O���[�o���ϐ�
//============================

//============================
//������
//������:�����N�̎��
//������:1P��2P��(0�Ȃ�P1����ȊO�Ȃ�P2)
//============================
void UIrank::initialize(int rankType,int playerType)
{
	//�X�v���C�g�̏�����
	rank[rankType] = new Sprite;

	//�T�C�Y����
	widthSize = WIDTH_RANK;
	heightSize = HEIGHT_RANK;

	//�����N�̎�ނƃv���C���[�ɉ����ď�����
	switch (rankType)
	{
	case EXCELLENT:
		if (playerType == 0)
		{
			rank[EXCELLENT]->initialize(
				*textureNS::reference(textureNS::RESULT_EXCELLENT)//�e�N�X�`��
				, SpriteNS::CENTER							//���S
				, WIDTH_RANK								//����
				, HEIGHT_RANK								//�c��
				, POSITION_RANK_P1							//�\���ʒu
				, ROTATION_TEX								//��]
				, COLOR_TEX);								//�F

		}
		else
		{
			rank[EXCELLENT]->initialize(
				*textureNS::reference(textureNS::RESULT_EXCELLENT)//�e�N�X�`��
				, SpriteNS::CENTER							//���S
				, WIDTH_RANK								//����
				, HEIGHT_RANK								//�c��
				, POSITION_RANK_P2							//�\���ʒu
				, ROTATION_TEX								//��]
				, COLOR_TEX);								//�F
		}
		break;

	case GREAT:
		if (playerType == 0)
		{
			rank[GREAT]->initialize(
				*textureNS::reference(textureNS::RESULT_GREAT)//�e�N�X�`��
				, SpriteNS::CENTER							//���S
				, WIDTH_RANK								//����
				, HEIGHT_RANK								//�c��
				, POSITION_RANK_P1							//�\���ʒu
				, ROTATION_TEX								//��]
				, COLOR_TEX);								//�F
		}
		else
		{
			rank[GREAT]->initialize(
				*textureNS::reference(textureNS::RESULT_GREAT)//�e�N�X�`��
				, SpriteNS::CENTER							//���S
				, WIDTH_RANK								//����
				, HEIGHT_RANK								//�c��
				, POSITION_RANK_P2							//�\���ʒu
				, ROTATION_TEX								//��]
				, COLOR_TEX);								//�F
		}
		break;

	case CLEARE:
		if (playerType == 0)
		{
			rank[CLEARE]->initialize(
				*textureNS::reference(textureNS::RESULT_CLEARE)//�e�N�X�`��
				, SpriteNS::CENTER							//���S
				, WIDTH_RANK								//����
				, HEIGHT_RANK								//�c��
				, POSITION_RANK_P1							//�\���ʒu
				, ROTATION_TEX								//��]
				, COLOR_TEX);								//�F
		}
		else
		{
			rank[CLEARE]->initialize(
				*textureNS::reference(textureNS::RESULT_CLEARE)//�e�N�X�`��
				, SpriteNS::CENTER							//���S
				, WIDTH_RANK								//����
				, HEIGHT_RANK								//�c��
				, POSITION_RANK_P2							//�\���ʒu
				, ROTATION_TEX								//��]
				, COLOR_TEX);								//�F
		}
		break;

	case FAILED:
		if (playerType == 0)
		{
			rank[FAILED]->initialize(
				*textureNS::reference(textureNS::RESULT_FAILED)//�e�N�X�`��
				, SpriteNS::CENTER							//���S
				, WIDTH_RANK								//����
				, HEIGHT_RANK								//�c��
				, POSITION_RANK_P1							//�\���ʒu
				, ROTATION_TEX								//��]
				, COLOR_TEX);								//�F
		}
		else
		{
			rank[FAILED]->initialize(
				*textureNS::reference(textureNS::RESULT_FAILED)//�e�N�X�`��
				, SpriteNS::CENTER							//���S
				, WIDTH_RANK								//����
				, HEIGHT_RANK								//�c��
				, POSITION_RANK_P2							//�\���ʒu
				, ROTATION_TEX								//��]
				, COLOR_TEX);								//�F
		}
		break;

	default:
		break;
	}
}

//============================
//�`��
//������:�����N�̎��
//============================
void UIrank::render(int rankType)
{
	rank[rankType]->render();
}

//============================
//�X�V
//������:�����N�̎��
//============================
void UIrank::update(int rankType)
{
	if (widthSize > END_WIDTH_RANK && heightSize > END_HEIGHT_RANK)
	{
		changeSize(rankType);
	}
}

//=============================
//�I������
//������:�����N�̎��
//=============================
void UIrank::uninitialize(int rankType)
{
	delete rank[rankType];
}

//============================
//�g��k���֐�
//============================
void UIrank::changeSize(int rankType)
{
	widthSize -= SHRINK_SPEED;
	heightSize -= SHRINK_SPEED;
	rank[rankType]->setSize(widthSize, heightSize);
	rank[rankType]->setVertex();
}