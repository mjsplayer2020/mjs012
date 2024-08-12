/* ---------------------------------------------------------------------------------------------- 
 * 
 * プログラム概要 ： Newさくら麻雀(MJAIクライアント実装版)
 * バージョン     ： 0.1.2.0.164(OldScoreクラス削除)
 * プログラム名   ： mjs.exe
 * ファイル名     ： oldscore.cpp
 * クラス名       ： MJSOldScoreクラス
 * 処理概要       ： 得点計算クラス：廃止予定
 * Ver0.1.1作成日 ： 2022/07/24 10:32:05
 * Ver0.1.2作成日 ： 2022/08/31 22:19:54
 * 最終更新日     ： 2024/05/19 09:50:30
 * 
 * Copyright (c) 2010-2023 Techmilestone, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#include "oldscore.h"

/* ---------------------------------------------------------------------------------------------- */
// 得点計算クラスの初期化
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ScoreInit(){

}

/* ---------------------------------------------------------------------------------------------- */
// 得点計算クラスの終了処理
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ScorePost(){

}

/* ---------------------------------------------------------------------------------------------- */
// 得点計算のメイン処理
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::setAgariScore(MJSTkinfo *tk, int kyoku_index){

	// 事前定義
	SetYakuInfo();
	SetBaseScoreTable();

	// メイン処理
	chk_initAgariScore(tk, kyoku_index);    // 01:
	chk_preAgariScore(tk, kyoku_index);     // 02:

	// 通常形式の場合
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
// 役情報定義
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::SetYakuInfo(){

	// ハン数定義・通常役
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

	// ハン数定義・通常役：鳴きあり
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

	// 役満
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
// 基礎得点テーブルの設定
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::SetBaseScoreTable(){

	// 得点情報
	// https://mj-dragon.com/calc/index-score.html
	// http://yahoo-mbga.jp/page/stdgame/300001/majan_09.html

	// -----------------------------
	// 親ロン
	// -----------------------------

	// 親ロン・一翻
	score_ron_oya[0][0] = 0;    // 20符
	score_ron_oya[0][1] = 1500; // 30符
	score_ron_oya[0][2] = 2000; // 40符
	score_ron_oya[0][3] = 2400; // 50符
	score_ron_oya[0][4] = 2900; // 60符
	score_ron_oya[0][5] = 3400; // 70符
	score_ron_oya[0][6] = 3900; // 80符
	score_ron_oya[0][7] = 4400; // 90符
	score_ron_oya[0][8] = 4800; // 100符
	score_ron_oya[0][9] = 5300; // 110符

	// 親ロン・二翻
	score_ron_oya[1][0] = 2100;  // 20符
	score_ron_oya[1][1] = 2900;  // 30符
	score_ron_oya[1][2] = 3900;  // 40符
	score_ron_oya[1][3] = 4800;  // 50符
	score_ron_oya[1][4] = 5800;  // 60符
	score_ron_oya[1][5] = 6800;  // 70符
	score_ron_oya[1][6] = 7700;  // 80符
	score_ron_oya[1][7] = 8700;  // 90符
	score_ron_oya[1][8] = 9600;  // 100符
	score_ron_oya[1][9] = 10600; // 110符

	// 親ロン・三翻
	score_ron_oya[2][0] = 3900;  // 20符
	score_ron_oya[2][1] = 5800;  // 30符
	score_ron_oya[2][2] = 7700;  // 40符
	score_ron_oya[2][3] = 9600;  // 50符
	score_ron_oya[2][4] = 11600; // 60符
	score_ron_oya[2][5] = 12000; // 70符
	score_ron_oya[2][6] = 12000; // 80符
	score_ron_oya[2][7] = 12000; // 90符
	score_ron_oya[2][8] = 12000; // 100符
	score_ron_oya[2][9] = 12000; // 110符

	// 親ロン・四翻
	score_ron_oya[3][0] =  5800; // 20符
	score_ron_oya[3][1] = 11600; // 30符
	score_ron_oya[3][2] = 12000; // 40符
	score_ron_oya[3][3] = 12000; // 50符
	score_ron_oya[3][4] = 12000; // 60符
	score_ron_oya[3][5] = 12000; // 70符
	score_ron_oya[3][6] = 12000; // 80符
	score_ron_oya[3][7] = 12000; // 90符
	score_ron_oya[3][8] = 12000; // 100符
	score_ron_oya[3][9] = 12000; // 110符

	// 親ロン・七対子
	score_chitoi_ron_oya[0] = 1200;  // 一翻25符
	score_chitoi_ron_oya[1] = 2400;  // 二翻25符
	score_chitoi_ron_oya[2] = 4800;  // 三翻25符
	score_chitoi_ron_oya[3] = 9600;  // 四翻25符

	// 親ロン・満貫以上
	score_mangan_ron_oya[0] = 12000; // 満貫
	score_mangan_ron_oya[1] = 18000; // 跳満
	score_mangan_ron_oya[2] = 24000; // 倍満
	score_mangan_ron_oya[3] = 36000; // 三倍満
	score_mangan_ron_oya[4] = 48000; // 数え役満

	// 親ロン・役満
	score_yakuman_ron_oya = 48000;

	// -----------------------------
	// 子ロン
	// -----------------------------

	// 子ロン・一翻
	score_ron_ko[0][0] = 0;    // 20符
	score_ron_ko[0][1] = 1000; // 30符
	score_ron_ko[0][2] = 1300; // 40符
	score_ron_ko[0][3] = 1600; // 50符
	score_ron_ko[0][4] = 2000; // 60符
	score_ron_ko[0][5] = 2300; // 70符
	score_ron_ko[0][6] = 2600; // 80符
	score_ron_ko[0][7] = 2900; // 90符
	score_ron_ko[0][8] = 3200; // 100符
	score_ron_ko[0][9] = 3600; // 110符

	// 子ロン・二翻
	score_ron_ko[1][0] = 1300; // 20符
	score_ron_ko[1][1] = 2000; // 30符
	score_ron_ko[1][2] = 2600; // 40符
	score_ron_ko[1][3] = 3200; // 50符
	score_ron_ko[1][4] = 3900; // 60符
	score_ron_ko[1][5] = 4500; // 70符
	score_ron_ko[1][6] = 5200; // 80符
	score_ron_ko[1][7] = 5800; // 90符
	score_ron_ko[1][8] = 6400; // 100符
	score_ron_ko[1][9] = 7100; // 110符

	// 子ロン・三翻
	score_ron_ko[2][0] = 2600; // 20符
	score_ron_ko[2][1] = 3900; // 30符
	score_ron_ko[2][2] = 5200; // 40符
	score_ron_ko[2][3] = 6400; // 50符
	score_ron_ko[2][4] = 7700; // 60符
	score_ron_ko[2][5] = 8000; // 70符
	score_ron_ko[2][6] = 8000; // 80符
	score_ron_ko[2][7] = 8000; // 90符
	score_ron_ko[2][8] = 8000; // 100符
	score_ron_ko[2][9] = 8000; // 110符

	// 子ロン・四翻
	score_ron_ko[3][0] = 5200; // 20符
	score_ron_ko[3][1] = 7700; // 30符
	score_ron_ko[3][2] = 8000; // 40符
	score_ron_ko[3][3] = 8000; // 50符
	score_ron_ko[3][4] = 8000; // 60符
	score_ron_ko[3][5] = 8000; // 70符
	score_ron_ko[3][6] = 8000; // 80符
	score_ron_ko[3][7] = 8000; // 90符
	score_ron_ko[3][8] = 8000; // 100符
	score_ron_ko[3][9] = 8000; // 110符

	// 子ロン・七対子
	score_chitoi_ron_oya[0] =  800;  // 一翻25符
	score_chitoi_ron_oya[1] = 1600;  // 二翻25符
	score_chitoi_ron_oya[2] = 3200;  // 三翻25符
	score_chitoi_ron_oya[3] = 6400;  // 四翻25符

	// 子ロン・満貫以上
	score_mangan_ron_ko[0] =  8000; // 満貫
	score_mangan_ron_ko[1] = 12000; // 跳満
	score_mangan_ron_ko[2] = 16000; // 倍満
	score_mangan_ron_ko[3] = 24000; // 三倍満
	score_mangan_ron_ko[4] = 32000; // 数え役満

	// 子ロン・役満
	score_yakuman_ron_ko = 32000;

	// -----------------------------
	// 自摸和了・親支払い
	// -----------------------------

	// 自摸和了親支払い・一翻
	score_tsumo_oya[0][0] =    0; // 20符
	score_tsumo_oya[0][1] =  500; // 30符
	score_tsumo_oya[0][2] =  700; // 40符
	score_tsumo_oya[0][3] =  800; // 50符
	score_tsumo_oya[0][4] = 1000; // 60符
	score_tsumo_oya[0][5] = 1200; // 70符
	score_tsumo_oya[0][6] = 1300; // 80符
	score_tsumo_oya[0][7] = 1500; // 90符
	score_tsumo_oya[0][8] = 1600; // 100符
	score_tsumo_oya[0][9] = 1800; // 110符

	// 自摸和了親支払い・二翻
	score_tsumo_oya[1][0] =  700; // 20符
	score_tsumo_oya[1][1] = 1000; // 30符
	score_tsumo_oya[1][2] = 1300; // 40符
	score_tsumo_oya[1][3] = 1600; // 50符
	score_tsumo_oya[1][4] = 2000; // 60符
	score_tsumo_oya[1][5] = 2300; // 70符
	score_tsumo_oya[1][6] = 2600; // 80符
	score_tsumo_oya[1][7] = 2900; // 90符
	score_tsumo_oya[1][8] = 3200; // 100符
	score_tsumo_oya[1][9] = 3600; // 110符

	// 自摸和了親支払い・三翻
	score_tsumo_oya[2][0] = 1300; // 20符
	score_tsumo_oya[2][1] = 2000; // 30符
	score_tsumo_oya[2][2] = 2600; // 40符
	score_tsumo_oya[2][3] = 3200; // 50符
	score_tsumo_oya[2][4] = 3900; // 60符
	score_tsumo_oya[2][5] = 4000; // 70符
	score_tsumo_oya[2][6] = 4000; // 80符
	score_tsumo_oya[2][7] = 4000; // 90符
	score_tsumo_oya[2][8] = 4000; // 100符
	score_tsumo_oya[2][9] = 4000; // 110符

	// 自摸和了親支払い・四翻
	score_tsumo_oya[3][0] = 2600; // 20符
	score_tsumo_oya[3][1] = 3900; // 30符
	score_tsumo_oya[3][2] = 4000; // 40符
	score_tsumo_oya[3][3] = 4000; // 50符
	score_tsumo_oya[3][4] = 4000; // 60符
	score_tsumo_oya[3][5] = 4000; // 70符
	score_tsumo_oya[3][6] = 4000; // 80符
	score_tsumo_oya[3][7] = 4000; // 90符
	score_tsumo_oya[3][8] = 4000; // 100符
	score_tsumo_oya[3][9] = 4000; // 110符

	// 自摸和了親支払い・七対子
	score_chitoi_tsumo_oya[0] =  400;
	score_chitoi_tsumo_oya[1] =  800;
	score_chitoi_tsumo_oya[2] = 1600;
	score_chitoi_tsumo_oya[3] = 3200;

	// 自摸和了親支払い・満貫以上
	score_mangan_tsumo_oya[0] =  4000;
	score_mangan_tsumo_oya[1] =  6000;
	score_mangan_tsumo_oya[2] =  8000;
	score_mangan_tsumo_oya[3] = 12000;
	score_mangan_tsumo_oya[4] = 16000;

	// 自摸和了親支払い・役満
	score_yakuman_tsumo_oya = 16000;

	// -----------------------------
	// 自摸和了・子支払い
	// -----------------------------

	// 自摸和了子支払い・一翻
	score_tsumo_ko[0][0] = 0;    // 20符
	score_tsumo_ko[0][1] = 300;  // 30符
	score_tsumo_ko[0][2] = 400;  // 40符
	score_tsumo_ko[0][3] = 400;  // 50符
	score_tsumo_ko[0][4] = 500;  // 60符
	score_tsumo_ko[0][5] = 600;  // 70符
	score_tsumo_ko[0][6] = 700;  // 80符
	score_tsumo_ko[0][7] = 800;  // 90符
	score_tsumo_ko[0][8] = 800;  // 100符
	score_tsumo_ko[0][9] = 900;  // 110符

	// 自摸和了子支払い・二翻
	score_tsumo_ko[1][0] =  400;  // 20符
	score_tsumo_ko[1][1] =  500;  // 30符
	score_tsumo_ko[1][2] =  700;  // 40符
	score_tsumo_ko[1][3] =  800;  // 50符
	score_tsumo_ko[1][4] = 1000;  // 60符
	score_tsumo_ko[1][5] = 1200;  // 70符
	score_tsumo_ko[1][6] = 1300;  // 80符
	score_tsumo_ko[1][7] = 1500;  // 90符
	score_tsumo_ko[1][8] = 1600;  // 100符
	score_tsumo_ko[1][9] = 1800;  // 110符

	// 自摸和了子支払い・三翻
	score_tsumo_ko[2][0] =  700; // 20符
	score_tsumo_ko[2][1] = 1000; // 30符
	score_tsumo_ko[2][2] = 1300; // 40符
	score_tsumo_ko[2][3] = 1600; // 50符
	score_tsumo_ko[2][4] = 2000; // 60符
	score_tsumo_ko[2][5] = 2000; // 70符
	score_tsumo_ko[2][6] = 2000; // 80符
	score_tsumo_ko[2][7] = 2000; // 90符
	score_tsumo_ko[2][8] = 2000; // 100符
	score_tsumo_ko[2][9] = 2000; // 110符

	// 自摸和了子支払い・四翻
	score_tsumo_ko[3][0] = 1300; // 20符
	score_tsumo_ko[3][1] = 2000; // 30符
	score_tsumo_ko[3][2] = 2000; // 40符
	score_tsumo_ko[3][3] = 2000; // 50符
	score_tsumo_ko[3][4] = 2000; // 60符
	score_tsumo_ko[3][5] = 2000; // 70符
	score_tsumo_ko[3][6] = 2000; // 80符
	score_tsumo_ko[3][7] = 2000; // 90符
	score_tsumo_ko[3][8] = 2000; // 100符
	score_tsumo_ko[3][9] = 2000; // 110符

	// 自摸和了子支払い・七対子
	score_chitoi_tsumo_ko[0] =  200;
	score_chitoi_tsumo_ko[1] =  400;
	score_chitoi_tsumo_ko[2] =  800;
	score_chitoi_tsumo_ko[3] = 1600;

	// 自摸和了子支払い・満貫以上
	score_mangan_tsumo_ko[0] = 2000;
	score_mangan_tsumo_ko[1] = 3000;
	score_mangan_tsumo_ko[2] = 4000;
	score_mangan_tsumo_ko[3] = 6000;
	score_mangan_tsumo_ko[4] = 8000;

	// 自摸和了子支払い・役満
	score_yakuman_tsumo_ko   = 8000;

}

/* ---------------------------------------------------------------------------------------------- */
// 01:初期化処理
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_initAgariScore(MJSTkinfo *tk, int kyoku_index){

	// 和了牌面子
	tk->kyoku[kyoku_index].agari_men_num_agari_hai = 999;

	// ドラ
	tk->kyoku[kyoku_index].agari_dora_count=0; 
	tk->kyoku[kyoku_index].agari_uradora_count=0;

	// 赤牌
	tk->kyoku[kyoku_index].agari_aka_count[0]=0;
	tk->kyoku[kyoku_index].agari_aka_count[1]=0;
	tk->kyoku[kyoku_index].agari_aka_count[2]=0;

	// 面子数
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

	// 符の設定
	tk->kyoku[kyoku_index].basefu = 20;
	tk->kyoku[kyoku_index].agari_men_Fu[0]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[1]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[2]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[3]=0;
	tk->kyoku[kyoku_index].atamaFu=0;
	tk->kyoku[kyoku_index].menzenFu=0;
	tk->kyoku[kyoku_index].machiFu=0;
	tk->kyoku[kyoku_index].tsumoFu=0;

	// 符の合計
	tk->kyoku[kyoku_index].totalFu = tk->kyoku[kyoku_index].basefu;
	tk->kyoku[kyoku_index].scoreFu = tk->kyoku[kyoku_index].totalFu;

}

/* ---------------------------------------------------------------------------------------------- */
// 02:事前和了情報の設定
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_preAgariScore(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// 局情報の設定
	// -----------------------------

	// 流局フラグ
	tk->kyoku[kyoku_index].ryukyoku_flg = false;

	// 場風時風の設定
	tk->agari_ply_bakaze = 31;
	tk->agari_ply_zikaze = 31+tk->kyoku[kyoku_index].ie[tk->kyoku[kyoku_index].agari_ply_num];

	// 親フラグの設定
	if(tk->kyoku[kyoku_index].agari_ply_num == tk->kyoku[kyoku_index].kyoku_oya){
		tk->kyoku[kyoku_index].agari_ply_oya_flg = true;
	}else{
		tk->kyoku[kyoku_index].agari_ply_oya_flg = false;
	}

	// 面前フラグの設定
	if(tk->kyoku[kyoku_index].naki_count[tk->kyoku[kyoku_index].agari_ply_num] == 0){
		tk->kyoku[kyoku_index].menzen_flg = true;
	}else{
		tk->kyoku[kyoku_index].menzen_flg = false;
	}

	// -----------------------------
	// 和了プレーヤーの和了自摸回数・リーチ状態確認(初期化)
	// -----------------------------

	tk->kyoku[kyoku_index].riichi_flg          = false;
	tk->kyoku[kyoku_index].ippatsu_riichi_flg  = false;
	tk->kyoku[kyoku_index].w_riichi_flg        = false;
	tk->kyoku[kyoku_index].agari_ply_tsumo_count  = 0;
	tk->kyoku[kyoku_index].agari_ply_riichi_count = 0;

	// -----------------------------
	// 和了プレーヤーの和了自摸回数・リーチ状態確認(メイン処理)
	// -----------------------------

	// アクションの確認
	for(int tmp_i = 0; tmp_i < tk->kyoku[kyoku_index].act_count+1; tmp_i++){

		// 自摸回数カウント
		if(tk->kyoku[kyoku_index].act_stat[tmp_i] == PLYACTTSUMO &&
		   tk->kyoku[kyoku_index].act_ply[tmp_i]  == tk->kyoku[kyoku_index].agari_ply_num ){
			// 自摸カウント
			tk->kyoku[kyoku_index].agari_ply_tsumo_count++;
		}

		// リーチ確認
		if(tk->kyoku[kyoku_index].act_stat[tmp_i] == PLYACTRIICH &&
		   tk->kyoku[kyoku_index].act_ply[tmp_i]  == tk->kyoku[kyoku_index].agari_ply_num ){

			// リーチモード変更
			tk->kyoku[kyoku_index].riichi_flg=true;

			// ダブルリーチ確認
			if(tk->kyoku[kyoku_index].agari_ply_tsumo_count == 1){
				// リーチモード変更
				tk->kyoku[kyoku_index].w_riichi_flg=true;
			}else{
				// リーチモード変更
				tk->kyoku[kyoku_index].w_riichi_flg=false;
			}	
	
			// リーチ巡目の設定
			tk->kyoku[kyoku_index].agari_ply_riichi_count = tk->kyoku[kyoku_index].agari_ply_tsumo_count;

		}

		// リーチ一発確認(自摸和了)
		if (tk->kyoku[kyoku_index].act_stat[tmp_i] == PLYTSUMOAGARI && 
			tk->kyoku[kyoku_index].riichi_flg == true &&
		    tk->kyoku[kyoku_index].act_ply[tmp_i]  == tk->kyoku[kyoku_index].agari_ply_num ){
			// 次巡であれば一発
			if(tk->kyoku[kyoku_index].agari_ply_riichi_count + 1 == tk->kyoku[kyoku_index].agari_ply_tsumo_count){
				// リーチモード変更
				tk->kyoku[kyoku_index].ippatsu_riichi_flg=true;
			}else{
				// リーチモード変更
				tk->kyoku[kyoku_index].ippatsu_riichi_flg=false;
			}
		}

		// リーチ一発確認(ロン和了)
		if (tk->kyoku[kyoku_index].act_stat[tmp_i] == PLYACTRON && 
			tk->kyoku[kyoku_index].riichi_flg == true &&
		    tk->kyoku[kyoku_index].act_ply[tmp_i]  == tk->kyoku[kyoku_index].agari_ply_num ){
			// 次巡であれば一発
			if(tk->kyoku[kyoku_index].agari_ply_riichi_count == tk->kyoku[kyoku_index].agari_ply_tsumo_count){
				// リーチモード変更
				tk->kyoku[kyoku_index].ippatsu_riichi_flg=true;
			}else{
				// リーチモード変更
				tk->kyoku[kyoku_index].ippatsu_riichi_flg=false;
			}
		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 03:事前和了情報の設定(七対子)
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_chitoi_mentsu(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// 変数定義
	// -----------------------------

	// 赤牌作業用
	int tmp_aka_man;
	int tmp_aka_pin;
	int tmp_aka_sou;

	tk->kyoku[kyoku_index].mentsu_count_19zi=0;                   // 一九字の面子数
	tk->kyoku[kyoku_index].mentsu_count_chunchan=0;               // 中張牌の面子数

	tk->kyoku[kyoku_index].mentsu_count_manzu=0;                  // 萬子数
	tk->kyoku[kyoku_index].mentsu_count_pinzu=0;                  // 筒子数
	tk->kyoku[kyoku_index].mentsu_count_souzu=0;                  // 索子数
	tk->kyoku[kyoku_index].mentsu_count_zihai=0;                  // 字牌の数

	// -----------------------------
	// 待ち形式
	// -----------------------------
	tk->kyoku[kyoku_index].agari_machi_stat = TANKI;

	// -----------------------------
	// 符の設定
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

	// 符の合計
	tk->kyoku[kyoku_index].totalFu = tk->kyoku[kyoku_index].basefu;
	tk->kyoku[kyoku_index].scoreFu = tk->kyoku[kyoku_index].totalFu;

	// -----------------------------
	// 赤牌初期化
	// -----------------------------

	// 作業用変数の設定
	tmp_aka_man = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][0];
	tmp_aka_pin = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][1];
	tmp_aka_sou = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][2];

	// -----------------------------
	// 面子確認
	// -----------------------------
	int tmp_men_count=0;
	for(int tmp_hai=1; tmp_hai<PAI_MAX; tmp_hai++){
		// 和了面子番号設定
		if(tk->kyoku[kyoku_index].agari_hai == tmp_hai){
			tk->kyoku[kyoku_index].agari_men_num_agari_hai = tmp_men_count;
		}

		// 頭処理確認
		if(tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][tmp_hai] > 1 ||
		   tk->kyoku[kyoku_index].agari_hai == tmp_hai){
			// 面子設定
			tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_men_count] = tmp_hai;
			tk->kyoku[kyoku_index].agari_chitoi_men_aka_count[tmp_men_count] = 0;
			tmp_men_count++;
		}

	}

	// -----------------------------
	// 各手牌の枚数確認
	// -----------------------------
	for(int tmp_i=0; tmp_i<7; tmp_i++){

		// -----------------------------
		// 一九字確認
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

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_19zi++;

		}else{

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_chunchan++;

		}

		// -----------------------------
		// 色枚数
		// -----------------------------
		if (tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] >  0 &&
		    tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] < 10 ){

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_manzu++;

		}else if ( tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] > 10 &&
		           tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] < 20 ){

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_pinzu++;

		}else if ( tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] > 20 &&
		           tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] < 30 ){

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_souzu++;

		}else if ( tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] > 30 &&
		           tk->kyoku[kyoku_index].agari_chitoi_men_hai[tmp_i] < 38 ){

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_zihai++;

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 03:事前和了情報の設定(国士)
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_kokushi_mentsu(MJSTkinfo *tk, int kyoku_index){

	// 待ち形式
	tk->kyoku[kyoku_index].agari_machi_stat = TANKI;

	// 符の設定
	tk->kyoku[kyoku_index].basefu = 20;
	tk->kyoku[kyoku_index].agari_men_Fu[0]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[1]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[2]=0;
	tk->kyoku[kyoku_index].agari_men_Fu[3]=0;
	tk->kyoku[kyoku_index].atamaFu=0;
	tk->kyoku[kyoku_index].menzenFu=0;
	tk->kyoku[kyoku_index].machiFu=0;
	tk->kyoku[kyoku_index].tsumoFu=0;

	// 符の合計
	tk->kyoku[kyoku_index].totalFu = tk->kyoku[kyoku_index].basefu;
	tk->kyoku[kyoku_index].scoreFu = tk->kyoku[kyoku_index].totalFu;
}

/* ---------------------------------------------------------------------------------------------- */
// 03:面子確認
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_mentsu(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// 変数定義
	// -----------------------------

	// 赤牌作業用
	int tmp_aka_man;
	int tmp_aka_pin;
	int tmp_aka_sou;

	tk->kyoku[kyoku_index].agari_aka_count[0] = 0;
	tk->kyoku[kyoku_index].agari_aka_count[1] = 0;
	tk->kyoku[kyoku_index].agari_aka_count[2] = 0;

	// -----------------------------
	// 赤牌初期化
	// -----------------------------

	// 作業用変数の設定
	tmp_aka_man = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][0];
	tmp_aka_pin = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][1];
	tmp_aka_sou = tk->ply_act_aka_count[tk->kyoku[kyoku_index].agari_ply_num][2];

	// -----------------------------
	// 雀頭情報の設定
	// -----------------------------

	// 雀頭設定
	tk->kyoku[kyoku_index].agari_ata_hai = tk->atama_hai;

	// 和了牌の面子番号設定
	if (tk->kyoku[kyoku_index].agari_ata_hai == tk->kyoku[kyoku_index].agari_hai){

		// 面子番号は仮置きの「999」とする
		tk->kyoku[kyoku_index].agari_men_num_agari_hai = 999;

	}

	// 赤牌設定
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
	// メンツ情報の設定
	// -----------------------------
	for(int tmp_i = 0; tmp_i < tk->mentu_count; tmp_i++){

		// -----------------------------
		// メンツ情報の格納
		// -----------------------------

		tk->kyoku[kyoku_index].agari_men_stat[tmp_i]      = tk->mentu_stat[tmp_i];  
		tk->kyoku[kyoku_index].agari_men_hai[tmp_i]       = tk->mentu_hai[tmp_i];   
		tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i] = 0;                      // 赤牌の初期化

		// -----------------------------
		// 暗刻処理
		// -----------------------------
		if ( tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKO){

			// 萬子処理
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 5){
				if(tmp_aka_man>3){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=3;
					tmp_aka_man=tmp_aka_man-3;
				}else{
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=tmp_aka_man;
					tmp_aka_man=0;
				}
			}

			// 筒子処理
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 15){
				if(tmp_aka_pin>2){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=3;
					tmp_aka_pin=tmp_aka_pin-3;
				}else{
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=tmp_aka_pin;
					tmp_aka_pin=0;
				}
			}

			// 索子処理
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 25){
				if(tmp_aka_sou>2){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=3;
					tmp_aka_sou=tmp_aka_sou-3;
				}else{
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]=tmp_aka_sou;
					tmp_aka_sou=0;
				}
			}
		
			// 和了牌の面子番号設定 - 暗刻の場合
			if ( tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == tk->kyoku[kyoku_index].agari_hai){

				// 面子番号の設定
				tk->kyoku[kyoku_index].agari_men_num_agari_hai = tmp_i;

				// ロン和了の面子番号は鳴きメンツに変更する
				if(tk->kyoku[kyoku_index].tsumo_agari_flg == false){
					tk->kyoku[kyoku_index].agari_men_stat[tmp_i] = MINKO;
				}

			}
		}

		// -----------------------------
		// 順子処理
		// -----------------------------
		if ( tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == SHUNTSU){

			// 萬子処理
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 3 || 
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 4 ||
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 5){

				// 赤牌があるなら
				if(tmp_aka_man>0){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]++;
					tmp_aka_man--;
				}
			}

			// 筒子処理
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 13 || 
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 14 ||
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 15){

				// 赤牌があるなら
				if(tmp_aka_pin>0){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]++;
					tmp_aka_pin--;
				}
			}

			// 索子処理
			if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 23 || 
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 24 ||
			   tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 25){

				// 赤牌があるなら
				if(tmp_aka_sou>0){
					tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i]++;
					tmp_aka_sou--;
				}
			}

			// 和了牌の面子番号設定 - 順子の場合
			if ( tk->kyoku[kyoku_index].agari_men_hai[tmp_i]   == tk->kyoku[kyoku_index].agari_hai || 
			     tk->kyoku[kyoku_index].agari_men_hai[tmp_i]+1 == tk->kyoku[kyoku_index].agari_hai || 
			     tk->kyoku[kyoku_index].agari_men_hai[tmp_i]+2 == tk->kyoku[kyoku_index].agari_hai ){

				// 面子番号の設定
				tk->kyoku[kyoku_index].agari_men_num_agari_hai = tmp_i;

				// ロン和了の面子番号は鳴きメンツに変更する
				if(tk->kyoku[kyoku_index].tsumo_agari_flg == false){
					tk->kyoku[kyoku_index].agari_men_stat[tmp_i] = MINSHUN;
				}
			}

		}

	}

	// -----------------------------
	// 晒し面子の設定
	// -----------------------------

	// 晒し面子の追加
	for(int tmp_i = 0; tmp_i < tk->kyoku[kyoku_index].naki_count[tk->kyoku[kyoku_index].agari_ply_num]; tmp_i++){

		// カカン確認
		if( tk->kyoku[kyoku_index].naki_stat[tk->kyoku[kyoku_index].agari_ply_num][tmp_i] == KAKAN){

			// カカン面子設定
			for(int tmp_j = 0; tmp_j < tk->mentu_count; tmp_j++){

				// カカンした暗刻であれば
				if(tk->kyoku[kyoku_index].agari_men_hai[tmp_j] == tk->kyoku[kyoku_index].naki_idx[tk->kyoku[kyoku_index].agari_ply_num][tmp_i]){

					// メンツ情報の格納(カカン)
					tk->kyoku[kyoku_index].agari_men_stat[tmp_j] = MINKAN;

					// 赤牌+1加算
					if( tk->kyoku[kyoku_index].naki_aka[tk->kyoku[kyoku_index].agari_ply_num][tmp_j] > 0){
						tk->kyoku[kyoku_index].agari_men_aka_count[tmp_j]++;
					}

				}
			}

		// カカン以外
		}else{

			// メンツ情報の格納
			tk->kyoku[kyoku_index].agari_men_stat[tk->mentu_count]       = tk->kyoku[kyoku_index].naki_stat[tk->kyoku[kyoku_index].agari_ply_num][tmp_i];
			tk->kyoku[kyoku_index].agari_men_hai[tk->mentu_count]        = tk->kyoku[kyoku_index].naki_idx[tk->kyoku[kyoku_index].agari_ply_num][tmp_i];
			tk->kyoku[kyoku_index].agari_men_aka_count[tk->mentu_count]  = tk->kyoku[kyoku_index].naki_aka[tk->kyoku[kyoku_index].agari_ply_num][tmp_i];
			tk->mentu_count++;

		}

	}

	// -----------------------------
	// 待ち形式の確認
	// -----------------------------

	// 単騎待ち確認
	if( tk->kyoku[kyoku_index].agari_men_num_agari_hai == 999){
		tk->kyoku[kyoku_index].agari_machi_stat = TANKI;

	// 順子関連の待ち
	}else if( tk->kyoku[kyoku_index].agari_men_stat[tk->kyoku[kyoku_index].agari_men_num_agari_hai] == SHUNTSU ||
              tk->kyoku[kyoku_index].agari_men_stat[tk->kyoku[kyoku_index].agari_men_num_agari_hai] == MINSHUN ){

		// 和了牌が面子INDEXと同じなら
		if( tk->kyoku[kyoku_index].agari_men_hai[tk->kyoku[kyoku_index].agari_men_num_agari_hai] == tk->kyoku[kyoku_index].agari_hai ){

			// ペンチャンを調べる
			if( tk->kyoku[kyoku_index].agari_hai ==  7 || 
			    tk->kyoku[kyoku_index].agari_hai == 17 || 
			    tk->kyoku[kyoku_index].agari_hai == 27 ){
				tk->kyoku[kyoku_index].agari_machi_stat = PENCHAN ; 
			}else{
				tk->kyoku[kyoku_index].agari_machi_stat = RYANMEN;
			}

		}

		// 和了牌が面子INDEX+1なら
		if( tk->kyoku[kyoku_index].agari_men_hai[tk->kyoku[kyoku_index].agari_men_num_agari_hai] + 1 == tk->kyoku[kyoku_index].agari_hai ){
			tk->kyoku[kyoku_index].agari_machi_stat = KANCHAN;
		}

		// 和了牌が面子INDEX+2なら
		if( tk->kyoku[kyoku_index].agari_men_hai[tk->kyoku[kyoku_index].agari_men_num_agari_hai] + 2 == tk->kyoku[kyoku_index].agari_hai ){

			// ペンチャンを調べる
			if( tk->kyoku[kyoku_index].agari_hai ==  3 || 
			    tk->kyoku[kyoku_index].agari_hai == 13 || 
			    tk->kyoku[kyoku_index].agari_hai == 23 ){
				tk->kyoku[kyoku_index].agari_machi_stat = PENCHAN ; 
			}else{
				tk->kyoku[kyoku_index].agari_machi_stat = RYANMEN;
			}

		}

	// シャポン待ち確認
	}else if( tk->kyoku[kyoku_index].agari_men_stat[tk->kyoku[kyoku_index].agari_men_num_agari_hai] == ANKO  ||
              tk->kyoku[kyoku_index].agari_men_stat[tk->kyoku[kyoku_index].agari_men_num_agari_hai] == MINKO ){
				tk->kyoku[kyoku_index].agari_machi_stat = TOITSU;

	// その他
	}else{
		tk->kyoku[kyoku_index].agari_machi_stat = NOMENTSU;
	}

	// -----------------------------
	// ドラカウント
	// -----------------------------

	// カウント処理
	Chk_tehai_dora_count(tk, kyoku_index, 0 , false);

	// -----------------------------
	// 赤牌カウント
	// -----------------------------

	tk->kyoku[kyoku_index].agari_aka_count[0] = 0;
	tk->kyoku[kyoku_index].agari_aka_count[1] = 0;
	tk->kyoku[kyoku_index].agari_aka_count[2] = 0;

	// 頭赤カウント
	if(tk->kyoku[kyoku_index].agari_ata_hai == MAN5NUM){
		tk->kyoku[kyoku_index].agari_aka_count[0]=tk->kyoku[kyoku_index].agari_ata_aka;
	}else if(tk->kyoku[kyoku_index].agari_ata_hai == PIN5NUM){
		tk->kyoku[kyoku_index].agari_aka_count[1]=tk->kyoku[kyoku_index].agari_ata_aka;
	}else if(tk->kyoku[kyoku_index].agari_ata_hai == SOU5NUM){
		tk->kyoku[kyoku_index].agari_aka_count[2]=tk->kyoku[kyoku_index].agari_ata_aka;
	}

	// 面子赤カウント
	for(int tmp_i = 0; tmp_i < 4; tmp_i++){

		// 面子赤カウント - 萬子
		if( tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == MAN3NUM || 
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == MAN4NUM ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == MAN5NUM ){

			// 赤牌加算
			tk->kyoku[kyoku_index].agari_aka_count[0] = tk->kyoku[kyoku_index].agari_aka_count[0] + tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i];

		// 面子赤カウント - 筒子
		}else if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == PIN3NUM ||
		         tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == PIN4NUM ||
		         tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == PIN5NUM ){

			// 赤牌加算
			tk->kyoku[kyoku_index].agari_aka_count[1] = tk->kyoku[kyoku_index].agari_aka_count[1] + tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i];

		// 面子赤カウント - 索子
		}else if(tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == SOU3NUM ||
		         tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == SOU4NUM ||
		         tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == SOU5NUM ){

			// 赤牌加算
			tk->kyoku[kyoku_index].agari_aka_count[2] = tk->kyoku[kyoku_index].agari_aka_count[2] + tk->kyoku[kyoku_index].agari_men_aka_count[tmp_i];

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 03:手牌枚数確認
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_tehai_count(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// 各手牌の枚数確認
	// -----------------------------

	// 変数初期化

	tk->kyoku[kyoku_index].mentsu_count_shuntsu = 0;
	tk->kyoku[kyoku_index].mentsu_count_minshun = 0;
	tk->kyoku[kyoku_index].mentsu_count_anko    = 0;
	tk->kyoku[kyoku_index].mentsu_count_minko   = 0;
	tk->kyoku[kyoku_index].mentsu_count_ankan   = 0;
	tk->kyoku[kyoku_index].mentsu_count_minkan  = 0;

	tk->kyoku[kyoku_index].mentsu_count_19zi     = 0;             // 一九字の数
	tk->kyoku[kyoku_index].mentsu_count_chunchan = 0;             // 中張牌の面子数

	tk->kyoku[kyoku_index].mentsu_count_manzu    = 0;             // 萬子数
	tk->kyoku[kyoku_index].mentsu_count_pinzu    = 0;             // 筒子数
	tk->kyoku[kyoku_index].mentsu_count_souzu    = 0;             // 索子数
	tk->kyoku[kyoku_index].mentsu_count_zihai    = 0;             // 字牌の数
	tk->kyoku[kyoku_index].mentsu_count_green    = 0;             // 緑牌の数

	// ヒストグラムの初期化
	for(int tmp_i = 0; tmp_i < PAI_MAX; tmp_i++){
		tk->anko_hist[tmp_i]    = 0;
		tk->shuntsu_hist[tmp_i] = 0;
	}

	// -----------------------------
	// 雀頭確認処理
	// -----------------------------

		// -----------------------------
		// 雀頭確認処理
		// -----------------------------

		// 役牌確認
		if (tk->kyoku[kyoku_index].agari_ata_hai == tk->agari_ply_bakaze ||
		    tk->kyoku[kyoku_index].agari_ata_hai == tk->agari_ply_zikaze ||
		    tk->kyoku[kyoku_index].agari_ata_hai == 35 ||
	        tk->kyoku[kyoku_index].agari_ata_hai == 36 ||
		    tk->kyoku[kyoku_index].agari_ata_hai == 37 ){

			// 役牌設定
			tk->kyoku[kyoku_index].agari_ata_19zi = 2; 

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_19zi++;

		// 一九字牌確認
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

			// 一九字牌設定
			tk->kyoku[kyoku_index].agari_ata_19zi = 1;

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_19zi++;

		// 中張牌確認
		}else{

			// 中張牌設定
			tk->kyoku[kyoku_index].agari_ata_19zi = 0;

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_chunchan++;

		}

		// -----------------------------
		// 萬子・筒子・索子・字牌の枚数確認(雀頭)
		// -----------------------------

		// 萬子加算
		if (tk->kyoku[kyoku_index].agari_ata_hai >  0 &&
		    tk->kyoku[kyoku_index].agari_ata_hai < 10 ){

			// 萬子加算
			tk->kyoku[kyoku_index].mentsu_count_manzu++;

		// 筒子加算
		}else if (tk->kyoku[kyoku_index].agari_ata_hai > 10 &&
		          tk->kyoku[kyoku_index].agari_ata_hai < 20 ){

			// 筒子加算
			tk->kyoku[kyoku_index].mentsu_count_pinzu++;

		// 索子加算
		}else if (tk->kyoku[kyoku_index].agari_ata_hai > 20 &&
		          tk->kyoku[kyoku_index].agari_ata_hai < 30 ){

			// 索子加算
			tk->kyoku[kyoku_index].mentsu_count_souzu++;

		// 字牌加算
		}else if (tk->kyoku[kyoku_index].agari_ata_hai > 30 &&
		          tk->kyoku[kyoku_index].agari_ata_hai < 38 ){

			// 字牌加算
			tk->kyoku[kyoku_index].mentsu_count_zihai++;

		}

	// -----------------------------
	// 緑牌の枚数確認(雀頭)
	// -----------------------------





	// -----------------------------
	// 面子確認処理
	// -----------------------------

	for(int tmp_i = 0; tmp_i < 4; tmp_i++){

		// -----------------------------
		// 一九字確認(メンツ)
		// -----------------------------

		if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == tk->agari_ply_bakaze ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == tk->agari_ply_zikaze ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 35 ||
	        tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 36 ||
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 37 ){

			// 役牌設定
			tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] = 2; 

			// 面子数の加算
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

			// 一九字設定
			tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] = 1; 

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_19zi++;

		// 789のペンチャンの場合
		}else if((tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == SHUNTSU || tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINSHUN) && 
                 (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 7  || 
		          tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 17 || 
		          tk->kyoku[kyoku_index].agari_men_hai[tmp_i] == 27 )){

			// 一九字設定
			tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] = 1; 

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_19zi++;


		}else{

			// 中張牌設定
			tk->kyoku[kyoku_index].agari_men_19zi[tmp_i] = 0;

			// 面子数の加算
			tk->kyoku[kyoku_index].mentsu_count_chunchan++;

		}

		// -----------------------------
		// 萬子・筒子・索子・字牌の枚数確認(面子)
		// -----------------------------

		// 萬子加算
		if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] >  0 &&
		    tk->kyoku[kyoku_index].agari_men_hai[tmp_i] < 10 ){

			// 萬子加算
			tk->kyoku[kyoku_index].mentsu_count_manzu++;

		// 筒子加算
		}else if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] > 10 &&
		          tk->kyoku[kyoku_index].agari_men_hai[tmp_i] < 20 ){

			// 筒子加算
			tk->kyoku[kyoku_index].mentsu_count_pinzu++;

		// 索子加算
		}else if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] > 20 &&
		          tk->kyoku[kyoku_index].agari_men_hai[tmp_i] < 30 ){

			// 索子加算
			tk->kyoku[kyoku_index].mentsu_count_souzu++;

		// 字牌加算
		}else if (tk->kyoku[kyoku_index].agari_men_hai[tmp_i] > 30 &&
		          tk->kyoku[kyoku_index].agari_men_hai[tmp_i] < 38 ){

			// 字牌加算
			tk->kyoku[kyoku_index].mentsu_count_zihai++;

		}

		// -----------------------------
		// 緑牌の枚数確認
		// -----------------------------




		// -----------------------------
		// 順子・暗刻のヒストグラム設定
		// -----------------------------

		if( tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == SHUNTSU ){

			// 面子種別の加算
			tk->kyoku[kyoku_index].mentsu_count_shuntsu++;

			// ヒストグラム加算
			tk->shuntsu_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}else if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINSHUN ){

			// 面子種別の加算
			tk->kyoku[kyoku_index].mentsu_count_minshun++;

			// ヒストグラム加算
			tk->shuntsu_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}else if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKO){

			// 面子種別の加算
			tk->kyoku[kyoku_index].mentsu_count_anko++;

			// ヒストグラム加算
			tk->anko_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}else if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINKO){

			// 面子種別の加算
			tk->kyoku[kyoku_index].mentsu_count_minko++;

			// ヒストグラム加算
			tk->anko_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}else if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKAN){

			// 面子種別の加算
			tk->kyoku[kyoku_index].mentsu_count_ankan++;

			// ヒストグラム加算
			tk->anko_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}else if(tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINKAN){

			// 面子種別の加算
			tk->kyoku[kyoku_index].mentsu_count_minkan++;

			// ヒストグラム加算
			tk->anko_hist[tk->kyoku[kyoku_index].agari_men_hai[tmp_i]]++;

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 04:符計算
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_fu(MJSTkinfo *tk, int kyoku_index){

	// 符計算
	// https://kinmaweb.jp/mahjong-rule/fukeisan

	// -----------------------------
	// 雀頭の符計算
	// -----------------------------

	// 雀頭の符
	if (tk->kyoku[kyoku_index].agari_ata_19zi == 2){

		// 雀頭の符
		tk->kyoku[kyoku_index].atamaFu = 2;

	}else{

		// 雀頭の符
		tk->kyoku[kyoku_index].atamaFu = 0;

	}

	// -----------------------------
	// 面子の符計算
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

				// デバグ用
				tk->kyoku[kyoku_index].agari_men_Fu[tmp_i] = 99;

		}

	}

	// -----------------------------
	// 面前符
	// -----------------------------

	if(tk->kyoku[kyoku_index].menzen_flg      == true  && 
       tk->kyoku[kyoku_index].tsumo_agari_flg == false ){
		tk->kyoku[kyoku_index].menzenFu=10;
	}else{
		tk->kyoku[kyoku_index].menzenFu=0;
	}

	// -----------------------------
	// 待ち符計算
	// -----------------------------
	if( tk->kyoku[kyoku_index].agari_machi_stat == TANKI || 
	    tk->kyoku[kyoku_index].agari_machi_stat == PENCHAN || 
	    tk->kyoku[kyoku_index].agari_machi_stat == KANCHAN ){

		tk->kyoku[kyoku_index].machiFu=2;

	}else{
		tk->kyoku[kyoku_index].machiFu=0;
	}

	// -----------------------------
	// 自摸符
	// -----------------------------

	if(tk->kyoku[kyoku_index].tsumo_agari_flg == true){
		tk->kyoku[kyoku_index].tsumoFu=2;
	}else{
		tk->kyoku[kyoku_index].tsumoFu=0;
	}

	// -----------------------------
	// 符の合計
	// -----------------------------

	tk->kyoku[kyoku_index].basefu = 20;

	// 符の合計
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
	// 符の切り上げ
	// -----------------------------

	if(tk->kyoku[kyoku_index].totalFu % 10 == 0){
		tk->kyoku[kyoku_index].scoreFu = tk->kyoku[kyoku_index].totalFu;
	}else{
		tk->kyoku[kyoku_index].scoreFu = tk->kyoku[kyoku_index].totalFu+10-(tk->kyoku[kyoku_index].totalFu % 10);
	}

}

/* ---------------------------------------------------------------------------------------------- */
// 05:役確認
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_yaku(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// 初期化
	// -----------------------------
	tk->kyoku[kyoku_index].yakucount     = 0;
	tk->kyoku[kyoku_index].yakuman_count = 0;
	tk->kyoku[kyoku_index].agari_ply_han = 0;
	tk->kyoku[kyoku_index].agari_ply_mangan_count = 0;
	tk->kyoku[kyoku_index].yakuman_agari_ply_bai=0;

	// -----------------------------
	// フラグ初期化
	// -----------------------------

	// 役満
	for(int tmp_i = 0; tmp_i < YAKUMAN_SHUBETSU_MAX; tmp_i++){
		tk->kyoku[kyoku_index].yakuman_flg[tmp_i]=false;
	}

	// 通常役
	for(int tmp_i = 0; tmp_i < YAKU_SHUBETSU_MAX; tmp_i++){
		tk->kyoku[kyoku_index].yaku_flg[tmp_i]=false;
	}

	// -----------------------------
	// 役確認
	// -----------------------------

	ChkYakuRiich(tk,kyoku_index);             // リーチ
	ChkYakuChitoiIpeko(tk,kyoku_index);       // 七対子、一盃口、二盃口 
	ChkYakuChinItsu_HonItsu(tk,kyoku_index);  // 一色
	ChkYakuAnko(tk,kyoku_index);              // 暗刻
	ChkYakuChanta(tk,kyoku_index);            // チャンタ
	ChkYakuSanshoku(tk,kyoku_index);          // 三色
	ChkYakuItsu(tk,kyoku_index);              // 一通
	ChkYakuPinfu(tk,kyoku_index);             // 平和
	ChkYakuTanyao(tk,kyoku_index);            // タンヤオ
	ChkYakuYakuhai(tk,kyoku_index);           // 役牌
	ChkYakuDaisangen(tk,kyoku_index);         // 大三元・小三元
	ChkYakuDaisushi(tk,kyoku_index);          // 大四喜和・小四喜和
	ChkYakuKokushi(tk,kyoku_index);           // 国士無双
	ChkYakuChuren(tk,kyoku_index);            // 九連宝燈
	ChkYakuTenho(tk,kyoku_index);             // 天和
	ChkYakuEtc(tk,kyoku_index);               // その他

	// -----------------------------
	// 役テーブル設定
	// -----------------------------

		// 役満確認
		for(int tmp_i = 0; tmp_i < YAKUMAN_SHUBETSU_MAX; tmp_i++){

			// 役設定有無
			if(tk->kyoku[kyoku_index].yakuman_flg[tmp_i] == true){

				// 役テーブル設定
				// wsprintf(tk->kyoku[kyoku_index].yakuname[tk->kyoku[kyoku_index].yakuman_count], "%s … 役満　　", yakumanname[tmp_i],1);
				tk->kyoku[kyoku_index].yakuman_count++;

				// 役満倍の設定
				tk->kyoku[tk->kyoku_index].yakuman_bai[tmp_i] = yakuman_bai[tmp_i];

				// 役満合計倍数カウント
				tk->kyoku[kyoku_index].yakuman_agari_ply_bai = tk->kyoku[kyoku_index].yakuman_agari_ply_bai + yakuman_bai[tmp_i];

			}

		}

	// 通常役
	if( tk->kyoku[kyoku_index].yakuman_count == 0 ){

		// 通常役確認
		for(int tmp_i = 0; tmp_i < YAKU_SHUBETSU_MAX; tmp_i++){

			// 役設定有無
			if(tk->kyoku[kyoku_index].yaku_flg[tmp_i] == true){

				// 役テーブル設定
				// wsprintf(tk->kyoku[kyoku_index].yakuname[tk->kyoku[kyoku_index].yakucount], "%s … %d翻", yakuname[tmp_i], yakuhan[tmp_i]);
				tk->kyoku[kyoku_index].yakucount++;

				// 役翻設定
				tk->kyoku[tk->kyoku_index].yaku_han[tmp_i] = yakuhan[tmp_i];

				// 合計翻数のカウント
				tk->kyoku[kyoku_index].agari_ply_han = tk->kyoku[kyoku_index].agari_ply_han + yakuhan[tmp_i];

			}
		}

		// 満貫以上確認
		if (tk->kyoku[kyoku_index].agari_ply_han == 5){
			// 満貫
			tk->kyoku[kyoku_index].agari_ply_mangan_count = 1;
		}else if(tk->kyoku[kyoku_index].agari_ply_han >=6 && tk->kyoku[kyoku_index].agari_ply_han <= 7){
			// 跳満
			tk->kyoku[kyoku_index].agari_ply_mangan_count = 2;
		}else if(tk->kyoku[kyoku_index].agari_ply_han >=8 && tk->kyoku[kyoku_index].agari_ply_han <= 10){
			// 倍満
			tk->kyoku[kyoku_index].agari_ply_mangan_count = 3;
		}else if(tk->kyoku[kyoku_index].agari_ply_han >=11 && tk->kyoku[kyoku_index].agari_ply_han <= 12){
			// 三倍満
			tk->kyoku[kyoku_index].agari_ply_mangan_count = 4;
		}else if(tk->kyoku[kyoku_index].agari_ply_han >=13){
			// 数え役満
			tk->kyoku[kyoku_index].agari_ply_mangan_count = 5;
		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 06:得点計算・メイン
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::chk_score(MJSTkinfo *tk, int kyoku_index){

	Chk_kyokuscore(tk, kyoku_index);
	Chk_totalscore(tk, kyoku_index);

}

/* ---------------------------------------------------------------------------------------------- */
// 06:得点計算・サブ
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::Chk_kyokuscore(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------
	// 得点 - 和了得点
	// -----------------------------

	// 自摸和了であるかどうか
	if (tk->kyoku[kyoku_index].tsumo_agari_flg == true){

		// -----------------------------
		// ツモ和了・親
		// -----------------------------
		if (tk->kyoku[kyoku_index].agari_ply_oya_flg == true){

			// 役満の場合
			if( tk->kyoku[kyoku_index].yakuman_count > 0 ){

					// 得点設定
					tk->kyoku[kyoku_index].agari_ply_ron       = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 16000*tk->kyoku[kyoku_index].yakuman_agari_ply_bai;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

			// 通常役の場合
			}else{

				// 満貫以上
				if(tk->kyoku[kyoku_index].agari_ply_mangan_count > 0){

					// 得点設定
					tk->kyoku[kyoku_index].agari_ply_ron       = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_mangan_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_mangan_count-1];
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

				// 満貫未満
				}else{
					// 形式確認
					if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){
						// 得点設定(七対子)
						tk->kyoku[kyoku_index].agari_ply_ron       = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_chitoi_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_han-1];
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}else{
						// 得点設定(通常)
						tk->kyoku[kyoku_index].agari_ply_ron       = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_han-1][(tk->kyoku[kyoku_index].scoreFu-20)/10];
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}
				}
			}

		// -----------------------------
		// ツモ和了・子
		// -----------------------------
		}else{

			// 役満の場合
			if( tk->kyoku[kyoku_index].yakuman_count > 0 ){

					// 得点設定
					tk->kyoku[kyoku_index].agari_ply_ron       = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 16000*tk->kyoku[kyoku_index].yakuman_agari_ply_bai;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 8000*tk->kyoku[kyoku_index].yakuman_agari_ply_bai;

			// 通常役の場合
			}else{

				// 満貫以上
				if(tk->kyoku[kyoku_index].agari_ply_mangan_count > 0){

					// 得点設定
					tk->kyoku[kyoku_index].agari_ply_ron       = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_mangan_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_mangan_count-1];
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = score_mangan_tsumo_ko[tk->kyoku[kyoku_index].agari_ply_mangan_count-1];

				// 満貫未満
				}else{
					// 形式確認
					if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){
						// 得点設定(七対子)
						tk->kyoku[kyoku_index].agari_ply_ron       = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_chitoi_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_han-1];
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = score_chitoi_tsumo_ko[tk->kyoku[kyoku_index].agari_ply_han-1];
					}else{
						// 得点設定(通常)
						tk->kyoku[kyoku_index].agari_ply_ron       = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = score_tsumo_oya[tk->kyoku[kyoku_index].agari_ply_han-1][(tk->kyoku[kyoku_index].scoreFu-20)/10];
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = score_tsumo_ko[tk->kyoku[kyoku_index].agari_ply_han-1][(tk->kyoku[kyoku_index].scoreFu-20)/10];
					}
				}
			}
		}

	}else{

		// -----------------------------
		// ロン和了・親
		// -----------------------------
		if (tk->kyoku[kyoku_index].agari_ply_oya_flg == true){

			// 役満の場合
			if( tk->kyoku[kyoku_index].yakuman_count > 0 ){

					// 得点設定
					tk->kyoku[kyoku_index].agari_ply_ron       = 48000*tk->kyoku[kyoku_index].yakuman_agari_ply_bai;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

			// 通常役の場合
			}else{

				// 満貫以上
				if(tk->kyoku[kyoku_index].agari_ply_mangan_count > 0){

					// 得点設定
					tk->kyoku[kyoku_index].agari_ply_ron       = score_mangan_ron_oya[tk->kyoku[kyoku_index].agari_ply_mangan_count-1];
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

				// 満貫未満
				}else{
					// 形式確認
					if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){
						// 得点設定(七対子)
						tk->kyoku[kyoku_index].agari_ply_ron       = score_chitoi_ron_oya[tk->kyoku[kyoku_index].agari_ply_han-1];
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}else{
						// 得点設定(通常)
						tk->kyoku[kyoku_index].agari_ply_ron       = score_ron_oya[tk->kyoku[kyoku_index].agari_ply_han-1][(tk->kyoku[kyoku_index].scoreFu-20)/10];
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}
				}
			}

		// -----------------------------
		// ロン和了・子
		// -----------------------------
		}else{

			// 役満の場合
			if( tk->kyoku[kyoku_index].yakuman_count > 0 ){

					// 得点設定
					tk->kyoku[kyoku_index].agari_ply_ron       = 32000*tk->kyoku[kyoku_index].yakuman_agari_ply_bai;
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

			// 通常役の場合
			}else{

				// 満貫以上
				if(tk->kyoku[kyoku_index].agari_ply_mangan_count > 0){

					// 得点設定(満貫)
					tk->kyoku[kyoku_index].agari_ply_ron       = score_mangan_ron_ko[tk->kyoku[kyoku_index].agari_ply_mangan_count-1];
					tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
					tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;

				// 満貫未満
				}else{
					// 形式確認
					if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){
						// 得点設定(七対子)
						tk->kyoku[kyoku_index].agari_ply_ron       = score_chitoi_tsumo_ko[tk->kyoku[kyoku_index].agari_ply_han-1];
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}else{
						// 得点設定(通常)
						tk->kyoku[kyoku_index].agari_ply_ron       = score_ron_ko[tk->kyoku[kyoku_index].agari_ply_han-1][(tk->kyoku[kyoku_index].scoreFu-20)/10];
						tk->kyoku[kyoku_index].agari_ply_tsumo_oya = 0;
						tk->kyoku[kyoku_index].agari_ply_tsumo_ko  = 0;
					}
				}
			}

		}

	}

	// -----------------------------
	// 得点 - プレーヤーごとの清算
	// -----------------------------

	// 初期化
	tk->kyoku[kyoku_index].kyoku_score[0] = 0;
	tk->kyoku[kyoku_index].kyoku_score[1] = 0;
	tk->kyoku[kyoku_index].kyoku_score[2] = 0;
	tk->kyoku[kyoku_index].kyoku_score[3] = 0;

	// 自摸ロン確認
	if (tk->kyoku[kyoku_index].tsumo_agari_flg == true){

		if (tk->kyoku[kyoku_index].agari_ply_oya_flg == true){

			// ツモ和了・親
			for(int tmp_i = 0; tmp_i < 4; tmp_i++){
				if(tmp_i == tk->kyoku[kyoku_index].agari_ply_num){
					tk->kyoku[kyoku_index].kyoku_score[tmp_i] = tk->kyoku[kyoku_index].agari_ply_tsumo_oya*3;
				}else{
					tk->kyoku[kyoku_index].kyoku_score[tmp_i] = tk->kyoku[kyoku_index].agari_ply_tsumo_oya*-1;
				}
			}

		}else{

			// ツモ和了・子
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

			// ロン和了
			tk->kyoku[kyoku_index].kyoku_score[tk->kyoku[kyoku_index].agari_ply_num] = tk->kyoku[kyoku_index].agari_ply_ron;
			tk->kyoku[kyoku_index].kyoku_score[tk->kyoku[kyoku_index].furikomi_ply_num]  = tk->kyoku[kyoku_index].agari_ply_ron*(-1);

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 06:得点計算・サブ
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::Chk_totalscore(MJSTkinfo *tk, int kyoku_index){

	// 局終了得点の設定
/*	for(int tmp_i = 0; tmp_i < PLAYER_MAX; tmp_i++){
		tk->kyoku[kyoku_index].ply_kyoku_end_score[tmp_i] = tk->kyoku[kyoku_index].ply_kyoku_start_score[tmp_i] 
		                                                  + tk->kyoku[kyoku_index].kyoku_score[tmp_i];
	}*/

}

/* ---------------------------------------------------------------------------------------------- */
// ドラ枚数の確認
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::Chk_tehai_dora_count(MJSTkinfo *tk, int kyoku_index, int rinshan, bool ura_chk){

	// -----------------------------
	// 初期化
	// -----------------------------

	// ドラ初期化
	tk->kyoku[kyoku_index].agari_dora_count = 0;
	tk->kyoku[kyoku_index].agari_uradora_count = 0;

	// デバグ用
	rinshan=0;

	// 作業用変数定義
	int dora_hai;

	// 実ドラ牌算出
	dora_hai=Get_dora_hai(tk->kyoku[kyoku_index].dora[0]);

	// -----------------------------
	// ドラ枚数カウント・頭
	// -----------------------------

	if (tk->kyoku[kyoku_index].agari_ata_hai == dora_hai){

		// ドラ加算
		tk->kyoku[kyoku_index].agari_dora_count = tk->kyoku[kyoku_index].agari_dora_count + 2 ;

	}

	// -----------------------------
	// ドラ枚数カウント・面子
	// -----------------------------

	// ドラカウント
	for(int tmp_i = 0; tmp_i < 4; tmp_i++){

		// ドラカウント
		if((tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKO || tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINKO) && 
			     (tk->kyoku[kyoku_index].agari_men_hai[tmp_i]    == dora_hai )){

				// ドラ加算
				tk->kyoku[kyoku_index].agari_dora_count = tk->kyoku[kyoku_index].agari_dora_count + 3 ;

		}else if((tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == ANKAN || tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINKAN) && 
			     (tk->kyoku[kyoku_index].agari_men_hai[tmp_i]    == dora_hai )){

				// ドラ加算
				tk->kyoku[kyoku_index].agari_dora_count = tk->kyoku[kyoku_index].agari_dora_count + 4 ;

		}else if((tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == SHUNTSU || tk->kyoku[kyoku_index].agari_men_stat[tmp_i] == MINSHUN) && 
			     (tk->kyoku[kyoku_index].agari_men_hai[tmp_i]    == dora_hai || 
			      tk->kyoku[kyoku_index].agari_men_hai[tmp_i] +1 == dora_hai || 
			      tk->kyoku[kyoku_index].agari_men_hai[tmp_i] +2 == dora_hai )){

				// ドラ加算
				tk->kyoku[kyoku_index].agari_dora_count ++;

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// ドラ表示牌→ドラ牌の変換
/* ---------------------------------------------------------------------------------------------- */
int MJSOldScore::Get_dora_hai(int dora_hai){

	// ドラ表示牌→ドラ牌の変換
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
	// デバグ用
	}else if(dora_hai < 1 || dora_hai > 37){
		return 1;
	}else{
		return dora_hai+1;
	}

}

/* ---------------------------------------------------------------------------------------------- */
// リーチ系
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuRiich(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 01: リーチ
	// -----------------------------------------------------------------------

	if (tk->kyoku[kyoku_index].riichi_flg == true){
		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[RIICH] = true;
	}

	// -----------------------------------------------------------------------
	// 02: ダブルリーチ
	// -----------------------------------------------------------------------

	if (tk->kyoku[kyoku_index].w_riichi_flg == true){
		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[RIICH]  = false;
		tk->kyoku[kyoku_index].yaku_flg[WRIICH] = true;
	}

	// -----------------------------------------------------------------------
	// 03: 一発
	// -----------------------------------------------------------------------

	if (tk->kyoku[kyoku_index].ippatsu_riichi_flg == true){
		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[IPPATSU] = true;
	}

}

/* ---------------------------------------------------------------------------------------------- */
// 七対子、一盃口、二盃口 
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuChitoiIpeko(MJSTkinfo *tk, int kyoku_index){

	/* ----------------------------------------------------------------------- */
	// 一盃口・二盃口
	/* ----------------------------------------------------------------------- */
	for(int tmp_i = 1; tmp_i < 28; tmp_i++){

		// 二盃口有効化
		if ( tk->shuntsu_hist[tmp_i] > 1 && 
		     tk->kyoku[kyoku_index].menzen_flg == true &&
			 tk->kyoku[kyoku_index].yaku_flg[IPEKO] == true){

			// 二盃口有効化
			tk->kyoku[kyoku_index].yaku_flg[IPEKO] = false;
			tk->kyoku[kyoku_index].yaku_flg[RYANPEKO] = true;
			break;

		// 一盃口の有効化確認
		}else if ( tk->shuntsu_hist[tmp_i] > 1 && tk->kyoku[kyoku_index].menzen_flg == true ){
			// 役flg有効化
			tk->kyoku[kyoku_index].yaku_flg[IPEKO] = true;

		// 七対子の有効化確認
		}else if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){

			// 役flg有効化
			tk->kyoku[kyoku_index].yaku_flg[CHITOI] = true;

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 混一系
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuChinItsu_HonItsu(MJSTkinfo *tk, int kyoku_index){

	// 通常形式
	if(tk->kyoku[kyoku_index].agari_stat == AGARI_NORMAL){

		// -----------------------------------------------------------------------
		// 04: 清一色
		// -----------------------------------------------------------------------
		if ( tk->kyoku[kyoku_index].mentsu_count_manzu == 5 ||
		     tk->kyoku[kyoku_index].mentsu_count_pinzu == 5 ||
		     tk->kyoku[kyoku_index].mentsu_count_souzu == 5 ){

			// 役flg有効化
			tk->kyoku[kyoku_index].yaku_flg[CHINISO]=true;

		// -----------------------------------------------------------------------
		// 10: 字一色
		// -----------------------------------------------------------------------
		}else if( tk->kyoku[kyoku_index].mentsu_count_zihai == 5){

			// 役flg有効化
			tk->kyoku[kyoku_index].yakuman_flg[TSUISO]=true;

		// -----------------------------------------------------------------------
		// 04: 混一色
		// -----------------------------------------------------------------------
		}else if( tk->kyoku[kyoku_index].mentsu_count_manzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 5 ||
		          tk->kyoku[kyoku_index].mentsu_count_pinzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 5 ||
		          tk->kyoku[kyoku_index].mentsu_count_souzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 5 ){

			// 役flg有効化
			tk->kyoku[kyoku_index].yaku_flg[HONISO]=true;

		// -----------------------------------------------------------------------
		// 12: 緑一色
		// -----------------------------------------------------------------------

		}

	// 七対子形式
	}else if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){

		// -----------------------------------------------------------------------
		// 04: 清一色
		// -----------------------------------------------------------------------
		if ( tk->kyoku[kyoku_index].mentsu_count_manzu == 7 ||
		     tk->kyoku[kyoku_index].mentsu_count_pinzu == 7 ||
		     tk->kyoku[kyoku_index].mentsu_count_souzu == 7 ){

			// 役flg有効化
			tk->kyoku[kyoku_index].yaku_flg[CHINISO]=true;

		// -----------------------------------------------------------------------
		// 10: 字一色
		// -----------------------------------------------------------------------
		}else if( tk->kyoku[kyoku_index].mentsu_count_zihai == 7){

			// 役flg有効化
			tk->kyoku[kyoku_index].yakuman_flg[TSUISO]=true;

		// -----------------------------------------------------------------------
		// 04: 混一色
		// -----------------------------------------------------------------------
		}else if( tk->kyoku[kyoku_index].mentsu_count_manzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 7 ||
		          tk->kyoku[kyoku_index].mentsu_count_pinzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 7 ||
		          tk->kyoku[kyoku_index].mentsu_count_souzu + tk->kyoku[kyoku_index].mentsu_count_zihai == 7 ){

			// 役flg有効化
			tk->kyoku[kyoku_index].yaku_flg[HONISO]=true;
		}
	}


}

/* ---------------------------------------------------------------------------------------------- */
// 暗刻系
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuAnko(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 役満14: 四槓子
	// -----------------------------------------------------------------------
	if ( tk->kyoku[kyoku_index].mentsu_count_ankan  +
	     tk->kyoku[kyoku_index].mentsu_count_minkan == 4 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[SUKANTSU] = true;

	}

	// -----------------------------------------------------------------------
	// 13: 三槓子
	// -----------------------------------------------------------------------
	if ( tk->kyoku[kyoku_index].mentsu_count_ankan  +
	     tk->kyoku[kyoku_index].mentsu_count_minkan == 3 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[SANKANTSU] = true;

	}

	// -----------------------------------------------------------------------
	// 役満15: 四暗刻
	// -----------------------------------------------------------------------
	if ( tk->kyoku[kyoku_index].mentsu_count_anko  +
	     tk->kyoku[kyoku_index].mentsu_count_ankan == 4 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[SUANKO]=true;

	}

	// -----------------------------------------------------------------------
	// 14: 三暗刻
	// -----------------------------------------------------------------------
	if ( tk->kyoku[kyoku_index].mentsu_count_anko  +
	     tk->kyoku[kyoku_index].mentsu_count_ankan == 3 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[SANANKO] = true;

	}

	// -----------------------------------------------------------------------
	// 15: 対々和
	// -----------------------------------------------------------------------
	if ( tk->kyoku[kyoku_index].mentsu_count_anko  +
	     tk->kyoku[kyoku_index].mentsu_count_minko +
	     tk->kyoku[kyoku_index].mentsu_count_ankan +
	     tk->kyoku[kyoku_index].mentsu_count_minkan == 4 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[TOITOI] = true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 純全帯
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuChanta(MJSTkinfo *tk, int kyoku_index){


	// 通常形式
	if(tk->kyoku[kyoku_index].agari_stat == AGARI_NORMAL){

		/* ----------------------------------------------------------------------- */
		// チャンタ系(通常役)
		/* ----------------------------------------------------------------------- */
		if (tk->kyoku[kyoku_index].mentsu_count_19zi == 5){
			// 全てアンコの場合
			if ( tk->kyoku[kyoku_index].mentsu_count_anko  +
			     tk->kyoku[kyoku_index].mentsu_count_minko +
			     tk->kyoku[kyoku_index].mentsu_count_ankan +
			     tk->kyoku[kyoku_index].mentsu_count_minkan == 4 ){
				// 字牌数確認
				if(tk->kyoku[kyoku_index].mentsu_count_zihai == 0){
					// 役flg有効化
					tk->kyoku[kyoku_index].yaku_flg[JUNCHAN] = true;
				}else{
					// 役flg有効化
					tk->kyoku[kyoku_index].yaku_flg[CHANTA] = true;
				}
			// 順子がある場合
			}else{
				// 字牌数確認
				if(tk->kyoku[kyoku_index].mentsu_count_zihai == 0){
					// 役flg有効化
					tk->kyoku[kyoku_index].yakuman_flg[CHINROTO]=true;
				}else{
					// 役flg有効化
					tk->kyoku[kyoku_index].yaku_flg[HONROTO] = true;
				}
			}
		}

	// 七対子形式
	}else if(tk->kyoku[kyoku_index].agari_stat == AGARI_CHITOI){

		/* ----------------------------------------------------------------------- */
		// チャンタ系(七対子)
		/* ----------------------------------------------------------------------- */
		if (tk->kyoku[kyoku_index].mentsu_count_19zi == 7){
			// 役flg有効化
			tk->kyoku[kyoku_index].yaku_flg[HONROTO] = true;
		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 三色系
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuSanshoku(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 11: 三色同刻
	// 12: 三色同順
	// -----------------------------------------------------------------------
	for(int i = 0; i < 9; i++){

		// 三色同刻確認
		if ( tk->shuntsu_hist[1+i]  > 0 &&
		     tk->shuntsu_hist[11+i] > 0 &&
		     tk->shuntsu_hist[21+i] > 0 ){

			// 役flg有効化
			tk->kyoku[kyoku_index].yaku_flg[SANDOJUN] = true;

		}

		// 三色同刻確認
		if ( tk->anko_hist[1+i]  > 0 &&
		     tk->anko_hist[11+i] > 0 &&
		     tk->anko_hist[21+i] > 0 ){

			// 役flg有効化
			tk->kyoku[kyoku_index].yaku_flg[SANDOKOU] = true;

		}

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 一通系
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuItsu(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 10: 一気通貫
	// -----------------------------------------------------------------------
	for(int i = 0; i < 3; i++){
		if ( tk->shuntsu_hist[1+10*i] > 0 &&
		     tk->shuntsu_hist[4+10*i] > 0 &&
		     tk->shuntsu_hist[7+10*i] > 0 ){

			// 役flg有効化
			tk->kyoku[kyoku_index].yaku_flg[ITSU] = true;

		}
	}

}

/* ---------------------------------------------------------------------------------------------- */
// 平和系
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuPinfu(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 10: 平和
	// -----------------------------------------------------------------------

	// 鳴き確認
	if(tk->kyoku[kyoku_index].menzen_flg == false ){
		return ;
	}

	// 順子数の確認
	if( (tk->kyoku[kyoku_index].mentsu_count_shuntsu != 4 ) && 
	    (tk->kyoku[kyoku_index].mentsu_count_shuntsu != 3 || tk->kyoku[kyoku_index].mentsu_count_minshun != 1 )
	){
		return ;
	}

	// 雀頭の役牌確認→agari_ata_19zi=2の場合は平和にならない
	if( tk->kyoku[kyoku_index].agari_ata_19zi == 2){
		return ;
	}

	// 両面の確認
	if(tk->kyoku[kyoku_index].agari_machi_stat != RYANMEN ){
		return ;
	}

	// 役flg有効化
	tk->kyoku[kyoku_index].yaku_flg[PINFU] = true;

	// 平和は固定で20符
	tk->kyoku[kyoku_index].totalFu = 20;
	tk->kyoku[kyoku_index].scoreFu = 20;

}

/* ---------------------------------------------------------------------------------------------- */
// タンヤオ系
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuTanyao(MJSTkinfo *tk, int kyoku_index){

	/* ----------------------------------------------------------------------- */
	// タンヤオ
	/* ----------------------------------------------------------------------- */
	if (tk->kyoku[kyoku_index].mentsu_count_chunchan == 5){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[TANYAO] = true;

	}
}


/* ---------------------------------------------------------------------------------------------- */
// 役牌系
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuYakuhai(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 21: 場風牌
	// -----------------------------------------------------------------------
	if ( tk->anko_hist[tk->agari_ply_bakaze] > 0 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[BAKAZE] = true;

	}

	/* ----------------------------------------------------------------------- */
	// 22: 自風牌
	/* ----------------------------------------------------------------------- */
	if ( tk->anko_hist[tk->agari_ply_zikaze] > 0 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[ZIKAZE] = true;

	}

	// -----------------------------------------------------------------------
	// 23: 三元牌白
	// -----------------------------------------------------------------------
	if ( tk->anko_hist[HAKUNUM] > 0 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[YAKUHAIHAKU] = true;

	}

	// -----------------------------------------------------------------------
	// 24: 三元牌発
	// -----------------------------------------------------------------------
	if ( tk->anko_hist[HATSUNUM] > 0 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[YAKUHAIHATSU] = true;

	}

	// -----------------------------------------------------------------------
	// 25: 三元牌中
	// -----------------------------------------------------------------------
	if ( tk->anko_hist[CHUNNUM] > 0){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[YAKUHAICHUN] = true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 大三元・小三元
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuDaisangen(MJSTkinfo *tk, int kyoku_index){

	/* ----------------------------------------------------------------------- */
	// 小三元・白(HAKUNUM)アタマ
	/* ----------------------------------------------------------------------- */
	if (( tk->kyoku[kyoku_index].agari_ata_hai == HAKUNUM ) &&
		( tk->anko_hist[HATSUNUM] > 0 ) &&
		( tk->anko_hist[CHUNNUM]  > 0 ) ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[SHOSANGEN]=true;
	}

	/* ----------------------------------------------------------------------- */
	// 小三元・発(HAKUNUM)アタマ
	/* ----------------------------------------------------------------------- */
	if (( tk->kyoku[kyoku_index].agari_ata_hai == HATSUNUM ) &&
		( tk->anko_hist[HAKUNUM] > 0 ) &&
		( tk->anko_hist[CHUNNUM]  > 0 ) ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[SHOSANGEN]=true;
	}

	/* ----------------------------------------------------------------------- */
	// 小三元・中(HAKUNUM)アタマ
	/* ----------------------------------------------------------------------- */
	if (( tk->kyoku[kyoku_index].agari_ata_hai == CHUNNUM ) &&
		( tk->anko_hist[HAKUNUM]   > 0 ) &&
		( tk->anko_hist[HATSUNUM]  > 0 ) ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[SHOSANGEN]=true;
	}

	/* ----------------------------------------------------------------------- */
	// 大三元
	/* ----------------------------------------------------------------------- */
	if (( tk->anko_hist[HAKUNUM]  > 0 ) &&
		( tk->anko_hist[HATSUNUM] > 0 ) &&
		( tk->anko_hist[CHUNNUM]  > 0 ) ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[DAISANGEN]=true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 大四喜和・小四喜和
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuDaisushi(MJSTkinfo *tk, int kyoku_index){

	/* ----------------------------------------------------------------------- */
	// 小四喜和・東アタマ
	/* ----------------------------------------------------------------------- */

	if (( tk->kyoku[kyoku_index].agari_ata_hai == TONNUM ) &&
		( tk->anko_hist[NANNUM] > 0 ) &&
		( tk->anko_hist[SHANUM] > 0 ) &&
		( tk->anko_hist[PEINUM] > 0 ) ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[SHOSUSHI]=true;

	}

	/* ----------------------------------------------------------------------- */
	// 小四喜和・南アタマ
	/* ----------------------------------------------------------------------- */

	if (( tk->kyoku[kyoku_index].agari_ata_hai == NANNUM ) &&
		( tk->anko_hist[TONNUM] > 0 ) &&
		( tk->anko_hist[SHANUM] > 0 ) &&
		( tk->anko_hist[PEINUM] > 0 ) ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[SHOSUSHI]=true;

	}

	/* ----------------------------------------------------------------------- */
	// 小四喜和・西アタマ
	/* ----------------------------------------------------------------------- */

	if (( tk->kyoku[kyoku_index].agari_ata_hai == SHANUM ) &&
		( tk->anko_hist[TONNUM] > 0 ) &&
		( tk->anko_hist[NANNUM] > 0 ) &&
		( tk->anko_hist[PEINUM] > 0 ) ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[SHOSUSHI]=true;

	}

	/* ----------------------------------------------------------------------- */
	// 小四喜和・北アタマ
	/* ----------------------------------------------------------------------- */

	if (( tk->kyoku[kyoku_index].agari_ata_hai == PEINUM ) &&
		( tk->anko_hist[TONNUM] > 0 ) &&
		( tk->anko_hist[NANNUM] > 0 ) &&
		( tk->anko_hist[SHANUM] > 0 ) ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[SHOSUSHI]=true;

	}

	// -----------------------------------------------------------------------
	// 07: 大四喜和
	// -----------------------------------------------------------------------

	if (( tk->anko_hist[TONNUM] > 0 ) &&
		( tk->anko_hist[NANNUM] > 0 ) &&
		( tk->anko_hist[SHANUM] > 0 ) &&
		( tk->anko_hist[PEINUM] > 0 ) ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[DAISUSHI]=true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 国士無双
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuKokushi(MJSTkinfo *tk, int kyoku_index){

	// 手配形式が国士であるのか？
	if(tk->kyoku[kyoku_index].agari_stat == AGARI_KOKUSHI){
		//13面確認
		if ( tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][tk->kyoku[kyoku_index].agari_hai] > 0){
			// 役flg有効化
			tk->kyoku[kyoku_index].yakuman_flg[KOKUSHI13MEN] = true;
		}else{
			// 役flg有効化
			tk->kyoku[kyoku_index].yakuman_flg[KOKUSHI] = true;
		}
	}

}

/* ---------------------------------------------------------------------------------------------- */
// 九連宝燈
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuChuren(MJSTkinfo *tk, int kyoku_index){

	// 変数設定
	bool agari_flg;

	/* ----------------------------------------------------------------------- */
	// 03: 九連宝燈・萬子
	/* ----------------------------------------------------------------------- */

	// 和了フラグ初期化
	agari_flg = true;

	// 雀頭と面子4枚がすべて同一の索子であること
	if ( tk->kyoku[kyoku_index].mentsu_count_manzu != 5){
		agari_flg = false ;
	}

	// 一牌と九牌が3枚以上あること
    if ( (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][MAN1NUM] < 3) || 
	     (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][MAN9NUM] < 3) ){
		agari_flg = false ;
	}

	// 一牌から九牌まで全て揃っていること
	for (int tmp_i = 1; tmp_i < 10; tmp_i++) {
        if (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][tmp_i] == 0){
			agari_flg = false ;
		}
    }

	// 和了確認
	if (agari_flg == true){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[CHUREN]=true;

	}

	/* ----------------------------------------------------------------------- */
	// 03: 九連宝燈・筒子
	/* ----------------------------------------------------------------------- */

	// 和了フラグ初期化
	agari_flg = true;

	// 雀頭と面子4枚がすべて同一の索子であること
	if ( tk->kyoku[kyoku_index].mentsu_count_pinzu != 5){
		agari_flg = false ;
	}

	// 一牌と九牌が3枚以上あること
    if ( (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][PIN1NUM] < 3) || 
	     (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][PIN9NUM] < 3) ){
		agari_flg = false ;
	}

	// 一牌から九牌まで全て揃っていること
	for (int tmp_i = 11; tmp_i < 20; tmp_i++) {
        if (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][tmp_i] == 0){
			agari_flg = false ;
		}
    }

	// 和了確認
	if (agari_flg == true){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[CHUREN]=true;

	}

	/* ----------------------------------------------------------------------- */
	// 03: 九連宝燈・索子
	/* ----------------------------------------------------------------------- */

	// 和了フラグ初期化
	agari_flg = true;

	// 雀頭と面子4枚がすべて同一の索子であること
	if ( tk->kyoku[kyoku_index].mentsu_count_souzu != 5){
		agari_flg = false ;
	}

	// 一牌と九牌が3枚以上あること
    if ( (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][SOU1NUM] < 3) || 
	     (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][SOU9NUM] < 3) ){

		// 和了フラグ無効化
		agari_flg = false ;
	}

	// 一牌から九牌まで全て揃っていること
	for (int tmp_i = 21; tmp_i < 30; tmp_i++) {
        if (tk->ply_act_tehai[tk->kyoku[kyoku_index].agari_ply_num][tmp_i] == 0){
			agari_flg = false ;
		}
    }

	// 和了確認
	if (agari_flg == true){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[CHUREN]=true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 天和
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuTenho(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 役満01: 天和
	// -----------------------------------------------------------------------
	if(tk->kyoku[kyoku_index].agari_ply_tsumo_count == 1 && tk->kyoku[kyoku_index].tsumo_agari_flg == true){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[TENHO]=true;

	}

	// -----------------------------------------------------------------------
	// 役満02: 地和
	// -----------------------------------------------------------------------
	if(tk->kyoku[kyoku_index].agari_ply_tsumo_count == 0 && tk->kyoku[kyoku_index].tsumo_agari_flg == false){

		// 役flg有効化
		tk->kyoku[kyoku_index].yakuman_flg[CHIHO]=true;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// その他処理
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::ChkYakuEtc(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------------------
	// 29: 門前清自摸和
	// -----------------------------------------------------------------------

	if(tk->kyoku[kyoku_index].tsumo_agari_flg == true && 
	   tk->kyoku[kyoku_index].menzen_flg      == true ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[TSUMO] = true;

	}

	// -----------------------------
	// 31: ドラ
	// -----------------------------
	if( tk->kyoku[kyoku_index].agari_dora_count > 0 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[DORA] = true;

		// 翻数設定
		yakuhan[DORA] = tk->kyoku[kyoku_index].agari_dora_count;

	}

	// -----------------------------
	// 33: 赤牌
	// -----------------------------
	if(tk->kyoku[kyoku_index].agari_aka_count[0] > 0 ||
	   tk->kyoku[kyoku_index].agari_aka_count[1] > 0 ||
	   tk->kyoku[kyoku_index].agari_aka_count[2] > 0 ){

		// 役flg有効化
		tk->kyoku[kyoku_index].yaku_flg[AKAHAI] = true;

		// 翻数設定
		yakuhan[AKAHAI] = tk->kyoku[kyoku_index].agari_aka_count[0] + 
		                  tk->kyoku[kyoku_index].agari_aka_count[1] +
		                  tk->kyoku[kyoku_index].agari_aka_count[2] ;

	}

}

/* ---------------------------------------------------------------------------------------------- */
// 荒牌時得点設定
/* ---------------------------------------------------------------------------------------------- */
void MJSOldScore::SetHowanpaiScore(MJSTkinfo *tk, int kyoku_index){

	// -----------------------------------------------------------
	// ステータス定義
	// -----------------------------------------------------------
	// tk->kyoku[tk->kyoku_index].ryukyoku_stat = HOWANPAI;

	// -----------------------------------------------------------
	// 役テーブル設定
	// -----------------------------------------------------------
/*	tk->kyoku[tk->kyoku_index].yakuman_count=0;
	tk->kyoku[tk->kyoku_index].yakucount=1;
	wsprintf(tk->kyoku[tk->kyoku_index].yakuname[0], "流局：荒牌");*/

	// -----------------------------------------------------------
	// 得点設定
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

	// 得点の加算
	Chk_totalscore(tk, kyoku_index);
}

/* ---------------------------------------------------------------------------------------------- */
// ソース終了
/* ---------------------------------------------------------------------------------------------- */
