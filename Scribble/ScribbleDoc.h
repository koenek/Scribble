
// ScribbleDoc.h : interface of the CScribbleDoc class
//


#pragma once

/////////////////////////////////////////////////////
// class CStroke
// A stroke is a series of connected points in the Scribble drawing.
// A Scribble document may have multiple strokes.
class CStroke : public CObject
{
public:
	CStroke(UINT nPenWidth);

protected:
	CStroke();
	DECLARE_SERIAL(CStroke)

	// Attributes
protected:
	UINT	m_nPenWidth; // One width applies to entire stroke
public:
	CArray<CPoint, CPoint> m_pointArray; // Series of connected points

protected:
	CRect m_rectBounding; // smallest rect that surrounds all
		// of the points in the stroke
public:
	CRect& GetBoundingRect() { return m_rectBounding; }

	// Operations
public:
	BOOL DrawStroke(CDC* pDC);

public:
	virtual void Serialize(CArchive& ar);
	void FinishStroke();
};

class CScribbleDoc : public CDocument
{
protected: // create from serialization only
	CScribbleDoc() noexcept;
	DECLARE_DYNCREATE(CScribbleDoc)

// Attributes
public:
	CTypedPtrList<CObList, CStroke*> m_strokeList;

	CPen* GetCurrentPen() { return &m_penCur; }

protected:
	CSize m_sizeDoc;
public:
	CSize GetDocSize() { return m_sizeDoc; }

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CScribbleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CStroke* NewStroke();

protected:
	void InitDocument();

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

// Member variables
protected:
	UINT m_nPenWidth;
	CPen m_penCur;
	BOOL m_bThickPen;    // Thick currently selected or not
	UINT m_nThinWidth;    // Current definition of thin
	UINT m_nThickWidth;    // Current definition of thick
public:
	afx_msg void OnEditClearAll();
	afx_msg void OnPenThickOrThin();
protected:
	void ReplacePen();
public:
	afx_msg void OnUpdateEditClearAll(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePenThickOrThin(CCmdUI* pCmdUI);
	afx_msg void OnPenWidths();
};
