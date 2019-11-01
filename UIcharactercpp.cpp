//============================
//[UIcharacter.cpp]
//����W��
//============================

//============================
//�C���N���[�h
//============================
#include "UIcharacter.h"

//============================
//�yusing�錾�z
//============================
using namespace uiCharacterNS;

//============================
//�O���[�o���ϐ�
//============================

//============================
//������
//============================
void UIcharacter::initialize(int playerType)
{
	//Sprite�̍쐬��pos�ɏ����ʒu����
	for (int i = 0; i < UICHARACTER_MAX; i++)
	{
		uiCharacter[i] = new Sprite;
		assignPos(i,playerType);
	}

	//���U���g���S�̏�����
	uiCharacter[RESULT]->initialize(
		*textureNS::reference(textureNS::RESULT)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_RESULT								//����
		, HEIGHT_RESULT								//�c��
		, POSITION_RESULT							//�\���ʒu
		, ROTATION									//��]
		, COLOR);									//�F

	//�v���C���[�̏�����
	uiCharacter[PLAYER1]->initialize(
		*textureNS::reference(textureNS::RESULT_PLAYER)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_PLAYER								//����
		, HEIGHT_PLAYER								//�c��
		, POSITION_PLAYER							//�\���ʒu
		, ROTATION									//��]
		, COLOR);									//�F

	uiCharacter[PLAYER2]->initialize(
		*textureNS::reference(textureNS::RESULT_PLAYER)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_PLAYER								//����
		, HEIGHT_PLAYER								//�c��
		, POSITION_PLAYER							//�\���ʒu
		, ROTATION									//��]
		, COLOR);									//�F

	//�Ή�(�p��)�̏�����
	uiCharacter[GREENIG]->initialize(
		*textureNS::reference(textureNS::RESULT_GREENIG)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_GREENIG								//����
		, HEIGHT_GREENIG							//�c��
		, POSITION_GREENIG_01						//�\���ʒu
		, ROTATION									//��]
		, COLOR);									//�F

	//�Ή�
	uiCharacter[RYOKUKA]->initialize(
		*textureNS::reference(textureNS::RESULT_RYOKUKA)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_RYOKUKA								//����
		, HEIGHT_RYOKUKA							//�c��
		, POSITION_RYOKUKA_01						//�\���ʒu
		, ROTATION									//��]
		, COLOR);									//�F

	//�p�[�Z���g�̏�����
	uiCharacter[PERSENT]->initialize(
		*textureNS::reference(textureNS::RESULT_PERSENT)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_PERSENT								//����
		, HEIGHT_PERSENT							//�c��
		, POSITION_PERSENT_01						//�\���ʒu
		, ROTATION									//��]
		, COLOR);									//�F

	//����(�p��)�̏�����
	uiCharacter[DEFEAT]->initialize(
		*textureNS::reference(textureNS::RESULT_DEFEAT)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_DEFEAT								//����
		, HEIGHT_DEFEAT								//�c��
		, POSITION_DEFEAT_01						//�\���ʒu
		, ROTATION									//��]
		, COLOR);									//�F

	//����
	uiCharacter[GEKITAI]->initialize(
		*textureNS::reference(textureNS::RESULT_GEKITAI)//�e�N�X�`��
		, SpriteNS::CENTER							//���S
		, WIDTH_GEKITAI								//����
		, HEIGHT_GEKITAI							//�c��
		, POSITION_GEKITAI_01						//�\���ʒu
		, ROTATION									//��]
		, COLOR);									//�F
}

//============================
//�`��
//============================
void UIcharacter::render(int resultPhase)
{
	
	switch (resultPhase)
	{
	case PHASE_01:
		uiCharacter[RESULT]->render();
		break;
	case PHASE_02:
		uiCharacter[RESULT]->render();
		break;
	case PHASE_03:
		uiCharacter[RESULT]->render();
		uiCharacter[PLAYER1]->render();
		uiCharacter[PLAYER2]->render();
		uiCharacter[GREENIG]->render();
		uiCharacter[RYOKUKA]->render();
		uiCharacter[PERSENT]->render();
		uiCharacter[DEFEAT]->render();
		uiCharacter[GEKITAI]->render();
		break;
	case PHASE_04:
		uiCharacter[RESULT]->render();
		uiCharacter[PLAYER1]->render();
		uiCharacter[PLAYER2]->render();
		uiCharacter[GREENIG]->render();
		uiCharacter[RYOKUKA]->render();
		uiCharacter[PERSENT]->render();
		uiCharacter[DEFEAT]->render();
		uiCharacter[GEKITAI]->render();
		break;
	case PHASE_05:
		uiCharacter[RESULT]->render();
		uiCharacter[PLAYER1]->render();
		uiCharacter[PLAYER2]->render();
		uiCharacter[GREENIG]->render();
		uiCharacter[RYOKUKA]->render();
		uiCharacter[PERSENT]->render();
		uiCharacter[DEFEAT]->render();
		uiCharacter[GEKITAI]->render();
	default:
		break;
	}
}

//============================
//�X�V
//============================
void UIcharacter::update(int resultPhase)
{
	//�v���C���[��uv���W�̐ݒ�
	setUV();

	switch (resultPhase)
	{
	case PHASE_01:

		if (pos[RESULT].x > END_POS_RESULT)
		{
			slideLeft(RESULT);
		}

		break;
	case PHASE_02:
		break;
	case PHASE_03:

		if (pos[PLAYER1].x > END_POS_PLAYER_01)
		{
			slideLeft(PLAYER1);
		}

		if (pos[PLAYER2].x > END_POS_PLAYER_02)
		{
			slideLeft(PLAYER2);
		}

		if (pos[GREENIG].y > END_POS_GREENING)
		{
			slideUp(GREENIG);
		}

		if (pos[RYOKUKA].y > END_POS_RYOKUKA)
		{
			slideUp(RYOKUKA);
		}

		if (pos[PERSENT].y > END_POS_PERSENT)
		{
			slideUp(PERSENT);
		}

		if (pos[DEFEAT].y > END_POS_DEFEAT)
		{
			slideUp(DEFEAT);
		}

		if (pos[GEKITAI].y > END_POS_GEKITAI)
		{
			slideUp(GEKITAI);
		}

		break;
	case PHASE_04:
		break;
	default:
		break;
	}
}

//=====================================
//�I������
//=====================================
void UIcharacter::uninitialize()
{
	//Sprite�̍폜
	for (int i = 0; i < UICHARACTER_MAX; i++)
	{
		delete uiCharacter[i];
	}
}

//======================================
//�E�ɃX���C�h�C�������֐�
//�������F�X���C�h�C��������UI�̎��
//======================================
void UIcharacter::slideRight(int uiType)
{
	//�E�ւ̃X���C�h�C��
	pos[uiType].x += SLIDE_SPEED;		
	uiCharacter[uiType]->setPosition(pos[uiType]);
	uiCharacter[uiType]->setVertex();
}

//======================================
//���ɃX���C�h�C�������֐�
//�������F�X���C�h�C��������UI�̎��
//======================================
void UIcharacter::slideLeft(int uiType)
{
	//���ւ̃X���C�h�C��
	pos[uiType].x -= SLIDE_SPEED;
	uiCharacter[uiType]->setPosition(pos[uiType]);
	uiCharacter[uiType]->setVertex();
}

//======================================
//��ɃX���C�h�C�������֐�
//�������F�X���C�h�C��������UI�̎��
//======================================
void UIcharacter::slideUp(int uiType)
{
	//��ւ̃X���C�h�C��
	pos[uiType].y -= SLIDE_SPEED;
	uiCharacter[uiType]->setPosition(pos[uiType]);
	uiCharacter[uiType]->setVertex();
}

//========================================
//�ϐ�pos�ɊeUI�̕\���ʒu��������֐�
//������:UI�̎��
//������:�v���C���[�̎��
//========================================
void UIcharacter::assignPos(int uiType,int playerType)
{
	//pos�ɂ��ꂼ��̍��W����
	switch (uiType)
	{
	case RESULT:
		pos[RESULT] = POSITION_RESULT;
		break;
	case PLAYER1:
		if (playerType == 0)
		{
			pos[PLAYER1] = POSITION_PLAYER;
			break;
		}
		else
		{
			pos[PLAYER1] = POSITION_PLAYER;
			break;
		}
	case PLAYER2:
		if (playerType == 0)
		{
			pos[PLAYER2] = POSITION_PLAYER;
			break;
		}
		else
		{
			pos[PLAYER2] = POSITION_PLAYER;
			break;
		}
	case GREENIG:
		if (playerType == 0)
		{
			pos[GREENIG] = POSITION_GREENIG_01;
			break;
		}
		else
		{
			pos[GREENIG] = POSITION_GREENIG_02;
			break;
		}
	case RYOKUKA:
		if (playerType == 0)
		{
			pos[RYOKUKA] = POSITION_RYOKUKA_01;
			break;
		}
		else
		{
			pos[RYOKUKA] = POSITION_RYOKUKA_02;
			break;
		}
	case PERSENT:
		if (playerType == 0)
		{
			pos[PERSENT] = POSITION_PERSENT_01;
			break;
		}
		else
		{
			pos[PERSENT] = POSITION_PERSENT_02;
			break;
		}
	case DEFEAT:
		if (playerType == 0)
		{
			pos[DEFEAT] = POSITION_DEFEAT_01;
			break;
		}
		else
		{
			pos[DEFEAT] = POSITION_DEFEAT_02;
			break;
		}
	case GEKITAI:
		if (playerType == 0)
		{
			pos[GEKITAI] = POSITION_GEKITAI_01;
			break;
		}
		else
		{
			pos[GEKITAI] = POSITION_GEKITAI_02;
			break;
		}
	default:
		break;
	}
}

//================================
//�v���C���[��uv���W�̐ݒ�
//================================
void UIcharacter::setUV()
{
	uiCharacter[PLAYER1]->setUVCoord(PLAYER1_UV_VERTEX01, PLAYER1_UV_VERTEX02, PLAYER1_UV_VERTEX03, PLAYER1_UV_VERTEX04);
	uiCharacter[PLAYER2]->setUVCoord(PLAYER2_UV_VERTEX01, PLAYER2_UV_VERTEX02, PLAYER2_UV_VERTEX03, PLAYER2_UV_VERTEX04);
}