/* ---------------------------------------------------------------------------------------------- 
 * 
 * �v���O�����T�v �F New�����疃��(MJAI�N���C�A���g������)
 * �o�[�W����     �F 0.1.2.0.164(OldScore�N���X�폜)
 * �v���O������   �F mjs.exe
 * �t�@�C����     �F oldscore.h
 * �N���X��       �F MJSOldScore�N���X
 * �����T�v       �F ���_�v�Z�N���X�F�p�~�\��
 * Ver0.1.1�쐬�� �F 2022/07/24 10:32:05
 * Ver0.1.2�쐬�� �F 2022/08/31 22:19:54
 * �ŏI�X�V��     �F 2024/05/19 09:50:30
 * 
 * Copyright (c) 2010-2022 Techmilestone, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#pragma once

#ifndef MJSOLDSCORE_H_INCLUDED
#define MJSOLDSCORE_H_INCLUDED

#include "tkinfo.h"

/* ---------------------------------------------------------------------------------------------- */
// �N���X��`
/* ---------------------------------------------------------------------------------------------- */

class MJSOldScore{

	// ------------------------------------------------------------------- 
	// ���J�֐���`
	// ------------------------------------------------------------------- 
	public:

	// ------------------------------------------------------------------- 
	// �ϐ�(��)
	// ------------------------------------------------------------------- 

	// �|���e�[�u��
	int yakuhan[YAKU_SHUBETSU_MAX];
	int nakihan[YAKU_SHUBETSU_MAX];
	int yakuman_bai[YAKUMAN_SHUBETSU_MAX];       // ��{�𖞂ł��邩�ǂ���

	// �𖼏��
	// char yakuname[YAKU_SHUBETSU_MAX][20];        // ��𖼁E�ʏ��
	// char yakumanname[YAKUMAN_SHUBETSU_MAX][20];  // ��𖼁E��

	// ------------------------------------------------------------------- 
	// �ϐ�(���_)
	// ------------------------------------------------------------------- 

	// ���_�e�[�u���E�ʏ퓾�_
	int score_ron_oya[4][10];
	int score_ron_ko[4][10];
	int score_tsumo_oya[4][10];
	int score_tsumo_ko[4][10];

	// ���_�e�[�u���E���шȏ�
	int score_mangan_ron_oya[5];
	int score_mangan_ron_ko[5];
	int score_mangan_tsumo_oya[5];
	int score_mangan_tsumo_ko[5];

	// ���_�e�[�u���E���Ύq
	int score_chitoi_ron_oya[4];
	int score_chitoi_ron_ko[4];
	int score_chitoi_tsumo_oya[4];
	int score_chitoi_tsumo_ko[4];

	// ���_�e�[�u���E��
	int score_yakuman_ron_oya;
	int score_yakuman_ron_ko;
	int score_yakuman_tsumo_oya;
	int score_yakuman_tsumo_ko;

	// ------------------------------------------------------------------- 
	// �R���X�g���N�^
	// ------------------------------------------------------------------- 

	// �R���X�g���N�^
    MJSOldScore(){};

	// �f�X�g���N�^
    ~MJSOldScore(){};

	// ------------------------------------------------------------------- 
	// �֐���`
	// ------------------------------------------------------------------- 

	// �������E�㏈��
	void ScoreInit();                                             // ���_�v�Z�N���X�̏�����
	void ScorePost();                                             // ���_�v�Z�N���X�̏I������

	// ���O��`
	void SetYakuInfo();                                           // ������`
	void SetBaseScoreTable();                                     // ��b���_�e�[�u���̐ݒ�

	// �I�ǃ��C���֐�
	void setAgariScore(MJSTkinfo *tk, int kyoku_index);           // �a�����_���ʂ̐ݒ�(���C������)

	// �I�ǃT�u�֐�
	void chk_initAgariScore(MJSTkinfo *tk, int kyoku_index);      // 01:����������
	void chk_preAgariScore(MJSTkinfo *tk, int kyoku_index);       // 02:���O�a�����̐ݒ�
	void chk_mentsu(MJSTkinfo *tk, int kyoku_index);              // 03:�ʎq�m�F
	void chk_tehai_count(MJSTkinfo *tk, int kyoku_index);         // 04:��v�����m�F
	void chk_fu(MJSTkinfo *tk, int kyoku_index);                  // 05:���v�Z
	void chk_yaku(MJSTkinfo *tk, int kyoku_index);                // 06:���m�F
	void chk_score(MJSTkinfo *tk, int kyoku_index);               // 07:���_�v�Z

	// �I�ǃT�u�֐�(���Ύq�E���m)
	void chk_chitoi_mentsu(MJSTkinfo *tk, int kyoku_index);       // 03:�ʎq�m�F(���Ύq)
	void chk_kokushi_mentsu(MJSTkinfo *tk, int kyoku_index);      // 03:�ʎq�m�F(���m)

	// ���_�v�Z�T�u����
	void Chk_kyokuscore(MJSTkinfo *tk, int kyoku_index);          // �ǂ̓��_���x
	void Chk_totalscore(MJSTkinfo *tk, int kyoku_index);          // ���v���_�̉��Z

	// �h������
	void Chk_tehai_dora_count(MJSTkinfo *tk, int kyoku_index, int rinshan, bool ura_chk);     // �h�������̊m�F
	int Get_dora_hai(int dora_hai);                                                           // �h���\���v���h���v�̕ϊ�

	// ���m�F
	void ChkYakuRiich(MJSTkinfo *tk, int kyoku_index);            // ���[�`�n
	void ChkYakuChitoiIpeko(MJSTkinfo *tk, int kyoku_index);      // ���Ύq�A��u���A��u�� 
	void ChkYakuChinItsu_HonItsu(MJSTkinfo *tk, int kyoku_index); // ���ꍬ��n
	void ChkYakuAnko(MJSTkinfo *tk, int kyoku_index);             // �Í��n
	void ChkYakuChanta(MJSTkinfo *tk, int kyoku_index);           // �`�����^�n
	void ChkYakuSanshoku(MJSTkinfo *tk, int kyoku_index);         // �O�F�n
	void ChkYakuItsu(MJSTkinfo *tk, int kyoku_index);             // ��ʌn
	void ChkYakuPinfu(MJSTkinfo *tk, int kyoku_index);            // ���a�n
	void ChkYakuTanyao(MJSTkinfo *tk, int kyoku_index);           // �^�����I�n
	void ChkYakuYakuhai(MJSTkinfo *tk, int kyoku_index);          // ��v�n
	void ChkYakuDaisangen(MJSTkinfo *tk, int kyoku_index);        // ��O���E���O��
	void ChkYakuDaisushi(MJSTkinfo *tk, int kyoku_index);         // ��l��a�E���l��a
	void ChkYakuKokushi(MJSTkinfo *tk, int kyoku_index);          // ���m���o
	void ChkYakuChuren(MJSTkinfo *tk, int kyoku_index);           // ��A��
	void ChkYakuTenho(MJSTkinfo *tk, int kyoku_index);            // �V�a
	void ChkYakuEtc(MJSTkinfo *tk, int kyoku_index);              // ���̑��̎��

	// �r�v����
	void SetHowanpaiScore(MJSTkinfo *tk, int kyoku_index);        // �r�v�����_�ݒ�

};

#endif /* MJSOLDSCORE_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- */
// �\�[�X�I��
/* ---------------------------------------------------------------------------------------------- */
