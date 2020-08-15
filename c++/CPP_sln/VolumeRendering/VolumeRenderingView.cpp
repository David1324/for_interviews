
// VolumeRenderingView.cpp : implementation of the CVolumeRenderingView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "VolumeRendering.h"
#endif

#include "VolumeRenderingDoc.h"
#include "VolumeRenderingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVolumeRenderingView

IMPLEMENT_DYNCREATE(CVolumeRenderingView, CView)

BEGIN_MESSAGE_MAP(CVolumeRenderingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CVolumeRenderingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CVolumeRenderingView construction/destruction

CVolumeRenderingView::CVolumeRenderingView()
{
	// TODO: add construction code here

}

CVolumeRenderingView::~CVolumeRenderingView()
{
}

BOOL CVolumeRenderingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVolumeRenderingView drawing

void CVolumeRenderingView::OnDraw(CDC* /*pDC*/)
{
	CVolumeRenderingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CVolumeRenderingView printing


void CVolumeRenderingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CVolumeRenderingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVolumeRenderingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVolumeRenderingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CVolumeRenderingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVolumeRenderingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CVolumeRenderingView diagnostics

#ifdef _DEBUG
void CVolumeRenderingView::AssertValid() const
{
	CView::AssertValid();
}

void CVolumeRenderingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVolumeRenderingDoc* CVolumeRenderingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVolumeRenderingDoc)));
	return (CVolumeRenderingDoc*)m_pDocument;
}
#endif //_DEBUG


// CVolumeRenderingView message handlers
