#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <X11/Xlib.h>
#include <vector>
#include <memory>

class WindowManager {
public:
    static WindowManager& getInstance();
    void run();

private:
    WindowManager();
    ~WindowManager();

    void handleEvent(XEvent *event);

    Display *display;
    int screen;
    Window root;
};

#endif // WINDOWMANAGER_H
