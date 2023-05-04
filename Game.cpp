﻿#include "Game.h"
#include <easyx.h>

Game::Game() {
	initgraph(600, 600);
	// 设置当前设备图案填充和文字输出时的背景模式为透明
	setbkmode(TRANSPARENT);

	chessBoard = new ChessBoard();
}

Game::~Game() {
	EndBatchDraw();
	closegraph();
}

void Game::handleInput() {
	// 获取鼠标信息
	ExMessage mouse = getmessage(EX_MOUSE);
	chessBoard->setHoverPoint({ mouse.x, mouse.y });
	if (mouse.lbutton) {
		chessBoard->setClickPoint({ mouse.x, mouse.y });
	}
	// 如果能放
	//if (chessBoard->canPut()) {
	//	// 则放
	//	chessBoard->putChess({ 0, 0 }, BLACK);
	//	
	//}
}

void Game::update() {
	// 判断输赢
}

void Game::render() {
	// 使用白色背景清空屏幕
	setbkcolor(WHITE);
	cleardevice();

	// 开始批量绘画
	BeginBatchDraw();
	chessBoard->render();

	FlushBatchDraw();
}