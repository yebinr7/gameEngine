// gameEngine.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#include "pch.h"
#include "framework.h"
#include "gameEngine.h"
//테스트 
#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GAMEENGINE, szWindowClass, MAX_LOADSTRING);
   
    //1) 윈도우 창 정보 등록 ::없으면 우리가 만든거 
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    //2) 윈도우 창 생성 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMEENGINE));

    MSG msg;

    // 기본 메시지 루프입니다:
    //3)  메인 루프 
    while (true)
    {
        if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))//메세지가 없으면 false리턴 
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {

        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
#pragma region MyResgisterClass가 무엇인가?
/*
 RegisterClassExW는 Microsoft의 Windows API에 포함된 함수 중 하나로,창 클래스를 등록하는 데 사용됩니다.
이 함수를 호출하면, 운영 체제는 해당 클래스를 식별하고, 이후 해당 클래스를 사용하여 창을 생성할 수 있게 됩니다.

RegisterClassExW 함수는 WNDCLASSEXW 구조체를 매개변수로 받습니다.
이 구조체에는 창 클래스의 여러 가지 속성을 정의하는 필드들이 포함되어 있습니다.
이 필드에는 창의 배경 브러시, 커서, 아이콘, 메뉴, 클래스 이름 등을 설정할 수 있습니다.

그리고 이 함수의 이름에서 'W'는 Wide의 약자로, ;;와이드바이트? 고정길이 2byte 영어나 한국어 차별 x
이 함수가 유니코드 문자열을 지원함을 나타냅니다.
Windows API에는 문자열에 대해 ANSI 버전 함수와
유니코드 버전 함수를 모두 제공하는데, 'W'가 붙은 함수는 유니코드 버전 함수를 의미합니다.

따라서 RegisterClassExW 함수는 창 클래스를 운영 체제에 등록하고, 이 클래스를 이용해 창을 생성하고 관리하는 기능을 제공하는 것이죠.

*/

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAMEENGINE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr; //MAKEINTRESOURCEW(IDC_GAMECODING); //menu없애고 싶으면 nullptr
    wcex.lpszClassName  = L"GameCoding"; //키값 
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
#pragma region AdjustWindow 설명
   /*
   * AdjustWindowRect는 Windows API의 함수 중 하나로,
   주어진 클라이언트 영역의 크기에 필요한 전체 창 크기를 계산하는 데 사용됩니다.

클라이언트 영역이란 창의 내부 영역으로
, 메뉴, 스크롤 바, 테두리 등이 아닌 사용자가 직접 볼 수 있는 영역을 말합니다.

이 함수는 RECT 구조체를 매개변수로 받아
, 클라이언트 영역의 크기를 기반으로 창의 전체 크기를 계산하고,
그 결과를 다시 RECT 구조체에 저장합니다.
이때 창 스타일과 메뉴가 있을 경우 그것들이 창 크기에 미치는 영향을 고려하여 계산합니다.

따라서 AdjustWindowRect 함수는 주어진 클라이언트 영역에 맞는 창의 크기를 계산하는 데 사용되며,
이를 통해 원하는 크기의 클라이언트 영역을 가진 창을 정확하게 생성할 수 있습니다.
   */
#pragma endregion

   RECT windowRect = { 0,0,800,600 };
   ::AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);


   //내가 원하는 구조체 대로 윈도우창 만들어줘라 !!! 핵심 
       //창의 크기 조절 
   HWND hWnd = CreateWindowW(L"GameCoding", L"Client", WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, windowRect.right - windowRect.left,
       windowRect.bottom - windowRect.top, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
