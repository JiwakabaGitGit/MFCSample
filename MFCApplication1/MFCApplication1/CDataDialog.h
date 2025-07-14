#pragma once
#include "CTestDialog.h"

class CDataDialog : public CTestDialog
{
    DECLARE_DYNAMIC( CDataDialog );

public:
    CDataDialog(CWnd* pParent = nullptr);
    CDataDialog( UINT nIDTemplate, CWnd* pParent = nullptr );
    virtual ~CDataDialog();

    // ダイアログ データ (通常はリソースエディタで関連付けられるコントロール変数など)
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_PATHLOGDLG }; // 仮のダイアログID (必要に応じて変更)
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:
    void OnShowWindow( BOOL bShow, UINT nStatus );

    void CenterToParent();
    int GetWidth();
    int GetHeight();
    virtual BOOL OnInitDialog();
    afx_msg void OnSize( UINT nType, int cx, int cy );

private:
    CBrush m_brEdit;
    COLORREF	m_colEditText;
    COLORREF	m_colStaticText;// スタティックテキストのテキスト色
public:
    afx_msg HBRUSH OnCtlColor( CDC* pDC, CWnd* pWnd, UINT nCtlColor );
    virtual BOOL PreTranslateMessage( MSG* pMsg );
};

