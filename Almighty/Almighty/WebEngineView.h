#pragma once
#include <QWebChannel>
#include <QWebEngineView>
#include <QWebEngineFullScreenRequest>
#include <QWebEngineSettings>

/*
�̸� �ε带 �س��� swap ���ֱ� ����
2���� player���� ������̰�,
webengineview�� qwebchannel�� ����
javascript�� ����� �� ����.
ä���� ���� ��� �ϱ� ���ؼ� QObject�� ��ӹ޾�.
slot�� slagals�� ��� �ϰ� ����.
*/
class WebEngineView : public QObject
{
	Q_OBJECT

public:
	explicit WebEngineView(QObject *parent = Q_NULLPTR);
	~WebEngineView();

private:
	QWebEngineView *m_webView;
	QWebChannel *m_webChannel;

	double m_dCurrentTime = 0.0;

public:
	QWebEngineView *GetWebView() const { return m_webView; }
	QWebChannel *GetWebChannel() const { return m_webChannel; }

public slots:
	void setCurrentTime(QVariant _currentTime);
	void PlayerReady();

signals:
	void PauseSignal();
	void PlaySignal();

	void ClearVideoDictSignal();
	void SetVideoIdSignal(QString);
	void SetVideoStartSignal(int);
	void SetVideoEndSignal(int);
	void SetQualitySignal(QString);
	void LoadSignal();
};

