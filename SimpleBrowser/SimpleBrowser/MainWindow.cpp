#include "MainWindow.h"
#include "SimpleWebView.h"

#include <QToolBar>
#include <QLineEdit>
#include <QAction>
#include <QStatusBar>
#include <QProgressBar>
#include <QLabel>

MainWindow::MainWindow(QWidget * pParent):QMainWindow(pParent){
	
	m_pWebView = new SimpleWebView("http://www.google.com",this);
	m_pUrlLineEdit = new QLineEdit(this);
	m_pPageLoadProgressBar = new QProgressBar(this);
	m_pPageLoadProgressBar->setValue(0);
	m_pStatusBarMessageLabel = new QLabel(this);
	
	//make a toolbar
	QToolBar * pToolBar = new QToolBar(this);
	QAction * pGoAction = new QAction("Go", this);
	pToolBar->addWidget(m_pUrlLineEdit);
	pToolBar->addAction(pGoAction);

	//put the progress bar in the status bar.
	statusBar()->addWidget(m_pPageLoadProgressBar);
	statusBar()->addWidget(m_pStatusBarMessageLabel);
	statusBar()->hide();
	m_pPageLoadProgressBar->hide();


	//connect up the progress bar and status bar label.
	connect(m_pWebView, SIGNAL(loadStarted()), this, SLOT(ShowProgressBar()));
	connect(m_pWebView, SIGNAL(loadFinished(bool)), this, SLOT(HideProgressBar(bool)));
	connect(m_pWebView, SIGNAL(loadProgress(int)), this, SLOT(UpdateProgressBar(int)));
	connect(m_pWebView, SIGNAL(statusBarMessage(const QString&)), this,SLOT(SetStatusBarLabelText(const QString&)));

	connect(pGoAction,SIGNAL(triggered()),this,SLOT(GoToUrl()));
	addToolBar(Qt::TopToolBarArea, pToolBar);
	setCentralWidget(m_pWebView);



}

void MainWindow::UpdateProgressBar(int progress){
	m_pPageLoadProgressBar->setValue(progress);
}

void MainWindow::SetStatusBarLabelText(const QString& text){
	m_pStatusBarMessageLabel->setText(text);
}

void MainWindow::ShowProgressBar(){
	statusBar()->show();
	m_pPageLoadProgressBar->setValue(0);
	m_pPageLoadProgressBar->show();
}

void MainWindow::HideProgressBar(bool ok){
	Q_UNUSED(ok);
	statusBar()->hide();
	m_pPageLoadProgressBar->hide();
}

void MainWindow::GoToUrl(){
	if(!m_pUrlLineEdit->text().isEmpty()){
		m_pWebView->LoadUrl(m_pUrlLineEdit->text());
	}
}