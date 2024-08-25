/* ---------------------------------------------------------------------------------------------- 
 * 
 * �v���O�����T�v �F �����疃��(Ver0.1.2�F�J����)
 * �o�[�W����     �F 0.1.2.0.183(�a�����ʎq���\���̏C��)
 * �v���O������   �F mjs.exe
 * �t�@�C����     �F dispparts.h
 * �N���X��       �F MJSDisplayParts
 * �����T�v       �F �p�[�c�`�ʃN���X
 * ����쐬��     �F 2023/05/20 10:59:12
 * Ver0.1.2�쐬�� �F 2023/05/20 10:59:12
 * Ver0.1.3.0pre  �F 2024/03/19 23:55:27
 * Ver0.1.3.1pre  �F 2024/04/05 19:50:22
 * �ŏI�X�V��     �F 2024/08/25 10:19:10
 * 
 * Copyright (c) 2010-2024 TechMileStoraJP, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#include "stdafx.h"
#include "DxLib.h"

#include "common.h"
#include "gui.h"

#ifndef MJSDISPPARTS_H_INCLUDED
#define MJSDISPPARTS_H_INCLUDED

/* ---------------------------------------------------------------------------------------------- */
// �Œ�l
/* ---------------------------------------------------------------------------------------------- */

#define PI  3.1415926535897932384626433832795f    // �~����

#define HAI_COLOR    0                            // �v���ʂ̐F

// ��ʃ��[�h�̐ݒ�
#define SUB_TEHAI_DISP_MODE   0                   // �T�u��v�̕\�����[�h(0�Ȃ�΃V�����e���m�F)

// �v�F�̔ԍ��ݒ�
#define DISP_HAI_COLOR_NUM_NOCOLOR        0       // �u���F�v�̔ԍ�

#define DISP_HAI_COLOR_NUM_GRAY           1       // �u�D�F�v�̔ԍ�
#define DISP_HAI_COLOR_NUM_BLUE           2       // �u�F�v�̔ԍ�
#define DISP_HAI_COLOR_NUM_YELLOW         3       // �u���F�v�̔ԍ�
#define DISP_HAI_COLOR_NUM_GREEN          4       // �u�ΐF�v�̔ԍ�

#define DISP_HAI_COLOR_NUM_DEEP_GRAY     11       // �u�Z�D�F�v�̔ԍ�
#define DISP_HAI_COLOR_NUM_DEEP_BLUE     12       // �u�Z�F�v�̔ԍ�
#define DISP_HAI_COLOR_NUM_DEEP_YELLOW   13       // �u�Z���F�v�̔ԍ�
#define DISP_HAI_COLOR_NUM_DEEP_GREEN    14       // �u�Z�ΐF�v�̔ԍ�

/* ---------------------------------------------------------------------------------------------- */
// ���x��(�e���[�h)
/* ---------------------------------------------------------------------------------------------- */

// �Q�[���X�e�[�^�X
typedef enum {

	PARTS_BUT_NOCOLOR = 0,    // �{�^���F�Ȃ�
	PARTS_BUT_BLUE,           // �{�^����
	PARTS_BUT_GREEN,          // �{�^����
	PARTS_BUT_YELLOW,         // �{�^����
	PARTS_BUT_RED,            // �{�^����

} LBPartsButColor;

/* ---------------------------------------------------------------------------------------------- */
// �N���X��`
/* ---------------------------------------------------------------------------------------------- */
class MJSDisplayParts
{

	// ------------------------------------------------------------------- 
	// ���J�֐���`
	// ------------------------------------------------------------------- 
	public:

	// ------------------------------------------------------------------- 
	// �摜�n���h��
	// ------------------------------------------------------------------- 

	// �w�i�E�^�C�g��
	int backpic;         // �w�i��
	int title;           // �^�C�g��
	int banner;          // �o�i�[
	int center_pltimg;   // �Z���^�[�v���[�g

	// �v�p�[�c
	int Pai[40];      // �v�摜_�c
	int LPai[40];     // �v�摜_��
	
	int PaiBase[10];  // �v���摜_�c
	int LPaiBase[10]; // �v���摜_��

	// �v�w�i�F
	int blue;         // �v����-��
	int gray;         // �v����-�D�F
	int yellow;       // �v����-���F

	int lblue;        // ���v����-��
	int lgray;        // ���v����-�D�F
	int lyellow;      // ���v����-���F

	// �v�ԍ��e�[�u��
	int PaiImgNum[40];  // �v�摜�Ƃ̑Ή��\

	// �v���[�g
	int pltimg;         // �v���[�g�摜

	// �{�^��
	int but_green;      // �ʏ�ύX�{�^��(�ΐF�{�^��)
	int but_blue;       // tkinfo���{�^��(�F�{�^��)
	int but_yellow;     // ply���{�^��(���F�{�^��)
	int but_red;        // �I���{�^��(�ԐF�{�^��)
	int but_kyokuid;    // ��ID����{�^��
	int but_actid;      // ActID����{�^��

	// �{�^��(�r���[���[���[�h)
	int but02;          // ��ID�{�^��
	int but03;          // ACTID�{�^��

	// ------------------------------------------------------------------- 
	// ������
	// ------------------------------------------------------------------- 

	// �f�B�X�v���C�\���p�E���b�Z�[�W�p
	char tmp_disp_msg[256];

	// �v���[�g�\����
	char plt_name[PLT_COUNT_MAX][20];             // �v���[�g�\����

	// �Ǖ\���p������
	char kyokutbl[12][8];

	// �𖼁E���Ǖ�����
	char yakuname[YAKU_SHUBETSU_MAX][20];         // ��𖼁E�ʏ��
	char yakumanname[YAKUMAN_SHUBETSU_MAX][20];   // ��𖼁E��
	char ryukyokuname[10][20];                    // ���ǖ�

	// ------------------------------------------------------------------- 
	// ��ʂ̐ݒ�ϐ�
	// ------------------------------------------------------------------- 

	// ��v�\�����[�h
	int desp_tehai_mode; // (0:���C�i�[�\���A1:�X�N�G�A�\���A2:������\��)

	// �v���ʂ̐F
	int hai_color;

	// ------------------------------------------------------------------- 
	// �R���X�g���N�^
	// ------------------------------------------------------------------- 

	//�R���X�g���N�^
    MJSDisplayParts(){};

	//�f�X�g���N�^
    ~MJSDisplayParts(){};

	// ------------------------------------------------------------------- 
	// �N���X������
	// ------------------------------------------------------------------- 

	// ���C���֐�
	void DispPartsInit();          // �p�[�c�\���N���X�̏���������
	void DispPartsPost();          // �p�[�c�\���N���X�̏���������

	// �T�u�֐�
	void SetYakuName();            // �𖼒�`

	// ------------------------------------------------------------------- 
	// DX���C�u��������������
	// ------------------------------------------------------------------- 

	int  DispPartsFrameInit();     // �t���[������
	int  DispPartsLibInit();       // ��������
	void DispPartsReadPic();       // �摜�ǂݍ���
	void DispPartsLibPost();       // �I������

	void DispPartsClearDraw();     // �����`�揈��
	void DispPartsFlip();          // �t���b�v����

	// ------------------------------------------------------------------- 
	// ���ʊ֐�
	// ------------------------------------------------------------------- 

	// ���ʏ���(DX���C�u�����֘A)
	void DispString(int x, int y, char *str);                                                   // ������\��

	// ------------------------------------------------------------------- 
	// �p�[�c�\��
	// ------------------------------------------------------------------- 

	// �p�[�c�\��/DX���C�u�������
	void DispOpeningTitle(int ver1, int ver2, int ver3, int ver4, int ver5);                    // �I�[�v�j���O�^�C�g��
	void DispBunner(int ver1, int ver2, int ver3, int ver4, int ver5);                          // �o�i�[�\��
	void DispCenterPlt();                                                                       // �Z���^�[�v���[�g�\��
	void DispMousepoint(int x, int y, int msx, int msy, int b0, int b1);                        // �}�E�X���
	void DispFps(int x, int y, float mFps, int total_frame_count, int frame_count);             // FPS�E�t���[��

	// �p�[�c�\��/�v���[�g
	void DispPltline(bool plt_mode[]);                                                          // �v���[�g���C���̕\��
	void DispPltNakiAriNashi(bool plt_naki_stat);                                               // �v���[�g/�L�E��

	// �p�[�c�\��/�{�^��
	void DispButton(int x, int y, LBPartsButColor but_color);                                   // �{�^���\��
	void DispGameModeButton();                                                                  // �Q�[�����[�h�̃{�^���ꗗ�\��
	void DispViewerModeButton();                                                                // �r���[�A�[���[�h�̃{�^���ꗗ�\��

	// �p�[�c�\��/�v�\��
	void DispHai(int x, int y, int hai, bool aka, bool hai_turn, int haimode, int haicolor);    // �v�\��
	void DispLHai(int x, int y, int hai, bool aka, bool hai_turn, int haimode, int haicolor);   // ���v�\��

	// �p�[�c�\��/����
	void DispDora(int x, int y, int doracount, int dora[], bool dora_aka[]);                    // �h�����

	// ------------------------------------------------------------------- 
	// �֐���`(�v��p�[�c�E���C�i�[�\��)
	// ------------------------------------------------------------------- 

	// �v��p�[�c/��v�p�[�c�̕\��(�ʏ�o�[�W����)
	void DispActTehaiParts(   int  x,                       // 01:X���W
	                          int  y,                       // 02:Y���W
	                          int  tehai_tbl_count,         // 03:��v�e�[�u��
	                          int  tehai_tbl[],             // 04:��v�e�[�u��
	                          bool tehai_tbl_aka[],         // 05:��v�ԃe�[�u��
	                          int  tsumo_hai,               // 06:���̔v
	                          bool tsumo_aka,               // 07:���̐�
	                          int  sute_hai_num,            // 08:�̔v�̈ʒu�ԍ�
	                          int  color_hai_num,           // 09:��v�F���F�̈ʒu(1����)
	                          int  color_hai2_num,          // 10:��v�F���F�̈ʒu(2����)
	                          bool color_ankan              // 11:��v�F���F�E�Þȗp
	                          );

	// �v��p�[�c/��v�p�[�c(�l�v���[���[�̔v�֎~�\��)
	void DispActHumCanSuteParts(int  x,                     // X���W
	                          int  y,                       // Y���W
	                          int  tehai_tbl_count,         // ��v�e�[�u��
	                          int  tehai_tbl[],             // ��v�e�[�u��
	                          bool tehai_tbl_aka[],         // ��v�ԃe�[�u��
	                          bool tehai_can_sute_tbl[],    // �̔v�֎~�e�[�u��
	                          int  tsumo_hai,               // ���̔v
	                          bool tsumo_aka,               // ���́E��
	                          bool tsumo_can_sute,          // ���́E�̔v�֎~
	                          int  color_hai                // �J�[�\���I��v(���F�v)
	                          );

	// �v��p�[�c/��v�p�[�c(�l�v���[���[�E�Ȕv�I����)
	void DispActHumKanSelectTehaiParts(int  x,              // X���W
	                          int  y,                       // Y���W
	                          int  tehai_tbl_count,         // ��v�e�[�u��
	                          int  tehai_tbl[],             // ��v�e�[�u��
	                          bool tehai_tbl_aka[],         // ��v�ԃe�[�u��
	                          int  tsumo_hai,               // ���̔v
	                          bool tsumo_aka,               // ���́E��
	                          int  ankan_hai1,              // �ÞȔv1
	                          int  ankan_hai2,              // �ÞȔv2
	                          int  ankan_hai3,              // �ÞȔv3
	                          int  kakan_hai1,              // ���Ȕv1
	                          int  kakan_hai2,              // ���Ȕv2
	                          int  kakan_hai3,              // ���Ȕv3
	                          int  color_hai                // �J�[�\���I��v(���F�v)
	                          );

	// �v��p�[�c/�A�N�V������v�ECOM�p�̗�������v
	void DisplayUnkownTehai(int  x,               // X���W
	                        int  y,               // Y���W
	                        int  tehai_tbl_count, // ��v����
	                        bool tsumo_flg,       // ���̃t���O
	                        int  sute_hai_num);   // �̔v�̈ʒu�ԍ�

	// �v��p�[�c/�N���v���F���C�i�[�\��
	void DispActSarashiParts(int x,               // X���W
	                         int y,               // Y���W
	                         LBMen naki_stat,     // �ʎq�`��
	                         int hai_index,       // �v�ԍ�
	                         int aka_count);      // �Ԕv�L��

	// �v��p�[�c/�N���ʎq�̃p�[�c�\���F�S���ʎq�\��
	void DispAllSarashiParts(int x, 
	                         int y, 
	                         int naki_count, 
	                         LBMen naki_stat[], 
	                         int naki_hai[], 
	                         int naki_idx[], 
	                         int naki_aka[]);

	// �v��p�[�c/�͏��F���C�i�[�\��
	void DispActKawaParts_liner(int x, int y, int kawa_tbl_count, int kawa_tbl[], bool kawa_tbl_aka[], int kawa_mode[]);

	// ------------------------------------------------------------------- 
	// �֐���`(�v��p�[�c�E�͂ݕ\��)
	// ------------------------------------------------------------------- 

	//  �v��p�[�c/�A�N�V������v�FUP�v���[���\��
	void DispActTehaiParts_up(   int  x,                    // 01:X���W
	                             int  y,                    // 02:Y���W
	                             int  tehai_tbl_count,      // 03:��v��
	                             int  tehai_tbl[],          // 04:��v�e�[�u��
	                             bool tehai_tbl_aka[],      // 05:��v�ԃe�[�u��
	                             int  tsumo_hai,            // 06:���̔v
	                             bool tsumo_aka,            // 07:���̐�
	                             int  sute_hai_num);        // 08:�̔v�̈ʒu�ԍ�

	//  �v��p�[�c/�A�N�V������v�EDown�v���[���\�������C�i�[�Ƌ���

	//  �v��p�[�c/�A�N�V������v�ELeft�v���[���\��
	void DispActTehaiParts_left( int  x,                    // 01:X���W
	                             int  y,                    // 02:Y���W
	                             int  tehai_tbl_count,      // 03:��v��
	                             int  tehai_tbl[],          // 04:��v�e�[�u��
	                             bool tehai_tbl_aka[],      // 05:��v�ԃe�[�u��
	                             int  tsumo_hai,            // 06:���̔v
	                             bool tsumo_aka,            // 07:���̐�
	                             int  sute_hai_num);        // 08:�̔v�̈ʒu�ԍ�

	//  �v��p�[�c/�A�N�V������v�ERIGHT�v���[���\��
	void DispActTehaiParts_right( int  x,                   // 01:X���W
	                              int  y,                   // 02:Y���W
	                              int  tehai_tbl_count,     // 03:��v��
	                              int  tehai_tbl[],         // 04:��v�e�[�u��
	                              bool tehai_tbl_aka[],     // 05:��v�ԃe�[�u��
	                              int  tsumo_hai,           // 06:���̔v
	                              bool tsumo_aka,           // 07:���̐�
	                              int  sute_hai_num);       // 08:�̔v�̈ʒu�ԍ�

	//  �v��p�[�c/�A�N�V������v�EUP�v���[���������\��
	void DisplayUnkownTehai_up(int  x,                      // X���W
	                           int  y,                      // Y���W
	                           int  tehai_tbl_count,        // ��v����
	                           bool tsumo_flg,              // ���̃t���O
	                           int  sute_hai_num);          // �̔v�̈ʒu�ԍ�

	//  �v��p�[�c/�A�N�V������v�EDown�v���[���������\�������C�i�[�Ƌ���

	//  �v��p�[�c/�A�N�V������v�ELEFT�v���[���������\��
	void DisplayUnkownTehai_left(int  x,                    // X���W
	                             int  y,                    // Y���W
	                             int  tehai_tbl_count,      // ��v����
	                             bool tsumo_flg,            // ���̃t���O
	                             int  sute_hai_num);        // �̔v�̈ʒu�ԍ�

	//  �v��p�[�c/�A�N�V������v�ERIGHT�v���[���������\��
	void DisplayUnkownTehai_right(int  x,                   // X���W
	                              int  y,                   // Y���W
	                              int  tehai_tbl_count,     // ��v����
	                              bool tsumo_flg,           // ���̃t���O
	                              int  sute_hai_num);       // �̔v�̈ʒu�ԍ�


	// �v��p�[�c/�N���v���
	void DispActSarashiParts_up(int x,    int y, LBMen naki_stat, int hai_index, int aka_count);         // �N���ʎq�̃p�[�c�\���FUP�v���[���\��
	// void DispActSarashiParts_down(int x, int y, LBMen naki_stat, int hai_index, int aka_count);       // �N���ʎq�̃p�[�c�\���FDOWN�v���[���\�������C�i�[�Ƌ���
	void DispActSarashiParts_left(int x,  int y, LBMen naki_stat, int hai_index, int aka_count);         // �N���ʎq�̃p�[�c�\���FLEFT�v���[���\��
	void DispActSarashiParts_right(int x, int y, LBMen naki_stat, int hai_index, int aka_count);         // �N���ʎq�̃p�[�c�\���FRIGHT�v���[���\��

	// �v��p�[�c/�͏��
	void DispActKawaParts_up(int x,    int y, int kawa_tbl_count, int kawa_tbl[], bool kawa_tbl_aka[], int kawa_mode[]);             // �̓p�[�c�\���FUP�v���[���\��
	void DispActKawaParts_down(int x,  int y, int kawa_tbl_count, int kawa_tbl[], bool kawa_tbl_aka[], int kawa_mode[]);           // �̓p�[�c�\���FDOWN�v���[���\��
	void DispActKawaParts_left(int x,  int y, int kawa_tbl_count, int kawa_tbl[], bool kawa_tbl_aka[], int kawa_mode[]);           // �̓p�[�c�\���FLEFT�v���[���\��
	void DispActKawaParts_right(int x, int y, int kawa_tbl_count, int kawa_tbl[], bool kawa_tbl_aka[], int kawa_mode[]);          // �̓p�[�c�\���FRIGHT�v���[���\��

	// �v��p�[�c/�͂ݎ�v�\��(�e�X�g�p)
	void DispActTehai_test_square();       // ��\��(�e�X�g�p�j
	void DispActTehai_test_square_parts(); // ��\��(�e�X�g�p�F�p�[�c�\��)

};

#endif/* MJSDISPPARTS_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- */
// �\�[�X�I��
/* ---------------------------------------------------------------------------------------------- */
