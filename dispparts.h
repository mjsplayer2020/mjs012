/* ---------------------------------------------------------------------------------------------- 
 * 
 * プログラム概要 ： さくら麻雀(Ver0.1.2：開発版)
 * バージョン     ： 0.1.2.0.183(和了時面子情報表示の修正)
 * プログラム名   ： mjs.exe
 * ファイル名     ： dispparts.h
 * クラス名       ： MJSDisplayParts
 * 処理概要       ： パーツ描写クラス
 * 初回作成日     ： 2023/05/20 10:59:12
 * Ver0.1.2作成日 ： 2023/05/20 10:59:12
 * Ver0.1.3.0pre  ： 2024/03/19 23:55:27
 * Ver0.1.3.1pre  ： 2024/04/05 19:50:22
 * 最終更新日     ： 2024/08/25 10:19:10
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
// 固定値
/* ---------------------------------------------------------------------------------------------- */

#define PI  3.1415926535897932384626433832795f    // 円周率

#define HAI_COLOR    0                            // 牌裏面の色

// 画面モードの設定
#define SUB_TEHAI_DISP_MODE   0                   // サブ手牌の表示モード(0ならばシャンテン確認)

// 牌色の番号設定
#define DISP_HAI_COLOR_NUM_NOCOLOR        0       // 「無色」の番号

#define DISP_HAI_COLOR_NUM_GRAY           1       // 「灰色」の番号
#define DISP_HAI_COLOR_NUM_BLUE           2       // 「青色」の番号
#define DISP_HAI_COLOR_NUM_YELLOW         3       // 「黄色」の番号
#define DISP_HAI_COLOR_NUM_GREEN          4       // 「緑色」の番号

#define DISP_HAI_COLOR_NUM_DEEP_GRAY     11       // 「濃灰色」の番号
#define DISP_HAI_COLOR_NUM_DEEP_BLUE     12       // 「濃青色」の番号
#define DISP_HAI_COLOR_NUM_DEEP_YELLOW   13       // 「濃黄色」の番号
#define DISP_HAI_COLOR_NUM_DEEP_GREEN    14       // 「濃緑色」の番号

/* ---------------------------------------------------------------------------------------------- */
// ラベル(各モード)
/* ---------------------------------------------------------------------------------------------- */

// ゲームステータス
typedef enum {

	PARTS_BUT_NOCOLOR = 0,    // ボタン色なし
	PARTS_BUT_BLUE,           // ボタン青
	PARTS_BUT_GREEN,          // ボタン緑
	PARTS_BUT_YELLOW,         // ボタン黄
	PARTS_BUT_RED,            // ボタン赤

} LBPartsButColor;

/* ---------------------------------------------------------------------------------------------- */
// クラス定義
/* ---------------------------------------------------------------------------------------------- */
class MJSDisplayParts
{

	// ------------------------------------------------------------------- 
	// 公開関数定義
	// ------------------------------------------------------------------- 
	public:

	// ------------------------------------------------------------------- 
	// 画像ハンドル
	// ------------------------------------------------------------------- 

	// 背景・タイトル
	int backpic;         // 背景画
	int title;           // タイトル
	int banner;          // バナー
	int center_pltimg;   // センタープレート

	// 牌パーツ
	int Pai[40];      // 牌画像_縦
	int LPai[40];     // 牌画像_横
	
	int PaiBase[10];  // 牌裏画像_縦
	int LPaiBase[10]; // 牌裏画像_横

	// 牌背景色
	int blue;         // 牌透過-青
	int gray;         // 牌透過-灰色
	int yellow;       // 牌透過-黄色

	int lblue;        // 横牌透過-青
	int lgray;        // 横牌透過-灰色
	int lyellow;      // 横牌透過-黄色

	// 牌番号テーブル
	int PaiImgNum[40];  // 牌画像との対応表

	// プレート
	int pltimg;         // プレート画像

	// ボタン
	int but_green;      // 通常変更ボタン(緑色ボタン)
	int but_blue;       // tkinfo情報ボタン(青色ボタン)
	int but_yellow;     // ply情報ボタン(黄色ボタン)
	int but_red;        // 終了ボタン(赤色ボタン)
	int but_kyokuid;    // 局ID決定ボタン
	int but_actid;      // ActID決定ボタン

	// ボタン(ビューワーモード)
	int but02;          // 局IDボタン
	int but03;          // ACTIDボタン

	// ------------------------------------------------------------------- 
	// 文字列
	// ------------------------------------------------------------------- 

	// ディスプレイ表示用・メッセージ用
	char tmp_disp_msg[256];

	// プレート表示名
	char plt_name[PLT_COUNT_MAX][20];             // プレート表示名

	// 局表示用文字列
	char kyokutbl[12][8];

	// 役名・流局文字列
	char yakuname[YAKU_SHUBETSU_MAX][20];         // 手役名・通常役
	char yakumanname[YAKUMAN_SHUBETSU_MAX][20];   // 手役名・役満
	char ryukyokuname[10][20];                    // 流局名

	// ------------------------------------------------------------------- 
	// 画面の設定変数
	// ------------------------------------------------------------------- 

	// 手牌表示モード
	int desp_tehai_mode; // (0:ライナー表示、1:スクエア表示、2:文字列表示)

	// 牌裏面の色
	int hai_color;

	// ------------------------------------------------------------------- 
	// コンストラクタ
	// ------------------------------------------------------------------- 

	//コンストラクタ
    MJSDisplayParts(){};

	//デストラクタ
    ~MJSDisplayParts(){};

	// ------------------------------------------------------------------- 
	// クラス初期化
	// ------------------------------------------------------------------- 

	// メイン関数
	void DispPartsInit();          // パーツ表示クラスの初期化処理
	void DispPartsPost();          // パーツ表示クラスの初期化処理

	// サブ関数
	void SetYakuName();            // 役名定義

	// ------------------------------------------------------------------- 
	// DXライブラリ初期化処理
	// ------------------------------------------------------------------- 

	int  DispPartsFrameInit();     // フレーム処理
	int  DispPartsLibInit();       // 初期処理
	void DispPartsReadPic();       // 画像読み込み
	void DispPartsLibPost();       // 終了処理

	void DispPartsClearDraw();     // 初期描画処理
	void DispPartsFlip();          // フリップ処理

	// ------------------------------------------------------------------- 
	// 共通関数
	// ------------------------------------------------------------------- 

	// 共通処理(DXライブラリ関連)
	void DispString(int x, int y, char *str);                                                   // 文字列表示

	// ------------------------------------------------------------------- 
	// パーツ表示
	// ------------------------------------------------------------------- 

	// パーツ表示/DXライブラリ情報
	void DispOpeningTitle(int ver1, int ver2, int ver3, int ver4, int ver5);                    // オープニングタイトル
	void DispBunner(int ver1, int ver2, int ver3, int ver4, int ver5);                          // バナー表示
	void DispCenterPlt();                                                                       // センタープレート表示
	void DispMousepoint(int x, int y, int msx, int msy, int b0, int b1);                        // マウス情報
	void DispFps(int x, int y, float mFps, int total_frame_count, int frame_count);             // FPS・フレーム

	// パーツ表示/プレート
	void DispPltline(bool plt_mode[]);                                                          // プレートラインの表示
	void DispPltNakiAriNashi(bool plt_naki_stat);                                               // プレート/鳴有・鳴無

	// パーツ表示/ボタン
	void DispButton(int x, int y, LBPartsButColor but_color);                                   // ボタン表示
	void DispGameModeButton();                                                                  // ゲームモードのボタン一覧表示
	void DispViewerModeButton();                                                                // ビューアーモードのボタン一覧表示

	// パーツ表示/牌表示
	void DispHai(int x, int y, int hai, bool aka, bool hai_turn, int haimode, int haicolor);    // 牌表示
	void DispLHai(int x, int y, int hai, bool aka, bool hai_turn, int haimode, int haicolor);   // 横牌表示

	// パーツ表示/卓情報
	void DispDora(int x, int y, int doracount, int dora[], bool dora_aka[]);                    // ドラ情報

	// ------------------------------------------------------------------- 
	// 関数定義(牌画パーツ・ライナー表示)
	// ------------------------------------------------------------------- 

	// 牌画パーツ/手牌パーツの表示(通常バージョン)
	void DispActTehaiParts(   int  x,                       // 01:X座標
	                          int  y,                       // 02:Y座標
	                          int  tehai_tbl_count,         // 03:手牌テーブル
	                          int  tehai_tbl[],             // 04:手牌テーブル
	                          bool tehai_tbl_aka[],         // 05:手牌赤テーブル
	                          int  tsumo_hai,               // 06:自摸牌
	                          bool tsumo_aka,               // 07:自摸赤
	                          int  sute_hai_num,            // 08:捨牌の位置番号
	                          int  color_hai_num,           // 09:手牌色着色の位置(1枚目)
	                          int  color_hai2_num,          // 10:手牌色着色の位置(2枚目)
	                          bool color_ankan              // 11:手牌色着色・暗槓用
	                          );

	// 牌画パーツ/手牌パーツ(人プレーヤー捨牌禁止表示)
	void DispActHumCanSuteParts(int  x,                     // X座標
	                          int  y,                       // Y座標
	                          int  tehai_tbl_count,         // 手牌テーブル
	                          int  tehai_tbl[],             // 手牌テーブル
	                          bool tehai_tbl_aka[],         // 手牌赤テーブル
	                          bool tehai_can_sute_tbl[],    // 捨牌禁止テーブル
	                          int  tsumo_hai,               // 自摸牌
	                          bool tsumo_aka,               // 自摸・赤
	                          bool tsumo_can_sute,          // 自摸・捨牌禁止
	                          int  color_hai                // カーソル選択牌(着色牌)
	                          );

	// 牌画パーツ/手牌パーツ(人プレーヤー・槓牌選択時)
	void DispActHumKanSelectTehaiParts(int  x,              // X座標
	                          int  y,                       // Y座標
	                          int  tehai_tbl_count,         // 手牌テーブル
	                          int  tehai_tbl[],             // 手牌テーブル
	                          bool tehai_tbl_aka[],         // 手牌赤テーブル
	                          int  tsumo_hai,               // 自摸牌
	                          bool tsumo_aka,               // 自摸・赤
	                          int  ankan_hai1,              // 暗槓牌1
	                          int  ankan_hai2,              // 暗槓牌2
	                          int  ankan_hai3,              // 暗槓牌3
	                          int  kakan_hai1,              // 加槓牌1
	                          int  kakan_hai2,              // 加槓牌2
	                          int  kakan_hai3,              // 加槓牌3
	                          int  color_hai                // カーソル選択牌(着色牌)
	                          );

	// 牌画パーツ/アクション手牌・COM用の裏向き手牌
	void DisplayUnkownTehai(int  x,               // X座標
	                        int  y,               // Y座標
	                        int  tehai_tbl_count, // 手牌枚数
	                        bool tsumo_flg,       // 自摸フラグ
	                        int  sute_hai_num);   // 捨牌の位置番号

	// 牌画パーツ/晒し牌情報：ライナー表示
	void DispActSarashiParts(int x,               // X座標
	                         int y,               // Y座標
	                         LBMen naki_stat,     // 面子形式
	                         int hai_index,       // 牌番号
	                         int aka_count);      // 赤牌有無

	// 牌画パーツ/晒し面子のパーツ表示：全鳴き面子表示
	void DispAllSarashiParts(int x, 
	                         int y, 
	                         int naki_count, 
	                         LBMen naki_stat[], 
	                         int naki_hai[], 
	                         int naki_idx[], 
	                         int naki_aka[]);

	// 牌画パーツ/河情報：ライナー表示
	void DispActKawaParts_liner(int x, int y, int kawa_tbl_count, int kawa_tbl[], bool kawa_tbl_aka[], int kawa_mode[]);

	// ------------------------------------------------------------------- 
	// 関数定義(牌画パーツ・囲み表示)
	// ------------------------------------------------------------------- 

	//  牌画パーツ/アクション手牌：UPプレーヤ表示
	void DispActTehaiParts_up(   int  x,                    // 01:X座標
	                             int  y,                    // 02:Y座標
	                             int  tehai_tbl_count,      // 03:手牌数
	                             int  tehai_tbl[],          // 04:手牌テーブル
	                             bool tehai_tbl_aka[],      // 05:手牌赤テーブル
	                             int  tsumo_hai,            // 06:自摸牌
	                             bool tsumo_aka,            // 07:自摸赤
	                             int  sute_hai_num);        // 08:捨牌の位置番号

	//  牌画パーツ/アクション手牌・Downプレーヤ表示→ライナーと共通

	//  牌画パーツ/アクション手牌・Leftプレーヤ表示
	void DispActTehaiParts_left( int  x,                    // 01:X座標
	                             int  y,                    // 02:Y座標
	                             int  tehai_tbl_count,      // 03:手牌数
	                             int  tehai_tbl[],          // 04:手牌テーブル
	                             bool tehai_tbl_aka[],      // 05:手牌赤テーブル
	                             int  tsumo_hai,            // 06:自摸牌
	                             bool tsumo_aka,            // 07:自摸赤
	                             int  sute_hai_num);        // 08:捨牌の位置番号

	//  牌画パーツ/アクション手牌・RIGHTプレーヤ表示
	void DispActTehaiParts_right( int  x,                   // 01:X座標
	                              int  y,                   // 02:Y座標
	                              int  tehai_tbl_count,     // 03:手牌数
	                              int  tehai_tbl[],         // 04:手牌テーブル
	                              bool tehai_tbl_aka[],     // 05:手牌赤テーブル
	                              int  tsumo_hai,           // 06:自摸牌
	                              bool tsumo_aka,           // 07:自摸赤
	                              int  sute_hai_num);       // 08:捨牌の位置番号

	//  牌画パーツ/アクション手牌・UPプレーヤ裏向き表示
	void DisplayUnkownTehai_up(int  x,                      // X座標
	                           int  y,                      // Y座標
	                           int  tehai_tbl_count,        // 手牌枚数
	                           bool tsumo_flg,              // 自摸フラグ
	                           int  sute_hai_num);          // 捨牌の位置番号

	//  牌画パーツ/アクション手牌・Downプレーヤ裏向き表示→ライナーと共通

	//  牌画パーツ/アクション手牌・LEFTプレーヤ裏向き表示
	void DisplayUnkownTehai_left(int  x,                    // X座標
	                             int  y,                    // Y座標
	                             int  tehai_tbl_count,      // 手牌枚数
	                             bool tsumo_flg,            // 自摸フラグ
	                             int  sute_hai_num);        // 捨牌の位置番号

	//  牌画パーツ/アクション手牌・RIGHTプレーヤ裏向き表示
	void DisplayUnkownTehai_right(int  x,                   // X座標
	                              int  y,                   // Y座標
	                              int  tehai_tbl_count,     // 手牌枚数
	                              bool tsumo_flg,           // 自摸フラグ
	                              int  sute_hai_num);       // 捨牌の位置番号


	// 牌画パーツ/晒し牌情報
	void DispActSarashiParts_up(int x,    int y, LBMen naki_stat, int hai_index, int aka_count);         // 晒し面子のパーツ表示：UPプレーヤ表示
	// void DispActSarashiParts_down(int x, int y, LBMen naki_stat, int hai_index, int aka_count);       // 晒し面子のパーツ表示：DOWNプレーヤ表示→ライナーと共通
	void DispActSarashiParts_left(int x,  int y, LBMen naki_stat, int hai_index, int aka_count);         // 晒し面子のパーツ表示：LEFTプレーヤ表示
	void DispActSarashiParts_right(int x, int y, LBMen naki_stat, int hai_index, int aka_count);         // 晒し面子のパーツ表示：RIGHTプレーヤ表示

	// 牌画パーツ/河情報
	void DispActKawaParts_up(int x,    int y, int kawa_tbl_count, int kawa_tbl[], bool kawa_tbl_aka[], int kawa_mode[]);             // 河パーツ表示：UPプレーヤ表示
	void DispActKawaParts_down(int x,  int y, int kawa_tbl_count, int kawa_tbl[], bool kawa_tbl_aka[], int kawa_mode[]);           // 河パーツ表示：DOWNプレーヤ表示
	void DispActKawaParts_left(int x,  int y, int kawa_tbl_count, int kawa_tbl[], bool kawa_tbl_aka[], int kawa_mode[]);           // 河パーツ表示：LEFTプレーヤ表示
	void DispActKawaParts_right(int x, int y, int kawa_tbl_count, int kawa_tbl[], bool kawa_tbl_aka[], int kawa_mode[]);          // 河パーツ表示：RIGHTプレーヤ表示

	// 牌画パーツ/囲み手牌表示(テスト用)
	void DispActTehai_test_square();       // 卓表示(テスト用）
	void DispActTehai_test_square_parts(); // 卓表示(テスト用：パーツ表示)

};

#endif/* MJSDISPPARTS_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- */
// ソース終了
/* ---------------------------------------------------------------------------------------------- */
