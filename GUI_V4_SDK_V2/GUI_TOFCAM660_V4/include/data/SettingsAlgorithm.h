#ifndef SETTINGSALGORITHM_H
#define SETTINGSALGORITHM_H

#include <QObject>

class SettingsAlgorithm : public QObject
{
    Q_OBJECT
public:
    explicit SettingsAlgorithm(QObject *parent = nullptr);
    void updateAlgorithm();

    void setSDAEnabled(bool state);
    bool isSDAEnabled();

    void setMDAEnabled(bool state);
    bool isMDAEnabled();
    void setMDAWindowSize(int value);
    int getMDAWindowSize();
    void setMDAImageType(int value);
    int getMDAImageType();


signals:
    void algorithmChanged();

public slots:

private:

    bool sdaEnabled;
    bool mdaEnabled;
    int mdaWindowSize;
    int mdaImageType;

};

#endif // SETTINGSALGORITHM_H
