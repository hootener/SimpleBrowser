// System Includes
#include <QMainWindow>

// Application Includes

// Forward Declarations
class QLineEdit;
class SimpleWebView;

class MainWindow: public QMainWindow{
	Q_OBJECT
public:
	MainWindow(QWidget * pParent = 0);
protected:
	QLineEdit * m_pUrlLineEdit;
	Q_SLOT void GoToUrl();
	SimpleWebView * m_pWebView;

};
