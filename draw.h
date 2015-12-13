#ifndef DRAW_H
#define DRAW_H

#include "character.h"
#include "random.h"
#include <QLabel>
#include <array>
#include <vector>

class Draw : public QObject
{
    Q_OBJECT

public:
    Draw();
    ~Draw();
    void PixmapToLabel(QLabel*, const QString&);
    void Character(QLabel*, Characters);
    void Health(std::array<QLabel*, 12>, int, int, int, bool);
    void Spacebar(QLabel*, int);
    void Charge(QLabel*, int);
    void Pill(QLabel*);
    void Card(QLabel*, int);
    void Trinket(QLabel*, int);
    void Familiar(QLabel*, std::vector<int>);
    int DrawnPill = 0;
private:
    Random _rng = Random();
};

#endif // DRAW_H
