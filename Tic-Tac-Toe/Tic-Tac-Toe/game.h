//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: game.h
// Description	: Header file for CGame class
// Author		: Lance Chaney
// Mail			: lance.cha7337@mediadesign.school.nz
//

#if !defined(__GAME_H__)
#define __GAME_H__

// Library Includes
#define NOMINMAX
#include <windows.h>
#include <array>

// Local Includes
#include "clock.h"
#include "sprite.h"
#include "GameState.h"
#include "utils.h"

// Types

// Constants

// Prototypes
class CBackBuffer;

class CGame
{
    // Member Functions
public:
    ~CGame();

    bool Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight);

    void Draw();
    void Process(float _fDeltaTick);

    void ExecuteOneFrame();

    CBackBuffer* GetBackBuffer();
    HINSTANCE GetAppInstance();
    HWND GetWindow();

    // Singleton Methods
    static CGame& GetInstance();
    static void DestroyInstance();

	void HandleClick();
	EWIN_STATE CheckWinCondition();
	void SetPlayMode(EPLAY_MODE playMode);
	void Restart();
	
	static ETOKEN_TYPE GetPlayerToken(size_t playerId);

protected:

private:
    CGame();
    CGame(const CGame& _kr);
    CGame& operator= (const CGame& _kr);

	// Check for a win condition along the specified diagonal
	// offDiagonal: true or false, whether we are checking the off diagonal for the win condition
	EWIN_STATE CheckDiagWinCondition(bool offDiagonal = false);

    // Member Variables
public:

protected:
    CClock* m_pClock;

    CBackBuffer* m_pBackBuffer;

	CGameState m_state;
	CSprite m_boardSprite;
	CSprite m_noughtSprite;
	CSprite m_crossSprite;

	std::array<EPLAYER_TYPE, 2> m_turnOrder;
	EPLAY_MODE m_playMode;

	static const int s_kBoardOffsetX;
	static const int s_kBoardOffsetY;
	static const int s_kBoardDividerWidth;
	static const int s_kBoardCellSize;

    //Application data
    HINSTANCE m_hApplicationInstance;
    HWND m_hMainWindow;

    // Singleton Instance
    static CGame* s_pGame;

private:

};

#endif    // __GAME_H__
