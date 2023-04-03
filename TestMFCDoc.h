// TestMFCDoc.h : interface of the CTestMFCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTMFCDOC_H__0E47A75B_19CF_40E2_988D_374E4F922A95__INCLUDED_)
#define AFX_TESTMFCDOC_H__0E47A75B_19CF_40E2_988D_374E4F922A95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestMFCDoc : public CDocument
{
protected: // create from serialization only
	CTestMFCDoc();
	DECLARE_DYNCREATE(CTestMFCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestMFCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestMFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestMFCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTMFCDOC_H__0E47A75B_19CF_40E2_988D_374E4F922A95__INCLUDED_)
