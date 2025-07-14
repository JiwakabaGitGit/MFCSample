// CDataDialog.cpp : 実装ファイル
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CDataDialog.h"
#include "afxdialogex.h"
#include "resource.h"

// CDataDialog ダイアログ

IMPLEMENT_DYNAMIC(CDataDialog, CDialogEx)

CDataDialog::CDataDialog(CWnd* pParent /*=nullptr*/)
	: CTestDialog(IDD_DIALOG1, pParent)
{
    m_brEdit.CreateSolidBrush( RGB( 255, 255, 255 ) );
    m_colEditText = RGB( 0, 0, 0 );
    m_colStaticText = RGB( 0, 0, 0 );
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
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDataDialog メッセージ ハンドラー

void CDataDialog::OnShowWindow( BOOL bShow, UINT nStatus )
{
	this->ShowWindow( SW_SHOW );

}

void CDataDialog::CenterToParent()
{
   CWnd* pParent = GetParent();
    //if( !pParent || !::IsWindow( pParent->GetSafeHwnd() ) )
    //    return;

    //CRect rcParent;
    //pParent->GetWindowRect( &rcParent );

    //int x = rcParent.left + ( rcParent.Width() - this->GetWidth() ) / 2;
    //int y = rcParent.top + ( rcParent.Height() - this->GetHeight() ) / 2;
    ////int x = 0;
    ////int y = 0;
    //SetWindowPos( nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER );


    CWnd* pTagControl = pParent->GetDlgItem( IDC_TAB1 );
    if( pTagControl  == nullptr ) return;

    CRect targetRect;
    pTagControl->GetWindowRect( &targetRect );



    int x = targetRect.left + ( targetRect.Width() - this->GetWidth() ) / 2;
    int y = targetRect.top + ( targetRect.Height() - this->GetHeight() ) / 2;

    SetWindowPos( nullptr, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_SHOWWINDOW );
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
    
    CEdit* pedt = ( CEdit* )GetDlgItem( IDC_EDIT1 );
    pedt->SetReadOnly();
    pedt->SetWindowText( _T( "123456" ) );

    pedt = ( CEdit* )GetDlgItem( IDC_EDIT2 );
    pedt->SetWindowText( _T( "012012" ) );
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


HBRUSH CDataDialog::OnCtlColor( CDC* pDC, CWnd* pWnd, UINT nCtlColor )
{
    HBRUSH hbr = CTestDialog::OnCtlColor( pDC, pWnd, nCtlColor );
#if 0
    // TODO: ここで DC の属性を変更してください。
    switch( nCtlColor )
    {
        // エディットボックス
        case CTLCOLOR_STATIC:
            // 読み取り専用エディットボックス
            if( IDC_EDIT1 == pWnd->GetDlgCtrlID() )
            {
                pDC->SetBkMode( OPAQUE );
                pDC->SetBkColor( RGB( 255, 255, 255 ) );
                pDC->SetTextColor( m_colEditText );
                hbr = m_brEdit;
            }
            break;
        default:
            break;
    }
#endif
    // TODO: 既定値を使用したくない場合は別のブラシを返します。
    return hbr;
}


BOOL CDataDialog::PreTranslateMessage( MSG* pMsg )
{
    // TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。
    if( ( pMsg->message == WM_KEYDOWN || pMsg->message == WM_CHAR ) &&
        ( pMsg->hwnd == GetDlgItem( IDC_EDIT2 )->GetSafeHwnd() ||
        pMsg->hwnd == GetDlgItem( IDC_EDIT3 )->GetSafeHwnd() ) )
    {
        return TRUE; // 入力を無効化（メッセージを握りつぶす）
    }

    return CTestDialog::PreTranslateMessage( pMsg );
}
