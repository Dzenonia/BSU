//
// Created by evgeniy on 10.4.23.
//

#ifndef BSU_GRAPHWIDJET_H
#define BSU_GRAPHWIDJET_H

#include <QWidget>


class GraphWidjet : public QWidget {
    Q_OBJECT

public:
    explicit GraphWidjet(QWidget* parent = nullptr);
    ~GraphWidjet() override;

private:
};


#endif // BSU_GRAPHWIDJET_H
