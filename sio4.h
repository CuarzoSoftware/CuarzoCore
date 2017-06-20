#ifndef SiO4_H
#define SiO4_H

#include "includes.h"

class SiO4 : public QLabel
{
    Q_OBJECT

public:
    SiO4();
    ~SiO4();

    void startUI();

public slots:
    void resolutionChanged();
};

#endif // SiO4_H
