//============================
//[UItex.cpp]
//����W��
//============================

//============================
//�C���N���[�h
//============================
#include "UItex.h"

//============================
//�yusing�錾�z
//============================
using namespace uiTexNS;

//============================
//�O���[�o���ϐ�
//============================

//============================
//������
//============================
void UItexture::initialize()
{

	//Sprite�̍쐬��pos�ɏ����ʒu����
	for (int i = 0; i < UITEX_MAX; i++)
	{
		uiTexture[i] = new Sprite;
		assignPos(i);
	}

	//���C���̏�����
	uiTexture[LINE]->initialize(
		*textureNS::reference(textureNS::RESULT_LINE)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_LINE								//����
		, HEIGHT_LINE								//�c��
		, POSITION_LINE								//�\���ʒu
		, ROTATION_TEX								//��]
		, COLOR_TEX);								//�F

	//�t���[���̏�����
	uiTexture[FLAME01]->initialize(
		*textureNS::reference(textureNS::RESULT_FLAME)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_FLAME								//����
		, HEIGHT_FLAME								//�c��
		, POSITION_FLAME_01							//�\���ʒu
		, ROTATION_TEX								//��]
		, COLOR_TEX);								//�F

	//�t���[���̏�����
	uiTexture[FLAME02]->initialize(
		*textureNS::reference(textureNS::RESULT_FLAME)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_FLAME								//����
		, HEIGHT_FLAME								//�c��
		, POSITION_FLAME_02							//�\���ʒu
		, ROTATION_TEX								//��]
		, COLOR_TEX);								//�F

	//�L����A�̏�����
	uiTexture[CHARA_A]->initialize(
		*textureNS::reference(textureNS::RESULT_CHARA_A)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_CHARA_A								//����
		, HEIGHT_CHARA_A							//�c��
		, POSITION_CHARA_A							//�\���ʒu
		, ROTATION_TEX								//��]
		, COLOR_TEX);								//�F

	//�L����B�̏�����
	uiTexture[CHARA_B]->initialize(
		*textureNS::reference(textureNS::RESULT_CHARA_B)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_CHARA_B								//����
		, HEIGHT_CHARA_B							//�c��
		, POSITION_CHARA_B							//�\���ʒu
		, ROTATION_TEX								//��]
		, COLOR_TEX);								//�F

	//NEXT�e�N�X�`���̏�����
	uiTexture[NEXT]->initialize(
		*textureNS::reference(textureNS::RESULT_NEXT)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_NEXT								//����
		, HEIGHT_NEXT								//�c��
		, POSITION_NEXT								//�\���ʒu
		, ROTATION_TEX								//��]
		, COLOR_TEX);								//�F

}

//============================
//�`��
//============================
void UItexture::render(int resultPhase)
{

	switch (resultPhase)
	{
	case PHASE_01:
		uiTexture[LINE]->render();
		break;
	case PHASE_02:
		uiTexture[LINE]->render();
		break;
	case PHASE_03:
		uiTexture[LINE]->render();
		uiTexture[FLAME01]->render();
		uiTexture[FLAME02]->render();
		uiTexture[CHARA_A]->render();
		uiTexture[CHARA_B]->render();
		break;
	case PHASE_04:
		uiTexture[LINE]->render();
		uiTexture[FLAME01]->render();
		uiTexture[FLAME02]->render();
		uiTexture[CHARA_A]->render();
		uiTexture[CHARA_B]->render();
		break;
	case PHASE_05:
		uiTexture[LINE]->render();
		uiTexture[FLAME01]->render();
		uiTexture[FLAME02]->render();
		uiTexture[CHARA_A]->render();
		uiTexture[CHARA_B]->render();
		uiTexture[NEXT]->render();
		break;
	default:
		break;
	}
}

//============================
//�X�V
//============================
void UItexture::update(int resultPhase)
{
	switch (resultPhase)
	{
	case PHASE_01:
		if (pos[LINE].x < END_POS_LINE)
		{
			slideRight(LINE);
		}
		break;

	case PHASE_02:
		break;
	case PHASE_03:
		if (pos[FLAME01].y > END_POS_FLAME)
		{
			slideUp(FLAME01);
			slideUp(FLAME02);
		}
		if (pos[CHARA_A].y > END_POS_CHARA_A)
		{
			slideUp(CHARA_A);
			slideUp(CHARA_B);
		}
		break;
	case PHASE_04:
		break;
	case PHASE_05:
		if (pos[NEXT].x > END_POS_NEXT)
		{
			slideLeft(NEXT);
		}
		break;
	default:
		break;
	}
}

//=====================================
//�I������
//=====================================
void UItexture::uninitialize()
{
	//Sprite�̍폜
	for (int i = 0; i < UITEX_MAX; i++)
	{
		delete uiTexture[i];
	}
}

//======================================
//�E�ɃX���C�h�C�������֐�
//�������F�X���C�h�C��������UI�̎��
//======================================
void UItexture::slideRight(int uiType)
{
	//�E�ւ̃X���C�h�C��
	pos[uiType].x += SLIDE_SPEED_TEX;
	uiTexture[uiType]->setPosition(pos[uiType]);
	uiTexture[uiType]->setVertex();
}

//======================================
//���ɃX���C�h�C�������֐�
//�������F�X���C�h�C��������UI�̎��
//======================================
void UItexture::slideLeft(int uiType)
{
	//���ւ̃X���C�h�C��
	pos[uiType].x -= SLIDE_SPEED_TEX;
	uiTexture[uiType]->setPosition(pos[uiType]);
	uiTexture[uiType]->setVertex();
}

//======================================
//��ɃX���C�h�C�������֐�
//�������F�X���C�h�C��������UI�̎��
//======================================
void UItexture::slideUp(int uiType)
{
	//��ւ̃X���C�h�C��
	pos[uiType].y -= SLIDE_SPEED_TEX;
	uiTexture[uiType]->setPosition(pos[uiType]);
	uiTexture[uiType]->setVertex();
}

//========================================
//�ϐ�pos�ɊeUI�̕\���ʒu��������֐�
//========================================
void UItexture::assignPos(int uiType)
{
	//pos�ɂ��ꂼ��̍��W����
	switch (uiType)
	{
	case LINE:
		pos[LINE] = POSITION_LINE;
		break;

	case FLAME01:
		pos[FLAME01] = POSITION_FLAME_01;
		break;
		
	case FLAME02:
		pos[FLAME02] = POSITION_FLAME_02;
		break;

	case CHARA_A:
		pos[CHARA_A] = POSITION_CHARA_A;
		break;

	case CHARA_B:
		pos[CHARA_B] = POSITION_CHARA_B;
		break;

	case NEXT:
		pos[NEXT] = POSITION_NEXT;
		break;

	default:
		break;
	}
}