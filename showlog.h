/* ---------------------------------------------------------------------------------------------- 
 * 
 * プログラム概要 ： Newさくら麻雀(MJAIクライアント実装版)
 * バージョン     ： 0.1.2.0.141(kyoku_index変数の共通化)
 * プログラム名   ： mjs.exe
 * ファイル名     ： showlog.h
 * クラス名       ： MJSShowlog
 * 処理概要       ： ログコアクラス(MJSログ関連)：廃止予定
 * 作成日         ： 2018/11/18 10:12:12
 * Ver0.0.1作成日 ： 2022/04/11 15:57:39
 * Ver0.1.2作成日 ： 2022/08/31 22:19:54
 * 最終更新日     ： 2024/04/24 00:17:30
 * 
 * Copyright (c) 2010-2024 Techmilestone, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#pragma once

#ifndef SHOWLOG_H_INCLUDED
#define SHOWLOG_H_INCLUDED

#include <windows.h>
#include "stdafx.h"

#include "tkinfo.h"

/* ---------------------------------------------------------------------------------------------- */
// クラス定義
/* ---------------------------------------------------------------------------------------------- */
class MJSShowlog
{

	/* ----------------------------- */
	// 公開関数定義
	/* ----------------------------- */
	public:

	// Windows用ログハンドル
	HANDLE   hFile;
	DWORD    dwBytes;

	// 作業用変数
	char tmp_msg[256]; // 一時処理用

	// 表示用麻雀牌
	char CharHai[41][4];
	char kyokutbl[12][8];

	/* ----------------------------- */
	// コンストラクタ
	/* ----------------------------- */

	// コンストラクタ定義
	MJSShowlog() {};

	// デストラクタ定義
	~MJSShowlog() {};

	// -----------------------------
	// 関数定義
	// -----------------------------

	// 全体処理
	void ShowlogInit(char *logname);        // ログ処理開始処理
	void ShowlogPost();                     // ログ処理終了処理

	// ファイル処理
	void ShowlogFileInit(char *logname);    // ファイル初期化
	void ShowlogFileClose();                // ファイルクローズ

	// ログ出力
	void ShowlogPrint(char *msg);           // ログ出力

	// 共通関数
	void ShowBorder();                      // 区切り線出力
	void ShowSpace();                       // 空白
	void ShowCR();                          // 改行
	void ShowTime();                        // 時間出力

	// -----------------------------
	// MJSログ出力関数
	// -----------------------------

	// メイン処理
	void ShowMJSlogMain(MJSTkinfo *tk, int log_ver1, int log_ver2, int log_ver3, int log_ver4);  // MJSログ出力メイン処理

	// サブ処理 - 卓開始
	void Showlog_000_MJSlogStart(int log_ver1, int log_ver2, int log_ver3, int log_ver4);        // 000：MJSログ開始
	void Showlog_011_TakuStart(MJSTkinfo *tk);                                                   // 011：卓開始
	void Showlog_012_PlayerInfo(MJSTkinfo *tk);                                                  // 012：プレーヤー情報

	// サブ処理 - 局情報
	void Showlog_101_KyokuStart(MJSTkinfo *tk, int kyoku_index);                                 // 101：局開始
	void Showlog_102_KyokuPlyInfo(MJSTkinfo *tk, int kyoku_index);                               // 102：局プレーヤー情報
	void Showlog_103_DoraInfo(MJSTkinfo *tk, int kyoku_index);                                   // 103：表ドラ情報
	void Showlog_11x_HaipaiInfo(MJSTkinfo *tk, int kyoku_index);                                 // 11x：配牌情報
	void Showlog_201_Actinfo(MJSTkinfo *tk, int kyoku_index);                                    // 201：アクション情報
	void Showlog_21x_Nakiinfo(MJSTkinfo *tk, int kyoku_index);                                   // 21x：鳴き情報
	void Showlog_901_AgariInfo(MJSTkinfo *tk, int kyoku_index);                                  // 901：和了情報
	void Showlog_902_YakuInfo(MJSTkinfo *tk, int kyoku_index);                                   // 902：役情報
	void Showlog_903_kyokuScore(MJSTkinfo *tk, int kyoku_index);                                 // 903：局の合計得点

	// サブ処理 - 卓終了
	void Showlog_911_TakuEndScore(MJSTkinfo *tk);                                                // 911：得点結果
	void Showlog_919_TakuEnd(MJSTkinfo *tk);                                                     // 919：卓終了
	void Showlog_999_MJSlogEnd(int log_ver1, int log_ver2, int log_ver3, int log_ver4);          // 999：MJSログ終了

};

#endif/* SHOWLOG_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- 
 * ソース終了
 * ---------------------------------------------------------------------------------------------- */
