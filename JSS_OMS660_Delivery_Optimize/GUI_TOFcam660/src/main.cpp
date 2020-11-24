/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "MainWindow.h"
#include "Controller.h"
#include "Settings.h"
#include "Interface.h"
#include <QApplication>
#include <QFile>
#include <QCommandLineParser>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QByteArray styleByte;
#ifdef Q_OS_MAC
  QFile styleFileMac( ":/stylesheets/mac.qss" );
  styleFileMac.open( QFile::ReadOnly );
  styleByte.append(styleFileMac.readAll());
  styleFileMac.close();
#else
  QString str;

  if(argc > 1 && strcmp(argv[1], "debug") == 0){

      if(argc < 3 || strcmp(argv[2], "tablet") != 0) str = "../stylesheets/main.qss";
      else str = "../stylesheets/tablet.qss";

      QFile styleFile(str);
      styleFile.open( QFile::ReadOnly );
      styleByte.append(styleFile.readAll());
      styleFile.close();

  }else{

    if(argc < 2 || strcmp(argv[1], "tablet") != 0) str = ":/stylesheets/main.qss";
    else str = ":/stylesheets/tablet.qss";
    QFile styleFile(str);
    styleFile.open( QFile::ReadOnly );
    styleByte.append(styleFile.readAll());
    styleFile.close();
  }

#endif

  QString strSplash;

  if(argc < 2 || strcmp(argv[1], "tablet") != 0) strSplash = ":/splash_screen/images/splash_screen/splash_screen.png";
  else strSplash = ":/splash_screen/images/splash_screen/splash_screen_tablet.png";

  QSplashScreen splashScreen;
  splashScreen.setPixmap(QPixmap(strSplash));
  splashScreen.show();

  QString style(styleByte);
  a.setStyleSheet(style);

  ApplicationContext context;

  //Parse the command line arguments. At the moment the destination IP can be set with: --ip 10.10.31.180
  QCommandLineParser parser;
  QCommandLineOption targetIpOption(QStringList() << "ip",
  QCoreApplication::translate("main", "Set destination ip to <IPV4>."),
  QCoreApplication::translate("main", "IPV4"));
  parser.addOption(targetIpOption);
  parser.setApplicationDescription("TOFCam660 GUI");
  parser.addHelpOption();
  parser.process(a);

  //Store the IP
  QString targetIp = parser.value(targetIpOption);
  if (targetIp != "")
  {
    context.getSettings().setDestIp(targetIp);
  }

  //At the moment connect here to the device; use the IP stored in the configuration
  context.getInterface().connectToDevice(context.getSettings().getDestIp());  

  MainWindow w(context);
  splashScreen.finish(&w);
  w.show();

  return a.exec();
}
