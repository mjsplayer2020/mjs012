/* ---------------------------------------------------------------------------------------------- 
 * 
 * �v���O�����T�v �F �����疃��(Ver0.1.2�F�J����)
 * �o�[�W����     �F 0.1.2.0.183(�a�����ʎq���\���̏C��)
 * �v���O������   �F mjs.exe
 * �t�@�C����     �F display.h
 * �N���X��       �F MJSDisplay
 * �����T�v       �F ��ʕ\�������N���X
 * Ver0.0.8�쐬�� �F 2012/05/12 11:06:22
 * Ver0.1.0�쐬�� �F 2022/05/03 18:50:06
 * Ver0.1.1�쐬�� �F 2022/06/30 21:19:01
 * Ver0.1.2�쐬�� �F 2022/08/31 22:19:54
 * Ver0.1.3.0pre  �F 2024/03/19 23:55:27
 * Ver0.1.3.1pre  �F 2024/04/05 19:50:22
 * �ŏI�X�V��     �F 2024/08/18 11:40:12
 * 
 * Copyright (c) 2010-2024 TechMileStoraJP, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#include "stdafx.h"
#include "DxLib.h"

#include "dispparts.h"
#include "gui.h"
#include "player.h"
#include "tkinfo.h"

#ifndef MJSDISPLAY_H_INCLUDED
#define MJSDISPLAY_H_INCLUDED

/* ---------------------------------------------------------------------------------------------- */
// �N���X��`
/* ---------------------------------------------------------------------------------------------- */
class MJSDisplay
{

	// ------------------------------------------------------------------- 
	// ���J�֐���`
	// ------------------------------------------------------------------- 
	public:

	// ------------------------------------------------------------------- 
	// �N���X��`
	// ------------------------------------------------------------------- 

	MJSDisplayParts  *dparts;           // �p�[�c�\���N���X

	// ------------------------------------------------------------------- 
	// ������
	// ------------------------------------------------------------------- 

	// �f�B�X�v���C�\���p�E���b�Z�[�W�p
	char tmp_disp_msg[256];

	// ------------------------------------------------------------------- 
	// ��ʂ̐ݒ�ϐ�
	// ------------------------------------------------------------------- 

	// ��v�\�����[�h
	int desp_tehai_mode;                // �f�t�H���g�̎�v�\�����[�h(0:���C�i�[�\���A1:�X�N�G�A�\���A2:�e�X�g�\��)

	// �v���ʂ̐F
	int hai_color;

	// ------------------------------------------------------------------- 
	// �R���X�g���N�^
	// ------------------------------------------------------------------- 

	//�R���X�g���N�^
    MJSDisplay(){};

	//�f�X�g���N�^
    ~MJSDisplay(){};

	// ------------------------------------------------------------------- 
	// �֐���`(���������E�㏈��)
	// ------------------------------------------------------------------- 

	// ��������
	void DisplayInit();

	// �㏈��
	void DisplayPost();

	// ------------------------------------------------------------------- 
	// ���C����ʕ\��(�e�X�g�p��\��)
	// ------------------------------------------------------------------- 
	void DisplaySampleTitle(MJSTkinfo *tk, MJSGui *gui, float mFps, int total_frame_count, int ver1, int ver2, int ver3, int ver4, int ver5);

	// ------------------------------------------------------------------- 
	// ���C����ʕ\��(�I�[�v�j���O)
	// ------------------------------------------------------------------- 
	void DisplayOpening(MJSGui *gui, float mFps, int total_frame_count, int ver1, int ver2, int ver3, int ver4, int ver5);  // �Q�[�����[�h��\��(���C������)

	// ------------------------------------------------------------------- 
	// ���C����ʕ\��(��Q�[�����[�h�\��)
	// ------------------------------------------------------------------- 

	// �Q�[�����[�h��\��(���C������)
	void DisplayTaku(MJSTkinfo *tk, MJSPlayer *ply, MJSGui *gui, float mFps, int total_frame_count, int ver1, int ver2, int ver3, int ver4, int ver5);
	void DisplayBagime(MJSTkinfo *tk, MJSGui *gui, int kyoku_index);            // �ꌈ�߉��
	void DispNormalTakuStat(MJSTkinfo *tk, MJSPlayer *ply, MJSGui *gui);        // �ʏ�̑�\��

	// �ǏI������
	void DispKyokuEnd(MJSTkinfo *tk, MJSGui *gui, int kyoku_index);             // �ǌ��ʕ\���F���C������
	// �ǏI������/�T�u����
	void DispKyokuEndTehai(MJSTkinfo *tk, int kyoku_index);                     // ��v�\��
	void DispKyokuEndHanInfo(MJSTkinfo *tk, int kyoku_index);                   // �|���\��
	void DispKyokuEndYakuInfo(MJSTkinfo *tk, int kyoku_index);                  // ��L���̕\��
	void DispKyokuEndMentsuInfoNormal(MJSTkinfo *tk, int kyoku_index);          // �ʏ����E�ʎq���
	void DispKyokuEndAgariInfoNormal(MJSTkinfo *tk, int kyoku_index);           // �ʏ�a���E�ڍ׏��
	void DispKyokuEndMentsuInfoChitoi(MJSTkinfo *tk, int kyoku_index);          // ���Ύ���E�ʎq���
	void DispKyokuEndAgariInfoChitoi(MJSTkinfo *tk, int kyoku_index);           // ���Ύ���E�ڍ׏��
	void DisplayRyukyokuMachiHai(MJSTkinfo *tk, int kyoku_index);               // ���ǎ��\��

	// ��Q�[���I������
	void DisplayGameResult(MJSTkinfo *tk, MJSGui *gui);                         // ��I��

	// �p�[�c���
	void DispTehaiLineMessage(MJSTkinfo *tk, MJSGui *gui, int x, int y);        // ��v���C�����b�Z�[�W

	// ------------------------------------------------------------------- 
	// ���C����ʕ\��(�r���[�A�[���[�h�\��)
	// ------------------------------------------------------------------- 

	// �r���[�A�[���[�h��\��(���C������)
	void DisplayViewerTaku(MJSTkinfo *tk, MJSPlayer *ply, MJSGui *gui, float mFps, int total_frame_count, int ver1, int ver2, int ver3, int ver4, int ver5);
	void DisplayViewerStatparts(MJSTkinfo *tk, MJSGui *gui);                              // �X�e�[�^�X���Ƃ̃p�[�c�\��
	void DispKyokuEndTplog(MJSTkinfo *tk, int kyoku_index);                               // �a�����

	// ------------------------------------------------------------------- 
	// ���C����ʕ\��(MJAI�N���C�A���g���[�h�\��)
	// ------------------------------------------------------------------- 

	// �N���C�A���g���[�h��\��(���C������)
	void DisplayMjaiClientTaku(MJSTkinfo *tk, MJSPlayer *ply, MJSGui *gui, float mFps, int total_frame_count, int ver1, int ver2, int ver3, int ver4, int ver5);
	void DisplayMjaiConnect(MJSTkinfo *tk, MJSGui *gui);                                  // �ڑ��m�F���
	void DisplayClientModeBagime(MJSTkinfo *tk, MJSGui *gui, int kyoku_index);            // �ꌈ�ߕ\��(�N���C�A���g���[�h)
	void DispyMjaiClientNormalTakuStat(MJSTkinfo *tk, MJSPlayer *ply, MJSGui *gui);       // �ʏ�̑�\��(�N���C�A���g���[�h)
	void DisplayMjaiClientKyokuEnd(MJSTkinfo *tk, MJSGui *gui, int kyoku_index);          // �ǌ��ʕ\��(�N���C�A���g���[�h)
	void DisplayMjaiClientGameResult(MJSTkinfo *tk, MJSGui *gui);                         // ��I��(�N���C�A���g���[�h)
	void DisplayMjaiClientErrMes(MJSTkinfo *tk, MJSGui *gui);                             // �G���[�\��(�N���C�A���g���[�h)

	// �T�u����(�N���C�A���g���[�h�F����)
	void DisplayClientModeInfo(MJSTkinfo *tk, MJSGui *gui, int x, int y);                 // �N���C�A���g���[�h�̐ݒ���

	// ------------------------------------------------------------------- 
	// �֐���`(�A�N�V������v�\���E���C�i�[�\��)
	// ------------------------------------------------------------------- 

	// �A�N�V������v�\���E���C�i�[HUM�\���ACOM�\��
	void DispActTehaiHum(MJSTkinfo *tk, MJSGui *gui, int kyoku_index, int actid, int pnum, int msx, int msy);           // �A�N�V������vHUM����(�X�N�G�A���p)
	void DispActTehaiCom(MJSTkinfo *tk, MJSGui *gui, int kyoku_index, int actid, int pnum, int msx, int msy);           // �A�N�V������vCOM����
	void DispActSarashi(MJSTkinfo *tk, int kyoku_index, int pnum, int actid);                                           // �A�N�V�����ԍ����l���������炵�v�̕\��(���C�i�[) 
	void DispActKawa(MJSTkinfo *tk, int kyoku_index, int actid, int pnum);                                              // �A�N�V������v�͔̉v(���C�i�[) 

	// ------------------------------------------------------------------- 
	// �֐���`(�A�N�V������v�\���E�X�N�G�A�\��)
	// ------------------------------------------------------------------- 

	// �A�N�V������v�\���E�X�N�G�A�\��
	void DispActTehaiCom_square(MJSTkinfo *tk, MJSGui *gui, int kyoku_index, int actid, int pnum, int msx, int msy);    // �A�N�V������vCOM����(�X�N�G�A)
	void DispActSarashi_square(MJSTkinfo *tk, int kyoku_index, int pnum, int actid);                                    // �A�N�V������v���l���������炵�v(�X�N�G�A) 
	void DispActKawa_square(MJSTkinfo *tk, int kyoku_index, int actid, int pnum);                                       // �A�N�V������v�͔̉v(�X�N�G�A) 

	// �A�N�V������v�\���E������\��(�f�o�O�p)
	void DispActTehai_info_all();

	// ------------------------------------------------------------------- 
	// ��v���ڍ�(tkinfo�N���X���\��)
	// ------------------------------------------------------------------- 

	// ���C���֐�
	void DispKyokuInfo(MJSTkinfo *tk, int kyoku_index);                                                                 // �Ǐ��
	void DispPlyInfo(MJSTkinfo *tk, int kyoku_index, int pnum);                                                         // �v���[���[���

	// tkinfo�N���X���\��/���C���֐�
	void DispActNumInfo(MJSTkinfo *tk, int x, int y, int kyoku_index, int actid);                                       // �ԍ����Ƃ̃A�N�V�������
	void DispTakuStat(MJSTkinfo *tk, int x, int y);                                                                     // ����
	void DispTkInfoStat(MJSTkinfo *tk, int x, int y);                                                                   // ��N���X���

	// tkinfo�N���X���\��/�T�u�֐�
	void DisplayTehaiDetail(MJSTkinfo *tk, int pnum);                                                                   // ��v���̏ڍ�
	void DisplayTkinfoDetail(MJSTkinfo *tk);                                                                            // tkinfo���ڍ�
	void DisplayTkinfoDetail_sub_tehai(MJSTkinfo *tk, int x, int y, int pnum);                                          // tkinfo���ڍ�(�T�u�����F��v���)
	void DisplayTkinfoDetail_sub_hist(MJSTkinfo *tk, int x, int y, int pnum);                                           // tkinfo���ڍ�(�T�u�����F��v�q�X�g�O�������)
	void DisplayTkinfoDetail_sub_sute(MJSTkinfo *tk, int x, int y, int pnum, int line_num);                             // tkinfo���ڍ�(�T�u�����F�̔v���)
	void DisplayTkinfoDetail_sub_naki(MJSTkinfo *tk, int kyoku_index, int actid, int pnum, int x, int y);               // tkinfo���ڍ�(�T�u�����F�v���)
	void DisplayTkinfoDetail_sub_shanten(MJSTkinfo *tk, int x, int y, int pnum);                                        // tkinfo���ڍ�(�T�u�����F�Ԕv�A�����A�Ҕv���)
	void DisplayTkinfoDetail_sub_ply_actnaki_info(MJSTkinfo *tk, int x, int y, int pnum);                               // tkinfo���ڍ�(�T�u�����FAct�v���)
	void DisplayTkinfoDetail_sub_tkstat(MJSTkinfo *tk, LBTkSt tk_stat, int x, int y);                                   // tkinfo���ڍ�(�T�u�����Ftkinfo�X�e�[�^�X)
	void DisplayTkinfoDetail_sub_plyactInfo(MJSTkinfo *tk, LBPAct tmp_act, int x, int y);                               // tkinfo���ڍ�(�T�u�����Fply_act�X�e�[�^�X)
	void DisplayTkinfoDetail_sub_tehai_count(MJSTkinfo *tk, int x, int y, int pnum);                                    // tkinfo���ڍ�(�T�u�����F��v����)

	// �f�o�O�p
	void DispYamahai(MJSTkinfo *tk);                                                                                    // �v�R�\��(�f�o�O�p)

	// ------------------------------------------------------------------- 
	// ��v���ڍ�(GUI�N���X���\��)
	// ------------------------------------------------------------------- 

	void DispGuiInfo(MJSGui *gui, int x, int y);                                                                        // GUI���
	void DisplayGuiClientMode(MJSGui *gui, int x, int y);                                                               // GUI���EGUI�N���C�A���g���[�h
	void DisplayGuiTehaiMode(MJSGui *gui, int x, int y);                                                                // GUI���EGUI��v���[�h
	void DisplayGuiChiKoho(MJSGui *gui, int x, int y);                                                                  // GUI���E�v���[���[�̃`�[�����

	// ------------------------------------------------------------------- 
	// ��v���ڍ�(ply�N���X���\��)
	// ------------------------------------------------------------------- 

	// ��v���ڍ�(ply�N���X���\��)
	void DisplayPlyTehaiDetail(MJSTkinfo *tk, MJSPlayer *ply, int pnum);                                                // ply��v�̏ڍ׏��
	void DisplayClientPlyTehaiDetail(MJSTkinfo *tk, MJSPlayer *ply);                                                    // �N���C�A���g���[�hply��v�̏ڍ׏��

	// �T�u����
	void DisplayPlyTehaiDetailTsumoAri(MJSTkinfo *tk, MJSPlayer *ply, int pnum, int x, int y);                          // ply��v�̏ڍ׏��(���̗L�莞)
	void DisplayPlyTehaiDetailTsumoNashi(MJSTkinfo *tk, MJSPlayer *ply, int pnum, int x, int y);                        // ply��v�̏ڍ׏��(���̖�����)
	void DisplaySutekoho(MJSTkinfo *tk, MJSPlayer *ply, int pnum, int x, int y, int sutenum);                           // �̔v���

	// ------------------------------------------------------------------- 
	// �֐���`(�ݒ���)
	// ------------------------------------------------------------------- 

	// �ݒ���
	void DisplayRule();                                // ���[���\��
	void DisplayParamSet(MJSTkinfo *tk);               // �p�����[�^�ݒ�
	void DisplayTotalScore();                          // ���ѕ\��

};

#endif/* MJSDISPLAY_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- */
// �\�[�X�I��
/* ---------------------------------------------------------------------------------------------- */
