/* ---------------------------------------------------------------------------------------------- 
 * 
 * プログラム概要 ： Newさくら麻雀(MJAIクライアント実装版)
 * バージョン     ： 0.1.2.0.196(tklogクラス実装)
 * プログラム名   ： mjs.exe
 * ファイル名     ： game.h
 * クラス名       ： MJSGame
 * 処理概要       ： メイン処理
 * Ver0.0.8作成日 ： 2012/07/29 11:09:51
 * Ver0.1.0作成日 ： 2022/05/03 18:50:06
 * Ver0.1.1作成日 ： 2022/06/30 21:19:01
 * Ver0.1.2作成日 ： 2022/08/31 22:19:54
 * Ver0.1.3.0pre  ： 2024/03/19 23:55:27
 * Ver0.1.3.1pre  ： 2024/04/05 19:50:22
 * 最終更新日     ： 2024/09/19 08:18:20
 * 
 * Copyright (c) 2010-2024 TechMileStoraJP, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#pragma once

#ifndef MJSGAME_H_INCLUDED
#define MJSGAME_H_INCLUDED

#include <windows.h>
#include "stdafx.h"
#include "DxLib.h"

#include "display.h"
#include "gui.h"

#include "taku.h"
#include "tkinfo.h"
#include "player.h"
#include "client.h"

#include "tklog.h"
#include "tpread.h"

/* ---------------------------------------------------------------------------------------------- */
// 固定値
/* ---------------------------------------------------------------------------------------------- */

// バージョン情報(MJSlog)

#define MJSLOG_VER1    0      // 1桁目のバージョン(公開向け)
#define MJSLOG_VER2    0      // 2桁目のバージョン(ログ出力の形式を全体的に見直した場合、互換性なし)
#define MJSLOG_VER3    1      // 3桁目のバージョン(ログ出力の形式を若干見直した場合、互換性あり)
#define MJSLOG_VER4    3      // 4桁目のバージョン(形式を変更しない細かな更新があった場合、互換性あり)

/* ---------------------------------------------------------------------------------------------- */
// クラス定義
/* ---------------------------------------------------------------------------------------------- */
class MJSGame
{

	// ------------------------------------------------------------------- 
	// バージョン情報
	// ------------------------------------------------------------------- 
	public:

	// バージョン情報
	int ver1;
	int ver2;
	int ver3;
	int ver4;
	int ver5;

	// バージョン情報(MJSlog)
	int log_ver1;
	int log_ver2;
	int log_ver3;
	int log_ver4;

	// ------------------------------------------------------------------- 
	// フレーム処理
	// ------------------------------------------------------------------- 

	// フレーム処理用定数
	int SAMPLE_FRAME_COUNT = 60;        // フレームのサンプル数
	int FPS                = 60;        // 想定のFPS値 (待ち時間の算出用)

	// FPS算出用変数(フレーム定義)
	int frame_count;                    // サンプルフレームのカウンタ数
	int total_frame_count;              // 処理したフレームの合計数

	// FPS算出用変数(時間定義)
	int checkpoint_time;                // 定点時刻(チェックポイントごとの時刻)
	int wait_time;                      // 待ち時間(Sleep関数を利用するために単位はミリ秒)

	// FPS算出用変数(FPS数)
	float ave_fps;                      // 実測のFPS値

	// ------------------------------------------------------------------- 
	// モード定義
	// ------------------------------------------------------------------- 

	// ビューアーモードの有無
	bool haifu_read_mode;

	// ------------------------------------------------------------------- 
	// クラス定義
	// ------------------------------------------------------------------- 

	// クラス定義
	MJSGui gui;                  // GUI操作クラス(マウス操作情報)
	MJSTkinfo tk;                // 卓情報クラス
	MJSTaku taku;                // 卓計算処理
	MJSPlayer* ply;              // プレーヤークラス(ポインタ定義)
	MJSDisplay dsp;              // ディスプレイクラス
	MJSMjaiClient cli;           // MJAIクライアントクラス
	MJSReadTplog tp;             // 東風荘ログ読込クラス
	MJSReadMjai mjai;            // MJAIログ読込みクラス
	MJSTklog log;                // ログクラス
	// MJSShowlog log;              // ログクラス

	/* ----------------------------- */
	// コンストラクタ
	/* ----------------------------- */

	// コンストラクタ定義
	MJSGame(){};

	// デストラクタ定義
	~MJSGame(){};

	/* ----------------------------- */
	// 関数定義
	/* ----------------------------- */

	// 全体処理
	void GameInit();               // 開始処理
	void GameExe();                // 実行処理
	void GameExe_ChkStat();        // ゲーム状態ごとに処理分岐
	void GamePost();               // 終了処理

	// Fps算出処理
	void FpsParamInit();
	void FpsUpdate();
	void FpsWait();

	// 卓ステータスの初期化と終了処理
	void GameTakuInit();
	void GameTakuPost();

	// オープニング画面
	void OpeningInit();
	void OpeningExe();
	void OpeningPost();

	// ゲームモード
	void PlayingInit();
	void PlayingExe();
	void PlayingPost();

	// ビューアーモード
	void ViewingInit();
	void ViewingExe();
	void ViewingPost();

	// 検証モード
	void RunningInit();
	void RunningExec();
	void RunningPost();

	// Mjaiクライアントモード
	void ClientInit();
	void ClientExec();
	void ClientPost();

	// Mjaiサーバモード
	void MJServerInit();
	void MJServerExe();
	void MJServerPost();

	// 設定画面
	void SettingInit();
	void SettingExe();
	void SettingPost();

};

#endif/* MJSGAME_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- */
// ソース終了
/* ---------------------------------------------------------------------------------------------- */
