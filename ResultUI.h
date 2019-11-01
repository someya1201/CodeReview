//============================
// [ResultUI.h]
// ����@�W��
//============================

//============================
//�C���N���[�h
//============================
#include "Sprite.h"
#include "TextureLoader.h"
#include "Input.h"
#include "UIcharacter.h"
#include "UItex.h"
#include "UIrank.h"
#include "UInumber.h"

//============================
//���O��� �萔
//============================
namespace resultUiNS
{
	
	//���U���g�̃t�F�C�Y
	enum RESULT_PHASE
	{
		PHASE_01,		//���U���g���S�̃X���C�h�C��
		PHASE_02,		//���\��
		PHASE_03,		//�����\��
		PHASE_04,		//�����̃J�E���g�A�b�v
		PHASE_05,		//�����N�̕\��
		PHASE_MAX,		//�t�F�C�Y�̑���
	};

	//�v���C���[�̎��
	enum PLAYER_TYPE
	{
		PLAYER_01,
		PLAYER_02,
		PLAYER_MAX,
	};

}
//============================
//�N���X��`
//============================
class ResultUI
{
public: //�����o�[�ϐ�
	UIcharacter uiCharacter01;		//�v���C���[�P�p������UI
	UIcharacter uiCharacter02;		//�v���C���[2�p������UI
	UItexture	uiTexture;			//�e�N�X�`����UI
	UIrank      uiRank01;			//�v���C���[�P�̃����N��UI
	UIrank      uiRank02;			//�v���C���[2�̃����N��UI
	UInumber	uiNumber[uiNumberNS::NUMBER_TYPE_MAX];			//����
	int			score01;			//�v���C���[�P�̃X�R�A�ۑ��p
	int			score02;			//�v���C���[�Q�̃X�R�A�ۑ��p
	int			resultPhase;		//�t�F�C�Y�Ǘ��p
	float		time;				//�t�F�C�Y�ڍs���鎞��
	int			rank01;				//�v���C���[�P�̃����N�Ǘ��p
	int         rank02;				//�v���C���[2�̃����N�Ǘ��p

public: //�����o�[�֐�
	void initialize();				//������
	void render();					//�`��
	void update(float flameTime);	//�X�V
	void uninitialize();			//�I��
	
};

