/* ---------------------------------------------------------------------------------------------- 
 * 
 * プログラム概要 ： Newさくら麻雀(MJAIクライアント実装版)
 * バージョン     ： 0.1.2.0.180(mjsplyと変数、関数名の共通化)
 * プログラム名   ： mjs.exe
 * ファイル名     ： player.h
 * クラス名       ： MJSPlayerクラス
 * 処理概要       ： プレーヤークラス
 * Ver0.0.8作成日 ： 2012/05/04 11:41:34
 * Ver0.1.0作成日 ： 2022/06/04 10:13:26
 * Ver0.1.1作成日 ： 2022/06/30 21:19:01
 * Ver0.1.2作成日 ： 2022/10/23 23:38:32
 * 最終更新日     ： 2024/08/12 11:23:39
 * 
 * Copyright (c) 2010-2024 TechMileStoraJP, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#pragma once

#ifndef PLY_H_INCLUDED
#define PLY_H_INCLUDED

#include "tkinfo.h"

/* ---------------------------------------------------------------------------------------------- */
// ラベル(各モード)
/* ---------------------------------------------------------------------------------------------- */

// プレーヤーキャラクター
typedef enum {

	PLYCHAR_NONAME = 0,                 // 00:プレーヤー状態なし
	PLYCHAR_TAMPOPO,                    // 01:プレーヤーキャラクター1
	PLYCHAR_HIMAWARI,                   // 02:プレーヤーキャラクター2
	PLYCHAR_FATABA,                     // 03:プレーヤーキャラクター3
	PLYCHAR_WAKABA,                     // 04:プレーヤーキャラクター4
	PLYCHAR_AOBA,                       // 05:プレーヤーキャラクター5
	PLYCHAR_AYAME,                      // 06:プレーヤーキャラクター6
	PLYCHAR_TSUBAKI,                    // 07:プレーヤーキャラクター7
	PLYCHAR_KOBUSHI,                    // 08:プレーヤーキャラクター8
	PLYCHAR_NADESHIKO,                  // 09:プレーヤーキャラクター9
	PLYCHAR_TSUBOMI,                    // 10:プレーヤーキャラクター10
	PLYCHAR_SAKURA,                     // 11:プレーヤーサクラ
	PLYCHAR_MJSPLY_TEST,                // 12:テスト用キャラクター

} LBPlyChar;

// プレーヤー手牌モード
typedef enum {

	PLY_TEHAI_NO_MODE = 0,              // 00:状態なし
	PLY_TEHAI_NORMAL,                   // 01:通常状態
	PLY_TEHAI_NAKI_WAIT,                // 02:鳴き待ち
	PLY_TEHAI_RIICHI_SUTEHAI,           // 03:リーチ時の捨牌選択
	PLY_TEHAI_RIICHI_YUKO,              // 04:リーチ有効状態

} LBPlyTehaiMode;

/* ---------------------------------------------------------------------------------------------- */
// 変数定義
/* ---------------------------------------------------------------------------------------------- */

class MJSPlayer{

	public:

	// -----------------------------
	// 卓情報
	// -----------------------------

	// プレーヤのタイプ
	LBPlyChar ply_type;

	// プレーヤ席番号
	int ply_num;                             // 自分のプレーヤ番号
	int ply_num_shimo;                       // 下家のプレーヤ番号

	// プレーヤの家
	int ie;                                  // 家情報 東家：0、南家：1、ie=2でプレーヤが西家
	int ply_bakaze;                          // プレーヤの場風牌の牌番号(東家 = 0、南家 = 1)
	int ply_zikaze;                          // プレーヤの自風牌の牌番号

	// 赤牌情報
	int max_aka_count[AKA_TYPE_MAX_COUNT];   // 最大赤牌枚数

	// -----------------------------
	// 手牌情報
	// -----------------------------

	// 手牌情報
	int tehai[PAI_MAX];                      // 手牌ヒストグラム
	int tehai_count;                         // 手牌枚数
	int aka_count[AKA_TYPE_MAX_COUNT];       // 赤牌枚数

	// 手牌テーブル
	int  tehaitbl[TEHAI_MAX];                // 牌テーブル
	bool tehaitbl_aka[TEHAI_MAX];            // 牌テーブル(赤牌)

	// リーチ状態
	int ply_riichi_mode;                     // リーチ状態(0：リーチかけてない、1：リーチ宣言後・捨牌前、2：リーチ確定状態)

	/* ----------------------------- */
	// 晒し牌情報
	/* ----------------------------- */

	int naki_count;                          // 鳴き合計面子数
	int ankan_count;                         // 暗槓合計面子数
	int kakan_count;                         // 加槓合計面子数

	LBMen naki_stat[MEN_MAX];                // 鳴き状態
	int naki_hai[MEN_MAX];                   // 鳴き牌
	int naki_idx[MEN_MAX];                   // チー時の頭牌
	int naki_aka[MEN_MAX];                   // 赤牌の数

	/* ----------------------------- */
	// 河情報
	/* ----------------------------- */

	int kawa[30];                            // 河(捨牌情報)

	/* ----------------------------- */
	// プレーヤーアクション情報
	/* ----------------------------- */

	// アクションステータス
	LBPAct ply_act;                     // プレーヤーのアクションステータス

	// ツモアクション
	int  ply_tsumo_hai;                 // ツモ牌
	bool ply_tsumo_aka;                 // 自摸牌の赤牌有無

	// 捨牌アクション
	int  ply_sute_hai;                  // 捨牌
	bool ply_sute_aka;                  // 捨牌の赤牌有無

	// 鳴きアクション
	int ply_naki_idx;                   // 鳴いた時の牌INDEX(カン宣言も含む)
	int ply_naki_aka_count;             // 鳴いた時の赤牌枚数

	/* ----------------------------- */
	// 向聴数定義
	/* ----------------------------- */

	int shanten_normal;                 // 通常向聴数
	int shanten_kokushi;                // 国士向聴数
	int shanten_chitoi;                 // 七対向聴数

	/* ----------------------------- */
	// 通常シャンテン計算
	/* ----------------------------- */

	int atama_count;                    // 雀頭の枚数(値は0又は1)
	int atama_hai;                      // 雀頭の牌番号

	int mentu_count;                    // 面子数
	LBMen mentu_stat[MEN_MAX];          // 面子状態
	int mentu_hai[MEN_MAX];             // 面子牌

	int taatu_count;                    // 塔子数
	LBMen taatsu_stat[MEN_MAX];         // 塔子状態
	int taatsu_hai[MEN_MAX];            // 塔子牌

	// -----------------------------
	// 通常シャンテン計算・作業用
	// -----------------------------

	int tmp_shanten;                    // (作業用)通常シャンテン

	int tmp_atama_count;                // 雀頭の枚数(値は0又は1)
	int tmp_atama_hai;                  // 雀頭の牌番号

	int tmp_mentu_count;                // 面子数
	LBMen tmp_mentu_stat[MEN_MAX];      // 面子状態
	int tmp_mentu_hai[MEN_MAX];         // 面子牌

	int tmp_taatu_count;                // 塔子数
	LBMen tmp_taatsu_stat[MEN_MAX];     // 塔子状態
	int tmp_taatsu_hai[MEN_MAX];        // 塔子牌

	// -----------------------------
	// 捨牌候補・捨牌候補ごとの有効牌
	// -----------------------------

	int sutekoho_count;                 // 捨牌候補の総数
	int sutekoho_hai[14];               // 捨牌候補の牌番号
	int sutekoho_shanten[14];           // 捨牌候補の向聴数
	int sutekoho_priority[14];          // 捨牌候補の優先順位

	bool yuko_hai[14][40];              // 有効牌
	int  yuko_haishu_count[14];         // 有効牌の牌種別数
	int  yuko_hai_count[14];            // 有効牌となる種別の総数
	int  yuko_max_count;                // 有効牌の最大数

	int fixed_sutekoho_num;             // 最終決定した捨牌番号

	// -----------------------------
	// プレーヤステータス
	// -----------------------------

	// プレーヤステータス
	bool ply_tehai_ori_stat;               // オリ状態
	int  ply_ori_hai;                      // オリ状態の候補オリ牌
	bool ply_ori_aka;                      // オリ状態の候補オリ牌の赤牌有無

	// 和了処理関連
	bool ply_tehai_yaku_stat;              // 手牌役の有無
	bool ply_furiten_stat;                 // フリテン状態

	// 鳴き処理関連
	bool ply_tehai_naki_stat;              // 鳴き許可
	bool ply_yakuhai_stat;                 // 役牌の保持有無

	// -----------------------------
	// 鳴き候補テーブル
	// -----------------------------

	// 有効牌
	bool yuko_hai_13mai[PAI_MAX];       // 13枚時の有効牌

	// 鳴き候補テーブル
	int  nakikoho_tbl_count;                             // 鳴き候補テーブルの枚数
	LBPAct nakikoho_tbl_act[NAKI_KOHO_MAX_COUNT];        // 鳴き候補テーブル
	int  nakikoho_tbl_hai[NAKI_KOHO_MAX_COUNT];          // 鳴き候補_牌テーブル
	int  nakikoho_tbl_idx[NAKI_KOHO_MAX_COUNT];          // 鳴き候補_チーテーブル
	bool nakikoho_tbl_yesno[NAKI_KOHO_MAX_COUNT];        // 鳴き候補_実行有無

	// -----------------------------
	// コンストラクタ
	// -----------------------------

	// コンストラクタ定義
    MJSPlayer(){};

	// デストラクタ定義
    ~MJSPlayer(){};

	// -----------------------------
	// アクション処理
	// -----------------------------

	// クラス初期化・後処理
	void PlyInit();
	void PlyPost();

	// 1-1.卓開始・終了
	void PlyActTakuStart(int tmp_ply_num);
	void PlyActTakuEnd();

	// 1-2.局開始・終了
	void PlyActKyokuStart(int tmp_ie);

	void PlyActKyokuEnd();

	// 2-1.配牌処理
	void PlyActHaipai(int tmp_tsumo_hai, bool tmp_tsumo_aka);

	// 2-2.配牌後処理
	void PlyActPostHaipai();

	// 3-1.自摸処理
	void PlyActTsumo(int tmp_tsumo_hai, bool tmp_tsumo_aka);          // 自摸時捨牌決定(メイン)
	void PlyChkAISutehai();                                           // (サブ)戦略を含めた捨牌設定
	void PlyChkTehaiOri();                                            // (サブ)手牌オリ確認
	void PlyCountTsumo();                                             // 自摸枚数をカウント

	// 3-1.(サブ処理)アクション確認
	void PlyChkAnkan(int tmp_tsumo_hai, bool tmp_tsumo_aka);          // 暗槓確認
	void PlyChkKakan(int tmp_tsumo_hai, bool tmp_tsumo_aka);          // 加槓確認
	void PlyChkTsumoSute();                                           // 自摸時のアクションと捨牌の決定
	void PlyChk9shu9hai();                                            // 九種九牌確認

	// 3-2.リーチ宣言時処理
	void PlyChkRiichiSute(struct MJSPlyInfo *pinfo);                  // リーチ時の捨牌決定(メイン)

	// 3-3.捨牌後アクション処理
	void PlyActTsumoSute();                                           // 自摸捨牌アクション

	// 3-3.(サブ処理)捨牌後アクション処理
	void PlySetTsumoSuteTehaiHist();                                  // 1.自摸捨牌時の手牌ヒストグラム処理
	void PlyChkPlyStat();                                             // 2.プレーヤ手牌の状態確認
	void PlyChkYaku();                                                // 3.役有り確認
	void PlyChkFuriten();                                             // 4.フリテン確認
	void PlyChkNakitbl();                                             // 5.鳴きテーブルの状態確認
	void PlySetKawa(int tmp_ply_id, int tmp_hai, int tmp_aka);        // (汎用処理)河情報の設定

	// 3-4.捨牌時アクション処理(自摸捨てアクション以外)
	void PlyActAnkan(int tmp_naki_hai);                               // 暗槓アクション
	void PlyActKakan(int tmp_naki_hai, int tmp_naki_aka_count);       // 加槓アクション

	// 4-1.他プレーヤの確認処理
	void PlyChkOthPlyTsumo();                                         // 他プレーヤの自摸
	void PlyChkOthPlyRiichi(int tmp_ply_id);                          // 他プレーヤのリーチ宣言
	void PlyChkNaki(int suteply, int hai);                            // 鳴き確認

	// 4-2.鳴きアクション処理
	void PlyActNaki(int naki_ply_num,                                 // 鳴きプレーヤ
	                LBPAct naki_ply_act,                              // 鳴きアクション種別
	                int hai,                                          // 鳴き牌
	                int chi_hai_idx,                                  // 鳴き面子(チー面子)の頭牌
	                int naki_aka_count);                              // 鳴き面子の赤牌枚数
	void PlyChkNakiSute();                                            // 鳴き後の捨牌確認

	// 4-3.鳴き捨牌アクション
	void PlyActNakiSute();                                            // 鳴き後の捨牌処理

	// 5-1.和了終了処理
	void PlyAgari();

	// 5-2.流局終了処理
	void PlyRyuKyoku();

	// -----------------------------
	// 向聴数確認(メイン処理)
	// -----------------------------

	void ChkTsumoAriShanten();          // 自摸有り(自摸後。捨牌前)状態の向聴数確認：捨牌候補算出
	void ChkTsumoNashiShanten();        // 自摸無し(捨牌後、自摸前)状態の向聴数確認：鳴きテーブル情報格納
	void SetSutekohoPriority();         // 捨牌候補の優先順位算出
	void SetFixedSutekoho();            // 最終捨牌候補の算出

	// -----------------------------
	// 向聴数確認(サブ処理)
	// -----------------------------

	void NormalShanten();               // 向聴数確認(通常)
	void mentu_cut(int hai);            // 面子削除処理
	void taatu_cut(int hai);            // 塔子削除処理

	void NormalShanten_detail();        // 向聴数確認(通常_面子情報付与版)
	void mentu_cut_detail(int hai);     // 面子削除処理(面子情報付与版)
	void taatu_cut_detail(int hai);     // 塔子削除処理(塔子情報付与版)

	void KokushiShanten();              // 向聴数確認(国士無双)
	void ChitoiShanten();               // 向聴数確認(七対子)

	// -----------------------------
	// その他の関数
	// -----------------------------

	// 手牌テーブル更新処理
	void settehaitbl();                 // 手牌テーブル更新処理

};

#endif/* PLY_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- */
// ソース終了
/* ---------------------------------------------------------------------------------------------- */
