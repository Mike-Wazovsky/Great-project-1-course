#include "Button.h"
#include "mutex"
#include "Global.h"
#include "sapper.h"

extern std::condition_variable cond;

QSize Button::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}

void Button::mineCheck() {
    if (status_for_player != -1) {
        win->left_decr();
    }
    status_for_player = -1;
    setText(QString::fromStdString("*"));
    win->check_win();
}

void Button::oncellClicked() {
    if (status_for_player == -1) {
        win->left_incr();
    }
    setText(QString::fromStdString(std::to_string(status)));
    revealed = true;
    if (status == -1) {
        //cond.notify_all();
        win->waiting_end();
    }
    if (status == 0)
        win->check_zero(this->x, this->y);
    status_for_player = status;
    win->check_win();
}

void Button::cellClickedforrecursion() {
    if (status_for_player == -1) {
        win->left_incr();
    }
    setText(QString::fromStdString(std::to_string(status)));
    revealed = true;
    if (status == -1) {
        win->waiting_end();
    }
    status_for_player = status;

    win->check_win();
}

void Button::changeStatus(int new_st) {
    status = new_st;
}

void Button::mousePressEvent(QMouseEvent *e) {
    QString button = enumNameFromValue(e->button());
    if (button == "LeftButton") {
        oncellClicked();
    }
    else if (button == "RightButton") {
        mineCheck();
    }
}


int Button::get_status() {
    return status;
}

int Button::get_status_for_player() {
    return status_for_player;
}

bool Button::get_rev() {
    return revealed;
}

QString Button::enumNameFromValue(const Qt::MouseButton button)
{
    if (button == Qt::NoButton)      return "NoButton";
    if (button == Qt::LeftButton)    return "LeftButton";
    if (button == Qt::RightButton)   return "RightButton";
    if (button == Qt::MiddleButton)  return "MiddleButton";
    if (button == Qt::BackButton)    return "BackButton";
    if (button == Qt::ForwardButton) return "ForwardButton";
    if (button == Qt::TaskButton)    return "TaskButton";
    if (button == Qt::ExtraButton4)  return "ExtraButton4";
    if (button == Qt::ExtraButton5)  return "ExtraButton5";
    if (button == Qt::ExtraButton6)  return "ExtraButton6";
    if (button == Qt::ExtraButton7)  return "ExtraButton7";
    if (button == Qt::ExtraButton8)  return "ExtraButton8";
    if (button == Qt::ExtraButton9)  return "ExtraButton9";
    if (button == Qt::ExtraButton10) return "ExtraButton10";
    if (button == Qt::ExtraButton11) return "ExtraButton11";
    if (button == Qt::ExtraButton12) return "ExtraButton12";
    if (button == Qt::ExtraButton13) return "ExtraButton13";
    if (button == Qt::ExtraButton14) return "ExtraButton14";
    if (button == Qt::ExtraButton15) return "ExtraButton15";
    if (button == Qt::ExtraButton16) return "ExtraButton16";
    if (button == Qt::ExtraButton17) return "ExtraButton17";
    if (button == Qt::ExtraButton18) return "ExtraButton18";
    if (button == Qt::ExtraButton19) return "ExtraButton19";
    if (button == Qt::ExtraButton20) return "ExtraButton20";
    if (button == Qt::ExtraButton21) return "ExtraButton21";
    if (button == Qt::ExtraButton22) return "ExtraButton22";
    if (button == Qt::ExtraButton23) return "ExtraButton23";
    if (button == Qt::ExtraButton24) return "ExtraButton24";
    qDebug("QMouseShortcutEntry::addShortcut contained Invalid Qt::MouseButton value");
    return "NoButton";
}
