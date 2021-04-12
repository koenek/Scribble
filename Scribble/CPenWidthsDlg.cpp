// CPenWidthsDlg.cpp : implementation file
//

#include "pch.h"
#include "Scribble.h"
#include "CPenWidthsDlg.h"
#include "afxdialogex.h"


// CPenWidthsDlg dialog

IMPLEMENT_DYNAMIC(CPenWidthsDlg, CDialog)

CPenWidthsDlg::CPenWidthsDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PEN_WIDTHS, pParent)
	, m_nThinWidth(0)
	, m_nThickWidth(0)
{

}

CPenWidthsDlg::~CPenWidthsDlg()
{
}

void CPenWidthsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_THIN_PEN_WIDTH, m_nThinWidth);
	DDV_MinMaxInt(pDX, m_nThinWidth, 1, 20);
	DDX_Text(pDX, IDC_THICK_PEN_WIDTH, m_nThickWidth);
	DDV_MinMaxInt(pDX, m_nThickWidth, 1, 20);
}


BEGIN_MESSAGE_MAP(CPenWidthsDlg, CDialog)
	ON_BN_CLICKED(IDC_DEFAULT_PEN_WIDTHS, &CPenWidthsDlg::OnDefaultPenWidths)
END_MESSAGE_MAP()


// CPenWidthsDlg message handlers


void CPenWidthsDlg::OnDefaultPenWidths()
{
	m_nThinWidth = 2;
	m_nThickWidth = 5;
	UpdateData(FALSE); // causes DoDataExchange()
	// bSave=FALSE means don't save from screen, rather, write
	// to screen
}
