
// MFCApplication1Dlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "CTestDialog.h"
#include "CDataDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg ダイアログ



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange( pDX );
	DDX_Control( pDX, IDC_TAB1, AAA );
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED( IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1 )
	ON_BN_CLICKED( IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2 )
	ON_WM_SIZE()
	ON_NOTIFY( TCN_SELCHANGE, IDC_TAB1, &CMFCApplication1Dlg::OnTcnSelchangeTab1 )
END_MESSAGE_MAP()


// CMFCApplication1Dlg メッセージ ハンドラー

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CTestDialog dlg;
	INT_PTR nRes = dlg.DoModal();
	if( nRes == IDOK )
	{	// "OK"(ダイアログ上のどこかをクリックした)時.
		AfxMessageBox( _T( "OK" ), MB_OK | MB_ICONASTERISK );	// AfxMessageBoxで"OK"と表示.
	}
	else if( nRes == IDCANCEL )
	{	// "キャンセル"(閉じるボタンを押した)時.
		AfxMessageBox( _T( "キャンセル" ), MB_OK | MB_ICONEXCLAMATION );	// AfxMessageBoxで"キャンセル"と表示.
	}
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CDataDialog dlg;


	INT_PTR nRes = dlg.DoModal();
	if( nRes == IDOK )
	{	// "OK"(ダイアログ上のどこかをクリックした)時.
		AfxMessageBox( _T( "OK" ), MB_OK | MB_ICONASTERISK );	// AfxMessageBoxで"OK"と表示.
	}
	else if( nRes == IDCANCEL )
	{	// "キャンセル"(閉じるボタンを押した)時.
		AfxMessageBox( _T( "キャンセル" ), MB_OK | MB_ICONEXCLAMATION );	// AfxMessageBoxで"キャンセル"と表示.
	}
}



void CMFCApplication1Dlg::OnSize( UINT nType, int cx, int cy )
{
	CDialogEx::OnSize( nType, cx, cy );

	// TODO: ここにメッセージ ハンドラー コードを追加します。
	if( GetSafeHwnd() == nullptr ) return;

	CWnd* pButton = GetDlgItem( IDC_BUTTON1 );
	if( pButton )
	{
		CRect rect;
		GetClientRect( &rect );

		// たとえばダイアログの幅に合わせてボタンの幅を拡張する
		int btnHeight = 30;
		int margin = 10;
		pButton->MoveWindow(
			margin,
			rect.bottom - btnHeight - margin,
			rect.Width() - 2 * margin,
			btnHeight
		);
	}
}


void CMFCApplication1Dlg::OnTcnSelchangeTab1( NMHDR* pNMHDR, LRESULT* pResult )
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	*pResult = 0;
}
