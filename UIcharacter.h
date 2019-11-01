//============================
//[UIcharacter.h]
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
namespace uiCharacterNS
{
	//UI�̎��
	enum UICHARACTER_TYPE
	{
		RESULT,
		PLAYER1,
		PLAYER2,
		GREENIG,
		RYOKUKA,
		PERSENT,
		DEFEAT,
		GEKITAI,
		UICHARACTER_MAX,	//UI(����)�̑���
	};

	//���U���g�̃t�F�C�Y
	enum RESULT_PHASE
	{
		PHASE_01,		//���U���g���S�̃X���C�h�C��
		PHASE_02,		//���\��
		PHASE_03,		//���ʕ\��(�����Ȃ�)
		PHASE_04,		//�^�C�g���ɖ߂�t�F�C�Y
		PHASE_05,
		PHASE_MAX,		//�t�F�C�Y�̑���
	};

	//���U���g���S
	const int WIDTH_RESULT = (330);			//��
	const int HEIGHT_RESULT = (170);		//����
	const D3DXVECTOR3 POSITION_RESULT = D3DXVECTOR3(2100, 70, 0);//�����ʒu
	const float	END_POS_RESULT =(215.0f);	//�ŏI�ʒu��x���W

	//�v���C���[
	const int WIDTH_PLAYER = (345);			//��
	const int HEIGHT_PLAYER = (90);			//����
	const D3DXVECTOR3 POSITION_PLAYER = D3DXVECTOR3(3800, 250, 0);//�����ʒu
	const float END_POS_PLAYER_01 = (645.0f);//�v���C���[�P�̍ŏI�ʒu��x���W
	const float END_POS_PLAYER_02 = (1605);	 //�v���C���[�Q�̍ŏI�ʒu��x���W
	//uv���W
	const D3DXVECTOR2 PLAYER1_UV_VERTEX01 = D3DXVECTOR2(0.0, 0.0);
	const D3DXVECTOR2 PLAYER1_UV_VERTEX02 = D3DXVECTOR2(1.0, 0.0);
	const D3DXVECTOR2 PLAYER1_UV_VERTEX03 = D3DXVECTOR2(0.0, 0.5);
	const D3DXVECTOR2 PLAYER1_UV_VERTEX04 = D3DXVECTOR2(1.0, 0.5);
	const D3DXVECTOR2 PLAYER2_UV_VERTEX01 = D3DXVECTOR2(0.0, 0.5);
	const D3DXVECTOR2 PLAYER2_UV_VERTEX02 = D3DXVECTOR2(1.0, 0.5);
	const D3DXVECTOR2 PLAYER2_UV_VERTEX03 = D3DXVECTOR2(0.0, 1.0);
	const D3DXVECTOR2 PLAYER2_UV_VERTEX04 = D3DXVECTOR2(1.0, 1.0);

	//�Ή�(�p��)
	const int WIDTH_GREENIG = (334);		//��
	const int HEIGHT_GREENIG = (53);		//����
	const D3DXVECTOR3 POSITION_GREENIG_01 = D3DXVECTOR3(248, 3500, 0);//�v���C���[�P�p�����ʒu
	const D3DXVECTOR3 POSITION_GREENIG_02 = D3DXVECTOR3(1208, 3500, 0);//�v���C���[�Q�p�����ʒu
	const float END_POS_GREENING = (353.0f);//�ŏI�ʒu��y���W

	//�Ή�
	const int WIDTH_RYOKUKA = (256);		//��
	const int HEIGHT_RYOKUKA = (86);		//����
	const D3DXVECTOR3 POSITION_RYOKUKA_01 = D3DXVECTOR3(358, 4500, 0);//�v���C���[�P�p�����ʒu
	const D3DXVECTOR3 POSITION_RYOKUKA_02 = D3DXVECTOR3(1318, 4500, 0);//�v���C���[�Q�p�����ʒu
	const float END_POS_RYOKUKA = (425.0f);	//�ŏI�ʒu��y���W

	//�p�[�Z���g
	const int WIDTH_PERSENT = (115);		//��
	const int HEIGHT_PERSENT = (124);		//����
	const D3DXVECTOR3 POSITION_PERSENT_01 = D3DXVECTOR3(845, 4500, 0);//�v���C���[�P�p�����ʒu
	const D3DXVECTOR3 POSITION_PERSENT_02 = D3DXVECTOR3(1805, 4500, 0);//�v���C���[�Q�p�����ʒu
	const float END_POS_PERSENT = (429.0f);	//�ŏI�ʒu��y���W

	//����(�p��)
	const int WIDTH_DEFEAT = (390);			//��
	const int HEIGHT_DEFEAT = (53);			//����
	const D3DXVECTOR3 POSITION_DEFEAT_01 = D3DXVECTOR3(273, 5500, 0);//�v���C���[�P�p�����ʒu
	const D3DXVECTOR3 POSITION_DEFEAT_02 = D3DXVECTOR3(1318, 5500, 0);//�v���C���[�Q�p�����ʒu
	const float END_POS_DEFEAT = (523.0f);	//�ŏI�ʒu��y���W

	//����
	const int WIDTH_GEKITAI = (255);		//��
	const int HEIGHT_GEKITAI = (86);		//����
	const D3DXVECTOR3 POSITION_GEKITAI_01 = D3DXVECTOR3(358, 6500, 0);//�v���C���[�P�p�����ʒu
	const D3DXVECTOR3 POSITION_GEKITAI_02 = D3DXVECTOR3(1318, 6500, 0);//�v���C���[�Q�p�����ʒu
	const float END_POS_GEKITAI = (595.0f);	//�ŏI�ʒu��y���W

	 //����
	const D3DXVECTOR3 ROTATION = D3DXVECTOR3(0, 0, 0);			//��]
	const D3DCOLOR COLOR = D3DCOLOR_RGBA(255, 255, 255, 255);	//�F
	const float SLIDE_SPEED = 20.0f;							//�X���C�h�C���̑��x
}
//============================
//�N���X��`
//============================
class UIcharacter
{
public: //�����o�[�ϐ�
	Sprite * uiCharacter[uiCharacterNS::UICHARACTER_MAX];	//�X�v���C�g
	D3DXVECTOR3 pos[uiCharacterNS::UICHARACTER_MAX];		//�\���ʒu�Ǘ��p

public: //�����o�[�֐�
	void initialize(int playerType);						//������
	void render(int resultPhase);							//�`��
	void update(int resultPhase);							//�X�V
	void uninitialize();									//�I��
	void slideRight(int uiType);							//�E�փX���C�h�C���֐�
	void slideLeft(int uiType);								//���փX���C�h�C���֐�
	void slideUp(int uiType);								//��փX���C�h�C���֐�
	void assignPos(int uiType,int playerType);				//�\���ʒu�̑���֐�
	void setUV();											//uv���W�̐ݒ�֐�
};


