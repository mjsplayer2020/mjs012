/* ---------------------------------------------------------------------------------------------- 
 * 
 * �v���O�����T�v �F New�����疃��(MJAI�N���C�A���g������)
 * �o�[�W����     �F 0.1.2.0.196(tklog�N���X����)
 * �v���O������   �F mjs.exe
 * �t�@�C����     �F game.h
 * �N���X��       �F MJSGame
 * �����T�v       �F ���C������
 * Ver0.0.8�쐬�� �F 2012/07/29 11:09:51
 * Ver0.1.0�쐬�� �F 2022/05/03 18:50:06
 * Ver0.1.1�쐬�� �F 2022/06/30 21:19:01
 * Ver0.1.2�쐬�� �F 2022/08/31 22:19:54
 * Ver0.1.3.0pre  �F 2024/03/19 23:55:27
 * Ver0.1.3.1pre  �F 2024/04/05 19:50:22
 * �ŏI�X�V��     �F 2024/09/19 08:18:20
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
// �Œ�l
/* ---------------------------------------------------------------------------------------------- */

// �o�[�W�������(MJSlog)

#define MJSLOG_VER1    0      // 1���ڂ̃o�[�W����(���J����)
#define MJSLOG_VER2    0      // 2���ڂ̃o�[�W����(���O�o�͂̌`����S�̓I�Ɍ��������ꍇ�A�݊����Ȃ�)
#define MJSLOG_VER3    1      // 3���ڂ̃o�[�W����(���O�o�͂̌`�����኱���������ꍇ�A�݊�������)
#define MJSLOG_VER4    3      // 4���ڂ̃o�[�W����(�`����ύX���Ȃ��ׂ��ȍX�V���������ꍇ�A�݊�������)

/* ---------------------------------------------------------------------------------------------- */
// �N���X��`
/* ---------------------------------------------------------------------------------------------- */
class MJSGame
{

	// ------------------------------------------------------------------- 
	// �o�[�W�������
	// ------------------------------------------------------------------- 
	public:

	// �o�[�W�������
	int ver1;
	int ver2;
	int ver3;
	int ver4;
	int ver5;

	// �o�[�W�������(MJSlog)
	int log_ver1;
	int log_ver2;
	int log_ver3;
	int log_ver4;

	// ------------------------------------------------------------------- 
	// �t���[������
	// ------------------------------------------------------------------- 

	// �t���[�������p�萔
	int SAMPLE_FRAME_COUNT = 60;        // �t���[���̃T���v����
	int FPS                = 60;        // �z���FPS�l (�҂����Ԃ̎Z�o�p)

	// FPS�Z�o�p�ϐ�(�t���[����`)
	int frame_count;                    // �T���v���t���[���̃J�E���^��
	int total_frame_count;              // ���������t���[���̍��v��

	// FPS�Z�o�p�ϐ�(���Ԓ�`)
	int checkpoint_time;                // ��_����(�`�F�b�N�|�C���g���Ƃ̎���)
	int wait_time;                      // �҂�����(Sleep�֐��𗘗p���邽�߂ɒP�ʂ̓~���b)

	// FPS�Z�o�p�ϐ�(FPS��)
	float ave_fps;                      // ������FPS�l

	// ------------------------------------------------------------------- 
	// ���[�h��`
	// ------------------------------------------------------------------- 

	// �r���[�A�[���[�h�̗L��
	bool haifu_read_mode;

	// ------------------------------------------------------------------- 
	// �N���X��`
	// ------------------------------------------------------------------- 

	// �N���X��`
	MJSGui gui;                  // GUI����N���X(�}�E�X������)
	MJSTkinfo tk;                // ����N���X
	MJSTaku taku;                // ��v�Z����
	MJSPlayer* ply;              // �v���[���[�N���X(�|�C���^��`)
	MJSDisplay dsp;              // �f�B�X�v���C�N���X
	MJSMjaiClient cli;           // MJAI�N���C�A���g�N���X
	MJSReadTplog tp;             // ���������O�Ǎ��N���X
	MJSReadMjai mjai;            // MJAI���O�Ǎ��݃N���X
	MJSTklog log;                // ���O�N���X
	// MJSShowlog log;              // ���O�N���X

	/* ----------------------------- */
	// �R���X�g���N�^
	/* ----------------------------- */

	// �R���X�g���N�^��`
	MJSGame(){};

	// �f�X�g���N�^��`
	~MJSGame(){};

	/* ----------------------------- */
	// �֐���`
	/* ----------------------------- */

	// �S�̏���
	void GameInit();               // �J�n����
	void GameExe();                // ���s����
	void GameExe_ChkStat();        // �Q�[����Ԃ��Ƃɏ�������
	void GamePost();               // �I������

	// Fps�Z�o����
	void FpsParamInit();
	void FpsUpdate();
	void FpsWait();

	// ��X�e�[�^�X�̏������ƏI������
	void GameTakuInit();
	void GameTakuPost();

	// �I�[�v�j���O���
	void OpeningInit();
	void OpeningExe();
	void OpeningPost();

	// �Q�[�����[�h
	void PlayingInit();
	void PlayingExe();
	void PlayingPost();

	// �r���[�A�[���[�h
	void ViewingInit();
	void ViewingExe();
	void ViewingPost();

	// ���؃��[�h
	void RunningInit();
	void RunningExec();
	void RunningPost();

	// Mjai�N���C�A���g���[�h
	void ClientInit();
	void ClientExec();
	void ClientPost();

	// Mjai�T�[�o���[�h
	void MJServerInit();
	void MJServerExe();
	void MJServerPost();

	// �ݒ���
	void SettingInit();
	void SettingExe();
	void SettingPost();

};

#endif/* MJSGAME_H_INCLUDED */

/* ---------------------------------------------------------------------------------------------- */
// �\�[�X�I��
/* ---------------------------------------------------------------------------------------------- */
