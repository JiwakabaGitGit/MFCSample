// CDataDialog.cpp : 実装ファイル
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CDataDialog.h"
#include "afxdialogex.h"


// CDataDialog ダイアログ

IMPLEMENT_DYNAMIC(CDataDialog, CDialogEx)

CDataDialog::CDataDialog(CWnd* pParent /*=nullptr*/)
	: CTestDialog(IDD_DIALOG1, pParent)
{

}

// リソースIDを指定するコンストラクタ
CDataDialog::CDataDialog( UINT nIDTemplate, CWnd* pParent /*=nullptr*/ )
	: CTestDialog( nIDTemplate, pParent ) // 親クラスのコンストラクタを呼び出し
{
	// 初期化コード
}

CDataDialog::~CDataDialog()
{
}

void CDataDialog::DoDataExchange(CDataExchange* pDX)
{
	CTestDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDataDialog, CDialogEx)
	ON_WM_SHOWWINDOW()
    ON_WM_SIZE()
END_MESSAGE_MAP()


// CDataDialog メッセージ ハンドラー

void CDataDialog::OnShowWindow( BOOL bShow, UINT nStatus )
{
	this->ShowWindow( SW_SHOW );

}

void CDataDialog::CenterToParent()
{
    CWnd* pParent = GetParent();
    if( !pParent || !::IsWindow( pParent->GetSafeHwnd() ) )
        return;

    CRect rcParent;
    pParent->GetWindowRect( &rcParent );

    int x = rcParent.left + ( rcParent.Width() - this->GetWidth() ) / 2;
    int y = rcParent.top + ( rcParent.Height() - this->GetHeight() ) / 2;
    //int x = 0;
    //int y = 0;
    SetWindowPos( nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
}

int CDataDialog::GetWidth()
{
    CRect rect;
    GetWindowRect( &rect );
    return rect.Width();
}

int CDataDialog::GetHeight()
{
    CRect rect;
    GetWindowRect( &rect );
    return rect.Height();
}


BOOL CDataDialog::OnInitDialog()
{
    CTestDialog::OnInitDialog();

    // TODO: ここに初期化を追加してください
    CenterToParent(); // 表示前に中央へ移動
    return TRUE;  // return TRUE unless you set the focus to a control
                  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void CDataDialog::OnSize( UINT nType, int cx, int cy )
{
    CTestDialog::OnSize( nType, cx, cy );

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
