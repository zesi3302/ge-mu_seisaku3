#pragma once
#include <DxLib.h>

#define DEBUG
//定義関連----------------------

static int WINDOW_SIZE_X = 960;
static int WINDOW_SIZE_Y = 960;

//画面の中心座標
const int WINDOW_SENTER_X = static_cast<int>(WINDOW_SIZE_X * 0.5);
const int WINDOW_SENTER_Y = static_cast<int>(WINDOW_SIZE_Y * 0.5);
//------------------------------

static const VECTOR ZERO = { 0.0f,0.0f,0.0f };

static const int OBJECT_SIZE = 10;