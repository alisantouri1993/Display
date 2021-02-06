############### linking Marbel

include(Copy.pri)

win32:{
    IntelPath="C:/Program Files/marble"

    INCLUDEPATH += $$IntelPath/include
    DEPENDPATH += $$IntelPath/include

    CONFIG(debug, debug|release):{
        LIBS += -L$$IntelPath/lib/ -lastrod
        LIBS += -L$$IntelPath/lib/ -lmarblewidget-qt5d
    }
    CONFIG(release, debug|release):{
        LIBS += -L$$IntelPath/lib/ -lastro
        LIBS += -L$$IntelPath/lib/ -lmarblewidget-qt5
    }
}
unix:{

    IntelPath="/usr/local"

    INCLUDEPATH += $$IntelPath/include/marble
    DEPENDPATH += $$IntelPath/include/marble
  
    LIBS += -L$$IntelPath/lib/ -lastro
    LIBS += -L$$IntelPath/lib/ -lmarblewidget-qt5
}

CONFIG(release, debug|release):{
copyToDestDir($$IntelPath/astro.dll , $$OUT_PWD/release)
copyToDestDir($$IntelPath/marbledeclarative.dll , $$OUT_PWD/release)
copyToDestDir($$IntelPath/marblewidget-qt5.dll , $$OUT_PWD/release)
copyToDestDir($$IntelPath/pluginsRelease , $$OUT_PWD/release/plugins)
copyToDestDir($$IntelPath/data , $$OUT_PWD/release/data)
}

CONFIG(debug, debug|release):{
copyToDestDir($$IntelPath/astrod.dll , $$OUT_PWD/debug)
copyToDestDir($$IntelPath/marbledeclaratived.dll , $$OUT_PWD/debug)
copyToDestDir($$IntelPath/marblewidget-qt5d.dll , $$OUT_PWD/debug)
copyToDestDir($$IntelPath/pluginsDebug , $$OUT_PWD/debug/plugins)
copyToDestDir($$IntelPath/data , $$OUT_PWD/debug/data)
}


########### end of Marbel
