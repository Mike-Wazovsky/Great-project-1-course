#include "Button.h"
#include "mutex"
#include "Global.h"
#include "minigame.h"

extern std::condition_variable cond;

QSize Button::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}

void Button::oncellClicked() {
    setText(QString::fromStdString(std::to_string(status)));
    revealed = true;
    if (status == -1) {
        //cond.notify_all();
        win->waiting_end();
    }
    if (status == 0)
        win->check_zero(this->x, this->y);
}

void Button::cellClickedforrecursion() {
    setText(QString::fromStdString(std::to_string(status)));
    revealed = true;
    if (status == -1) {
        //cond.notify_all();
        win->waiting_end();
    }
}

void Button::changeStatus(int new_st) {
    status = new_st;
}

int Button::get_status() {
    return status;
}

bool Button::get_rev() {
    return revealed;
}
