#ifndef SCENEWIDGETITEM_H
#define SCENEWIDGETITEM_H

#include <QWidget>

class QVBoxLayout;
class QLabel;
class QCheckBox;
class QComboBox;
class QPushButton;
class QMenu;

class SceneWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit SceneWidgetItem(QWidget *parent = 0);
    ~SceneWidgetItem();

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    QVBoxLayout *layout;
    QLabel *label;
    QCheckBox *checkbox;
    QComboBox *combobox;
    QPushButton *resetButton;
    QMenu* menu;

signals:
    void rotateItem();

public slots:
    void reset();
    void rotate();
};
#endif // SCENEWIDGETITEM_H
