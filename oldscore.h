/* ---------------------------------------------------------------------------------------------- 
 * 
 * プログラム概要 ： Newさくら麻雀(MJAIクライアント実装版)
 * バージョン     ： 0.1.2.0.164(OldScoreクラス削除)
 * プログラム名   ： mjs.exe
 * ファイル名     ： oldscore.h
 * クラス名       ： MJSOldScoreクラス
 * 処理概要       ： 得点計算クラス：廃止予定
 * Ver0.1.1作成日 ： 2022/07/24 10:32:05
 * Ver0.1.2作成日 ： 2022/08/31 22:19:54
 * 最終更新日     ： 2024/05/19 09:50:30
 * 
 * Copyright (c) 2010-2022 Techmilestone, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#pragma once

#ifndef MJSOLDSCORE_H_INCLUDED
#define MJSOLDSCORE_H_INCLUDED

#include "tkinfo.h"

/* ---------------------------------------------------------------------------------------------- */
// クラス定義
/* ---------------------------------------------------------------------------------------------- */

class MJSOldScore{

	// ------------------------------------------------------------------- 
	// 公開関数定義
	// ------------------------------------------------------------------- 
	public:

	// ------------------------------------------------------------------- 
	// 変数(役名)
	// ------------------------------------------------------------------- 

	// 翻数テーブル
	int yakuhan[YAKU_SHUBETSU_MAX];
	int nakihan[YAKU_SHUBETSU_MAX];
	int yakuman_bai[YAKUMAN_SHUBETSU_MAX];       // 二倍役満であるかどうか

	// 役名情報
	// char yakuname[YAKU_SHUBETSU_MAX][20];        // 手役名・通常役
	// char yakumanname[YAKUMAN_SHUBETSU_MAX][20];  // 手役名・役満

	// ------------------------------------------------------------------- 
	// 変数(得点)
	// ------------------------------------------------------------------- 

	// 得点テーブル・通常得点
	int score_ron_oya[4][10];
	int score_ron_ko[4][10];
	int score_tsumo_oya[4][10];
	int score_tsumo_ko[4][10];

	// 得点テーブル・満貫以上
	int score_mangan_ron_oya[5];
	int score_mangan_ron_ko[5];
	int score_mangan_tsumo_oya[5];
	int score_mangan_tsumo_ko[5];

	// 得点テーブル・七対子
	int score_chitoi_ron_oya[4];
	int score_chitoi_ron_ko[4];
	int score_chitoi_tsumo_oya[4];
	int score_chitoi_tsumo_ko[4];

	// 得点テーブル・役満
	int score_yakuman_ron_oya;
	int score_yakuman_ron_ko;
	int score_yakuman_tsumo_oya;
	int score_yakuman_tsumo_ko;

	// ------------------------------------------------------------------- 
	// コンストラクタ
	// ------------------------------------------------------------------- 

	// コンストラクタ
    MJSOldScore(){};

	// デストラクタ
    ~MJSOldScore(){};

	// ------------------------------------------------------------------- 
	// 関数定義
	// ------------------------------------------------------------------- 

	// 初期化・後処理
	void ScoreInit();                                             // 得点計算クラスの初期化
	void ScorePost();                                             // 得点計算クラスの終了処理

	// 事前定義
	void SetYakuInfo();                                           // 役情報定義
	void SetBaseScoreTable();                                     // 基礎得点テーブルの設定

	// 終局メイン関数
	void setAgariScore(MJSTkinfo *tk, int kyoku_index);           // 和了得点結果の設定(メイン処理)

	// 終局サブ関数
	void chk_initAgariScore(MJSTkinfo *tk, int kyoku_index);      // 01:初期化処理
	void chk_preAgariScore(MJSTkinfo *tk, int kyoku_index);       // 02:事前和了情報の設定
	void chk_mentsu(MJSTkinfo *tk, int kyoku_index);              // 03:面子確認
	void chk_tehai_count(MJSTkinfo *tk, int kyoku_index);         // 04:手牌枚数確認
	void chk_fu(MJSTkinfo *tk, int kyoku_index);                  // 05:符計算
	void chk_yaku(MJSTkinfo *tk, int kyoku_index);                // 06:役確認
	void chk_score(MJSTkinfo *tk, int kyoku_index);               // 07:得点計算

	// 終局サブ関数(七対子・国士)
	void chk_chitoi_mentsu(MJSTkinfo *tk, int kyoku_index);       // 03:面子確認(七対子)
	void chk_kokushi_mentsu(MJSTkinfo *tk, int kyoku_index);      // 03:面子確認(国士)

	// 得点計算サブ処理
	void Chk_kyokuscore(MJSTkinfo *tk, int kyoku_index);          // 局の得点収支
	void Chk_totalscore(MJSTkinfo *tk, int kyoku_index);          // 合計得点の加算

	// ドラ処理
	void Chk_tehai_dora_count(MJSTkinfo *tk, int kyoku_index, int rinshan, bool ura_chk);     // ドラ枚数の確認
	int Get_dora_hai(int dora_hai);                                                           // ドラ表示牌→ドラ牌の変換

	// 役確認
	void ChkYakuRiich(MJSTkinfo *tk, int kyoku_index);            // リーチ系
	void ChkYakuChitoiIpeko(MJSTkinfo *tk, int kyoku_index);      // 七対子、一盃口、二盃口 
	void ChkYakuChinItsu_HonItsu(MJSTkinfo *tk, int kyoku_index); // 清一混一系
	void ChkYakuAnko(MJSTkinfo *tk, int kyoku_index);             // 暗刻系
	void ChkYakuChanta(MJSTkinfo *tk, int kyoku_index);           // チャンタ系
	void ChkYakuSanshoku(MJSTkinfo *tk, int kyoku_index);         // 三色系
	void ChkYakuItsu(MJSTkinfo *tk, int kyoku_index);             // 一通系
	void ChkYakuPinfu(MJSTkinfo *tk, int kyoku_index);            // 平和系
	void ChkYakuTanyao(MJSTkinfo *tk, int kyoku_index);           // タンヤオ系
	void ChkYakuYakuhai(MJSTkinfo *tk, int kyoku_index);          // 役牌系
	void ChkYakuDaisangen(MJSTkinfo *tk, int kyoku_index);        // 大三元・小三元
	void ChkYakuDaisushi(MJSTkinfo *tk, int kyoku_index);         // 大四喜和・小四喜和
	void ChkYakuKokushi(MJSTkinfo *tk, int kyoku_index);          // 国士無双
	void ChkYakuChuren(MJSTkinfo *tk, int kyoku_index);           // 九連宝燈
	void ChkYakuTenho(MJSTkinfo *tk, int kyoku_index);            // 天和
	void ChkYakuEtc(MJSTkinfo *tk, int kyoku_index);              // その他の手役

	// 荒牌処理
	void SetHowanpaiScore(MJSTkinfo *tk, int kyoku_index);        // 荒牌時得点設定

};

#endif /* MJSOLDSCORE_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- */
// ソース終了
/* ---------------------------------------------------------------------------------------------- */
