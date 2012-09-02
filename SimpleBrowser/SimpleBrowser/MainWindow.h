// System Includes
#include <QMainWindow>

// Application Includes

// Forward Declarations
class QLineEdit;
class SimpleWebView;
class QProgressBar;
class QLabel;

class MainWindow: public QMainWindow{
	Q_OBJECT
public:
	MainWindow(QWidget * pParent = 0);
protected:
	QLineEdit * m_pUrlLineEdit;
	Q_SLOT void GoToUrl();
	SimpleWebView * m_pWebView;
	
	/*!
	* For showing status messages in the status bar.
	*/
	QLabel * m_pStatusBarMessageLabel;
	Q_SLOT void SetStatusBarLabelText(const QString& text);
	
	/*!
	* For showing hiding and updating the main window's page load progress bar.
	*/
	QProgressBar * m_pPageLoadProgressBar;
	Q_SLOT void UpdateProgressBar(int progress);
	Q_SLOT void HideProgressBar(bool ok);
	Q_SLOT void ShowProgressBar();
};
