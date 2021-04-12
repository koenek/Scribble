#pragma once


// CPenWidthsDlg dialog

class CPenWidthsDlg : public CDialog
{
	DECLARE_DYNAMIC(CPenWidthsDlg)

public:
	CPenWidthsDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPenWidthsDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PEN_WIDTHS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDefaultPenWidths();
	int m_nThinWidth;
	int m_nThickWidth;
};
