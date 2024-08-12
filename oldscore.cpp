/* ---------------------------------------------------------------------------------------------- 
 * 
 * �v���O�����T�v �F New�����疃��(MJAI�N���C�A���g������)
 * �o�[�W����     �F 0.1.2.0.164(OldScore�N���X�폜)
 * �v���O������   �F mjs.exe
 * �t�@�C����     �F oldscore.cpp
 * �N���X��       �F MJSOldScore�N���X
 * �����T�v       �F ���_�v�Z�N���X�F�p�~�\��
 * Ver0.1.1�쐬�� �F 2022/07/24 10:32:05
 * Ver0.1.2�쐬�� �F 2022/08/31 22:19:54
 * �ŏI�X�V��     �F 2024/05/19 09:50:30
 * 
 * Copyright (c) 2010-2023 Techmilestone, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#include "oldscore.h"

/* ---------------------------------------------------------------------------------------------- */
// ���_�v�Z�N���X�̏�����
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ScoreInit(){

}

/* ---------------------------------------------------------------------------------------------- */
// ���_�v�Z�N���X�̏I������
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ScorePost(){

}

/* ---------------------------------------------------------------------------------------------- */
// ���_�v�Z�̃��C������
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::setAgariScore(MJSTkinfo *tk, int kyoku_index){

	// ���O��`
	SetYakuInfo();
	SetBaseScoreTable();

	// ���C������
	chk_initAgariScore(tk, kyoku_index);    // 01:
	chk_preAgariScore(tk, kyoku_index);     // 02:

	// �ʏ�`���̏ꍇ
	if(tk->kyoku[kyoku_index].agari_stat == AGARI_NORMAL){
		chk_mentsu(tk, kyoku_index);
		chk_tehai_count(tk, kyoku_index);
		chk_fu(tk, kyoku_index);
	}else if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){
		chk_chitoi_mentsu(tk, kyoku_index);
	}else if(tk->kyoku[kyoku_index].agari_stat == AGARI_KOKUSHI){
		chk_kokushi_mentsu(tk, kyoku_index);
	}

	chk_yaku(tk, kyoku_index);
	chk_score(tk, kyoku_index);

}

/* ---------------------------------------------------------------------------------------------- */
// ������`
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::SetYakuInfo(){

	// �n������`�E�ʏ��
	yakuhan[NOYAKU]     = 0;
	yakuhan[RIICH]      = 1;
	yakuhan[WRIICH]     = 2;
	yakuhan[IPPATSU]    = 1;
	yakuhan[CHINISO]    = 6;
	yakuhan[HONISO]     = 3;
	yakuhan[JUNCHAN]    = 3;
	yakuhan[RYANPEKO]   = 3;
	yakuhan[HONROTO]    = 2;
	yakuhan[SHOSANGEN]  = 2;
	yakuhan[ITSU]       = 2;
	yakuhan[SANDOKOU]   = 2;
	yakuhan[SANDOJUN]   = 2;
	yakuhan[SANKANTSU]  = 2;
	yakuhan[SANANKO]    = 2;
	yakuhan[TOITOI]     = 2;
	yakuhan[CHANTA]     = 2;
	yakuhan[CHITOI]     = 2;
	yakuhan[PINFU]      = 1;
	yakuhan[TANYAO]     = 1;
	yakuhan[IPEKO]      = 1;
	yakuhan[BAKAZE]     = 1;
	yakuhan[ZIKAZE]     = 1;
	yakuhan[YAKUHAIHAKU]  = 1;
	yakuhan[YAKUHAIHATSU] = 1;
	yakuhan[YAKUHAICHUN]  = 1;
	yakuhan[HAITEI]  = 1;
	yakuhan[HOUTEI]  = 1;
	yakuhan[RINSHAN] = 1;
	yakuhan[CHANKAN] = 1;
	yakuhan[TSUMO]   = 1;
	yakuhan[DORA]    = 0;
	yakuhan[URADORA] = 0;
	yakuhan[AKAHAI]  = 0;
	yakuhan[RENHO]   = 5;
	yakuhan[NAGASHIMAN] = 5;

	// �n������`�E�ʏ���F������
	nakihan[NOYAKU]     = 0;
	nakihan[RIICH]      = 0;
	nakihan[WRIICH]     = 0;
	nakihan[IPPATSU]    = 0;
	nakihan[CHINISO]    = 5;
	nakihan[HONISO]     = 2;
	nakihan[JUNCHAN]    = 2;
	nakihan[RYANPEKO]   = 0;
	nakihan[HONROTO]    = 2;
	nakihan[SHOSANGEN]  = 2;
	nakihan[ITSU]       = 1;
	nakihan[SANDOKOU]   = 2;
	nakihan[SANDOJUN]   = 1;
	nakihan[SANKANTSU]  = 2;
	nakihan[SANANKO]    = 2;
	nakihan[TOITOI]     = 2;
	nakihan[CHANTA]     = 1;
	nakihan[CHITOI]     = 0;
	nakihan[PINFU]      = 0;
	nakihan[TANYAO]     = 1;
	nakihan[IPEKO]      = 0;
	nakihan[BAKAZE]     = 1;
	nakihan[ZIKAZE]     = 1;
	nakihan[YAKUHAIHAKU]  = 1;
	nakihan[YAKUHAIHATSU] = 1;
	nakihan[YAKUHAICHUN]  = 1;
	nakihan[HAITEI]     = 1;
	nakihan[HOUTEI]     = 1;
	nakihan[RINSHAN]    = 1;
	nakihan[CHANKAN]    = 1;
	nakihan[TSUMO]      = 0;
	nakihan[DORA]       = 0;
	nakihan[URADORA]    = 0;
	nakihan[AKAHAI]     = 0;
	nakihan[RENHO]      = 0;
	nakihan[NAGASHIMAN] = 5;

	// ��
	yakuman_bai[NOYAKUMAN]    = 0;
	yakuman_bai[TENHO]        = 1;
	yakuman_bai[CHIHO]        = 1;
	yakuman_bai[CHUREN9MEN]   = 1;
	yakuman_bai[CHUREN]       = 1;
	yakuman_bai[KOKUSHI13MEN] = 1;
	yakuman_bai[KOKUSHI]      = 1;
	yakuman_bai[DAISANGEN]    = 1;
	yakuman_bai[DAISUSHI]     = 1;
	yakuman_bai[SHOSUSHI]     = 1;
	yakuman_bai[TSUISO]       = 1;
	yakuman_bai[CHINROTO]     = 1;
	yakuman_bai[RYUISO]       = 1;
	yakuman_bai[SUKANTSU]     = 1;
	yakuman_bai[SUANKOTANKI]  = 1;
	yakuman_bai[SUANKO]       = 1;
	yakuman_bai[RENHOYAKUMAN] = 1;

}

/* ---------------------------------------------------------------------------------------------- */
// ��b���_�e�[�u���̐ݒ�
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::SetBaseScoreTable(){

	// ���_���
	// https://mj-dragon.com/calc/index-score.html
	// http://yahoo-mbga.jp/page/stdgame/300001/majan_09.html

	// -----------------------------
	// �e����
	// -----------------------------

	// �e�����E��|
	score_ron_oya[0][0] = 0;    // 20��
	score_ron_oya[0][1] = 1500; // 30��
	score_ron_oya[0][2] = 2000; // 40��
	score_ron_oya[0][3] = 2400; // 50��
	score_ron_oya[0][4] = 2900; // 60��
	score_ron_oya[0][5] = 3400; // 70��
	score_ron_oya[0][6] = 3900; // 80��
	score_ron_oya[0][7] = 4400; // 90��
	score_ron_oya[0][8] = 4800; // 100��
	score_ron_oya[0][9] = 5300; // 110��

	// �e�����E��|
	score_ron_oya[1][0] = 2100;  // 20��
	score_ron_oya[1][1] = 2900;  // 30��
	score_ron_oya[1][2] = 3900;  // 40��
	score_ron_oya[1][3] = 4800;  // 50��
	score_ron_oya[1][4] = 5800;  // 60��
	score_ron_oya[1][5] = 6800;  // 70��
	score_ron_oya[1][6] = 7700;  // 80��
	score_ron_oya[1][7] = 8700;  // 90��
	score_ron_oya[1][8] = 9600;  // 100��
	score_ron_oya[1][9] = 10600; // 110��

	// �e�����E�O�|
	score_ron_oya[2][0] = 3900;  // 20��
	score_ron_oya[2][1] = 5800;  // 30��
	score_ron_oya[2][2] = 7700;  // 40��
	score_ron_oya[2][3] = 9600;  // 50��
	score_ron_oya[2][4] = 11600; // 60��
	score_ron_oya[2][5] = 12000; // 70��
	score_ron_oya[2][6] = 12000; // 80��
	score_ron_oya[2][7] = 12000; // 90��
	score_ron_oya[2][8] = 12000; // 100��
	score_ron_oya[2][9] = 12000; // 110��

	// �e�����E�l�|
	score_ron_oya[3][0] =  5800; // 20��
	score_ron_oya[3][1] = 11600; // 30��
	score_ron_oya[3][2] = 12000; // 40��
	score_ron_oya[3][3] = 12000; // 50��
	score_ron_oya[3][4] = 12000; // 60��
	score_ron_oya[3][5] = 12000; // 70��
	score_ron_oya[3][6] = 12000; // 80��
	score_ron_oya[3][7] = 12000; // 90��
	score_ron_oya[3][8] = 12000; // 100��
	score_ron_oya[3][9] = 12000; // 110��

	// �e�����E���Ύq
	score_chitoi_ron_oya[0] = 1200;  // ��|25��
	score_chitoi_ron_oya[1] = 2400;  // ��|25��
	score_chitoi_ron_oya[2] = 4800;  // �O�|25��
	score_chitoi_ron_oya[3] = 9600;  // �l�|25��

	// �e�����E���шȏ�
	score_mangan_ron_oya[0] = 12000; // ����
	score_mangan_ron_oya[1] = 18000; // ����
	score_mangan_ron_oya[2] = 24000; // �{��
	score_mangan_ron_oya[3] = 36000; // �O�{��
	score_mangan_ron_oya[4] = 48000; // ������

	// �e�����E��
	score_yakuman_ron_oya = 48000;

	// -----------------------------
	// �q����
	// -----------------------------

	// �q�����E��|
	score_ron_ko[0][0] = 0;    // 20��
	score_ron_ko[0][1] = 1000; // 30��
	score_ron_ko[0][2] = 1300; // 40��
	score_ron_ko[0][3] = 1600; // 50��
	score_ron_ko[0][4] = 2000; // 60��
	score_ron_ko[0][5] = 2300; // 70��
	score_ron_ko[0][6] = 2600; // 80��
	score_ron_ko[0][7] = 2900; // 90��
	score_ron_ko[0][8] = 3200; // 100��
	score_ron_ko[0][9] = 3600; // 110��

	// �q�����E��|
	score_ron_ko[1][0] = 1300; // 20��
	score_ron_ko[1][1] = 2000; // 30��
	score_ron_ko[1][2] = 2600; // 40��
	score_ron_ko[1][3] = 3200; // 50��
	score_ron_ko[1][4] = 3900; // 60��
	score_ron_ko[1][5] = 4500; // 70��
	score_ron_ko[1][6] = 5200; // 80��
	score_ron_ko[1][7] = 5800; // 90��
	score_ron_ko[1][8] = 6400; // 100��
	score_ron_ko[1][9] = 7100; // 110��

	// �q�����E�O�|
	score_ron_ko[2][0] = 2600; // 20��
	score_ron_ko[2][1] = 3900; // 30��
	score_ron_ko[2][2] = 5200; // 40��
	score_ron_ko[2][3] = 6400; // 50��
	score_ron_ko[2][4] = 7700; // 60��
	score_ron_ko[2][5] = 8000; // 70��
	score_ron_ko[2][6] = 8000; // 80��
	score_ron_ko[2][7] = 8000; // 90��
	score_ron_ko[2][8] = 8000; // 100��
	score_ron_ko[2][9] = 8000; // 110��

	// �q�����E�l�|
	score_ron_ko[3][0] = 5200; // 20��
	score_ron_ko[3][1] = 7700; // 30��
	score_ron_ko[3][2] = 8000; // 40��
	score_ron_ko[3][3] = 8000; // 50��
	score_ron_ko[3][4] = 8000; // 60��
	score_ron_ko[3][5] = 8000; // 70��
	score_ron_ko[3][6] = 8000; // 80��
	score_ron_ko[3][7] = 8000; // 90��
	score_ron_ko[3][8] = 8000; // 100��
	score_ron_ko[3][9] = 8000; // 110��

	// �q�����E���Ύq
	score_chitoi_ron_oya[0] =  800;  // ��|25��
	score_chitoi_ron_oya[1] = 1600;  // ��|25��
	score_chitoi_ron_oya[2] = 3200;  // �O�|25��
	score_chitoi_ron_oya[3] = 6400;  // �l�|25��

	// �q�����E���шȏ�
	score_mangan_ron_ko[0] =  8000; // ����
	score_mangan_ron_ko[1] = 12000; // ����
	score_mangan_ron_ko[2] = 16000; // �{��
	score_mangan_ron_ko[3] = 24000; // �O�{��
	score_mangan_ron_ko[4] = 32000; // ������

	// �q�����E��
	score_yakuman_ron_ko = 32000;

	// -----------------------------
	// ���̘a���E�e�x����
	// -----------------------------

	// ���̘a���e�x�����E��|
	score_tsumo_oya[0][0] =    0; // 20��
	score_tsumo_oya[0][1] =  500; // 30��
	score_tsumo_oya[0][2] =  700; // 40��
	score_tsumo_oya[0][3] =  800; // 50��
	score_tsumo_oya[0][4] = 1000; // 60��
	score_tsumo_oya[0][5] = 1200; // 70��
	score_tsumo_oya[0][6] = 1300; // 80��
	score_tsumo_oya[0][7] = 1500; // 90��
	score_tsumo_oya[0][8] = 1600; // 100��
	score_tsumo_oya[0][9] = 1800; // 110��

	// ���̘a���e�x�����E��|
	score_tsumo_oya[1][0] =  700; // 20��
	score_tsumo_oya[1][1] = 1000; // 30��
	score_tsumo_oya[1][2] = 1300; // 40��
	score_tsumo_oya[1][3] = 1600; // 50��
	score_tsumo_oya[1][4] = 2000; // 60��
	score_tsumo_oya[1][5] = 2300; // 70��
	score_tsumo_oya[1][6] = 2600; // 80��
	score_tsumo_oya[1][7] = 2900; // 90��
	score_tsumo_oya[1][8] = 3200; // 100��
	score_tsumo_oya[1][9] = 3600; // 110��

	// ���̘a���e�x�����E�O�|
	score_tsumo_oya[2][0] = 1300; // 20��
	score_tsumo_oya[2][1] = 2000; // 30��
	score_tsumo_oya[2][2] = 2600; // 40��
	score_tsumo_oya[2][3] = 3200; // 50��
	score_tsumo_oya[2][4] = 3900; // 60��
	score_tsumo_oya[2][5] = 4000; // 70��
	score_tsumo_oya[2][6] = 4000; // 80��
	score_tsumo_oya[2][7] = 4000; // 90��
	score_tsumo_oya[2][8] = 4000; // 100��
	score_tsumo_oya[2][9] = 4000; // 110��

	// ���̘a���e�x�����E�l�|
	score_tsumo_oya[3][0] = 2600; // 20��
	score_tsumo_oya[3][1] = 3900; // 30��
	score_tsumo_oya[3][2] = 4000; // 40��
	score_tsumo_oya[3][3] = 4000; // 50��
	score_tsumo_oya[3][4] = 4000; // 60��
	score_tsumo_oya[3][5] = 4000; // 70��
	score_tsumo_oya[3][6] = 4000; // 80��
	score_tsumo_oya[3][7] = 4000; // 90��
	score_tsumo_oya[3][8] = 4000; // 100��
	score_tsumo_oya[3][9] = 4000; // 110��

	// ���̘a���e�x�����E���Ύq
	score_chitoi_tsumo_oya[0] =  400;
	score_chitoi_tsumo_oya[1] =  800;
	score_chitoi_tsumo_oya[2] = 1600;
	score_chitoi_tsumo_oya[3] = 3200;

	// ���̘a���e�x�����E���шȏ�
	score_mangan_tsumo_oya[0] =  4000;
	score_mangan_tsumo_oya[1] =  6000;
	score_mangan_tsumo_oya[2] =  8000;
	score_mangan_tsumo_oya[3] = 12000;
	score_mangan_tsumo_oya[4] = 16000;

	// ���̘a���e�x�����E��
	score_yakuman_tsumo_oya = 16000;

	// -----------------------------
	// ���̘a���E�q�x����
	// -----------------------------

	// ���̘a���q�x�����E��|
	score_tsumo_ko[0][0] = 0;    // 20��
	score_tsumo_ko[0][1] = 300;  // 30��
	score_tsumo_ko[0][2] = 400;  // 40��
	score_tsumo_ko[0][3] = 400;  // 50��
	score_tsumo_ko[0][4] = 500;  // 60��
	score_tsumo_ko[0][5] = 600;  // 70��
	score_tsumo_ko[0][6] = 700;  // 80��
	score_tsumo_ko[0][7] = 800;  // 90��
	score_tsumo_ko[0][8] = 800;  // 100��
	score_tsumo_ko[0][9] = 900;  // 110��

	// ���̘a���q�x�����E��|
	score_tsumo_ko[1][0] =  400;  // 20��
	score_tsumo_ko[1][1] =  500;  // 30��
	score_tsumo_ko[1][2] =  700;  // 40��
	score_tsumo_ko[1][3] =  800;  // 50��
	score_tsumo_ko[1][4] = 1000;  // 60��
	score_tsumo_ko[1][5] = 1200;  // 70��
	score_tsumo_ko[1][6] = 1300;  // 80��
	score_tsumo_ko[1][7] = 1500;  // 90��
	score_tsumo_ko[1][8] = 1600;  // 100��
	score_tsumo_ko[1][9] = 1800;  // 110��

	// ���̘a���q�x�����E�O�|
	score_tsumo_ko[2][0] =  700; // 20��
	score_tsumo_ko[2][1] = 1000; // 30��
	score_tsumo_ko[2][2] = 1300; // 40��
	score_tsumo_ko[2][3] = 1600; // 50��
	score_tsumo_ko[2][4] = 2000; // 60��
	score_tsumo_ko[2][5] = 2000; // 70��
	score_tsumo_ko[2][6] = 2000; // 80��
	score_tsumo_ko[2][7] = 2000; // 90��
	score_tsumo_ko[2][8] = 2000; // 100��
	score_tsumo_ko[2][9] = 2000; // 110��

	// ���̘a���q�x�����E�l�|
	score_tsumo_ko[3][0] = 1300; // 20��
	score_tsumo_ko[3][1] = 2000; // 30��
	score_tsumo_ko[3][2] = 2000; // 40��
	score_tsumo_ko[3][3] = 2000; // 50��
	score_tsumo_ko[3][4] = 2000; // 60��
	score_tsumo_ko[3][5] = 2000; // 70��
	score_tsumo_ko[3][6] = 2000; // 80��
	score_tsumo_ko[3][7] = 2000; // 90��
	score_tsumo_ko[3][8] = 2000; // 100��
	score_tsumo_ko[3][9] = 2000; // 110��

	// ���̘a���q�x�����E���Ύq
	score_chitoi_tsumo_ko[0] =  200;
	score_chitoi_tsumo_ko[1] =  400;
	score_chitoi_tsumo_ko[2] =  800;
	score_chitoi_tsumo_ko[3] = 1600;

	// ���̘a���q�x�����E���шȏ�
	score_mangan_tsumo_ko[0] = 2000;
	score_mangan_tsumo_ko[1] = 3000;
	score_mangan_tsumo_ko[2] = 4000;
	score_mangan_tsumo_ko[3] = 6000;
	score_mangan_tsumo_ko[4] = 8000;

	// ���̘a���q�x�����E��
	score_yakuman_tsumo_ko   = 8000;

}

/* ---------------------------------------------------------------------------------------------- */
// 01:����������
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_initAgariScore(MJSTkinfo *tk, int kyoku_index){

	// �a���v�ʎq
	tk->kyoku[kyoku_index].agari_men_num_agari_hai = 999;

	// �h��
	tk->kyoku[kyoku_index].agari_dora_count=0; 
	tk->kyoku[kyoku_index].agari_uradora_count=0;

	// �Ԕv
	tk->kyoku[kyoku_index].agari_aka_count[0]=0;
	tk->kyoku[kyoku_index].agari_aka_count[1]=0;
	tk->kyoku[kyoku_index].agari_aka_count[2]=0;

	// �ʎq��
	tk->kyoku[kyoku_index].mentsu_count_shuntsu = 0;
	tk->kyoku[kyoku_index].mentsu_count_minshun = 0;
	tk->kyoku[kyoku_index].mentsu_count_anko    = 0;
	tk->kyoku[kyoku_index].mentsu_count_minko   = 0;
	tk->kyoku[kyoku_index].mentsu_count_ankan   = 0;
	tk->kyoku[kyoku_index].mentsu_count_minkan  = 0;

	tk->kyoku[kyoku_index].mentsu_count_19zi = 0;
	tk->kyoku[kyoku_index].mentsu_count_chunchan = 0;
	tk->kyoku[kyoku_index].mentsu_count_manzu = 0;
	tk->kyoku[kyoku_index].mentsu_count_pinzu = 0;
	tk->kyoku[kyoku_index].mentsu_count_souzu = 0;
	tk->kyoku[kyoku_index].mentsu_count_zihai = 0;
	tk->kyoku[kyoku_index].mentsu_count_green = 0;

	// ���̐ݒ�
	tk->kyoku[kyoku_index].basefu = 20;
	tk->kyoku[kyoku_index].agari_men_Fu[0]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[1]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[2]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[3]=0;
	tk->kyoku[kyoku_index].atamaFu=0;
	tk->kyoku[kyoku_index].menzenFu=0;
	tk->kyoku[kyoku_index].machiFu=0;
	tk->kyoku[kyoku_index].tsumoFu=0;

	// ���̍��v
	tk->kyoku[kyoku_index].totalFu = tk->kyoku[kyoku_index].basefu;
	tk->kyoku[kyoku_index].scoreFu = tk->kyoku[kyoku_index].totalFu;

}

/* ---------------------------------------------------------------------------------------------- */
// 02:���O�a�����̐ݒ�
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_preAgariScore(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// �Ǐ��̐ݒ�
	// -----------------------------

	// ���ǃt���O
	tk->kyoku[kyoku_index].ryukyoku_flg = false;

	// �ꕗ�����̐ݒ�
	tk->agari_ply_bakaze = 31;
	tk->agari_ply_zikaze = 31+tk->kyoku[kyoku_index].ie[tk->kyoku[kyoku_index].agari_ply_num];

	// �e�t���O�̐ݒ�
	if(tk->kyoku[kyoku_index].agari_ply_num == tk->kyoku[kyoku_index].kyoku_oya){
		tk->kyoku[kyoku_index].agari_ply_oya_flg = true;
	}else{
		tk->kyoku[kyoku_index].agari_ply_oya_flg = false;
	}

	// �ʑO�t���O�̐ݒ�
	if(tk->kyoku[kyoku_index].naki_count[tk->kyoku[kyoku_index].agari_ply_num] == 0){
		tk->kyoku[kyoku_index].menzen_flg = true;
	}else{
		tk->kyoku[kyoku_index].menzen_flg = false;
	}

	// -----------------------------
	// �a���v���[���[�̘a�����̉񐔁E���[�`��Ԋm�F(������)
	// -----------------------------

	tk->kyoku[kyoku_index].riichi_flg          = false;
	tk->kyoku[kyoku_index].ippatsu_riichi_flg  = false;
	tk->kyoku[kyoku_index].w_riichi_flg        = false;
	tk->kyoku[kyoku_index].agari_ply_tsumo_count  = 0;
	tk->kyoku[kyoku_index].agari_ply_riichi_count = 0;

	// -----------------------------
	// �a���v���[���[�̘a�����̉񐔁E���[�`��Ԋm�F(���C������)
	// -----------------------------

	// �A�N�V�����̊m�F
	for(int tmp_i = 0; tmp_i < tk->kyoku[kyoku_index].act_count+1; tmp_i++){

		// ���̉񐔃J�E���g
		if(tk->kyoku[kyoku_index].act_stat[tmp_i] == PLYACTTSUMO &&
		   tk->kyoku[kyoku_index].act_ply[tmp_i]  == tk->kyoku[kyoku_index].agari_ply_num ){
			// ���̃J�E���g
			tk->kyoku[kyoku_index].agari_ply_tsumo_count++;
		}

		// ���[�`�m�F
		if(tk->kyoku[kyoku_index].act_stat[tmp_i] == PLYACTRIICH &&
		   tk->kyoku[kyoku_index].act_ply[tmp_i]  == tk->kyoku[kyoku_index].agari_ply_num ){

			// ���[�`���[�h�ύX
			tk->kyoku[kyoku_index].riichi_flg=true;

			// �_�u�����[�`�m�F
			if(tk->kyoku[kyoku_index].agari_ply_tsumo_count == 1){
				// ���[�`���[�h�ύX
				tk->kyoku[kyoku_index].w_riichi_flg=true;
			}else{
				// ���[�`���[�h�ύX
				tk->kyoku[kyoku_index].w_riichi_flg=false;
			}	
	
			// ���[�`���ڂ̐ݒ�
			tk->kyoku[kyoku_index].agari_ply_riichi_count = tk->kyoku[kyoku_index].agari_ply_tsumo_count;

		}

		// ���[�`�ꔭ�m�F(���̘a��)
		if (tk->kyoku[kyoku_index].act_stat[tmp_i] == PLYTSUMOAGARI && 
			tk->kyoku[kyoku_index].riichi_flg == true &&
		    tk->kyoku[kyoku_index].act_ply[tmp_i]  == tk->kyoku[kyoku_index].agari_ply_num ){
			// �����ł���Έꔭ
			if(tk->kyoku[kyoku_index].agari_ply_riichi_count + 1 == tk->kyoku[kyoku_index].agari_ply_tsumo_count){
				// ���[�`���[�h�ύX
				tk->kyoku[kyoku_index].ippatsu_riichi_flg=true;
			}else{
				// ���[�`���[�h�ύX
				tk->kyoku[kyoku_index].ippatsu_riichi_flg=false;
			}
		}

		// ���[�`�ꔭ�m�F(�����a��)
		if (tk->kyoku[kyoku_index].act_stat[tmp_i] == PLYACTRON && 
			tk->kyoku[kyoku_index].riichi_flg == true &&
		    tk->kyoku[kyoku_index].act_ply[tmp_i]  == tk->kyoku[kyoku_index].agari_ply_num ){
			// �����ł���Έꔭ
			if(tk->kyoku[kyoku_index].agari_ply_riichi_count == tk->kyoku[kyoku_index].agari_ply_tsumo_count){
				// ���[�`���[�h�ύX
				tk->kyoku[kyoku_index].ippatsu_riichi_flg=true;
			}else{
				// ���[�`���[�h�ύX
				tk->kyoku[kyoku_index].ippatsu_riichi_flg=false;
			}
		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 03:���O�a�����̐ݒ�(���Ύq)
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_chitoi_mentsu(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// �ϐ���`
	// -----------------------------

	// �Ԕv��Ɨp
	int tmp_aka_man;
	int tmp_aka_pin;
	int tmp_aka_sou;

	tk->kyoku[kyoku_index].mentsu_count_19zi=0;                   // ��㎚�̖ʎq��
	tk->kyoku[kyoku_index].mentsu_count_chunchan=0;               // �����v�̖ʎq��

	tk->kyoku[kyoku_index].mentsu_count_manzu=0;                  // �ݎq��
	tk->kyoku[kyoku_index].mentsu_count_pinzu=0;                  // ���q��
	tk->kyoku[kyoku_index].mentsu_count_souzu=0;                  // ���q��
	tk->kyoku[kyoku_index].mentsu_count_zihai=0;                  // ���v�̐�

	// -----------------------------
	// �҂��`��
	// -----------------------------
	tk->kyoku[kyoku_index].agari_machi_stat = TANKI;

	// -----------------------------
	// ���̐ݒ�
	// -----------------------------
	tk->kyoku[kyoku_index].basefu = 25;
	tk->kyoku[kyoku_index].agari_men_Fu[0]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[1]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[2]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[3]=0;
	tk->kyoku[kyoku_index].atamaFu=0;
	tk->kyoku[kyoku_index].menzenFu=0;
	tk->kyoku[kyoku_index].machiFu=0;
	tk->kyoku[kyoku_index].tsumoFu=0;

	// ���̍��v
	tk->kyoku[kyoku_index].totalFu = tk->kyoku[kyoku_index].basefu;
	tk->kyoku[kyoku_index].scoreFu = tk->kyoku[kyoku_index].totalFu;

	// -----------------------------
	// �Ԕv������
	// -----------------------------

	// ��Ɨp�ϐ��̐ݒ�
	tmp_aka_man = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][0];
	tmp_aka_pin = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][1];
	tmp_aka_sou = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][2];

	// -----------------------------
	// �ʎq�m�F
	// -----------------------------
	int tmp_men_count=0;
	for(int tmp_hai=1; tmp_hai<PAI_MAX; tmp_hai++){
		// �a���ʎq�ԍ��ݒ�
		if(tk->kyoku[kyoku_index].agari_hai == tmp_hai){
			tk->kyoku[kyoku_index].agari_men_num_agari_hai = tmp_men_count;
		}

		// �������m�F
		if(tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][tmp_hai] > 1 ||
		   tk->kyoku[kyoku_index].agari_hai == tmp_hai){
			// �ʎq�ݒ�
			tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_men_count] = tmp_hai;
			tk->kyoku[kyoku_index].agari_chitoi_men_aka_count[tmp_men_count] = 0;
			tmp_men_count++;
		}

	}

	// -----------------------------
	// �e��v�̖����m�F
	// -----------------------------
	for(int tmp_i=0; tmp_i<7; tmp_i++){

		// -----------------------------
		// ��㎚�m�F
		// -----------------------------
		if (tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] ==  9 ||
		    tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 11 ||
	        tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 19 ||
		    tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 21 ||
		    tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 29 ||
		    tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 31 ||
		    tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 32 ||
		    tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 33 ||
	        tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 34 ||
	        tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 35 ||
		    tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 36 ||
		    tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] == 37 ){

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_19zi++;

		}else{

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_chunchan++;

		}

		// -----------------------------
		// �F����
		// -----------------------------
		if (tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] >  0 &&
		    tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] < 10 ){

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_manzu++;

		}else if ( tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] > 10 &&
		           tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] < 20 ){

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_pinzu++;

		}else if ( tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] > 20 &&
		           tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] < 30 ){

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_souzu++;

		}else if ( tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] > 30 &&
		           tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] < 38 ){

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_zihai++;

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 03:���O�a�����̐ݒ�(���m)
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_kokushi_mentsu(MJSTkinfo *tk, int kyoku_index){

	// �҂��`��
	tk->kyoku[kyoku_index].agari_machi_stat = TANKI;

	// ���̐ݒ�
	tk->kyoku[kyoku_index].basefu = 20;
	tk->kyoku[kyoku_index].agari_men_Fu[0]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[1]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[2]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[3]=0;
	tk->kyoku[kyoku_index].atamaFu=0;
	tk->kyoku[kyoku_index].menzenFu=0;
	tk->kyoku[kyoku_index].machiFu=0;
	tk->kyoku[kyoku_index].tsumoFu=0;

	// ���̍��v
	tk->kyoku[kyoku_index].totalFu = tk->kyoku[kyoku_index].basefu;
	tk->kyoku[kyoku_index].scoreFu = tk->kyoku[kyoku_index].totalFu;
}

/* ---------------------------------------------------------------------------------------------- */
// 03:�ʎq�m�F
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_mentsu(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// �ϐ���`
	// -----------------------------

	// �Ԕv��Ɨp
	int tmp_aka_man;
	int tmp_aka_pin;
	int tmp_aka_sou;

	tk->kyoku[kyoku_index].agari_aka_count[0] = 0;
	tk->kyoku[kyoku_index].agari_aka_count[1] = 0;
	tk->kyoku[kyoku_index].agari_aka_count[2] = 0;

	// -----------------------------
	// �Ԕv������
	// -----------------------------

	// ��Ɨp�ϐ��̐ݒ�
	tmp_aka_man = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][0];
	tmp_aka_pin = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][1];
	tmp_aka_sou = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][2];

	// -----------------------------
	// �������̐ݒ�
	// -----------------------------

	// �����ݒ�
	tk->kyoku[kyoku_index].agari_ata_hai = tk->atama_hai;

	// �a���v�̖ʎq�ԍ��ݒ�
	if (tk->kyoku[kyoku_index].agari_ata_hai == tk->kyoku[kyoku_index].agari_hai){

		// �ʎq�ԍ��͉��u���́u999�v�Ƃ���
		tk->kyoku[kyoku_index].agari_men_num_agari_hai = 999;

	}

	// �Ԕv�ݒ�
	tk->kyoku[kyoku_index].agari_ata_aka = 0;

	if(tk->kyoku[kyoku_index].agari_ata_hai == 5){
		if(tmp_aka_man>2){
			tk->kyoku[kyoku_index].agari_ata_aka=2;
			tmp_aka_man=tmp_aka_man-2;
		}else{
			tk->kyoku[kyoku_index].agari_ata_aka=tmp_aka_man;
			tmp_aka_man=0;
		}
	}

	if(tk->kyoku[kyoku_index].agari_ata_hai == 15){
		if(tmp_aka_pin>2){
			tk->kyoku[kyoku_index].agari_ata_aka=2;
			tmp_aka_pin=tmp_aka_pin-2;
		}else{
			tk->kyoku[kyoku_index].agari_ata_aka=tmp_aka_pin;
			tmp_aka_pin=0;
		}
	}

	if(tk->kyoku[kyoku_index].agari_ata_hai == 25){
		if(tmp_aka_sou>2){
			tk->kyoku[kyoku_index].agari_ata_aka=tmp_aka_sou=2;
			tmp_aka_sou=tmp_aka_sou-2;
		}else{
			tk->kyoku[kyoku_index].agari_ata_aka=tmp_aka_sou;
			tmp_aka_sou=0;
		}
	}

	// -----------------------------
	// �����c���̐ݒ�
	// -----------------------------
	for(int tmp_i = 0; tmp_i < tk->mentu_count; tmp_i++){

		// -----------------------------
		// �����c���̊i�[
		// -----------------------------

		tk->kyoku[kyoku_index].agari_men_stat[tmp_i]      = tk->mentu_stat[tmp_i];  
		tk->kyoku[kyoku_index].agari_men_hai[tmp_i]       = tk->mentu_hai[tmp_i];   
		tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i] = 0;                      // �Ԕv�̏�����

		// -----------------------------
		// �Í�����
		// -----------------------------
		if ( tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKO){

			// �ݎq����
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 5){
				if(tmp_aka_man>3){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=3;
					tmp_aka_man=tmp_aka_man-3;
				}else{
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=tmp_aka_man;
					tmp_aka_man=0;
				}
			}

			// ���q����
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 15){
				if(tmp_aka_pin>2){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=3;
					tmp_aka_pin=tmp_aka_pin-3;
				}else{
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=tmp_aka_pin;
					tmp_aka_pin=0;
				}
			}

			// ���q����
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 25){
				if(tmp_aka_sou>2){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=3;
					tmp_aka_sou=tmp_aka_sou-3;
				}else{
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=tmp_aka_sou;
					tmp_aka_sou=0;
				}
			}
		
			// �a���v�̖ʎq�ԍ��ݒ� - �Í��̏ꍇ
			if ( tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == tk->kyoku[kyoku_index].agari_hai){

				// �ʎq�ԍ��̐ݒ�
				tk->kyoku[kyoku_index].agari_men_num_agari_hai = tmp_i;

				// �����a���̖ʎq�ԍ��͖������c�ɕύX����
				if(tk->kyoku[kyoku_index].tsumo_agari_flg == false){
					tk->kyoku[kyoku_index].agari_men_stat[tmp_i] = MINKO;
				}

			}
		}

		// -----------------------------
		// ���q����
		// -----------------------------
		if ( tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == SHUNTSU){

			// �ݎq����
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 3 || 
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 4 ||
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 5){

				// �Ԕv������Ȃ�
				if(tmp_aka_man>0){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]++;
					tmp_aka_man--;
				}
			}

			// ���q����
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 13 || 
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 14 ||
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 15){

				// �Ԕv������Ȃ�
				if(tmp_aka_pin>0){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]++;
					tmp_aka_pin--;
				}
			}

			// ���q����
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 23 || 
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 24 ||
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 25){

				// �Ԕv������Ȃ�
				if(tmp_aka_sou>0){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]++;
					tmp_aka_sou--;
				}
			}

			// �a���v�̖ʎq�ԍ��ݒ� - ���q�̏ꍇ
			if ( tk->kyoku[kyoku_index].agari_men_hai[tmp_i]   == tk->kyoku[kyoku_index].agari_hai || 
			     tk->kyoku[kyoku_index].agari_men_hai[tmp_i]+1 == tk->kyoku[kyoku_index].agari_hai || 
			     tk->kyoku[kyoku_index].agari_men_hai[tmp_i]+2 == tk->kyoku[kyoku_index].agari_hai ){

				// �ʎq�ԍ��̐ݒ�
				tk->kyoku[kyoku_index].agari_men_num_agari_hai = tmp_i;

				// �����a���̖ʎq�ԍ��͖������c�ɕύX����
				if(tk->kyoku[kyoku_index].tsumo_agari_flg == false){
					tk->kyoku[kyoku_index].agari_men_stat[tmp_i] = MINSHUN;
				}
			}

		}

	}

	// -----------------------------
	// �N���ʎq�̐ݒ�
	// -----------------------------

	// �N���ʎq�̒ǉ�
	for(int tmp_i = 0; tmp_i < tk->kyoku[kyoku_index].naki_count[tk->kyoku[kyoku_index].agari_ply_num]; tmp_i++){

		// �J�J���m�F
		if( tk->kyoku[kyoku_index].naki_stat[tk->kyoku[kyoku_index].agari_ply_num][tmp_i] == KAKAN){

			// �J�J���ʎq�ݒ�
			for(int tmp_j = 0; tmp_j < tk->mentu_count; tmp_j++){

				// �J�J�������Í��ł����
				if(tk->kyoku[kyoku_index].agari_men_hai[tmp_j] == tk->kyoku[kyoku_index].naki_idx[tk->kyoku[kyoku_index].agari_ply_num][tmp_i]){

					// �����c���̊i�[(�J�J��)
					tk->kyoku[kyoku_index].agari_men_stat[tmp_j] = MINKAN;

					// �Ԕv+1���Z
					if( tk->kyoku[kyoku_index].naki_aka[tk->kyoku[kyoku_index].agari_ply_num][tmp_j] > 0){
						tk->kyoku[kyoku_index].agari_men_aka_count[tmp_j]++;
					}

				}
			}

		// �J�J���ȊO
		}else{

			// �����c���̊i�[
			tk->kyoku[kyoku_index].agari_men_stat[tk->mentu_count]       = tk->kyoku[kyoku_index].naki_stat[tk->kyoku[kyoku_index].agari_ply_num][tmp_i];
			tk->kyoku[kyoku_index].agari_men_hai[tk->mentu_count]        = tk->kyoku[kyoku_index].naki_idx[tk->kyoku[kyoku_index].agari_ply_num][tmp_i];
			tk->kyoku[kyoku_index].agari_men_aka_count[tk->mentu_count]  = tk->kyoku[kyoku_index].naki_aka[tk->kyoku[kyoku_index].agari_ply_num][tmp_i];
			tk->mentu_count++;

		}

	}

	// -----------------------------
	// �҂��`���̊m�F
	// -----------------------------

	// �P�R�҂��m�F
	if( tk->kyoku[kyoku_index].agari_men_num_agari_hai == 999){
		tk->kyoku[kyoku_index].agari_machi_stat = TANKI;

	// ���q�֘A�̑҂�
	}else if( tk->kyoku[kyoku_index].agari_men_stat[tk->kyoku[kyoku_index].agari_men_num_agari_hai] == SHUNTSU ||
              tk->kyoku[kyoku_index].agari_men_stat[tk->kyoku[kyoku_index].agari_men_num_agari_hai] == MINSHUN ){

		// �a���v���ʎqINDEX�Ɠ����Ȃ�
		if( tk->kyoku[kyoku_index].agari_men_hai[tk->kyoku[kyoku_index].agari_men_num_agari_hai] == tk->kyoku[kyoku_index].agari_hai ){

			// �y���`�����𒲂ׂ�
			if( tk->kyoku[kyoku_index].agari_hai ==  7 || 
			    tk->kyoku[kyoku_index].agari_hai == 17 || 
			    tk->kyoku[kyoku_index].agari_hai == 27 ){
				tk->kyoku[kyoku_index].agari_machi_stat = PENCHAN ; 
			}else{
				tk->kyoku[kyoku_index].agari_machi_stat = RYANMEN;
			}

		}

		// �a���v���ʎqINDEX+1�Ȃ�
		if( tk->kyoku[kyoku_index].agari_men_hai[tk->kyoku[kyoku_index].agari_men_num_agari_hai] + 1 == tk->kyoku[kyoku_index].agari_hai ){
			tk->kyoku[kyoku_index].agari_machi_stat = KANCHAN;
		}

		// �a���v���ʎqINDEX+2�Ȃ�
		if( tk->kyoku[kyoku_index].agari_men_hai[tk->kyoku[kyoku_index].agari_men_num_agari_hai] + 2 == tk->kyoku[kyoku_index].agari_hai ){

			// �y���`�����𒲂ׂ�
			if( tk->kyoku[kyoku_index].agari_hai ==  3 || 
			    tk->kyoku[kyoku_index].agari_hai == 13 || 
			    tk->kyoku[kyoku_index].agari_hai == 23 ){
				tk->kyoku[kyoku_index].agari_machi_stat = PENCHAN ; 
			}else{
				tk->kyoku[kyoku_index].agari_machi_stat = RYANMEN;
			}

		}

	// �V���|���҂��m�F
	}else if( tk->kyoku[kyoku_index].agari_men_stat[tk->kyoku[kyoku_index].agari_men_num_agari_hai] == ANKO  ||
              tk->kyoku[kyoku_index].agari_men_stat[tk->kyoku[kyoku_index].agari_men_num_agari_hai] == MINKO ){
				tk->kyoku[kyoku_index].agari_machi_stat = TOITSU;

	// ���̑�
	}else{
		tk->kyoku[kyoku_index].agari_machi_stat = NOMENTSU;
	}

	// -----------------------------
	// �h���J�E���g
	// -----------------------------

	// �J�E���g����
	Chk_tehai_dora_count(tk, kyoku_index, 0 , false);

	// -----------------------------
	// �Ԕv�J�E���g
	// -----------------------------

	tk->kyoku[kyoku_index].agari_aka_count[0] = 0;
	tk->kyoku[kyoku_index].agari_aka_count[1] = 0;
	tk->kyoku[kyoku_index].agari_aka_count[2] = 0;

	// ���ԃJ�E���g
	if(tk->kyoku[kyoku_index].agari_ata_hai == MAN5NUM){
		tk->kyoku[kyoku_index].agari_aka_count[0]=tk->kyoku[kyoku_index].agari_ata_aka;
	}else if(tk->kyoku[kyoku_index].agari_ata_hai == PIN5NUM){
		tk->kyoku[kyoku_index].agari_aka_count[1]=tk->kyoku[kyoku_index].agari_ata_aka;
	}else if(tk->kyoku[kyoku_index].agari_ata_hai == SOU5NUM){
		tk->kyoku[kyoku_index].agari_aka_count[2]=tk->kyoku[kyoku_index].agari_ata_aka;
	}

	// �ʎq�ԃJ�E���g
	for(int tmp_i = 0; tmp_i < 4; tmp_i++){

		// �ʎq�ԃJ�E���g - �ݎq
		if( tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == MAN3NUM || 
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == MAN4NUM ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == MAN5NUM ){

			// �Ԕv���Z
			tk->kyoku[kyoku_index].agari_aka_count[0] = tk->kyoku[kyoku_index].agari_aka_count[0] + tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i];

		// �ʎq�ԃJ�E���g - ���q
		}else if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == PIN3NUM ||
		         tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == PIN4NUM ||
		         tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == PIN5NUM ){

			// �Ԕv���Z
			tk->kyoku[kyoku_index].agari_aka_count[1] = tk->kyoku[kyoku_index].agari_aka_count[1] + tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i];

		// �ʎq�ԃJ�E���g - ���q
		}else if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == SOU3NUM ||
		         tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == SOU4NUM ||
		         tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == SOU5NUM ){

			// �Ԕv���Z
			tk->kyoku[kyoku_index].agari_aka_count[2] = tk->kyoku[kyoku_index].agari_aka_count[2] + tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i];

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 03:��v�����m�F
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_tehai_count(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// �e��v�̖����m�F
	// -----------------------------

	// �ϐ�������

	tk->kyoku[kyoku_index].mentsu_count_shuntsu = 0;
	tk->kyoku[kyoku_index].mentsu_count_minshun = 0;
	tk->kyoku[kyoku_index].mentsu_count_anko    = 0;
	tk->kyoku[kyoku_index].mentsu_count_minko   = 0;
	tk->kyoku[kyoku_index].mentsu_count_ankan   = 0;
	tk->kyoku[kyoku_index].mentsu_count_minkan  = 0;

	tk->kyoku[kyoku_index].mentsu_count_19zi     = 0;             // ��㎚�̐�
	tk->kyoku[kyoku_index].mentsu_count_chunchan = 0;             // �����v�̖ʎq��

	tk->kyoku[kyoku_index].mentsu_count_manzu    = 0;             // �ݎq��
	tk->kyoku[kyoku_index].mentsu_count_pinzu    = 0;             // ���q��
	tk->kyoku[kyoku_index].mentsu_count_souzu    = 0;             // ���q��
	tk->kyoku[kyoku_index].mentsu_count_zihai    = 0;             // ���v�̐�
	tk->kyoku[kyoku_index].mentsu_count_green    = 0;             // �Δv�̐�

	// �q�X�g�O�����̏�����
	for(int tmp_i = 0; tmp_i < PAI_MAX; tmp_i++){
		tk->anko_hist[tmp_i]    = 0;
		tk->shuntsu_hist[tmp_i] = 0;
	}

	// -----------------------------
	// �����m�F����
	// -----------------------------

		// -----------------------------
		// �����m�F����
		// -----------------------------

		// ��v�m�F
		if (tk->kyoku[kyoku_index].agari_ata_hai == tk->agari_ply_bakaze ||
		    tk->kyoku[kyoku_index].agari_ata_hai == tk->agari_ply_zikaze ||
		    tk->kyoku[kyoku_index].agari_ata_hai == 35 ||
	        tk->kyoku[kyoku_index].agari_ata_hai == 36 ||
		    tk->kyoku[kyoku_index].agari_ata_hai == 37 ){

			// ��v�ݒ�
			tk->kyoku[kyoku_index].agari_ata_19zi = 2; 

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_19zi++;

		// ��㎚�v�m�F
		}else if (tk->kyoku[kyoku_index].agari_ata_hai == 1 ||
		    tk->kyoku[kyoku_index].agari_ata_hai ==  9 ||
		    tk->kyoku[kyoku_index].agari_ata_hai == 11 ||
	        tk->kyoku[kyoku_index].agari_ata_hai == 19 ||
		    tk->kyoku[kyoku_index].agari_ata_hai == 21 ||
	        tk->kyoku[kyoku_index].agari_ata_hai == 29 ||
		    tk->kyoku[kyoku_index].agari_ata_hai == 31 ||
	        tk->kyoku[kyoku_index].agari_ata_hai == 32 ||
	        tk->kyoku[kyoku_index].agari_ata_hai == 33 ||
		    tk->kyoku[kyoku_index].agari_ata_hai == 34 ){

			// ��㎚�v�ݒ�
			tk->kyoku[kyoku_index].agari_ata_19zi = 1;

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_19zi++;

		// �����v�m�F
		}else{

			// �����v�ݒ�
			tk->kyoku[kyoku_index].agari_ata_19zi = 0;

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_chunchan++;

		}

		// -----------------------------
		// �ݎq�E���q�E���q�E���v�̖����m�F(����)
		// -----------------------------

		// �ݎq���Z
		if (tk->kyoku[kyoku_index].agari_ata_hai >  0 &&
		    tk->kyoku[kyoku_index].agari_ata_hai < 10 ){

			// �ݎq���Z
			tk->kyoku[kyoku_index].mentsu_count_manzu++;

		// ���q���Z
		}else if (tk->kyoku[kyoku_index].agari_ata_hai > 10 &&
		          tk->kyoku[kyoku_index].agari_ata_hai < 20 ){

			// ���q���Z
			tk->kyoku[kyoku_index].mentsu_count_pinzu++;

		// ���q���Z
		}else if (tk->kyoku[kyoku_index].agari_ata_hai > 20 &&
		          tk->kyoku[kyoku_index].agari_ata_hai < 30 ){

			// ���q���Z
			tk->kyoku[kyoku_index].mentsu_count_souzu++;

		// ���v���Z
		}else if (tk->kyoku[kyoku_index].agari_ata_hai > 30 &&
		          tk->kyoku[kyoku_index].agari_ata_hai < 38 ){

			// ���v���Z
			tk->kyoku[kyoku_index].mentsu_count_zihai++;

		}

	// -----------------------------
	// �Δv�̖����m�F(����)
	// -----------------------------





	// -----------------------------
	// �ʎq�m�F����
	// -----------------------------

	for(int tmp_i = 0; tmp_i < 4; tmp_i++){

		// -----------------------------
		// ��㎚�m�F(�����c)
		// -----------------------------

		if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == tk->agari_ply_bakaze ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == tk->agari_ply_zikaze ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 35 ||
	        tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 36 ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 37 ){

			// ��v�ݒ�
			tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] = 2; 

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_19zi++;

		}else if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 1 ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] ==  9 ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 11 ||
	        tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 19 ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 21 ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 29 ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 31 ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 32 ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 33 ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 34 ){

			// ��㎚�ݒ�
			tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] = 1; 

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_19zi++;

		// 789�̃y���`�����̏ꍇ
		}else if((tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == SHUNTSU || tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINSHUN) && 
                 (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 7  || 
		          tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 17 || 
		          tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 27 )){

			// ��㎚�ݒ�
			tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] = 1; 

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_19zi++;


		}else{

			// �����v�ݒ�
			tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] = 0;

			// �ʎq���̉��Z
			tk->kyoku[kyoku_index].mentsu_count_chunchan++;

		}

		// -----------------------------
		// �ݎq�E���q�E���q�E���v�̖����m�F(�ʎq)
		// -----------------------------

		// �ݎq���Z
		if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] >  0 &&
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] < 10 ){

			// �ݎq���Z
			tk->kyoku[kyoku_index].mentsu_count_manzu++;

		// ���q���Z
		}else if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] > 10 &&
		          tk->kyoku[kyoku_index].agari_men_hai[tmp_i] < 20 ){

			// ���q���Z
			tk->kyoku[kyoku_index].mentsu_count_pinzu++;

		// ���q���Z
		}else if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] > 20 &&
		          tk->kyoku[kyoku_index].agari_men_hai[tmp_i] < 30 ){

			// ���q���Z
			tk->kyoku[kyoku_index].mentsu_count_souzu++;

		// ���v���Z
		}else if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] > 30 &&
		          tk->kyoku[kyoku_index].agari_men_hai[tmp_i] < 38 ){

			// ���v���Z
			tk->kyoku[kyoku_index].mentsu_count_zihai++;

		}

		// -----------------------------
		// �Δv�̖����m�F
		// -----------------------------




		// -----------------------------
		// ���q�E�Í��̃q�X�g�O�����ݒ�
		// -----------------------------

		if( tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == SHUNTSU ){

			// �ʎq��ʂ̉��Z
			tk->kyoku[kyoku_index].mentsu_count_shuntsu++;

			// �q�X�g�O�������Z
			tk->shuntsu_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}else if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINSHUN ){

			// �ʎq��ʂ̉��Z
			tk->kyoku[kyoku_index].mentsu_count_minshun++;

			// �q�X�g�O�������Z
			tk->shuntsu_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}else if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKO){

			// �ʎq��ʂ̉��Z
			tk->kyoku[kyoku_index].mentsu_count_anko++;

			// �q�X�g�O�������Z
			tk->anko_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}else if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINKO){

			// �ʎq��ʂ̉��Z
			tk->kyoku[kyoku_index].mentsu_count_minko++;

			// �q�X�g�O�������Z
			tk->anko_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}else if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKAN){

			// �ʎq��ʂ̉��Z
			tk->kyoku[kyoku_index].mentsu_count_ankan++;

			// �q�X�g�O�������Z
			tk->anko_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}else if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINKAN){

			// �ʎq��ʂ̉��Z
			tk->kyoku[kyoku_index].mentsu_count_minkan++;

			// �q�X�g�O�������Z
			tk->anko_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 04:���v�Z
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_fu(MJSTkinfo *tk, int kyoku_index){

	// ���v�Z
	// https://kinmaweb.jp/mahjong-rule/fukeisan

	// -----------------------------
	// �����̕��v�Z
	// -----------------------------

	// �����̕�
	if (tk->kyoku[kyoku_index].agari_ata_19zi == 2){

		// �����̕�
		tk->kyoku[kyoku_index].atamaFu = 2;

	}else{

		// �����̕�
		tk->kyoku[kyoku_index].atamaFu = 0;

	}

	// -----------------------------
	// �ʎq�̕��v�Z
	// -----------------------------

	for(int tmp_i = 0; tmp_i < tk->mentu_count; tmp_i++){

		if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKO){

			if (tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] == 1 || 
			    tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] == 2 ){

				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 8;

			}else{

				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 4;

			}

		}else if (tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINKO){

			if (tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] == 1 || 
			    tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] == 2 ){

				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 4;

			}else{

				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 2;

			}

		}else if (tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKAN){

			if (tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] == 1 || 
			    tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] == 2 ){

				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 32;

			}else{

				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 16;

			}

		}else if (tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINKAN){

			if (tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] == 1 || 
			    tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] == 2 ){

				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 16;

			}else{

				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 8;

			}

		}else if ( tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == SHUNTSU || 
                   tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINSHUN ){

				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 0;

		}else{

				// �f�o�O�p
				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 99;

		}

	}

	// -----------------------------
	// �ʑO��
	// -----------------------------

	if(tk->kyoku[kyoku_index].menzen_flg      == true  && 
       tk->kyoku[kyoku_index].tsumo_agari_flg == false ){
		tk->kyoku[kyoku_index].menzenFu=10;
	}else{
		tk->kyoku[kyoku_index].menzenFu=0;
	}

	// -----------------------------
	// �҂����v�Z
	// -----------------------------
	if( tk->kyoku[kyoku_index].agari_machi_stat == TANKI || 
	    tk->kyoku[kyoku_index].agari_machi_stat == PENCHAN || 
	    tk->kyoku[kyoku_index].agari_machi_stat == KANCHAN ){

		tk->kyoku[kyoku_index].machiFu=2;

	}else{
		tk->kyoku[kyoku_index].machiFu=0;
	}

	// -----------------------------
	// ���̕�
	// -----------------------------

	if(tk->kyoku[kyoku_index].tsumo_agari_flg == true){
		tk->kyoku[kyoku_index].tsumoFu=2;
	}else{
		tk->kyoku[kyoku_index].tsumoFu=0;
	}

	// -----------------------------
	// ���̍��v
	// -----------------------------

	tk->kyoku[kyoku_index].basefu = 20;

	// ���̍��v
	tk->kyoku[kyoku_index].totalFu = tk->kyoku[kyoku_index].basefu + 
	tk->kyoku[kyoku_index].agari_men_Fu[0] +
	tk->kyoku[kyoku_index].agari_men_Fu[1] +
	tk->kyoku[kyoku_index].agari_men_Fu[2] +
	tk->kyoku[kyoku_index].agari_men_Fu[3] +
	tk->kyoku[kyoku_index].atamaFu +
	tk->kyoku[kyoku_index].menzenFu +
	tk->kyoku[kyoku_index].machiFu +
	tk->kyoku[kyoku_index].tsumoFu;

	// -----------------------------
	// ���̐؂�グ
	// -----------------------------

	if(tk->kyoku[kyoku_index].totalFu % 10 == 0){
		tk->kyoku[kyoku_index].scoreFu = tk->kyoku[kyoku_index].totalFu;
	}else{
		tk->kyoku[kyoku_index].scoreFu = tk->kyoku[kyoku_index].totalFu+10-(tk->kyoku[kyoku_index].totalFu % 10);
	}

}

/* ---------------------------------------------------------------------------------------------- */
// 05:���m�F
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_yaku(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// ������
	// -----------------------------
	tk->kyoku[kyoku_index].yakucount     = 0;
	tk->kyoku[kyoku_index].yakuman_count = 0;
	tk->kyoku[kyoku_index].agari_ply_han = 0;
	tk->kyoku[kyoku_index].agari_ply_mangan_count = 0;
	tk->kyoku[kyoku_index].yakuman_agari_ply_bai=0;

	// -----------------------------
	// �t���O������
	// -----------------------------

	// ��
	for(int tmp_i = 0; tmp_i < YAKUMAN_SHUBETSU_MAX; tmp_i++){
		tk->kyoku[kyoku_index].yakuman_flg[tmp_i]=false;
	}

	// �ʏ��
	for(int tmp_i = 0; tmp_i < YAKU_SHUBETSU_MAX; tmp_i++){
		tk->kyoku[kyoku_index].yaku_flg[tmp_i]=false;
	}

	// -----------------------------
	// ���m�F
	// -----------------------------

	ChkYakuRiich(tk,kyoku_index);             // ���[�`
	ChkYakuChitoiIpeko(tk,kyoku_index);       // ���Ύq�A��u���A��u�� 
	ChkYakuChinItsu_HonItsu(tk,kyoku_index);  // ��F
	ChkYakuAnko(tk,kyoku_index);              // �Í�
	ChkYakuChanta(tk,kyoku_index);            // �`�����^
	ChkYakuSanshoku(tk,kyoku_index);          // �O�F
	ChkYakuItsu(tk,kyoku_index);              // ���
	ChkYakuPinfu(tk,kyoku_index);             // ���a
	ChkYakuTanyao(tk,kyoku_index);            // �^�����I
	ChkYakuYakuhai(tk,kyoku_index);           // ��v
	ChkYakuDaisangen(tk,kyoku_index);         // ��O���E���O��
	ChkYakuDaisushi(tk,kyoku_index);          // ��l��a�E���l��a
	ChkYakuKokushi(tk,kyoku_index);           // ���m���o
	ChkYakuChuren(tk,kyoku_index);            // ��A��
	ChkYakuTenho(tk,kyoku_index);             // �V�a
	ChkYakuEtc(tk,kyoku_index);               // ���̑�

	// -----------------------------
	// ���e�[�u���ݒ�
	// -----------------------------

		// �𖞊m�F
		for(int tmp_i = 0; tmp_i < YAKUMAN_SHUBETSU_MAX; tmp_i++){

			// ��ݒ�L��
			if(tk->kyoku[kyoku_index].yakuman_flg[tmp_i] == true){

				// ���e�[�u���ݒ�
				// wsprintf(tk->kyoku[kyoku_index].yakuname[tk->kyoku[kyoku_index].yakuman_count], "%s �c �𖞁@�@", yakumanname[tmp_i],1);
				tk->kyoku[kyoku_index].yakuman_count++;

				// �𖞔{�̐ݒ�
				tk->kyoku[tk->kyoku_index].yakuman_bai[tmp_i] = yakuman_bai[tmp_i];

				// �𖞍��v�{���J�E���g
				tk->kyoku[kyoku_index].yakuman_agari_ply_bai = tk->kyoku[kyoku_index].yakuman_agari_ply_bai + yakuman_bai[tmp_i];

			}

		}

	// �ʏ��
	if( tk->kyoku[kyoku_index].yakuman_count == 0 ){

		// �ʏ���m�F
		for(int tmp_i = 0; tmp_i < YAKU_SHUBETSU_MAX; tmp_i++){

			// ��ݒ�L��
			if(tk->kyoku[kyoku_index].yaku_flg[tmp_i] == true){

				// ���e�[�u���ݒ�
				// wsprintf(tk->kyoku[kyoku_index].yakuname[tk->kyoku[kyoku_index].yakucount], "%s �c %d�|", yakuname[tmp_i], yakuhan[tmp_i]);
				tk->kyoku[kyoku_index].yakucount++;

				// ��|�ݒ�
				tk->kyoku[tk->kyoku_index].yaku_han[tmp_i] = yakuhan[tmp_i];

				// ���v�|���̃J�E���g
				tk->kyoku[kyoku_index].agari_ply_han = tk->kyoku[kyoku_index].agari_ply_han + yakuhan[tmp_i];

			}
		}

		// ���шȏ�m�F
		if (tk->kyoku[kyoku_index].agari_ply_han == 5){
			// ����
			tk->kyoku[kyoku_index].agari_ply_mangan_count = 1;
		}else if(tk->kyoku[kyoku_index].agari_ply_han >=6 && tk->kyoku[kyoku_index].agari_ply_han <= 7){
			// ����
			tk->kyoku[kyoku_index].agari_ply_mangan_count = 2;
		}else if(tk->kyoku[kyoku_index].agari_ply_han >=8 && tk->kyoku[kyoku_index].agari_ply_han <= 10){
			// �{��
			tk->kyoku[kyoku_index].agari_ply_mangan_count = 3;
		}else if(tk->kyoku[kyoku_index].agari_ply_han >=11 && tk->kyoku[kyoku_index].agari_ply_han <= 12){
			// �O�{��
			tk->kyoku[kyoku_index].agari_ply_mangan_count = 4;
		}else if(tk->kyoku[kyoku_index].agari_ply_han >=13){
			// ������
			tk->kyoku[kyoku_index].agari_ply_mangan_count = 5;
		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 06:���_�v�Z�E���C��
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_score(MJSTkinfo *tk, int kyoku_index){

	Chk_kyokuscore(tk, kyoku_index);
	Chk_totalscore(tk, kyoku_index);

}

/* ---------------------------------------------------------------------------------------------- */
// 06:���_�v�Z�E�T�u
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::Chk_kyokuscore(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// ���_ - �a�����_
	// -----------------------------

	// ���̘a���ł��邩�ǂ���
	if (tk->kyoku[kyoku_index].tsumo_agari_flg == true){

		// -----------------------------
		// �c���a���E�e
		// -----------------------------
		if (tk->kyoku[kyoku_index].agari_ply_oya_flg == true){

			// �𖞂̏ꍇ
			if( tk->kyoku[kyoku_index].yakuman_count > 0 ){

					// ���_�ݒ�
					tk->kyoku[kyoku_index].agari_ply_ron       = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 16000*tk->kyoku[kyoku_index].yakuman_agari_ply_bai;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

			// �ʏ���̏ꍇ
			}else{

				// ���шȏ�
				if(tk->kyoku[kyoku_index].agari_ply_mangan_count > 0){

					// ���_�ݒ�
					tk->kyoku[kyoku_index].agari_ply_ron       = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_mangan_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_mangan_count-1];
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

				// ���і���
				}else{
					// �`���m�F
					if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){
						// ���_�ݒ�(���Ύq)
						tk->kyoku[kyoku_index].agari_ply_ron       = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_chitoi_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_han-1];
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}else{
						// ���_�ݒ�(�ʏ�)
						tk->kyoku[kyoku_index].agari_ply_ron       = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_han-1][(tk->kyoku[kyoku_index].scoreFu-20)/10];
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}
				}
			}

		// -----------------------------
		// �c���a���E�q
		// -----------------------------
		}else{

			// �𖞂̏ꍇ
			if( tk->kyoku[kyoku_index].yakuman_count > 0 ){

					// ���_�ݒ�
					tk->kyoku[kyoku_index].agari_ply_ron       = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 16000*tk->kyoku[kyoku_index].yakuman_agari_ply_bai;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 8000*tk->kyoku[kyoku_index].yakuman_agari_ply_bai;

			// �ʏ���̏ꍇ
			}else{

				// ���шȏ�
				if(tk->kyoku[kyoku_index].agari_ply_mangan_count > 0){

					// ���_�ݒ�
					tk->kyoku[kyoku_index].agari_ply_ron       = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_mangan_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_mangan_count-1];
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = score_mangan_tsumo_ko[tk->kyoku[kyoku_index].agari_ply_mangan_count-1];

				// ���і���
				}else{
					// �`���m�F
					if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){
						// ���_�ݒ�(���Ύq)
						tk->kyoku[kyoku_index].agari_ply_ron       = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_chitoi_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_han-1];
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = score_chitoi_tsumo_ko[tk->kyoku[kyoku_index].agari_ply_han-1];
					}else{
						// ���_�ݒ�(�ʏ�)
						tk->kyoku[kyoku_index].agari_ply_ron       = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_han-1][(tk->kyoku[kyoku_index].scoreFu-20)/10];
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = score_tsumo_ko[tk->kyoku[kyoku_index].agari_ply_han-1][(tk->kyoku[kyoku_index].scoreFu-20)/10];
					}
				}
			}
		}

	}else{

		// -----------------------------
		// �����a���E�e
		// -----------------------------
		if (tk->kyoku[kyoku_index].agari_ply_oya_flg == true){

			// �𖞂̏ꍇ
			if( tk->kyoku[kyoku_index].yakuman_count > 0 ){

					// ���_�ݒ�
					tk->kyoku[kyoku_index].agari_ply_ron       = 48000*tk->kyoku[kyoku_index].yakuman_agari_ply_bai;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

			// �ʏ���̏ꍇ
			}else{

				// ���шȏ�
				if(tk->kyoku[kyoku_index].agari_ply_mangan_count > 0){

					// ���_�ݒ�
					tk->kyoku[kyoku_index].agari_ply_ron       = score_mangan_ron_oya[tk->kyoku[kyoku_index].agari_ply_mangan_count-1];
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

				// ���і���
				}else{
					// �`���m�F
					if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){
						// ���_�ݒ�(���Ύq)
						tk->kyoku[kyoku_index].agari_ply_ron       = score_chitoi_ron_oya[tk->kyoku[kyoku_index].agari_ply_han-1];
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}else{
						// ���_�ݒ�(�ʏ�)
						tk->kyoku[kyoku_index].agari_ply_ron       = score_ron_oya[tk->kyoku[kyoku_index].agari_ply_han-1][(tk->kyoku[kyoku_index].scoreFu-20)/10];
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}
				}
			}

		// -----------------------------
		// �����a���E�q
		// -----------------------------
		}else{

			// �𖞂̏ꍇ
			if( tk->kyoku[kyoku_index].yakuman_count > 0 ){

					// ���_�ݒ�
					tk->kyoku[kyoku_index].agari_ply_ron       = 32000*tk->kyoku[kyoku_index].yakuman_agari_ply_bai;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

			// �ʏ���̏ꍇ
			}else{

				// ���шȏ�
				if(tk->kyoku[kyoku_index].agari_ply_mangan_count > 0){

					// ���_�ݒ�(����)
					tk->kyoku[kyoku_index].agari_ply_ron       = score_mangan_ron_ko[tk->kyoku[kyoku_index].agari_ply_mangan_count-1];
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

				// ���і���
				}else{
					// �`���m�F
					if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){
						// ���_�ݒ�(���Ύq)
						tk->kyoku[kyoku_index].agari_ply_ron       = score_chitoi_tsumo_ko[tk->kyoku[kyoku_index].agari_ply_han-1];
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}else{
						// ���_�ݒ�(�ʏ�)
						tk->kyoku[kyoku_index].agari_ply_ron       = score_ron_ko[tk->kyoku[kyoku_index].agari_ply_han-1][(tk->kyoku[kyoku_index].scoreFu-20)/10];
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}
				}
			}

		}

	}

	// -----------------------------
	// ���_ - �v���[���[���Ƃ̐��Z
	// -----------------------------

	// ������
	tk->kyoku[kyoku_index].kyoku_score[0] = 0;
	tk->kyoku[kyoku_index].kyoku_score[1] = 0;
	tk->kyoku[kyoku_index].kyoku_score[2] = 0;
	tk->kyoku[kyoku_index].kyoku_score[3] = 0;

	// ���̃����m�F
	if (tk->kyoku[kyoku_index].tsumo_agari_flg == true){

		if (tk->kyoku[kyoku_index].agari_ply_oya_flg == true){

			// �c���a���E�e
			for(int tmp_i = 0; tmp_i < 4; tmp_i++){
				if(tmp_i == tk->kyoku[kyoku_index].agari_ply_num){
					tk->kyoku[kyoku_index].kyoku_score[tmp_i] = tk->kyoku[kyoku_index].agari_ply_tsumo_oya*3;
				}else{
					tk->kyoku[kyoku_index].kyoku_score[tmp_i] = tk->kyoku[kyoku_index].agari_ply_tsumo_oya*-1;
				}
			}

		}else{

			// �c���a���E�q
			for(int tmp_i = 0; tmp_i < 4; tmp_i++){
				if(tmp_i == tk->kyoku[kyoku_index].agari_ply_num){
					tk->kyoku[kyoku_index].kyoku_score[tmp_i] = tk->kyoku[kyoku_index].agari_ply_tsumo_oya+tk->kyoku[kyoku_index].agari_ply_tsumo_ko*2;
				}else{
					if(tk->kyoku[kyoku_index].ie[tmp_i]==0){
						tk->kyoku[kyoku_index].kyoku_score[tmp_i] = tk->kyoku[kyoku_index].agari_ply_tsumo_oya*-1;
					}else{
						tk->kyoku[kyoku_index].kyoku_score[tmp_i] = tk->kyoku[kyoku_index].agari_ply_tsumo_ko*-1;
					}
				}
			}

		}

	}else{

			// �����a��
			tk->kyoku[kyoku_index].kyoku_score[tk->kyoku[kyoku_index].agari_ply_num] = tk->kyoku[kyoku_index].agari_ply_ron;
			tk->kyoku[kyoku_index].kyoku_score[tk->kyoku[kyoku_index].furikomi_ply_num]  = tk->kyoku[kyoku_index].agari_ply_ron*(-1);

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 06:���_�v�Z�E�T�u
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::Chk_totalscore(MJSTkinfo *tk, int kyoku_index){

	// �ǏI�����_�̐ݒ�
/*	for(int tmp_i = 0; tmp_i < PLAYER_MAX; tmp_i++){
		tk->kyoku[kyoku_index].ply_kyoku_end_score[tmp_i] = tk->kyoku[kyoku_index].ply_kyoku_start_score[tmp_i] 
		                                                  + tk->kyoku[kyoku_index].kyoku_score[tmp_i];
	}*/

}

/* ---------------------------------------------------------------------------------------------- */
// �h�������̊m�F
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::Chk_tehai_dora_count(MJSTkinfo *tk, int kyoku_index, int rinshan, bool ura_chk){

	// -----------------------------
	// ������
	// -----------------------------

	// �h��������
	tk->kyoku[kyoku_index].agari_dora_count = 0;
	tk->kyoku[kyoku_index].agari_uradora_count = 0;

	// �f�o�O�p
	rinshan=0;

	// ��Ɨp�ϐ���`
	int dora_hai;

	// ���h���v�Z�o
	dora_hai=Get_dora_hai(tk->kyoku[kyoku_index].dora[0]);

	// -----------------------------
	// �h�������J�E���g�E��
	// -----------------------------

	if (tk->kyoku[kyoku_index].agari_ata_hai == dora_hai){

		// �h�����Z
		tk->kyoku[kyoku_index].agari_dora_count = tk->kyoku[kyoku_index].agari_dora_count + 2 ;

	}

	// -----------------------------
	// �h�������J�E���g�E�ʎq
	// -----------------------------

	// �h���J�E���g
	for(int tmp_i = 0; tmp_i < 4; tmp_i++){

		// �h���J�E���g
		if((tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKO || tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINKO) && 
			     (tk->kyoku[kyoku_index].agari_men_hai[tmp_i]    == dora_hai )){

				// �h�����Z
				tk->kyoku[kyoku_index].agari_dora_count = tk->kyoku[kyoku_index].agari_dora_count + 3 ;

		}else if((tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKAN || tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINKAN) && 
			     (tk->kyoku[kyoku_index].agari_men_hai[tmp_i]    == dora_hai )){

				// �h�����Z
				tk->kyoku[kyoku_index].agari_dora_count = tk->kyoku[kyoku_index].agari_dora_count + 4 ;

		}else if((tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == SHUNTSU || tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINSHUN) && 
			     (tk->kyoku[kyoku_index].agari_men_hai[tmp_i]    == dora_hai || 
			      tk->kyoku[kyoku_index].agari_men_hai[tmp_i] +1 == dora_hai || 
			      tk->kyoku[kyoku_index].agari_men_hai[tmp_i] +2 == dora_hai )){

				// �h�����Z
				tk->kyoku[kyoku_index].agari_dora_count ++;

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// �h���\���v���h���v�̕ϊ�
/* ---------------------------------------------------------------------------------------------- */
int MJSOldScore::Get_dora_hai(int dora_hai){

	// �h���\���v���h���v�̕ϊ�
	if(dora_hai == 9){
		return 1;
	}else if(dora_hai == 19){
		return 11;
	}else if(dora_hai == 29){
		return 21;
	}else if(dora_hai == 34){
		return 31;
	}else if(dora_hai == 37){
		return 35;
	// �f�o�O�p
	}else if(dora_hai < 1 || dora_hai > 37){
		return 1;
	}else{
		return dora_hai+1;
	}

}

/* ---------------------------------------------------------------------------------------------- */
// ���[�`�n
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuRiich(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 01: ���[�`
	// -----------------------------------------------------------------------

	if (tk->kyoku[kyoku_index].riichi_flg == true){
		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[RIICH] = true;
	}

	// -----------------------------------------------------------------------
	// 02: �_�u�����[�`
	// -----------------------------------------------------------------------

	if (tk->kyoku[kyoku_index].w_riichi_flg == true){
		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[RIICH]  = false;
		tk->kyoku[kyoku_index].yaku_flg[WRIICH] = true;
	}

	// -----------------------------------------------------------------------
	// 03: �ꔭ
	// -----------------------------------------------------------------------

	if (tk->kyoku[kyoku_index].ippatsu_riichi_flg == true){
		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[IPPATSU] = true;
	}

}

/* ---------------------------------------------------------------------------------------------- */
// ���Ύq�A��u���A��u�� 
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuChitoiIpeko(MJSTkinfo *tk, int kyoku_index){

	/* ----------------------------------------------------------------------- */
	// ��u���E��u��
	/* ----------------------------------------------------------------------- */
	for(int tmp_i = 1; tmp_i < 28; tmp_i++){

		// ��u���L����
		if ( tk->shuntsu_hist[tmp_i] > 1 && 
		     tk->kyoku[kyoku_index].menzen_flg == true &&
			 tk->kyoku[kyoku_index].yaku_flg[IPEKO] == true){

			// ��u���L����
			tk->kyoku[kyoku_index].yaku_flg[IPEKO] = false;
			tk->kyoku[kyoku_index].yaku_flg[RYANPEKO] = true;
			break;

		// ��u���̗L�����m�F
		}else if ( tk->shuntsu_hist[tmp_i] > 1 && tk->kyoku[kyoku_index].menzen_flg == true ){
			// ��flg�L����
			tk->kyoku[kyoku_index].yaku_flg[IPEKO] = true;

		// ���Ύq�̗L�����m�F
		}else if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){

			// ��flg�L����
			tk->kyoku[kyoku_index].yaku_flg[CHITOI] = true;

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// ����n
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuChinItsu_HonItsu(MJSTkinfo *tk, int kyoku_index){

	// �ʏ�`��
	if(tk->kyoku[kyoku_index].agari_stat == AGARI_NORMAL){

		// -----------------------------------------------------------------------
		// 04: ����F
		// -----------------------------------------------------------------------
		if ( tk->kyoku[kyoku_index].mentsu_count_manzu == 5 ||
		     tk->kyoku[kyoku_index].mentsu_count_pinzu == 5 ||
		     tk->kyoku[kyoku_index].mentsu_count_souzu == 5 ){

			// ��flg�L����
			tk->kyoku[kyoku_index].yaku_flg[CHINISO]=true;

		// -----------------------------------------------------------------------
		// 10: ����F
		// -----------------------------------------------------------------------
		}else if( tk->kyoku[kyoku_index].mentsu_count_zihai == 5){

			// ��flg�L����
			tk->kyoku[kyoku_index].yakuman_flg[TSUISO]=true;

		// -----------------------------------------------------------------------
		// 04: ����F
		// -----------------------------------------------------------------------
		}else if( tk->kyoku[kyoku_index].mentsu_count_manzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 5 ||
		          tk->kyoku[kyoku_index].mentsu_count_pinzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 5 ||
		          tk->kyoku[kyoku_index].mentsu_count_souzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 5 ){

			// ��flg�L����
			tk->kyoku[kyoku_index].yaku_flg[HONISO]=true;

		// -----------------------------------------------------------------------
		// 12: �Έ�F
		// -----------------------------------------------------------------------

		}

	// ���Ύq�`��
	}else if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){

		// -----------------------------------------------------------------------
		// 04: ����F
		// -----------------------------------------------------------------------
		if ( tk->kyoku[kyoku_index].mentsu_count_manzu == 7 ||
		     tk->kyoku[kyoku_index].mentsu_count_pinzu == 7 ||
		     tk->kyoku[kyoku_index].mentsu_count_souzu == 7 ){

			// ��flg�L����
			tk->kyoku[kyoku_index].yaku_flg[CHINISO]=true;

		// -----------------------------------------------------------------------
		// 10: ����F
		// -----------------------------------------------------------------------
		}else if( tk->kyoku[kyoku_index].mentsu_count_zihai == 7){

			// ��flg�L����
			tk->kyoku[kyoku_index].yakuman_flg[TSUISO]=true;

		// -----------------------------------------------------------------------
		// 04: ����F
		// -----------------------------------------------------------------------
		}else if( tk->kyoku[kyoku_index].mentsu_count_manzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 7 ||
		          tk->kyoku[kyoku_index].mentsu_count_pinzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 7 ||
		          tk->kyoku[kyoku_index].mentsu_count_souzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 7 ){

			// ��flg�L����
			tk->kyoku[kyoku_index].yaku_flg[HONISO]=true;
		}
	}


}

/* ---------------------------------------------------------------------------------------------- */
// �Í��n
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuAnko(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// ��14: �l�Ȏq
	// -----------------------------------------------------------------------
	if ( tk->kyoku[kyoku_index].mentsu_count_ankan  +
	     tk->kyoku[kyoku_index].mentsu_count_minkan == 4 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[SUKANTSU] = true;

	}

	// -----------------------------------------------------------------------
	// 13: �O�Ȏq
	// -----------------------------------------------------------------------
	if ( tk->kyoku[kyoku_index].mentsu_count_ankan  +
	     tk->kyoku[kyoku_index].mentsu_count_minkan == 3 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[SANKANTSU] = true;

	}

	// -----------------------------------------------------------------------
	// ��15: �l�Í�
	// -----------------------------------------------------------------------
	if ( tk->kyoku[kyoku_index].mentsu_count_anko  +
	     tk->kyoku[kyoku_index].mentsu_count_ankan == 4 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[SUANKO]=true;

	}

	// -----------------------------------------------------------------------
	// 14: �O�Í�
	// -----------------------------------------------------------------------
	if ( tk->kyoku[kyoku_index].mentsu_count_anko  +
	     tk->kyoku[kyoku_index].mentsu_count_ankan == 3 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[SANANKO] = true;

	}

	// -----------------------------------------------------------------------
	// 15: �΁X�a
	// -----------------------------------------------------------------------
	if ( tk->kyoku[kyoku_index].mentsu_count_anko  +
	     tk->kyoku[kyoku_index].mentsu_count_minko +
	     tk->kyoku[kyoku_index].mentsu_count_ankan +
	     tk->kyoku[kyoku_index].mentsu_count_minkan == 4 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[TOITOI] = true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// ���S��
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuChanta(MJSTkinfo *tk, int kyoku_index){


	// �ʏ�`��
	if(tk->kyoku[kyoku_index].agari_stat == AGARI_NORMAL){

		/* ----------------------------------------------------------------------- */
		// �`�����^�n(�ʏ��)
		/* ----------------------------------------------------------------------- */
		if (tk->kyoku[kyoku_index].mentsu_count_19zi == 5){
			// �S�ăA���R�̏ꍇ
			if ( tk->kyoku[kyoku_index].mentsu_count_anko  +
			     tk->kyoku[kyoku_index].mentsu_count_minko +
			     tk->kyoku[kyoku_index].mentsu_count_ankan +
			     tk->kyoku[kyoku_index].mentsu_count_minkan == 4 ){
				// ���v���m�F
				if(tk->kyoku[kyoku_index].mentsu_count_zihai == 0){
					// ��flg�L����
					tk->kyoku[kyoku_index].yaku_flg[JUNCHAN] = true;
				}else{
					// ��flg�L����
					tk->kyoku[kyoku_index].yaku_flg[CHANTA] = true;
				}
			// ���q������ꍇ
			}else{
				// ���v���m�F
				if(tk->kyoku[kyoku_index].mentsu_count_zihai == 0){
					// ��flg�L����
					tk->kyoku[kyoku_index].yakuman_flg[CHINROTO]=true;
				}else{
					// ��flg�L����
					tk->kyoku[kyoku_index].yaku_flg[HONROTO] = true;
				}
			}
		}

	// ���Ύq�`��
	}else if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){

		/* ----------------------------------------------------------------------- */
		// �`�����^�n(���Ύq)
		/* ----------------------------------------------------------------------- */
		if (tk->kyoku[kyoku_index].mentsu_count_19zi == 7){
			// ��flg�L����
			tk->kyoku[kyoku_index].yaku_flg[HONROTO] = true;
		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// �O�F�n
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuSanshoku(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 11: �O�F����
	// 12: �O�F����
	// -----------------------------------------------------------------------
	for(int i = 0; i < 9; i++){

		// �O�F�����m�F
		if ( tk->shuntsu_hist[1+i]  > 0 &&
		     tk->shuntsu_hist[11+i] > 0 &&
		     tk->shuntsu_hist[21+i] > 0 ){

			// ��flg�L����
			tk->kyoku[kyoku_index].yaku_flg[SANDOJUN] = true;

		}

		// �O�F�����m�F
		if ( tk->anko_hist[1+i]  > 0 &&
		     tk->anko_hist[11+i] > 0 &&
		     tk->anko_hist[21+i] > 0 ){

			// ��flg�L����
			tk->kyoku[kyoku_index].yaku_flg[SANDOKOU] = true;

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// ��ʌn
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuItsu(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 10: ��C�ʊ�
	// -----------------------------------------------------------------------
	for(int i = 0; i < 3; i++){
		if ( tk->shuntsu_hist[1+10*i] > 0 &&
		     tk->shuntsu_hist[4+10*i] > 0 &&
		     tk->shuntsu_hist[7+10*i] > 0 ){

			// ��flg�L����
			tk->kyoku[kyoku_index].yaku_flg[ITSU] = true;

		}
	}

}

/* ---------------------------------------------------------------------------------------------- */
// ���a�n
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuPinfu(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 10: ���a
	// -----------------------------------------------------------------------

	// ���m�F
	if(tk->kyoku[kyoku_index].menzen_flg == false ){
		return ;
	}

	// ���q���̊m�F
	if( (tk->kyoku[kyoku_index].mentsu_count_shuntsu != 4 ) && 
	    (tk->kyoku[kyoku_index].mentsu_count_shuntsu != 3 || tk->kyoku[kyoku_index].mentsu_count_minshun != 1 )
	){
		return ;
	}

	// �����̖�v�m�F��agari_ata_19zi=2�̏ꍇ�͕��a�ɂȂ�Ȃ�
	if( tk->kyoku[kyoku_index].agari_ata_19zi == 2){
		return ;
	}

	// ���ʂ̊m�F
	if(tk->kyoku[kyoku_index].agari_machi_stat != RYANMEN ){
		return ;
	}

	// ��flg�L����
	tk->kyoku[kyoku_index].yaku_flg[PINFU] = true;

	// ���a�͌Œ��20��
	tk->kyoku[kyoku_index].totalFu = 20;
	tk->kyoku[kyoku_index].scoreFu = 20;

}

/* ---------------------------------------------------------------------------------------------- */
// �^�����I�n
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuTanyao(MJSTkinfo *tk, int kyoku_index){

	/* ----------------------------------------------------------------------- */
	// �^�����I
	/* ----------------------------------------------------------------------- */
	if (tk->kyoku[kyoku_index].mentsu_count_chunchan == 5){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[TANYAO] = true;

	}
}


/* ---------------------------------------------------------------------------------------------- */
// ��v�n
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuYakuhai(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 21: �ꕗ�v
	// -----------------------------------------------------------------------
	if ( tk->anko_hist[tk->agari_ply_bakaze] > 0 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[BAKAZE] = true;

	}

	/* ----------------------------------------------------------------------- */
	// 22: �����v
	/* ----------------------------------------------------------------------- */
	if ( tk->anko_hist[tk->agari_ply_zikaze] > 0 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[ZIKAZE] = true;

	}

	// -----------------------------------------------------------------------
	// 23: �O���v��
	// -----------------------------------------------------------------------
	if ( tk->anko_hist[HAKUNUM] > 0 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[YAKUHAIHAKU] = true;

	}

	// -----------------------------------------------------------------------
	// 24: �O���v��
	// -----------------------------------------------------------------------
	if ( tk->anko_hist[HATSUNUM] > 0 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[YAKUHAIHATSU] = true;

	}

	// -----------------------------------------------------------------------
	// 25: �O���v��
	// -----------------------------------------------------------------------
	if ( tk->anko_hist[CHUNNUM] > 0){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[YAKUHAICHUN] = true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// ��O���E���O��
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuDaisangen(MJSTkinfo *tk, int kyoku_index){

	/* ----------------------------------------------------------------------- */
	// ���O���E��(HAKUNUM)�A�^�}
	/* ----------------------------------------------------------------------- */
	if (( tk->kyoku[kyoku_index].agari_ata_hai == HAKUNUM ) &&
		( tk->anko_hist[HATSUNUM] > 0 ) &&
		( tk->anko_hist[CHUNNUM]  > 0 ) ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[SHOSANGEN]=true;
	}

	/* ----------------------------------------------------------------------- */
	// ���O���E��(HAKUNUM)�A�^�}
	/* ----------------------------------------------------------------------- */
	if (( tk->kyoku[kyoku_index].agari_ata_hai == HATSUNUM ) &&
		( tk->anko_hist[HAKUNUM] > 0 ) &&
		( tk->anko_hist[CHUNNUM]  > 0 ) ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[SHOSANGEN]=true;
	}

	/* ----------------------------------------------------------------------- */
	// ���O���E��(HAKUNUM)�A�^�}
	/* ----------------------------------------------------------------------- */
	if (( tk->kyoku[kyoku_index].agari_ata_hai == CHUNNUM ) &&
		( tk->anko_hist[HAKUNUM]   > 0 ) &&
		( tk->anko_hist[HATSUNUM]  > 0 ) ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[SHOSANGEN]=true;
	}

	/* ----------------------------------------------------------------------- */
	// ��O��
	/* ----------------------------------------------------------------------- */
	if (( tk->anko_hist[HAKUNUM]  > 0 ) &&
		( tk->anko_hist[HATSUNUM] > 0 ) &&
		( tk->anko_hist[CHUNNUM]  > 0 ) ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[DAISANGEN]=true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// ��l��a�E���l��a
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuDaisushi(MJSTkinfo *tk, int kyoku_index){

	/* ----------------------------------------------------------------------- */
	// ���l��a�E���A�^�}
	/* ----------------------------------------------------------------------- */

	if (( tk->kyoku[kyoku_index].agari_ata_hai == TONNUM ) &&
		( tk->anko_hist[NANNUM] > 0 ) &&
		( tk->anko_hist[SHANUM] > 0 ) &&
		( tk->anko_hist[PEINUM] > 0 ) ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[SHOSUSHI]=true;

	}

	/* ----------------------------------------------------------------------- */
	// ���l��a�E��A�^�}
	/* ----------------------------------------------------------------------- */

	if (( tk->kyoku[kyoku_index].agari_ata_hai == NANNUM ) &&
		( tk->anko_hist[TONNUM] > 0 ) &&
		( tk->anko_hist[SHANUM] > 0 ) &&
		( tk->anko_hist[PEINUM] > 0 ) ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[SHOSUSHI]=true;

	}

	/* ----------------------------------------------------------------------- */
	// ���l��a�E���A�^�}
	/* ----------------------------------------------------------------------- */

	if (( tk->kyoku[kyoku_index].agari_ata_hai == SHANUM ) &&
		( tk->anko_hist[TONNUM] > 0 ) &&
		( tk->anko_hist[NANNUM] > 0 ) &&
		( tk->anko_hist[PEINUM] > 0 ) ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[SHOSUSHI]=true;

	}

	/* ----------------------------------------------------------------------- */
	// ���l��a�E�k�A�^�}
	/* ----------------------------------------------------------------------- */

	if (( tk->kyoku[kyoku_index].agari_ata_hai == PEINUM ) &&
		( tk->anko_hist[TONNUM] > 0 ) &&
		( tk->anko_hist[NANNUM] > 0 ) &&
		( tk->anko_hist[SHANUM] > 0 ) ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[SHOSUSHI]=true;

	}

	// -----------------------------------------------------------------------
	// 07: ��l��a
	// -----------------------------------------------------------------------

	if (( tk->anko_hist[TONNUM] > 0 ) &&
		( tk->anko_hist[NANNUM] > 0 ) &&
		( tk->anko_hist[SHANUM] > 0 ) &&
		( tk->anko_hist[PEINUM] > 0 ) ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[DAISUSHI]=true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// ���m���o
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuKokushi(MJSTkinfo *tk, int kyoku_index){

	// ��z�`�������m�ł���̂��H
	if(tk->kyoku[kyoku_index].agari_stat == AGARI_KOKUSHI){
		//13�ʊm�F
		if ( tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][tk->kyoku[kyoku_index].agari_hai] > 0){
			// ��flg�L����
			tk->kyoku[kyoku_index].yakuman_flg[KOKUSHI13MEN] = true;
		}else{
			// ��flg�L����
			tk->kyoku[kyoku_index].yakuman_flg[KOKUSHI] = true;
		}
	}

}

/* ---------------------------------------------------------------------------------------------- */
// ��A��
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuChuren(MJSTkinfo *tk, int kyoku_index){

	// �ϐ��ݒ�
	bool agari_flg;

	/* ----------------------------------------------------------------------- */
	// 03: ��A�󓕁E�ݎq
	/* ----------------------------------------------------------------------- */

	// �a���t���O������
	agari_flg = true;

	// �����Ɩʎq4�������ׂē���̍��q�ł��邱��
	if ( tk->kyoku[kyoku_index].mentsu_count_manzu != 5){
		agari_flg = false ;
	}

	// ��v�Ƌ�v��3���ȏ゠�邱��
    if ( (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][MAN1NUM] < 3) || 
	     (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][MAN9NUM] < 3) ){
		agari_flg = false ;
	}

	// ��v�����v�܂őS�đ����Ă��邱��
	for (int tmp_i = 1; tmp_i < 10; tmp_i++) {
        if (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][tmp_i] == 0){
			agari_flg = false ;
		}
    }

	// �a���m�F
	if (agari_flg == true){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[CHUREN]=true;

	}

	/* ----------------------------------------------------------------------- */
	// 03: ��A�󓕁E���q
	/* ----------------------------------------------------------------------- */

	// �a���t���O������
	agari_flg = true;

	// �����Ɩʎq4�������ׂē���̍��q�ł��邱��
	if ( tk->kyoku[kyoku_index].mentsu_count_pinzu != 5){
		agari_flg = false ;
	}

	// ��v�Ƌ�v��3���ȏ゠�邱��
    if ( (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][PIN1NUM] < 3) || 
	     (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][PIN9NUM] < 3) ){
		agari_flg = false ;
	}

	// ��v�����v�܂őS�đ����Ă��邱��
	for (int tmp_i = 11; tmp_i < 20; tmp_i++) {
        if (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][tmp_i] == 0){
			agari_flg = false ;
		}
    }

	// �a���m�F
	if (agari_flg == true){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[CHUREN]=true;

	}

	/* ----------------------------------------------------------------------- */
	// 03: ��A�󓕁E���q
	/* ----------------------------------------------------------------------- */

	// �a���t���O������
	agari_flg = true;

	// �����Ɩʎq4�������ׂē���̍��q�ł��邱��
	if ( tk->kyoku[kyoku_index].mentsu_count_souzu != 5){
		agari_flg = false ;
	}

	// ��v�Ƌ�v��3���ȏ゠�邱��
    if ( (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][SOU1NUM] < 3) || 
	     (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][SOU9NUM] < 3) ){

		// �a���t���O������
		agari_flg = false ;
	}

	// ��v�����v�܂őS�đ����Ă��邱��
	for (int tmp_i = 21; tmp_i < 30; tmp_i++) {
        if (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][tmp_i] == 0){
			agari_flg = false ;
		}
    }

	// �a���m�F
	if (agari_flg == true){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[CHUREN]=true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// �V�a
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuTenho(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// ��01: �V�a
	// -----------------------------------------------------------------------
	if(tk->kyoku[kyoku_index].agari_ply_tsumo_count == 1 && tk->kyoku[kyoku_index].tsumo_agari_flg == true){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[TENHO]=true;

	}

	// -----------------------------------------------------------------------
	// ��02: �n�a
	// -----------------------------------------------------------------------
	if(tk->kyoku[kyoku_index].agari_ply_tsumo_count == 0 && tk->kyoku[kyoku_index].tsumo_agari_flg == false){

		// ��flg�L����
		tk->kyoku[kyoku_index].yakuman_flg[CHIHO]=true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// ���̑�����
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuEtc(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 29: ��O�����̘a
	// -----------------------------------------------------------------------

	if(tk->kyoku[kyoku_index].tsumo_agari_flg == true && 
	   tk->kyoku[kyoku_index].menzen_flg      == true ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[TSUMO] = true;

	}

	// -----------------------------
	// 31: �h��
	// -----------------------------
	if( tk->kyoku[kyoku_index].agari_dora_count > 0 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[DORA] = true;

		// �|���ݒ�
		yakuhan[DORA] = tk->kyoku[kyoku_index].agari_dora_count;

	}

	// -----------------------------
	// 33: �Ԕv
	// -----------------------------
	if(tk->kyoku[kyoku_index].agari_aka_count[0] > 0 ||
	   tk->kyoku[kyoku_index].agari_aka_count[1] > 0 ||
	   tk->kyoku[kyoku_index].agari_aka_count[2] > 0 ){

		// ��flg�L����
		tk->kyoku[kyoku_index].yaku_flg[AKAHAI] = true;

		// �|���ݒ�
		yakuhan[AKAHAI] = tk->kyoku[kyoku_index].agari_aka_count[0] + 
		                  tk->kyoku[kyoku_index].agari_aka_count[1] +
		                  tk->kyoku[kyoku_index].agari_aka_count[2] ;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// �r�v�����_�ݒ�
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::SetHowanpaiScore(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------
	// �X�e�[�^�X��`
	// -----------------------------------------------------------
	// tk->kyoku[tk->kyoku_index].ryukyoku_stat = HOWANPAI;

	// -----------------------------------------------------------
	// ���e�[�u���ݒ�
	// -----------------------------------------------------------
/*	tk->kyoku[tk->kyoku_index].yakuman_count=0;
	tk->kyoku[tk->kyoku_index].yakucount=1;
	wsprintf(tk->kyoku[tk->kyoku_index].yakuname[0], "���ǁF�r�v");*/

	// -----------------------------------------------------------
	// ���_�ݒ�
	// -----------------------------------------------------------
	for(int tmp_num = 0; tmp_num< PLAYER_MAX; tmp_num++){
		if(tk->kyoku[tk->kyoku_index].ply_tempai_count == 0 || tk->kyoku[tk->kyoku_index].ply_tempai_count == 4){
			tk->kyoku[tk->kyoku_index].kyoku_score[tmp_num] = 0;
		}else if(tk->kyoku[tk->kyoku_index].ply_tempai_count == 1 && tk->kyoku[tk->kyoku_index].ply_tempai_flg[tmp_num] == true){
			tk->kyoku[tk->kyoku_index].kyoku_score[tmp_num] = 3000;
		}else if(tk->kyoku[tk->kyoku_index].ply_tempai_count == 1 && tk->kyoku[tk->kyoku_index].ply_tempai_flg[tmp_num] == false){
			tk->kyoku[tk->kyoku_index].kyoku_score[tmp_num] = -1000;
		}else if(tk->kyoku[tk->kyoku_index].ply_tempai_count == 2 && tk->kyoku[tk->kyoku_index].ply_tempai_flg[tmp_num] == true){
			tk->kyoku[tk->kyoku_index].kyoku_score[tmp_num] = 1500;
		}else if(tk->kyoku[tk->kyoku_index].ply_tempai_count == 2 && tk->kyoku[tk->kyoku_index].ply_tempai_flg[tmp_num] == false){
			tk->kyoku[tk->kyoku_index].kyoku_score[tmp_num] = -1500;
		}else if(tk->kyoku[tk->kyoku_index].ply_tempai_count == 3 && tk->kyoku[tk->kyoku_index].ply_tempai_flg[tmp_num] == true){
			tk->kyoku[tk->kyoku_index].kyoku_score[tmp_num] = 1000;
		}else if(tk->kyoku[tk->kyoku_index].ply_tempai_count == 3 && tk->kyoku[tk->kyoku_index].ply_tempai_flg[tmp_num] == false){
			tk->kyoku[tk->kyoku_index].kyoku_score[tmp_num] = -3000;
		}
	}

	// ���_�̉��Z
	Chk_totalscore(tk, kyoku_index);
}

/* ---------------------------------------------------------------------------------------------- */
// �\�[�X�I��
/* ---------------------------------------------------------------------------------------------- */
