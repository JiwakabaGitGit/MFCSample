// CTestDialog.cpp : 実装ファイル
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CTestDialog.h"
#include "afxdialogex.h"


// CTestDialog ダイアログ

IMPLEMENT_DYNAMIC(CTestDialog, CDialogEx)

CTestDialog::CTestDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

// リソースIDを指定するコンストラクタ
CTestDialog::CTestDialog( UINT nIDTemplate, CWnd* pParent /*=nullptr*/ )
	: CDialogEx( nIDTemplate, pParent ) // 親クラスのコンストラクタを呼び出し
{
	// 初期化コード
}

CTestDialog::~CTestDialog()
{
}

void CTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDialog, CDialogEx)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED( IDC_BUTTON1, &CTestDialog::OnBnClickedButton1 )
END_MESSAGE_MAP()


// CTestDialog メッセージ ハンドラー

void CTestDialog::OnShowWindow( BOOL bShow, UINT nStatus )
{
	this->ShowWindow( SW_SHOW );
	this->SetWindowTextW( _T( "aaaa" ) );
	this->CenterWindow();
}


void CTestDialog::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}
