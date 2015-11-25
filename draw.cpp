#include "draw.h"

#include <QBitmap>
#include <QLabel>
#include <QPixmap>

Draw::Draw() { }

Draw::~Draw() { }

void Draw::PixmapToLabel(QLabel* label, const QString &filename)
{
    QPixmap pixmap(filename);
    label->setPixmap(pixmap);
    label->setMask(pixmap.mask());
    label->show();
}

void Draw::Character(QLabel* characterImageLabel, Characters characterToDraw)
{
    QString character;

    switch(characterToDraw)
    {
    case Characters::Isaac:
        character = ":/Resources/Characters/Isaac.png";
        break;
    case Characters::Maggy:
        character = ":/Resources/Characters/Maggy.png";
        break;
    case Characters::Cain:
        character = ":/Resources/Characters/Cain.png";
        break;
    case Characters::Judas:
        character = ":/Resources/Characters/Judas.png";
        break;
    case Characters::BlueBaby:
        character = ":/Resources/Characters/BlueBaby.png";
        break;
    case Characters::Eve:
        character = ":/Resources/Characters/Eve.png";
        break;
    case Characters::Samson:
        character = ":/Resources/Characters/Samson.png";
        break;
    case Characters::Azazel:
        character = ":/Resources/Characters/Azazel.png";
        break;
    case Characters::Lazarus:
        character = ":/Resources/Characters/Lazarus.png";
        break;
    case Characters::Eden:
        character = ":/Resources/Characters/Eden.png";
        break;
    case Characters::TheLost:
        character = ":/Resources/Characters/TheLost.png";
        break;
    case Characters::Lazarus2:
        character = ":/Resources/Characters/Lazarus2.png";
        break;
    case Characters::BlackJudas:
        character = ":/Resources/Characters/BlackJudas.png";
        break;
    case Characters::Lilith:
        character = ":/Resources/Characters/Lilith.png";
        break;
    case Characters::TheKeeper:
        character = ":/Resources/Characters/TheKeeper.png";
        break;
    default:
        character = ":/Resources/Characters/Isaac.png";
        break;
    }

    PixmapToLabel(characterImageLabel, character);
}

void Draw::Health(std::array<QLabel*, 12> heartLabels, int redHearts, int soulHearts, int blackHearts, bool isKeeper)
{
    for(int i = 0; i < 12; ++i) heartLabels.at(i)->clear();

    if(isKeeper)
    {
        int drawnHealth = 0;
        for(int i = 0; i < 12; ++i)
        {
            if(drawnHealth >= 4) break;

            if(redHearts > 1)
            {
                PixmapToLabel(heartLabels.at(i), ":/Resources/Health/CoinHeartFull.png");
                redHearts -= 2;
                drawnHealth += 2;
            }
            else if(redHearts == 1)
            {
                PixmapToLabel(heartLabels.at(i), ":/Resources/Health/CoinHeartHalf.png");
                redHearts -= 1;
                drawnHealth += 1;
            }
            else if(soulHearts > 1 && drawnHealth < 3)
            {
                PixmapToLabel(heartLabels.at(i), ":/Resources/Health/SoulHeartFull.png");
                soulHearts -= 2;
                drawnHealth += 2;
            }
            else if((soulHearts == 1 || soulHearts > 1) && drawnHealth >= 3)
            {
                PixmapToLabel(heartLabels.at(i), ":/Resources/Health/SoulHeartHalf.png");
                soulHearts -= 1;
                drawnHealth += 1;
            }
            else if(blackHearts > 1 && drawnHealth < 3)
            {
                PixmapToLabel(heartLabels.at(i), ":/Resources/Health/BlackHeartFull.png");
                blackHearts -= 2;
                drawnHealth += 2;
            }
            else if((soulHearts == 1 || soulHearts > 1) && drawnHealth >= 3)
            {
                PixmapToLabel(heartLabels.at(i), ":/Resources/Health/BlackHeartHalf.png");
                blackHearts -= 1;
                drawnHealth += 1;
            }
        }
        return;
    }

    for(int i = 0; i < 12; ++i)
    {
        if(redHearts > 1)
        {
            PixmapToLabel(heartLabels.at(i), ":/Resources/Health/RedHeartFull.png");
            redHearts -= 2;
        }
        else if(redHearts == 1)
        {
            PixmapToLabel(heartLabels.at(i), ":/Resources/Health/RedHeartHalf.png");
            redHearts -= 1;
        }
        else if(soulHearts > 1)
        {
            PixmapToLabel(heartLabels.at(i), ":/Resources/Health/SoulHeartFull.png");
            soulHearts -= 2;
        }
        else if(soulHearts == 1)
        {
            PixmapToLabel(heartLabels.at(i), ":/Resources/Health/SoulHeartHalf.png");
            soulHearts -= 1;
        }
        else if(blackHearts > 1)
        {
            PixmapToLabel(heartLabels.at(i), ":/Resources/Health/BlackHeartFull.png");
            blackHearts -= 2;
        }
        else if(blackHearts == 1)
        {
            PixmapToLabel(heartLabels.at(i), ":/Resources/Health/BlackHeartHalf.png");
            blackHearts -= 1;
        }
    }
}
