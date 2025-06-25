#pragma once


// CTestDialog ダイアログ

class CTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDialog)

public:
	CTestDialog(CWnd* pParent = nullptr);   // 標準コンストラクター
	CTestDialog( UINT nIDTemplate, CWnd* pParent = nullptr );

	virtual ~CTestDialog();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

	afx_msg void OnShowWindow( BOOL bShow, UINT nStatus );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
