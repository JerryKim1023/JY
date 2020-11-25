#include "WebEngineView.h"
#include <windows.h>

WebEngineView::WebEngineView(QObject *parent) : QObject(parent)
, m_webView(Q_NULLPTR)
, m_webChannel(Q_NULLPTR)
{
	// �����ڿ��� webView�� webChannel, load�� ���� �ϰ� �ִµ�. ���߿� ��ġ �Ű� ��.
	// ���� ������ webView�� ������� �� �ִ� ����� �߰� �ؾ��Ѵٴ� ����.
	m_webView = new QWebEngineView();
	m_webView->page()->setBackgroundColor(Qt::black);
	m_webView->settings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true);
	m_webView->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
	m_webView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);

	//�� ä��
	m_webChannel = new QWebChannel(this);
	m_webChannel->registerObject("media", this);
	m_webView->page()->setWebChannel(m_webChannel);

	QUrl url = QUrl(QStringLiteral("qrc:/index.html"));
	m_webView->load(url);
}


WebEngineView::~WebEngineView()
{
}

/*
* webchannel���� currentTime�� �޾ƿ��� �Լ��̰�, �޾ƿö��� QVariant, QjsonValue, QJsonDocument��
* �޾ƿ;����� ��� �ϰ� ���� ��.
*/
void WebEngineView::setCurrentTime(QVariant _currentTime)
{
	m_dCurrentTime = _currentTime.toDouble();

	//OutputDebugString(std::to_wstring(m_dCurrentTime).c_str());
}

void WebEngineView::PlayerReady()
{
	emit ClearVideoDictSignal();
	emit SetVideoIdSignal("oWhkL4899u8");
	emit SetVideoStartSignal(0.0);
	emit SetVideoEndSignal(80.0);

	emit LoadSignal();
}
