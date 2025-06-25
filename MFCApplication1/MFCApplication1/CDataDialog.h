#pragma once
#include "CTestDialog.h"

class CDataDialog : public CTestDialog
{
    DECLARE_DYNAMIC( CDataDialog );

public:
    CDataDialog(CWnd* pParent = nullptr);
    CDataDialog( UINT nIDTemplate, CWnd* pParent = nullptr );
    virtual ~CDataDialog();

    // �_�C�A���O �f�[�^ (�ʏ�̓��\�[�X�G�f�B�^�Ŋ֘A�t������R���g���[���ϐ��Ȃ�)
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_PATHLOGDLG }; // ���̃_�C�A���OID (�K�v�ɉ����ĕύX)
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
};

