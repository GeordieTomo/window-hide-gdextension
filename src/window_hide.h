#ifndef WINDOW_HIDE_H
#define WINDOW_HIDE_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>

#ifdef _WIN32
#include <windows.h>
#endif

namespace godot {

class WindowHide : public Object {
    GDCLASS(WindowHide, Object)

protected:
    static void _bind_methods();

public:
    WindowHide();
    ~WindowHide();

    // Window functions
    static void hide_window();
    static void show_window();
    static bool is_window_visible();
};

}

#endif // WINDOW_HIDE_H