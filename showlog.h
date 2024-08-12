/* ---------------------------------------------------------------------------------------------- 
 * 
 * �v���O�����T�v �F New�����疃��(MJAI�N���C�A���g������)
 * �o�[�W����     �F 0.1.2.0.141(kyoku_index�ϐ��̋��ʉ�)
 * �v���O������   �F mjs.exe
 * �t�@�C����     �F showlog.h
 * �N���X��       �F MJSShowlog
 * �����T�v       �F ���O�R�A�N���X(MJS���O�֘A)�F�p�~�\��
 * �쐬��         �F 2018/11/18 10:12:12
 * Ver0.0.1�쐬�� �F 2022/04/11 15:57:39
 * Ver0.1.2�쐬�� �F 2022/08/31 22:19:54
 * �ŏI�X�V��     �F 2024/04/24 00:17:30
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
// �N���X��`
/* ---------------------------------------------------------------------------------------------- */
class MJSShowlog
{

	/* ----------------------------- */
	// ���J�֐���`
	/* ----------------------------- */
	public:

	// Windows�p���O�n���h��
	HANDLE   hFile;
	DWORD    dwBytes;

	// ��Ɨp�ϐ�
	char tmp_msg[256]; // �ꎞ�����p

	// �\���p�����v
	char CharHai[41][4];
	char kyokutbl[12][8];

	/* ----------------------------- */
	// �R���X�g���N�^
	/* ----------------------------- */

	// �R���X�g���N�^��`
	MJSShowlog() {};

	// �f�X�g���N�^��`
	~MJSShowlog() {};

	// -----------------------------
	// �֐���`
	// -----------------------------

	// �S�̏���
	void ShowlogInit(char *logname);        // ���O�����J�n����
	void ShowlogPost();                     // ���O�����I������

	// �t�@�C������
	void ShowlogFileInit(char *logname);    // �t�@�C��������
	void ShowlogFileClose();                // �t�@�C���N���[�Y

	// ���O�o��
	void ShowlogPrint(char *msg);           // ���O�o��

	// ���ʊ֐�
	void ShowBorder();                      // ��؂���o��
	void ShowSpace();                       // ��
	void ShowCR();                          // ���s
	void ShowTime();                        // ���ԏo��

	// -----------------------------
	// MJS���O�o�͊֐�
	// -----------------------------

	// ���C������
	void ShowMJSlogMain(MJSTkinfo *tk, int log_ver1, int log_ver2, int log_ver3, int log_ver4);  // MJS���O�o�̓��C������

	// �T�u���� - ��J�n
	void Showlog_000_MJSlogStart(int log_ver1, int log_ver2, int log_ver3, int log_ver4);        // 000�FMJS���O�J�n
	void Showlog_011_TakuStart(MJSTkinfo *tk);                                                   // 011�F��J�n
	void Showlog_012_PlayerInfo(MJSTkinfo *tk);                                                  // 012�F�v���[���[���

	// �T�u���� - �Ǐ��
	void Showlog_101_KyokuStart(MJSTkinfo *tk, int kyoku_index);                                 // 101�F�ǊJ�n
	void Showlog_102_KyokuPlyInfo(MJSTkinfo *tk, int kyoku_index);                               // 102�F�ǃv���[���[���
	void Showlog_103_DoraInfo(MJSTkinfo *tk, int kyoku_index);                                   // 103�F�\�h�����
	void Showlog_11x_HaipaiInfo(MJSTkinfo *tk, int kyoku_index);                                 // 11x�F�z�v���
	void Showlog_201_Actinfo(MJSTkinfo *tk, int kyoku_index);                                    // 201�F�A�N�V�������
	void Showlog_21x_Nakiinfo(MJSTkinfo *tk, int kyoku_index);                                   // 21x�F�����
	void Showlog_901_AgariInfo(MJSTkinfo *tk, int kyoku_index);                                  // 901�F�a�����
	void Showlog_902_YakuInfo(MJSTkinfo *tk, int kyoku_index);                                   // 902�F�����
	void Showlog_903_kyokuScore(MJSTkinfo *tk, int kyoku_index);                                 // 903�F�ǂ̍��v���_

	// �T�u���� - ��I��
	void Showlog_911_TakuEndScore(MJSTkinfo *tk);                                                // 911�F���_����
	void Showlog_919_TakuEnd(MJSTkinfo *tk);                                                     // 919�F��I��
	void Showlog_999_MJSlogEnd(int log_ver1, int log_ver2, int log_ver3, int log_ver4);          // 999�FMJS���O�I��

};

#endif/* SHOWLOG_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- 
 * �\�[�X�I��
 * ---------------------------------------------------------------------------------------------- */
