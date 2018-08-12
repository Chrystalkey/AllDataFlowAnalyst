//
// Created by Chrystalkey on 07.08.2018.
//

#ifndef ALLDATAFLOWANALYST_KEYBOARDHEATMAP_H
#define ALLDATAFLOWANALYST_KEYBOARDHEATMAP_H

#include <QWidget>
#include <libglobal.h>
#include <QtCore/QMap>

class KeyboardHeatmap : public QWidget{
public:
    explicit KeyboardHeatmap(QWidget *parent = nullptr);
    ~KeyboardHeatmap();
private:
    void build();
    void rebuild();
private:
    QMap<quint32, quint32> keyPresses;
};


#endif //ALLDATAFLOWANALYST_KEYBOARDHEATMAP_H
