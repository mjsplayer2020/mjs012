/* ---------------------------------------------------------------------------------------------- 
 * 
 * �v���O�����T�v �F �����疃��(Ver0.1.2�F�J����)
 * �o�[�W����     �F 0.1.2.0.183(�a�����ʎq���\���̏C��)
 * �v���O������   �F mjs.exe
 * �t�@�C����     �F score.h
 * �N���X��       �F MJSScore�N���X
 * �����T�v       �F ���_�v�Z�N���X(�V)
 * Ver0.1.2�쐬�� �F 2023/11/04 09:10:01
 * �ŏI�X�V��     �F 2024/08/18 11:40:12
 * 
 * Copyright (c) 2010-2024 Techmilestone, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#pragma once

#ifndef MJSSCORE_H_INCLUDED
#define MJSSCORE_H_INCLUDED

#include "common.h"

/* ---------------------------------------------------------------------------------------------- */
// �Œ�l
/* ---------------------------------------------------------------------------------------------- */

// �|�萔
#define NORMAL_FU_SCORE_COUNT    10     // �ʏ�_�̕���
#define NORMAL_HAN_SCORE_COUNT    4     // �ʏ�_�̖|��
#define MANGAN_HAN_SCORE_COUNT    5     // ���шȏ�̖|��

/* ---------------------------------------------------------------------------------------------- */
//  �\����
/* ---------------------------------------------------------------------------------------------- */
// �����\����
struct MJSYakuinfo{

	// -----------------------------
	// ���ǎ�
	// -----------------------------
	bool ryukyoku_flg;                       // ���ǂł���̂��H
	LBRKStat ryukyoku_stat;                  // �ǏI�����
	int  ply_tempai_count;                   // �e���p�C���Ă���v���[���[��
	bool ply_tempai_flg[PLAYER_MAX];         // �v���[�����Ƃ̃e���p�C

	// ���_���
	int kyoku_score[PLAYER_MAX];             // �e�ǂ̍ŏI���_(���[�`�_�A�c�~�_����)

	// -----------------------------
	// �a���v���[���[
	// -----------------------------

	int agari_ply_num;                       // �a���v���[���[
	int furikomi_ply_num;                    // �U���v���[���[

	// -----------------------------
	// �a�����
	// -----------------------------

	// �a�����
	LBAgariTehai agari_stat;                 // �a���`��
	int ie[PLAYER_MAX];                      // �Ə��
	bool agari_ply_oya_flg;                  // �a���v���[���[���e�ł���̂��H
	bool tsumo_agari_flg;                    // ���̘a���ł���̂��H
	bool menzen_flg;                         // �ʑO�ł���̂��H

	// �a�����(���[�`)
	bool riichi_flg;                         // �ʏ탊�[�`�������Ă��邩�H
	bool w_riichi_flg;                       // �_�u�����[�`�������Ă��邩�H
	bool ippatsu_riichi_flg;                 // ���[�`�ꔭ�̏�Ԃł���̂��H
	int agari_ply_tsumo_count;               // �a���v���[���[�̎��̉�
	int agari_ply_riichi_count;              // �a���v���[���[�̃��[�`��̎��̉�

	// -----------------------------
	// �a���v
	// -----------------------------

	// �a���v
	int  agari_hai;                        // �a���������̔v�ԍ�
	bool agari_aka;                        // �a���������̔v�̐Ԕv�L��

	// �������
	int  agari_ata_hai;                    // �a�����_�̐����̔v�ԍ�
	int  agari_ata_aka;                    // �a�����_�̐����̐Ԕv����
	int  agari_ata_19zi;                   // �a�����_�̐����̃��I�`���E�L��(0:���� 1:���I�`���E 2:��v)
	int  atamaFu;                          // ������

	// �a���ʎq���
	int   agari_men_count;                  // �a�������c��
	LBMen agari_men_stat[MEN_MAX];          // �a�������c���
	int   agari_men_hai[MEN_MAX];           // �a�������c�v
	int   agari_men_aka_count[MEN_MAX];     // �a�������c�̐Ԕv��
	int   agari_men_Fu[MEN_MAX];            // �a�������c�̕�
	int   agari_men_19zi[MEN_MAX];          // �a�������c�̃��I�`���E�L��(0:���� 1:���I�`���E 2:��v)

	// �a���ʎq���(���Ύq)
	int agari_chitoi_men_hai[CHITOI_MEN_MAX];          // �a�������c�v(���Ύq)
	int agari_chitoi_men_aka_count[CHITOI_MEN_MAX];    // �a�������c�̐Ԕv��(���Ύq)

	// �a���v�̖ʎq�ԍ�
	int agari_men_num_agari_hai;            // �a���v���܂ޖʎq�̖ʎq�ԍ�

	// �҂��`��
	LBMen agari_machi_stat;                 // �a�����̑҂��`��

	// �h������
	int agari_dora_count;
	int agari_uradora_count;

	// �Ԗ���
	int agari_aka_count[AKA_TYPE_MAX_COUNT];  // �Ԕv����

	// �����ʂ̖ʎq��
	int mentsu_count_shuntsu;
	int mentsu_count_minshun;
	int mentsu_count_anko;
	int mentsu_count_minko;
	int mentsu_count_ankan;
	int mentsu_count_minkan;

	int mentsu_count_19zi;                   // ��㎚�̖ʎq��
	int mentsu_count_chunchan;               // �����v�̖ʎq��

	int mentsu_count_manzu;                  // �ݎq��
	int mentsu_count_pinzu;                  // ���q��
	int mentsu_count_souzu;                  // ���q��
	int mentsu_count_zihai;                  // ���v�̐�
	int mentsu_count_green;                  // �Δv�̐�

	// �a�����
	int agari_ply_bakaze;                    // �ꕗ�̔v�ԍ�
	int agari_ply_zikaze;                    // �����̔v�ԍ�

	// �ʎq�q�X�g�O����
	int anko_hist[PAI_MAX];
	int shuntsu_hist[PAI_MAX];

	/* ----------------------------- */
	// �Ǔ��_���(���E��)
	/* ----------------------------- */

	// ��
	int basefu;                              // ��b��
	int menzenFu;                            // �ʑO��
	int machiFu;                             // �҂���
	int tsumoFu;                             // ���̕�
	int totalFu;                             // ���̍��v
	int scoreFu;                             // ���̍��v(�؂�グ��)

	// �ʏ���̏��
	bool yaku_flg[YAKU_SHUBETSU_MAX];        // ���t���O
	int  yaku_han[YAKU_SHUBETSU_MAX];        // �����Ƃ̖|��
	int  yakucount;                          // ���̌�
	int  agari_ply_han;                      // �a���v���[���[�̍��v�|��
	int  agari_ply_mangan_count;             // �a���v���[���[�̖��шȏ��

	// �𖞂̏��
	bool yakuman_flg[YAKUMAN_SHUBETSU_MAX];  // �𖞃t���O
	int  yakuman_bai[YAKUMAN_SHUBETSU_MAX];  // �𖞂̔{��
	int  yakuman_count;                      // �𖞂̌�
	int  yakuman_agari_ply_bai;              // �a���{��

	// ���_��� - ����
	int agari_ply_ron;
	int agari_ply_tsumo_oya; 
	int agari_ply_tsumo_ko; 

};

/* ---------------------------------------------------------------------------------------------- */
// �N���X��`
/* ---------------------------------------------------------------------------------------------- */

class MJSScore{

	// ------------------------------------------------------------------- 
	// ���J�֐���`
	// ------------------------------------------------------------------- 
	public:

	// ------------------------------------------------------------------- 
	// �ϐ�(��)
	// ------------------------------------------------------------------- 

	// �|��
	int yakuhan[YAKU_SHUBETSU_MAX];
	int nakihan[YAKU_SHUBETSU_MAX];
	int yakuman_bai[YAKUMAN_SHUBETSU_MAX];       // ��{�𖞂ł��邩�ǂ���

	// ------------------------------------------------------------------- 
	// �ϐ�(���_)
	// ------------------------------------------------------------------- 

	// ���_�e�[�u���E�ʏ퓾�_
	int score_ron_oya[NORMAL_HAN_SCORE_COUNT][NORMAL_FU_SCORE_COUNT];
	int score_ron_ko[NORMAL_HAN_SCORE_COUNT][NORMAL_FU_SCORE_COUNT];
	int score_tsumo_oya[NORMAL_HAN_SCORE_COUNT][NORMAL_FU_SCORE_COUNT];
	int score_tsumo_ko[NORMAL_HAN_SCORE_COUNT][NORMAL_FU_SCORE_COUNT];

	// ���_�e�[�u���E���шȏ�
	int score_mangan_ron_oya[MANGAN_HAN_SCORE_COUNT];
	int score_mangan_ron_ko[MANGAN_HAN_SCORE_COUNT];
	int score_mangan_tsumo_oya[MANGAN_HAN_SCORE_COUNT];
	int score_mangan_tsumo_ko[MANGAN_HAN_SCORE_COUNT];

	// ���_�e�[�u���E���Ύq
	int score_chitoi_ron_oya[NORMAL_HAN_SCORE_COUNT];
	int score_chitoi_ron_ko[NORMAL_HAN_SCORE_COUNT];
	int score_chitoi_tsumo_oya[NORMAL_HAN_SCORE_COUNT];
	int score_chitoi_tsumo_ko[NORMAL_HAN_SCORE_COUNT];

	// ���_�e�[�u���E��
	int score_yakuman_ron_oya;
	int score_yakuman_ron_ko;
	int score_yakuman_tsumo_oya;
	int score_yakuman_tsumo_ko;

	// ------------------------------------------------------------------- 
	// �R���X�g���N�^
	// ------------------------------------------------------------------- 

	// �R���X�g���N�^
    MJSScore(){};

	// �f�X�g���N�^
    ~MJSScore(){};

	// ------------------------------------------------------------------- 
	// �֐���`
	// ------------------------------------------------------------------- 

	// �������E�㏈��
	void ScoreInit();                                       // ���_�v�Z�N���X�̏�����
	void ScorePost();                                       // ���_�v�Z�N���X�̏I������

	// ���O��`
	void SetYakuInfo();                                     // ������`
	void SetBaseScoreTable();                               // ��b���_�e�[�u���̐ݒ�

	// �a�����_�ݒ�(�ꎞ�m�F)
	void ChkAgariScoreInfo(MJSYakuinfo *yk);                // �a�����_�ݒ�(�ꎞ�m�F)

	// -----------------------------
	// ���_�m�F(�v������)
	// ��v�ʎq�e�[�u��
	// ���ʎq�e�[�u��
	// �A�N�V�����e�[�u��(���[�`�m�F�̂���)
	// -----------------------------

	void SetAgari(
	MJSYakuinfo *yk,          // �a�������\����
	int  kyoku,               // �ǔԍ�
	int  ie[],                // �v���[���̉Ə��
	int  dora_count,          // �\�h���v����
	int  dora[],              // �\�h���v���
	int  uradora_count,       // ���h���v����
	int  uradora[],           // ���h���v���
	LBAgariTehai  agari_stat, // �a���`��
	int  agari_ply_num,       // �a���v���[��
	int  furikomi_ply_num,    // �U���v���[��
	bool tsumoagari_flg,      // ���̘a���̗L��
	int  agari_hai,           // �a���v
	bool  agari_aka,          // �a���v�̐Ԕv�L��
	int  tehai_hist[],        // �a�����̎�v�q�X�g�O����
	int  aka_count[],         // ��v�̐Ԕv����
	int  atama_hai,           // ���v
	int  men_count,           // �ʎq��
	LBMen men_stat[],         // �ʎq���
	int  men_hai[],           // �ʎq�v
	int  men_idx[],           // �ʎqINDEX
	int  nakimen_count,       // ���ʎq��
	LBMen nakimen_stat[],     // ���ʎq���
	int  nakimen_hai[],       // ���ʎq�v
	int  nakimen_idx[],       // ���ʎqINDEX
	int  nakimen_aka[],       // ���ʎq�Ԕv����
	int  act_count,           // actid�̍��v��
	LBTkSt  act_stat[],       // �A�N�V�������
	int  act_ply[]            // �A�N�V�����v���[���[
	);

	// ���_�m�F(�T�u����)
	void Chk_initAgariScore(MJSYakuinfo *yk);               // 01:����������

	void Chk_preAgariScore(                                 // 02:���O�a�����̐ݒ�
	MJSYakuinfo *yk,                                        // �a�������\����
	int  atama_hai,                                         // ���v
	int  men_count,                                         // �ʎq��
	LBMen men_stat[],                                       // �ʎq���
	int  men_hai[],                                         // �ʎq�v
	int  men_idx[],                                         // �ʎqINDEX
	int  nakimen_count,                                     // ���ʎq��
	LBMen nakimen_stat[],                                   // ���ʎq���
	int  nakimen_hai[],                                     // ���ʎq�v
	int  nakimen_idx[],                                     // ���ʎqINDEX
	int  nakimen_aka[],                                     // ���ʎq�Ԕv����
	int  act_count,                                         // actid�̍��v��
	LBTkSt  act_stat[],                                     // �A�N�V�������
	int  act_ply[]                                          // �A�N�V�����v���[���[
	);

	void Chk_mentsu(MJSYakuinfo *yk);                       // 03:�ʎq�m�F
	void Chk_tehai_count(MJSYakuinfo *yk);                  // 04:��v�����m�F
	void Chk_fu(MJSYakuinfo *yk);                           // 05:���v�Z
	void Chk_yaku(MJSYakuinfo *yk, int tehai_hist[]);       // 06:���m�F
	void Chk_score(MJSYakuinfo *yk);                        // 07:���_�v�Z

	// ���_�m�F(�T�u�����E���Ύq�E���m)
	void Chk_chitoi_mentsu(MJSYakuinfo *yk);                // 03-01:�ʎq�m�F(���Ύq)
	void Chk_kokushi_mentsu(MJSYakuinfo *yk);               // 03-02:�ʎq�m�F(���m)

	// �h������
	void Chk_tehai_dora_count(int rinshan, bool ura_chk);   // �h�������̊m�F
	int  Get_dora_hai(int dora_hai);                        // �h���\���v���h���v�̕ϊ�

	// ���m�F
	void ChkYakuRiich(MJSYakuinfo *yk);                     // ���[�`�n
	void ChkYakuChitoiIpeko(MJSYakuinfo *yk);               // ���Ύq�A��u���A��u�� 
	void ChkYakuChinItsu_HonItsu(MJSYakuinfo *yk);          // ���ꍬ��n
	void ChkYakuAnko(MJSYakuinfo *yk);                      // �Í��n
	void ChkYakuChanta(MJSYakuinfo *yk);                    // �`�����^�n
	void ChkYakuSanshoku(MJSYakuinfo *yk);                  // �O�F�n
	void ChkYakuItsu(MJSYakuinfo *yk);                      // ��ʌn
	void ChkYakuPinfu(MJSYakuinfo *yk);                     // ���a�n
	void ChkYakuTanyao(MJSYakuinfo *yk);                    // �^�����I�n
	void ChkYakuYakuhai(MJSYakuinfo *yk);                   // ��v�n
	void ChkYakuDaisangen(MJSYakuinfo *yk);                 // ��O���E���O��
	void ChkYakuDaisushi(MJSYakuinfo *yk);                  // ��l��a�E���l��a
	void ChkYakuKokushi(MJSYakuinfo *yk);                   // ���m���o
	void ChkYakuChuren(MJSYakuinfo *yk, int tehai_hist[]);  // ��A��
	void ChkYakuTenho(MJSYakuinfo *yk);                     // �V�a
	void ChkYakuEtc(MJSYakuinfo *yk);                       // ���̑��̎��

	// �r�v����
	void SetHowanpaiScore(MJSYakuinfo *yk);                 // �r�v�����_�ݒ�

};

#endif /* MJSSCORE_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- */
// �\�[�X�I��
/* ---------------------------------------------------------------------------------------------- */
