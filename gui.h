/* ---------------------------------------------------------------------------------------------- 
 * 
 * プログラム概要 ： さくら麻雀(Ver0.1.2：開発版)
 * バージョン     ： 0.1.2.0.182(囲みモード：鳴き捨牌時のアクション手牌表示)
 * プログラム名   ： mjs.exe
 * ファイル名     ： gui.h
 * クラス名       ： MJSGui
 * 処理概要       ： GUI操作クラス
 * Ver0.1.0作成日 ： 2022/05/03 18:50:06
 * 最終更新日     ： 2024/08/17 11:36:15
 * 
 * Copyright (c) 2010-2024 Techmilestone, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#include "stdafx.h"
#include "DxLib.h"
#include "tkinfo.h"

#ifndef MJSMOUSE_H_INCLUDED
#define MJSMOUSE_H_INCLUDED

/* ---------------------------------------------------------------------------------------------- */
// 固定値(画像関連)
/* ---------------------------------------------------------------------------------------------- */

// 手牌表示形式
#define DESP_TEHAI_MODE_DEF               1    // デフォルトの手牌表示モード(0:ライナー表示、1:スクエア表示、2:テスト表示)

// フレームカウント
#define AUTO_FRAME_COUNT_PLAYING         20    // プレイモードのフレームカウント数
#define AUTO_FRAME_COUNT_RUNNING          1    // 検証モードのフレームカウント数
#define AUTO_FRAME_COUNT_CLIENT           5    // クライアントモードのフレームカウント数
#define AUTO_FRAME_COUNT_CLIENT_SND       5    // 送信時ウエイト用のフレームカウント数
#define AUTO_FRAME_COUNT_AUTO_TSUMO      20    // リーチ時のオート自摸のフレームカウント数
#define AUTO_FRAME_COUNT_RESULT         150    // 結果表示等のウェイト用フレームカウント数

/* ---------------------------------------------------------------------------------------------- */
// 固定値(GUIクラス定義用)
/* ---------------------------------------------------------------------------------------------- */

#define PLT_COUNT_MAX    10   // プレート総数
#define PLTLINE_COUNT     6   // プレートラインの数
#define PLTSTATNUM_NEXT   6   // 「次へ」プレートの位置番号

/* ---------------------------------------------------------------------------------------------- */
// 固定値(サイズ)
/* ---------------------------------------------------------------------------------------------- */

// 牌サイズ
#define HAI_XSIZE        24
#define HAI_YSIZE        32

// 横牌サイズ
#define LHAI_XSIZE       32
#define LHAI_YSIZE       24

// プレートサイズ
#define PLT_ICON_XSIZE   80
#define PLT_ICON_YSIZE   30

// ボタンサイズ
#define BUT_ICON_XSIZE   32
#define BUT_ICON_YSIZE   32

/* ---------------------------------------------------------------------------------------------- */
// 固定値(画像位置)
/* ---------------------------------------------------------------------------------------------- */

// オープニング表示位置
#define OPENING_BUT01_X_START     150   // セレクトボタンのX軸開始位置
#define OPENING_BUT01_Y_START     250   // セレクトボタンのY軸開始位置
#define OPENING_BUT01_Y_RANGE      50   // Y軸の幅

// 共通パーツの表示位置
#define GAMESTAT_X_STAT           770   // ゲームステータスのX位置
#define GAMESTAT_Y_STAT            50   // ゲームステータスのY位置

// ゲームモードの表示位置(全体)
#define STRING_YSIZE               17   // 文字サイズ
#define PLY_YSIZE                  90   // プレーヤーごとのYサイズのレンジ
#define SPACE_XSIZE                 5   // X軸の隙間サイズ
#define SPACE_YSIZE                 5   // Y軸の隙間サイズ

// ゲームモードの表示位置(牌表示)
#define DORA_XSIZE                450   // ドラ牌の位置
#define URADORA_XSIZE_RANGE       130   // 裏ドラ牌の差分位置

// ゲームモードの表示位置(手牌関連)
#define NAKI_X_START              600   // 鳴き牌のX軸開始位置
#define NAKI_MENTSU_XSIZE         150   // 鳴き面子の幅サイズ

// ゲームモードの表示位置(手牌関連・囲みモード)

#define LINE_SUTEHAI_COUNT_MAX      6   // 1行あたりの捨牌数

#define TEHAI_RIGHT_X_START       540   // RIGHTの手牌X開始位置
#define TEHAI_RIGHT_Y_START       100   // RIGHTの手牌Y開始位置
#define TEHAI_RIGHT_NAKI_X_START  380   // RIGHTの鳴牌開始位置
#define TEHAI_RIGHT_NAKI_Y_START  105   // RIGHTの鳴牌開始位置
#define TEHAI_RIGHT_SUTE_X_START  380   // RIGHTの捨牌開始位置
#define TEHAI_RIGHT_SUTE_Y_START  215   // RIGHTの捨牌開始位置

#define TEHAI_UP_X_START          210   // UPの手牌X開始位置
#define TEHAI_UP_Y_START           65   // UPの手牌Y開始位置
#define TEHAI_UP_NAKI_X_START      65   // UPの鳴牌開始位置
#define TEHAI_UP_NAKI_Y_START      65   // UPの鳴牌開始位置
#define TEHAI_UP_SUTE_X_START     210   // UPの捨牌開始位置
#define TEHAI_UP_SUTE_Y_START     115   // UPの捨牌開始位置

#define TEHAI_LEFT_X_START          5   // LEFTの手牌X開始位置
#define TEHAI_LEFT_Y_START        100   // LEFTの手牌Y開始位置
#define TEHAI_LEFT_NAKI_X_START    60   // LEFTの鳴牌開始位置
#define TEHAI_LEFT_NAKI_Y_START   310   // LEFTの鳴牌開始位置
#define TEHAI_LEFT_SUTE_X_START   155   // LEFTの捨牌開始位置
#define TEHAI_LEFT_SUTE_Y_START   155   // LEFTの捨牌開始位置

#define TEHAI_DOWN_X_START         50   // DOWNの手牌X開始位置
#define TEHAI_DOWN_Y_START        420   // DOWNの手牌Y開始位置
#define TEHAI_DOWN_NAKI_X_START   420   // DOWNの鳴牌開始位置
#define TEHAI_DOWN_NAKI_Y_START   420   // DOWNの鳴牌開始位置
#define TEHAI_DOWN_SUTE_X_START   210   // DOWNの捨牌開始位置
#define TEHAI_DOWN_SUTE_Y_START   310   // DOWNの捨牌開始位置

// ゲームモードの表示位置(プレーヤー情報)
#define PLY_YSTART                 85   // プレーヤー情報のY開始位置

// ゲームモードの表示位置(プレート関連)
#define PLT_Y_STAT                465   // プレートのY位置
#define PLT_NAKIARI_X_STAT        550   // プレート鳴き有無のX位置

// ゲームモードの表示位置(ボタン関連)
#define BUT_Y_STAT          515         // ボタンのY位置
#define BUT01_X_STAT          5         // ボタン01のX位置(局開始情報)
#define BUT02_X_STAT         45         // ボタン02のX位置(ビューワーモード：局ID変更)
#define BUT03_X_STAT        115         // ボタン03のX位置(ビューワーモード：ActID変更)
#define BUT04_X_STAT        315         // ボタン04のX位置(局終了情報)
#define THINFO_BUT_X_STAT   360         // 手牌詳細情報ボタンのX位置
#define TKINFO_BUT_X_STAT   400         // TKクラス情報ボタンのX位置
#define PLYINFO_BUT_X_STAT  440         // PLY情報ボタンのX位置
#define QUIT_BUT_X_STAT     480         // 終了ボタンのX位置

// ゲームモードの表示位置(情報表示)
#define DEBUG_INFO_Y_STAT   550         // デバグ情報のY位置
#define GUI_INFO_Y_STAT     715         // GUI情報のY位置
#define TKINFO_X1           145         // 卓情報_1のX位置
#define TKINFO_X2           275         // 卓情報_2のX位置

// ゲームモードの表示位置(和了結果)
#define AGARI_INFO_X1       250         // 和了情報_1のX位置
#define AGARI_INFO_X1_1     350         // 和了情報_1(サブ1)のX位置
#define AGARI_INFO_X1_2     390         // 和了情報_1(サブ2)のX位置
#define AGARI_INFO_X2       450         // 和了情報_2のX位置
#define AGARI_INFO_X3       620         // 和了情報_3のX位置
#define AGARI_INFO_X4       670         // 和了情報_4のX位置

/* ---------------------------------------------------------------------------------------------- */
// ラベル(各モード)
/* ---------------------------------------------------------------------------------------------- */

// GUIメインステータス
typedef enum {

	GUI_NO_MAIN_STAT = 0, // 何もしていない

	GUI_OPENING_INIT,     // タイトル画面
	GUI_OPENING,
	GUI_OPENING_POST,

	GUI_PLAYING_INIT,     // 卓ゲームプレイモード
	GUI_PLAYING,
	GUI_PLAYING_POST,

	GUI_VIEWING_INIT,     // ビューワーモード
	GUI_VIEWING,
	GUI_VIEWING_POST,

	GUI_RUNNING_INIT,     // 検証モード
	GUI_RUNNING,
	GUI_RUNNING_POST,

	GUI_CLIENT_INIT,      // MJAIクライアントモード
	GUI_CLIENT,
	GUI_CLIENT_POST,

	GUI_MJAISERVER_INIT,  // MJAIサーバモード
	GUI_MJAISERVER,
	GUI_MJAISERVER_POST,

	GUI_SETTING_INIT,     // 設定画面
	GUI_SETTING,
	GUI_SETTING_POST,

	GUI_DEMO_INIT,        // デモ画面
	GUI_DEMO,
	GUI_DEMO_POST,

} LBGuiGmSt;

// 卓GUIモード
typedef enum {

	COMMON_NO_MODE = 0,                 // 00:状態なし
	COMMON_BAGIME_MODE,                 // 01:卓開始(場決め)モード
	COMMON_PLAY_MODE,                   // 02:通常モード
	COMMON_TEHAI_DETAIL_MODE,           // 03:手牌詳細モード
	COMMON_TKINFO_MODE,                 // 04:TKクラス情報表示モード
	COMMON_END_CHECK_MODE,              // 05:終了確認モード
	COMMON_KYOKURESULT_MODE,            // 06:局結果表示
	COMMON_TAKURESULT_MODE,             // 07:卓結果表示
	COMMON_END_MODE,                    // 08:終了モード
	GAME_PLY_INFO_MODE,                 // 09:プレーヤモジュール表示用
	SETTING_DETAIL_MODE,                // 10:設定モード

} LBGuiTakuMode;

// 手牌GUIモード
typedef enum {

	TEHAI_NO_MODE = 0,                  // 00:状態なし
	TEHAI_NORMAL,                       // 01:通常状態
	TEHAI_RIICHI_SUTEHAI,               // 03:リーチ時の捨牌選択
	TEHAI_RIICHI_YUKO,                  // 04:リーチ有効状態
	TEHAI_ANKAN_KAKAN_SELECT,           // 05:アンカン・カカン選択(アンカン・カカンは同時)
	TEHAI_CHI_SELECT,                   // 06:チー選択
	TEHAI_KUIKAE_NAKISUTE,              // 07:喰い換え状態の鳴き捨牌

} LBGuiTehaiMode;

// クライアントモード・ステータス
typedef enum {

	GUI_MJAI_CLIENT_NO_MODE = 0,        // 00:状態なし
	GUI_MJAI_NOTCONNECT,                // 01:接続前待ち
	GUI_MJAI_CONNECT_ACTION,            // 02:接続処理
	GUI_MJAI_CHECK_DISCONNECT,          // 03:切断確認
	GUI_MJAI_DISCONNECT,                // 04:切断処理
	GUI_MJAI_ERR_CONNECT,               // 05:Socket接続時エラー
	GUI_MJAI_WAIT_HELO_RESMES,          // 06:HELLOリクエスト待ち
	GUI_MJAI_WAIT_TAKU_START_RESMES,    // 07:卓開始待ち
	GUI_MJAI_BAGIME,                    // 08:場決め
	GUI_MJAI_WAIT_KYOKU_START_RESMES,   // 09:局開始待ち
	GUI_MJAI_HAIPAI,                    // 10:配牌表示
	GUI_MJAI_WAIT_TAKU_RESMES,          // 11:卓モード：受信メッセージ待ち
	GUI_MJAI_WAIT_TAKU_PLYACT,          // 12:卓モード：プレーヤーアクション待ち
	GUI_MJAI_WAIT_SED_MES,              // 13:卓モード：メッセージ送信の処理待ち時間
	GUI_MJAI_ERR_RES_MES,               // 14:卓モード：エラーメッセージ受信時状態
	GUI_MJAI_KYOKUEND,                  // 15:局結果：局終了処理
	GUI_MJAI_KYOKUEND_SED_MES,          // 16:局結果：局終了時の確認メッセージ送信の待ち時間
	GUI_MJAI_TAKURESULT,                // 17:卓結果：卓結果処理
	GUI_MJAI_END_MODE,                  // 18:終了モード

} LBGuiMjaiClientMode;

/* ---------------------------------------------------------------------------------------------- */
// ラベル(GUI向け)
/* ---------------------------------------------------------------------------------------------- */

// プレートラベル
typedef enum {

	// 通常表示
	PLT_RIICHI = 0,      // 00:プレート・リーチ
	PLT_PON,             // 01:プレート・ポン
	PLT_KAN,             // 02:プレート・カン
	PLT_CHI,             // 03:プレート・チー
	PLT_AGARI,           // 04:プレート・和了
	PLT_NEXT,            // 05:プレート・次へ

	// 鳴有/鳴無
	PLT_NAKIARI,         // 06:プレート・鳴有
	PLT_NAKINASHI,       // 07:プレート・鳴無

	// YES/NO処理
	PLT_YES,             // 08:プレート・はい
	PLT_NO,              // 09:プレート・いいえ

} LBPlt;

/* ---------------------------------------------------------------------------------------------- */
// クラス定義
/* ---------------------------------------------------------------------------------------------- */
class MJSGui
{

	/* ----------------------------- */
	// 公開関数定義
	/* ----------------------------- */
	public:

	// -----------------------------
	// マウス用
	// -----------------------------
	int msx;                   // マウスのX座標
	int msy;                   // マウスのY座標
	int wheelrotvol;           // ホイールの回転量
	unsigned int Button[8];    // ボタンの押した状態

	// マウス押下フラグ
	// bool mouse_push_flg  
	int mouse_push_flg;                      // bool型に変更予定

	// -----------------------------
	// マウス押下関連のフラグ
	// -----------------------------
	bool act_push_flg;                       // 有効箇所を押下した場合のマウス押下フラグ                         
	bool but_push_flg;                       // ボタン押下フラグ

	// -----------------------------
	// フレームカウント
	// -----------------------------
	int frame_count;                         // フレームカウント
	int total_frame_count;                   // 合計フレームカウント

	// -----------------------------
	// 手牌位置
	// -----------------------------
	int tehai_x;                             // 手牌のX座標
	int tehai_y;                             // 手牌のY座標

	// -----------------------------
	// プレート
	// -----------------------------
	bool plt_mode[PLT_COUNT_MAX];            // プレート表示有無
	char plt_name[PLT_COUNT_MAX][20];        // プレート表示名
	bool plt_nakiari_flg;                    // 鳴有/鳴無フラグ

	// -----------------------------
	// 表示モードごとのGUI状態(プレイモード)
	// -----------------------------

	// GUIメインステータス
	LBGuiGmSt gui_main_stat;                 // メインステータスの値
	LBGuiGmSt gui_next_stat;                 // 「POST処理」後にメインステータスの値

	// GUIモード(卓表示)
	LBGuiTakuMode  gui_taku_mode;            // 卓表示モード
	LBGuiTehaiMode gui_ply_tehai_mode;       // 手牌表示モード(手牌・鳴き状態)

	// -----------------------------
	// 表示モードごとのGUI状態(ビューアーモード)
	// -----------------------------

	// ビューアーモード
	int gui_kyoku;                           // GUI局番号
	int gui_actid;                           // GUIアクション番号

	// -----------------------------
	// 表示モードごとのGUI状態(クライアントモード)
	// -----------------------------

	// クライアントのステータス
	LBGuiMjaiClientMode cli_mode;

	// -----------------------------
	// Socket処理用
	// -----------------------------

	// IPアドレス
	int ip_seg1;                   // IPアドレス・セグメント1
	int ip_seg2;                   // IPアドレス・セグメント2
	int ip_seg3;                   // IPアドレス・セグメント3
	int ip_seg4;                   // IPアドレス・セグメント4

	// Socketメッセージ
	char res_mes[1024];            // 受信メッセージ
	char snd_mes[1024];            // 送信メッセージ
	char stat_mes[256];            // ステータスメッセージ

	// Socket処理
	int send_wait_frame_count;     // メッセージ処理待ち時のフレーム数
	int send_mes_bytes;            // 送信バッファのサイズ

	// MJAIメッセージ解析用バッファ
	int  wk_str_count;             // 作業用文字配列の総数
	char wk_str[128][64];          // 作業用文字配列

	// -----------------------------
	// 鳴き種別用
	// -----------------------------

	// 鳴き種別(アンカン関連)
	int naki_ankan_hai_count;                     // アンカン牌枚数
	int naki_ankan_hai[4];                        // アンカンの牌番号

	// 鳴き種別(カカン関連)
	int naki_kakan_hai_count;                     // カカン牌枚数
	int naki_kakan_hai[4];                        // カカンの牌番号

	// 鳴き種別(チー関連)
	int  chihai_count;                            // チー牌枚数
	bool chihai_mode[CHI_KOHO_COUNT_MAX];         // チー牌の有効性
	int  chi_idx_hai[CHI_KOHO_COUNT_MAX];         // チー牌先頭の牌番号
	int  chi_aka_count[CHI_KOHO_COUNT_MAX];       // チーの赤牌枚数
	int  chi_hai_num1[CHI_KOHO_COUNT_MAX];        // チーを行う手牌1枚目の牌番号
	int  chi_hai_num2[CHI_KOHO_COUNT_MAX];        // チーを行う手牌2枚目の牌番号

	// 捨牌不可テーブル
	int  cannot_sutehai_count;                    // 捨牌不可牌の枚数
	int  cannot_sutehai[14];                      // 捨牌不可テーブル

	// -----------------------------
	// コンストラクタ
	// -----------------------------

	//コンストラクタ
    MJSGui(){};

	//デストラクタ
    ~MJSGui(){};

	// -----------------------------
	// 関数定義
	// -----------------------------

	// GUIクラス初期化処理
	void GuiInit();
	void GuiPost();

	// マウス状態
	void MouseStat();

	// -----------------------------
	// オープニング
	// -----------------------------
	void chk_opening(MJSTkinfo *tk);

	// -----------------------------
	// 共通関数
	// -----------------------------
	void auto_frame_click(int tmp_coint_max);                         // フレーム自動カウント
	void auto_frame_click_riichi(MJSTkinfo *tk, int tmp_coint_max);   // フレーム自動カウント(リーチ用)
	void chk_but(MJSTkinfo *tk);                                      // 終了ボタンの確認
	void set_plt_next();                                              // 次へボタン確認
	void set_plt_naki_arinashi();                                     // 「鳴有/鳴無」プレートの表示変更
	void set_plt_false();                                             // プレート表示の無効化

	// -----------------------------
	// 共通関数・手牌処理
	// -----------------------------
	// void set_gui_ply_tsumo_action(MJSTkinfo *tk);                  // 鳴きアクション設定
	// void set_gui_ply_nak_action(MJSTkinfo *tk);                    // 鳴きアクション設定
	// void set_gui_ply_nakisute_action(MJSTkinfo *tk);               // 鳴きアクション設定

	// -----------------------------
	// プレイモード・卓処理
	// -----------------------------

	// GUIクラス卓初期化
	void guiTakuInit();
	void guiTakuPost();

	// 卓処理・メイン処理
	void guiTaku(MJSTkinfo *tk);                     // メイン処理
	void guiTakuChkPreClick(MJSTkinfo *tk);          // クリック前処理(メイン)
	void guiTakuActClick(MJSTkinfo *tk);             // クリック後処理(メイン)

	// 卓処理・手牌確認
	void guiChkPlyTsumoStat(MJSTkinfo *tk);          // プレーヤーの自摸状態確認
	void guiChkPlyNakiStat(MJSTkinfo *tk);           // プレーヤーの鳴き状態確認
	void guiChkPlyRonStat(MJSTkinfo *tk);            // プレーヤーのロン状態確認

	// 卓処理・自摸時
	void guiSetPlyNormalActMain(MJSTkinfo *tk);      // クリック後処理_通常画面・メイン処理
	void guiSetPlyNormalAct(MJSTkinfo *tk);          // クリック後処理_通常画面・プレーヤー通常アクション定義(mode:TEHAI_NORMAL)
	void guiSetPlyRiichiSutehaiAct(MJSTkinfo *tk);   // クリック後処理_通常画面・リーチ宣言後の捨牌選択(mode:TEHAI_RIICHI_SUTEHAI)
	void guiSetPlyRiichiYukoAct(MJSTkinfo *tk);      // クリック後処理_通常画面・リーチ有効後のアクション(自摸切り、自摸和了、アンカン)(mode:TEHAI_RIICHI_YUKO)
	void guiSetPlyAnkanKakanAct(MJSTkinfo *tk);      // クリック後処理_通常画面・プレーヤーアンカンアクション定義(mode:TEHAI_ANKAN_KAKAN_SELECT)

	// 卓処理・鳴きアクション決定
	void guiSetPlyNakiActMain(MJSTkinfo *tk);        // クリック後処理_鳴き画面・鳴きアクション・メイン処理
	void guiSetPlyNakiAct(MJSTkinfo *tk);            // クリック後処理_鳴き画面・鳴きアクション・サブ処理
	void guiSetPlyChiPaiAct(MJSTkinfo *tk);          // クリック後処理_鳴き画面・プレーヤーチーの1枚目の牌選択アクション(mode=11)
	void guiSetPlyChiPaiAct2(MJSTkinfo *tk);         // クリック後処理_鳴き画面・プレーヤーチーの2枚目の牌選択アクション(mode=12)

	// 卓処理・鳴き捨牌
	void guiSetPlyNakiSuteAct(MJSTkinfo *tk);        // クリック後処理_鳴き捨牌時

	// 卓処理・その他
	void guiPlyDetailInfo(MJSTkinfo *tk);            // クリック後処理_通常画面・ply情報画面操作(デバグ用)
	void guiKyokuEnd(MJSTkinfo *tk);                 // 局終了処理
	void guiTakuEnd(MJSTkinfo *tk);                  // 卓終了処理

	// -----------------------------
	// クライアントモード・卓処理
	// -----------------------------

	// クライアントモード・初期化
	void guiClientInit(MJSTkinfo *tk); 

	// クライアントモード・メイン処理
	void guiClientMain(MJSTkinfo *tk); 

	// クライアントモード・自摸時
	void guiClientSetPlyNormalActMain(MJSTkinfo *tk);       // クライアントモード・クリック後処理_通常画面・メイン処理
	void guiClientSetPlyNormalAct(MJSTkinfo *tk);           // クライアントモード・クリック後処理_通常画面・プレーヤー通常アクション定義(mode:TEHAI_NORMAL)
	void guiClientSetPlyRiichiSutehaiAct(MJSTkinfo *tk);    // クライアントモード・クリック後処理_通常画面・リーチ宣言後の捨牌選択(mode:TEHAI_RIICHI_SUTEHAI)
	void guiClientSetPlyRiichiYukoAct(MJSTkinfo *tk);       // クライアントモード・クリック後処理_通常画面・リーチ有効後のアクション(自摸切り、自摸和了、アンカン)(mode:TEHAI_RIICHI_YUKO)
	void guiClientSetPlyAnkanKakanAct(MJSTkinfo *tk);       // クライアントモード・クリック後処理_通常画面・プレーヤーアンカンアクション定義(mode:TEHAI_ANKAN_KAKAN_SELECT)

	// クライアントモード・鳴きアクション決定
	void guiClientSetPlyNakiActMain(MJSTkinfo *tk);         // クライアントモード・鳴きアクション・メイン処理
	void guiClientSetPlyNakiAct(MJSTkinfo *tk);             // クライアントモード・鳴きアクション・サブ処理
	void guiSetPlyChiHaiAct(MJSTkinfo *tk);                 // クライアントモード・チーの1枚目の牌選択アクション(mode=11)
	void guiSetPlyChiHaiAct2(MJSTkinfo *tk);                // クライアントモード・チーの2枚目の牌選択アクション(mode=12)

	// クライアントモード・鳴き捨牌
	void guiClienSetPlyNakiSuteAct(MJSTkinfo *tk);          // クライアントモード・鳴き捨牌

	// -----------------------------
	// 卓処理(ビューアーモード)
	// -----------------------------
	// ビューアー・初期化
	void guiViewerInitTaku(MJSTkinfo *tk);                  // ビューワーモードの初期化

	// ビューアー・メイン
	void guiViewerTaku(MJSTkinfo *tk);                      // メイン処理
	void count_plyact(MJSTkinfo *tk);                       // ACTIDのカウントアップ処理

	// -----------------------------
	// 卓処理(検証モード)
	// -----------------------------
	// 検証・初期化
	void guiRunningInit();                                  // 初期化処理

	// 検証・メイン処理
	void guiRunningMain(MJSTkinfo *tk);                     // メイン処理

};

#endif/* MJSMOUSE_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- */
// ソース終了
/* ---------------------------------------------------------------------------------------------- */
