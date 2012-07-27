#include "MainWindow.h"
#include "SimpleWebView.h"

#include <QToolBar>
#include <QLineEdit>
#include <QAction>

MainWindow::MainWindow(QWidget * pParent):QMainWindow(pParent){
	
	m_pWebView = new SimpleWebView("http://www.google.com",this);
	m_pUrlLineEdit = new QLineEdit(this);
	//make a toolbar

	QToolBar * pToolBar = new QToolBar(this);
	QAction * pGoAction = new QAction("Go", this);
	pToolBar->addWidget(m_pUrlLineEdit);
	pToolBar->addAction(pGoAction);

	connect(pGoAction,SIGNAL(triggered()),this,SLOT(GoToUrl()));
	addToolBar(Qt::TopToolBarArea, pToolBar);
	setCentralWidget(m_pWebView);
}

void MainWindow::GoToUrl(){
	if(!m_pUrlLineEdit->text().isEmpty()){
		m_pWebView->LoadUrl(m_pUrlLineEdit->text());
	}
}