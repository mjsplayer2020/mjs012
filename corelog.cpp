/* ---------------------------------------------------------------------------------------------- 
 * 
 * プログラム概要 ： さくら麻雀(Ver0.1.2：開発版)
 * バージョン     ： 0.1.2.0.195(卓ログ、クライアントログの無効化)
 * プログラム名   ： mjs.exe
 * ファイル名     ： corelog.cpp
 * クラス名       ： MJSCorelog
 * 処理概要       ： ログコアクラス(MJSログ関連)
 * 0.1.2版作成日  ： 2023/10/14 16:55:10
 * 最終更新日     ： 2024/09/16 15:51:09
 * 
 * Copyright (c) 2010-2024 TechMileStoraJP, All rights reserved.
 * 
 * ---------------------------------------------------------------------------------------------- */

#include "corelog.h"

/* ---------------------------------------------------------------------------------------------- */
// ログ処理開始処理
/* ---------------------------------------------------------------------------------------------- */
void MJSCorelog::CorelogInit(char *tmp_logname){

	// ログファイル名設定
	wsprintf(logname, tmp_logname);

	// ファイル初期化
	// CorelogFileInit(logname);

}

/* ---------------------------------------------------------------------------------------------- */
// ログ処理終了処理
/* ---------------------------------------------------------------------------------------------- */
void MJSCorelog::CorelogPost(){

	// ファイルクローズ
	// CorelogFileClose();

}

/* ---------------------------------------------------------------------------------------------- */
// ファイル初期化
/* ---------------------------------------------------------------------------------------------- */
void MJSCorelog::CorelogFileInit(){

	// ファイルポイント定義
	hFile = CreateFile( logname, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );

	// 処理確認
	if (hFile == INVALID_HANDLE_VALUE) {
		MessageBox(NULL, "ファイル読込エラーです", "メッセージ", MB_OK);
	}

	// ポインタを一番最後にして追記書きこみ
	SetFilePointer( hFile, 0, NULL, FILE_END );

}

/* ---------------------------------------------------------------------------------------------- */
// ファイルクローズ
/* ---------------------------------------------------------------------------------------------- */
void MJSCorelog::CorelogFileClose(){

	// ファイルクローズ
	CloseHandle(hFile);

}

/* ---------------------------------------------------------------------------------------------- */
// ログ出力・メイン処理
/* ---------------------------------------------------------------------------------------------- */
void MJSCorelog::CorelogPrint(char *msg){

	// ファイル初期化
	CorelogFileInit();

	// 書きこみ処理開始
	WriteFile(hFile, msg, (DWORD)strlen(msg), &dwBytes, NULL);

	// ファイルクローズ
	CloseHandle(hFile);

}

/* ---------------------------------------------------------------------------------------------- */
// 区切り線出力
/* ---------------------------------------------------------------------------------------------- */
void MJSCorelog::PrintBorder(){

	wsprintf(tmp_msg, "---------------------------------------------------------------");
	CorelogPrint(tmp_msg);
	PrintCR();

}

/* ---------------------------------------------------------------------------------------------- */
// 空白出力
/* ---------------------------------------------------------------------------------------------- */
void MJSCorelog::PrintSpace(){

	wsprintf(tmp_msg, "　");
	CorelogPrint(tmp_msg);

}

/* ---------------------------------------------------------------------------------------------- */
// 改行出力
/* ---------------------------------------------------------------------------------------------- */
void MJSCorelog::PrintCR(){

	wsprintf(tmp_msg, "\n");
	CorelogPrint(tmp_msg);

}

/* ---------------------------------------------------------------------------------------------- */
// 時間出力
/* ---------------------------------------------------------------------------------------------- */
void MJSCorelog::PrintTime(){

	// 関数定義 

    time_t jikan = time(NULL);
    struct tm imanojikan;
	errno_t error;

	int year, mon, day;
	int hour, min, sec;

	// 現在の日時を取得 
	error = localtime_s(&imanojikan, &jikan);

	year = imanojikan.tm_year + 1900;
	mon  = imanojikan.tm_mon  + 1;
	day  = imanojikan.tm_mday ;

	hour = imanojikan.tm_hour;
	min  = imanojikan.tm_min;
	sec  = imanojikan.tm_sec;

	// 文字列代入
	wsprintf(tmp_msg,"%d/%02d/%02d %02d:%02d:%02d",year,mon,day,hour,min,sec);
	CorelogPrint(tmp_msg);

}

/* ---------------------------------------------------------------------------------------------- */
// ソース終了
/* ---------------------------------------------------------------------------------------------- */
